### 剑指Offer

#### 面试题3（一）：找出数组中重复的数字

```c++
int duplicate(int numbers[], int length, int *duplication)
{
    if (numbers == nullptr || length <= 0)
        return -1;
    for (int i = 0; i < length; ++i)
    {
        while (numbers[i] != i)
        {
            if (numbers[i] == numbers[numbers[i]])
            {
                return numbers[i];
            }
            int temp = numbers[i];
            numbers[i] = numbers[temp];
            numbers[temp] = temp;
        }
    }
    return -1;
}
```

#### 面试题3（二）：不修改数组找出重复的数字

```c++
int getDuplication(const int *numbers, int length)
{
    if (numbers == nullptr || length <= 0)
        return -1;

    int start = 1;
    int end = length - 1;
    while (end >= start)
    {
        int middle = ((end - start) >> 1) + start;
        int count = countRange(numbers, length, start, middle);
        if (end == start)
        {
            if (count > 1)
                return start;
            else
                break;
        }

        if (count > (middle - start + 1))
            end = middle;
        else
            start = middle + 1;
    }
    return -1;
}
int countRange(const int *numbers, int length, int start, int end)
{
    if (numbers == nullptr)
        return 0;

    int count = 0;
    for (int i = 0; i < length; i++)
        if (numbers[i] >= start && numbers[i] <= end)
            ++count;
    return count;
}
```

#### 面试题6：从尾到头打印链表

```c++
void PrintListReversingly_Iteratively(ListNode *pHead)
{
    std::stack<ListNode *> nodes;

    ListNode *pNode = pHead;
    while (pNode != nullptr)
    {
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }
    while (!nodes.empty())
    {
        pNode = nodes.top();
        printf("%d\t", pNode->m_nValue);
        nodes.pop();
    }
}

void PrintListReversingly_Recursively(ListNode *pHead)
{
    if (pHead != nullptr)
    {
        if (pHead->m_pNext != nullptr)
        {
            PrintListReversingly_Recursively(pHead->m_pNext);
        }
        printf("%d\t", pHead->m_nValue);
    }
}
```

#### 面试题8：二叉树的下一个结点

```c++
BinaryTreeNode *GetNext(BinaryTreeNode *pNode)
{
    if (pNode == nullptr)
        return nullptr;

    BinaryTreeNode *pNext = nullptr;
    if (pNode->m_pRight != nullptr)
    {
        BinaryTreeNode *pRight = pNode->m_pRight;
        while (pRight->m_pLeft != nullptr)
            pRight = pRight->m_pLeft;

        pNext = pRight;
    }
    else if (pNode->m_pParent != nullptr)
    {
        BinaryTreeNode *pCurrent = pNode;
        BinaryTreeNode *pParent = pNode->m_pParent;
        while (pParent != nullptr && pCurrent == pParent->m_pRight)
        {
            pCurrent = pParent;
            pParent = pParent->m_pParent;
        }

        pNext = pParent;
    }
    return pNext;
}
```

#### 面试题9：用两个栈实现队列

```c++
template <typename T>
class CQueue
{
private:
    stack<T> stack1;
    stack<T> stack2;

public:
    CQueue(void);
    ~CQueue(void);

    void appendTail(const T &node);
    T deleteHead();
};
template <typename T>
CQueue<T>::CQueue(/* args */)
{
}
template <typename T>
CQueue<T>::~CQueue()
{
}
template <typename T>
void CQueue<T>::appendTail(const T &element)
{
    stack1.push(element);
}
template <typename T>
T CQueue<T>::deleteHead()
{
    if (stack2.size() <= 0)
    {
        while (stack1.size() > 0)
        {
            T &data = stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }

    if (stack2.size() == 0)
        throw new exception("queue is empty");

    T head = stack2.top();
    stack2.pop();
    return head;
}
```

