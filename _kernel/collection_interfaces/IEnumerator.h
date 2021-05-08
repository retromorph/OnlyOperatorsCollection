#ifndef IENUMERATOR_H
#define IENUMERATOR_H

#include <functional>
#include <any>

// stream[tuple<int, int, int>]
// stream -> map(T) -> T, filter(T) -> bool
template<typename T>
class IEnumerator {
public:
    // moveNext()
    virtual IEnumerator<T> &operator++() = 0;

    // current()
    virtual T &operator()() = 0;

    // reset()
    virtual IEnumerator<T> &operator!() = 0;

    // slice(std::size_t, std::size_t)
    virtual IEnumerator<T> &operator[](std::tuple<std::size_t, std::size_t>) = 0;

    // slice(std::size_t, std::size_t, std::size_t)
    virtual IEnumerator<T> &operator[](std::tuple<std::size_t, std::size_t, std::size_t>) = 0;

    // find(IEnumerator<T>)
    virtual IEnumerator<T> &operator<<=(IEnumerator<T>) = 0;

    // merge(IEnumerator, IEnumerator)
    virtual IEnumerator<T> &operator+(IEnumerator<T> &second) = 0;

    virtual IEnumerator<std::any> map(std::function<std::any(T)> transformator) = 0;

    virtual std::size_t where(T toFind) = 0;

    virtual std::any reduce(std::function<std::any(T)> transformator, std::any accum) = 0;

    virtual IEnumerator<T> filter(std::function<bool(T)> predicate) = 0;

    virtual ~IEnumerator() = default;
};

#endif
