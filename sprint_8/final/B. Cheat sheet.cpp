/*
ID решения - 90378056

-- ПРИНЦИП РАБОТЫ --
Работа этого алгоритма основывается на решении задачи о рюкзаке с неограниченным числом предметов
Но в качестве допустимого веса выступает длина текста
Мы идем по строке тексту символ за символом и проверяем, можно ли разбить текст до текущего символа на слова из списка
Для этого мы храним массив, который хранит true, если подстроку длины i можно разбить по заданным словам.

-- ВРЕМЕННАЯ СЛОЖНОСТЬ --
O(T * N * M), где T - длина текста, который нужнно разбить на слова, N - кол-во слов, M - длина слова

-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
O(T * N * M), где T - длина текста
*/

#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

#define N 100100
bool is_correct(const string& crib, const vector<string>& words) {

    bitset<N> dp;
    dp[0] = true;
    string substring;
    for (int i = 1; i <= crib.size(); ++i) {
        for (const auto& word : words) {
            if (i - (int)word.size() >= 0 &&  dp[i - (int)word.size()] && crib.substr(i - word.size(), word.size()) == word) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[crib.size()];
}


int main() {
    string crib;
    cin >> crib;
    int n;
    cin >> n;

    vector<string> words(n);
    for (auto& word : words) {
        cin >> word;
    }

    if (is_correct(crib, words)) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    return 0;
}