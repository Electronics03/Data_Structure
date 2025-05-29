#include <iostream>
#include <cstdlib>
#include <list>
#include <vector>

template <typename K, typename V>
class Entry
{
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
    using EntryType = Entry<K, V>;
    using Bucket = std::list<EntryType>;
    using BktArray = std::vector<Bucket>;
    using Iterator = typename std::list<EntryType>::iterator;

public:
    int size(void) const { return data.size(); }
    bool empty(void) const { return data.empty(); }
    Iterator find(const K &k) const;
    Iterator put(const K &k, const V &v);
    void erase(const K &k);
    Iterator begin(void) const { return data.begin(); }
    Iterator end(void) const { return data.end(); }
    void printEnt(void) const;

private:
    int n;
    H hash;
    BktArray B;
};