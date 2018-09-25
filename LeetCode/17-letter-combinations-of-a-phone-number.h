//
//  17-letter-combinations-of-a-phone-number.h
//  CppToySolution
//
//  Created by QZQ on 25/09/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef _7_letter_combinations_of_a_phone_number_h
#define _7_letter_combinations_of_a_phone_number_h
class Solution {
public:
    map<char, string> charSet;
    vector<string> ret;
    
    void dfs(string &temp,const string &digits, int index)
    {
        if(index == digits.length()) ret.push_back(temp);
        else
        {
            string &chars = charSet[digits[index]];
            for(int i = 0; i < chars.length(); ++i)
            {
                temp.push_back(chars[i]);
                dfs(temp, digits, index+1);
                temp.pop_back();
            }
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(!digits.length()) return ret;
        charSet['2'] = "abc";
        charSet['3'] = "def";
        charSet['4'] = "ghi";
        charSet['5'] = "jkl";
        charSet['6'] = "mno";
        charSet['7'] = "pqrs";
        charSet['8'] = "tuv";
        charSet['9'] = "wxyz";
        
        string temp = "";
        dfs(temp, digits, 0);
        return ret;
    }
};

#endif /* _7_letter_combinations_of_a_phone_number_h */
