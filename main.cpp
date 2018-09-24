//
//  main.cpp
//  CppToySolution
//
//  Created by QZQ on 16/09/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ret;
        int len = nums.size();
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i < len; ++i)
        {
            int a = nums[i];
            if(i > 0 && a == nums[i-1]) continue;
            for(int j = i+1, k = len-1; j < k;)
            {
                int b = nums[j], c = nums[k];
                int temp = a + b + c;
                if(temp == 0)
                {
                    vector<int> vec({a, b, c});
                    ret.push_back(vec);
                    while(j < len && b == nums[j]) j++;
                    while(k >= 0  && c == nums[k]) k--;
                }
                else if(temp < 0) j++;
                else if(temp > 0) k--;
            }
        }
        
        return ret;
    }


int main(int argc, const char * argv[]) {
    vector<int> temp({-4, -1, -1, 0, 1, 2});
    threeSum(temp);
    
    return 0;
}
