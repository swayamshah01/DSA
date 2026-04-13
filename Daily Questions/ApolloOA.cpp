// 📘 Problem Statement: Stone Transformation Simulation

// While exploring an ancient corridor, a sequence of magical stones is discovered. Each stone has an integer engraved on it, and the stones are arranged in a straight line.

// Every time a transformation is applied, each stone changes according to a fixed set of rules. The transformations are applied simultaneously to all stones, and the order of stones is always preserved.

// 🔄 Transformation Rules

// For each stone with value x, apply the following rules in order:

// If the value is 0:
// Replace it with a single stone having value 1.
// If the number of digits in x is even:
// Split the stone into two stones:
// The left half of the digits becomes the first stone.
// The right half becomes the second stone.
// Any leading zeros are removed from the resulting numbers.

// Otherwise (odd number of digits):
// Replace the stone with a single stone having value:

// x × 2024
// 📥 Input
// An integer array stones representing the initial sequence.
// An integer k representing the number of transformations to apply.
// 📤 Output
// Return the final sequence of stones after applying the transformation rules k times.
// 📌 Example
// Input:
// stones = [1000, 23, 0, 7]
// k = 1
// Output:
// [10, 0, 2, 3, 1, 14168]
// 🔍 Explanation
// 1000 → even digits → split → 10, 0
// 23 → split → 2, 3
// 0 → becomes 1
// 7 → odd digits → 7 × 2024 = 14168
// ⚠️ Constraints
// 1 ≤ stones.length ≤ 10^5
// 0 ≤ stones[i] ≤ 10^9
// 1 ≤ k ≤ 75
// The size of the list may grow significantly after transformations.


#include <bits/stdc++.h>
using namespace std;

vector<long long> transform(vector<long long>& stones) {
    vector<long long> result;

    for (auto x : stones) {

        // Rule 1
        if (x == 0) {
            result.push_back(1);
        }
        else {
            string s = to_string(x);

            // Rule 2: even number of digits
            if (s.length() % 2 == 0) {
                int mid = s.length() / 2;

                string left = s.substr(0, mid);
                string right = s.substr(mid);

                // remove leading zeros automatically via stoll
                long long leftNum = stoll(left);
                long long rightNum = stoll(right);

                result.push_back(leftNum);
                result.push_back(rightNum);
            }
            // Rule 3
            else {
                result.push_back(x * 2024);
            }
        }
    }

    return result;
}

int main() {
    vector<long long> stones = {1000, 23, 0, 7};

    stones = transform(stones);

    for (auto x : stones) {
        cout << x << " ";
    }
}