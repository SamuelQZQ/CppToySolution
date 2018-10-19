// https://leetcode.com/problems/minimum-path-sum/description/
//  64-minimum-path-sum.h
//  CppToySolution
//
//  Created by QZQ on 19/10/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef _4_minimum_path_sum_h
#define _4_minimum_path_sum_h
class Solution {
public:
    const int INF = 123456789;
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(); if(!n) return 0;
        int m = grid[0].size(); if(!m) return 0;
        
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(0 == i && j == 0) continue;
                int temp = grid[i][j];
                grid[i][j] = INF;
                if(i-1 >= 0) grid[i][j] = min(grid[i][j], grid[i-1][j] + temp);
                if(j-1 >= 0) grid[i][j] = min(grid[i][j], grid[i][j-1] + temp);
            }
        }
        
        return grid[n-1][m-1];
        
    }
};

#endif /* _4_minimum_path_sum_h */
