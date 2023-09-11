#include <iostream>
#include <string>

using namespace std;

string insert(string str, int index, string substring) {
    int length = str.length();
    int shift = substring.length();
    str.resize(length + shift, ' ');
    if (length > 0) {
        for (int i = length - 1; i >= index; i--) {
            str[i + shift] = str[i];
        }
    }
    for (int i = 0; i < shift; i++) {
        str[index + i] = substring[i];
    }
    return str;
}

int main() {
    string str;
    getline(cin, str);

    string result;
    string buf;

    for (int i = 0; i < str.size() + 1; ++i) {
        if (str[i] >= 'a' && str[i] <= 'z')
            buf += str[i];
        if (str[i] == ' ') {
            result = insert(result, 0, buf + " ");
            buf.clear();
        }
        else if (str[i] == '\0') {
            result = insert(result, 0, buf + " ");
        }
    }
    result[result.size() - 1] = '\n';
    cout << result;

    return 0;
}