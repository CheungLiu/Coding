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

//error
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

        int length = getLength(head);
        //不能用指针来代替答案中的结点，必须新建结点的->next指向第一个结点
        //因为如果删除第一个结点的时候，会导致失败
        ListNode *p = head;
        for (int i = 0; i < length - n - 1; i++)
        {
            p = p->next;
        }
        p->next = p->next->next;
        //指针不能用delet
        // delete p;
        return head;
    }
};

int main(int argc, char **argv)
{
    Solution obj = Solution();
    cout << "1+3" << endl;

    return 0;
}
