#include <iostream>
#include <cmath>
#include <algorithm>
//Взялся за задачку H, не понимаю как дальше оптимимзировать(саму задачку тестам решил)

int partition(int** vec, int low, int high) 
{
    int pivot = vec[0][high];

    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {

        if (vec[0][j] <= pivot) {
            i++;
            std::swap(vec[0][i], vec[0][j]);
            std::swap(vec[1][i], vec[1][j]);
        }
    }

    std::swap(vec[0][i + 1], vec[0][high]);
    std::swap(vec[1][i + 1], vec[1][high]);

    return (i + 1);
}

void quickSort(int**& vec, int low, int high) 
{
    if (low < high) {
        int pi = partition(vec, low, high);

        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}


int main() {
    int t = 0;
    std::cin >> t;
    int n = 0;
    int q = 0;
    int** a = new int* [2];
    int temp = 0;
    int l = 0;
    int r = 0;
    int rCount = 0;
    int shCount = 0;
    for (int i = 0; i < t; i++)
    {
        std::cin >> n;
        std::cin >> q;
        a[0] = new int[n];
        a[1] = new int[n];
        for (int j = 0; j < n; j++)
        {
            std::cin >> a[0][j];
            a[1][j] = j;
        }
        quickSort(a, 0, n - 1);
        for (int j = 0; j < q; j++)
        {
            rCount = 0;
            shCount = 0;
            std::cin >> l;
            std::cin >> r;
            temp = 0;
            for (int k = 0; k < n; k++)
            {
                if (a[1][k] >= l - 1 && a[1][k] <= r - 1)
                {
                    if (temp % 2 == 0)
                    {
                        rCount += a[0][k];
                    }
                    else
                    {
                        shCount += a[0][k];
                    }
                    temp += 1;
                    if (temp == r - l + 1)
                    {
                        break;
                    }
                }
            }
            if (rCount == shCount)
            {
                std::cout << "YES\n";
            }
            else
            {
                std::cout << "NO\n";
            }
        }
    }
}