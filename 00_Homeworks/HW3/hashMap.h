#pragma once

#include <iostream>
#include <list>
#include <vector>
#include "hashError.h"

/*=======<stringHash struct>=======*/
// Hash funtion of std::string type
// std::string -> std::size_t (integer)
struct stringHash
{
    std::size_t operator()(const std::string &key) const
    {
        std::size_t hash = 0;
        // Initialization
        for (char c : key)
        {
            // Processing each character in string
            hash = (hash * 31) + c;
            // Hash function using multiplier 31
        }
        return hash;
    }
};

/*=======<Entry Class>=======*/
// Key-Value entry type stored in hash map
template <typename K, typename V>
class Entry
{
public:
    Entry(const K &k = K(), const V &v = V()) : _key(k), _value(v) {}
    // Constructor
    const K &key(void) const { return _key; }     // Return key
    const V &value(void) const { return _value; } // Return value
    void setKey(const K &k) { _key = k; }         // Set key
    void setValue(const V &v) { _value = v; }     // Set value

private:
    K _key;   // Entry key
    V _value; // Entry value
    template <typename, typename, typename>
    friend class HashMap;
};

/*=======<HashMap Class>=======*/
// HashMap class using separate chaining
template <typename K, typename V, typename H>
class HashMap
{
public:
    using EntryType = Entry<const K, V>; // Const key entries
    class Iterator;                      // Forward declaration of iterator

public:
    HashMap(int capacity = 100);          // Constructor with initial capacity
    int size(void) const;                 // Return number of entries
    bool empty(void) const;               // Check if hash map is empty
    Iterator find(const K &k);            // Find entry with key
    Iterator put(const K &k, const V &v); // Insert or update entry
    void erase(const K &k);               // Remove entry by key
    void erase(const Iterator &p);        // Remove entry by iterator
    Iterator end(void);                   // Return iterator to first entry
    Iterator begin(void);                 // Return iterator to end

protected:
    using Bucket = std::list<EntryType>;       // A bucket is a list of entries
    using BktArray = std::vector<Bucket>;      // Hash table is an array of buckets
    using EItor = typename Bucket::iterator;   // Entry iterator type
    using BItor = typename BktArray::iterator; // Bucket iterator type

    Iterator finder(const K &k);                              // Find helper
    Iterator inserter(const Iterator &p, const EntryType &e); // Insert helper
    void eraser(const Iterator &p);                           // Erase helper
    static void nextEntry(Iterator &p) { ++p.ent; }           // Advance entry in bucket
    static bool endOfBkt(const Iterator &p)
    { // Check if entry iterator is at bucket end
        return (p.ent == p.bkt->end());
    }

private:
    int n;
    H hash;
    BktArray B;

public:
    /*=======<HashMap::Iterator Class>=======*/
    class Iterator
    {
    private:
        EItor ent;          // Check if entry iterator is at bucket end
        BItor bkt;          // Current bucket iterator
        const BktArray *ba; // Pointer to the bucket array

    public:
        Iterator(const BktArray &a, const BItor &b, const EItor &q = EItor()) : ent(q), bkt(b), ba(&a) {}
        // Constructor Iterator
        EntryType &operator*() const;             // Dereference
        bool operator==(const Iterator &p) const; // Equality check
        Iterator &operator++(void);               // Move to next entry
        friend class HashMap<K, V, H>;
    };
};