#include <iostream>
using namespace std;

// Pass by value - original variable is not modified
void passByValue(int x) {
    x = x + 10;
    cout << "Inside passByValue: " << x << endl;
}

// Pass by reference - original variable is modified
void passByReference(int& x) {
    x = x + 10;
    cout << "Inside passByReference: " << x << endl;
}

int main() {
    int num = 5;
    
    cout << "Original value: " << num << endl;
    
    // Pass by value
    passByValue(num);
    cout << "After passByValue: " << num << endl << endl;
    
    // Pass by reference
    passByReference(num);
    cout << "After passByReference: " << num << endl;
    
    return 0;
}