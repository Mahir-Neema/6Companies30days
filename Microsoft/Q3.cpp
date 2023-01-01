// You are playing the Bulls and Cows game with your friend.

// You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:

// The number of "bulls", which are digits in the guess that are in the correct position.
// The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.
// Given the secret number secret and your friend's guess guess, return the hint for your friend's guess

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int cowCount=0, bullCount=0;
        
        vector<int> sPos(10,0);
        vector<int> gPos(10,0);
        
        for(int i=0;i<n;i++){
            char ch1 = secret[i], ch2 = guess[i];
            
            if(ch1==ch2) bullCount++;
            else{
                sPos[ch1-'0']++;
                gPos[ch2-'0']++;
            }
        }
        
        for(int i=0;i<10;i++) cowCount+=min(sPos[i],gPos[i]);
        
        string ans = to_string(bullCount)+'A'+to_string(cowCount)+'B';
        
        return ans;
    }
};