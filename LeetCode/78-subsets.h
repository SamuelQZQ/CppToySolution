// https://leetcode.com/problems/subsets/description/
//  78-subsets.h
//  CppToySolution
//
//  Created by QZQ on 20/10/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef _8_subsets_h
#define _8_subsets_h
class Solution {
public:
    void dfs(vector<vector<int>> &ret, vector<int> &nums, vector<int> &temp, int pos)
    {
        if(pos == nums.size())
        {
            ret.push_back(temp);
            return;
        }
        
        temp.push_back(nums[pos]);
        dfs(ret, nums, temp, pos+1);
        temp.pop_back();
        dfs(ret, nums, temp, pos+1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> temp;
        dfs(ret, nums, temp, 0);
        return ret;
    }
};

#endif /* _8_subsets_h */
