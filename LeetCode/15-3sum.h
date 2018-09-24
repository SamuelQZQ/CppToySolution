// https://leetcode.com/problems/3sum/description/
//  15-3sum.h
//  CppToySolution
//
//  Created by QZQ on 24/09/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef _5_3sum_h
#define _5_3sum_h
// O(n^2) double pointer
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ret;
        int len = nums.size();
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i < len; ++i)
        {
            int a = nums[i];
            if(i > 0 && a == nums[i-1]) continue;
            for(int j = i+1, k = len-1; j < k;)
            {
                int b = nums[j], c = nums[k];
                int temp = a + b + c;
                if(temp == 0)
                {
                    vector<int> vec({a, b, c});
                    ret.push_back(vec);
                    while(j < len && b == nums[j]) j++;
                    while(k >= 0  && c == nums[k]) k--;
                }
                else if(temp < 0) j++;
                else if(temp > 0) k--;
            }
        }
        
        return ret;
    }
};


// O(n^2log(n))
class Solution2 {
public:
    
    void adjust(vector<int> &vec)
    {
        int &a = vec[0];
        int &b = vec[1];
        int &c = vec[2];
        if(a > b) swap(a,b);
        if(a > c) swap(a,c);
        if(b > c) swap(b,c);
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int> > st;
        map<int, int>mp;
        
        int len = nums.size();
        for(int i = 0; i < len; ++i)
        {
            if(mp.find(nums[i]) == mp.end())
                mp[nums[i]] = 0;
            mp[nums[i]] ++;
        }
        
        for(int i = 0; i < len; ++i)
        {
            mp[nums[i]]--;
            for(int j = 0; j < i; ++j)
            {
                if(mp.find(-nums[i]-nums[j]) != mp.end() && mp[-nums[i]-nums[j]] > 0)
                {
                    vector<int> temp({nums[i] , nums[j],  -nums[i]-nums[j]});
                    adjust(temp);
                    st.insert(temp);
                }
            }
        }
        
        vector<vector<int> > ret;
        for(auto it = st.begin(); it != st.end(); ++it)
        {
            ret.push_back(*it);
        }
        return ret;
    }
};

#endif /* _5_3sum_h */
