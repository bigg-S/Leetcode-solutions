#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

class Solution
{
public:
    std::string intToRoman(int num)
    {
        std::string roman = "";
        std::vector<int> value{ 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
        std::vector<std::string> cor_str{ "M","CM", "D","CD","C","XC","L","XL","X","IX","V","IV","I" };
        for (int i = 0; i < value.size(); i++)
        {
            while (num >= value[i])
            {
                num -= value[i];
                roman += cor_str[i];
            }
        }
        return roman;
    }
};

class Solution1
{
public:
    std::string intToRoman(int num)
    {
        std::unordered_map<int, std::string>map = { {1000, "M"},{900, "CM"}, { 500, "D" },{400, "CD"},{100, "C"},{90, "XC"},{50, "L"},{40, "XL"},{10, "X"},{9, "IX"},{5,"V"},{4,"IV"},{1,"I"}};

        std::string roman = "";

        for (auto it = map.begin(); it != map.end(); ++it)
        {
            if (map.find(num) != map.end())
            {
                roman += it->second;
                num -= it->first;
            }
            else
            {
                if (num % 1000 > 0)
                {
                    roman += "M";
                    num -= 1000;
                }
                else if (num % 500 > 0)
                {
                    roman += "D";
                    num -= 500;
                }
            }

        }

        return roman;
    }
};

int main()
{
    Solution1 s;
    std::cout<<s.intToRoman(1994);
    return 0;
}
