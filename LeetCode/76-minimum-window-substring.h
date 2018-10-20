//
//  76-minimum-window-substring.h
//  CppToySolution
//
//  Created by QZQ on 20/10/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef _6_minimum_window_substring_h
#define _6_minimum_window_substring_h
class Solution {
public:
    string minWindow(string s, string t) {
        int need[128];
        for(int i = 0; i < 128; ++i) need[i] = 0;
        
        int lenS = s.length(), lenT = t.length();
        for(int i = 0; i < lenT; ++i) need[t[i]]++;
        
        int needNum = 0;
        for(int i = 0; i < 128; ++i) needNum += need[i];
        
        int count[128];
        for(int i = 0; i < 128; ++i) count[i] = 0;
        
        int ansl = -1, ansLen = 2e9;
        int l = 0, r = 0;
        for(r = 0; r < lenS; ++r)
        {
            count[s[r]] ++;
            if(count[s[r]] <= need[s[r]]) needNum--;
            
            while(0 == needNum)
            {
                if(r - l + 1 < ansLen)
                {
                    ansLen = r-l+1;
                    ansl = l;
                }
                
                count[s[l]] --;
                if(count[s[l]] < need[s[l]]) needNum++;
                l++;
            }
        }
        
        if(-1 == ansl) return "";
        else return s.substr(ansl, ansLen);
    }
};

#endif /* _6_minimum_window_substring_h */
