#include <iostream>
#include <vector>
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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int length = lists.size();
        if (length == 0 || (length == 0 && !lists[0]))
        {
            return nullptr;
        }
        for (int i = 1; i < length; i++)
        {
            lists[0] = merge(lists[0], lists[i]);
        }
        return lists[0];
    }

    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
        {
            return l2;
        }
        if (l2 == nullptr)
        {
            return l1;
        }
        ListNode *p = l1, *q = l2, *temp;
        if (p->val > q->val)
        {
            temp = q;
            q = p;
            p = temp;
            l1 = p, l2 = q;
        }

        while (p->next && q)
        {
            if (p->next->val <= q->val)
            {
                p = p->next;
            }
            else
            {
                ListNode *dummy = new ListNode(q->val, p->next);
                p->next = dummy;
                p = p->next;
                q = q->next;
            }
        }
        if (!p->next)
        {
            //如果p跑完的话，就一定是最后一个结点
            p->next = q;
        }
        return l1;
    }
};

int main(int argc, char **argv)
{
    Solution obj = Solution();
    cout << "1+3" << endl;

    return 0;
}
