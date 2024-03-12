// Problem Number: 287
#include <vector>
class Solution
{
public:
    // Fast and Slow Pointer
    // Regard array as circle,linked list cycle detection
    int FindDuplicate(std::vector<int> &nums)
    {
        int slow = 0;
        int fast = 0;
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = 0;
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};