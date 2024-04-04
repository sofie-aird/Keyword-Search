/*
  Copyright (c) 2024
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2024
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/25wjykh8
*/

#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>

#include "hashFunctions.h"

using std::pair;
using std::runtime_error;
using std::vector;

template <typename K, typename V> HashTable<K, V>::HashTable() {
    throw runtime_error("Not yet implemented: HashTable<K,V>::HashTable");
}

template <typename K, typename V>
HashTable<K, V>::HashTable(float maxLoadFactor) {
    throw runtime_error(
        "Not yet implemented: HashTable<K,V>::HashTable(float)");
}

template <typename K, typename V> HashTable<K, V>::~HashTable() {
    // TODO: HashTable<K,V>::~HashTable
}

template <typename K, typename V> int HashTable<K, V>::getSize() {
    throw runtime_error("Not yet implemented: HashTable<K,V>::getSize");
}

template <typename K, typename V> bool HashTable<K, V>::isEmpty() {
    throw runtime_error("Not yet implemented: HashTable<K,V>::isEmpty");
}

template <typename K, typename V> void HashTable<K, V>::insert(K key, V value) {
    throw runtime_error("Not yet implemented: HashTable<K,V>::insert");
}

template <typename K, typename V> void HashTable<K, V>::update(K key, V value) {
    throw runtime_error("Not yet implemented: HashTable<K,V>::update");
}

template <typename K, typename V> V HashTable<K, V>::get(K key) {
    throw runtime_error("Not yet implemented: HashTable<K,V>::get");
}

template <typename K, typename V> bool HashTable<K, V>::contains(K key) {
    throw runtime_error("Not yet implemented: HashTable<K,V>::contains");
}

template <typename K, typename V> void HashTable<K, V>::remove(K key) {
    throw runtime_error("Not yet implemented: HashTable<K,V>::remove");
}

template <typename K, typename V> vector<K> HashTable<K, V>::getKeys() {
    throw runtime_error("Not yet implemented: HashTable<K,V>::getKeys");
}

template <typename K, typename V>
vector<pair<K, V>> HashTable<K, V>::getItems() {
    throw runtime_error("Not yet implemented: HashTable<K,V>::getItems");
}

// TODO: put any other definitions here
