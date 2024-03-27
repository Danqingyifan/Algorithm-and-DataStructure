// Problem Number: 739
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> result(temperatures.size(), 0);
        stack<int> s;
        for (int i = 0; i < temperatures.size(); i++)
        {
            while (!s.empty() && temperatures[i] > temperatures[s.top()])
            {
                int index = s.top();
                s.pop();
                result[index] = i - index;
            }
            s.push(i);
        }
        return result;
    }
};