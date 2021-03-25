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


class Solution {
    // 最简单的方法，就是从第一个数n1开始遍历，找到（target-n1）的数的下标;
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // 返回数组，记录两个下标
        vector<int> res ;
        unordered_map<int, int> mymap;
        // 建立hash table array's value=> array's index
        for(int i=0; i<numbers.size(); i++){
            mymap[numbers[i]] = i;
        }
        // 第二次遍历，查询是否存在当前数的complement在hash table中
        for(int i=0; i<numbers.size(); i++){
            int complement = target - numbers[i];
            if(mymap.count(complement)!=0 && mymap.at(complement)!=i){
                res = {i+1, mymap.at(complement)+1};
                return res;
            }
        }
        throw invalid_argument("No two sum solution");
    }
};
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
```

```c++
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

### 