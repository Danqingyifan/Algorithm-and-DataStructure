// Problem Number: 17
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> result;
        if (digits.size() == 0)
        {
            return result;
        }
        unordered_map<int, string> hash;
        hash[2] = "abc";
        hash[3] = "def";
        hash[4] = "ghi";
        hash[5] = "jkl";
        hash[6] = "mno";
        hash[7] = "pqrs";
        hash[8] = "tuv";
        hash[9] = "wxyz";

        stack<string> s;
        s.push("");
        while (!s.empty())
        {
            string current = s.top();
            s.pop();
            if (current.size() == digits.size())
            {
                result.push_back(current);
            }
            else
            {
                for (char c : hash[digits[current.size()] - '0'])
                {
                    s.push(current + c);
                }
            }
        }
        return result;
    }
};