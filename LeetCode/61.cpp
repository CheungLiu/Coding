#include <iostream>
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
    int getLength(ListNode *head)
    {
        int n = 0;
        while (head)
        {
            head = head->next;
            n++;
        }
        return n;
    }
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head)
        {
            return head;
        }
        int length = getLength(head);
        k = k % length;
        if (k == 0)
        {
            return head;
        }
        ListNode *p = head;
        while (p->next)
        {
            p = p->next;
        }
        p->next = head;
        for (int i = 0; i < length - k - 1; i++)
        {
            head = head->next;
        }
        p = head;
        head = head->next;
        p->next = nullptr;
        return head;
    }
};
template <typename T>
class print
{
public:
    void operator()(const T &elem)
    {
        cout << elem << ' ';
    }
};
int main(int argc, char **argv)
{
    cout << "Test!" << endl;
    int ia[] = {1, 2, 3, 4, 5};
    vector<int> iv(ia, ia + 5);
    for_each(iv.begin(), iv.end(), print<int>());

    Solution obj = Solution();
    ListNode *head = new ListNode(-1);
    ListNode *p = head, *tmp = nullptr;
    for (vector<int>::const_iterator iter = iv.begin(); iter != iv.end(); iter++)
    {
        tmp = new ListNode(*iter);
        head->next = tmp;
        head = head->next;
    }

    head = p->next;
    head = obj.rotateRight(head, 2);
    p = head;
    while (head)
    {
        cout << head->val;
        head = head->next;
    }
    delete p;
    delete head;
    return 0;
}
