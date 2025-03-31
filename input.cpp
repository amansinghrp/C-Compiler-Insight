#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {3, 1, 4, 1, 5};
    v.push_back(9);
    sort(v.begin(), v.end());

    for (int x : v) {
        cout << x << " ";
    }
    return 0;
}
