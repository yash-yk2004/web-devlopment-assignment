#include <iostream>
using namespace std;

bool isMatch(string text, string pattern) {

    int i = 0;
    int j = 0;

    while (i < text.length() && j < pattern.length()) {

        if (j + 1 < pattern.length() && pattern[j + 1] == '+') {

            char current = pattern[j];

            if (text[i] != current) {
                return false;
            }

            while (i < text.length() && text[i] == current) {
                i++;
            }

            j += 2;
        }
        else {

            if (text[i] != pattern[j]) {
                return false;
            }

            i++;
            j++;
        }
    }

    return (i == text.length() && j == pattern.length());
}

int main() {

    string P, Q;

    cout << "Enter String P: ";
    cin >> P;

    cout << "Enter Pattern Q: ";
    cin >> Q;

    if (isMatch(P, Q)) {
        cout << "True";
    }
    else {
        cout << "False";
    }

    return 0;
}