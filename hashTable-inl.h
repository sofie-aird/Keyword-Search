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
    this->capacity = 8;
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
    // Find the correct index in the hash table
    int index = hash(key, this->capacity);
    // Use linear dictionary update
    this->table[index].update(key, value);
}

template <typename K, typename V> V HashTable<K, V>::get(K key) {
    // Following pseudocode from lecture
    // Find the index
    int index = hash(key, this->capacity);
    // Use linear dictionary get
    return this->table[index].get(key);
}

template <typename K, typename V> bool HashTable<K, V>::contains(K key) {
    // Find the correct index in the hash table
    int index = hash(key, this->capacity);
    // Use linear dictionary contains
    return this->table[index].contains(key);
}

template <typename K, typename V> void HashTable<K, V>::remove(K key) {
    // Find the correct index in the hash table
    int index = hash(key, this->capacity);
    // Use linear dictionary remove
    return this->table[index].remove(key);
    this->size--;
}

template <typename K, typename V> vector<K> HashTable<K, V>::getKeys() {
    vector<K> result;
    // Go through all the linear dictionaries and add all their items
    for (int i = 0; i < this->capacity; i++) {
        vector<K> item = this->table[i].getKeys();
        int vectorSize = item.size();
        for (int j = 0; j < vectorSize; j++) {
            result.push_back(item[j]);
        }
    }
    return result;
}

template <typename K, typename V>
vector<pair<K, V>> HashTable<K, V>::getItems() {
    vector<pair<K, V>> result;
    // Go through all the linear dictionaries and add all their items
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
    // Following pseudocode given in lecture
    LinearDictionary<K, V>* new_table = new LinearDictionary<K, V>[this->capacity*2];
    vector<pair<K, V>> items = getItems();
    int vectorSize = items.size();
    for (int i = 0; i < vectorSize; i++) {
        int index = hash(items[i].first, this->capacity*2);
        new_table[index].insert(items[i].first, items[i].second);
    }
    delete [] this->table;
    this->table = new_table;
    this->capacity = this->capacity*2;
}