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
    this->maxLoadFactor = 0.75;
    this->size = 0;
    this->capacity = 1;
    this->table = new LinearDictionary<K, V>[this->capacity];
}

template <typename K, typename V>
HashTable<K, V>::HashTable(float maxLoadFactor) {
    this->maxLoadFactor = maxLoadFactor;
    this->size = 0;
    this->capacity = 1;
    this->table = new LinearDictionary<K, V>[this->capacity];
}

template <typename K, typename V> HashTable<K, V>::~HashTable() {
    delete[] this->table;
}

template <typename K, typename V> int HashTable<K, V>::getSize() {
    return this->size;
}

template <typename K, typename V> bool HashTable<K, V>::isEmpty() {
    return this->size == 0;
}

template <typename K, typename V> void HashTable<K, V>::insert(K key, V value) {
    //find the index in the table
    int index = hash(key, this->capacity);
    //use Linear Dictionary insert method
    this->table[index].insert(key, value);
    this->size++;
    //cast numerator as float
    float load = float(this->size) / this->capacity;
    //resize?
    if (load > this->maxLoadFactor) {
        ensureCapacity();
    }
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
    vector<pair<K, V>> result;
    for (int i = 0; i < this->capacity; i++) {
        vector<pair<K, V>> item = this->table[i].getItems();
        int vectorSize = item.size();
        for (int j = 0; j < vectorSize; j++) {
            result.push_back(item[j]);
        }
    }
    return result;
}

// TODO: put any other definitions here
template <typename K, typename V> void HashTable<K, V>::ensureCapacity() {
    
    LinearDictionary<K, V>* new_table = new LinearDictionary<K, V>[this->capacity*2];
    vector<pair<K, V>> items = getItems();
    int vectorSize = items.size();
    for (int i = 0; i < vectorSize; i++) {
        new_table[hash(items[i].first, this->capacity)].insert(items[i].first, items[i].second);
    }
    delete [] this->table;
    this->table = new_table;
    this->capacity = this->capacity*2;

}