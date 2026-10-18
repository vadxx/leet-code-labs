#include <cstdio>

#include <string>

using std::string;

// 13. Roman to Integer
// https://leetcode.com/problems/roman-to-integer/
class Solution {
public:
  int romanToInt(string s) {
    auto getValue = [](char c) {
      switch (c) {
      case 'M':
        return 1000;
      case 'D':
        return 500;
      case 'C':
        return 100;
      case 'L':
        return 50;
      case 'X':
        return 10;
      case 'V':
        return 5;
      case 'I':
        return 1;
      default:
        return 0;
      }
    };

    int res = 0;
    int current;
    for (size_t i = 0; i < s.length(); i++) {
        current = getValue(s[i]);
        // Check next symbol to resolve cases like IV (4), VI (6)
        if ((i + 1 < s.length()) && (current < getValue(s[i+1]))) {
            res -= current;
        } else {
            res += current;
        }
    }
    return res;
  }
};

int main() {
  Solution s;
  printf("res: %d\n", s.romanToInt("III"));     // expected value: 3
  printf("res: %d\n", s.romanToInt("LVIII"));   // expected value: 58
  printf("res: %d\n", s.romanToInt("MCMXCIV")); // expected value: 1994
}
