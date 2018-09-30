// https://leetcode.com/problems/generate-parentheses/description/
//  22-generate-parentheses.h
//  CppToySolution
//
//  Created by QZQ on 30/09/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef _2_generate_parentheses_h
#define _2_generate_parentheses_h
class Solution {
public:
    void dfs(int sta, int remain, int top, string &str, vector<string> &ret) {
        if(!sta && !remain) ret.push_back(str);
        else {
            if(remain) {
                str[top] = '(';
                dfs(sta+1, remain-1, top+1, str, ret);
            }
            if(sta) {
                str[top] = ')';
                dfs(sta-1, remain, top+1, str, ret);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        string str(2*n, 'x');
        vector<string> ret;
        dfs(0, n, 0, str, ret);
        return ret;
    }
};

#endif /* _2_generate_parentheses_h */
