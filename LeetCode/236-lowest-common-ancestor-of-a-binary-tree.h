// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
//  236-lowest-common-ancestor-of-a-binary-tree.h
//  CppToySolution
//
//  Created by QZQ on 20/10/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef _36_lowest_common_ancestor_of_a_binary_tree_h
#define _36_lowest_common_ancestor_of_a_binary_tree_h
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 1. one dfs
class Solution2 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(NULL == root || p == root || q == root) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if(NULL == left) return right;
        else if(NULL == right) return left;
        else return root;
    }
};

// 2. one dfs but other memory usage
// 注意默认构造函数很多时候会被隐含的调用到，一定要写上~
class Solution {
public:
    struct Node
    {
        int depth;
        TreeNode* parent;
        Node(int d, TreeNode* p): depth(d), parent(p) {}
        Node(){}
    };
    
    void dfs(unordered_map<TreeNode*, Node> &nodes, TreeNode *root, int depth, TreeNode *parent)
    {
        Node node(depth, parent);
        nodes[root] = node;
        
        if(root->left) dfs(nodes, root->left, depth+1, root);
        if(root->right) dfs(nodes, root->right, depth+1, root);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, Node> nodes;
        dfs(nodes, root, 0, NULL);
        
        while(p != q)
        {
            if(nodes[p].depth < nodes[q].depth) q = nodes[q].parent;
            else p = nodes[p].parent;
        }
        return p;
    }
};


#endif /* _36_lowest_common_ancestor_of_a_binary_tree_h */
