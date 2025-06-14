#include "hashMap.h"

#include <iostream>
#include <list>
#include <vector>

/*=======<HashMap>=======*/
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
        return inserter(p, EntryType(k, v));
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
        throw NonexistentElement("Erase of nonexistent");
    eraser(p);
}

template <typename K, typename V, typename H>
void HashMap<K, V, H>::erase(const Iterator &p)
{
    eraser(p);
}

template <typename K, typename V, typename H>
typename HashMap<K, V, H>::Iterator HashMap<K, V, H>::end(void) { return Iterator(B, B.end()); }

template <typename K, typename V, typename H>
typename HashMap<K, V, H>::Iterator HashMap<K, V, H>::begin(void)
{
    if (empty())
        return end();
    BItor bkt = B.begin();
    while (bkt->empty())
        ++bkt;
    return Iterator(B, bkt, bkt->begin());
}

template <typename K, typename V, typename H>
typename HashMap<K, V, H>::Iterator HashMap<K, V, H>::finder(const K &k)
{
    int i = hash(k) % B.size();
    BItor bkt = B.begin() + i;
    Iterator p(B, bkt, bkt->begin());

    while (!endOfBkt(p) && (*p).key() != k)
        nextEntry(p);
    return p;
}

template <typename K, typename V, typename H>
typename HashMap<K, V, H>::Iterator HashMap<K, V, H>::inserter(const Iterator &p, const EntryType &e)
{
    EItor ins = p.bkt->insert(p.ent, e);
    n++;
    return Iterator(B, p.bkt, ins);
}
template <typename K, typename V, typename H>

void HashMap<K, V, H>::eraser(const Iterator &p)
{
    p.bkt->erase(p.ent);
    n--;
}

/*=======<Iterator>=======*/
template <typename K, typename V, typename H>
typename HashMap<K, V, H>::EntryType &HashMap<K, V, H>::Iterator::operator*() const { return *ent; }

template <typename K, typename V, typename H>
bool HashMap<K, V, H>::Iterator::operator==(const Iterator &p) const
{
    if ((ba != p.ba) || (bkt != p.bkt))
        return false;
    else if (bkt == ba->end())
        return true;
    else
        return (ent == p.ent);
}

template <typename K, typename V, typename H>
bool HashMap<K, V, H>::Iterator::operator!=(const Iterator &p) const
{
    return !(*this == p);
}

template <typename K, typename V, typename H>
typename HashMap<K, V, H>::Iterator &HashMap<K, V, H>::Iterator::operator++(void)
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
template class HashMap<std::string, int, stringHash>;
