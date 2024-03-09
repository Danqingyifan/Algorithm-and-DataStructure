#include <algorithm>
void BubbleSort(int*a,int n)
{
    // 从数组的最后一个元素开始向前遍历
    for (int i = n - 1; i > 0; i--)
    {
        // 对于每个元素，从数组的开始位置遍历到当前元素
        for (int j = 0; j < i; j++)
        {
            // 如果当前元素大于下一个元素，交换它们的位置
            if (a[j] > a[j + 1])
            {
                std::swap(a[j], a[j + 1]);
            }
        }
    }
}
//每次最后端排出一个最大的

// 平均时间复杂度：O(n^2)
// 最优时间复杂度：O(n)
// 最差时间复杂度：O(n^2)

// 空间复杂度: O(1)
// 排序方式: in-place
// 稳定性：稳定