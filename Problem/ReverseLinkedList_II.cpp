// Problem number: 92
struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
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
        ListNode *cur = preBetween->next;
        ListNode *next = cur->next;
        for (int i = 0; i < n - m; i++)
        {
        }
    }
};