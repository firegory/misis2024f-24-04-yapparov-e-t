#include <iostream>
#include <vector>

int main() {
    int t = 0;
    std::cin >> t;
    int n = 0;
    std::vector<int> a;
    std::vector<int> b;
    int time = 0;
    int temp = 0;
    for (int i = 0; i < t; i++)
    {
        time = 0;
        std::cin >> n;
        a = std::vector<int>(n);
        b = std::vector<int>(n);
        for (int j = 0; j < n; j++)
        {
            std::cin >> a[j] >> b[j];
        }
        std::cin >> temp;
        time += a[0];
        time += temp;
        if (n>1)
        {
            time += (b[0] - a[0]) / 2 + (b[0] - a[0]) % 2;
            if (b[0] > time)
            {
                time = b[0];
            }
        }
        for (int j = 1; j < n-1; j++)
        {
            std::cin >> temp;
            time += a[j] - b[j-1];
            time += temp;
            time += (b[j] - a[j]) / 2 + (b[j] - a[j]) % 2;
            if (b[j] > time)
            {
                time = b[j];
            }
        }
        if (n>1)
        {
            std::cin >> temp;
            time += a[n - 1] - b[n - 2];
            time += temp;
        }
        std::cout << time << "\n";
    }
}
