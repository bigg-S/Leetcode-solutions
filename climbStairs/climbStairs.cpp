#include <iostream>
#include <map>

//fibbonacci with memoization
class Solution
{
public:
    int climbStairs(int n)
    {
        static std::map<int, int> my_map = { {0, 1},{1, 1} };
        auto found = my_map.find(n);
        if (found != my_map.end())
            return found->second;
        int cache = climbStairs(n - 1) + climbStairs(n - 2);
        my_map[n] = cache;
        return cache;
    }
};

int main()
{
    Solution s;
    std::cout<<s.climbStairs(1000);
    return 0;
}

