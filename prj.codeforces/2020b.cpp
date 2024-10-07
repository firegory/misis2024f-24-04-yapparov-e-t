#include <iostream>

int main() {
    int t = 0;
    std::cin >> t;
    long long n = 0;
    long long k = 0;
    int counter = 0;
    long long low = 0;
    long long high = 0;
    long long  const number = 1000000000 / 2;
    for (int i = 0; i < t; i++)
    {

        std::cin >> k;
        n = number;
        counter = 1;
        high = 1000000000;
        low = 1;
        while (true)
        {
            n = low + (high - low) / 2;
            if (n * n - n + 1 > k)
            {
                if ((n - 1) * (n - 1) - n + 2 <= k)
                {
                    break;
                }
                else
                {
                    high = n - 1;

                }
            }
            else
            {
                low = n + 1;

            }
            counter++;
        }

        std::cout << k + n - 1 << "\n";
    }
}