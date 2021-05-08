#include <cmath>

#include "DynamicArray.h"


template<typename T>
void DynamicArray<T>::initialization() {
    if (size < 0) {
        throw std::length_error("DynamicArray::DynamicArray");
    }
    this->array = new T[this->guaranteedCapacity];
}

template<typename T>
DynamicArray<T>::DynamicArray(size_t size): size(size), guaranteedCapacity(size) {
    this->initialization();
}

template<typename T>
DynamicArray<T>::DynamicArray(size_t size, const T &value): size(size), guaranteedCapacity(size) {
    this->initialization();
    for (int i = 0; i < size; i++) {
        this->array[i] = value;
    }
}

template<typename T>
DynamicArray<T>::DynamicArray(std::size_t size, T *toCopy): size(size), guaranteedCapacity(size) {
    this->initialization();
    for (int i = 0; i < size; i++) {
        array[i] = toCopy[i];
    }
}

template<typename T>

DynamicArray<T>::DynamicArray(const DynamicArray<T> &toCopy) {
    // TODO
}

template<typename T>
void DynamicArray<T>::resize() {
    if (this->size > this->guaranteedCapacity) {
        if (this->size > 64) {
            this->guaranteed_capacity *= 1.5;
        } else if (this->size > 8) {
            this->guaranteed_capacity += 16;
        } else {
            this->guaranteed_capacity += 4;
        }
    }
    delete[] this->array;
    this->array = new T[this->guaranteedCapacity];
}

template<typename T>
std::size_t DynamicArray<T>::getSize() {
    return this->size;
}

template<typename T>
T &DynamicArray<T>::operator[](std::size_t idx) {
    if (0 <= idx < this->size) {
        return this->array[idx];
    }
    throw std::out_of_range("DynamicArray::operator[]");
}

template<typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] this->array;
}