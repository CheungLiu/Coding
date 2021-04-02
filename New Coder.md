[TOC]

### 1、大数加法

```c++
string solve(string s, string t)
{
    int lengthstr1 = s.length();
    int lengthstr2 = t.length();
    if (!lengthstr1)
    {
        return t;
    }
    if (!lengthstr2)
    {
        return s;
    }
    int push = 0;
    int i = lengthstr1 - 1;
    int j = lengthstr2 - 1;
    stack<int> sta;
    int num = 0;
    while (i >= 0 && j >= 0)
    {
        num = s[i] + t[j] + push - '0' - '0';
        push = num / 10;
        num = num % 10;
        sta.push(num);
        --i, --j;
    }
    i < 0 ? s = t, i = j : 1;
    while (i >= 0)
    {
        num = s[i] + push - '0';
        push = num / 10;
        num = num % 10;
        sta.emplace(num);
        --i;
    }
    if (push)
    {
        sta.push(push);
    }
    string str;
    while (!sta.empty())
    {
        str += sta.top() + '0';
        sta.pop();
    }
    return str;
}
```

### 3、链表中环的入口节点

```C++
//判断链表中是否有环
bool hasCycle(ListNode *head) {
    if(head==nullptr||head->next==nullptr){
        return false;
    }
    ListNode* slowP=head;
    ListNode* fastP=head;
    while(fastP->next!=nullptr){
        slowP=slowP->next;
        fastP=fastP->next;
        if(fastP->next==nullptr){
            return false;
        }
        fastP=fastP->next;
        if(slowP==fastP){
            return true;
        }
    }
    return false;
}

//不仅判断有环，还要找到入口节点
ListNode *detectCycle(ListNode *head) {
    if(head==nullptr){
        return nullptr;
    }
    ListNode* slowP=head;
    ListNode* fastP=head;
    while(fastP->next!=nullptr){
        slowP=slowP->next;
        fastP=fastP->next;
        if(fastP->next==nullptr){
            return nullptr;
        }
        fastP=fastP->next;
        if(slowP==fastP){
            while(head!=fastP){
                fastP=fastP->next;
                head=head->next;
            }
            return head;
        }
    }
    return nullptr;
}
```

### 7、股票（一次交易）

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=INT_MAX;
        int max_price=0;
        vector<int>::iterator iter=prices.begin();
        for(;iter!=prices.end();++iter){
            //首先找到单调递减的最小值，用min记录现在的最小值，后面每次的更新min的最小值
            if(*iter<min){
                min=*iter;
            }else if(max_price<(*iter-min))
            {
                //因为我们的min后面可能会因为一个更小的值而被更新，所以需要用max_price来记录一个全局最小值
                max_price=*iter-min;
            }
        }
        return max_price;
    }
};
```


### 15、求二叉树的层序遍历
```C++
vector<vector<int> > levelOrder(TreeNode* root) {
        // write code here
        vector<vector<int>> vec;
        if(root==nullptr){
            return vec;
        }
        queue<TreeNode*> que;
        que.emplace(root);
        while(!que.empty()){
            vector<int> vec1;
            int length=que.size();
            while(length--){
                TreeNode *temp=que.front();
                que.pop();
                vec1.emplace_back(temp->val);
                if(temp->left){
                    que.emplace(temp->left);
                }
                if(temp->right){
                    que.emplace(temp->right);
                }
            }
            if(vec1.size()){
                vec.emplace_back(vec1);
            }
        }
        return vec;
    }
```


### 17、最长回文子字串
```C++
int longestPalindromeSubseq(string A)
{
    int n = A.length();
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    // for (int i = 1; i <= n; ++i)
    // {
    //     dp[i][i] = 1;
    // }
    for (int i = n; i >= 1; --i)
    {
        dp[i][i] = 1;
        for (int j = i + 1; j <= n; ++j)
        {
            if (A[i - 1] == A[j - 1])
            {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[1][n];
}
```

### 19、子数组的最大累加和问题

```C++
// 自己的方法
int maxsumofSubarray(vector<int>& arr) {
    // write code here
    int maxSum=0;
    int length=arr.size();
    for(int i=length-1;i>=0;--i){
        if(arr[i]>0){
            break;
        }
        arr[i]=0;
    }
    for(auto item:arr){
        if(item<=0&&(item+maxSum)<=0){
            maxSum=0;
            continue;
        }else{
            maxSum+=item;
        }
    }
    return maxSum;
}

//动态规划
int maxsumofSubarray(vector<int>& arr) {
    // write code here
    int maxSum=arr[0];
    int length=arr.size();
    for(int i=1;i<length;++i){
        arr[i]=max(arr[i],arr[i-1]+arr[i]);
        maxSum=max(arr[i], maxSum);
    }        
    return maxSum;
}
```

### 54、数组中相加和为0的三元组

```C++
//先排序，然后以第一个值为基准开始遍历，用双指针求第二个值和第三个值
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        int length=num.size();
        if(length<3){
            return {};
        }
        sort(num.begin(),num.end());
        vector<vector<int>> vec;
        for(int i=0;i<length-2;i++){
            int j=i+1;
            int k=length-1;
            for(;j<k;){
                int sum = num[i]+num[j]+num[k];
                if(sum>0){
                    --k;
                }else if(sum<0){
                    ++j;
                }else{
                    vector<int> temp={num[i],num[j],num[k]};
                    vec.emplace_back(temp);
                    while(j+1<k&&num[j]==num[j+1])++j;
                    while(j+1<k&&num[k-1]==num[k])--k;
                    ++j,--k;
                }
            }
            while(i<length-2&&num[i]==num[i+1])++i;
        }
        return vec;
    }
};

```

### 33、合并有序链表

```c++
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr&&l2==nullptr){
            return nullptr;
        }
        if(l1==nullptr||l2==nullptr){
            return l1==nullptr?l2:l1;
        }
        ListNode* dummyHead=new ListNode(0);
        ListNode* tail=dummyHead;
        while(l1!=nullptr&&l2!=nullptr){
            if(l1->val<=l2->val){
                tail->next=l1;
                l1=l1->next;
            }else{
                tail->next=l2;
                l2=l2->next;
            }
            tail=tail->next;
        }
        tail->next=l1==nullptr?l2:l1;
        return dummyHead->next;
    }
};
```

### 35、最小编辑代价

```c++
// LeetCode只有最小代价

// D[i][j-1] 为 A 的前 i 个字符和 B 的前 j - 1 个字符编辑距离的子问题。即对于 B 的第 j 个字符，我们在 A 的末
// 尾添加了一个相同的字符，那么 D[i][j] 最小可以为 D[i][j-1] + 1；
int minDistance(string word1, string word2)
{
    int length1 = word1.size();
    int length2 = word2.size();
    if (length1 * length2 == 0)
    {
        return length1 + length2;
    }
    int dp[length1 + 1][length2 + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= length1; ++i)
    {
        dp[i][0] = i;
    }
    for (int j = 1; j <= length2; ++j)
    {
        dp[0][j] = j;
    }
    for (int i = 0; i < length1; ++i)
    {
        for (int j = 0; j < length2; ++j)
        {
            int up = dp[i][j + 1] + 1;
            int left = dp[i + 1][j] + 1;
            int left_up = dp[i][j];
            if (word1[i] != word2[j])
            {
                left_up += 1;
            }
            dp[i + 1][j + 1] = min(left, min(up, left_up));
        }
    }
    return dp[length1][length2];
}

//方法二 newcoder
int minEditCost(string word1, string word2, int ic, int dc, int rc)
{
    int length1 = word1.size();
    int length2 = word2.size();
    if (length1 * length2 == 0)
    {
        return length1 + length2;
    }
    int dp[length1 + 1][length2 + 1];
    memset(dp, 0, sizeof(dp));
    //dp[i][j]表示word1的前i个字符编辑成word2的前j个字符需要的最小操作数
    //dp[i][j]在本方法中是单纯的从i到j
    //就和方法1不一样，方法1还会从j到i的理解
    for (int i = 1; i <= length1; ++i)
    {
        dp[i][0] = i * dc;
    }
    for (int j = 1; j <= length2; ++j)
    {
        dp[0][j] = j * ic;
    }
    for (int i = 0; i < length1; ++i)
    {
        for (int j = 0; j < length2; ++j)
        {

            if (word1[i] == word2[j])
            {
                dp[i + 1][j + 1] = dp[i][j];
            }
            else
            {
                //因为数组是从1开始的，所以dp[i + 1][j]代表的是A的第i个字符到B的第j-1个字符，所以是需要dp[i + 1][j]加上一次插入操作
                int Insert = dp[i + 1][j] + ic;
                int Delete = dp[i][j + 1] + dc;
                int left_up = dp[i][j] + rc;
                dp[i + 1][j + 1] = min(Insert, min(Delete, left_up));
            }
        }
    }
    return dp[length1][length2];
}
```



### 37、合并区间

```c++
#include<algorithm>
bool cmp(Interval  a,Interval  b)
{
    if(a.start==b.start){ return a.end< b.end;}
    return a.start < b.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ans;
        sort(intervals.begin(),intervals.end(),cmp);
        int len = intervals.size();
        if(len==0)return intervals;
        for(int i = 1 ; i < len ; i++)
        {
                if(intervals[i].start <= intervals[i-1].end)
                {
                    intervals[i].start = min(intervals[i-1].start,intervals[i].start);
                    intervals[i].end = max(intervals[i-1].end,intervals[i].end);
                }
                else{
                        ans.push_back(intervals[i-1]);
                }
        }
        ans.push_back(intervals[len-1]);
        return ans;
    }
};

//自己的方法
//段错误:您的程序发生段错误，可能是数组越界，堆栈溢出（比如，递归调用层数太多）等情况引起
//if(!intervals.size()) return intervals;
#include<algorithm>
bool cmp(Interval  a,Interval  b)
{
    if(a.start==b.start){ return a.end< b.end;}
    return a.start < b.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        //没有加这一行的判定
        if(!intervals.size()) return intervals;
        sort(intervals.begin(),intervals.end(),cmp);
        vector<Interval>::iterator end=intervals.begin();
        vector<Interval>::iterator iter=end+1;
        vector<Interval> vec;
	   //vec.emplace_back(*end);
        for(;iter!=intervals.end();++iter){
            if(iter->start>end->end){
                vec.emplace_back(*end);
            }else{
                iter->start=min(iter->start,end->start);
                iter->end=max(iter->end,end->end);
            }
            end=iter;
        }
        //因为采用for里面的策略，end都是指向最后应该一个元素（）
        vec.emplace_back(*end);
        return vec;
    }
};
```



### 41、找到字符串的最长无重复字符子串

```c++
#include<unordered_set>
class Solution {
public:
    int maxLength(vector<int>& arr) {
        // write code here
        unordered_set<int> mySet;
        int maxLength=0;
        int i=0;
        int j=0;
        int length=arr.size();
        while(j<length){
            if(!mySet.count(arr[j])){
                mySet.emplace(arr[j++]);
                maxLength=max(maxLength,j-i);
            }else{
                mySet.erase(arr[i++]);
            }
        }
        return maxLength;
    }
};
```

```c++
//未通过
#include<map>
class Solution {
public
    int maxLength(vector<int>& arr) {
        // write code here
        int length=arr.size();
        int maxLength=0;
        map<int, int> myMap;
        int i=0;
        int j=0;
        while(j<length){
            if(myMap.count(arr[j])){
                i=max(myMap.at(arr[j]),i);
            }
            maxLength=max(maxLength, j-i+1);
            myMap.emplace(arr[j],j+1);
            ++j;
        }
        return maxLength;
    }
};
```
### 53 、删除链表的倒数第n个节点

```c++
ListNode* removeNthFromEnd(ListNode* pHead, int k) {
    ListNode* Tail=pHead;
    for(int i=0;i<k;++i){
        // 保证k的值小于链表长度
        if(Tail==nullptr){
            return Tail;
        }
        // 说明到这里的时候k的值等于链表的长度，则是删除头节点
        if(Tail->next==nullptr){
            return pHead->next;
        }
        Tail=Tail->next;
    }
    ListNode *pre=pHead;
    while(Tail->next!=nullptr){
        Tail=Tail->next;
        pre=pre->next;
    }
    pre->next=pre->next->next;
    return pHead;
}
```

### 57、反转数字

```c++
int reverse(int x) {
    int num=0;
    int sign=1;
    if(x<0){
        sign=-1;
        x=-x;
    }
    while(x){
        num=num*10+x%10;
        x=x/10;
    }
    return sign*num;
}
```

### 59、矩阵的最小路径和

```C++
int minPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i)
    {
        dp[i][1] = dp[i - 1][1] + matrix[i - 1][0];
        }
    // n和m不同！！！
    for (int i = 1; i <= m; ++i)
    {
        dp[1][i] = dp[1][i - 1] + matrix[0][i - 1];
    }

    for (int i = 2; i <= n; ++i)
    {
        for (int j = 2; j <= m; ++j)
        {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + matrix[i - 1][j - 1];
        }
    }
    return dp[n][m];
}
```
### 61、两数之和

```c++
//运行超时:您的程序未能在规定时间内运行结束，请检查是否循环有错或算法复杂度过大。
vector<int> twoSum(vector<int>& numbers, int target) {
    int length=numbers.size();
    int left=0;
    int right=length-1;
    while(left<=right){
        while(left<=right&&numbers[right]>target){
            --right;
        }
        while(left<=right&&numbers[left]<=target){
            if((numbers[left]+numbers[right])==target){
                return {left+1,right+1};
            }
            ++left;
        }
        left=0;
    }
    return {-1,-1};
}

// 解法2:哈希表
vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> myMap;
        for(int i=0;i<numbers.size();++i){
            myMap[numbers[i]]=i;
        }
        vector<int> vec;
        for(int i=0;i<numbers.size();++i){
            int reverse=target-numbers[i];
            // 需要满足 index1 小于index2，reverse[i]本身，不然就是同一个数
            if(myMap.count(reverse)&&myMap.at(reverse)!=i){
                // unordered_map是无序的，即使输入[70,30,20,100, 110, 150],90
                // 但是我们返回的是下标的顺序，第一个元素是70，下标为0，所以reverse只能去下标大于0的其余元素去找，即20的下标2
                return {i+1,myMap.at(reverse)+1};
            }
        }
        return {-1,-1};
    }
```

### 65、斐波拉契数列
### Offer面试题10——青蛙跳台阶问题
```C++
//解法1：
int Fibonacci(int n) {
    int result[2]={0,1};
    if(n<2){
        return result[n];
    }
    int fibFirst=0;
    int fibSecond=1;
    int fibN=0;
    for(unsigned int i=2;i<=n;++i){
        fibN=fibFirst+fibSecond;
        fibFirst=fibSecond;
        fibSecond=fibSecond;
        fibSecond=fibN;
    }
    return fibN;
}
```

### 66、两个链表的第一个公告结点
```C++
//自己的方法段错误
int LengthList(ListNode * pHead){
        int length=0;
        while(pHead!=nullptr){
            ++length;
            pHead=pHead->next;
        }
        return length;
    }
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1==nullptr){
            return pHead2;
        }
        if(pHead2==nullptr){
            return pHead1;
        }
        int length1=LengthList(pHead1);
        int length2=LengthList(pHead2);
        if(length1>length2){
            while(length1-length2){
                pHead1=pHead1->next;
            }
        }else{
            while(length2-length1){
                pHead2=pHead2->next;
            }
        }
        while(pHead1!=nullptr&&pHead2!=nullptr){
            if(pHead1==pHead2){
                return pHead1;
            }
        }
        return nullptr;
    }


//
ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode *ta = pHead1, *tb = pHead2;
        while (ta != tb) {
            ta = ta ? ta->next : pHead2;
            tb = tb ? tb->next : pHead1;
        }
        return ta;
    }
```

### 69、链表中倒数第k个结点
```C++
ListNode* FindKthToTail(ListNode* pHead, int k) {
        // write code here
        if(k<1){
            return nullptr;
        }
        ListNode* Tail=pHead;
        for(int i=0;i<k-1;++i){
            if(Tail==nullptr){
                return Tail;
            }
            Tail=Tail->next;
            //当k大于链表长度时，上面的Tail=Tail->next会将Tail置空，必须在判断一次
            if(Tail==nullptr){
                return Tail;
            }
        }
        while(Tail->next!=nullptr){
            Tail=Tail->next;
            pHead=pHead->next;
        }
        return pHead;
    }
```

### 73、数组中出现次数超过一半的数字
### offer面试题39——数组中出现次数超过一半的数字
```C++
//解法1：排序 O(n)
int MoreThanHalfNum_Solution(vector<int> numbers) {
    sort(numbers.begin(),numbers.end());
    int mid=numbers.size()>>1;
    int key=numbers[mid];
    int num=0;
    for(int i=0;i<numbers.size();++i){
        if(numbers[i]==key){
            ++num;
        }
    }
    if(2*num>numbers.size()){
        return key;
    }
    return 0;
}
//解法2：快速排序 O(n)
int MoreThanHalfNum_Solution1(int* numbers, int length)
{
 
    int middle = length >> 1;
    int start = 0;
    int end = length - 1;
    int index = Partition(numbers, length, start, end);
    while(index != middle)
    {
        if(index > middle)
        {
            end = index - 1;
            index = Partition(numbers, length, start, end);
        }
        else
        {
            start = index + 1;
            index = Partition(numbers, length, start, end);
        }
    }
 
    int result = numbers[middle];
    if(!CheckMoreThanHalf(numbers, length, result))
        result = 0;
    return result;
}
//解法3：O(n)
int MoreThanHalfNum_Solution(vector<int> numbers)
{
    if (numbers.size() == 0)
    {
        return 0;
    }
    int result = numbers[0];
    int times = 1;
    for (int i = 1; i < numbers.size(); ++i)
    {
        if (times == 0)
        {
            result = numbers[i];
            times = 1;
        }
        else
        {
            if (result == numbers[i])
            {
                ++times;
            }
            else
            {
                --times;
            }
        }
    }
    int num = 0;
    for (int i = 0; i < numbers.size(); ++i)
    {
        if (numbers[i] == result)
        {
            ++num;
        }
    }
    if (2 * num > numbers.size())
    {
        return result;
    }
    return 0;
}
```
### 91、最长上升子序列
```C++
//动态规划
int LIS(vector<int> &arr)
{
    if (arr.size() == 0)
    {
        return 0;
    }
    int length = arr.size();
    // int dp[length];
    //初始化数组dp的每个值为1，memset只能填充0和-1，因为其是按字节填充
    // memset(dp, 1, sizeof(dp));
    vector<int> dp(length);
    // fill_n(dp.begin(), length, 1);
    fill(dp.begin(), dp.end(), 1);
    int max_length = INT_MIN;
    //最外层for循环
    for (int i = 1; i < length; ++i)
    {
        //里面的for循环是寻找长度为i时的最长递增子序列，从长度为0开始找
        for (int j = 0; j < i; ++j)
        {
            if (arr[i] > arr[j])
            {
                //dp[i]表示数组的前i个元素构成的最长上升子序列
                dp[i] = max(dp[i], dp[j] + 1);
                max_length = max(max_length, dp[i]);
            }
        }
    }
    return max_length;
}
//分查找
int LIS(vector<int> &arr)
{
    int length = arr.size();
    if (length == 0)
    {
        return -1;
    }
    vector<int> vec;
    // vector不能数组那样填充元素再push_back
    // 除非采用下标寻址
    // fill_n(vec.begin(), length, 1);
    for (auto item : arr)
    {
        if (vec.empty() || vec.back() < item)
        {
            vec.emplace_back(item);
        }
        else
        {
            for (int i = 0; i < vec.size(); ++i)
            {
                if (vec[i] > item)
                {
                    vec[i] = item;
                    break;
                }
            }
        }
    }
    return vec.size();
}

// 方法3：
vector<int> LIS(vector<int> &arr)
{
    int length = arr.size();
    if (length < 0)
    {
        return arr;
    }
    vector<int> vec;
    vector<int> maxLength;
    vec.emplace_back(arr[0]);
    maxLength.emplace_back(1);
    for (int k = 1; k < length; ++k)
    {
        if (arr[k] > vec.back())
        {
            vec.emplace_back(arr[k]);
            maxLength.emplace_back(vec.size());
        }
        else
        {
            int index = lower_bound(vec.begin(), vec.end(), arr[k]) - vec.begin();
            vec[index] = arr[k];
            maxLength.emplace_back(index + 1);
        }
    }
    // 首先因为在lower_bound的过程中，vec中的元素可能会被会面较小的元素所替换
    // 所以我们需要在maxLength从后往前查找，如果maxLength[i] == j，说明vec[j-1]的值应该是
    // arr[i]对应的值
    // 因为maxLength[i]数组里存放以元素i结尾的最大递增子序列长度
    for (int i = length - 1, j = vec.size(); j > 0; --i)
    {
        // maxLength[i]的值是vec对应值下标+1
        // 也就是说，maxLength最后一个元素=vec最后一个元素的下标+1
        // 等价于maxLength[length-1]=vec.size()
        if (maxLength[i] == j)
        {
            j--;
            vec[j] = arr[i];
        }
    }
    return vec;
}
```
### 92、最长公共子序列（可以跳着连接）

```c++
//LeetCode 只返回长度
int longestCommonSubsequence(string text1, string text2) {
    int length1=text1.length();
    int length2=text2.length();
    int dp[length1+1][length2+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<length1;++i){
        for(int j=0;j<length2;++j){
            if(text1[i]==text2[j]){
                dp[i+1][j+1]=dp[i][j]+1;
            }else{
                dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
            }
        }
    }
    return dp[length1][length2];
}
//采用两个二维数组
class Solution {
public:
    string LCS(string text1, string text2) {
        int length1=text1.length();
        int length2=text2.length();
        int dp[length1+1][length2+1];
        int path[length1+1][length2+1];
        memset(dp,0,sizeof(dp));
        memset(path,0,sizeof(path));
        for(int i=0;i<length1;++i){
            for(int j=0;j<length2;++j){
                if(text1[i]==text2[j]){
                    dp[i+1][j+1]=dp[i][j]+1;
                    // 来自dp[i - 1][j - 1]
                    path[i+1][j+1]=1;
                }else{
                    // 上方格，代替的就是dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
                    if(dp[i][j+1]>=dp[i+1][j]){
                        dp[i+1][j+1]=dp[i][j+1];
                        path[i+1][j+1]=2;
                    }else{
                        // 左边格
                        dp[i+1][j+1]=dp[i+1][j];
                        path[i+1][j+1]=3;
                    }
                }
            }
        }
        string str;
        while(length1>=0&&length2>=0){
            if(path[length1][length2]==1){
                --length1;
                --length2;
                str.append(string(text1[length1]));
            }
        }
        return "dp[length1][length2]";
    }
};


//算法导论
string LCS(string text1, string text2) {
    // write code here
    int length1 = text1.length();
    int length2 = text2.length();
    int dp[length1 + 1][length2 + 1];
    int path[length1 + 1][length2 + 1];
    memset(dp, 0, sizeof(dp));
    memset(path, 0, sizeof(path));

    for (int i = 0; i < length1; ++i)
    {
        for (int j = 0; j < length2; ++j)
        {
            if (text1[i] == text2[j])
            {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else
            {
                dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
            }
        }
    }
    string str="";
    for(int i=length1,j=length2;dp[i][j]>=1;){
        if(text1[i-1]==text2[j-1]){
            str+=text1[i-1];
            --i,--j;
        }else if(dp[i-1][j]>=dp[i][j-1]){
            --i;
        }else{
            --j;
        }
    }
    reverse(str.begin(), str.end());
    return str.empty() ? "-1" : str;
}
```



### 101、缺失数字

```c++
//运行超时
int getStandard(int* a,int left,int right){
    int key=a[left];
    while(left<right){
        while(left<right&&a[right]>=key){
            --right;
        }
        a[left]=a[right];
        while(left<right&&a[left]<=key){
            ++left;
        }
        a[right]=a[left];
    }
    a[left]=key;
    return left;
}
int solve(int* a, int aLen) {
    // write code here
    int left=0;
    int right=aLen-1;
    int key=getStandard(a, left, right);
    while(left<=right){
        if(key==a[key]){
            left=key+1;
        }else if(a[key]>key){
            right=key;
        }else{
            left=key+1;
        }
        key=getStandard(a, left, right);
    }
    return a[key];
}

//位运算
int solve(int* a, int aLen) {
    // write code here
    int num=0;
    for(int i=0;i<aLen;++i){
        num=num^(i+1);
        num=num^a[i];
    }
    return num;
}
```

### 103、反转字符串

```c++
string solve(string str) {
    int length=str.length();
    int temp=0;
    int low=0;
    int high=length-1;
    while(low<=high){
        temp=str[low];
        str[low]=str[high];
        str[high]=temp;
        ++low;
        --high;
    }
    return str;
}
```

### 109、岛屿数量

```c++
//深度优先
//时间复杂度：O(MN)O(MN)，其中 MM 和 NN 分别为行数和列数。
//空间复杂度：O(MN)O(MN)，在最坏情况下，整个网格均为陆地，深度优先搜索的深度达到 M NMN。
void dfs(vector<vector<char>> &grid, int i, int j, int n, int m)
{
    grid[i][j] = '0';
    if (i - 1 >= 0 && grid[i - 1][j] == '1')
        dfs(grid, i - 1, j, n, m);
    if (j - 1 >= 0 && grid[i][j - 1] == '1')
        dfs(grid, i, j - 1, n, m);
    if (i + 1 < n && grid[i + 1][j] == '1')
        dfs(grid, i + 1, j, n, m);
    if (j + 1 < m && grid[i][j + 1] == '1')
        dfs(grid, i, j + 1, n, m);
}
int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    if (n == 0)
    {
        return 0;
    }
    int m = grid[0].size();
    int num = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == '1')
            {
                ++num;
                dfs(grid, i, j, n, m);
            }
        }
    }
    return num;
}
```



### 127、最长公共子串（相邻最长的）

```c++
string LCS(string str1, string str2) {
    int length1=str1.size();
    int length2=str2.size();
    int dp[length1+1][length2+1];
    memset(dp, 0, sizeof(dp));
    int maxLen=0,end=0;
    for(int i=0;i<length1;++i){
        for(int j=0;j<length2;++j){
            if(str1[i]==str2[j]){
                dp[i+1][j+1]=dp[i][j]+1;
            }else{
                dp[i+1][j+1]=0;
            }
            if(dp[i+1][j+1]>maxLen){
                maxLen=dp[i+1][j+1];
                // j记录字符串str2中，最长公共子串的最后一位
                // 记录i也是一样的，因为这个算法是找相邻的最长
                end=j;
            }
        }
    }
    string res;
    if(maxLen==0) return "-1";
    else{
        res=str2.substr(end-maxLen+1,maxLen);
    }        
    return res;
}
```



### 141、判断回文

```C++
#include<cstring>
class Solution {
public:
    bool judge(string str) {
        int length=strlen(str.c_str());
        int i=0;
        int j=length-1;
        while(i<=j){
            if(str[i++]!=str[j--]){
                return false;
            }
        }
        return true;
    }
};


//拓展，判断回文数字leetcode
class Solution {
public:
    bool isPalindrome(int x) {
        // 特殊情况：
        // 如上所述，当 x < 0 时，x 不是回文数。
        // 同样地，如果数字的最后一位是 0，为了使该数字为回文，
        // 则其第一位数字也应该是 0
        // 只有 0 满足这一属性
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }
        // 当数字长度为奇数时，我们可以通过 revertedNumber/10 去除处于中位的数字。
        // 例如，当输入为 12321 时，在 while 循环的末尾我们可以得到 x = 12，revertedNumber = 123，
        // 由于处于中位的数字不影响回文（它总是与自己相等），所以我们可以简单地将其去除。
        return x == revertedNumber || x == revertedNumber / 10;
    }
};
```
### 144、不相邻最大子序列和
```C++
long long subsequence(int n, vector<int>& array) {
        // write code here
        // 因为需要取不相邻的两个值，dp数组中填充下标为0和1的位置
        vector<int> dp={0,array[0]};
        int i=0;
        int j=0;
        for(i=1;i<n;++i){
            // 每次从array中取一个下标值为i的时候，在dp中取值需要+1
            dp.emplace_back(max(dp[i+1-1],dp[i+1-2]+array[i]));
        }
        return dp[n];
    }
```