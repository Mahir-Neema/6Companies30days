// Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
// Only numbers 1 through 9 are used.
// Each number is used at most once.
// Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

#include <bits/stdc++.h>
using namespace std;

class Solution {
 void solver(int start,int k, int n, vector<vector<int>>& allComb, vector<int>& temp){
     if(k<=0){
         if(n==0) allComb.push_back(temp);
         return;
     }
     for(int i=start;i<=9;i++){
        temp.push_back(i);
        solver(i+1,k-1,n-i,allComb,temp);
        temp.pop_back();
     }
 }
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> allComb; // storing all the combinations
        vector<int> temp;            // storing each possible combinations

        solver(1,k,n,allComb,temp);
        return allComb;
    }
};