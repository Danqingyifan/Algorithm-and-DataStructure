// Problem Number: 131
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int i = 0;
        int j = s.size() - 1;
        while (i <= j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void backtrack(string s, vector<vector<string>> &result, vector<string> &temp, int index)
    {
        if (index == s.size())
        {
            result.push_back(temp);
            return;
        }
        for (int i = index; i < s.size(); i++)
        {
            string sub = s.substr(index, i - index + 1);
            if (isPalindrome(sub))
            {
                temp.push_back(sub);
                backtrack(s, result, temp, i + 1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        if (s.empty())
        {
            return {};
        }
        vector<vector<string>> result;
        vector<string> temp;
        backtrack(s, result, temp, 0);
        return result;
    }
};