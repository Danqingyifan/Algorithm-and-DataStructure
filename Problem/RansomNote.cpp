// Problem Number: 383
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> magazineMap;
        for (char c : magazine)
        {
            // This shows the count of each character in the magazine
            // If the character is not present in the map, it will be inserted with value 0
            magazineMap[c]++;
            // init them with 1;
        }

        for (char c : ransomNote)
        {
            // use them then decrement them
            if (magazineMap.find(c) == magazineMap.end() || magazineMap[c] == 0)
            {
                return false;
            }
            magazineMap[c]--;
        }
        return true;
    }
};