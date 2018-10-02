// https://leetcode.com/problems/longest-valid-parentheses/description/
//  32-longest-valid-parentheses.h
//  CppToySolution
//
//  Created by QZQ on 02/10/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef _2_longest_valid_parentheses_h
#define _2_longest_valid_parentheses_h
// 有很多其他Trick的方法，但是用DP应该是最有普适性的。
// 遇到这种能分解成子问题的题目，应该要足够敏感！
class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        int *dp = new int[len+1];
        
        dp[0] = dp[1] = 0;
        int ans = 0;
        for(int i = 2; i <= len; ++i) {
            if(i-1-dp[i-1]-1 >= 0 && s[i-1] == ')' && s[i-1-dp[i-1]-1] == '(')
                dp[i] = dp[i-1] + 2 + dp[i-1-dp[i-1]-1];
            else dp[i] = 0;
            
            if(dp[i] > ans) ans = dp[i];
        }
        delete [] dp;
        return ans;
    }
};
#endif /* _2_longest_valid_parentheses_h */
