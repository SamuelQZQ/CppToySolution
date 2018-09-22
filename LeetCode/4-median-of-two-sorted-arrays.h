// https://leetcode.com/problems/median-of-two-sorted-arrays/description/
//  4-median-of-two-sorted-arrays.h
//  CppToySolution
//
//  Created by QZQ on 22/09/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef __median_of_two_sorted_arrays_h
#define __median_of_two_sorted_arrays_h
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        bool isEven = (len1+len2)%2 ? false : true;
        int ansPos = (len1+len2+1) / 2;
        ansPos--;
        
        int p1 = 0, p2 = 0;
        double ans = 0;
        while(ansPos)
        {
            if(p1 < len1 && p2 < len2)
            {
                if(nums1[p1] > nums2[p2]) p2++;
                else p1++;
            }
            else if(p1 == len1) p2++;
            else p1++;
            
            ansPos--;
        }
        
        if(p1 < len1 && p2 < len2)
        {
            if(nums1[p1] > nums2[p2]) ans+=nums2[p2++];
            else ans+=nums1[p1++];
        }
        else if(p1 == len1) ans+=nums2[p2++];
        else ans+=nums1[p1++];
        
        if(isEven)
        {
            if(p1 < len1 && p2 < len2)
            {
                if(nums1[p1] > nums2[p2]) ans+=nums2[p2++];
                else ans+=nums1[p1++];
            }
            else if(p1 == len1) ans+=nums2[p2++];
            else ans+=nums1[p1++];
            
            ans/=2;
        }
        
        return ans;
    }
};

#endif /* __median_of_two_sorted_arrays_h */
