#include <iostream>
#include <cstdlib>
#include <list>
#include <vector>
#include "DataError.h"

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
    Iterator end(void) { return Iterator(B, B.end()); }
    Iterator begin(void)
    {
        if (empty())
            return end();
        BItor bkt = B.begin();
        while (bkt->empty())
            ++bkt;
        return Iterator(B, bkt, bkt->begin());
    }

protected:
    using Bucket = std::list<EntryType>;
    using BktArray = std::vector<Bucket>;
    using EItor = Bucket::iterator;
    using BItor = BktArray::iterator;
    Iterator finder(const K &k)
    {
        int i = hash(k) % B.size();
        BItor bkt = B.begin() + i;
        Iterator p(B, bkt, bkt->begin());

        while (!endOfBkt(p) && (*p).key() != k)
            nextEntry(p);
        return p;
    }
    Iterator inserter(const Iterator &p, const EntryType &e)
    {
        EItor ins = p.bkt->insert(p.ent, e);
        n++;
        return Iterator(B, p.bkt, ins);
    }
    void eraser(const Iterator &p)
    {
        p.bkt->erase(p.ent);
        n--;
    }
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
        EntryType &operator*() const { return *ent; }
        bool operator==(const Iterator &p) const
        {
            if ((ba != p.ba) || (bkt != p.bkt))
                return false;
            else if (bkt == ba->end())
                return true;
            else
                return (ent == p.ent);
        }
        Iterator &operator++(void)
        {
            ++ent;
            if (endOfBkt(*this))
            {
                ++bkt;
                while (bkt != ba->end() && bkt->empty())
                    ++bkt;
                if (bkt == ba->end())
                    return *this;
                ent = bkt->begin();
            }
            return *this;
        }
        friend class HashMap;
    };
};
template <typename K, typename V, typename H>
HashMap<K, V, H>::HashMap(int capacity) : n(0), B(capacity) {}

template <typename K, typename V, typename H>
int HashMap<K, V, H>::size(void) const { return n; }

template <typename K, typename V, typename H>
bool HashMap<K, V, H>::empty(void) const { return (size() == 0); }

template <typename K, typename V, typename H>
typename HashMap<K, V, H>::Iterator HashMap<K, V, H>::find(const K &k)
{
    Iterator p = finder(k);
    if (endOfBkt(p))
        return end();
    else
        return p;
}

template <typename K, typename V, typename H>
typename HashMap<K, V, H>::Iterator HashMap<K, V, H>::put(const K &k, const V &v)
{
    Iterator p = finder(k);
    if (endOfBkt(p))
        return Iterator(p, Entry(k, v));
    else
    {
        p.ent->setValue(v);
        return p;
    }
}

template <typename K, typename V, typename H>
void HashMap<K, V, H>::erase(const K &k)
{
    Iterator p = finder(k);
    if (endOfBkt(p))
        throw HashError("Erase of nonexistent");
    eraser(p);
}

template <typename K, typename V, typename H>
void HashMap<K, V, H>::erase(const Iterator &p)
{
    eraser(p);
}