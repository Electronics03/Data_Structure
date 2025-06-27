#include <iostream>
#include <cstdlib>
#include <string>
#include <list>
#include "DataError.h"

using Elem = std::string;
using Key = int;
class Heap
{
protected:
    struct Node
    {
        Elem elt;
        Key k;
        Node *par;
        Node *left;
        Node *right;
        Node() : elt(), k(), par(nullptr), left(nullptr), right(nullptr) {};
    };

public:
    class Position
    {
    private:
        Node *v;

    public:
        Position(Node *_v = nullptr) : v(_v) {};
        Elem &operator*(void) const { return v->elt; }
        Key &getKey(void) const { return v->k; }
        bool operator<(const Position &p) const { return v->k < p.v->k; }
        bool operator>(const Position &p) const { return v->k > p.v->k; }
        bool operator<=(const Position &p) const { return v->k <= p.v->k; }
        bool operator>=(const Position &p) const { return v->k >= p.v->k; }
        bool operator==(const Position &p) const { return v->k == p.v->k; }
        bool operator!=(const Position &p) const { return v->k != p.v->k; }
        Position left(void) { return Position(v->left); }
        Position right(void) { return Position(v->right); }
        Position parent(void) { return Position(v->par); }
        bool hasLeft(void) { return (v->left != nullptr); }
        bool hasRight(void) { return (v->right != nullptr); }
        bool isRoot(void) { return (v->par == nullptr); }
        bool isLeft(void) { return (v->par->left == v); }
        bool isRight(void) { return (v->par->right == v); }
        bool isExternal(void) { return (v->left == nullptr) && (v->right == nullptr); }
        friend class Heap;
    };
    using PositionList = std::list<Position>;

public:
    Heap();
    int size(void) const;
    bool empty(void) const;
    Position root(void);
    Position last(void);
    void addLast(const Elem &elt, const Key &k);
    void removeLast(void);
    void swap(const Position &p, const Position &q);
    void insert(const Elem &elt, const Key &k);
    void removeMax(void);

protected:
    void preorder(Node *v, PositionList &pl);
    void inorder(Node *v, PositionList &pl);

private:
    Node *_root;
    Node *_last;
    int n;
};
Heap::Heap() : _root(nullptr), n(0) {}
int Heap::size(void) const { return n; }
bool Heap::empty(void) const { return _root == nullptr; }
Heap::Position Heap::root(void) { return Position(_root); }
Heap::Position Heap::last(void) { return Position(_last); }
void Heap::addLast(const Elem &elt, const Key &k)
{
    Node *u = new Node;
    u->elt = elt;
    u->k = k;
    if (empty())
    {
        _root = u;
        _last = u;
        n++;
        return;
    }
    else
    {
        if (Position(_last).isRoot())
        {
            _last->left = u;
            u->par = _last;
            _last = u;
            n++;
            return;
        }
        if (Position(_last).isLeft())
        {
            _last->par->right = u;
            u->par = _last->par;
            _last = u;
            n++;
            return;
        }
        Node *tmp = _last;
        while (tmp->par != nullptr && Position(tmp).isRight())
            tmp = tmp->par;
        if (!Position(tmp).isRoot())
            tmp = tmp->par->right;
        while (tmp->left != nullptr)
            tmp = tmp->left;
        tmp->left = u;
        u->par = tmp;
        _last = u;
        n++;
        return;
    }
}
void Heap::removeLast(void)
{
    if (empty())
        throw TreeError("Error: Tree is empty.");
    if (Position(_last).isRoot())
    {
        delete _root;
        _root = nullptr;
        _last = nullptr;
        n = 0;
        return;
    }
    Node *u = _last;
    if (Position(_last).isRight())
    {
        _last = u->par->left;
        u->par->right = nullptr;
        delete u;
        n--;
        return;
    }
    Node *tmp = _last;
    while (tmp->par != nullptr && Position(tmp).isLeft())
        tmp = tmp->par;
    if (!Position(tmp).isRoot())
        tmp = tmp->par->left;
    while (tmp->right != nullptr)
        tmp = tmp->right;
    u->par->left = nullptr;
    delete u;
    _last = tmp;
    n--;
    return;
}
void Heap::swap(const Position &p, const Position &q)
{
    Elem tmpElt = *p;
    Key tmpKey = p.getKey();
    *p = *q;
    p.getKey() = q.getKey();
    *q = tmpElt;
    q.getKey() = tmpKey;
}
void Heap::insert(const Elem &elt, const Key &k)
{
    addLast(elt, k);
    Position v = last();
    while (!v.isRoot() && (v > v.parent()))
    {
        swap(v, v.parent());
        v = v.parent();
    }
}
void Heap::removeMax(void)
{
    if (empty())
        throw TreeError("Error: Tree is empty.");

    swap(root(), last());
    removeLast();

    if (empty())
        return;

    Position v = root();

    while (v.hasLeft())
    {
        Position bigChild = v.left();
        if (v.hasRight() && v.right() > v.left())
            bigChild = v.right();

        if (v >= bigChild)
            break;

        swap(v, bigChild);
        v = bigChild;
    }
}

void Heap::preorder(Node *v, PositionList &pl)
{
    pl.push_back(Position(v));
    if (v->left != nullptr)
        preorder(v->left, pl);
    if (v->right != nullptr)
        preorder(v->right, pl);
}
void Heap::inorder(Node *v, PositionList &pl)
{
    if (v->left != nullptr)
        inorder(v->left, pl);
    pl.push_back(Position(v));
    if (v->right != nullptr)
        inorder(v->right, pl);
}
int main()
{
    Heap h;
    h.insert("A", 4);
    h.insert("B", 2);
    h.insert("C", 5);
    h.insert("D", 1);
    h.insert("E", 10);
    h.insert("F", 8);
    h.insert("G", 3);
    h.insert("H", 6);

    while (!h.empty())
    {
        std::cout << *h.root() << " (" << h.root().getKey() << ")\n";
        h.removeMax();
    }
}
