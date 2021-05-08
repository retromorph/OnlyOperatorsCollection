#ifndef ICOLLECTION_H
#define ICOLLECTION_H

#include "IEnumerable.h"

template<typename T>
class ICollection : IEnumerable<T> {
public:
    // add(T)
    virtual ICollection<T> operator<<(T &source) = 0;

    // remove(T)
    virtual ICollection<T> operator>>(T &source) = 0;

    // remove(std::size_t)
    virtual ICollection<T> operator>>(std::size_t idx) = 0;

    // contains(T)
    virtual bool operator<<=(T &source) = 0;

    // clear(T)
    virtual ICollection<T> operator!() = 0;

    virtual void copyTo(T *dest, std::size_t amount) = 0;

    // getEnumerator()
    virtual IEnumerator<T> operator~() = 0;

    virtual ~ICollection() = default;
};

#endif
