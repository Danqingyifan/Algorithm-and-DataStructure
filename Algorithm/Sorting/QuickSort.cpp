#include <vector>
#include <algorithm>
void QuickSort(std::vector<int> &arr, int left, int right)
{
    // 如果左边界大于等于右边界，说明已经没有元素需要排序，直接返回
    if (left >= right)
        return;

    // 选择基准元素
    int pivot = arr[left];
    int i = left, j = right;

    // 当i小于j时，进行循环
    while (i < j)
    {
        // 从右向左找到第一个小于基准的元素
        while (i < j && arr[j] >= pivot)
            j--;
        // 将这个元素放到左边
        arr[i] = arr[j];

        // 从左向右找到第一个大于基准的元素
        while (i < j && arr[i] <= pivot)
            i++;
        // 将这个元素放到右边
        arr[j] = arr[i];
    }

    // 将基准元素放到正确的位置
    arr[i] = pivot;

    // 对基准元素左边的元素进行快速排序
    QuickSort(arr, left, i - 1);

    // 对基准元素右边的元素进行快速排序
    QuickSort(arr, i + 1, right);
}