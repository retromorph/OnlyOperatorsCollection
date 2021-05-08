#ifndef IENUMERABLE_H
#define IENUMERABLE_H

template<typename T>
class IEnumerable {
public:
    virtual IEnumerator <T> getEnumerator() = 0;

    virtual ~IEnumerable() = default;
};

#endif
