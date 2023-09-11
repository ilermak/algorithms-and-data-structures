#include <iostream>
#include <unordered_map>

using namespace std;

bool is_equal(const string& first, const string& second) {
    if (first.size() != second.size()) {return false;}

    bool result = true;
    unordered_map<char, char> char_in_string;
    unordered_map<char, char> string_in_char;

    for (int i = 0; i < first.size(); ++i) {
        if (char_in_string.contains(first[i])) {
            if (char_in_string[first[i]] != second[i]) {
                return false;
            }
        }
        else {
            char_in_string[first[i]] = second[i];
            string_in_char[second[i]] = first[i];
        }

        if (string_in_char.contains(second[i])) {
            if (string_in_char[second[i]] != first[i]) {
                return false;
            }
        }
        else {
            char_in_string[first[i]] = second[i];
            string_in_char[second[i]] = first[i];
        }
    }

    return result;
}

int main() {
    string first, second;
    cin >> first;
    cin >> second;

    if (is_equal(first, second)) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    return 0;
}