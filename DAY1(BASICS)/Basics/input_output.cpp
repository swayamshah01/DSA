#include <iostream>
using namespace std;

int main() {
    // Output examples
    cout << "Hello, World!" << endl;
    cout << "Welcome to C++ Input/Output" << endl;
    
    // Input and output variables
    int number;
    string name;
    double decimal;
    
    // Taking input from user
    cout << "Enter your name: ";
    cin >> name;
    
    cout << "Enter an integer: ";
    cin >> number;
    
    cout << "Enter a decimal number: ";
    cin >> decimal;
    
    // Displaying the input
    cout << "\n--- Your Input ---" << endl;
    cout << "Name: " << name << endl;
    cout << "Integer: " << number << endl;
    cout << "Decimal: " << decimal << endl;
    
    return 0;
}