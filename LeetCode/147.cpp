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
    ListNode *insertionSortList(ListNode *head)
    {
        if (head == nullptr)
        {
            return head;
        }

        ListNode *dummyNode = new ListNode(0, head);
        ListNode *lastSorted = head;
        ListNode *currentNode = lastSorted->next;
        while (currentNode != nullptr)
        {
            if (lastSorted->val <= currentNode->val)
            {
                lastSorted = lastSorted->next;
            }
            else
            {
                ListNode *pre = dummyNode;
                while (pre->next->val <= currentNode->val)
                {
                    pre = pre->next;
                }
                lastSorted->next = currentNode->next;
                currentNode->next = pre->next;
                pre->next = currentNode;
            }
            currentNode = lastSorted->next;
        }
        return dummyNode->next;
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
