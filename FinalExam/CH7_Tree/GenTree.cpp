#include <list>
#include <string>
#include <iostream>

using namespace std;
using Elem = string;

class GenTree
{
private:
    struct Node
    {
        Elem elem;
        Node *parent;
        list<Node *> children;
        Node() : elem(), parent(nullptr), children() {}
    };

public:
    class Position
    {
    private:
        Node *v;

    public:
        Position(Node *u);
        Elem &operator*(void);
        Position parent(void);
        list<Position> children(void);
        bool isRoot(void);
        bool isExternal(void);
        friend class GenTree;
    };

public:
    GenTree();
    bool size(void);
    bool empty(void);
    Position root(void);
    list<Position> position(void);
    Position addRoot(const Elem &e);
    Position addChild(const Position &p, const Elem &e);

private:
    int n;
    Node *rootNode;
    void preorder(Node *v, list<Position> pos);
};
GenTree::Position::Position(Node *u) : v(u) {}
Elem &GenTree::Position::operator*(void) { return v->elem; }
GenTree::Position GenTree::Position::parent(void) { return Position(v->parent); }
list<GenTree::Position> GenTree::Position::children(void)
{
    list<Position> pos;
    for (Node *i : v->children)
        pos.push_back(Position(i));
    return pos;
}
bool GenTree::Position::isRoot(void) { return v->parent == nullptr; }
bool GenTree::Position::isExternal(void) { return v->children.empty(); }

GenTree::GenTree() : n(0), rootNode(nullptr) {}
bool GenTree::size(void) { return n; }
bool GenTree::empty(void) { return n == 0; }
GenTree::Position GenTree::root(void) { return Position(rootNode); }
list<GenTree::Position> GenTree::position(void)
{
    list<Position> pos;
    if (rootNode != nullptr)
        preorder(rootNode, pos);
    return pos;
}
void GenTree::preorder(Node *v, list<Position> pos)
{
    pos.push_back(Position(v));
    if (!Position(v).isExternal())
        for (Node *i : v->children)
            preorder(i, pos);
}
GenTree::Position GenTree::addRoot(const Elem &elem)
{
    rootNode = new Node;
    rootNode->elem = elem;
    n = 1;
    return Position(rootNode);
}
GenTree::Position GenTree::addChild(const GenTree::Position &p, const Elem &e)
{
    Node *parentNode = p.v;
    Node *newNode = new Node;
    newNode->elem = e;
    newNode->parent = parentNode;
    parentNode->children.push_back(newNode);
    n++;
    return Position(newNode);
}
int depth(GenTree &T, GenTree::Position p)
{
    if (p.isRoot())
        return 0;
    else
        return 1 + depth(T, p.parent());
}
int height1(GenTree &T)
{
    int h = 0;
    list<GenTree::Position> pos = T.position();
    for (GenTree::Position i : pos)
        h = max(h, depth(T, i));
    return h;
}
int height2(GenTree &T, GenTree::Position p)
{
    int h = 0;
    list<GenTree::Position> pos = p.children();
    for (GenTree::Position i : pos)
        h = max(h, height2(T, i));
    return h + 1;
}
void preorderPrint(GenTree &T, GenTree::Position p)
{
    cout << *p;
    cout << "\n";
    for (GenTree::Position i : p.children())
        preorderPrint(T, i);
}
void postoderPrint(GenTree &T, GenTree::Position p)
{
    for (GenTree::Position i : p.children())
        postoderPrint(T, i);
    cout << *p;
    cout << "\n";
}
int main()
{
    GenTree tree;
    GenTree::Position root = tree.addRoot("Root");
    std::cout << "Root: " << *root << std::endl;

    GenTree::Position child1 = tree.addChild(root, "Child 1");
    GenTree::Position child2 = tree.addChild(root, "Child 2");
    GenTree::Position child3 = tree.addChild(child1, "Child 1.1");
    tree.addChild(child1, "Child 1.2");
    tree.addChild(child1, "Child 1.3");
    tree.addChild(child1, "Child 1.4");
    tree.addChild(child2, "Child 2.1");
    tree.addChild(child2, "Child 2.2");
    tree.addChild(child2, "Child 2.3");
    tree.addChild(root, "Child 3");
    tree.addChild(root, "Child 4");
    tree.addChild(root, "Child 5");
    tree.addChild(child3, "Child 1.1.1");
    tree.addChild(child3, "Child 1.1.2");
    tree.addChild(child3, "Child 1.1.3");
    tree.addChild(child3, "Child 1.1.4");

    list<GenTree::Position> posList = tree.position();

    std::cout << "Tree Structure (Pre-order):" << std::endl;
    for (GenTree::Position pos : posList)
    {
        cout << *pos << endl;
    }
    cout << depth(tree, child3) << endl;
    cout << height2(tree, tree.root()) << endl;
    preorderPrint(tree, root);
    postoderPrint(tree, root);
    return 0;
}