#include <iostream>
#include <vector>

using namespace std;

int max_weight(const vector<int>& array, int m) {
    vector<vector<int>> dp(array.size(), vector(m + 1, 0));

    for (int i = 0; i < dp.size(); ++i) {
        for (int j = 0; j < dp[i].size(); ++j) {
            if (j == 0) {
                dp[i][j] = 0;
            }
            else if (i == 0) {
                dp[i][j] = (j - array[i] >= 0) ? array[i] : 0;
            }
            else if (j - array[i] >= 0) {
                dp[i][j] = max(dp[i - 1][j], array[i] + dp[i - 1][j - array[i]]);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp.back().back();
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> weights(n);

    for (auto& i : weights) {
        cin >> i;
    }

    cout << max_weight(weights, m);

    return 0;
}
