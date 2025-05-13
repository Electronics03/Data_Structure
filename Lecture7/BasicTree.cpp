#include <iostream>
#include <cstdlib>
#include <list>
#include <string>

using namespace std;
using Elem = string;

class Tree
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
        Position parent(void) const;
        std::list<Position> children(void) const;
        bool isRoot(void) const;
        bool isExternal(void) const;
        friend class Tree;
    };
    using PositionList = list<Position>;

public:
    Tree();
    int size(void) const;
    bool empty(void) const;
    Position root(void) const;
    PositionList positions(void) const;
    Position addRoot(const Elem &e);
    Position addChild(const Position &p, const Elem &e);

private:
    Node *rootNode;
    int n;
    void preorder(Node *v, PositionList &pl) const
    {
        pl.push_back(Position(v));
        if (!(Position(v).isExternal()))
            for (Node *child : v->children)
                preorder(child, pl);
    }
};
Tree::Position::Position(Node *u) : v(u) {}
Elem &Tree::Position::operator*(void) { return v->elem; }
Tree::Position Tree::Position::parent(void) const
{
    return Position(v->parent);
}
std::list<Tree::Position> Tree::Position::children(void) const
{
    std::list<Position> posList;
    for (Node *child : v->children)
        posList.push_back(Position(child));
    return posList;
}
bool Tree::Position::isRoot(void) const { return v->parent == nullptr; }
bool Tree::Position::isExternal(void) const { return v->children.empty(); }

Tree::Tree() : rootNode(nullptr), n(0) {}
int Tree::size(void) const { return n; }
bool Tree::empty(void) const { return rootNode == nullptr; }
Tree::Position Tree::root(void) const { return Position(rootNode); }
Tree::PositionList Tree::positions(void) const
{
    PositionList pl;
    if (rootNode != nullptr)
        preorder(rootNode, pl);
    return pl;
}
Tree::Position Tree::addRoot(const Elem &elem)
{
    rootNode = new Node;
    rootNode->elem = elem;
    n = 1;
    return Position(rootNode);
}
Tree::Position Tree::addChild(const Tree::Position &p, const Elem &e)
{
    Node *parentNode = p.v;
    Node *newNode = new Node;
    newNode->elem = e;
    newNode->parent = parentNode;
    parentNode->children.push_back(newNode);
    n++;
    return Position(newNode);
}
int depth(Tree &T, Tree::Position p)
{
    if (p.isRoot())
        return 0;
    else
        return 1 + depth(T, p.parent());
}
int height1(Tree &T)
{
    int h = 0;
    Tree::PositionList posList = T.positions();
    for (Tree::PositionList::iterator iter = posList.begin(); iter != posList.end(); ++iter)
    {
        if (iter->isExternal())
            h = max(h, depth(T, *iter));
    }
    return h;
}
int height2(Tree &T, Tree::Position p)
{
    if (p.isExternal())
        return 0;
    int h = 0;
    Tree::PositionList posList = p.children();
    for (Tree::PositionList::iterator iter = posList.begin(); iter != posList.end(); ++iter)
        h = max(h, height2(T, *iter));
    return h + 1;
}
void preorderPrint(Tree T, Tree::Position p)
{
    cout << *p;
    Tree::PositionList chList = p.children();
    for (Tree::Position ch : chList)
    {
        cout << " ";
        preorderPrint(T, ch);
    }
}
void parenPrint(Tree T, Tree::Position p)
{
    cout << *p;
    if (!p.isExternal())
    {
        Tree::PositionList chList = p.children();
        cout << "(";
        for (Tree::PositionList::iterator ch = chList.begin(); ch != chList.end(); ++ch)
        {
            if (ch != chList.begin())
                cout << " ";
            parenPrint(T, *ch);
        }
        cout << ")";
    }
}
void postoderPrint(Tree T, Tree::Position p)
{
    Tree::PositionList chList = p.children();
    for (Tree::Position ch : chList)
    {
        cout << " ";
        postoderPrint(T, ch);
    }
    cout << *p;
}

int main()
{
    Tree tree;
    Tree::Position root = tree.addRoot("Root");
    std::cout << "Root: " << *root << std::endl;

    Tree::Position child1 = tree.addChild(root, "  Child 1");
    Tree::Position child2 = tree.addChild(root, "  Child 2");
    Tree::Position child3 = tree.addChild(child1, "    Child 1.1");
    tree.addChild(child1, "    Child 1.2");
    tree.addChild(child1, "    Child 1.3");
    tree.addChild(child1, "    Child 1.4");
    tree.addChild(child2, "    Child 2.1");
    tree.addChild(child2, "    Child 2.2");
    tree.addChild(child2, "    Child 2.3");
    tree.addChild(root, "  Child 3");
    tree.addChild(root, "  Child 4");
    tree.addChild(root, "  Child 5");
    tree.addChild(child3, "      Child 1.1.1");
    tree.addChild(child3, "      Child 1.1.2");
    tree.addChild(child3, "      Child 1.1.3");
    tree.addChild(child3, "      Child 1.1.4");

    Tree::PositionList posList = tree.positions();

    std::cout << "Tree Structure (Pre-order):" << std::endl;
    for (Tree::Position pos : posList)
    {
        cout << *pos << endl;
    }
    cout << depth(tree, child3) << endl;
    cout << height2(tree, tree.root()) << endl;
    preorderPrint(tree, root);
    parenPrint(tree, root);
    postoderPrint(tree, root);
    return 0;
}