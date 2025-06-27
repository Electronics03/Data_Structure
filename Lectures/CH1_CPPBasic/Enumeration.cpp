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
        tue,
        wed,
        thu = 11,
        fri,
        sat,
        sun
    };
    DAYS today;
    today = fri;
    switch (today)
    {
    case mon:
        cout << "mon\n";
        break;
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