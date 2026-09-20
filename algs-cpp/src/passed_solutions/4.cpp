#include <cstdio>
#include <vector>
using std::vector;

template <typename T> T &as_lvalue(T &&val) { return val; }

// 4. Median of Two Sorted Arrays
// https://leetcode.com/problems/median-of-two-sorted-arrays/
class Solution4 {
public:
  double findMedianSortedArrays(vector<int> &numsA, vector<int> &numsB) {
    const int sizeA = numsA.size();
    const int sizeB = numsB.size();
    const int total = sizeA + sizeB;

    // Mid indexes of the resulting array.
    // In odd 'total' they will be same
    int midLeft = (total - 1) / 2;
    int midRight = total / 2;

    int posA = 0;
    int posB = 0;

    // Resulting median pair: to be defined in bottom loop
    int leftValue = 0;
    int rightValue = 0;

    int next;

    // Loop up to mid right pos from resulting array
    // because after that it doesnt make sense
    for (int mergedPos = 0; mergedPos <= midRight; mergedPos++) {
      // Check boundaries
      const bool takeFromA =
          posA < sizeA && (posB == sizeB || numsA[posA] < numsB[posB]);

      next = takeFromA ? numsA[posA++] : numsB[posB++];

      if (mergedPos == midLeft) {
        leftValue = next;
      }
      if (mergedPos == midRight) {
        rightValue = next;
      }
    }
    return (leftValue + rightValue) / 2.0;
  }
};

int main() {
  Solution4 s;
  printf("res: %f\n",
         s.findMedianSortedArrays(as_lvalue<vector<int>>({1, 3}),
                                  as_lvalue<vector<int>>({2}))); // 2.00000
  printf("res: %f\n", s.findMedianSortedArrays(as_lvalue<vector<int>>({1, 2}),
                                               as_lvalue<vector<int>>({3, 4})));
  // 2.50000

  printf("res: %f\n",
         s.findMedianSortedArrays(as_lvalue<vector<int>>({}),
                                  as_lvalue<vector<int>>({1, 2, 3, 4, 5, 6})));
  // 3.50000

  printf("res: %f\n",
         s.findMedianSortedArrays(as_lvalue<vector<int>>({}),
                                  as_lvalue<vector<int>>({2, 3}))); // 2.50
}