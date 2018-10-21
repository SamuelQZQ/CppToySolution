// https://leetcode.com/problems/erect-the-fence/description/
//  587-erect-the-fence.h
//  CppToySolution
//
//  Created by QZQ on 21/10/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef _87_erect_the_fence_h
#define _87_erect_the_fence_h
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
// 求凸包
class Solution {
public:
    // 1个点，2个点的情况？
    vector<Point> outerTrees(vector<Point>& points) {
        int len = points.size();
        if(len <= 2) return points;
        int minIndex = 0;
        for(int i = 1; i < len; ++i)
        {
            if(points[i].y < points[minIndex].y) minIndex = i;
            else if(points[i].y == points[minIndex].y
                    && points[i].x < points[minIndex].x) minIndex = i;
        }
        
        swap(points[0], points[minIndex]);
        
        sort(++points.begin(), points.end(), [&](Point a, Point b){
            int dy1 = a.y - points[0].y;
            int dy2 = b.y - points[0].y;
            int dx1 = a.x - points[0].x;
            int dx2 = b.x - points[0].x;
            if(atan2(dy1, dx1) < atan2(dy2, dx2)) return true;
            else if(atan2(dy1, dx1) > atan2(dy2, dx2)) return false;
            else return dy1*dy1 + dx1*dx1 < dy2*dy2 + dx2*dx2;
        });
        
        // ！！！最后一条边需要从远到近排序
        auto it = points.end();
        it--;
        while(it != points.begin())
        {
            it--;
            Point a = *it;
            Point b = points.back();
            int dy1 = a.y - points[0].y;
            int dy2 = b.y - points[0].y;
            int dx1 = a.x - points[0].x;
            int dx2 = b.x - points[0].x;
            if(atan2(dy1, dx1) != atan2(dy2, dx2)) break;
        }
        it++;
        reverse(it, points.end());
        
        int pos = 0;
        vector<Point> ret;
        ret.push_back(points[pos++]);
        ret.push_back(points[pos++]);
        while(pos < len)
        {
            Point p2 = points[pos];
            Point p1 = ret[ret.size()-1];
            Point p0 = ret[ret.size()-2];
            int dy1 = p1.y - p0.y;
            int dx1 = p1.x - p0.x;
            int dy2 = p2.y - p0.y;
            int dx2 = p2.x - p0.x;
            while(dx1 * dy2 - dy1 * dx2 < 0)
            {
                ret.pop_back();
                p1 = ret[ret.size()-1];
                p0 = ret[ret.size()-2];
                dy1 = p1.y - p0.y;
                dx1 = p1.x - p0.x;
                dy2 = p2.y - p0.y;
                dx2 = p2.x - p0.x;
            }
            
            ret.push_back(points[pos++]);
        }
        
        return ret;
    }
};

#endif /* _87_erect_the_fence_h */
