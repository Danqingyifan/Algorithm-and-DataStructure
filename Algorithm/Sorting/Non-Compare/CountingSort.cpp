#include <vector>
#include <algorithm>

void CountingSort(std::vector<int> &arr)
{
    int max = *std::max_element(arr.begin(), arr.end()); // 找到数组中的最大值
    int min = *std::min_element(arr.begin(), arr.end()); // 找到数组中的最小值
    int range = max - min + 1;                           // 计算范围

    std::vector<int> count(range), output(arr.size());
    for (int i = 0; i < arr.size(); i++)
        count[arr[i] - min]++; // 计算每个元素的出现次数

    for (int i = 1; i < count.size(); i++)
        count[i] += count[i - 1]; // 计算每个元素的正确位置

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--; // 更新计数数组
    }

    for (int i = 0; i < arr.size(); i++)
        arr[i] = output[i]; // 将排序结果复制回原数组
}

//计数排序只适用于非负整数，并且最大值和最小值的差不能太大。