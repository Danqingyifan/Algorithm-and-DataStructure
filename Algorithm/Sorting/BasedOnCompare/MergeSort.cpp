#include <vector>
#include <algorithm>
//帮我写一个归并排序
void MergeSort(std::vector<int> &arr)
{
    //如果数组长度小于2，直接返回
    if (arr.size() < 2)
        return;

    //计算中间位置
    int mid = arr.size() / 2;

    //将数组分为两部分
    std::vector<int> left(arr.begin(), arr.begin() + mid);
    std::vector<int> right(arr.begin() + mid, arr.end());

    //递归调用归并排序
    MergeSort(left);
    MergeSort(right);

    //合并两个有序数组
    int i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
    }
    while (i < left.size())
    {
        arr[k++] = left[i++];
    }
    while (j < right.size())
    {
        arr[k++] = right[j++];
    }
}