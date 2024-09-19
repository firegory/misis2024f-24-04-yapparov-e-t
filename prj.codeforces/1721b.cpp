#include <iostream>

bool distCheck(int x, int y, int sx, int sy, int d)
{
    if (std::abs(x-sx) + std::abs(y-sy) > d)
    {
        return true;
    }
    return false;
}
//Сделал значит крутой рекурсивный алгоритм поиска пути, а оно оказывается в 10 строк решается...
/*int step(int n, int m, int x, int y, int sx, int sy, int d, int steps)
{
    if (x == n && y == m)
    {
        return steps;
    }
    else
    {
        int path1 = -1;
        int path2 = -1;
        if (x < n && distCheck(x + 1, y, sx, sy, d))
        {
            path1 = step(n, m, x + 1, y, sx, sy, d, steps + 1);
        }
        if (y < m && distCheck(x, y + 1, sx, sy, d))
        {
            path2 = step(n, m, x, y + 1, sx, sy, d, steps + 1);
        }
        return(std::max(path1, path2));
    }

}*/
int main() {
    int t = 0;
    int n = 0;
    int m = 0;
    int x = 0;
    int y = 0;
    int sx = 0;
    int sy = 0;
    int d = 0;
    int steps = 0;
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        x = 1;
        y = 1;
        steps = 0;
        std::cin >> n;
        std::cin >> m;
        std::cin >> sx;
        std::cin >> sy;
        std::cin >> d;
        if ((distCheck(1,sy,sx,sy,d) && distCheck(sx, m, sx, sy, d)) || (distCheck(n, sy, sx, sy, d) && distCheck(sx, 1, sx, sy, d)))
        {
            std::cout <<  m + n - 2 << "\n";
        }
        else
        {
            std::cout << -1 << "\n";
        }
    }

}