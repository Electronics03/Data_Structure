#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

int main(void)
{
    enum DAYS
    {
        mon = 100,
        tue, // 101
        wed, // 102
        thu = 11,
        fri, // 12
        sat, // 13
        sun  // 14
    };
    DAYS today;
    today = fri;
    switch (today)
    {
    case mon:
        cout << "mon\n";
        break; // break로 블록을 끝내야 한다
    case tue:
        cout << "tue\n";
        break;
    case wed:
        cout << "wed\n";
        break;
    case thu:
        cout << "thu\n";
        break;
    case fri:
        cout << "fri\n";
    case sat:
        cout << "fri\n";
    case sun:
        cout << "fri\n";
        cout << today << endl;
    default:
        break;
    }
    return EXIT_SUCCESS;
}