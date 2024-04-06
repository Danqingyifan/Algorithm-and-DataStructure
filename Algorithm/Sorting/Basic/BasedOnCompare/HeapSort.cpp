#include <vector>
#include <algorithm>
// 堆排序函数
void HeapSort(std::vector<int> &arr)
{
    int n = arr.size();

    // 从最后一个非叶子节点开始，从下至上，从右至左调整结构
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // 从堆中取出最大元素放到末尾，然后调整堆结构
    for (int i = n - 1; i >= 0; i--)
    {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// 堆调整函数，用于调整堆结构
void heapify(std::vector<int> &arr, int n, int i)
{
    int largest = i;       // 初始化最大元素的索引为根节点
    int left = 2 * i + 1;  // 左孩子的索引
    int right = 2 * i + 2; // 右孩子的索引

    // 如果左孩子存在且大于当前最大元素，更新最大元素的索引
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // 如果右孩子存在且大于当前最大元素，更新最大元素的索引
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // 如果最大元素的索引不是根节点，将最大元素与根节点交换，并对影响到的子树进行调整
    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}