
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
    ListNode *frontPointer;
    int flag = 0;

public:
    bool recursivelyCheck(ListNode *currentNode)
    {
        if (currentNode != nullptr)
        {
            if (!recursivelyCheck(currentNode->next))
            {
                return false;
            }
            if (flag)
            {
                return true;
            }

            if (currentNode->val != frontPointer->val)
            {
                return false;
            }
            if ((frontPointer == currentNode) or (frontPointer->next == currentNode))
            {
                flag = 1;
                return true;
            }
            frontPointer = frontPointer->next;
        }
        return true;
    }

    bool isPalindrome(ListNode *head)
    {
        frontPointer = head;
        return recursivelyCheck(head);
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
    int ia[] = {0, 0};
    vector<int> iv(ia, ia + 2);
    for_each(iv.begin(), iv.end(), print<int>());

    Solution obj = Solution();
    ListNode *head = new ListNode(-1);
    ListNode *p = head;
    for (vector<int>::const_iterator iter = iv.begin(); iter != iv.end(); ++iter)
    {
        auto tmp = new ListNode(*iter);
        p->next = tmp;
        p = p->next;
    }

    p = head;
    head = head->next;

    cout << obj.isPalindrome(head) << endl;
    free(head);
    delete p;
    return 0;
}
