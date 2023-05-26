/*
ID решения - 87719558

-- ПРИНЦИП РАБОТЫ --
Я реализовал калькулятор на стеке.
Строка делится на подстроки по пробелам.
Если элемент является числом, то он добавляется в стек.
Если элемент является оператором, то из стека извлекаются два последних элемента, выполняется операция, и результат добавляется в стек.
В конце в стеке остаётся один элемент - результат вычислений.

-- ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ --
Из-за того что в стеке хранятся все элементы строки, то при выполнении операции над двумя последними элементами стека, результат операции будет добавлен в стек, и в дальнейшем будет использован для выполнения следующей операции. 
Таким образом, результат вычислений будет корректным.

-- ВРЕМЕННАЯ СЛОЖНОСТЬ --
Поскольку цикл выполняется n раз, а внутри цикла выполняются операции, которые работают за константное время, то временная сложность алгоритма - O(n), где n - количество элементов в строке.

-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
Так как в стеке хранятся все элементы строки(оператор добавляется как результирующее число), то пространственная сложность алгоритма - O(n), где n - количество элементов в строке.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Stack {
private:
	std::vector<std::string> items;

public:
	void push(std::string item) {
		items.push_back(item);
	}

	std::string pop() {
		std::string lastItem = items.back();
		items.pop_back();
		return lastItem;
	}
};


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


int main() {
	string expression;
	getline(cin, expression);
	Stack stack;
	vector<string> parsed_expression = split(expression, ' ');
	string left, right;
	for (const string& elem : parsed_expression) {
		
		if (elem == "+" || elem == "-" || elem == "*" || elem == "/" ) {
			right = stack.pop();
			left = stack.pop();
			if (elem == "+") {
				stack.push(to_string(stoi(left) + stoi(right)));
			}
			else if (elem == "-") {
				stack.push(to_string(stoi(left) - stoi(right)));
			}
			else if (elem == "*") {
				stack.push(to_string(stoi(left) * stoi(right)));
			}
			else if (elem == "/") {

				if (stoi(left) % stoi(right)  < 0){
					stack.push(to_string(stoi(left) / stoi(right) - 1));
				}
				else {
					stack.push(to_string(stoi(left) / stoi(right)));
				}
			}
		}
		else{
			stack.push(elem);
		}
	}
	
	cout << stack.pop() << endl;

	return 0;
}