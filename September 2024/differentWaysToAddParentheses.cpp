// leetcode 241. Different Ways to Add Parentheses

// Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.

// The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 10^4.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> solve(string s)
    {
        vector<int> ans;

        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '+' or s[i] == '*' or s[i] == '-')
            {
                vector<int> left = solve(s.substr(0,i));
                vector<int> right = solve(s.substr(i+1));

                for(auto x : left)
                {
                    for(auto y : right)
                    {
                        if(s[i] == '+') ans.push_back(x + y);
                        else if(s[i] == '-') ans.push_back(x - y);
                        else ans.push_back(x * y);
                    }
                }
            }
        }
        

        if(ans.empty()) ans.push_back(stoi(s));

        return ans;
    }

    unordered_map<string,vector<int>> m;
    vector<int> solveTopDown(string s)
    {
        vector<int> ans;
        if(m.find(s) != m.end()) return m[s];

        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '+' or s[i] == '*' or s[i] == '-')
            {
                vector<int> left = solveTopDown(s.substr(0,i));
                vector<int> right = solveTopDown(s.substr(i+1));

                for(auto x : left)
                {
                    for(auto y : right)
                    {
                        if(s[i] == '+') ans.push_back(x + y);
                        else if(s[i] == '-') ans.push_back(x - y);
                        else ans.push_back(x * y);
                    }
                }
            }
        }
        

        if(ans.empty()) ans.push_back(stoi(s));

        return m[s] = ans;
    }

    vector<int> diffWaysToCompute(string expression) {
        return solveTopDown(expression);
    }
};