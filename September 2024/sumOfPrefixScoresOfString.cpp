// leetcode 2416. Sum of Prefix Scores of Strings

// You are given an array words of size n consisting of non-empty strings.

// We define the score of a string word as the number of strings words[i] such that word is a prefix of words[i].

// For example, if words = ["a", "ab", "abc", "cab"], then the score of "ab" is 2, since "ab" is a prefix of both "ab" and "abc".
// Return an array answer of size n where answer[i] is the sum of scores of every non-empty prefix of words[i].

// Note that a string is considered as a prefix of itself.

#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[26];
    int prefixCount=0;

    bool containsKey(char c){
        return (links[c-'a']!=NULL);
    }

    void put(char c,Node* node){
        links[c-'a']=node;
    }

    Node* get(char c){
        return links[c-'a'];
    }

    void increasePrefixCount(){
        prefixCount++;
    }

};


class Solution {

private:

    Node* root = new Node();

    void insert(string &word){
        Node* node = root;
        for(char &c:word){
            if(!node->containsKey(c)){
                node->put(c,new Node());
            }
            node=node->get(c);
            node->increasePrefixCount();
        }
    }

    int getScore(string&word){
        Node* node=root;
        int score=0;
        for(char &c:word){
            node=node->get(c);
            score+=node->prefixCount;
        }
        return score;
    }

public:
    vector<int> sumPrefixScores(vector<string>& words) {
        for(string &word:words){
            insert(word);
        }
        vector<int>ans;
        for(string &word:words){
            ans.push_back(getScore(word));
        }
        return ans;
    }
};