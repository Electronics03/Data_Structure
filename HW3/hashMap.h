#ifndef HASHMAP_H
#define HASHMAP_H

#include <iostream>
#include <list>
#include <vector>
#include "hashError.h"

struct stringHash
{
    std::size_t operator()(const std::string &key) const
    {
        std::size_t hash = 0;
        for (char c : key)
        {
            hash = (hash * 31) + c;
        }
        return hash;
    }
};

template <typename K, typename V>
class Entry
{
public:
    Entry(const K &k = K(), const V &v = V()) : _key(k), _value(v) {}
    const K &key(void) const { return _key; }
    const V &value(void) const { return _value; }
    void setKey(const K &k) { _key = k; }
    void setValue(const V &v) { _value = v; }

private:
    K _key;
    V _value;
    template <typename, typename, typename>
    friend class HashMap;
};

template <typename K, typename V, typename H>
class HashMap
{
public:
    using EntryType = Entry<const K, V>;
    class Iterator;

public:
    HashMap(int capacity = 100);
    int size(void) const;
    bool empty(void) const;
    Iterator find(const K &k);
    Iterator put(const K &k, const V &v);
    void erase(const K &k);
    void erase(const Iterator &p);
    Iterator end(void);
    Iterator begin(void);

protected:
    using Bucket = std::list<EntryType>;
    using BktArray = std::vector<Bucket>;
    using EItor = typename Bucket::iterator;
    using BItor = typename BktArray::iterator;
    Iterator finder(const K &k);
    Iterator inserter(const Iterator &p, const EntryType &e);
    void eraser(const Iterator &p);
    static void nextEntry(Iterator &p)
    {
        ++p.ent;
    }
    static bool endOfBkt(const Iterator &p)
    {
        return (p.ent == p.bkt->end());
    }

private:
    int n;
    H hash;
    BktArray B;

public:
    class Iterator
    {
    private:
        EItor ent;
        BItor bkt;
        const BktArray *ba;

    public:
        Iterator(const BktArray &a, const BItor &b, const EItor &q = EItor()) : ent(q), bkt(b), ba(&a) {}
        EntryType &operator*() const;
        bool operator==(const Iterator &p) const;
        bool operator!=(const Iterator &p) const;
        Iterator &operator++(void);
        friend class HashMap<K, V, H>;
    };
};
#include "hashMap.cpp"
#endif