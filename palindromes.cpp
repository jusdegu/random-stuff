/*
    Justin De Guzman
    palindromes.cpp

    20 March 2018

    This program just finds all palimdromic substrings within a string.

    Compiled with: g++ -std=c++11 palindromes.cpp -o pal.exe
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <deque>

using namespace std;

bool reverse(deque<char>);
void dump(deque<char>);
string stringify(deque<char>);

int main() {
    string inputStr;
    deque<char> seeker;

    do {
        vector<string> palins;

        cout << "Enter your string (# to exit): ";
        cin >> inputStr;

        cout << "String is: " << inputStr << '\n';

        for (size_t i = 0; i < inputStr.size(); ++i) {
            int j;
            if (i != inputStr.size())
                j = i + 1;
            else
                continue;

            seeker.push_back(inputStr[i]);

            while (j != inputStr.size()) {
                seeker.push_back(inputStr[j]);
                ++j;
            }

            while (seeker.size() > 1) {
                if (reverse(seeker)) {
                    palins.push_back(stringify(seeker));
                    seeker.pop_back();
                }
                else {
                    seeker.pop_back();
                }
            }

            seeker.clear();
        }

        cout << "Palindromes: \n";

        for (size_t i = 0; i < palins.size(); ++i) {
            cout << "   " << palins[i] << '\n';
        }
        cout << endl;
    }
    while (inputStr != "#");

    return 0;
}

bool reverse (deque<char> str) {
    bool flag = true;
    int size = str.size()/2;

    for (size_t i = 0, j = str.size()-1; i < size; ++i, --j) {
        if (str[i] != str[j])
            flag = false;
    }

    // flag ? cout << "Yes, this is a palindrome!\n\n" : cout << "No! This is not a palindrome!\n\n";

    return flag;
}


void dump(deque<char> str) {
    cout << "Output: ";
    for (size_t i = 0; i < str.size(); ++i) {
        cout << str[i];
    }
    cout << "  \n\n";
}


string stringify(deque<char> deq) {
    stringstream ss;
    for (size_t i = 0; i < deq.size(); ++i) {
        ss << deq[i];
    }

    return ss.str();
}

/*
    List of strings to test:
    asdfghjklkjhoiuiopoiiuyrterwqqweasdf
    - hjklkjh
    - jklkj
    - klk
    - oiuio
    - iui
    - iopoi
    - opo
    - ii
    - wqqw
    - qq
    
    
*/
