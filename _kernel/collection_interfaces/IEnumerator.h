#ifndef IENUMERATOR_H
#define IENUMERATOR_H

template<typename T>
class IEnumerator {
public:
    virtual bool moveNext() = 0;

    virtual T current() = 0;

    virtual void reset() = 0;

    virtual ~IEnumerator() = default;
};

#endif
