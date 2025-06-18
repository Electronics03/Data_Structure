#include <iostream>
#include <list>

using namespace std;

struct Elem
{
    std::string elt;
    int comp;
};

class Comp
{
public:
    bool operator()(const Elem &a, const Elem &b) { return a.comp < b.comp; }
};

template <typename E, typename C>
class ListPriorityQueue
{
public:
    int size(void) const { return _L.size(); }
    int empty(void) const { return _L.empty(); }
    const E &min(void) const { return _L.front(); }
    void removeMin(void) { _L.pop_front(); }
    void insert(const E &elem)
    {
        typename list<E>::iterator i;
        i = _L.begin();
        for (i; i != _L.end(); ++i)
        {
            if (isLess(elem, *i))
            {
                _L.insert(i, elem);
                return;
            }
        }
        _L.push_back(elem);
    }

private:
    list<E> _L;
    C isLess;
};

int main(void)
{
    ListPriorityQueue<Elem, Comp> pq;

    pq.insert({"banana", 5});
    pq.insert({"apple", 3});
    pq.insert({"cherry", 8});
    pq.insert({"date", 1});

    while (!pq.empty())
    {
        Elem e = pq.min();
        cout << e.elt << ": " << e.comp << endl;
        pq.removeMin();
    }

    return 0;
}