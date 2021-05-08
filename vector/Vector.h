#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <complex>
#include "../_kernel/collections/ICollection.h"

//template<typename T>
//constexpr bool whole_or_real_or_complex = std::is_same<T, short>::value || std::is_same<T, int>::value
//                                          || std::is_same<T, long>::value || std::is_same<T, long long>::value
//                                          || std::is_same<T, float>::value || std::is_same<T, double>::value
//                                          || std::is_same<T, long double>::value ||
//                                          std::is_same<T, std::complex<short>>::value
//                                          || std::is_same<T, std::complex<int>>::value ||
//                                          std::is_same<T, std::complex<int>>::value

template<typename T>
class Vector : ICollection<T> {
//    static_assert(whole_or_real_or_complex<T>, "Can't create class Vector because T is not whole, real or complex");
private:
    T *repr;
    size_t dimension{};
public:
    explicit Vector(size_t dimension);

    explicit Vector(T dimension[]);

    virtual T norm();

    friend Vector<T> operator+(const Vector<T> &left, const Vector<T> &right);

    friend Vector<T> operator*(const Vector<T> &left, const Vector<T> &right);

    friend Vector<T> operator*(const int &left, const Vector<T> &right);

    virtual void add(T) {

    }

    virtual void remove(T) = 0;

    virtual bool contains(T) = 0;

    virtual void clear() = 0;

    virtual void copyTo(T[], int) = 0;

    virtual IEnumerable<T> getEnumerator() = 0;
};

#endif
