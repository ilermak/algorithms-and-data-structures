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


class MyQueueSized {
	vector<int> queue;
	int max_size;
	int head;
	int tail;
	int current_size;

public:
	MyQueueSized(int n) {
		queue.resize(n);
		max_size = n;
		head = 0;
		tail = 0;
		current_size = 0;
	}

	bool is_empty() {
		return current_size == 0;
	}

	void push(int x) {
		if (current_size != max_size) {
			queue[tail] = x;
			tail = (tail + 1) % max_size;
			current_size += 1;
		}
	}

	int pop() {
		if (is_empty()) {
			return NULL;
		}
		int x = queue[head];
		queue[head] = NULL;
		head = (head + 1) % max_size;
		current_size -= 1;
		return x;
	}

	int peek() {
		if (is_empty()) {
			return NULL;
		}
		return queue[head];
	}

	int size() {
		return current_size;
	}
};


int main() {
	int n_commands, size;
	cin >> n_commands;
	cin >> size;
	  q(size);

	string command;
	vector<string> parsed_command;
	vector<vector<string>> commands(n_commands);

	for (int i = 0; i < n_commands + 1; ++i) {

		getline(cin, command);
		parsed_command = split(command, ' ');
		if (parsed_command[0] == "peek") {
			if(q.is_empty())
				cout << "None" << '\n';
			else
				cout << q.peek() << '\n';
		}
		else if (parsed_command[0] == "pop") {
			if(q.is_empty())
				cout << "None" << '\n';
			else
				cout << q.pop() << '\n';
		}
		else if (parsed_command[0] == "size") {
			cout << q.size() << '\n';
		}
		else if (parsed_command[0] == "push") {
			if (q.size() == size)
				cout << "error" << '\n';
			else {
				q.push(stoi(parsed_command[1]));
			}
		}
	}


	return 0;
}