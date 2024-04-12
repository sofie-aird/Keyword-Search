/*
  Copyright (c) 2024
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2024
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/25wjykh8
*/

#include <string>
#include "adts/dictionary.h"
#include "hashTable.h"
#include <algorithm>
#include <fstream>
#include <random>
#include <string>
#include <vector>

#include <UnitTest++/UnitTest++.h>

#include "adts/dictionary.h"
#include "hashFunctions.h"
#include "keywordSearcher.h"

using namespace std;

int main(int argc, char** argv) {
    // You can use this main to experiment with the code you have written
    KeywordSearcher ks;
    ks.loadWords("test_data/ATranslationGuideFromPython2ToC++.txt");
    vector<pair<int, int>> result = ks.search("python");
    cout << "searching for: python" << endl;
    int size = result.size();
    for (int i = 0; i < size; i++) {
      cout << "Page " << result[i].first << " has " << result[i].second << " occurrences" << endl; 
    }
    return 0;
}
