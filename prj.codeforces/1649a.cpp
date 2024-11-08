#include <iostream>



int main() {
    int t = 0;
    std::cin >> t;
    int n = 0;
    int answ = 0;
    int groundInSequence = 0;
    bool firstWater = false;
    int firstGrounds = 0;
    int temp = 0;
    for (int i = 0; i < t; i++)
    {
        std::cin >> n;
        answ = 0;
        groundInSequence = 0;
        firstWater = false;
        for (int i = 0; i < n; i++)
        {
            std::cin >> temp;
            if (temp == 1)
            {
                groundInSequence++;
            }
            else
            {
                if (!firstWater)
                {
                    firstGrounds = groundInSequence;
                    firstWater = true;
                }
                groundInSequence = 0;
            }
        }
        if (!firstWater)
        {
            std::cout << 0 << "\n";
        }
        else
        {
            std::cout << n - firstGrounds - groundInSequence + 1 << "\n";
        }
    }
}
