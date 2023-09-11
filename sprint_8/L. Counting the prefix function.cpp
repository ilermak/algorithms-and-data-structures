#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> prefix_function(string s) {
    int N = s.length();
    vector<int> pi(N, 0);
    for (int i = 1; i < N; i++) {
        int k = pi[i - 1];
        while (k > 0 && s[k] != s[i]) {
            k = pi[k - 1];
        }
        if (s[k] == s[i]) {
            k += 1;
        }
        pi[i] = k;
    }
    return pi;
}


int main() {
    string s;
    cin >> s;

    vector<int> result = prefix_function(s);

    for (auto i : result) {
        cout << i << " ";
    }
    return 0;
}