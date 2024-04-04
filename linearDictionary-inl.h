/*
  Copyright (c) 2024
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2024
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/25wjykh8
*/

#include <stdexcept>

template <typename K, typename V> LinearDictionary<K, V>::LinearDictionary() {
    throw std::runtime_error(
        "Not yet implemented: LinearDictionary<K,V>::LinearDictionary");
}

template <typename K, typename V> LinearDictionary<K, V>::~LinearDictionary() {
    // TODO: LinearDictionary<K,V>::~LinearDictionary
}

template <typename K, typename V> int LinearDictionary<K, V>::getSize() {
    throw std::runtime_error(
        "Not yet implemented: LinearDictionary<K,V>::getSize");
}

template <typename K, typename V> bool LinearDictionary<K, V>::isEmpty() {
    throw std::runtime_error(
        "Not yet implemented: LinearDictionary<K,V>::isEmpty");
}

template <typename K, typename V>
void LinearDictionary<K, V>::insert(K key, V value) {
    throw std::runtime_error(
        "Not yet implemented: LinearDictionary<K,V>::insert");
}

template <typename K, typename V>
void LinearDictionary<K, V>::update(K key, V value) {
    throw std::runtime_error(
        "Not yet implemented: LinearDictionary<K,V>::update");
}

template <typename K, typename V> V LinearDictionary<K, V>::get(K key) {
    throw std::runtime_error("Not yet implemented: LinearDictionary<K,V>::get");
}

template <typename K, typename V> bool LinearDictionary<K, V>::contains(K key) {
    throw std::runtime_error(
        "Not yet implemented: LinearDictionary<K,V>::contains");
}

template <typename K, typename V> void LinearDictionary<K, V>::remove(K key) {
    throw std::runtime_error(
        "Not yet implemented: LinearDictionary<K,V>::remove");
}

template <typename K, typename V> vector<K> LinearDictionary<K, V>::getKeys() {
    throw std::runtime_error(
        "Not yet implemented: LinearDictionary<K,V>::getKeys");
}

template <typename K, typename V>
vector<pair<K, V>> LinearDictionary<K, V>::getItems() {
    throw std::runtime_error(
        "Not yet implemented: LinearDictionary<K,V>::getItems");
}
