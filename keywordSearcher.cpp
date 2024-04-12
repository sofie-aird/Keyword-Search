/*
  Copyright (c) 2024
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2024
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/25wjykh8
*/

#include "keywordSearcher.h"
#include <fstream>

#include <stdexcept>

using namespace std;

KeywordSearcher::KeywordSearcher() {
    // Allocate a hash table and list of pages
    this->hashTable = new HashTable<int, int>();
    this->pages = new STLList<string>();
}

KeywordSearcher::~KeywordSearcher() {
    // Delete the hash table and list of pages
    delete this->hashTable;
    delete this->pages;
}

void KeywordSearcher::loadWords(string filename) {
    ifstream myFile;
    string data;
    int pageNumber = 0;
    string pageText;

    // Open the file
    myFile.open(filename);
    if (!myFile.is_open()) {
        throw runtime_error("file " + filename + " failed to open ");
    }

    // Read in the first line
    getline(myFile, data);

    // While we aren't at the end of the file
    while (!myFile.eof()) {
        // See if we are at the start of a new page
        if (data.find("$$@@$$PAGE:") != string::npos) {
            pageNumber++;
            // Put the last page in the list of pages
            if (pageNumber != 1) {
                this->pages->insertLast(pageText);
            }
            // Clear the page text
            pageText = " ";
        }
        // We are not at the start of a new page
        else {
            pageText += data;
            pageText += " ";
        }
        // Add the next line to the page text
        getline(myFile, data);
    }
    // Insert the last page
    pageNumber++;
    this->pages->insertLast(pageText);
}

vector<pair<int, int>> KeywordSearcher::search(string word) {
    vector<pair<int, int>> result;

    // Reset the hash table from the last search
    delete this->hashTable;
    this->hashTable = new HashTable<int, int>();

    // Add spaces so we dont get this word as a subword in larger words
    word = " " + word + " ";

    // Find out how many pages there are
    int size = this->pages->getSize();
    // Loop through each page
    for (int i = 0; i < size; i++) {
        // Count how many times the word occurs on this page
        int count = 0;
        // Where the string first occurs on the page
        int start = this->pages->get(i).find(word);
        // While there is an occurrence of the word on the page that we havent found yet
        while (start != string::npos) {
            // Increase count
            count++;
            // Find the next occurrence of the word
            start = this->pages->get(i).find(word, start + 1);
        }
        // At the end of the page, insert the key page number and value of occurrences
        if (count != 0) {
            this->hashTable->insert(i + 1, count);
        }
    }

    // Now sort the vector by putting each thing in a priority queue
    vector<pair<int, int>> occurrences = this->hashTable->getItems();
    size = occurrences.size();
    STLMaxPriorityQueue<int, int>* queue = new STLMaxPriorityQueue<int, int>();
    // Loop through each page with an occurrence of the word
    for (int i = 0; i < size; i++) {
        // Insert the pair into the queue, with occurrence count as the priotity
        queue->insert(occurrences[i].second, occurrences[i].first);
    }
    
    // While the queue still has things in it
    size = 0;
    while (!queue->isEmpty()) {
        // If we have 10 pages already, leave
        if (size >= 10) {
            break;
        }
        // Put the highest priority item into a vector
        pair<int, int> page;
        page.second = queue->peekPriority();
        page.first = queue->remove();
        result.push_back(page);
        size++;
    }
    delete queue;
    return result;
}
