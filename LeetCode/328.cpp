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
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr)
        {
            return head;
        }

        ListNode *evenHead = head->next;
        ListNode *odd = head;
        ListNode *even = evenHead;
        while (even != nullptr && even->next != nullptr)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
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
    // head = obj.reverseKGroup(head, 1);
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
