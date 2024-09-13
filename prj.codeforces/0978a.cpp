#include <vector>
#include <iostream>
#include <cmath>

int main() {
    using namespace std;
    vector<int> v;
    int n = 0;
    int num = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        for (int j = 0; j < v.size(); j++) {
            if (num == v[j]) {
                v.erase(v.begin() + j);
                break;
            }
        }
        v.push_back(num);
    }
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";

    }
}