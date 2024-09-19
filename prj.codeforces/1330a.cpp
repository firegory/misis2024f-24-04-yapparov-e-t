#include <iostream>
#include <vector>

int main() {
    int t = 0;
    int n = 0;
    int x = 0;
    int temp = 0;
    int ind = 0;
    std::vector<int> v;

    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        std::cin >> n;
        std::cin >> x;
        v.clear();
        for (int j = 0; j < n; j++)
        {
            std::cin >> temp;
            v.push_back(temp);
        }
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n-j-1; k++)
            {
                if (v[k] > v[k+1])
                {
                    std::swap(v[k], v[k + 1]);
                }
            }
        }
        temp = 1;
        ind = 0;
        while (true)//There are two breakpoints
        {
            if (ind < n)
            {
                if (v[ind] == temp)
                {
                    ind += 1;
                    temp += 1;
                }
                else if (v[ind] < temp)
                {
                    ind += 1;
                }
                else
                {
                    if (x > 0)
                    {
                        x -= 1;
                        temp += 1;
                    }
                    else
                    {
                        break;//here is one
                    }
                }
            }
            else
            {
                if (x>0)
                {
                    x -= 1;
                    temp += 1;
                }
                else
                {
                    break;//and here is another
                }
            }
        }
        std::cout << temp-1 << "\n";
    }

}