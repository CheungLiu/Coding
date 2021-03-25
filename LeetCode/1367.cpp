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
    bool dfs(TreeNode *rt, ListNode *head)
    {
        if (head == nullptr)
        {
            return true;
        }
        if (rt == nullptr)
        {
            return false;
        }
        if (rt->val != head->val)
        {
            return false;
        }
        return dfs(rt->left, head->next) || dfs(rt->right, head->next);
    }

    bool isSubPath(ListNode *head, TreeNode *root)
    {
        if (root == nullptr)
        {
            return false;
        }
        return dfs(root, head) || isSubPath(head, root->left) || isSubPath(head, root->right);
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
