// Problem number: 445
#include <stack>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *res = nullptr;

        stack<int> s1, s2;
        int carry = 0;
        while (l1)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }
        while (!s1.empty() || !s2.empty())
        {
            int sum = 0;
            if (!s1.empty())
            {
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty())
            {
                sum += s2.top();
                s2.pop();
            }
            sum += carry;
            carry = sum / 10;
            sum = sum % 10;
            ListNode *temp = new ListNode(sum);
            temp->next = res;
            res = temp;
        }
        return carry ? new ListNode(carry, res) : res;
    }
};