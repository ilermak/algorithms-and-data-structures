#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long number_of_options(long long n, long long k) {
    if (n == 0) return 0;

    long long divider = 1000000007;
    vector<long long> number_of_options_array(n, 0);
    number_of_options_array[0] = 1;

    for (long long i = 1; i < n; ++i) {
        for (long long j = 1; j <= k && j <= i; ++j) {
            number_of_options_array[i] += number_of_options_array[i - j] % divider;
            number_of_options_array[i] %= divider;
        }
    }

    return number_of_options_array.back();
}


int main() {
    long long n, k;
    cin >> n >> k;
    
    cout << number_of_options(n, k);

    return 0;
}
