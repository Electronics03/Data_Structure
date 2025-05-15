#include <iostream>
#include <cstdlib>
#include <list>
#include <string>
#include "DataError.h"

using Elem = std::string;

class LBinTree
{
protected:
    struct Node
    {
        Elem elt;
        Node *par;
        Node *left;
        Node *right;
        Node() : elt(), par(nullptr), left(nullptr), right(nullptr) {};
    };

public:
    class Position
    {
    private:
        Node *v;

    public:
        Position(Node *_v = nullptr) : v(_v) {};
        Elem &operator*(void) const { return v->elt; }
        Position left(void) { return Position(v->left); }
        Position right(void) { return Position(v->right); }
        Position parent(void) { return Position(v->par); }
        bool isRoot(void) { return (v->par == nullptr); }
        bool isExternal(void) { return (v->left == nullptr) && (v->right == nullptr); }
        friend class LBinTree;
    };
    using PositionList = std::list<Position>;

public:
    LBinTree();
    int size(void) const;
    bool empty(void) const;
    Position root(void);
    PositionList position(void);
    void addRoot(void);
    void expandExternal(const Position &p);
    Position removeAboveExternal(const Position &p);

protected:
    void preorder(Node *v, PositionList &pl);
    void inorder(Node *v, PositionList &pl);

private:
    Node *_root;
    int n;
};
LBinTree::LBinTree() : _root(nullptr), n(0) {}
int LBinTree::size(void) const { return n; }
bool LBinTree::empty(void) const { return _root == nullptr; }
LBinTree::Position LBinTree::root(void) { return Position(_root); }
LBinTree::PositionList LBinTree::position(void)
{
    PositionList pl;
    inorder(_root, pl);
    return pl;
}
void LBinTree::addRoot(void)
{
    if (!empty())
        throw TreeError("Error: Tree is not empty.");
    else
    {
        _root = new Node;
        n = 1;
    }
}
void LBinTree::expandExternal(const Position &p)
{
    Node *v = p.v;
    v->left = new Node;
    v->left->par = v;
    v->right = new Node;
    v->right->par = v;
    n += 2;
}
LBinTree::Position LBinTree::removeAboveExternal(const Position &p)
{
    Node *w = p.v;
    Node *v = w->par;
    Node *sib = (w == v->left) ? v->right : v->left;
    if (v == _root)
    {
        _root = sib;
        sib->par = nullptr;
    }
    else
    {
        Node *gpar = v->par;
        if (v == gpar->left)
            gpar->left = sib;
        else
            gpar->right = sib;
        sib->par = gpar;
    }
    delete w;
    delete v;
    n -= 2;
    return Position(sib);
}
void LBinTree::preorder(Node *v, PositionList &pl)
{
    pl.push_back(Position(v));
    if (v->left != nullptr)
        preorder(v->left, pl);
    if (v->right != nullptr)
        preorder(v->right, pl);
}
void LBinTree::inorder(Node *v, PositionList &pl)
{
    if (v->left != nullptr)
        inorder(v->left, pl);
    pl.push_back(Position(v));
    if (v->right != nullptr)
        inorder(v->right, pl);
}
int main(void)
{
    LBinTree T;
    T.addRoot();
    LBinTree::Position p = T.root();
    *p = "+";
    T.expandExternal(p);
    p = p.left();
    *p = "*";
    p = p.parent();
    p = p.right();
    *p = "/";
    p = p.parent();
    p = p.left();
    T.expandExternal(p);
    p = p.left();
    *p = "3";
    p = p.parent();
    p = p.right();
    *p = "2";
    p = p.parent();
    p = p.parent();
    p = p.right();
    T.expandExternal(p);
    p = p.left();
    *p = "4";
    p = p.parent();
    p = p.right();
    *p = "6";
    LBinTree::PositionList pl = T.position();
    for (LBinTree::Position i : pl)
        std::cout << *i << std::endl;
    return 0;
}