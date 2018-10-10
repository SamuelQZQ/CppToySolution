// https://leetcode.com/problems/trapping-rain-water/description/
//  42-trapping-rain-water.h
//  CppToySolution
//
//  Created by QZQ on 10/10/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef _2_trapping_rain_water_h
#define _2_trapping_rain_water_h
class Solution {
    // case1: height数组只有一个或0个？
    // case2: 最高点有多个？
public:
    int trap(vector<int>& height) {
        int maxHeight = -1, maxIndex = -1;
        int len = height.size();
        if(0 == len) return 0;
        
        for(int i = 0; i < len; ++i)
        {
            if(height[i] > maxHeight)
            {
                maxHeight = height[i];
                maxIndex = i;
            }
        }
        
        int ret = 0;

        int leftWall = height[0];
        for(int i = 1; i <= maxIndex; ++i)
        {
            if(height[i] >= leftWall)
            {
                leftWall = height[i];
            }
            else
            {
                ret += leftWall - height[i];
            }
        }
        
        leftWall = height[len-1];
        for(int i = len-2; i >= maxIndex; --i)
        {
            if(height[i] >= leftWall)
            {
                leftWall = height[i];
            }
            else
            {
                ret += leftWall - height[i];
            }
        }
        
        return ret;
    }
};

#endif /* _2_trapping_rain_water_h */
