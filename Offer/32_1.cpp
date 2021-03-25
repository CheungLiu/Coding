#include <iostream>
#include <deque>
#include "./Utilities/BinaryTree.h"
using namespace std;

void PrintFromTopToBottom(BinaryTreeNode *pRoot)
{
    if (!pRoot)
    {
        return;
    }
    deque<BinaryTreeNode *> dequeTreeNode;
    dequeTreeNode.push_back(pRoot);
    while (dequeTreeNode.size())
    {
        BinaryTreeNode *pNode = dequeTreeNode.front();
        dequeTreeNode.pop_front();
        printf("%d ", pNode->m_nValue);
        if (pRoot->m_pLeft)
        {
            dequeTreeNode.push_back(pNode->m_pLeft);
        }
        if (pRoot->m_pRight)
        {
            dequeTreeNode.push_back(pNode->m_pRight);
        }
    }
}