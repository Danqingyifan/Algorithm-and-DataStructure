#include <vector>

//它的名字来源于荷兰国旗的三色（红、白、蓝）。
void dutchNationalFlag(std::vector<int> &nums)
{
    int low = 0, mid = 0, high = nums.size() - 1;

    // 遍历数组
    while (mid <= high)
    {
        switch (nums[mid])
        {
        // 如果元素是0（红色），将其移动到数组的前部
        case 0:
            std::swap(nums[low++], nums[mid++]);
            break;
        // 如果元素是1（白色），不需要移动
        case 1:
            mid++;
            break;
        // 如果元素是2（蓝色），将其移动到数组的后部
        case 2:
            std::swap(nums[mid], nums[high--]);
            break;
        }
    }
}