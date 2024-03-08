struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类
     * @param m int整型
     * @param n int整型
     * @return ListNode类
     */
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        // write code here
        if (m > n)
            return nullptr;

        if (m == n)
            return head;

        ListNode *temp = new ListNode(0);
        temp->next = head;
        ListNode *preBetween = temp;
        for (int i = 0; i < m - 1; i++)
        {
            preBetween = preBetween->next;
        }
        ListNode* cur = preBetween->next;
        ListNode* next = cur->next;
        for (int i = 0; i < n - m; i++)
        {
            
        }
    }
};