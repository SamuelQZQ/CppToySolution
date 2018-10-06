// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
//  34-find-first-and-last-position-of-element-in-sorted-array.h
//  CppToySolution
//
//  Created by QZQ on 06/10/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef _4_find_first_and_last_position_of_element_in_sorted_array_h
#define _4_find_first_and_last_position_of_element_in_sorted_array_h
// 1A~
class Solution {
public:
    // 1. nums 可不可能是空的
    // 2. 找不到target怎么办？
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1, ansl = -1, ansr = -1;
        while(l <= r)
        {
            int mid = (l+r)/2;
            if(nums[mid] > target) r = mid-1;
            else if(mid-1 >= 0 && nums[mid] == target && nums[mid-1] == target) r = mid-1;
            else if(nums[mid] < target) l = mid+1;
            else if(nums[mid] == target && (mid-1 < 0 || nums[mid-1] != target))
            {
                ansl = mid;
                break;
            }
        }
        
        l = 0, r = nums.size()-1;
        while(l <= r)
        {
            int mid = (l+r)/2;
            if(nums[mid] > target) r = mid-1;
            else if(mid+1 < nums.size() && nums[mid] == target && nums[mid+1] == target) l = mid+1;
            else if(nums[mid] < target) l = mid+1;
            else if(nums[mid] == target && (mid+1 >= nums.size() || nums[mid+1] != target))
            {
                ansr = mid;
                break;
            }
        }
        
        vector<int> ans;
        ans.push_back(ansl);
        ans.push_back(ansr);
        return ans;
    }
};

#endif /* _4_find_first_and_last_position_of_element_in_sorted_array_h */
