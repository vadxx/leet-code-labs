#include <cstdio>

// #include <string>
// #include <vector>

// template <typename T> T &as_lvalue(T &&val) { return val; }

// using std::string;
// using std::vector;

// Task num
// Link
class Solution {
public:
  int func(int arg) {
    int res = 0;
#ifndef NDEBUG
    std::fprintf(stderr, "res=%d\n", res);
#endif
    return res;
  }
};

int main() {
  Solution s;
  printf("res: %f\n", /* s.func(as_lvalue<type>()) */); // expected value: n
}
