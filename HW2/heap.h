#pragma once

#include <vector>

template <typename E>
struct Comparator
{
    bool operator()(const E &a, const E &b) const
    {
        return a < b;
        // Return the result of comparing two values
    }
};

template <typename E>
class VectorCompleteTree
{
private:
    std::vector<E> V;
    // Define a vector to store the data

protected:
    using Position = typename std::vector<E>::iterator;
    // Use the vector's iterator type as Position
    Position pos(int i) { return V.begin() + i; }
    // Return the Position(iterator) at index i
    int idx(const Position &p) const { return p - V.begin(); }
    // Return the index of the given Position(iterator)

public:
    VectorCompleteTree() : V(1) {}
    // Tree constructor
    // The root exists at index 1
    int size(void) const { return V.size() - 1; }
    // Returns the size of the complete binary tree
    // Since the root is placed at index 1, the vector size is one larger
    // So we return one less than the vector size
    Position left(const Position &p) { return pos(2 * idx(p)); }
    // Returns the Position of the left child
    // In a complete binary tree stored in a vector, we can access it with index calculation
    Position right(const Position &p) { return pos(2 * idx(p) + 1); }
    // Returns the Position of the right child
    Position parent(const Position &p) { return pos(idx(p) / 2); }
    // Returns the Position of the parent
    // Integer division allows access to the parent regardless of left/right child
    bool hasLeft(const Position &p) const { return 2 * idx(p) <= size(); }
    // Checks whether the left child exists
    // Uses the size function to verify the index is within the vector bounds
    bool hasRight(const Position &p) const { return 2 * idx(p) + 1 <= size(); }
    // Checks whether the right child exists
    bool isRoot(const Position &p) const { return idx(p) == 1; }
    // Checks if the node is the root
    // Just check if its index is 1
    Position root(void) { return pos(1); }
    // Returns the Position of the root
    Position last(void) { return pos(size()); }
    // Returns the Position of the last node
    void addLast(const E &e) { V.push_back(e); }
    // Adds a new element at the end
    void removeLast(void) { V.pop_back(); }
    // Removes the last node
    void swap(const Position &p, const Position &q)
    {
        E e = *q;
        *q = *p;
        *p = e;
    }
    // Swaps the values of two nodes
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
