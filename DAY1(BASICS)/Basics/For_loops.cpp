#include <iostream>
using namespace std;

int main() {
    // Simple for loop - prints numbers 1 to 10
    for (int i = 1; i <= 10; i++) {
        cout << i << " ";
    }
    cout << endl;
    
    // For loop with array
    int arr[] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Range-based for loop (C++11)
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}