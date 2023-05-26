#include <iostream>
#include <string>
#include <vector>

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


class Node {
public:
	int value;
	Node* next;
	Node* prev;

	Node(int value, Node* next, Node* prev)
			: value(value)
			, next(next)
			, prev(prev)
	{}
};


class MyListQueue {
	int current_size;
	Node* head;
	Node* tail;

public:
	MyListQueue() {
		head = nullptr;
		tail = nullptr;
		current_size = 0;
	}

	bool is_empty() {
		return current_size == 0;
	}

	int get() {
		if (is_empty()) {
			return NULL;
		}

		int x = head->value;
		if (current_size == 1) {
			head = nullptr;
			tail = nullptr;
		}
		else {
			head = head->prev;
			head->next = nullptr;
		}

		current_size--;
		return x;
	}

	void put(int value) {
		Node* put_node = new Node(value, nullptr, nullptr);
		if (is_empty()){

			head = put_node;
			tail = put_node;
		}
		else {

			put_node->next = head;
			tail->prev = put_node;
			tail = tail->prev;
		}
		current_size++;
	}

	int size() {
		return current_size;
	}
};


int main() {
	int n;
	cin >> n;
	MyListQueue q;

	string command;
	vector<string> parsed_command;
	vector<vector<string>> commands(n);

	for (int i = 0; i < n + 1; ++i) {

		getline(cin, command);
		parsed_command = split(command, ' ');
		if (parsed_command[0] == "get") {
			if(q.is_empty())
				cout << "error" << '\n';
			else
				cout << q.get() << '\n';
		}
		else if (parsed_command[0] == "size") {
			cout << q.size() << '\n';
		}
		else if (parsed_command[0] == "put") {
			q.put(stoi(parsed_command[1]));
		}
	}
	
	return 0;
}