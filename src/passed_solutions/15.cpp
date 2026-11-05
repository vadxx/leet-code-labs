#include "helpers.h"
#include <algorithm>

using std::vector;

// 15. 3Sum
// https://leetcode.com/problems/3sum/
//
// Given an integer array nums, return all the triplets
// [nums[i], nums[j], nums[k]], where i != j, i != k, j != k
// and nums[i] + nums[j] + nums[k] == 0
//
// Solution must not contain duplicate triplets
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    if (nums.size() < 3) {
      return {};
    }
    
    // Sort to enable the two-pointer scan and easy duplicate skipping
    sort(nums.begin(), nums.end());

    vector<vector<int>> res;
    
    const int N = nums.size();
    int i = 0, low, high;
    
    // Pick the first element of the triplet; stop with 2 slots left for low/high
    for (; i < N - 2; i++) {
      // Skip duplicates
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      // All remaining values are positive — no zero-sum triplet possible
      if (nums[i] > 0) {
        break;
      }
      low = i + 1;
      high = N - 1;
      const int target = -nums[i]; // we need to find sum of values that will be 0
      
      while (low < high) {
        int sum = nums[low] + nums[high];
        if (sum < target) {
          low++;
        }
        else if (sum > target) {
          high--;
        }
        else {
          res.push_back({nums[i], nums[low], nums[high]});
          // Skip duplicate values for i (would produce identical triplets)
          while(low < high && nums[low] == nums[low + 1]) {
            low++;
          }
          while(low < high && nums[high] == nums[high - 1]) {
            high--;
          }
          // Look for the next pair
          low++;
          high--;
        }
      }
    }
    return res;
  }
};

int main() {
  Solution s;

#define PRINT_CASE(NUM, ...)                                                   \
  printf("[CASE " #NUM "]:\n");                                                \
  print_vector(s.threeSum(as_lvalue<vector<int>>(__VA_ARGS__)))

  // Cases
  PRINT_CASE(1, {-1, 0, 1, 2, -1, -4}); // expected value: [[-1,-1,2],[-1,0,1]]
  PRINT_CASE(2, {0, 1, 1});             // expected value: []
  PRINT_CASE(3, {0, 0, 0});             // expected value: [[0,0,0]]

#undef PRINT_CASE
}
