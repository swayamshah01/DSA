#include <iostream>
#include <vector>
using namespace std;

void leftRotate(vector<int>& arr, int n, int d) {
    // Handle case when d > n
    d = d % n;

    // Step 1: Store first d elements
    vector<int> temp(d);
    for (int i = 0; i < d; i++) {
        temp[i] = arr[i];
    }

    // Step 2: Shift remaining elements to left
    for (int i = d; i < n; i++) {
        arr[i - d] = arr[i];
    }

    // Step 3: Place temp elements at the end
    for (int i = n - d; i < n; i++) {
        arr[i] = temp[i - (n - d)];
    }
}

void rightRotate(vector<int>& arr, int n, int d) {
    // Handle case when d > n
    d = d % n;

    // Step 1: Store last d elements
    vector<int> temp(d);
    for (int i = 0; i < d; i++) {
        temp[i] = arr[n - d + i];
    }

    // Step 2: Shift remaining elements to right
    for (int i = n - d - 1; i >= 0; i--) {
        arr[i + d] = arr[i];
    }

    // Step 3: Place temp elements at the beginning
    for (int i = 0; i < d; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int n, d;

    cout << "Enter size of array: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid array size" << endl;
        return 0;
    }

    vector<int> arr(n);

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter number of rotations: ";
    cin >> d;

    leftRotate(arr, n, d);

    cout << "Array after left rotation:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n";
    rightRotate(arr, n, d);
    cout << "Array after right rotation:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}