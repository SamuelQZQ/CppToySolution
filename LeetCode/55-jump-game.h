// https://leetcode.com/problems/jump-game/description/
//  55-jump-game.h
//  CppToySolution
//
//  Created by QZQ on 18/10/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef _5_jump_game_h
#define _5_jump_game_h
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int far = 0;
        for(int i = 0; i < len && i <= far; ++i)
        {
            if(far >= len-1) return true;
            if(i + nums[i] > far) far = i + nums[i];
        }
        
        return false;
    }
};

#endif /* _5_jump_game_h */
