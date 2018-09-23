// https://leetcode.com/problems/regular-expression-matching/description/
//  10-regular-expression-matching.h
//  CppToySolution
//
//  Created by QZQ on 23/09/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef _0_regular_expression_matching_h
#define _0_regular_expression_matching_h
// O(n^2)
// top-down DP
class Solution {
public:
    bool isMatchChar(char a, char b)
    {
        if(a == '*' || b == '*') return false;
        if(a == b || a == '.' || b =='.') return true;
        return false;
    }
    
    bool isMatch(string s, string p) {
        int lenS = s.length(), lenP = p.length();
        bool **vis = new bool*[lenS+1];
        for(int i = 0; i < lenS+1; ++i)
        {
            vis[i] = new bool[lenP+1];
            memset(vis[i], 0, sizeof(bool)*(lenP+1));
        }
        
        vis[0][0] = true;

        for(int i = 0; i <= lenS; ++i)
        {
            for(int j = 0; j <= lenP; ++j)
            {
                if(!vis[i][j]) continue;
                if(i < lenS && j < lenP && isMatchChar(s[i], p[j])) vis[i+1][j+1] = true;
                if(j+1 < lenP && p[j+1] == '*') vis[i][j+2] = true;
                if(i < lenS && j+1 < lenP && isMatchChar(s[i], p[j]) && p[j+1] == '*') vis[i+1][j] = true;
            }
        }
        
        bool ans = vis[lenS][lenP];
        for(int i = 0; i < lenS; ++i) delete [] vis[i];
        delete [] vis;
        return ans;
        
    }
};

#endif /* _0_regular_expression_matching_h */
