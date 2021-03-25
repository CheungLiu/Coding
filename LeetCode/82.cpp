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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }

        ListNode *p = head;
        int length = getLength(head);
        map<int, int> m;
        while (p)
        {
            if ((m.find(p->val)) == m.end())
            {
                m.insert(pair<int, int>(p->val, 1));
            }
            else
            {
                ++(m[p->val]);
            }
            p = p->next;
        }

        ListNode *hair = new ListNode(-1, head);
        p = hair;
        while (p)
        {
            if (!p->next)
            {
                return hair->next;
            }

            if (m[p->next->val] == 1)
            {
                p = p->next;
            }
            else
            {
                p->next = p->next->next;
            }
        }
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
    int ia[] = {1, 1, 1, 2, 3};
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
    head = obj.deleteDuplicates(head);
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
