#include <iostream>
#include <cmath>

int main() {
    int n = 0;
    std::cin >> n;
    long long len = 0;
    long long n0 = 0;
    long long min = 0;
    long long num = 0;
    long long k;
    int temp;
    for (int i = 0; i < n; i++)
    {
        std::cin >> len >> n0;
        min = ULONG_MAX;
        k = len / 2 + len % 2;
        for (int j = 2; j < ceil(log2(len)) + 2; j++)
        {
            num = 0;
            num += (n0 + (n0 + k - 1)) * k / 2;
            num -= ((n0 + k) + (n0 + len - 1)) * (len - k) / 2;
            temp = pow(2, j);
            if (num > 0)
            {
                k -= len / temp;
                if (len % temp != 0)
                {
                    k -= 1;
                }
            }
            else
            {
                k += len / temp;
                if (len % temp != 0)
                {
                    k += 1;
                }
            }
            num = abs(num);
            if (num < min)
            {
                min = num;
            }
        }
        std::cout << min << "\n";
    }
}