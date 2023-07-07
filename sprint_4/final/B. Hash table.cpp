/*
ID решения - 88876007

-- ПРИНЦИП РАБОТЫ --
Хеш-таблица реализована на массиве, в котором хранятся узлы связного списка, для возможности обработки коллизий с помощью метода цепочек.
В узлах списка хранятся пары ключ - значение.
Размер хеш-таблицы создается в зависимости от кол-ва вводимых команд. Конечно так выделяется больше памяти, но зато не нужно заботиться о рехешировании.
Хеш-функция вычисляется путем взятия остатка от деления на кол-во элементов.
Изначально в каждой ячейке массива существует один узел листа, в котором хранится пара нулей.
Добавление пары ключ-значение: если заданный ключ уже есть в таблице, то соответствующее ему значение обновляется. 
Получение значения по ключу: если ключа нет в таблице, то возвращается -1, иначе выводится найденное значение. 
Удаление ключа из таблицы: если такого ключа нет, то возвращается -1, иначе выводится хранимое по данному ключу значение и удаляется ключ.
На случай возникновения коллизий(хеш-функция от разных ключей дает одинаковые номера корзин) используется метод цепочек, создаются дополнительные узлы списка.
В каждой функции осуществляется проход по всем узлам списка(в идеальном случае узел только один).

-- ВРЕМЕННАЯ СЛОЖНОСТЬ --
Поскольку хеш-функция простая и вычисляется за O(1), то все функции будут выполняеться за O(1), но в наихудшем случае коллизий временная сложность может составить O(n).

-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
Поскольку выделяемая память зависит от кол-ва введенных команд, пространственная сложность O(n), если для всех ключей хеш-функия вернет одинаковые значения то у нас выделится n ячеек массива, и в одной из этих ячеек n узлов списка, суммарно получается 2n, в сложность будет O(n). 

*/

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

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


class MyHashMap {
	vector< list< pair<int, int> > > buckets;
	int size_;


	int hash(int k) {
		return (size_ + k % size_) % size_;
	}

public:
	MyHashMap(int size) : buckets(size, list<std::pair<int, int>>(1, std::make_pair(0, 0))),
						  size_(size) {}

	void put(int key, int value) {
        // поиск по key
		auto listIt = find_if(buckets[hash(key)].begin(), buckets[hash(key)].end(), [&](const pair<int, int>& p) {
			return p.first == key;
		});

		if (listIt != buckets[hash(key)].end()) { //нашел key в list
			listIt->second = value;
		}
		else { //не нашел
			if(buckets[hash(key)].back().first == 0 && buckets[hash(key)].back().second == 0) { // нормальный случай
				buckets[hash(key)].back().first = key;
				buckets[hash(key)].back().second = value;
			}
			else { // вставка при коллизии
				buckets[hash(key)].emplace_back(key, value);
			}
		}
	}

	int get(int key) {
        // поиск по key
		auto listIt = find_if(buckets[hash(key)].begin(), buckets[hash(key)].end(), [&](const pair<int, int>& p) {
			return p.first == key;
		});

		if (listIt != buckets[hash(key)].end()) {
			return listIt->second;
		}
		else {
			return -1;
		}
	}

	int delete_key(int key) {
        // поиск по key
		auto listIt = find_if(buckets[hash(key)].begin(), buckets[hash(key)].end(), [&](const pair<int, int>& p) {
			return p.first == key;
		});

		if (listIt != buckets[hash(key)].end()) { //нашел
			if (buckets[hash(key)].size() == 1) { //удаление в нормальном случае 
				int result = buckets[hash(key)].back().second;
				buckets[hash(key)].back().first = 0;
				buckets[hash(key)].back().second = 0;
				return result;
			}
			else { // удаление при коллизии 
				int result = listIt->second;
				buckets[hash(key)].erase(listIt);
				return result;
			}
		}
		else {
			return -1;
		}
	}
};


int main() {
	int n_commands, size;
	cin >> n_commands;

	MyHashMap hashMap(n_commands);

	string command;
	vector<string> parsed_command;

	for (int i = 0; i < n_commands + 1; ++i) {

		getline(cin, command);
		parsed_command = split(command, ' ');

		if (parsed_command[0] == "put") {
			hashMap.put(stoi(parsed_command[1]), stoi(parsed_command[2]));
		}
		else if (parsed_command[0] == "get") {
			int result = hashMap.get(stoi(parsed_command[1]));
			if (result != -1) {
				cout << result << endl;
			}
			else {
				cout << "None" << endl;
			}
		}
		else if (parsed_command[0] == "delete") {
			int result = hashMap.delete_key(stoi(parsed_command[1]));
			if (result != -1) {
				cout << result << endl;
			}
			else {
				cout << "None" << endl;
			}
		}
	}

	return 0;
}