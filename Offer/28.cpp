#include <iostream>
#include "BinaryTree.h"
using namespace std;

bool isSymmetrical(BinaryTreeNode *pNode)
{
    return isSymmetrical(pNode, pNode);
}

bool isSymmetrical(BinaryTreeNode *pNode1, BinaryTreeNode *pNode2)
{
    if (pNode1 == nullptr && pNode2 == nullptr)
    {
        return true;
    }
    if (pNode1 == nullptr || pNode2 == nullptr)
    {
        return false;
    }
    if (pNode1->m_nValue != pNode2->m_nValue)
    {
        return false;
    }

    return isSymmetrical(pNode1->m_pLeft, pNode2->m_pRight) && isSymmetrical(pNode1->m_pRight, pNode2->m_pLeft);
}

int main()
{
    int array[] = {49, 38, 65, 97, 23, 22, 76, 1, 5, 8, 2, 0, -1, 22};
    return 0;
}