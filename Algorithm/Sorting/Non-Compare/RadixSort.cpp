#include <vector>
#include <algorithm>
#include <cmath>
// 获取x的第d位数字
int getDigit(int x, int d)
{
    return (x / static_cast<int>(std::pow(10, d - 1))) % 10;
}

// 基数排序函数
void radixSort(std::vector<int> &arr)
{
    int max = *std::max_element(arr.begin(), arr.end()); // 找到数组中的最大值
    int digits = 0;                                      // 计算最大值的位数
    while (max)
    {
        max /= 10;
        digits++;
    }

    std::vector<std::vector<int>> buckets(10); // 创建10个桶，对应0-9的每一位数字

    // 从最低位开始，对每一位进行排序
    for (int i = 1; i <= digits; i++)
    {
        // 将每个元素放到对应的桶中
        for (int num : arr)
        {
            int digit = getDigit(num, i);
            buckets[digit].push_back(num);
        }

        // 清空原数组，然后将桶中的元素按顺序放回原数组
        arr.clear();
        for (auto &bucket : buckets)
        {
            for (int num : bucket)
            {
                arr.push_back(num);
            }
            bucket.clear();
        }
    }
}