#include <cstdio>

#include <string>

using std::string;

// 12. Integer to Roman
// https://leetcode.com/problems/integer-to-roman
class Solution {
public:
  string intToRoman(int num) {

    static constexpr int values[] = {1000, 900, 500, 400, 100, 90, 50,
                                     40,   10,  9,   5,   4,   1};

    // Matches values[i]
    static constexpr const char *symbols[] = {
        "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    // Matches symbols[i]
    static constexpr int lengths[] = {
        1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1
    };

    string result;

    // Gen Roman values from largest one.
    for (int i = 0; num > 0; i++) {
      // Check if the remaining number fits into the Roman values
      while (num >= values[i]) {
        num -= values[i]; // substract its value from the input number

        // Append Roman symbol characters
        result.append(symbols[i], lengths[i]);
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  printf("res: %s\n",
         s.intToRoman(3749).data());            // expected value: "MMMDCCXLIX"
  printf("res: %s\n", s.intToRoman(58).data()); // expected value: "LVIII"
  printf("res: %s\n", s.intToRoman(1994).data()); // expected value: "MCMXCIV"
}
