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
    using EntryType = Entry<const K, V>;
    class Iterator;

public:
    HashMap(int capacity = 100);
    int size(void) const;
    bool empty(void) const;
    Iterator find(const K &k);
    Iterator put(const K &k, const V &v);
    void erase(const K &k);
    void erase(const Iterator &k);
    Iterator begin(void);
    Iterator end(void);

protected:
    using Bucket = std::list<EntryType>;
    using BktArray = std::vector<Bucket>;
    using EItor = Bucket::iterator;
    using BItor = BktArray::iterator;

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
        Entry &operator*() const;
        bool operator==(const Iterator &p) const;
        Iterator &operator++(void);
        friend class HashMap;
    };
};