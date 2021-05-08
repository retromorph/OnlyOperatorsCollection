#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <memory>
#include "../_kernel/collection_interfaces/ICollection.h"

template<typename T>
class DynamicArray : ICollection<T> {
private:
    T *array;
    std::size_t guaranteedCapacity{};

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

    virtual ~DynamicArray();
};

#endif