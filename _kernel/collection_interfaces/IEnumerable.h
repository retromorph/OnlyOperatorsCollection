#ifndef IENUMERABLE_H
#define IENUMERABLE_H

#include "IEnumerator.h"

template<typename T>
class IEnumerable {
public:
    virtual IEnumerator<T> operator~() = 0;

    virtual ~IEnumerable() = default;
};

#endif
