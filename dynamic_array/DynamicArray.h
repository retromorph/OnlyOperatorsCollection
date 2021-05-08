#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <memory>
#include "../_kernel/collection_interfaces/ICollection.h"

template<typename T>
class DynamicArray : ICollection<T> {
private:
    class DynamicArrayEnumerator : IEnumerator<T> {
        // moveNext()
        virtual IEnumerator<T> &operator++();

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

        virtual ~DynamicArrayEnumerator() = default;
    };

    T *array;
    std::size_t guaranteedCapacity{};
    DynamicArrayEnumerator<T> enumerator = DynamicArrayEnumerator<T>();

    virtual void resize();

    virtual void initialization();

protected:
    std::size_t size{};
public:
    explicit DynamicArray(std::size_t size);

    explicit DynamicArray(std::size_t size, const T &value);

    explicit DynamicArray(std::size_t size, T *toCopy);

    DynamicArray(const DynamicArray<T> &toCopy);


    virtual std::size_t getSize();

    virtual T &operator[](std::size_t idx);

    // add(T)
    virtual ICollection<T> operator<<(T &source);

    // remove(T)
    virtual ICollection<T> operator>>(T &source);

    // remove(std::size_t)
    virtual ICollection<T> operator>>(std::size_t idx);

    // contains(T)
    virtual bool operator<<=(T &source);

    // clear(T)
    virtual ICollection<T> operator!();

    virtual void copyTo(T *dest, std::size_t amount);

    // getEnumerator()
    virtual IEnumerator<T> operator~();

    virtual ~DynamicArray();
};

#endif