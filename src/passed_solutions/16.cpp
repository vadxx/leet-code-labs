#include "helpers.h"

// #include <string>
#include <vector>

// using std::string;
using std::vector;

// 16. 3Sum Closest
// https://leetcode.com/problems/3sum-closest/description/
//
// The goal is to find three integers at distinct indicies in nums
// such that the sum is closest to target.
// Return the sum of the three integers.
// Each input would have exactly one solution.
class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    if (nums.size() < 3) {
      return {};
    }

    // Sort to enable the two-pointer scan and easy duplicate skipping
    sort(nums.begin(), nums.end());

    const int N = nums.size();
    // Init with a valid triplet sum
    int closest = nums[0] + nums[1] + nums[2];
    
    int i = 0, low, high, sum;
    for (; i < N - 2; i++) {
      // Skip duplicates
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      low = i + 1;
      high = N - 1;
      while (low < high) {
        sum = nums[i] + nums[low] + nums[high];

        // Keep the sum with the smallest distance to the target
        if (std::abs(sum - target) < std::abs(closest - target)) {
          closest = sum;
        }
        // Move pointers
        if (sum < target) {
          low++;
        } else if (sum > target) {
          high--;
        } else {
          return sum;
        }
      }
    }
    return closest;
  }
};

int main() {
  Solution s;

#define LIST(...) __VA_ARGS__
#define PRINT_CASE(NUM, INIT_LIST, TARGET)                                     \
  printf("[CASE " #NUM "]: %d\n",                                              \
         s.threeSumClosest(as_lvalue<vector<int>>({INIT_LIST}), TARGET));

  PRINT_CASE(1, LIST(-1, 2, 1, -4), 1);
  PRINT_CASE(2, LIST(0, 0, 0), 1);

#undef PRINT_CASE
#undef LIST
}