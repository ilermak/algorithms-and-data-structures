#include <iostream>

using namespace std;

string ToBinary(int number) {
    string result;
    if (number == 0)
        return "0";
    while (number > 0){
        result = (char)(number % 2 + '0') + result;
        number /= 2;
    }
    return result;
}

void print(const string &result) {
    cout << result << endl;
}

int main() {
    int number;
    cin >> number;
    print(ToBinary(number));
}