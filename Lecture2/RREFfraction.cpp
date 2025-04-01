#include <iostream>
#include <cstdlib>
#include <math.h>

template <typename T>
class Fraction
{
private:
    T num;
    T den;

public:
    Fraction(T A = 0, T B = 1) : num(A), den(B) {}
    ~Fraction() {}
    /*
    음(-)부호는 항상 분자에 저장
    */
    Fraction operator+(const Fraction &other) const
    {
        /*
        1. 두 분모의 최소공배수 구함
        2. 오버플로우가 일어나지 않도록 잘 계산
        3. 기약분수로 만들기
        */
        T newnum = num * other.den + other.num * den;
        T newden = den * other.den;
        return Fraction(newnum, newden);
    }

    void printfrc(void)
    {
        std::cout << num << "/" << den << std::endl;
    }
};

int main(void)
{
    Fraction A(1, 2);
    Fraction B(3, 5);
    Fraction C(0, 1);
    C = A + B;
    C.printfrc();
    return 0;
}