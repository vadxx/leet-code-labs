#include "helpers.h"

// #include <string>
// #include <vector>

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

#define PRINT_CASE(NUM, ...)                                                   \
  printf("[CASE " #NUM "]:\n");                                                \
  print_vector(/* s.func(as_lvalue<type>(__VA_ARGS__))) */)

  // Cases
  PRINT_CASE(1, {/**/});  // expected value: N 
  PRINT_CASE(2, {/**/});  // expected value: N

#undef PRINT_CASE
}