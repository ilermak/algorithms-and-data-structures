#include <iostream>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    if (s.empty()) return 0;

    int result = 0;
    int j = 0;
    unordered_map<char, int> chars;

    for (int i = 0; i < s.size(); ++i) {
        chars[s[i]]++;
        if (chars.size() == i - j + 1) {
            if (i - j + 1 > result) {
                result = i - j + 1;
            }

        }
        else if (chars.size() < i - j + 1) {
            for (; i - j + 1 > chars.size(); ++j) {
                chars[s[j]]--;
                if (chars[s[j]] == 0) {
                    chars.erase(s[j]);
                }
            }
        }
    }

    return result;
}

int main() {
    string str;
    cin >> str;

    cout << lengthOfLongestSubstring(str);

    return 0;
}