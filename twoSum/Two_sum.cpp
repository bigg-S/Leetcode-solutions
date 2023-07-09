
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

class Solution
{
public:
    //using c++ pair
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::vector<std::pair<int, int>> el;

        for (int i = 0; i < nums.size(); i++)
        {
            el.push_back({ nums[i], i });
        }

        int first = 0;
        int last = nums.size() - 1;

        while (first < last)
        {
            if (el[first].first + el[last].first == target)
            {
                return { el[first].second, el[last].second };
            }
            else if (el[first].first + el[last].first < target)
            {
                first++;
                if (el[first].second == el[last].second)
                {
                    if (el[first].first == target)
                    {
                        return{ el[first].second };
                    }
                    else
                    {
                        last++;
                        if (el[first].first + el[last].first == target)
                        {
                            return{ el[first].second, el[last++].second };
                        }
                        else
                        {
                            return {};
                        }
                    }
                    
                }
                else
                {
                    first--;
                    first++;
                }
            }
            else
            {
                if(target < 0 && el[first].first < 0  && el[last].first < 0) 
                    first++;
                else
                    last--;
            }
        }
        return {};
    }

    //using unordered map

    std::vector<int> Soln(std::vector<int>& nums, int target)
    {
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            map.insert({ nums[i], i });
        }

        for (int j = 0; j < nums.size(); j++)
        {
            if (map.find(target - nums[j]) != map.end())
            {
                return { j, map[target - nums[j]] };
            }
            else
            {
                map[nums[j]] = j;
            }
        }
    }
};

int main()
{
    Solution s;
    std::vector<int> v = {-10, -1, -18, -19};
    int target = -19;
    s.twoSum(v, target);
    return 0;
}


