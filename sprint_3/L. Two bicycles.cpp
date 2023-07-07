#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int>& arr, int x, int left, int right) {
    if (right < left) {
        return -1;
    }
    else if (right == left && x <= arr[right]) {
        return right + 1;
    }

    int mid = (left + right) / 2;

    if (x <= arr[mid]) {
        return binary_search(arr, x, left, mid);
    }
    else {
        return binary_search(arr, x, mid + 1, right);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> wallet_history(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> wallet_history[i];
    }
    int k;
    cin >> k;


    cout << binary_search(wallet_history, k, 0 , n - 1) << " " <<  binary_search(wallet_history, 2 * k, 0, n - 1);

    return 0;
}