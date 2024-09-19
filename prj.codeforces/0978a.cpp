#include <vector>
#include <iostream>

int main() {
    std::vector<int> v;
    int n = 0;
    int num = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> num;
        for (int j = 0; j < v.size(); j++) {
            if (num == v[j]) {
                v.erase(v.begin() + j);
                break;
            }
        }
        v.push_back(num);
    }
    std::cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";

    }
}