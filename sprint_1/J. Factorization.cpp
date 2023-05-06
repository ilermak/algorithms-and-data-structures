#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> Factorize(int number) {
    vector <int> result;

    for (int i = 2; i * i <= number; ++i) {
        while (number % i == 0) {
            result.push_back(i);
            number /= i;
        }
    }
    if (number != 1)
        result.push_back(number);

    sort(result.begin(), result.end());

    return result;
}

void print(const vector <int> &result) {
    for (int x : result)
        cout << x << " ";
    cout << endl;
}

int main() {
    int number;
    cin >> number;
    print(Factorize(number));
}