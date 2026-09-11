#include <cstdio>
#include <vector>
using std::vector;

#define USE_HASHMAP 1

#if USE_HASHMAP
    #include <unordered_map>
    using std::unordered_map;
#endif

// Macro definition
#define PRINT_VECTOR(vec) \
    for (const auto& val : vec) printf("%d ", val); \
    printf("\n");

template <typename T>
T& as_lvalue(T&& val) { return val; }


// 1. Two Sum - https://leetcode.com/problems/two-sum/
class Solution1 {
public:
#if USE_HASHMAP
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash; // seen data in nums
        const int* pData = nums.data();
        const int N = (int)nums.size();

        int need;
        int value; // current in loop
        for (int i = 0; i < N; i++) {
            value = nums[i];
            need = target - value;
            auto it = hash.find(need);
            if (it != hash.end()) { // found
                return {it->second, i};
            }
            hash[value] = i; // store handled value
        }
        return {};
    }
#else
    vector<int> twoSum(vector<int>& nums, int target) {
        const int* pData = nums.data();
        const int N = (int)nums.size();
        for (int left = 0; left < N - 1; left++) {
            const int leftVal = pData[left];
            for (int right = left + 1; right < N; right++) {
                if (leftVal + pData[right] == target) {
                    return {left, right};
                }
            }
        }
        return {}; 
    }
#endif
};

#undef USE_HASHMAP

int main() {
    Solution1 s;
    PRINT_VECTOR(s.twoSum(as_lvalue<vector<int>>({2,7,11,15}), 9)); // [0,1]
    PRINT_VECTOR(s.twoSum(as_lvalue<vector<int>>({3,2,4}), 6)); // [1,2]
    PRINT_VECTOR(s.twoSum(as_lvalue<vector<int>>({3,3}), 6)); // [0,1]
    PRINT_VECTOR(s.twoSum(as_lvalue<vector<int>>({3,2,3}), 6)); // [0,2]
    return 0;
}