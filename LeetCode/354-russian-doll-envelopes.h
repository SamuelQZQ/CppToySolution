// https://leetcode.com/problems/russian-doll-envelopes/description/
//  354-russian-doll-envelopes.h
//  CppToySolution
//
//  Created by QZQ on 11/10/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef _54_russian_doll_envelopes_h
#define _54_russian_doll_envelopes_h
class Solution {
public:
    int lowbit(int x) {return x & (-x);}
    void update(vector<int> &tree, int pos, int val)
    {
        while(pos < tree.size())
        {
            if(val > tree[pos]) tree[pos] = val;
            pos += lowbit(pos);
        }
    }
    int get(vector<int> &tree, int pos)
    {
        int ret = 0;
        while(pos > 0)
        {
            if(ret < tree[pos]) ret = tree[pos];
            pos -= lowbit(pos);
        }
        return ret;
    }
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int ret = 0, len = envelopes.size();
        
        sort(envelopes.begin(), envelopes.end());
        
        map<int, int> indexMap;
        for(int i = 0; i < len; ++i) indexMap[envelopes[i].second] = 0;
        int count = 0;
        for(auto it = indexMap.begin(); it != indexMap.end(); ++it ) {
            it->second = ++count;
        }
        for(int i = 0; i < len; ++i) {
            envelopes[i].second = indexMap[envelopes[i].second];
        }

        vector<int> tree(count+1);
        vector<int> ans(len);
        
        int j = 0;
        for(int i = 0; i < len; ++i)
        {
            int temp = get(tree, envelopes[i].second - 1) + 1;
            ans[i] = temp;
            
            if(i+1 < len && envelopes[i].first < envelopes[i+1].first)
            {
                while(j <= i)
                {
                    update(tree, envelopes[j].second, ans[j]);
                    j++;
                }
            }
            if(temp > ret) ret = temp;
        }
        return ret;
    }
};

#endif /* _54_russian_doll_envelopes_h */
