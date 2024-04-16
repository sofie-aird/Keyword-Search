/*
  Copyright (c) 2024
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2024
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/25wjykh8
*/

#include <iostream>
#include <string>
#include <vector>

#include "keywordSearcher.h"

using namespace std;

int main(int argc, char** argv) {
    KeywordSearcher search;
    string searchWord;
    vector<pair<int, int>> result;
    
    // Make sure we have the correct number of command-line args
    if (argc != 2) {
      throw runtime_error("Usage: ./keywordSearch file.txt");
    }
    // Attempt to load words
    search.loadWords(argv[1]);

    // Continually ask user for words to search
    while (true) {
      cout << "Please enter a search word or '!' to quit: ";
      cin >> searchWord;

      // Exit if user wants to exit
      if (!searchWord.compare("!")) {
        break;
      }

      result = search.search(searchWord);
      int size = result.size();

      if (size == 0) {
        cout << "The word " << searchWord << " does not appear in the file." << endl;
      }
      else {
        cout << "The word " << searchWord << " appears in the file..." << endl;
        for (int i = 0; i < size; i++) {
          cout << "\ton page " << result[i].first << " (" << result[i].second << " occurrences)" << endl;
        }
      }
    }
    return 0;
}
