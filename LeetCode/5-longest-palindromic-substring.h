// https://leetcode.com/problems/longest-palindromic-substring/description/
//  5-longest-palindromic-substring.h
//  CppToySolution
//
//  Created by QZQ on 23/09/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef __longest_palindromic_substring_h
#define __longest_palindromic_substring_h
// 1. O(n^2) solution
class Solution2 {
public:
    string longestPalindrome(string s) {
        int ans = 0, len = s.length(), ansPosLeft = 0;
        for(int i = 0; i < len; ++i)
        {
            {
                int j = 0;
                while(i-j-1 >= 0 && i+j+1 < len && s[i-j-1] == s[i+j+1]) j++;
                if(2*j+1 > ans)
                {
                    ans = 2*j+1;
                    ansPosLeft = i-j;
                }
            }
            
            if(i+1 < len && s[i] == s[i+1])
            {
                int j = 0;
                while(i-j-1 >= 0 && i+j+2 < len && s[i-j-1] == s[i+j+2]) j ++;
                if(2*j+2 > ans)
                {
                    ans = 2*j+2;
                    ansPosLeft = i-j;
                }
            }
        }
        return s.substr(ansPosLeft, ans);
    }
};

// 2. O(n) manacher solution
// https://www.felix021.com/blog/read.php?2040
class Solution {
public:
    string longestPalindrome(string s) {
        string str;
        str.push_back('*');
        str.push_back('#');
        for(int i = 0, len=s.length(); i < len; ++i)
        {
            str.push_back(s[i]);
            str.push_back('#');
        }
        str.push_back('$');
        
        int *r = new int[str.length()];
        memset(r, 0, sizeof(int) * str.length());
        
        int mx = 0, idx = 0, ans = 0, ansPosLeft = 0;
        for(int i = 1, len=str.length(); i < len; ++i)
        {
            r[i] = mx>i ? min(r[2*idx - i], mx-i+1) : 1;
            while(str[i+r[i]] == str[i-r[i]]) r[i]++;
            if(i+r[i]-1 > mx) mx = i+r[i]-1, idx = i;
            
            if(r[i]-1 > ans)
            {
                ans = r[i]-1;
                ansPosLeft = (i - r[i]) / 2;
            }
        }
        
        delete [] r;
        return s.substr(ansPosLeft, ans);
    }
};
#endif /* __longest_palindromic_substring_h */
