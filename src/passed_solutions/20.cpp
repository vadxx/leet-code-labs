#include "helpers.h"

#include <cassert>
#include <cstdlib>

using std::string;
using std::vector;

// 20. Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/description
//
// Given a string s containing the chars '(',')','{','}','['.']'
// Determine if the input string is valid:
// 1. Open brackets must be closed by the same type of brackets
// 2. In the correct order
// 3. Close bracket thas a corresponding open bracket of same type
class Solution {
public:
  bool isValid(string s) {
    vector<char> stack;
    for (char c : s) {
      if (c == '(') {
        stack.push_back(')');
      } else if (c == '[') {
        stack.push_back(']');
      } else if (c == '{') {
        stack.push_back('}');
      } else {
        // 1 - given a close bracket, but there is no opening previously
        // 2 - different type of close brackets
        if (stack.empty() || stack.back() != c) {
          return false;
        }
        stack.pop_back(); // we got correct closing bracket
                          // clear the pair from stack
      };
    }
    return stack.empty();
  };
};

void runTest(string str) {
  static Solution s;
  printf("%d\n", s.isValid(str));
}

int main() {
  runTest("()");     // expected: true
  runTest("()[]{}"); // expected: true
  runTest("(]");     // expected: false
  runTest("([])");   // expected: true
  runTest("([)]");   // expected: false
}