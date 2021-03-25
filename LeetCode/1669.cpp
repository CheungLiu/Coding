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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        auto end2 = list2;
        while (end2->next)
            end2 = end2->next;
        auto pre = list1;
        auto cur = list1->next;
        int count = 1;
        while (count <= b)
        {
            if (count == a)
                pre->next = list2;
            if (count > a)
                delete (pre);
            pre = cur;
            cur = cur->next;
            count++;
        }
        end2->next = cur;
        pre->next = nullptr;
        return list1;
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
    ListNode *p = head;
    for (vector<int>::const_iterator iter = iv.begin(); iter != iv.end(); iter++)
    {
        auto tmp = new ListNode(*iter);
        p->next = tmp;
        p = p->next;
    }
    p = head;
    head = head->next;
    // head = obj.reverseKGroup(head, 1);
    while (head)
    {
        cout << head->val;
        head = head->next;
    }
    delete p;
    delete head;
    return 0;
}
