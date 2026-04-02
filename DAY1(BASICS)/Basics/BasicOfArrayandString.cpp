#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    // ===== ARRAYS =====
    
    // 1. Array Declaration and Initialization
    int arr[5] = {1, 2, 3, 4, 5};
    int arr2[3] = {10, 20, 30};
    
    // 2. Accessing Elements
    cout << "First element: " << arr[0] << endl;
    
    // 3. Array Iteration
    cout << "Array elements: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // 4. Finding Array Size
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Array size: " << size << endl;
    
    // ===== STRINGS =====
    
    // 1. String Declaration
    string str1 = "Hello";
    string str2 = "World";
    string str3(5, 'a'); // "aaaaa"
    
    // 2. String Concatenation
    string result = str1 + " " + str2;
    cout << "Concatenation: " << result << endl;
    
    // 3. String Length
    cout << "Length: " << str1.length() << endl;
    
    // 4. Accessing Characters
    cout << "First char: " << str1[0] << endl;
    
    // 5. String Functions
    str1.append(" World"); // Append
    cout << "Append: " << str1 << endl;
    
    string str4 = "Hello";
    if (str4.find("ell") != string::npos) {
        cout << "Substring found!" << endl;
    }
    
    // 6. Substring
    cout << "Substring: " << str4.substr(1, 3) << endl; // "ell"
    
    // 7. Replace
    string str5 = "Hello World";
    str5.replace(0, 5, "Hi"); // Replace "Hello" with "Hi"
    cout << "After replace: " << str5 << endl;
    
    // 8. Convert to Uppercase/Lowercase
    string str6 = "HeLLo";
    transform(str6.begin(), str6.end(), str6.begin(), ::tolower);
    cout << "Lowercase: " << str6 << endl;
    
    // 9. String Comparison
    if (str1 == str2) {
        cout << "Strings are equal" << endl;
    }
    
    // 10. Empty and Clear
    string str7 = "Test";
    cout << "Is empty: " << str7.empty() << endl;
    str7.clear(); // Remove all characters
    
    return 0;
}