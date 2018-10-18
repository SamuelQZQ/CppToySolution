// https://leetcode.com/problems/group-anagrams/description/
//  49-group-anagrams.h
//  CppToySolution
//
//  Created by QZQ on 18/10/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef _9_group_anagrams_h
#define _9_group_anagrams_h
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mp;
        
        int len = strs.size();
        for(int i = 0; i < len; ++i)
        {
            string &temp = strs[i];
            
            vector<int> counts(26);
            for(int j = 0; j < temp.size(); ++j)
            {
                counts[ temp[j] - 'a' ] ++;
            }
            if(mp.find(counts) == mp.end())
            {
                vector<string> empty;
                mp[counts] = empty;
            }
            
            mp[counts].push_back(temp);
        }
        
        vector<vector<string>> ret;
        for(auto o: mp) ret.push_back(o.second);
        return ret;
    }
};

#endif /* _9_group_anagrams_h */

