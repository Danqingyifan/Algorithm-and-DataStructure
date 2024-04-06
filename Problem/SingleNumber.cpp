// Problem Number: 136
#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

using namespace std;
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    }
    //对数组中的所有元素进行异或操作，由于异或操作的特性，出现两次的元素在异或操作后会变为0，
    //只出现一次的元素在异或操作后仍然保持原值，所以最后的结果就是只出现一次的元素。
};