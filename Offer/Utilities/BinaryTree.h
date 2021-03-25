/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

#pragma once

struct BinaryTreeNode
{

    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;

    BinaryTreeNode(int m = 0, BinaryTreeNode *l = nullptr, BinaryTreeNode *r = nullptr)
    {
        m_nValue = m;
        m_pLeft = l;
        m_pRight = r;
    }
};

BinaryTreeNode *CreateBinaryTreeNode(int value);
void ConnectTreeNodes(BinaryTreeNode *pParent, BinaryTreeNode *pLeft, BinaryTreeNode *pRight);
void PrintTreeNode(const BinaryTreeNode *pNode);
void PrintTree(const BinaryTreeNode *pRoot);
void DestroyTree(BinaryTreeNode *pRoot);
// __declspec(dllexport) 