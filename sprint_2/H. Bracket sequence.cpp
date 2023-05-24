#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Stack {

private:
	vector<char> items;

public:

	int size() {
		return items.size();
	}

	void push(int item) {
		items.push_back(item);
	}

	char pop() {
		if(!items.empty()) {
			char lastItem = items.back();
			items.pop_back();
			return lastItem;
		}
		else
			return '0';
	}

	char peek() {
		if(!items.empty())
			return items.back();
		else
			return '0';
	}
};


bool is_correct_bracket_seq(const string& bracket_seq) {

	if (bracket_seq.empty())
		return true;

	Stack stack;

	stack.push(bracket_seq[0]);

	for(int i = 1; i < bracket_seq.size(); ++i) {
		if(stack.peek() == '(' && bracket_seq[i] == ')')
			stack.pop();
		else if(stack.peek() == '{' && bracket_seq[i] == '}')
			stack.pop();
		else if(stack.peek() == '[' && bracket_seq[i] == ']')
			stack.pop();
		else
			stack.push(bracket_seq[i]);
}

if(stack.size())
return false;
else
return true;


}


void print(const bool &result) {
	if (result)
		cout << "True" << endl;
	else
		cout << "False" << endl;
}


int main() {
	string bracket_seq;
	cin >> bracket_seq;

	print(is_correct_bracket_seq(bracket_seq));

	return 0;
}
