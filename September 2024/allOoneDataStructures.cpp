// leetcode 432. All O`one Data Structure

// Design a data structure to store the strings' count with the ability to return the strings with minimum and maximum counts.

// Implement the AllOne class:

    // AllOne() Initializes the object of the data structure.
    // inc(String key) Increments the count of the string key by 1. If key does not exist in the data structure, insert it with count 1.
    // dec(String key) Decrements the count of the string key by 1. If the count of key is 0 after the decrement, remove it from the data structure. It is guaranteed that key exists in the data structure before the decrement.
    // getMaxKey() Returns one of the keys with the maximal count. If no element exists, return an empty string "".
    // getMinKey() Returns one of the keys with the minimum count. If no element exists, return an empty string "".
    // Note that each function must run in O(1) average time complexity.

#include<bits/stdc++.h>
using namespace std;

class AllOne {
public:
    unordered_map<string,int> count;
    set<pair<int,string>> se;
    AllOne() {
        count.clear();
    }

    void inc(string key) {
        int n = count[key];
        count[key]++;
        se.erase({n,key});
        se.insert({n+1,key});
    }
    void dec(string key) {
        int n = count[key];
        count[key]--;
        se.erase({n,key});
        if(count[key] > 0) se.insert({n-1,key});
    }
    
    string getMaxKey() {
        if(!se.empty()) return se.rbegin()->second;
        return "";
    }
    
    string getMinKey() {
        if(!se.empty()) return se.begin()->second;
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

