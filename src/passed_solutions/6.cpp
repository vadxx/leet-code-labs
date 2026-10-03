#include <string>
using std::string;
template <typename T> T &as_lvalue(T &&val) { return val; }

// 6. Zigzag Conversion
// https://leetcode.com/problems/zigzag-conversion/submissions/2152994732/
class Solution {
public:
  string convert(string s, int numRows) {
    const int totalLen = s.length();
    // Early exit in cases:
    // 1. with one row there is no zigzag movement
    // 2. with enough rows for every character, characters remain in input
    // order.
    if (numRows <= 1 || numRows >= totalLen) {
      return s;
    }
    constexpr int TOP_ROW = 0;
    const int BOTTOM_ROW = numRows - 1;

    char result[1000];

    // zigzag path: top -> bottom -> back to top
    const int ZIGZAG_CYCLE_LEN = 2 * BOTTOM_ROW;
    int resultIndex = 0;

    int row, index, diagonalIndex, diagonalOffset;
    for (row = TOP_ROW; row < numRows; ++row) {
      // step in the middle row
      diagonalOffset = ZIGZAG_CYCLE_LEN - (2 * row);

      // start row's first vertical char and then jump the whole cycle each time
      for (index = row; index < totalLen; index += ZIGZAG_CYCLE_LEN) {
        result[resultIndex++] = s[index];
        // middle row index
        diagonalIndex = index + diagonalOffset;
        if (row != TOP_ROW && row != BOTTOM_ROW && diagonalIndex < totalLen) {
          result[resultIndex++] = s[diagonalIndex];
        }
      }
    }
    return string(result, resultIndex);
  }
};

int main() {
  Solution s;
  printf("res: %s\n", s.convert("PAYPALISHIRING", 3).data()); // expected value:
}