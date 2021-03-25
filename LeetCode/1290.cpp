#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
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

// class Solution
// {
//     int count = 0;
//     int sum = 0;

// public:
//     int getDecimalValue(ListNode *head)
//     {
//         if (!head)
//         {
//             return 0;
//         }

//         int tmp = getDecimalValue(head->next);
//         sum = head->val * pow(2, count) + tmp;
//         ++count;
//         return sum;
//     }
// };

class Solution
{
public:
    int getDecimalValue(ListNode *head)
    {
        ListNode *cur = head;
        int ans = 0;
        while (cur != nullptr)
        {
            ans = ans * 2 + cur->val;
            cur = cur->next;
        }
        return ans;
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

    cout << "Test!" << pow(2, 3) << endl;
    int ia[] = {1, 0, 1};
    vector<int> iv(ia, ia + 3);
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
    cout << obj.getDecimalValue(head) << endl;
    while (head)
    {
        cout << head->val;
        head = head->next;
    }
    delete p;
    delete head;
    return 0;
}
