// Problem Number: 287
#include <vector>
class Solution
{
public:
    // Fast and Slow Pointer
    // Regard array as circle,linked list cycle detection
    int findDuplicate(std::vector<int> &nums)
    {
        int slow = nums[0];
        int fast = nums[0];
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = nums[0];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        // the distance between intersection and entrance is
        // always same to the distance between starting and entrance
        return slow;
    }
};

// Math
// 2*slow = fast
// 2*(preEntry + cycle - x) = preEntry + n*cycle - x
// p = (n-2)*cycle + x
// x is distance between the intersection in the cycle and the entrance;
// then now fast + x = entrance, + (n-2)*cycle is still the entrance
// so reset slow to 0,then slow + p = entrance