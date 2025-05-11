#include <iostream>
#include <cstdlib>
#include <list>
#include <string>

using Elem = std::string;
using PositionList = std::list<PositionList>;

class Position
{
private:
    Elem elem;
    Position *parent;
    PositionList *children;

public:
    Position();
    Elem &operator*(void);
    Position parent(void) const;
    PositionList children(void) const;
    bool isRoot(void) const;
    bool isExternal(void) const;
};
Position::Position();
Elem &operator*(void) {}
Position parent(void) const {}
PositionList children(void) const {}
bool isRoot(void) const {}
bool isExternal(void) const {}
int main(void)
{
    return 0;
}