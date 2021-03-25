#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
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

template <typename T>
class print
{
public:
    void operator()(const T &elem)
    {
        cout << elem << ' ';
    }
};

class Solution
{
public:
    vector<int> nextLargerNodes(ListNode *head)
    {
        vector<int> arr;
        // fill(head, arr);
        while (head)
        {
            arr.emplace_back(head->val);
            head = head->next;
        }
        const int n = arr.size();
        vector<int> ans(n, 0);
        stack<int> stk;
        for (int i = 0; i < n; ++i)
        {
            while (not stk.empty() and arr[stk.top()] < arr[i])
            {
                ans[stk.top()] = arr[i];
                stk.pop();
            }
            stk.emplace(i);
        }
        return ans;
    }

    // private:
    //     void fill(ListNode *head, vector<int> &arr)
    //     {
    //         // recursion exit condition
    //         if (!head)
    //             return;
    //         arr.emplace_back(head->val);
    //         fill(head->next, arr);
    //     }
};

int main(int argc, char **argv)
{
    cout << "Test!" << endl;
    int ia[] = {2, 7, 4, 3, 5};
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
    obj.nextLargerNodes(head);
    // while (head)
    // {
    //     cout << head->val;
    //     head = head->next;
    // }
    delete p;
    delete head;
    return 0;
}
