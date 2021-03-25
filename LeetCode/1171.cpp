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
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        map<int, ListNode *> map;
        ListNode *dummyHead = new ListNode(0, head);
        int sum = 0;
        //dummyHead必须需从0开始，应对[1,-1]的情况
        for (ListNode *node = dummyHead; node != nullptr; node = node->next)
        {
            sum += node->val;
            map[sum] = node->next;
        }

        sum = 0;
        for (ListNode *node = dummyHead; node != nullptr; node = node->next)
        {
            sum += node->val;
            node->next = map[sum];
        }

        return dummyHead->next;
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
    int ia[] = {1, 2, 3, -3, 4};
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
    head = obj.removeZeroSumSublists(head);
    while (head)
    {
        cout << head->val;
        head = head->next;
    }
    delete p;
    delete head;
    return 0;
}
