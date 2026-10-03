#include <cstdio>
#include <string>
using std::string;

#define USE_HASHMAP 0

#if USE_HASHMAP
#include <unordered_map>
using std::unordered_map;
#else
#include <memory.h>
#endif

// 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters
class Solution3 {
public:
#if USE_HASHMAP
  int lengthOfLongestSubstring(string s) {
    int totalLen = s.length();
    if (totalLen <= 1)
      return totalLen;
    unordered_map<char, int> hash; // seen char in string, longest len
    const char *pData = s.data();
    int startPos = 0;
    int longestLen = 0;

    // tmp variables in loop
    int currentLen;
    char currentSym;
    char targetSym = pData[startPos];

    for (int i = 0; i < totalLen; i++) {
      currentSym = pData[i];

      // symbol found and in current window
      auto it = hash.find(currentSym);
      if (it != hash.end() && it->second >= startPos) {
        // shrink the window
        startPos = it->second + 1;
      }
      hash[currentSym] = i;
      currentLen = i - startPos + 1;
      if (currentLen > longestLen) {
        longestLen = currentLen;
      }
    }
    return longestLen;
  }
#else
  int lengthOfLongestSubstring(string s) {
    int totalLen = s.length();
    if (totalLen <= 1)
      return totalLen;

    // init hash - indexes of only ASCII (0–127) chars 
    int map[128];
    for (int i = 0; i < 128; i++) map[i] = -1;

    const char *pData = s.data();

    // tmp data
    int longestLen = 0;
    int currentLen;
    char currentChar;
    int left = 0;

    for (int right = 0; right < totalLen; right++) {
      currentChar = pData[right];

      // move left bound when the current char inside the current window
      if (map[currentChar] >= left) {
        // begins just after the char's last seen index
        left = map[currentChar] + 1;
      }

      map[currentChar] = right;
      currentLen = right - left + 1; //  inclusive distance in window
      if (currentLen > longestLen) {
        longestLen = currentLen;
      }
    }
    return longestLen;
  }
#endif
};

#undef USE_HASHMAP

int main() {
  Solution3 s;
  printf("res: %d\n", s.lengthOfLongestSubstring("abcabcbb")); // 3
  printf("res: %d\n", s.lengthOfLongestSubstring("bbbbb"));    // 1
  printf("res: %d\n", s.lengthOfLongestSubstring("pwwkew"));   // 3
  printf("res: %d\n", s.lengthOfLongestSubstring("mq"));       // 2
  return 0;
}