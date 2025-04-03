#include <iostream>
#include <cstdlib>

using namespace std;

enum Day
{
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
};

enum Mood
{
    Happy = 3,
    Sad = 1,
    Anxious = 4,
    Sleepy = 2
};

int main(void)
{
    Day today = Monday;
    Mood myMood = Sleepy;

    if (today == Monday)
        cout << "Today is Monday..." << endl;
    else if (today == Friday)
        cout << "Today is Friday!!" << endl;
    if (myMood == Sleepy)
        cout << "I want to go to sleep..." << endl;
    return 0;
}