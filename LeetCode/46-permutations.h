// https://leetcode.com/problems/permutations/description/
//  46-permutations.h
//  CppToySolution
//
//  Created by QZQ on 13/10/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef _6_permutations_h
#define _6_permutations_h
// a elegant solution from network~
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        
        permuteRecursive(num, 0, result);
        return result;
    }
    
    // permute num[begin..end]
    // invariant: num[0..begin-1] have been fixed/permuted
    void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)    {
        if (begin >= num.size()) {
            // one permutation instance
            result.push_back(num);
            return;
        }
        
        for (int i = begin; i < num.size(); i++) {
            swap(num[begin], num[i]);
            permuteRecursive(num, begin + 1, result);
            // reset
            swap(num[begin], num[i]);
        }
    }
};


// my solution
class Solution2 {
public:
    void dfs(vector<int> &nums, vector<int> &vis, vector<int> &temp, vector<vector<int> > &ret, int cnt)
    {
        if(cnt == nums.size())
        {
            ret.push_back(temp);
            return;
        }
        
        for(int i = 0; i < nums.size(); ++i)
        {
            if(vis[i]) continue;
            vis[i] = 1;
            temp.push_back(nums[i]);

            dfs(nums, vis, temp, ret, cnt+1);
            
            temp.pop_back();
            vis[i] = 0;
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int> > ret;
        vector<int> temp, vis(nums.size());
        for(auto p: vis) p = 0;
        
        dfs(nums, vis, temp, ret, 0);
        return ret;
    }
};

#endif /* _6_permutations_h */
