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
    for (std::size_t i = 0; i < size; i++) {
        this->array[i] = value;
    }
}

template<typename T>
DynamicArray<T>::DynamicArray(std::size_t size, T *toCopy): size(size), guaranteedCapacity(size) {
    this->initialization();
    for (std::size_t i = 0; i < size; i++) {
        array[i] = toCopy[i];
    }
}

template<typename T>

DynamicArray<T>::DynamicArray(const DynamicArray<T> &toCopy) {
    // TODO
}

template<typename T>
void DynamicArray<T>::resize() {
    if (this->size + 1 > this->guaranteedCapacity) {
        if (this->size + 1 > 64) {
            this->guaranteed_capacity *= 1.5;
        } else if (this->size + 1 > 8) {
            this->guaranteed_capacity += 16;
        } else {
            this->guaranteed_capacity += 4;
        }
    }
    auto tmpArray = new T[this->guaranteedCapacity];
    for (std::size_t i = 0; i < this->size; i++) {
        tmpArray[i] = this->array[i];
    }
    delete[] this->array;
    this->array = tmpArray;
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
ICollection<T> DynamicArray<T>::operator<<(T &source) {
    this->resize();
    this->array[this->size - 1] = source;
    this->size++;
    return this;
}

template<typename T>
ICollection<T> DynamicArray<T>::operator>>(T &source) {
    for (std::size_t i = 0, j = 0; j < this->size; i++, j++) {
        if (*(this[i]) == source) {
            j++;
        }
        this[i] = this[j];
    }
    this->size--;
    return this;
}

template<typename T>
ICollection<T> DynamicArray<T>::operator>>(std::size_t idx) {
    for (std::size_t i = idx; i < this->size - 1; i++) {
        this[i] = this[i + 1];
    }
    this->size--;
    return this;
}

template<typename T>
bool DynamicArray<T>::operator<<=(T &source) {
    for (std::size_t i = 0; i < this->size; i++) {
        if (*(this[i]) == source) {
            return true;
        }
    }
    return false;
}

template<typename T>
ICollection<T> DynamicArray<T>::operator!() {
    delete[] this->array;
    this->size = 0;
    this->guaranteedCapacity = 0;
    return this;
}

template<typename T>
void DynamicArray<T>::copyTo(T *dest, std::size_t amount) {
    for (std::size_t i = 0; i < min(amount, this->size); i++) {
        dest[0] == this[i];
    }
}

template<typename T>
IEnumerator<T> DynamicArray<T>::operator~() {
    return nullptr;
}

template<typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] this->array;
}

//template<typename T>
//IEnumerator<T> &DynamicArray<T>::DynamicArrayEnumerator::operator++() {
//    this
//    return <#initializer#>;
//}
