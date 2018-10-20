//
//  144-binary-tree-preorder-traversal.h
//  CppToySolution
//
//  Created by QZQ on 20/10/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef _44_binary_tree_preorder_traversal_h
#define _44_binary_tree_preorder_traversal_h
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 非递归方法
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<TreeNode*> stack;
        vector<int> ret;
        if(!root) return ret;
        
        stack.push_back(root);
        while(0 != stack.size())
        {
            TreeNode* p = stack.back();
            stack.pop_back();
            ret.push_back(p->val);
            if(p->right) stack.push_back(p->right);
            if(p->left) stack.push_back(p->left);
        }
        return ret;
    }
};

#endif /* _44_binary_tree_preorder_traversal_h */
