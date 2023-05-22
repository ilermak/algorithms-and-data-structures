#include <iostream>
#include <vector>

using namespace std;


int GetWeatherRandomness(const vector <int> &temperatures) {
	int counter = 0;
	if (temperatures.size() == 1)
    	return 1;
	for(int i = 0; i < temperatures.size(); ++i) {
    	if(i == 0 && i + 1 < temperatures.size())
        	if(temperatures[i] > temperatures[i + 1])
        		counter++;
    	if(i == temperatures.size() - 1 && i - 1 >= 0)
        	if(temperatures[i] > temperatures[i - 1])
        		counter++;
        if(i + 1 < temperatures.size() && i - 1 >= 0)
        	if(temperatures[i] > temperatures[i - 1] && temperatures[i] > temperatures[i + 1])
        		counter++;   	
    }
	return counter;
}

void print(int result) {
	cout << result << endl;
}

int main() {
	int n;
	cin >> n;
	vector <int> temperatures(n);
	for (int i = 0; i < n; ++i)
		cin >> temperatures[i];
	print(GetWeatherRandomness(temperatures));
}