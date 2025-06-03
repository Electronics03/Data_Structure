#pragma once

#include <vector>

template <typename E>
struct Comparator
{
    bool operator()(const E &a, const E &b) const
    {
        return a < b;
    }
};

template <typename E>
class VectorCompleteTree
{
private:
    std::vector<E> V;

protected:
    typedef typename std::vector<E>::iterator Position;
    Position pos(int i) { return V.begin() + i; }
    int idx(const Position &p) const { return p - V.begin(); }

public:
    VectorCompleteTree() : V(1) {}
    int size(void) const { return V.size() - 1; }
    Position left(const Position &p) { return pos(2 * idx(p)); }
    Position right(const Position &p) { return pos(2 * idx(p) + 1); }
    Position parent(const Position &p) { return pos(idx(p) / 2); }
    bool hasLeft(const Position &p) const { return 2 * idx(p) <= size(); }
    bool hasRight(const Position &p) const { return 2 * idx(p) + 1 <= size(); }
    bool isRoot(const Position &p) const { return idx(p) == 1; }
    Position root(void) { return pos(1); }
    Position last(void) { return pos(size()); }
    void addLast(const E &e) { V.push_back(e); }
    void removeLast(void) { V.pop_back(); }
    void swap(const Position &p, const Position &q)
    {
        E e = *q;
        *q = *p;
        *p = e;
    }
};

template <typename E, typename C>
class HeapPriorityQueue
{
public:
    typename std::vector<E>::iterator root(void) { return T.root(); }
    int size(void) const;
    bool empty(void) const;
    void insert(const E &e);
    const E &min(void);
    void removeMin(void);

private:
    VectorCompleteTree<E> T;
    C isLess;
    typedef typename std::vector<E>::iterator Position;
};
