// leetcode 1381. Design a Stack With Increment Operation

// Design a stack that supports increment operations on its elements.

// Implement the CustomStack class:

// CustomStack(int maxSize) Initializes the object with maxSize which is the maximum number of elements in the stack.
// void push(int x) Adds x to the top of the stack if the stack has not reached the maxSize.
// int pop() Pops and returns the top of the stack or -1 if the stack is empty.
// void inc(int k, int val) Increments the bottom k elements of the stack by val. If there are less than k elements in the stack, increment all the elements in the stack.

#include<bits/stdc++.h>
using namespace std;

class CustomStack {

private:

    vector<int>nums;

public:
    CustomStack(int maxSize) {
        for(int i=0;i<maxSize;++i){nums.push_back(-1);}
    }
    
    void push(int x) {
        const int m = nums.size();
        if(nums[0]==-1){nums[0]=x;return;}
        for(int i=1;i<m;++i){
            if(nums[i]==-1&&nums[i-1]!=-1){
                nums[i]=x;
                return;
            }
        }
    }
    
    int pop() {
        const int m=nums.size();
        if(nums[0]==-1){return -1;}
        for(int i=0;i<m-1;++i){
            if(nums[i]!=-1 && nums[i+1]==-1){
                int val=nums[i];
                nums[i]=-1;
                return val;
            }
        }
        if(nums[m-1]!=-1){int val=nums[m-1];nums[m-1]=-1;return val;}
        return -1;
    }
    
    void increment(int k, int val) {
        const int m = nums.size();
        int i=0;
        while(k-- && i<m){
            if(nums[i]==-1){return;}
            nums[i]+=val;
            i++;
        }
        return;
    }
};