#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
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
    pair<ListNode *, ListNode *> myReverse(ListNode *head, ListNode *tail)
    {
        ListNode *prev = tail->next, *p = head, *next = nullptr;
        while (prev != tail)
        {
            next = p->next;
            p->next = prev;
            prev = p;
            p = next;
        }
        return {tail, head};
    }

    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        ListNode *hair = new ListNode(-1, head);
        ListNode *pre = hair, *tail = nullptr;

        for (int i = 0; i < m - 1; ++i)
        {
            pre = pre->next;
        }
        head = pre->next;
        tail = head;
        for (int i = 0; i < n - m; ++i)
        {
            tail = tail->next;
        }

        ListNode *next = tail->next;
        pair<ListNode *, ListNode *> result = myReverse(head, tail);
        head = result.first;
        tail = result.second;
        tail->next = next;
        pre->next = head;
        pre = tail;
        head = tail->next;

        return hair->next;
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
    head = obj.reverseBetween(head, 2, 4);
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
