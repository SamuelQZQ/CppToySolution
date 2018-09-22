// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
//  3-longest-substring-without-repeating-characters.h
//  CppToySolution
//
//  Created by QZQ on 22/09/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef __longest_substring_without_repeating_characters_h
#define __longest_substring_without_repeating_characters_h
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        bool charVis[256];
        for(int i = 0; i < 256; ++i) charVis[i] = false;
        
        int l = 0, r = 0, ans = 0;
        int len = s.length();
        
        while(r < len)
        {
            char temp = s[r++];
            
            if(charVis[temp]) {while(s[l++] != temp) charVis[s[l-1]] = false;}
            else charVis[temp] = true;
            
            if(r-l > ans) ans = r-l;
        }
        
        return ans;
    }
};

#endif /* __longest_substring_without_repeating_characters_h */
