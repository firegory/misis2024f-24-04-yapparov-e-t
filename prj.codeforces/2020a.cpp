#include <iostream>
#include <cmath>


int main() {
    int t = 0;
    std::cin >> t;
    int n = 0;
    int k = 0;
    int counter = 0;
    int k1 = 0;
    for (int i = 0; i < t; i++)
    {
        std::cin >> n;
        std::cin >> k;
        counter = 0;
        if (k == 1)
        {
            counter = n;
        }
        else
        {
            while (n > 0)
            {
                counter += n % k;
                n = n / k;
            }
        }

        std::cout << counter << "\n";
    }
}
