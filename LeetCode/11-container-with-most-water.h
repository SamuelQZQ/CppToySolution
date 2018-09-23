// https://leetcode.com/problems/container-with-most-water/description/
//  11-container-with-most-water.h
//  CppToySolution
//
//  Created by QZQ on 23/09/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef _1_container_with_most_water_h
#define _1_container_with_most_water_h
// O(n)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int l = 0, r = height.size()-1;
        while(l < r)
        {
            int temp = (r-l) * min(height[l], height[r]);
            if(temp > ans) ans = temp;
            
            if(height[l] < height[r]) l++;
            else r--;
        }
        return ans;
    }
};

// O(nlog(n))
class Solution2 {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        vector<pair<int, int> >orderHeight2;
        
        int lst = 0;
        orderHeight2.push_back(make_pair(height[0], 0));
        for(int i = 1; i < len; ++i)
        {
            if(height[i] > height[lst])
            {
                orderHeight2.push_back(make_pair(height[i], i));
                lst = i;
            }
        }
        
        int ans = 0;
        // case1
        lst = 0;
        pair<int, int> now = orderHeight2[lst];
        for(int i = 1; i < len; ++i)
        {
            if(lst+1 < orderHeight2.size())
            {
                pair<int, int> nxt = orderHeight2[lst+1];
                if((i-now.second)*now.first < (i-nxt.second)*nxt.first) lst++;
                now = orderHeight2[lst];
            }
            
            int tempAns = (i-now.second)*now.first;
            if(height[i] < now.first)
            {
                auto it = upper_bound(orderHeight2.begin(), orderHeight2.end(), make_pair(height[i], len));
                if(it == orderHeight2.begin()) continue;
                else it--;
                tempAns = (i-it->second)*it->first;
            }
            if(tempAns > ans) ans = tempAns;
        }
        
        // case2
        vector<pair<int, int> > orderHeight(len);
        for(int i = 0; i < len; ++i) orderHeight[i] = make_pair(height[i], i);
        sort(orderHeight.begin(), orderHeight.end());
        reverse(orderHeight.begin(), orderHeight.end());
        
        lst = orderHeight[0].second;
        for(int i = 1; i < len; ++i)
        {
            int tempAns = (orderHeight[i].second-lst) * orderHeight[i].first;
            if(tempAns > ans) ans = tempAns;
            if(orderHeight[i].second < lst) lst = orderHeight[i].second;
        }
        
        return ans;
    }
};
#endif /* _1_container_with_most_water_h */
