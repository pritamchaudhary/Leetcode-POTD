// leetcode 440. K-th Smallest in Lexicographical Order

// Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int Count(long curr, long next, int n) {
        int countNum = 0;
        while (curr <= n) {
            // storing the number of valid terms on that level in counNum
            countNum += (next - curr);
            // for going to the next level
            curr *= 10;
            next *= 10;
            // we need to make sure next does not exceed the limit
            next = min(next, long(n + 1));
        }
        return countNum;
    }

    int findKthNumber(int n, int k) {
        int curr = 1;
        k -= 1;
        while (k > 0) {
            // check number of valid terms with the curr as prefix
            int count = Count(curr, curr + 1, n);
            if (count <= k) {
                curr++;
                // skip those valid terms with curr prefix
                k -= count;
            } else {
                curr *= 10;
                k -= 1;
            }
        }
        return curr;
    }
};