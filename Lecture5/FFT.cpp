#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#include <algorithm>

typedef std::complex<double> cpx;
typedef std::vector<cpx> data;
const double PI = 3.141592653589793238;

int bitRev(int num, int bit)
{
    int revNum = 0;
    for (int i = 0; i < bit; i++)
        if (num & (1 << i))
            revNum |= 1 << (bit - 1 - i);
    return revNum;
}
void FFT(data &signal, const bool invert)
{
    int totalN = signal.size();
    int rTimes = log2(totalN);

    for (int i = 0; i < totalN; i++)
    {
        int j = bitRev(i, rTimes);
        if (j > i)
            swap(signal[i], signal[j]);
    }
    for (int N = 2; N <= totalN; N *= 2)
    {
        double basicAngle = (invert ? 1 : -1) * 2 * PI / N;
        cpx basicCpx(cos(basicAngle), sin(basicAngle));
        for (int n = 0; n < totalN; n += N)
        {
            cpx W(1.0);
            for (int k = 0; k < N / 2; k++)
            {
                int tmp = n + k;
                cpx E = signal[tmp];
                cpx O = W * signal[tmp + N / 2];
                signal[tmp] = E + O;
                signal[tmp + N / 2] = E - O;
                W *= basicCpx;
            }
        }
    }
    if (invert)
    {
        for (cpx &x : signal)
            x /= totalN;
    }
    return;
}
data convolution(const data &a, const data &b)
{
    int N = 1;
    while (N < a.size() + b.size())
        N <<= 1;

    data A(a.begin(), a.end());
    data B(b.begin(), b.end());

    A.resize(N);
    B.resize(N);

    FFT(A, false);
    FFT(B, false);

    for (int i = 0; i < N; i++)
        A[i] *= B[i];

    FFT(A, true);
    return A;
}
int main()
{
    int N = 0;
    std::cin >> N;

    data A(N);
    data B(N);
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
    for (int i = 0; i < N; i++)
        std::cin >> B[i];

    data X = A;
    X.insert(X.end(), A.begin(), A.end());
    data Y(B.rbegin(), B.rend());

    data result = convolution(X, Y);

    double maxData = result[0].real();
    for (int i = N - 1; i < 2 * N; i++)
        maxData = std::max(maxData, result[i].real());
    std::cout << llround(maxData) << std::endl;
    return 0;
}