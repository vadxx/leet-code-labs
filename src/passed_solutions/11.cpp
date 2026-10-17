#include <cstdio>
#include <vector>

template <typename T> T &as_lvalue(T &&val) { return val; }

using std::vector;

// 11. Container With Most Water
// https://leetcode.com/problems/container-with-most-water
class Solution {
public:
  int maxArea(vector<int> &height) {
    int left = 0;
    int right = static_cast<int>(height.size()) - 1;
    int best = 0;

    int hL;
    int hR;
    int width;
    int currentArea;

    while (left < right) {
      // Read container boundaries and compute its width.
      hL = height[left];
      hR = height[right];
      width = right - left;

      // Determine whether left or right walls is limiting,
      // record the resulting area and discard that wall
      if (hL < hR) {
        currentArea = hL * width;
        left++;
      } else {
        currentArea = hR * width;
        right--;
      }

      if (currentArea > best) {
        best = currentArea;
      }

#ifndef NDEBUG
      std::fprintf(
          stderr,
          "left=%d right=%d hL=%d hR=%d width=%d currentArea=%d best=%d\n",
          left, right, hL, hR, width, currentArea, best);
#endif
    }
    return best;
  }
};

int main() {
  Solution s;
  printf("res: %d\n", s.maxArea(as_lvalue<vector<int>>(
                          {1, 8, 6, 2, 5, 4, 8, 3, 7}))); // expected value: 49
  printf("res: %d\n",
         s.maxArea(as_lvalue<vector<int>>({1, 1}))); // expected value: 1
}
