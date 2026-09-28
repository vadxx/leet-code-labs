#include <stdint.h>
#include <string>
using std::string;

// 8. String to Integer (atoi)
// https://leetcode.com/problems/string-to-integer-atoi/description
class Solution {
public:
  int myAtoi(string s) {
    int i = 0;
    const int N = s.length();
    while (i < N && s[i] == ' ')
      i++;

    bool isNeg = false;
    if (i < N && (s[i] == '+' || s[i] == '-')) {
      isNeg = (s[i] == '-');
      i++;
    }
    int result = 0, digit;
    const int limit = isNeg ? INT32_MIN : -INT32_MAX;
    const int appendThreshold = limit / 10;
    const int largestFinalDigit = -(limit % 10);
    while (i < N && s[i] >= '0' && s[i] <= '9') {
      digit = s[i] - '0';
      if (result < appendThreshold ||
          (result == appendThreshold && digit > largestFinalDigit)) {
        return isNeg ? INT32_MIN : INT32_MAX;
      }
      result = result * 10 - digit;
      i++;
    }
    return isNeg ? result : -result;
  }
};

int main() {
  Solution s;
  printf("res: %d\n", s.myAtoi("42"));       // expected value: 42
  printf("res: %d\n", s.myAtoi("   -042"));  // expected value: -42
  printf("res: %d\n", s.myAtoi("1337c0d3")); // expected value:1337
  printf("res: %d\n", s.myAtoi("0-1"));      // expected value: 0
  printf("res: %d\n", s.myAtoi("-91283472332")); // expected value: -2147483648
  printf("res: %d\n", s.myAtoi("21474836460")); // expected value: 2147483647
}