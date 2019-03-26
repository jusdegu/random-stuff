/*
 *  Justin De Guzman 
 *  25 March 2019
 * 
 *  This program iterates through number ranges l and r and returns numbers that contain 6 or 8.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isExclusive (int);

int main() {
    vector <int> exclusives;
    int l, r;

    cout << "Enter first and second numbers: ";
    cin >> l;
    cin >> r;

    for (int i = l; i <= r; ++i) {  // This is the main loop that's present in the problem.
        if (isExclusive(i)){
            exclusives.push_back(i);
        }
    }

    for (size_t i = 0; i < exclusives.size(); ++i) { // output the saved numbers. These numbers contain a 6 or 8.
        cout << "i: " << exclusives[i] << '\n';
    }

    return 0;
}

bool isExclusive (int n) {  // Returns true if number contains a 6 or an 8.
    bool flag = false;
    int div = 1;

    while (n > div) {
        if (n/div%10 == 6 || n/div%10 == 8) { // check to see if the number contains a 6 or an 8
            flag = true;
        }
        div *= 10;
    }
    return flag;
}