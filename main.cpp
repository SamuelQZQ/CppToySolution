//
//  main.cpp
//  CppToySolution
//
//  Created by QZQ on 16/09/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//


#include <list>
#include <map>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

#include "priority_queue.hpp"
class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        stack<char> operators;
        s.push_back(')');
        operators.push('(');
        
        bool hasNumber = false;
        int number = 0;
        for(int i = 0; i < s.length(); ++i)
        {
            char c = s[i];
            if(c == ' ') continue;
            if(c >= '0' && c <= '9')
            {
                hasNumber = true;
                number = number * 10 + c-'0';
            }
            else
            {
                if(hasNumber)
                {
                    nums.push(number);
                    number = 0;
                    hasNumber = false;
                }
                if(c == ')')
                {
                    while(operators.top() != '(')
                    {
                        int a = nums.top(); nums.pop();
                        int b = nums.top(); nums.pop();
                        char op = operators.top(); operators.pop();
                        if(op == '+') nums.push(a+b);
                        else nums.push(b-a);
                    }
                    operators.pop();
                }
                else
                {
                    if(operators.top() == '+' || operators.top() == '-')
                    {
                        int a = nums.top(); nums.pop();
                        int b = nums.top(); nums.pop();
                        char op = operators.top(); operators.pop();
                        if(op == '+') nums.push(a+b);
                        else nums.push(b-a);
                    }
                    operators.push(c);
                }
                
            }
        }
        return nums.top();
    }
};
int main()
{
    Solution s;
    string st = "1+(4+5+2)";
    s.calculate(st);
    return 0;
}
