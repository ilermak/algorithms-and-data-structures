#include <iostream>
#include <vector>

using namespace std;

int max_profit(const vector<int>& cost) {
    int result = 0;
    int x1, x2;
    bool ownership = false;
    if (cost.size() >= 2) {
        for (int i = 0; i < cost.size() - 1; ++i) {
            x1 = cost[i];
            x2 = cost[i + 1];
            if (x1 < x2 && !ownership) {
                result -= x1;
                ownership = true;
            }
            else if (x1 > x2 && ownership) {
                result += x1;
                ownership = false;
            }
        }
        if (ownership) {
            result += x2;
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> cost(n);

    for (auto& i : cost) {
        cin >> i;
    }

    cout << max_profit(cost);

    return 0;
}
