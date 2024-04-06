#include <vector>
#include <algorithm>
#include <iterator>

// 桶排序函数
void BucketSort(std::vector<float> &arr)
{
    int n = arr.size();
    if (n <= 0)
        return;

    // 1. 创建 n 个空桶
    std::vector<std::vector<float>> buckets(n);

    // 2. 把 arr[i] 插入到一个适合的桶中
    for (int i = 0; i < n; i++)
    {
        int bucketIndex = n * arr[i]; // 桶的索引
        buckets[bucketIndex].push_back(arr[i]);
    }

    // 3. 对每个桶进行排序
    for (int i = 0; i < n; i++)
    {
        std::sort(buckets[i].begin(), buckets[i].end());
    }

    // 4. 把桶中的元素一次取出来，放回原数组
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < buckets[i].size(); j++)
        {
            arr[index++] = buckets[i][j];
        }
    }
}