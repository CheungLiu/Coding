#include <iostream>
#include "Utilities/BinaryTree.h"

using namespace std;

const BinaryTreeNode *KthNodeCore(const BinaryTreeNode *pRoot, unsigned int &k)
{
    const BinaryTreeNode *target = nullptr;
    if (pRoot->m_pLeft != nullptr)
    {
        target = KthNodeCore(pRoot->m_pLeft, k);
    }
    if (target == nullptr)
    {
        if (k == 1)
            target = pRoot;

        k--;
    }
    if (target == nullptr && pRoot->m_pRight != nullptr)
        target = KthNodeCore(pRoot->m_pRight, k);

    return target;
}

const BinaryTreeNode *KthNode(const BinaryTreeNode *pRoot, unsigned int &k)
{
    if (pRoot == nullptr || k == 0)
    {
        return nullptr;
    }
    return KthNodeCore(pRoot, k);
}

// ====================测试代码====================
void Test(const char *testName, const BinaryTreeNode *pRoot, unsigned int k, bool isNull, int expected)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    const BinaryTreeNode *pTarget = KthNode(pRoot, k);
    if ((isNull && pTarget == nullptr) || (!isNull && pTarget->m_nValue == expected))
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

BinaryTreeNode *CreateBinaryTreeNode(int value)
{
    BinaryTreeNode *pNode = new BinaryTreeNode();
    pNode->m_nValue = value;
    pNode->m_pLeft = nullptr;
    pNode->m_pRight = nullptr;

    return pNode;
}

void ConnectTreeNodes(BinaryTreeNode *pParent, BinaryTreeNode *pLeft, BinaryTreeNode *pRight)
{
    if (pParent != nullptr)
    {
        pParent->m_pLeft = pLeft;
        pParent->m_pRight = pRight;
    }
}

void DestroyTree(BinaryTreeNode *pRoot)
{
    if (pRoot != nullptr)
    {
        BinaryTreeNode *pLeft = pRoot->m_pLeft;
        BinaryTreeNode *pRight = pRoot->m_pRight;

        delete pRoot;
        pRoot = nullptr;

        DestroyTree(pLeft);
        DestroyTree(pRight);
    }
}

//            8
//        6      10
//       5 7    9  11
void TestA()
{
    BinaryTreeNode *pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode *pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode *pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode *pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode *pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode *pNode9 = CreateBinaryTreeNode(9);
    BinaryTreeNode *pNode11 = CreateBinaryTreeNode(11);

    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);

    Test("TestA0", pNode8, 0, true, -1);
    Test("TestA1", pNode8, 1, false, 5);
    Test("TestA2", pNode8, 2, false, 6);
    Test("TestA3", pNode8, 3, false, 7);
    Test("TestA4", pNode8, 4, false, 8);
    Test("TestA5", pNode8, 5, false, 9);
    Test("TestA6", pNode8, 6, false, 10);
    Test("TestA7", pNode8, 7, false, 11);
    Test("TestA8", pNode8, 8, true, -1);

    DestroyTree(pNode8);

    printf("\n\n");
}

int main(int argc, char *argv[])
{
    TestA();
    // TestB();
    // TestC();
    // TestD();
    // TestE();
    return 0;
}
