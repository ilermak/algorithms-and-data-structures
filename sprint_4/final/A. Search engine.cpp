/*
ID решения - 88930314

-- ПРИНЦИП РАБОТЫ --
Создается хеш-таблица, в которой хранятся пары слово - хеш-таблица документов, в которой хранятся пары номер документа - кол-во вхождений слова в документ.
При добавлении документа происходит разбиение его на слова. Для каждого слова считается его частота в документе и заносится в хеш-таблицу.
При поиске документов по запросу происходит разбиение запроса на слова. Для каждого слова происходит поиск документов, в которых оно встречается.
Для каждого документа считается суммарное кол-во вхождений слов в него. Документы сортируются по убыванию суммарного кол-ва вхождений слов в них.
Выводится 5 документов с наибольшим суммарным кол-вом вхождений слов в них.

-- ВРЕМЕННАЯ СЛОЖНОСТЬ --
Время добавления документов: O(L), где L - кол-во символов в документах.
Время поиска документов по запросу: O(K * N), но в случае коллизий может быть O(K * N * L),  где K - кол-во слов в запросе, N - кол-во документов, L - кол-во символов в документах.
Время сортировки документов: O(N).
Время вывода 5 документов: O(1).
Суммарная сложность по времени: O(L + K * N + M * N + M * 1)) = O(L + K * N), но в случае коллизий может достигать O(K * N * L), где M - кол-во запросов.

-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
Память на хранение документов: O(L/2) = O(L), если чередуется пробел и уникальный символ.
Память на хранение документов, в которых встречается слово: O(N), где N - кол-во документов.
Суммарная сложность по памяти: O(L + N).



*/

#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> split(string str, char separator) {
	vector<string> split_string;
	string word;
	for (int i = 0; i < str.size() + 1; ++i) {
		if (str[i] != separator && str[i] != '\0')
			word += str[i];
		else {
			split_string.push_back(word);
			word.clear();
		}
	}
	return split_string;
}

unordered_set<string> split_string_to_set(const string& str, char separator) {
	unordered_set<string> split_string;
	string word;
	for (int i = 0; i < str.size() + 1; ++i) {
		if (str[i] != separator && str[i] != '\0')
			word += str[i];
		else {
			split_string.insert(word);
			word.clear();
		}
	}
	return split_string;
}

void find_top_n_max(vector<pair<int, int>>& arr, int n) {
	if (n > arr.size())
		n = arr.size();

	for (int i = 0; i < n; i++) {
		int max_index = i;
		for (int j = i + 1; j < arr.size(); j++) {
			if (arr[j].second > arr[max_index].second ||
				(arr[j].second == arr[max_index].second && arr[j].first < arr[max_index].first)) {
				max_index = j;
			}
		}
		swap(arr[i], arr[max_index]);
	}
}

int main() {
	int n, m;
	cin >> n;

	unordered_map<string, unordered_map<int, int>> words; // Память: O(L/2) = O(L),
	// где L - суммарная длинна всех строк документов (если чередуется пробел и уникальный символ)
	string document;
	cin.ignore();
	// Время: O(L), L - суммарная длинна всех строк документов
	for (int i = 0; i < n; ++i) {
		getline(cin, document);
		for (const auto& word : split(document, ' ')) {
			words[word][i]++;
		}
	}

	cin >> m;

	string request;
	cin.ignore();
	// Время: O(K * N), но в случае коллизий может быть O(K * N * L), K суммарная длина всех строк запросов, N кол-во документов (если все слова запросов есть во всех документах)
	for (int i = 0; i < m; ++i) { // Время: O(M), M - кол-во запросов
		getline(cin, request);
		vector<pair<int, int>> result(n, pair<int, int>(0, 0)); // Память: O(N)
		for (const auto& word : split_string_to_set(request, ' ')) {
			if (words.find(word) != words.end()) {
				for (auto doc : words[word]) { // Время: O(N)
					if (words[word].find(doc.first) != words[word].end()) { // Время: O(1), но в случае коллизий может быть O(L)
						result[doc.first].first = doc.first + 1;
						result[doc.first].second += words[word][doc.first];
					}
				}
			}
		}
		find_top_n_max(result, 5); // Время: O(5 * N) = O(N)
		for (auto k = 0; k < 5 && k < n; k++) { // Время: O(5) = O(1)
			if(result[k].second != 0)
				cout << result[k].first << " ";
		}
		cout << endl;
	}

	return 0;
}