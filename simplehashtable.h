#ifndef SIMPLEHASHTABLE_H
#define SIMPLEHASHTABLE_H

#include <type_traits>

using namespace std;

constexpr int DEFAULT_CAPACITY = 100;

template <typename T, typename K>
class SimpleHashTable
{
    //static_assert(is_base_of<Hashable, T>::value, "T must inherit from Hashable");

public:
    SimpleHashTable();

    explicit SimpleHashTable(size_t capacity);

    virtual ~SimpleHashTable();

    void put(K key, T data);

    T* get(K key) const;

    void remove(K key);

    bool exists(K key) const;
private:
    size_t calcPosFromKey(K key) const;

    T** array;
    size_t capacity;
};

template <typename T, typename K>
SimpleHashTable<T, K>::SimpleHashTable(): capacity(DEFAULT_CAPACITY)
{
    array = new T*[capacity];
}

template <typename T, typename K>
SimpleHashTable<T, K>::SimpleHashTable(size_t capacity): capacity(capacity)
{
    array = new T*[capacity];
}

template <typename T, typename K>
SimpleHashTable<T, K>::~SimpleHashTable() = default;

template <typename T, typename K>
void SimpleHashTable<T, K>::put(K key, T data)
{
    array[calcPosFromKey(key)] = &data;
}

template <typename T, typename K>
T* SimpleHashTable<T, K>::get(K key) const
{
    return array[calcPosFromKey(key)];
}

template <typename T, typename K>
void SimpleHashTable<T, K>::remove(K key)
{
    array[calcPosFromKey(key)] = nullptr;
}

template <typename T, typename K>
bool SimpleHashTable<T, K>::exists(K key) const
{
    return array[calcPosFromKey(key)] != nullptr;
}

template <typename T, typename K>
size_t SimpleHashTable<T, K>::calcPosFromKey(K key) const {
    size_t k = hash<K>{}(key);

    return k % capacity;
}

#endif // SIMPLEHASHTABLE_H
