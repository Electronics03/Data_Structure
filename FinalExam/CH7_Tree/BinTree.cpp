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
        bool isRoot(void) { return v->par == nullptr; }
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
bool LBinTree::empty(void) const { return n == 0; }
LBinTree::Position LBinTree::root(void) { return Position(_root); }
LBinTree::PositionList LBinTree::position(void)
{
    PositionList pos;
    inorder(_root, pos);
    return pos;
}
void LBinTree::addRoot(void)
{
    if (!empty())
        throw TreeError("Error: Tree is not empty.");
    else
    {
        _root = new Node;
        n++;
    }
}
void LBinTree::expandExternal(const Position &p)
{
    p.v->left = new Node;
    p.v->left->par = p.v;
    p.v->right = new Node;
    p.v->right->par = p.v;
    n += 2;
}
LBinTree::Position LBinTree::removeAboveExternal(const Position &p)
{
    Node *mi = p.v;
    Node *par = mi->par;
    Node *sib = (par->left = mi) ? (par->right) : (par->left);

    if (par == _root)
    {
        _root = sib;
        sib->par = nullptr;
    }
    else
    {
        Node *gp = par->par;
        if (gp->left = par)
            gp->left = sib;
        else
            gp->right = sib;
        sib->par = gp;
    }

    delete mi;
    delete par;
    n -= 2;
    return Position(sib);
}
void LBinTree::preorder(Node *v, PositionList &pl)
{
    pl.push_back(Position(v));
    if (v->left != nullptr)
        preorder(v->left, pl);
    if (v->left != nullptr)
        preorder(v->right, pl);
}
void LBinTree::inorder(Node *v, PositionList &pl)
{
    if (v->left != nullptr)
        inorder(v->left, pl);
    pl.push_back(Position(v));
    if (v->left != nullptr)
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