// https://leetcode.com/problems/valid-parentheses/description/
//  20-valid-parentheses.h
//  CppToySolution
//
//  Created by QZQ on 27/09/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef _0_valid_parentheses_h
#define _0_valid_parentheses_h
class Solution {
public:
    bool isValid(string s) {
        vector<char> sta;
        for(int i = 0, len = s.length(); i < len; ++i)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') sta.push_back(s[i]);
            else
            {
                if(sta.size())
                {
                    if('[' == sta[sta.size()-1] && ']' != s[i]) return false;
                    if('{' == sta[sta.size()-1] && '}' != s[i]) return false;
                    if('(' == sta[sta.size()-1] && ')' != s[i]) return false;
                    
                    sta.pop_back();
                }
                else return false;
            }
        }
        return sta.size() == 0;
    }
};

#endif /* _0_valid_parentheses_h */
