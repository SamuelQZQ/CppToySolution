// https://leetcode.com/problems/unique-paths/description/
//  62-unique-paths.h
//  CppToySolution
//
//  Created by QZQ on 19/10/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef _2_unique_paths_h
#define _2_unique_paths_h
// ans is equal to C(m+n-2, m-1)
// but 200! >> MAX_INT
class Solution2 {
public:
    int dp[105][105];
    int uniquePaths(int m, int n) {
        dp[0][0] = 1;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
            {
                if(0 != i && 0 != j) dp[i][j] = 0;
                if(i - 1 >= 0) dp[i][j] += dp[i-1][j];
                if(j - 1 >= 0) dp[i][j] += dp[i][j-1];
            }
        
        return dp[n-1][m-1];
    }
};


#endif /* _2_unique_paths_h */
