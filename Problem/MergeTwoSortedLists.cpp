// Problem Number: 21
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *dummyHead = new ListNode(0);
        ListNode *curr = dummyHead;

        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val < list2->val)
            {
                curr->next = list1;
                list1 = list1->next;
            }
            else
            {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

        if (list1 != nullptr)
        {
            curr->next = list1;
        }
        else
        {
            curr->next = list2;
        }

        return dummyHead->next;
    }
};