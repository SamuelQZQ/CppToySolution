// https://leetcode.com/problems/median-of-two-sorted-arrays/description/
//  4-median-of-two-sorted-arrays.h
//  CppToySolution
//
//  Created by QZQ on 22/09/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef __median_of_two_sorted_arrays_h
#define __median_of_two_sorted_arrays_h
// 1. O(log(max(n,m))) solution
class Solution {
public:
    bool IsBigger(vector<int>& v1, int ind1, vector<int>& v2, int ind2) {
        if(ind1 >= static_cast<long long>(v1.size())) {
            if(ind2 < static_cast<long long>(v2.size())) return true;
            else return false;
        }
        else if(ind1 < 0) {
            return false;
        }
        else if(ind2 >= static_cast<long long>(v2.size())) {
            return false;
        }
        else if(ind2 < 0) {
            return true;
        }
        else return v1[ind1] > v2[ind2];
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& vecA = nums1.size() < nums2.size() ? nums1 : nums2;
        vector<int>& vecB = nums1.size() < nums2.size() ? nums2 : nums1;
        int lenA = vecA.size(), lenB = vecB.size();
        int leftNumber = (lenA+lenB+1) / 2;
        
        double ans = 0;
        int l = 0, r = lenA;
        while(l <= r)
        {
            int posA = (l+r) / 2; // [0, lenA]
            int posB = leftNumber - posA; // [0, lenB]
            if(IsBigger(vecB, posB-1, vecA, posA)) l = posA+1;
            else if(IsBigger(vecA, posA-1, vecB, posB)) r = posA-1;
            else
            {
                if(IsBigger(vecA, posA-1, vecB, posB-1)) ans += vecA[posA-1];
                else ans += vecB[posB-1];
                
                if((lenA+lenB) % 2 == 0)
                {
                    if(IsBigger(vecB, posB, vecA, posA)) ans += vecA[posA];
                    else ans += vecB[posB];
                    ans /= 2;
                }
                break;
            }
        }
        return ans;
    }
};

// 2. O(n) solution
class Solution2 {
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
