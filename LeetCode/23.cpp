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
    ListNode *mergeTwoLists(ListNode *a, ListNode *b)
    {
        if ((!a) || (!b))
        {
            return a ? a : b;
        }
        ListNode *aPtr = a, *bPtr = b, head, *tail = &head;
        while (aPtr && bPtr)
        {
            if (aPtr->val < bPtr->val)
            {
                tail->next = aPtr;
                aPtr = aPtr->next;
            }
            else
            {
                tail->next = bPtr;
                bPtr = bPtr->next;
            }
            tail = tail->next;
        }
        tail->next = (aPtr ? aPtr : bPtr);
        //head本身是一个结点，而不是指针？
        //所以不能head->next?
        return head.next;
    }

    ListNode *merge(vector<ListNode *> &lists, int l, int r)
    {
        if (l == r)
        {
            return lists[l];
        }
        if (l > r)
        {
            return nullptr;
        }
        int mid = (r + l) / 2;
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        return merge(lists, 0, lists.size() - 1);
    }
};

int main(int argc, char **argv)
{
    Solution obj = Solution();
    cout << "1+3" << endl;

    return 0;
}
