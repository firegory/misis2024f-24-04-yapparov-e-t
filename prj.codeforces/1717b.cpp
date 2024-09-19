#include <iostream>
#include <vector>

int main() {
    int t = 0;
    int n = 0;
    int koef = 0;
    int x = 0;
    int y = 0;
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        std::cin >> n;
        std::cin >> koef;
        std::cin >> x;
        std::cin >> y;
        x -= 1;
        y -= 1;
        char** mas = new char* [n];
        for (int j = 0; j < n; ++j)
        {
            mas[j] = new char[n];
            for (int k = 0; k < n; k++)
            {
                mas[j][k] = '.';
            }
        }
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n; k++)
            {
                if (((j - k) % koef + koef) % koef == ((x - y) % koef + koef) % koef)
                {
                    mas[j][k] = 'X';
                }
            }
        }



        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n; k++)
            {
                std::cout << mas[j][k];
            }
            std::cout << "\n";
        }

        for (int j = 0; j < n; ++j) delete[] mas[j];
        delete[] mas;
    }

}