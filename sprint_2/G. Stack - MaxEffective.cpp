#include <iostream>
#include <vector>
#include <string>

#define INT_MIN -2147483648

using namespace std;

class Stack {

public:
	vector<int> items;

	int size() {
		return items.size();
	}

	void push(int item) {
		items.push_back(item);
	}

	int pop() {
		int lastItem = items.back();
		items.pop_back();
		return lastItem;
	}

	int peek() {
		return items.back();
	}
};


class StackMaxEffective {
private:
	vector<int> items;
	Stack max_stack;

public:
	int size() {
		return items.size();
	}

	void push(int item) {

		if (!items.empty()) {
			if (item > max_stack.peek()){
				items.push_back(item);
				max_stack.items.push_back(item);
			}
			else{
				items.push_back(item);
				max_stack.items.push_back(max_stack.peek());
			}

		}
		else {
			items.push_back(item);
			max_stack.items.push_back(item);
		}

	}

	int pop() {
		int lastItem = items.back();
		items.pop_back();
		max_stack.items.pop_back();
		return lastItem;
	}

	int peek() {
		return items.back();
	}

	int get_max() {
		if (!items.empty()) {
			return max_stack.peek();
		}
		else
			return INT_MIN;
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
	StackMaxEffective stack;
	int n;
	cin >> n;
	string command;
	vector<string> parsed_command;
	vector<vector<string>> commands(n);

	for (int i = 0; i < n + 1; ++i) {

		getline(cin, command);
		parsed_command = split(command, ' ');
		if (parsed_command[0] == "get_max") {
			int max = stack.get_max();
			if (max == INT_MIN)
				cout << "None" << '\n';
			else
				cout << max << '\n';
		}
		else if (parsed_command[0] == "pop") {
			if(stack.size() == 0)
				cout << "error" << '\n';
			else
				stack.pop();
		}
		else if (parsed_command[0] == "push") {
			stack.push(stoi(parsed_command[1]));
		}
	}

	return 0;
}
