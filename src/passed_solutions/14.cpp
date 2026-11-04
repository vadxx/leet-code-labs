#include <cstdio>

#include <string>
#include <vector>

template <typename T> T &as_lvalue(T &&val) { return val; }

using std::string;
using std::vector;

// 14. Longest Common Prefix
// https://leetcode.com/problems/longest-common-prefix/
class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.empty()) {
      return "";
    }
    // Vertical scanning algorighm:
    // Check one position across all strings before moving to the next position.
    string res;
    std::size_t i = 0;
    // Check characters in the first word
    for (; i < strs[0].length(); i++) {
      // Compare the characters at the same position in the other words
      for (std::size_t j = 1; j < strs.size(); j++) {
        // Stop in 2 cases:
        if ( // 1: The next word has no character at position i
            i >= strs[j].size() ||
            // 2: Its character at position i differs from the first word
            strs[0][i] != strs[j][i]) {
          return strs[0].substr(0, i);
        }
      }
    }
    return strs[0].substr(0, i);
  }
};

int main() {
  Solution s;
#define PRINT_RET(NUM, ...)                                                    \
  printf("[CASE " #NUM "]:\n");                                                \
  printf(                                                                      \
      "res: %s\n",                                                             \
      s.longestCommonPrefix(as_lvalue<vector<string>>(__VA_ARGS__)).c_str());
  // Cases
  PRINT_RET(1, {"flower", "flow", "flight"}); // expected value: "fl"
  PRINT_RET(2, {"dog", "racecar", "car"});    // expected value: ""
#undef PRINT_RET
  return 0;
}
