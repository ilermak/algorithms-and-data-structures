/*
ID решения - 90296227

-- ПРИНЦИП РАБОТЫ --
По мере ввода строк, они распаковываются с помощью функции unpack_string и сравниваются с префиксом предыдущей с помощью match_prefix.
Функция unpack_string проходит по всем символам строки и проверяет какой это символ,
если символ буква, то ее добавляют в результирующую строку,
если встречается цифра, то она ее сохраняет и ожидает [,
если  [, то подстрока добавляется на стек и начинается новый уровень рекурсии
если ], то заканчивается текущий уровень рекурсии и результирующую строку добавляется n подстрок.

-- ВРЕМЕННАЯ СЛОЖНОСТЬ --
O(N * M), где N - кол-во строк, а M - длина строки.

-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
O(M), где M - длина строки.

*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

string unpack_string(const string& str) { // Время - O(n), память - O(n)
    string current_str;
    stack<pair<string, int>> stack;
    int multiplier = 0;

    for (auto c : str) {
        if (c >= '0' && c <= '9') {
            multiplier = c - '0';
        }
        else if (c == '[') {
            stack.emplace(current_str, multiplier);
            current_str = "";
            multiplier = 0;

        }
        else if (c == ']') {
            auto last = stack.top();
            stack.pop();
            string last_string = last.first;
            int last_multiplier = last.second;
            string sub = current_str;
            current_str = last_string;
            for (int i = 0; i < last_multiplier; ++i) {
                current_str += sub;
            }
        }
        else if (c >= 'a' && c <= 'z') {
            current_str += c;
        }
    }

    return current_str;
}

string match_prefix(const string& first, const string& second) { // Время - O(n), память - O(1)
    string prefix;
    for (int i = 0; i < first.size() && i < second.size() && first[i] == second[i]; ++i) {
        prefix += first[i];
    }
    return prefix;
}

int main() {
    int n;
    cin >> n;

    string prev;
    string current;
    if (n > 0) {
        cin >> prev;
    }
    prev = unpack_string(prev);

    for (int i = 1; i < n; ++i) {
        cin >> current;
        current = unpack_string(current);
        prev = match_prefix(prev, current);
    }

    cout << prev;

    return 0;
}