#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "String.h"

template <class T2>
class HashTable
{
public:
    constexpr static int SIZE = 1200000;
    T2* data;

    HashTable();
    ~HashTable();
    T2& operator[](const String& key);
    int hash(const String& key);
};

#endif

template<class T2>
HashTable<T2>::HashTable()
{
    data = new T2[SIZE];
}

template<class T2>
HashTable<T2>::~HashTable()
{
    delete[] data;
}

template<class T2>
T2& HashTable<T2>::operator[](const String& key)
{
    return data[hash(key)];
}

template<class T2>
int HashTable<T2>::hash(const String& key) //SDBM algorithm
{
    unsigned long hash = 0;
    int c;
    char* str = key.cstring;

    while (c = *str++)
        hash = c + (hash << 6) + (hash << 16) - hash;

    return hash % SIZE;
}
