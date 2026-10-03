#include <stdio.h>
#include <stdint.h>

// 7. Reverse Integer
// https://leetcode.com/problems/reverse-integer/
class Solution {
public:
  int reverse(int x) {
    long result = 0;
    int digit;
    while (x != 0) {
      digit = x % 10; // extract digit, apply to result by shifting
      result = result * 10 + digit;
      x /= 10; // drop the digit
    }
    return (result < INT32_MIN) || (result > INT32_MAX) ? 0 : result;
  }
};

int main() {
  Solution s;
  printf("res: %d\n", s.reverse(123)); // expected value: 321
  printf("res: %d\n", s.reverse(-123)); // expected value: -321
  printf("res: %d\n", s.reverse(120));  // expected value: 21
}