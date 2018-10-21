// https://leetcode.com/problems/top-k-frequent-elements/description/
//  347-top-k-frequent-elements.h
//  CppToySolution
//
//  Created by QZQ on 21/10/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef _47_top_k_frequent_elements_h
#define _47_top_k_frequent_elements_h
class Solution {
public:
    unordered_map<int, int> freq;
    int partition(vector<int> &nums, int l, int r)
    {
        int pivot = nums[l];
        while(l < r)
        {
            while(l < r && freq[nums[r]] <= freq[pivot]) r--;
            nums[l] = nums[r];
            while(l < r && freq[nums[l]] >= freq[pivot]) l++;
            nums[r] = nums[l];
        }
        nums[l] = pivot;
        return l;
    }
    
    void topK(vector<int> &nums, int l, int r, int k)
    {
        int pivot = partition(nums, l, r);
        if(pivot - l + 1 < k) topK(nums, pivot+1, r, k-(pivot-l+1));
        else if(pivot - l + 1 == k) return;
        else topK(nums, l, pivot-1, k);
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        freq.clear();
        vector<int> candidate;
        for(auto a: nums)
        {
            if(freq.find(a) == freq.end())
            {
                freq[a] = 0;
                candidate.push_back(a);
            }
            freq[a] ++;
        }
        
        topK(candidate, 0, candidate.size()-1, k);
        while(candidate.size() > k) candidate.pop_back();
        return candidate;
    }
};

#endif /* _47_top_k_frequent_elements_h */
