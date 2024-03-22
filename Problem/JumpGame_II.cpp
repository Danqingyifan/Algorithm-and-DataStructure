// Problem Number: 45
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        int jumps = 0, curEnd = 0, curFarthest = 0;
        for (int i = 0; i < n - 1; i++)
        {
            curFarthest = max(curFarthest, i + nums[i]);
            if (i == curEnd)
            {
                jumps++;
                curEnd = curFarthest;
            }
        }
        return jumps;
    }
};

// 这个算法使用了贪心策略。它在每一步都尝试跳到能够在下一步跳得最远的位置。
// 下面是算法的详细步骤：
// 初始化跳跃次数 jumps 为0，当前结束位置 curEnd 为0，当前最远可达位置 curFarthest 为0。
// 遍历数组，对于每个位置 i，更新 curFarthest 为 curFarthest 和 i + nums[i] 中的较大值。这表示从当前位置开始，最远可以跳到 i + nums[i] 的位置。
// 如果 i 等于 curEnd，这表示已经到达了当前的边界，需要进行一次跳跃。增加 jumps 的值，然后更新 curEnd 为 curFarthest，表示新的边界是当前可以跳到的最远位置。
// 当遍历完数组后，jumps 的值就是到达数组末尾所需的最小跳跃次数。