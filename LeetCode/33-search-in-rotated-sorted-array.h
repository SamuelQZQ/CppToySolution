// https://leetcode.com/problems/search-in-rotated-sorted-array/description/
//  33-search-in-rotated-sorted-array.h
//  CppToySolution
//
//  Created by QZQ on 06/10/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef _3_search_in_rotated_sorted_array_h
#define _3_search_in_rotated_sorted_array_h
// 特殊情况！ nums为空
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if(!len) return -1;
        int l = 0, r = len-1, ans = -1;
        if(target > nums[len-1])
        {
            while(l <= r)
            {
                int mid = (l+r)/2;
                if(nums[mid] <= nums[len-1]) r = mid-1;
                else if(nums[mid] > target) r = mid-1;
                else if(nums[mid] < target) l = mid+1;
                else if(nums[mid] == target)
                {
                    ans = mid;
                    break;
                }
            }
        }
        else
        {
            while(l <= r)
            {
                int mid = (l+r)/2;
                if(nums[mid] > nums[len-1]) l = mid+1;
                else if(nums[mid] > target) r = mid-1;
                else if(nums[mid] < target) l = mid+1;
                else if(nums[mid] == target)
                {
                    ans = mid;
                    break;
                }
            }
        }
        return ans;
    }
};

#endif /* _3_search_in_rotated_sorted_array_h */
