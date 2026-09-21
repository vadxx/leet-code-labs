#include <string>
using std::string;
template <typename T> T &as_lvalue(T &&val) { return val; }

// 5. Longest Palindromic Substring
// https://leetcode.com/problems/longest-palindromic-substring/
class Solution {
public:
  string longestPalindrome(string s) {
    const int totalLen = s.length();
    const char *data = s.data();
    
    int start = 0;
    int maxlen = 1;
    int currentLen;
    int left;
    int right;

    // loop for char positions in string
    for (int i = 0; i < totalLen; i++) {
      // center: 1 digit, e.g. "aba"
      left = i;
      right = i;
      while (left >= 0 && right < totalLen && data[left] == data[right]) {
        currentLen = right - left + 1;
        if (currentLen > maxlen) {
          start = left;
          maxlen = currentLen;
        }
        left--;
        right++;
      }
      
      // center: between 2 digits, e.g. "abba"
      left = i;
      right = i + 1;
      while (left >= 0 && right < totalLen && data[left] == data[right]) {
        currentLen = right - left + 1;
        if (currentLen > maxlen) {
          start = left;
          maxlen = currentLen;
        }
        left--;
        right++;
      }

    }
    return s.substr(start, maxlen);
  }
};

int main() {
  Solution s;
  printf("res: %s\n", s.longestPalindrome("babad").data()); // bab
}