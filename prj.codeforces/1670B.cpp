#include <vector>
#include <iostream>
#include <cmath>



int main() {
    int t = 0;
    std::cin >> t;
    int n = 0;
    std::string s;
    int k = 0;
    char temp = ' ';
    std::vector<char> let;
    std::vector<int> indexes;
    int answ = 0;
    for (int i = 0; i < t; i++)
    {
        let.clear();
        indexes.clear();
        std::cin >> n;
        std::cin >> s;
        std::cin >> k;
        for (int j = 0; j < k; j++)
        {
            std::cin >> temp;
            let.push_back(temp);
        }
        
        answ = 0;
        for (int j = 1; j < s.size(); j++)
        {
            for (int k = 0; k < let.size(); k++)
            {
                if (s[j] == let[k])
                {
                    indexes.push_back(j);
                    break;
                }
            }
        }
        while (indexes.size()>0)
        {
            n = indexes.size();
            k = 0;//Now used as number to move everything
            for (int i = 0; i < n -1; i++)
            {
                k += 1;
                if (indexes[i] == indexes[i+1] - 1)
                {
                    indexes.erase(indexes.begin() + i);
                    i -= 1;
                    n -= 1;
                    continue;
                }
                indexes[i] -= k;
                if (indexes[i] <= 0)
                {
                    indexes.erase(indexes.begin() + i);
                    i -= 1;
                    n -= 1;
                }
            }
            k += 1;
            indexes[indexes.size() - 1] -= k;
            answ += 1;
            if (indexes[indexes.size()-1] <= 0)
            {
                break;
            }
        }
        std::cout << answ << "\n";
    }
}