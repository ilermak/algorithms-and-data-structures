/*
ID решения - 87678544

-- ПРИНЦИП РАБОТЫ --
Я реализовал дек определенного размера на статическом массиве(по факту динамическом, но на деле он как статический =) ).
Кольцевой буффер обеспечивает использование индексации по остатку от деления на размер массива.
Есть два указателя head и tail, которые указывают на начало и конец дека соответственно.
Также есть переменная current_size, которая хранит текущее количество элементов в деке.
При добавлении элемента в  конец дека, tail сдвигается на одну позицию вправо. 
При добавлении элемента в начало дека, head сдвигается на одну позицию влево.
При извлечении элемента из конца дека, tail сдвигается на одну позицию влево.
При извлечении элемента из начала дека, head сдвигается на одну позицию вправо.
Если на момент извлечения из очереди current_size == 0, то извлечение не удастся и вернется NULL.
Если на момент добавления в очередь current_size == max_size, то добавление не удастся и ничего не произойдет.
При добавлении элемента в конец дека, если tail == max_size, то tail = 0.
При добавлении элемента в начало дека, если head == -1, то head = max_size - 1.
При извлечении элемента из конца дека, если tail == -1, то tail = max_size - 1.
При извлечении элемента из начала дека, если head == max_size, то head = 0.

-- ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ --
Дек - это структура данных, которая поддерживает операции добавления и удаления элементов с двух концов.

-- ВРЕМЕННАЯ СЛОЖНОСТЬ --
Добавление в дек стоит O(1), потому что запись в массив стоит O(1).
Извлечение из очереди стоит O(1), так как чтение из массива тоже стоит O(1).
Таким образом, временная сложность алгоритма - O(n), где n - количество команд.

-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
Поскольку размер дека фиксирован, то пространственная сложность алгоритма - O(k), где k - размер дека.
*/

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


class MyDequeSized {
    vector<int> queue;
    int max_size;
    int head;
    int tail;
    int current_size;

public:
    MyDequeSized(int n) {
        queue.resize(n);
        max_size = n;
        head = 0;
        tail = 0;
        current_size = 0;
    }

    bool is_empty() {
        return current_size == 0;
    }

    void push_back(int x) {
        if (current_size != max_size) {
            queue[tail] = x;
            tail = (tail + 1) % max_size;
            current_size++;
        }
    }

    void push_front(int x) {
        if (current_size != max_size) {
            head = (head - 1 + max_size) % max_size;
            queue[head] = x;
            current_size++;
        }
    }

    int pop_back() {
        if (is_empty()) {
            return NULL;
        }
        tail = (tail - 1 + max_size) % max_size;
        int x = queue[tail];
        queue[tail] = NULL;
        current_size--;
        return x;
    }

    int pop_front() {
        if (is_empty()) {
            return NULL;
        }
        int x = queue[head];
        queue[head] = NULL;
        head = (head + 1) % max_size;
        current_size--;
        return x;
    }

    int size() {
        return current_size;
    }
};


int main() {
    int n_commands, size;
    cin >> n_commands;
    cin >> size;
    MyDequeSized q(size);

    string command;
    vector<string> parsed_command;
    vector<vector<string>> commands(n_commands);

    for (int i = 0; i < n_commands + 1; ++i) {

        getline(cin, command);
        parsed_command = split(command, ' ');

        if (parsed_command[0] == "push_back") {
            if (q.size() == size)
                cout << "error" << '\n';
            else {
                q.push_back(stoi(parsed_command[1]));
            }
        }
        else if (parsed_command[0] == "push_front") {
            if (q.size() == size)
                cout << "error" << '\n';
            else {
                q.push_front(stoi(parsed_command[1]));
            }
        }
        else if (parsed_command[0] == "pop_back") {
            if(q.is_empty())
                cout << "error" << '\n';
            else
                cout << q.pop_back() << '\n';
        }
        else if (parsed_command[0] == "pop_front") {
            if(q.is_empty())
                cout << "error" << '\n';
            else
                cout << q.pop_front() << '\n';
        }
    }

    return 0;
}