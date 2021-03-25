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
    int getLength(ListNode *head)
    {
        int n = 0;
        while (head)
        {
            n++;
            head = head->next;
        }
        return n;
    }
    void swap(ListNode *pre, ListNode *p)
    {
        pre->next = p->next;
        p->next = pre->next->next;
        pre->next->next = p;
    }

    ListNode *swapPairs(ListNode *head)
    {
        int n = getLength(head);
        if (n < 2)
        {
            return head;
        }
        ListNode *preHead = new ListNode(-1, head);

        ListNode *p = head, *pre = preHead;
        for (int i = 0; i < n / 2; i++)
        {
            swap(pre, p);
            pre = p;
            p = p->next;
        }
        return preHead->next;
    }
};

int main(int argc, char **argv)
{
    cout << "Test!" << endl;
    Solution obj = Solution();
    ListNode *head = new ListNode(-1);
    ListNode *p = head;
    int in = 0;
    cin >> in;
    //只有0才会退出
    while (in)
    {
        ListNode *tmp = new ListNode(in);
        p->next = tmp;
        p = p->next;
        cin >> in;
    }
    cout << endl;

    p = head->next;
    delete head;

    p = obj.swapPairs(p);
    while (p)
    {
        cout << p->val;
        p = p->next;
    }
    cout << endl;
    return 0;
}
