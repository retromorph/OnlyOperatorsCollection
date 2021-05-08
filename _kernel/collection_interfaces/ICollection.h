#ifndef ICOLLECTION_H
#define ICOLLECTION_H

#include "IEnumerable.h"

template<typename T>
class ICollection: IEnumerable<T> {
public:
    virtual void add(T) = 0;

    virtual void remove(T) = 0;

    virtual bool contains(T) = 0;

    virtual void clear() = 0;

    virtual void copyTo(T[], int) = 0;

    virtual IEnumerable<T> getEnumerator() = 0;
};

#endif
