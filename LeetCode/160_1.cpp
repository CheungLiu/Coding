#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
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
    int getLength(ListNode *head)
    {
        int count = 0;
        while (head)
        {
            ++count;
            head = head->next;
        }
        return count;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int lengthA = getLength(headA);
        int lengthB = getLength(headB);
        int diff = lengthA - lengthB;
        if (diff < 0)
        {
            ListNode *tmp = headB;
            headB = headA;
            headA = tmp;
        }

        while (diff < 0)
        {
            headA = headA->next;
            ++diff;
        }
        while (nullptr != headA && nullptr != headB)
        {
            if (headA == headB)
            {
                return headB;
            }
        }
        return nullptr;
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
