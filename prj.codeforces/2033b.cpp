#include <iostream>
#include <vector>

int main() {
    int t = 0;
    std::cin >> t;
    int n = 0;
    std::vector<std::vector<int>> mas;
    int adder = 0;
    long long result = 0;
    int temp = 0;
    std::vector<int> tempv;
    tempv.push_back(0);
    for (int i = 0; i < t; i++)
    {
        std::cin >> n;
        mas.clear();
        result = 0;
        for (int j = 0; j < n * 2 - 1; j++)
        {
            mas.push_back(tempv);
        }
        for (int j = 0; j < n*n; j++)
        {
            std::cin >> temp;

            mas[n - 1 + j / n - j % n].push_back(temp);
        }
        for (int j = 0; j < n * 2 - 1; j++)
        {
            adder = 0;
            for (int k = 0; k < mas[j].size(); k++)
            {
                if (mas[j][k] < -1*adder)
                {
                    adder = -1 * mas[j][k];
                }
            }
            result += adder;
        }
        std::cout << result << "\n";
    }
}