//
//  main.cpp
//  CppToySolution
//
//  Created by QZQ on 16/09/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//


#include <list>
#include <vector>
#include <iostream>
using namespace std;
void dfs(list<int> &lis, vector<int> &temp, vector<vector<int> > &ret)
{
    if(lis.empty())
    {
        ret.push_back(temp);
        return;
    }
    
    for(auto it = lis.begin(); it != lis.end(); ++it)
    {
        int val = *it;
        temp.push_back(val);
        
        auto pos = lis.erase(it);
        dfs(lis, temp, ret);
        
        temp.pop_back();
        lis.insert(pos, val);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    list<int> lis;
    for(auto it = nums.begin(); it != nums.end(); ++it) {
        lis.push_back(*it);
    }
    
    vector<vector<int> > ret;
    vector<int> temp;
    dfs(lis, temp, ret);
    return ret;
}

int main() {
    vector<int> a{1,2,3};
    auto ret = permute(a);
    for(auto p: ret)
    {
        for(auto q: p)
        {
            cout<<q<<endl;
        }
    }
    return 0;
}
