// https://leetcode.com/problems/maximum-subarray/description/
//  maximum-subarray.h
//  CppToySolution
//
//  Created by QZQ on 18/10/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef maximum_subarray_h
#define maximum_subarray_h
// try coding another solution using the divide and conquer approach, which is more subtle
class Solution {
public:
    struct node {
        node(int left, int right, int maxx, int sum):left(left), right(right), maxx(maxx), sum(sum) {}
        int left, right, maxx, sum;
    };
    
    node calc(vector<int>& nums, int s, int len) {
        if(len == 1) return node(nums[s], nums[s], nums[s], nums[s]);
        
        int midLen = len/2;
        node l = calc(nums, s, midLen);
        node r = calc(nums, s+midLen, len-midLen);
        
        int left = l.left;
        if(l.sum + r.left > left) left = l.sum + r.left;
        
        int right = r.right;
        if(l.right + r.sum > right) right = l.right + r.sum;
        
        int sum = l.sum + r.sum;
        
        int maxx = max(l.maxx, r.maxx);
        if(l.right + r.left > maxx) maxx = l.right + r.left;
        return node(left, right, maxx, sum);
    }
    
    int maxSubArray(vector<int>& nums) {
        node temp = calc(nums, 0, nums.size());
        return temp.maxx;
    }
};

class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        
        int len = nums.size();
        int sum = 0;
        for(int i = 0; i < len; ++i)
        {
            sum += nums[i];
            if(sum > ans) ans = sum;
            if(sum < 0) sum = 0;
        }
        return ans;
    }
};



#endif /* maximum_subarray_h */
