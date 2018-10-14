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
using namespace std;
int MOD = 987654321;

map<int, int> dp[2];
int mp[13][13];
int main() {
    int n, m;
    cin>> n >> m;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin>>mp[i][j];
    
    int now = 0, nxt = 1;
    dp[now][0] = 1;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
        {
            
            nxt = now ^ 1;
            dp[nxt].clear();
            
            for(auto it = dp[now].begin(); it != dp[now].end(); ++it)
            {
                int orig = it->first;
                int basic = (it->first) & (~(1 << j));
                
                int mask = basic;
                if(dp[nxt].find(mask) == dp[nxt].end()) dp[nxt][mask] = 0;
                dp[nxt][mask] = (dp[nxt][mask] + it->second) %MOD;
                
                if(mp[i][j]) //
                {
                    if(orig & (1 << j)) continue;
                    if(j-1 >= 0 && (orig & (1 << j-1))) continue;
                    mask = basic | (1<<j);
                    if(dp[nxt].find(mask) == dp[nxt].end()) dp[nxt][mask] = 0;
                    dp[nxt][mask] = (dp[nxt][mask] + it->second) %MOD;
                }
            }
            
            now ^= 1;
        }
    
    int ans = 0;
    for(auto it = dp[now].begin(); it != dp[now].end(); it ++) ans = (ans + it->second) %MOD;
    cout<<ans<<endl;
    return 0;
}
