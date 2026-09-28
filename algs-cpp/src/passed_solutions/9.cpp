#include <cstdio>
template <typename T> T &as_lvalue(T &&val) { return val; }

// 9. Palindrome Number
// https://leetcode.com/problems/palindrome-number/description/
class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0 || (x != 0 && x % 10 == 0)) {
      return false;
    }
    if (x == 0 || (x > 0 && x < 10)) {
      return true;
    }
    int digit;
    int reversedHalf = 0;
    while (x > reversedHalf) {
      digit = x % 10; // extract the most right digit
      reversedHalf = reversedHalf * 10 + digit;
      x /= 10; // drop the digit
    }
    // second cond: drop middle digit in odd input case
    return x == reversedHalf || x == (reversedHalf / 10);
  }
};

int main() {
  Solution s;
  printf("res: %d\n", s.isPalindrome(121)); // expected value: true
  printf("res: %d\n", s.isPalindrome(-121)); // expected value: false
  printf("res: %d\n", s.isPalindrome(10));   // expected value: false
  printf("res: %d\n", s.isPalindrome(100)); // expected value: false
  printf("res: %d\n", s.isPalindrome(0));   // expected value: true
  return 0;
}