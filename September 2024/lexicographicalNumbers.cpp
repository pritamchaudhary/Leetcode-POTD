// leetcode 386. Lexicographical Numbers

// Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.

// You must write an algorithm that runs in O(n) time and uses O(1) extra space. 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(vector<int> &ans, int curr, int n){
        if(curr > n) return;
        ans.push_back(curr);
        for(int i = 0 ; i <= 9 ; i++){
            if(curr * 10 + i <= n){
                helper(ans, curr * 10 + i, n);
            } else break;
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i = 1 ; i <= 9 ; i++){
            helper(ans, i, n);
        }
        return ans;
    }
};