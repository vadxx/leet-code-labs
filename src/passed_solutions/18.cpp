#include "helpers.h"
#include <algorithm>

using std::vector;

// 18. 4Sum
// https://leetcode.com/problems/4sum/description/
//
// Given an array nums of N integers
// Return an array of all the unique quadruplets
// [nums[a], nums[b], nums[c], nums[d]] such that: 0 <= a,b,c,d < N
// and nums[a] + nums[b] + nums[c] + nums[d] == target
class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    // Sort to enable the two-pointer scan and easy duplicate skipping
    sort(nums.begin(), nums.end());

    vector<vector<int>> res;
    int n = static_cast<int>(nums.size());

    for (int i = 0; i < n - 3; ++i) {
      // Skip duplicate first values
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      for (int j = i + 1; j < n - 2; ++j) {
        // Skip duplicates second values
        if (j > i + 1 && nums[j] == nums[j - 1]) {
          continue;
        }

        // this type fixes overflow
        long long remaining = 1LL * target - nums[i] - nums[j];

        long long minPair = 1LL * nums[j + 1] + nums[j + 2];
        long long maxPair = 1LL * nums[n - 2] + nums[n - 1];

        if (minPair > remaining) {
          break; // even the minimal pair is too big
        }
        if (maxPair < remaining) {
          continue; // even the max pair is too small
        }

        twoSum(nums, i, j, remaining, res);
      }
    }

    return res;
  }

private:
  void twoSum(const vector<int> &nums, int i, int j, long long target,
              vector<vector<int>> &res) {
    int low = j + 1;
    int high = static_cast<int>(nums.size()) - 1;

    while (low < high) {
      long long sum = 1LL * nums[low] + nums[high];

      if (sum < target) {
        low++;
      } else if (sum > target) {
        high--;
      } else {
        res.push_back({nums[i], nums[j], nums[low], nums[high]});

        low++;
        high--;

        // Skip duplicate values for i (would produce identical triplets)
        while (low < high && nums[low] == nums[low - 1]) {
          low++;
        }
        while (low < high && nums[high] == nums[high + 1]) {
          high--;
        }
      }
    }
  }
};

int main() {
  Solution s;

#define LIST(...) __VA_ARGS__
#define PRINT_CASE(NUM, INIT_LIST, TARGET)                                     \
  printf("[CASE " #NUM "]:\n");                                                \
  print_vector(s.fourSum(as_lvalue<vector<int>>({INIT_LIST}), TARGET))

  // Cases
  PRINT_CASE(1, LIST(1, 0, -1, 0, -2, 2),
             0); // expected: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
  PRINT_CASE(2, LIST(2, 2, 2, 2, 2), 8); // expected: [[2,2,2,2]]

#undef PRINT_CASE
}