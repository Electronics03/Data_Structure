#include <iostream>
#include <string>
#include <list>
#include <vector>
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
    HashMap(int capacity = 100) : n(0), B(capacity) {}
    int size(void) const { return n; }
    bool empty(void) const { return (size() == 0); }

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
    using EItor = typename Bucket::iterator;
    using BItor = typename BktArray::iterator;
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
            if ((bkt != p.bkt) || (ba != p.ba))
                return false;
            else if (bkt == ba->end())
                return true;
            else
                return ent == p.ent;
        }
        bool operator!=(const Iterator &p) const
        {
            return !(*this == p);
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
        friend class HashMap<K, V, H>;
    };
};

template <typename K, typename V, typename H>
typename HashMap<K, V, H>::Iterator HashMap<K, V, H>::find(const K &k)
{
    Iterator it = finder(k);
    if (endOfBkt(it))
        return end();
    else
        return it;
}

template <typename K, typename V, typename H>
typename HashMap<K, V, H>::Iterator HashMap<K, V, H>::put(const K &k, const V &v)
{
    Iterator it = finder(k);
    if (endOfBkt(it))
        return inserter(it, EntryType(k, v));
    else
    {
        it.ent->setValue(v);
        return it;
    }
}

template <typename K, typename V, typename H>
void HashMap<K, V, H>::erase(const K &k)
{
    Iterator it = finder(k);
    if (endOfBkt(it))
        throw HashError("Erase of nonexistent");
    eraser(it);
}

template <typename K, typename V, typename H>
void HashMap<K, V, H>::erase(const Iterator &p)
{
    eraser(p);
}
int main()
{
    HashMap<std::string, int, std::hash<std::string>> map;

    map.put("apple", 100);
    map.put("banana", 200);
    map.put("cherry", 300);

    auto it = map.find("banana");
    if (it != map.end())
    {
        std::cout << "banana: " << (*it).value() << std::endl;
    }
    else
    {
        std::cout << "banana not found" << std::endl;
    }

    map.put("banana", 250);
    it = map.find("banana");
    if (it != map.end())
    {
        std::cout << "banana (updated): " << (*it).value() << std::endl;
    }

    map.erase("apple");
    it = map.find("apple");
    std::cout << "apple after erase: "
              << (it == map.end() ? "not found" : std::to_string((*it).value()))
              << std::endl;

    std::cout << "\nAll entries in map:\n";
    for (auto itr = map.begin(); itr != map.end(); ++itr)
    {
        std::cout << (*itr).key() << ": " << (*itr).value() << std::endl;
    }

    return 0;
}