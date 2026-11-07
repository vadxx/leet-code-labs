#include "helpers.h"
#include <cstring>

using std::string;
using std::vector;

// 17. Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
//
// Given a string containing digits 2-9
// Return all positive letter combinations in any order
// Mapping of digits to letters like of telephone buttons. 1 does not map to
// any.
class Solution {
public:
  vector<string> letterCombinations(string digits) {
    constexpr std::string_view kMap[] = {"",    "",    "abc",  "def", "ghi",
                                         "jkl", "mno", "pqrs", "tuv", "wxyz"};

    // Starts with one empty combination before any digit is processed
    vector<string> res;
    res.push_back("");
    string combination;

    std::string_view val; // Letters for current digit
    int oldSize;

    for (int i = 0; i < digits.length(); i++) {
      val = kMap[digits[i] - '0'];

      oldSize = res.size();

      // First letter can reuse the existing strings in res.
      for (int k = 0; k < oldSize; k++) {
        res[k].push_back(val[0]);
      }

      // Remaining letters
      for (int j = 1; j < val.length(); j++) {
        for (int k = 0; k < oldSize; k++) {
          combination = res[k];        // copy old combination
          combination.back() = val[j]; // replace it by adding new one symbol
          res.push_back(std::move(combination)); // move old value to the new
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
  print_vector(s.letterCombinations(__VA_ARGS__))

  // Cases
  PRINT_CASE(
      1,
      "23"); // expected value: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
  PRINT_CASE(2, "2"); // expected value: ["a","b","c"]

#undef PRINT_CASE
}