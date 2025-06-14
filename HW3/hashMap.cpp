#include "hashMap.h"

#include <iostream>
#include <list>
#include <vector>

/*=======<HashMap>=======*/
template <typename K, typename V, typename H>
HashMap<K, V, H>::HashMap(int capacity) : n(0), B(capacity) {}
// Constructor: initialize hash tabl

template <typename K, typename V, typename H>
int HashMap<K, V, H>::size(void) const { return n; }
// Return the number of entries

template <typename K, typename V, typename H>
bool HashMap<K, V, H>::empty(void) const { return (size() == 0); }
// Check if the hash map is empty

template <typename K, typename V, typename H>
typename HashMap<K, V, H>::Iterator HashMap<K, V, H>::find(const K &k)
{
    // Search for key
    Iterator p = finder(k);
    if (endOfBkt(p))
        return end();
    else
        return p;
    // entry if not found -> return end()
    // else return Iterator p
}

template <typename K, typename V, typename H>
typename HashMap<K, V, H>::Iterator HashMap<K, V, H>::put(const K &k, const V &v)
{
    // Insert or update the key-value pair
    // Search for key
    Iterator p = finder(k);
    if (endOfBkt(p))
        return inserter(p, EntryType(k, v));
    else
    {
        p.ent->setValue(v);
        // using STL iterator -> using STL func setValue()
        // update value
        return p;
    }
    // entry if not found -> Insert new entry
    // else update value
    // return Iterator of entry
}

template <typename K, typename V, typename H>
void HashMap<K, V, H>::erase(const K &k)
{
    // Search for key
    Iterator p = finder(k);
    if (endOfBkt(p))
        throw NonexistentElement("Erase of nonexistent");
    // throw an exception if not found
    eraser(p);
    // Erase the entry with key
}

template <typename K, typename V, typename H>
void HashMap<K, V, H>::erase(const Iterator &p)
{
    // Erase entry pointed to by iterator
    eraser(p);
}

template <typename K, typename V, typename H>
typename HashMap<K, V, H>::Iterator HashMap<K, V, H>::end(void) { return Iterator(B, B.end()); }
// Return iterator pointing to end of hash table
// Even if there is no entry, just pointing to end of hash table
// using STL iterator -> using STL func end()

template <typename K, typename V, typename H>
typename HashMap<K, V, H>::Iterator HashMap<K, V, H>::begin(void)
{
    // Return iterator pointing to the first valid entry in the hash table
    if (empty())
        return end();
    // There is no entry, return end of hash table
    BItor bkt = B.begin();
    while (bkt->empty())
        ++bkt;
    // Find first valid entry
    // Start at first point of hash table

    // return Iterator
    return Iterator(B, bkt, bkt->begin());
}

template <typename K, typename V, typename H>
typename HashMap<K, V, H>::Iterator HashMap<K, V, H>::finder(const K &k)
{
    // Internal helper to find an entry with key
    int i = hash(k) % B.size();
    // get bucket index
    BItor bkt = B.begin() + i;
    // Go to bucket by index i
    Iterator p(B, bkt, bkt->begin());
    // New iterator

    while (!endOfBkt(p) && (*p).key() != k)
        nextEntry(p);
    // Find Entry in bucket by key

    return p; // Return iterator
}

template <typename K, typename V, typename H>
typename HashMap<K, V, H>::Iterator HashMap<K, V, H>::inserter(const Iterator &p, const EntryType &e)
{
    EItor ins = p.bkt->insert(p.ent, e);
    // Insert entry e before p.ent
    // using STL iterator -> using STL func insert()
    // If p.ent is at the trailer
    // then the new entry is appended to the end of the bucket.

    n++;                            // Increase number of entry
    return Iterator(B, p.bkt, ins); // Return iterator
}
template <typename K, typename V, typename H>

void HashMap<K, V, H>::eraser(const Iterator &p)
{
    p.bkt->erase(p.ent);
    // erase entry p.ent
    // bucket : list, p.ent :  list::iterator
    // using STL iterator -> using STL func erase()
    n--;
}

/*=======<Iterator>=======*/
template <typename K, typename V, typename H>
typename HashMap<K, V, H>::EntryType &HashMap<K, V, H>::Iterator::operator*() const { return *ent; }
// Dereference operator: return reference to the current entry

template <typename K, typename V, typename H>
bool HashMap<K, V, H>::Iterator::operator==(const Iterator &p) const
{
    // Equality comparison operator
    if ((ba != p.ba) || (bkt != p.bkt))
        return false;
    else if (bkt == ba->end())
        return true; // both at end
    else
        return (ent == p.ent);
}

template <typename K, typename V, typename H>
typename HashMap<K, V, H>::Iterator &HashMap<K, V, H>::Iterator::operator++(void)
{
    // Pre-increment operator: move to next entry in hash table
    ++ent; // move to next in current bucke
    // move to next bucket
    // using STL iterator -> using ++
    // ++ if pre-overoded
    if (endOfBkt(*this))
    {
        // if entry is end of bucket
        ++bkt; // move to next bucket

        while (bkt != ba->end() && bkt->empty())
            ++bkt; // find non-empty bucket
        if (bkt == ba->end())
            return *this;   // if end of bucket vector
        ent = bkt->begin(); // first entry in new bucket
    }
    return *this; // return Iterator
}

template class HashMap<std::string, int, stringHash>;
