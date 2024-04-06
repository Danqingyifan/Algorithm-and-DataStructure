#include <algorithm>
void SelectionSort(int *a, int n)
{
    // 遍历整个数组
    for (int i = 0; i < n; i++)
    {
        // 假设当前位置是最小值的位置
        int minIndex = i;

        // 从当前位置向后遍历，寻找是否有更小的元素
        for (int j = i; j < n; j++)
        {
            // 如果找到更小的元素，更新最小值的位置
            if (a[j] > a[minIndex])
                minIndex = j;
        }

        // 将最小元素交换到当前位置
        std::swap(a[i], a[minIndex]);
    }
}
//每次选一个最小的排前面

// 平均时间复杂度：O(n^2)
// 最优时间复杂度：O(n^2)
// 最差时间复杂度：O(n^2)

// 空间复杂度: O(1)
// 排序方式: in-place
// 稳定性：不稳定