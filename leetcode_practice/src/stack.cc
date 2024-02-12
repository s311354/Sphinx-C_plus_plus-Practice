#include "solutions.h"
#include <numeric>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <queue>
#include <boost/lexical_cast.hpp>

namespace leetcode {

using namespace std;

bool Solutions::isValid(std::string s)
{
    std::stack<char> st; 
    
    for(auto & ch : s)  
    {
        if( ch == '(' || ch == '{' || ch == '[' )
            st.push(ch);  
        else {
            if( st.empty() || ( st.top() == '(' && ch != ')' ) || ( st.top() == '{' && ch != '}') || (st.top() == '[' && ch != ']'))
                return false;
            
            st.pop();
        }
    }

    return st.empty(); 
}

std::string Solutions::simplifyPath(std::string path)
{
    std::stack<std::string> st;
    
    for(int i = 0; i < path.size(); i++) {
        if(path[i] == '/') continue;
        
        std::string temp;
        
        while(i < path.size() && path[i] != '/') {
            temp += path[i];
            ++i;
        }
        
        if(temp == ".") continue;
        else if(temp == "..") {
            if(!st.empty()) st.pop();
        }
        else st.push(temp);
    }
    
    std::string ans = "";
    
    while(!st.empty()) {
        ans = "/" + st.top() + ans;
        st.pop();
    }
    
    if(ans.size() == 0) return "/";

    return ans;
}

int Solutions::evalRPN(std::vector<std::string>& tokens)
{
    std::stack<int> st;

    for(int i=0 ; i < tokens.size() ; i++){
        if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/") {
            st.push(stoi(tokens[i]));
        } else {

            long a,b;
            b = st.top();
            st.pop();
            a = st.top();
            st.pop();

            if(tokens[i] == "+")
                st.push(a+b);
            else if(tokens[i] == "-")
                st.push(a-b);
            else if(tokens[i] == "*")
                st.push(a*b);
            else
                st.push(a/b);
        }
    }
    return st.top();  
}

int Solutions::calculate(std::string s) {
    int res = 0, sum = 0, sign = 1;
    std::stack<int> st({1});

    for(auto & ch : s) {
        if(std::isdigit(ch)) sum = sum * 10 + (ch - '0');
        else {
            res += sum * sign * st.top();
            sum = 0;

            if (ch == '-') sign = -1;
            else if (ch == '+') sign = 1;
            else if (ch == '(') {
                st.push(st.top() * sign);
                sign = 1;
            } else if (ch == ')') st.pop();
        }
    }
    return res += (sum * sign);

}

} /* namespace leetcode */
