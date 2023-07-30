#include <iostream>
#include <string>
#include <unordered_map>
#include <iomanip>


class Solution1 
{
public:
    int myAtoi(std::string str) 
    {
        int sign = 1, i = 0, result = 0;
        while (str[i] == ' ') 
        {
            i++;
        }
        if (str[i] == '-') 
        {
            sign = -1;
            i++;
        }
        else if (str[i] == '+') 
        {
            i++;
        }
        while (isdigit(str[i])) 
        {
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && str[i] - '0' > 7)) 
            {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            result = result * 10 + (str[i] - '0');
            i++;
        }
        return result * sign;
    }
};


class Solution
{
public:
    int myAtoi(std::string s)
    {
        std::unordered_map<char, int> my_map;
        int my_num = 0;
        int sign = 1;
        bool numStart = false;
        bool sign_or_nah = false;

        my_map['0'] = 0;
        my_map['1'] = 1;
        my_map['2'] = 2;
        my_map['3'] = 3;
        my_map['4'] = 4;
        my_map['5'] = 5;
        my_map['6'] = 6;
        my_map['7'] = 7;
        my_map['8'] = 8;
        my_map['9'] = 9;

        for (auto c : s)
        {
            if (c == ' ' && !numStart && !sign_or_nah)
            {
                continue;
            }
            else if (c == '-' && !numStart && !sign_or_nah)
            {
                sign_or_nah = true;
                sign = -1;
            }
            else if (c == '+' && !numStart && !sign_or_nah)
            {
                sign_or_nah = true;
            }
            else
            {
                if (my_map.find(c) != my_map.end())
                {
                    numStart = true;
                    if (my_num > INT_MAX / 10 || (my_num == INT_MAX / 10 && c - '0' > 7))
                    {
                        return (sign == 1) ? INT_MAX : INT_MIN;
                    }
                    my_num = my_num * 10 + (c - '0');                   
                }
                else
                {
                    return my_num * sign;
                }
            }

        }

        return my_num*sign;
    }
};

int main()
{
    Solution s;
    std::string my_str = "21474836460";
    std::cout<<s.myAtoi(my_str);
    return 0;
}

