#include <iostream>
#include <stack>
#include "./Utilities/BinaryTree.h"

void MirrorRecursively(BinaryTreeNode *pNode)
{
    if ((pNode == nullptr) || (pNode->m_pLeft == nullptr && pNode->m_pRight))
        return;

    BinaryTreeNode *pTemp = pNode->m_pLeft;
    pNode->m_pLeft = pNode->m_pRight;
    pNode->m_pRight = pTemp;

    if (pNode->m_pLeft)
        MirrorRecursively(pNode->m_pLeft);

    if (pNode->m_pRight)
        MirrorRecursively(pNode->m_pRight);
}

void MirrorIteratively(BinaryTreeNode *pRoot)
{
    if (pRoot == nullptr)
        return;

    std::stack<BinaryTreeNode *> stackTreeNode;
    stackTreeNode.push(pRoot);

    while (stackTreeNode.size() > 0)
    {
        BinaryTreeNode *pNode = stackTreeNode.top();
        stackTreeNode.pop();

        BinaryTreeNode *pTemp = pNode->m_pLeft;
        pNode->m_pLeft = pNode->m_pRight;
        pNode->m_pRight = pTemp;

        if (pNode->m_pLeft)
            stackTreeNode.push(pNode->m_pLeft);

        if (pNode->m_pRight)
            stackTreeNode.push(pNode->m_pRight);
    }
}

int main(int argc, char *argv[])
{

    return 0;
}
