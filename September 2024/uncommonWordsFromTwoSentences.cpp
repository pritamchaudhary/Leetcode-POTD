// Leetcode 884. Uncommon Words from Two Sentences

// A sentence is a string of single-space separated words where each word consists only of lowercase letters.

// A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.

// Given two sentences s1 and s2, return a list of all the uncommon words. You may return the answer in any order.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        int n = s1.size();
        int i = 0;
        while (i < n) {
            string t = "";
            while (i < n && s1[i] != ' ') {
                t += s1[i];
                i++;
            }
            i++;
            mp[t]++;
        }
        int j = 0;
        while (j < s2.size()) {
            string t = "";
            while (j < s2.size() && s2[j] != ' ') {
                t += s2[j];
                j++;
            }
            j++;
            mp[t]++;
        }
        vector<string> v;
        for (auto it : mp)
            if (it.second == 1)
                v.push_back(it.first);

        return v;
    }
};