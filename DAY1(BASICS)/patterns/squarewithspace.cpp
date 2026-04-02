#include <iostream>
using namespace std;

int main() {
    int n = 4;

    for (int i = 1; i <= n; i++) {

        // increasing part
        for (int j = 1; j <= i; j++) {
            cout << j;
        }

        // spaces
        for (int s = 1; s <= 2 * (n - i); s++) {
            cout << " ";
        }

        // decreasing part
        for (int j = i; j >= 1; j--) {
            cout << j;
        }

        cout << endl;
    }

    return 0;
}