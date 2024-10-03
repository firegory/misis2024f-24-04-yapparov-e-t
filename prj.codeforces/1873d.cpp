#include <iostream>
#include <cmath>
#include <vector>

int main() {
    int t = 0;
    std::cin >> t;
    int n = 0;
    int k = 0;
    int counter;
    int powerLeft;
    char a = ' ';
    for (int i = 0; i < t; i++)
    {
        std::cin >> n;
        std::cin >> k;
        counter = 0;
        powerLeft = 0;
        for (int j = 0; j < n; j++)
        {
            std::cin >> a;
            if (powerLeft <= 0)
            {
                if (a == 'B')
                {
                    counter++;
                    powerLeft = k;
                }
            }
            powerLeft -= 1;
        }
        std::cout << counter << "\n";
    }
}