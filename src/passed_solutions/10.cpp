#include <memory.h>
#include <string>
using std::string;

// 10. Regular Expression Matching
// https://leetcode.com/problems/regular-expression-matching/description/
class Solution {
public:
  bool isMatch(string s, string p) {
    const int LEN_MAX = 20;
    const int S_LEN = s.length();
    const int P_LEN = p.length();

    constexpr char DOT = '.';
    constexpr char STAR = '*';
    // Check constraints of the task
    // Note:
    if ((S_LEN > LEN_MAX || P_LEN > LEN_MAX) || (P_LEN > 0 && p[0] == STAR)) {
      return false;
    }

    // Init
    bool dp[LEN_MAX + 1]
           [LEN_MAX + 1]; // table X: s, Y: p. Including empty ones.
    memset(dp, false, sizeof(dp));
    dp[0][0] = true; // s[0..si) matches p[0..pi). Top left and bottom right
                     // should be true.

    // Empty string can match patterns such as a*, a*b*, a*b*c*.
    // Note: Star cannot be earlier.
    for (int pi = 2; pi <= P_LEN; pi++) {
      if (p[pi - 1] == STAR) {
        dp[0][pi] = dp[0][pi - 2]; // Set the value that before star
      }
    }

    char patternChar;  // current pattern char p[pi-1]
    char stringChar;   // current string char s[si-1]
    char repeatedChar; // char before STAR in pattern p[pi - 2]

    bool skipRepeatedChar;
    bool consumeRepeatedChar; // match X* with current char
    bool restMatchesPattern;

    // si: s-index, pi: p-index
    for (int si = 1; si <= S_LEN; si++) {
      for (int pi = 1; pi <= P_LEN; pi++) {
        // last chars
        patternChar = p[pi - 1];
        stringChar = s[si - 1];

        if (patternChar == STAR) {
          repeatedChar = p[pi - 2];
          skipRepeatedChar = dp[si][pi - 2]; // drop X* from pattern
          restMatchesPattern = dp[si - 1][pi]; // drop last string char, keep X*

          consumeRepeatedChar =
              (repeatedChar == DOT || repeatedChar == stringChar) &&
              restMatchesPattern;

          dp[si][pi] = skipRepeatedChar || consumeRepeatedChar;

        } else {
          if (patternChar == DOT || patternChar == stringChar) {
            dp[si][pi] = dp[si - 1][pi - 1];
          }
        }
      }
    }
    return dp[S_LEN][P_LEN]; // bottom right result of the processed DP-table
  }
};

int main() {
  Solution s;
  printf("res: %d\n", s.isMatch("aa", "a"));   // expected value: false
  printf("res: %d\n", s.isMatch("aaa", "a*")); // expected value: true
  printf("res: %d\n", s.isMatch("ab", ".*"));  // expected value: true
}
