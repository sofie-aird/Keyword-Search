/*
  Copyright (c) 2024
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2024
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/25wjykh8
*/

#include <stdexcept>
using std::runtime_error;

template <typename K, typename V> LinearDictionary<K, V>::LinearDictionary() {}

template <typename K, typename V> LinearDictionary<K, V>::~LinearDictionary() {}

template <typename K, typename V> int LinearDictionary<K, V>::getSize() {
    return this->items.size();
}

template <typename K, typename V> bool LinearDictionary<K, V>::isEmpty() {
    return this->items.size() == 0;
}

template <typename K, typename V>
void LinearDictionary<K, V>::insert(K key, V value) {
    // Search to make sure key is not already in dictionary
    int size = this->items.size();
    for (int i = 0; i < size; i++) {
        if (this->items[i].first == key) {
            throw runtime_error("Key already in linear dictionary");
        }
    }
    pair<K, V> item;
    item.first = key;
    item.second = value;
    this->items.push_back(item);
}

template <typename K, typename V>
void LinearDictionary<K, V>::update(K key, V value) {
    // Another linear search
    int size = this->items.size();
    for (int i = 0; i < size; i++) {
        if (this->items[i].first == key) {
            // Update the value
            this->items[i].second = value;
            return;
        }
    }
    throw runtime_error("update: Key not found");
}

template <typename K, typename V> V LinearDictionary<K, V>::get(K key) {
    // Search through whole vector for key
    int size = this->items.size();
    for (int i = 0; i < size; i++) {
        if (this->items[i].first == key) {
            return this->items[i].second;
        }
    }
    throw runtime_error("get: Key not found");
}

template <typename K, typename V> bool LinearDictionary<K, V>::contains(K key) {
    // Another linear search
    int size = this->items.size();
    for (int i = 0; i < size; i++) {
        if (this->items[i].first == key) {
            return true;
        }
    }
    return false;
}

template <typename K, typename V> void LinearDictionary<K, V>::remove(K key) {
    // Another linear search
    int size = this->items.size();
    for (int i = 0; i < size; i++) {
        if (this->items[i].first == key) {
            // Remove the item
            this->items.erase(this->items.begin() + i, this->items.begin() + i + 1);
            return;
        }
    }
    throw runtime_error("remove: Key not found");
}

template <typename K, typename V> vector<K> LinearDictionary<K, V>::getKeys() {
    // Another linear search
    int size = this->items.size();
    vector<K> keys;
    for (int i = 0; i < size; i++) {
        keys.push_back(this->items[i].first);
    }
    return keys;
}

template <typename K, typename V>
vector<pair<K, V>> LinearDictionary<K, V>::getItems() {
    // Another linear search
    int size = this->items.size();
    vector<pair<K, V>> itemsget;
    for (int i = 0; i < size; i++) {
        itemsget.push_back(this->items[i]);
    }
    return itemsget;
}
