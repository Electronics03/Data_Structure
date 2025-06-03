#include "heap.h"

template <typename E, typename C>
int HeapPriorityQueue<E, C>::size(void) const
{
    return T.size();
    // Returns the size of the complete binary tree
}
template <typename E, typename C>
bool HeapPriorityQueue<E, C>::empty(void) const
{
    return T.size() == 0;
    // Checks if the tree size is zero
    // The root node is located at index 1
    // If the tree is empty, only index 0 exists, so size becomes 1 - 1 = 0
}
template <typename E, typename C>
const E &HeapPriorityQueue<E, C>::min(void)
{
    return *(T.root());
    // Returns the element at the root
    // The root node always holds the minimum element
}
template <typename E, typename C>
void HeapPriorityQueue<E, C>::insert(const E &e)
{
    T.addLast(e);
    // Add the element to the last position
    Position v = T.last();
    // Declare v as the Position of the last node
    while (!T.isRoot(v))
    {
        Position u = T.parent(v);
        // Declare u as the parent of v
        if (!isLess(*v, *u))
        {
            // Compare u and v
            // If the child (v) is not less than the parent (u), stop swapping
            break;
        }
        T.swap(v, u);
        // Swap the nodes until the loop terminates
        v = u;
        // Move up to the parent node
    }
}
template <typename E, typename C>
void HeapPriorityQueue<E, C>::removeMin(void)
{
    // The root node holds the minimum element, so we remove it
    // Reorganize the tree to maintain the heap property

    if (size() == 1)
    {
        T.removeLast();
        // If the heap has only one node, remove the last node (which is the root)
    }
    else
    {
        Position u = T.root();
        // Declare u as the root node
        T.swap(u, T.last());
        // Swap the root (u) with the last node
        T.removeLast();
        // Remove the last node (which was originally the root, i.e., the minimum)

        while (T.hasLeft(u))
        {
            Position v = T.left(u);
            // Declare v as the left child of u

            if (T.hasRight(u) && isLess(*(T.right(u)), *v))
            {
                // Compare the left and right children
                // If the right child is smaller, set v to the right child
                // Choose the smaller child as v
                v = T.right(u);
            }
            if (isLess(*v, *u))
            {
                // Compare the parent (u) with the smaller child (v)
                // If the child is smaller, swap the values
                T.swap(u, v);
                u = v;
                // Move down to the child node
            }
            else
            {
                // Stop if the parent is smaller than both children
                break;
            }
        }
    }
}

template class HeapPriorityQueue<int, Comparator<int>>;
template class HeapPriorityQueue<char, Comparator<char>>;
