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
    ListNode *frontPointer, *nextNode;
    // ListNode *dummyHead;
    bool flag = false;

public:
    void recursivelyConnect(ListNode *currentNode)
    {
        if (currentNode != nullptr)
        {
            recursivelyConnect(currentNode->next);
            if (flag)
            {
                return;
            }

            currentNode->next = nextNode;
            frontPointer->next = currentNode;
            frontPointer = nextNode;
            nextNode = nextNode->next;

            if (nextNode->next == frontPointer)
            {
                frontPointer->next = nullptr;
                flag = true;
            }
        }
        return;
    }

    void reorderList(ListNode *head)
    {
        if ((!head) or (!head->next) or (!head->next->next))
        {
            return;
        }
        // dummyHead = head;
        frontPointer = head;
        nextNode = frontPointer->next;
        recursivelyConnect(head);
        return;
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
    obj.reorderList(head);
    while (head)
    {
        cout << head->val;
        head = head->next;
    }
    delete p;
    delete head;
    return 0;
}
