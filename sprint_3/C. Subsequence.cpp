#include <iostream>
#include <string>

using namespace std;

bool is_subsequence(string first, string second) {
    string result;

    int i = 0;
    int j = 0;

    while (i < first.size() && j < second.size()) {
        if (first[i] == second[j]) {
            result += first[i];
            i++;
            j++;
        }
        else {
            j++;
        }
    }
    return result == first;
}

void print(bool result) {
    if (result) {
        cout << "True" << "\n";
    }
    else {
        cout << "False" << "\n";
    }
}

int main() {
    string first, second;
    cin >> first;
    cin >> second;

    print(is_subsequence(first, second));

    return 0;
}