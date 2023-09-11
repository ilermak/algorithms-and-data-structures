/*
ID решения - 90149082

-- ПРИНЦИП РАБОТЫ --
Для решения этой задачи используется каноническое решение динамическим программированием задачи о рюкзаке,
но вместо максимально допустимого веса у нас половинна суммы очков всех раундов.
Если мы нашли такую комбинацию очков за раунды, которые дают половину суммы за все раунды,
то оставшиеся множество дает такую сумму тоже.

-- ВРЕМЕННАЯ СЛОЖНОСТЬ --
O(N * M), где N - кол-во раундов, а M сумма всех очков деленная пополам.

-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
O(M), где M - сумма всех очков деленная пополам.

*/

#include <iostream>
#include <vector>

using namespace std;

int is_same_sum(const vector<int>& points, int sum) {
    vector<vector<int>> dp(2, vector(sum / 2 + 1, 0));

    for (int i = 0; i < points.size(); ++i) {
        for (int j = 0; j < dp[0].size(); ++j) {
            if (j == 0) {
                dp[1][j] = 0;
            }
            else if (i == 0) {
                dp[0][j] = (j - points[i] >= 0) ? points[i] : 0;
            }
            else if (j - points[i] >= 0) {
                dp[1][j] = max(dp[0][j], points[i] + dp[0][j - points[i]]);
            }
            else {
                dp[1][j] = dp[0][j];
            }
        }

        if (i > 0) {
            dp[0] = dp[1];
        }
    }

    return dp.back().back();
}

int main() {
    int n;
    cin >> n;

    vector<int> weights(n);

    for (auto& i : weights) {
        cin >> i;
    }

    int sum = 0;

    for (auto i : weights) {
        sum += i;
    }

    if (sum % 2 == 0 && is_same_sum(weights, sum) == sum / 2) {
        cout << "True";
    }
    else {
        cout << "False";
    }

    return 0;
}