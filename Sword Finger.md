[TOC]

#### 面试题27：二叉树的镜像

```c++
void MirrorRecursively(BinaryTreeNode *pNode)
{
    if((pNode == nullptr) || (pNode->m_pLeft == nullptr && pNode->m_pRight))
        return;
    BinaryTreeNode *pTemp = pNode->m_pLeft;
    pNode->m_pLeft = pNode->m_pRight;
    pNode->m_pRight = pTemp;
    if(pNode->m_pLeft)
        MirrorRecursively(pNode->m_pLeft);  
    if(pNode->m_pRight)
        MirrorRecursively(pNode->m_pRight); 
}
```

#### 面试题28：对称的二叉树

```c++
bool isSymmetrical(BinaryTreeNode* pRoot)
{
    return isSymmetrical(pRoot, pRoot);
}
bool isSymmetrical(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
    if(pRoot1 == nullptr && pRoot2 == nullptr)
        return true;
    if(pRoot1 == nullptr || pRoot2 == nullptr)
        return false;
    if(pRoot1->m_nValue != pRoot2->m_nValue)
        return false;
    return isSymmetrical(pRoot1->m_pLeft, pRoot2->m_pRight)
        && isSymmetrical(pRoot1->m_pRight, pRoot2->m_pLeft);
}
```

#### 面试题30：包含min函数的栈

```c++
#include <stack>
template <typename T>
class StackWithMin
{
public:
    StackWithMin() {}
    virtual ~StackWithMin() {}
    T &top();
    const T &top() const;
    void push(const T &value);
    void pop();
    const T &min() const;
    bool empty() const;
    size_t size() const;

private:
    std::stack<T> m_data;
    std::stack<T> m_min;
};

template <typename T>
void StackWithMin<T>::push(const T &value)
{
    m_data.push(value);
    if (m_min.size() == 0 || value < m_min.top())
    {
        m_min.push(value);
    }
    else
    {
        m_min.push(m_min.top());
    }
}

template <typename T>
void StackWithMin<T>::pop()
{
    m_data.pop();
    m_min.pop();
}

template <typename T>
const T &StackWithMin<T>::min() const
{
    return m_min.top();
}

template <typename T>
const T &StackWithMin<T>::top() const
{
    return m_data.top();
}

template <typename T>
T &StackWithMin<T>::top()
{
    return m_data.top();
}

template <typename T>
bool StackWithMin<T>::empty() const
{
    return m_data.empty();
}

template <typename T>
size_t StackWithMin<T>::size() const
{
    return m_data.size();
}
```

```c++
int main(int argc, char* argv[])
{
    StackWithMin<int> stack;
    stack.push(3);
    Test("Test1", stack, 3);
    stack.push(4);
    Test("Test2", stack, 3);
    stack.push(2);
    Test("Test3", stack, 2);
    stack.push(3);
    Test("Test4", stack, 2);
    stack.pop();
    Test("Test5", stack, 2);
    stack.pop();
    Test("Test6", stack, 3);
    stack.pop();
    Test("Test7", stack, 3);
    stack.push(0);
    Test("Test8", stack, 0);
    return 0;
}
```

#### 面试题32（一）：不分行从上往下打印二叉树

```c++
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
```

#### 面试题32（二）：分行从上到下打印二叉树

```c++
void Print(BinaryTreeNode *pRoot)
{
    if (!pRoot)
    {
        return;
    }
    deque<BinaryTreeNode *> dequeTreeNode;
    dequeTreeNode.push_back(pRoot);
    int nextLevel = 0;
    int toBePrint = 1;
    while (dequeTreeNode.size())
    {
        BinaryTreeNode *pNode = dequeTreeNode.front();
        printf("%d ", pNode->m_nValue);
        dequeTreeNode.pop_front();
        if (pNode->m_pLeft)
        {
            dequeTreeNode.push_back(pNode->m_pLeft);
            ++nextLevel;
        }
        if (pNode->m_pRight)
        {
            dequeTreeNode.push_back(pNode->m_pRight);
            ++nextLevel;
        }
        --toBePrint;
        if (toBePrint==0)
        {
            printf("\n");
            toBePrint = nextLevel;
            nextLevel = 0;
        }
    }
}
```

#### 面试题32（三）：之字形打印二叉树

```c++
void Print(BinaryTreeNode *pRoot)
{
    if (pRoot == nullptr)
        return;
    std::stack<BinaryTreeNode *> levels[2];
    int current = 0;
    int next = 1;
    levels[current].push(pRoot);
    while (!levels[0].empty() || !levels[1].empty())
    {
        BinaryTreeNode *pNode = levels[current].top();
        levels[current].pop();
        printf("%d ", pNode->m_nValue);
        if (current == 0)
        {
            if (pNode->m_pLeft != nullptr)
                levels[next].push(pNode->m_pLeft);
            if (pNode->m_pRight != nullptr)
                levels[next].push(pNode->m_pRight);
        }
        else
        {
            if (pNode->m_pRight != nullptr)
                levels[next].push(pNode->m_pRight);
            if (pNode->m_pLeft != nullptr)
                levels[next].push(pNode->m_pLeft);
        }
        if (levels[current].empty())
        {
            printf("\n");
            current = 1 - current;
            next = 1 - next;
        }
    }
}
```

