#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        int curr = 0, total = 0;
        for (int i = 2; i < n; i++) {
            if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                curr++; 
                total += curr;
            } else {
                curr = 0;
            }
        }

        return total;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    cout << sol.numberOfArithmeticSlices(nums) << endl; // Output: 3
    return 0;
}

//we cant do just total++
// Short answer: **❌ No, you cannot just do `total++`**

// ---

// # 🧠 Why `total++` is wrong

// Because at each index, you might be forming **more than one new slice**, not just one.

// ---

// ## 🧪 Example

// ```cpp
// nums = [1,2,3,4]
// ```

// ---

// ### At `i = 2`

// ```cpp
// [1,2,3] → valid
// ```

// 👉 `total = 1`

// ---

// ### At `i = 3`

// ```cpp
// [2,3,4] → valid
// [1,2,3,4] → also valid
// ```

// 👉 **2 new slices**, not 1

// ---

// # 🔥 What happens if you do `total++`

// | i | total (wrong) |
// | - | ------------- |
// | 2 | 1             |
// | 3 | 2 ❌           |

// 👉 But correct answer = **3**

// ---

// # ✅ Why `curr++` works

// ```cpp
// curr++;
// total += curr;
// ```

// ---

// ## 🧠 Meaning of `curr`

// 👉 `curr` = number of arithmetic slices **ending at current index**

// ---

// ## 🧪 Same example

// ```cpp
// [1,2,3,4]
// ```

// | i | curr | total |
// | - | ---- | ----- |
// | 2 | 1    | 1     |
// | 3 | 2    | 3 ✅   |

// ---

// # 🔥 Intuition

// When sequence continues:

// * Previous slices can be **extended**
// * Plus new slice is formed

// 👉 So slices grow like:

// ```text
// 1 → 2 → 3 → ...
// ```

// ---

// # ⚡ Key Insight

// | Approach        | Result                   |
// | --------------- | ------------------------ |
// | `total++`       | ❌ misses extended slices |
// | `total += curr` | ✅ counts all             |

// ---

// # 💡 Interview Line

// > “Each valid extension creates multiple new slices, so we accumulate using `curr` instead of just incrementing by 1.”

// ---

// # 🧠 One-line memory trick

// 👉

// > “If pattern continues → slices grow cumulatively, not linearly”

// ---

