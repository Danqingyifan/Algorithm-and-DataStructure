#include <vector>
#include <stdexcept>

int findMajorityElement(std::vector<int>& nums) {
    int count = 0;
    int candidate = 0;

    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }

    // 验证候选元素是否真的是多数元素
    // 只有在数组中有一个多数元素（出现次数超过一半）的情况下才有效。
    count = 0;
    for (int num : nums) {
        if (num == candidate) {
            count++;
        }
    }

    if (count > nums.size() / 2) {
        return candidate;
    } else {
        throw std::runtime_error("No majority element");
    }
}