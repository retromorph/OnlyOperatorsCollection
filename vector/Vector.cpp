#include "Vector.h"

template<typename T>
Vector<T>::Vector(size_t dimension) {
    this->dimension = dimension;
    this->repr = new T[dimension];
}

template<typename T>
Vector<T>::Vector(T temp[]) {
    this->repr = temp;
    this->dimension = (sizeof(temp) / sizeof(*temp));
}

template<typename T>
T Vector<T>::norm() {
    return nullptr;
}

template<typename T>
Vector<T> operator+(const Vector<T> &left, const Vector<T> &right) {
    return Vector<T>();
}

template<typename T>
Vector<T> operator*(const Vector<T> &left, const Vector<T> &right) {
    return Vector<T>();
}

template<typename T>
Vector<T> operator*(const int &left, const Vector<T> &right) {
    return Vector<T>();
}
