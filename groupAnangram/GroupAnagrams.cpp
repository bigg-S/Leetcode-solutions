#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

class Solution
{
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs)
    {      
        std::unordered_map<std::string, std::vector<std::string>> _map;
        for (std::string s : strs) 
        {
            std::string temp = s;
            sort(temp.begin(), temp.end());
            _map[temp].push_back(s);
        }
        std::vector<std::vector<std::string>> result;
        for (auto p : _map) 
        {
            result.push_back(p.second);
        }
        return result;
    }
};

int main()
{
    Solution s;
    std::vector<std::string> my_vec = { "eat","tea","tan","ate","nat","bat" };
    s.groupAnagrams(my_vec);
    return 0;
}

