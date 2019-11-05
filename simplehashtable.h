#ifndef SIMPLEHASHTABLE_H
#define SIMPLEHASHTABLE_H

#include <type_traits>

#include "hashable.h"

using namespace std;

constexpr int DEFAULT_CAPACITY = 100;

template <typename T>
class SimpleHashTable
{
    static_assert(is_base_of<Hashable, T>::value, "T must inherit from Hashable");

public:
    SimpleHashTable();

    explicit SimpleHashTable(size_t capacity);

    virtual ~SimpleHashTable();

    void insert(T data);

    void remove(T data);

    T* find(T data) const;

    bool exists(T data) const;
private:
    int calcPosFromHash(T data) const;

    T** array;
    size_t capacity;
};

template <typename T>
SimpleHashTable<T>::SimpleHashTable(): capacity(DEFAULT_CAPACITY)
{
    array = new T*[capacity];
}

template<typename T>
SimpleHashTable<T>::SimpleHashTable(size_t capacity): capacity(capacity)
{
    array = new T*[capacity];
}

template <typename T>
SimpleHashTable<T>::~SimpleHashTable() = default;

template <typename T>
void SimpleHashTable<T>::insert(T data)
{
    array[calcPosFromHash(data)] = &data;
}

template <typename T>
void SimpleHashTable<T>::remove(T data)
{
    array[calcPosFromHash(data)] = nullptr;
}

template <typename T>
T* SimpleHashTable<T>::find(T data) const
{
    return array[calcPosFromHash(data)];
}

template <typename T>
bool SimpleHashTable<T>::exists(T data) const
{
    T* value = array[calcPosFromHash(data)];

    return value != nullptr;
}

template<typename T>
int SimpleHashTable<T>::calcPosFromHash(T data) const {
    int k = data.hashCode();

    return k % DEFAULT_CAPACITY;
}

#endif // SIMPLEHASHTABLE_H
