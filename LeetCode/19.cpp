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
        int length = 0;
        while (head)
        {
            ++length;
            head = head->next;
        }
        return length;
    }
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        //题目中给的链接结构是：
        //head（指针）指向的是链表的第一个结点(也就是1)，

        //dummy是指向head
        //dummy->next是head指针
        ListNode *dummy = new ListNode(0, head);
        int length = getLength(head);
        ListNode *cur = dummy;
        for (int i = 1; i < length - n + 1; ++i)
        {
            cur = cur->next;
        }
        cur->next = cur->next->next;
        //head（指针）指向的是链表的第一个结点(也就是1)，
        ListNode *ans = dummy->next;
        //刪除的是结点，返回的是指针。
        delete dummy;
        return ans;
    }
};

int main(int argc, char **argv)
{
    Solution obj = Solution();
    cout << "1+3" << endl;

    return 0;
}
