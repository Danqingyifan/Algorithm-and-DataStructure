#include <vector>
#include <algorithm>
void ShellSort(std::vector<int> &arr)
{
    // 初始化间隔gap为1，然后不断乘以3并加1，直到gap大于数组长度的三分之一
    int gap = 1;
    while (gap < (int)arr.size() / 3)
    {
        gap = gap * 3 + 1;
    }

    // 从当前gap开始，每次将gap除以3，进行希尔排序
    for (; gap >= 1; gap /= 3)
    {
        // 对每个子序列进行插入排序
        for (int i = 0; i < gap; ++i)
        {
            for (int j = i + gap; j < arr.size(); j += gap)
            {
                // 如果当前元素小于前一个元素，交换它们的位置
                for (int k = j; k - gap >= 0 && arr[k] < arr[k - gap]; k -= gap)
                {
                    std::swap(arr[k], arr[k - gap]);
                }
            }
        }
    }
}
// 使用了一个不同的间隔序列，即3x+1间隔序列
// 这个序列由Donald Shell提出，其中x是整数。
// 这个序列的优点是在任何时候都能保证在h的序列中，任何h个子序列都是互相独立的。

// 平均时间复杂度：O(n^(3/2))
// 空间复杂度: O(1)
// 排序方式: in-place
// 稳定性：不稳定