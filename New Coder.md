7、股票（一次交易）

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
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* pHead, int k) {
        ListNode* Tail=pHead;
        for(int i=0;i<k-1;++i){
            if(Tail==nullptr){
                return Tail;
            }
            Tail=Tail->next;
        }
        while(Tail->next!=nullptr){
            Tail=Tail->next;
            pHead=pHead->next;
        }
        return pHead;
    }
};
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
        // 因为dp[0]填充了0
        return dp[n];
    }
```