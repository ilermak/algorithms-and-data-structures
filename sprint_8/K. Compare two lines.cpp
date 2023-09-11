#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string first, second;
    cin >> first >> second;

    string new_first;
    for (char i : first) {
        if (i >= 'a' && i <= 'z' && i % 2 == 0) {
            new_first += i;
        }
    }

    string new_second;
    for (char i : second) {
        if (i >= 'a' && i <= 'z' && i % 2 == 0) {
            new_second += i;
        }
    }

    if (new_first < new_second) {
        cout << -1;
    }
    else if (new_first == new_second) {
        cout << 0;
    }
    else {
        cout << 1;
    }

    return 0;
}