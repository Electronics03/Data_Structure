#include <iostream>
#include <string>
#include <list>
#include "DataError.h"

using namespace std;

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
    template <typename, typename>
    friend class Map;
};
template <typename K, typename V>
class Map
{
public:
    using EntryType = Entry<K, V>;
    using Iterator = typename list<EntryType>::iterator;
    using ConstIterator = typename list<EntryType>::const_iterator;

    int size(void) const { return data.size(); }
    bool empty(void) const { return data.empty(); }
    Iterator find(const K &k) const;
    Iterator put(const K &k, const V &v);
    void erase(const K &k);
    void erase(const Iterator &p);
    Iterator begin(void) const { return data.begin(); }
    Iterator end(void) const { return data.end(); }
    void printEnt(void) const;

private:
    list<EntryType> data;
};

template <typename K, typename V>
typename Map<K, V>::Iterator Map<K, V>::find(const K &k) const
{
    for (Iterator it = data.begin(); it != data.end(); ++it)
    {
        if (it->key() == k)
        {
            return it;
        }
        return data.end();
    }
}
template <typename K, typename V>
typename Map<K, V>::Iterator Map<K, V>::put(const K &k, const V &v)
{
    for (Iterator it = data.begin(); it != data.end(); ++it)
    {
        if (it->key() == k)
        {
            it->setValue(v);
            return it;
        }
    }
    data.push_back(EntryType(k, v));
    Iterator it = data.end();
    --it;
    return it;
}
template <typename K, typename V>
void Map<K, V>::erase(const K &k)
{
    for (Iterator it = data.begin(); it != data.end(); ++it)
    {
        if (it->key() == k)
        {
            data.erase(it);
            return;
        }
    }
}
template <typename K, typename V>
void Map<K, V>::erase(const Iterator &p)
{
    data.erase(p);
}
template <typename K, typename V>
void Map<K, V>::printEnt(void) const
{
    for (ConstIterator it = data.begin(); it != data.end(); ++it)
    {
        Entry<K, V> ent = *it;
        std::cout << "[" << ent.key() << ", " << ent.value() << "] ";
    }
    std::cout << std::endl;
}
int main(void)
{
    Map<std::string, int> myMap;
    Map<std::string, int>::Iterator p;
    myMap.put("Joe", 38);
    myMap.put("Joe", 50);
    myMap.put("Sue", 75);
    myMap.printEnt();
    myMap.erase("Joe");
    myMap.printEnt();
    return 0;
}