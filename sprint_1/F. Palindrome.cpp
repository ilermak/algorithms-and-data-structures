#include <iostream>
#include <string>

using namespace std;


bool IsPalindrome(const string &line) {
    string str;

    for(int i = 0; i < line.length(); ++i) {
        if((line[i] >= '0' && line[i] <= '9') || (line[i] >= 'A' && line[i] <= 'Z') || (line[i] >= 'a' && line[i] <= 'z')) {
            if(line[i] >= 'A' && line[i] <= 'Z')
                str += (char)(line[i] + ('a' - 'A'));
            else
                str += line[i];
        }
    }

    int left = 0;
    int right = str.length() - 1;

    while(left <= right) {
        if(str[left] != str[right]){
            return false;
        }

        left++;
        right--;
    }
    return true;
}

void print(bool result) {
    if (result)
        cout << "True";
    else
        cout << "False";
    cout << endl;
}

int main() {
    string line;
    getline(cin, line);
    print(IsPalindrome(line));
}