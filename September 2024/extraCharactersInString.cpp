// leetcode 2707. Extra Characters in a String

// You are given a 0-indexed string s and a dictionary of words dictionary. You have to break s into one or more non-overlapping substrings such that each substring is present in dictionary. There may be some extra characters in s which are not present in any of the substrings.

// Return the minimum number of extra characters left over if you break up s optimally.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int index, vector<pair<int,int>> v, int prev, vector<vector<int>>& dp){
        if(index==v.size()){
            return 0;
        }
        int ans=0;
        if(prev!=-1&&dp[index][prev]!=-1)return dp[index][prev];
        if(v[index].first>prev){
            ans=max(helper(index+1,v,prev,dp),v[index].second-v[index].first+1+helper(index+1,v,v[index].second,dp));
        }
        else{
            ans=helper(index+1,v,prev,dp);
        }
        if(prev!=-1)dp[index][prev]=ans;
        return ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string,int> m;
        for(auto&i:dictionary){
            m[i]++;
        }
        vector<pair<int,int>> v;
        for(int i = 0; i<s.length(); i++){
            string temp;
            for(int j = i; j<s.length(); j++){
                temp.push_back(s[j]);
                if(m[temp])v.push_back({i,j});
            }
        }
        vector<vector<int>> dp(v.size(),vector<int>(s.length(),-1));
        return s.length()-helper(0,v,-1,dp);
    }
};