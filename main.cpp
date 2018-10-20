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


// 2. one dfs but other memory usage
struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
class Solution {
public:
    struct Node
    {
        int depth;
        TreeNode* parent;
        Node(int d, TreeNode* p): depth(d), parent(p) {}
        Node() {}
    };
    
    void dfs(map<TreeNode*, Node> &nodes, TreeNode *root, int depth, TreeNode *parent)
    {
        Node node(depth, parent);
        nodes[root] = node;
        
        if(root->left) dfs(nodes, root->left, depth+1, root);
        if(root->right) dfs(nodes, root->right, depth+1, root);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        map<TreeNode*, Node> nodes;
        dfs(nodes, root, 0, NULL);
        
        while(p != q)
        {
            if(nodes[p].depth < nodes[q].depth) q = nodes[q].parent;
            else p = nodes[p].parent;
        }
        return p;
    }
};


int main()
{
    return 0;
}
