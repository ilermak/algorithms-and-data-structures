#include <iostream>
#include <vector>

using namespace std;

bool passed_control(const string& first, const string& second) {
    if (int(first.size() - second.size()) < -1 || int(first.size() - second.size()) > 1) {
        return false;
    }
    int i = 0;
    int j = 0;
    int match_counter = 0;
    while (i < first.size() && j < second.size()) {
        if (first[i] == second[j]) {
            i++;
            j++;
            match_counter++;
        }
        else if (first.size() < second.size()) {
            j++;
        }
        else if (first.size() > second.size()) {
            i++;
        }
        else if (first.size() == second.size()) {
            i++;
            j++;
        }
    }

    if (match_counter == max(first.size(), second.size()) || match_counter + 1 == max(first.size(), second.size())) {
        return true;
    }
    else {
        return false;
    }

}

int main() {
    string first, second;
    cin >> first >> second;

    if (passed_control(first, second)) {
        cout << "OK";
    }
    else {
        cout << "FAIL";
    }

    return 0;
}