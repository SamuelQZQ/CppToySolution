//
//  main.cpp
//  CppToySolution
//
//  Created by QZQ on 16/09/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//


#include <list>
#include <map>
#include <iostream>
#include <vector>
using namespace std;

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
        if(l.left == l.sum && r.left > 0) left += r.left;
        
        int right = r.right;
        if(r.right == r.sum && l.right > 0) right += l.right;
        
        int sum = l.sum + r.sum;
        
        int maxx = max(l.maxx, r.maxx);
        if(l.right + r.left > maxx) maxx = l.right + r.left;
        
        nums.back();
        cout<<s<<','<<len<<','<<left<<','<<right<<','<<maxx<<','<<sum<<endl;
        return node(left, right, maxx, sum);
        
    }
    
    int maxSubArray(vector<int>& nums) {
        node temp = calc(nums, 0, nums.size());
        return temp.maxx;
    }
};

int main()
{
    Solution s;
    vector<int> a{1,2,-1,-2,2,1,-2,1,4,-5,4};
    cout<<s.maxSubArray(a)<<endl;
    return 0;
}
