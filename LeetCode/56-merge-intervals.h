// https://leetcode.com/problems/merge-intervals/description/
//  56-merge-intervals.h
//  CppToySolution
//
//  Created by QZQ on 18/10/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef _6_merge_intervals_h
#define _6_merge_intervals_h
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class Solution {
public:
    
    vector<Interval> merge(vector<Interval>& intervals) {
        
        int len = intervals.size();
        if(len <= 1) return intervals;
        
        sort(intervals.begin(), intervals.end(), [](const Interval a, const Interval b)
        {
            if(a.start < b.start) return true;
            else return a.end < b.end;
        });
        
        for(int i = 1; i < len; ++i)
        {
            if(intervals[i-1].end >= intervals[i].start)
            {
                intervals[i].start = intervals[i-1].start;
                intervals[i].end = max(intervals[i-1].end, intervals[i].end);
            }
        }
        
        vector<Interval> ret;
        for(int i = 0; i < len-1; ++i)
        {
            if(intervals[i].end < intervals[i+1].start) ret.push_back(intervals[i]);
        }
        
        ret.push_back(intervals[len-1]);
        return ret;
    }
};

#endif /* _6_merge_intervals_h */
