#include <iostream>
using namespace std;

void hollowSquare(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // Check if we are on the boundary
            if (i == 1 || i == n || j == 1 || j == n) {
                cout << "* ";
            } else {
                // Print a gap for the inside
                cout << "  "; 
            }
        }
        cout << endl;
    }
}

int main() {
    
   
    hollowSquare(4);
    return 0;
}