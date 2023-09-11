#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int fib_number(int n) {
    if (n == 0) return 0;

    int divider = 1000000007;
    vector<int> fib_numbers_array(n, 0);
    fib_numbers_array[0] = 1;
    fib_numbers_array[1] = 2;

    for (int i = 2; i < n; ++i) {
        fib_numbers_array[i] = (fib_numbers_array[i - 1] + fib_numbers_array[i - 2]) % divider;
    }
    
    return fib_numbers_array.back();
}


int main() {
    int n;
    cin >> n;
    
    cout << fib_number(n);

    return 0;
}
