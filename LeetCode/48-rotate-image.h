// https://leetcode.com/problems/rotate-image/description/
//  48-rotate-image.h
//  CppToySolution
//
//  Created by QZQ on 14/10/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef _8_rotate_image_h
#define _8_rotate_image_h
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // x = j
        // y = lenY - 1 - j
        vector<vector<int>> temp = matrix;
        int lenX = matrix.size(), lenY = matrix[0].size();
        for(int i = 0; i < lenX; ++i)
        {
            for(int j = 0; j < lenY; ++j)
                matrix[j][lenY-1-i] = temp[i][j];
        }
    }
};

#endif /* _8_rotate_image_h */
