#include <cstdio>

class Solution3871 {
public:
    long long countCommas(long long n) {
        if (n < 1000) return 0;
        long long commas = 0;
        long start = 1000;
        long valuesRange = 0;
        while (start <= n) {
            valuesRange = n - start + 1; // count zero also
            commas += valuesRange;
            start *= 1000; // shift to next group
        }
        return commas;
    }
};

int main() {
    Solution3871 s;
    printf("%lld\n", s.countCommas(1002)); // 3
    printf("%lld\n", s.countCommas(998)); // 0
    printf("%lld\n", s.countCommas(1409752114));
    return 0;
}