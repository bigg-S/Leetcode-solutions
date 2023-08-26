#include <vector>
#include <iostream>

int give_change(std::vector<int> currency_levels, int change);

int main()
{
    int change;
    int levels;
    int size;
    std::cout << "How many times can the highest amount in your currency be divided?: ";
    std::cin >> size;

    //int* currency_level = new int[size];(a method for declaring a dynamic array. 
    //Its not effecient since it needs the programmer to remember delete[] as opposed to vectors which do that automatically)
    std::vector<int> currency_level;

    for (int i = 1;i <= size;i++)
    {
        if (i == 1)
        {
            std::cout << "Enter the lowest value of your currency: ";
            std::cin>>levels;
            currency_level.push_back(levels);
        }
        else if (i == size)
        {
            std::cout << "And finally the highest: ";
            std::cin >> levels;
            currency_level.push_back(levels);
        }
        else
        {
            std::cout << "The next level: ";
            std::cin >> levels;
            currency_level.push_back(levels);
        }
    }

    std::cout << "You just entered: ";
    for (int j = 0;j < currency_level.size();j++)
    {
        if (j == currency_level.size())
        {
            std::cout << currency_level.at(j) << " ";
        }
        else
        {
            std::cout << currency_level.at(j) << ", ";
        }
    }

    std::cout << "\nHow much is the change you wish to give?: ";
    std::cin >> change;

    std::cout << "This is the best breakdown of how you should give the change: ";

    give_change(currency_level, change);    

    return 0;
}

int give_change(std::vector<int> currency_levels, int change)
{
    int size = currency_levels.size();
    std::vector<int> return_change;
    int i = 0;
    bool done = false;
    for (i = 0;i < size;i++)
    {
        while (currency_levels[i] >= change && done == false)
        {
            if (currency_levels[i] == change)
            {
                change -= currency_levels[i];
                return_change.push_back(currency_levels[i]);
                done = true;
            }
            else
            {
                change -= currency_levels[i - 1];
                return_change.push_back(currency_levels[i - 1]);
                i = 0;
            }
            
        }
    }


    for (int j = 0;j <= return_change.size() - 1;j++)
    {
        std::cout << return_change.at(j) << " ";
    }
    return 0;
}
