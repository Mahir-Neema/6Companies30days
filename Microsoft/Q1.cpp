// You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
// Evaluate the expression. Return an integer that represents the value of the expression.
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int evalRPN(vector<string>& s) {
        int n = s.size();
        stack<long> st;
        for(int i=0;i<n;i++){
            if(s[i]=="+"){
                long a = st.top(); st.pop();
                long b = st.top(); st.pop();
                st.push(a+b);
            }
            else if(s[i]=="-"){
                long a = st.top(); st.pop();
                long b = st.top(); st.pop();
                st.push(b-a);
            }
            else if(s[i]=="*"){
                long a = st.top(); st.pop();
                long b = st.top(); st.pop();
                st.push(a*b);
            }
            else if(s[i]=="/"){
                long a = st.top(); st.pop();
                long b = st.top(); st.pop();
                st.push(b/a);
            }
            
            else st.push(stoi(s[i]));
        }
        
        return st.top();
    }
};