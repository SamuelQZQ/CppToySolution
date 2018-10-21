//
//  priority_queue.cpp
//  CppToySolution
//
//  Created by QZQ on 01/10/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#include "priority_queue.hpp"
#include <queue>
#include <iostream>
using namespace std;


struct Node {
    int x, y;
};

bool operator < (const Node &a, const Node &b)
{
    if(a.x == b.x) return a.y > b.y;
    else return a.x > b.x;
}

ostream& operator << (ostream &out, const Node &a) {
    out<<a.x<<','<<a.y;
    return out;
}

void TestPriorityQueue()
{
    priority_queue<int> q1;
    q1.push(3);
    q1.push(6);
    q1.push(9);
    while(!q1.empty()) {
        cout << q1.top() << endl;
        q1.pop();
    }
    

    
    Node a{1,2};
    Node b{2,1};
    Node c{1,1};

    priority_queue<Node> q2;
    q2.push(a);
    q2.push(b);
    q2.push(c);
    while(!q2.empty()) {
        cout << q2.top() << endl;
        q2.pop();
    }
    
    priority_queue<int, vector<int>, greater<int>> q3;
    q3.push(3);
    q3.push(6);
    q3.push(9);
    while(!q3.empty()) {
        cout << q3.top() << endl;
        q3.pop();
    }
}
