/*
ID решения - 88174955

-- ПРИНЦИП РАБОТЫ --
Как работает in-place quick sort
Как и в случае обычной быстрой сортировки, которая использует дополнительную память, выбирается pivot, а затем меняется порядок массива таким образом, что элементы, стоящие перед pivot, больше его, а стоящие после, меньше.
Для сравнения элементов используется компаратор, который возвращает 0, если первый элемент больше второго, и 1, если меньше, и 2 при равенстве(случай не учитывается при работе программы).
В случае in-place quick sort, вместо того, чтобы создавать новые массивы, меняется порядок элементов в исходном массиве.
Для этого используются два указателя - left и right, которые изначально указывают на левый и правый концы отрезка соответственно.
Затем left двигается вправо до тех пор, пока он указывает на элемент, меньший опорного. Аналогично двигается right влево, пока он стоит на элементе, превосходящем опорный.
В итоге окажется, что что левее от left все элементы точно принадлежат первой группе, а правее от right — второй. Элементы, на которых стоят указатели, нарушают порядок. Поменяем их местами и продвинем указатели на следующие элементы.
Будем повторять это действие до тех пор, пока left и right не столкнутся.
Затем сортировка вызывается рекурсивно для двух полученных частей.

-- ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ --
Поскольку в случае in-place quick sort просто меняется порядок элементов в исходном массиве в отличае от классической версии, то для доказательства корректности алгоритма достаточно доказать корректность обычной быстрой сортировки.

-- ВРЕМЕННАЯ СЛОЖНОСТЬ --
Временная сложность быстрой сортировки в хужшем случае O(n^2), в среднем O(n*log(n)), где n - количество элементов в массиве.

-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
Поскольку все манипуляции с элементами массива происходят путем перестановок, то пространственная сложность алгоритма - O(1), где n - количество элементов в массиве.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define INT_MAX 2147483647

using namespace std;

struct triple {
	string name;
	int mark{};
	int fine{};
};

triple split(string str, char separator) {
	triple split_string;
	string word;
	int counter = 0;
	for (int i = 0; i < str.size() + 1; ++i) {
		if (str[i] != separator && str[i] != '\0')
			word += str[i];
		else {
			if (counter == 0) {
				split_string.name = word;
				word.clear();
			}
			else if (counter == 1) {
				split_string.mark = stoi(word);
				word.clear();
			}
			else if (counter == 2) {
				split_string.fine = stoi(word);
				word.clear();
			}
			counter++;
		}
	}
	return split_string;
}

int compare(triple first, triple second) {

	if (first.mark > second.mark) {
		return 0;
	}
	else if (first.mark == second.mark) {
		if (first.fine < second.fine) {
			return 0;
		}
		else if (first.fine == second.fine) {
			if (first.name > second.name) {
				return 1;
			}
			else if (first.name == second.name) {
				return 2;
			}
			else {
				return 0;
			}
		}
		else {
			return 1;
		}
	}
	else {
		return 1;
	}

}

void quicksort(vector<triple> *array, unsigned begin, unsigned end, int (*compare)(triple, triple)) {
	if (begin >= end || end > array->size()) {
		return;
	}
	else {
		unsigned left = begin;
		unsigned right = end;
		unsigned pivot_position = (begin + end) / 2;
		triple pivot = (*array)[pivot_position];
		while (left < right) {
			while (compare((*array)[left], pivot) == 0) {
				left++;
			}
			while (compare((*array)[right], pivot) == 1) {
				right--;
			}
			if (left >=right) {
				break;
			}
			swap((*array)[left], (*array)[right]);
		}

		quicksort(array, begin, right - 1, compare);
		quicksort(array, right + 1, end, compare);
	}
}

int main() {
	int n;
	cin >> n;
	string row;
	cin.ignore(INT_MAX, '\n');
	vector<triple> top;

	for (int i = 0; i < n; ++i) {
		getline(cin, row);
		top.push_back(split(row, ' '));
	}

	quicksort(&top, 0, top.size() - 1, compare);

	for (const auto& i : top) {
		cout << i.name << endl;
	}
	return 0;
}