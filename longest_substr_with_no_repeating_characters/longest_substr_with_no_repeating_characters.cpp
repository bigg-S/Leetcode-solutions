#include <iostream>
#include <string>
#include <unordered_map>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        std::unordered_map<char, int> char_map;
        int start = 0;
        int max_len = 0;
        for (int i = 0; i < s.size(); i++) 
        {
            if (char_map.find(s[i]) != char_map.end() && char_map[s[i]] >= start) 
            {
                start = char_map[s[i]] + 1;
            }
            char_map[s[i]] = i;
            max_len = std::max(max_len, i - start + 1);
        }
        return max_len;
    }
};

int main()
{
    Solution s;
    std::string my_str = "pwwkew";
    s.lengthOfLongestSubstring(my_str);
    return 0;
}


