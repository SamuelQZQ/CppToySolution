//
//  94-binary-tree-inorder-traversal.h
//  CppToySolution
//
//  Created by QZQ on 20/10/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef _4_binary_tree_inorder_traversal_h
#define _4_binary_tree_inorder_traversal_h
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 非递归方法，不使用map
// 把栈中的每个结点，当做（根节点+右子树）
// 栈始终维护着所有还没print出来的结点
class Solution {
public:
    void insertRoot(TreeNode* root, vector<TreeNode *> &stack)
    {
        stack.push_back(root);
        while(root->left)
        {
            root = root->left;
            stack.push_back(root);
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<TreeNode *> stack;
        vector<int> ret;
        if(NULL == root) return ret;
        
        insertRoot(root, stack);
        
        while(0 != stack.size())
        {
            TreeNode *p = stack.back();
            stack.pop_back();
            
            ret.push_back(p->val);
            if(p->right) insertRoot(p->right, stack);
        }
        
        return ret;
    }
};

// 非递归方法，但用了map
class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        unordered_map<TreeNode *, bool> vis;
        vector<TreeNode *> stack;
        vector<int> ret;
        if(NULL == root) return ret;
        
        stack.push_back(root);
        while(0 != stack.size())
        {
            TreeNode *p = stack.back();
            stack.pop_back();
            
            if(vis.find(p) == vis.end())
            {
                vis[p] = true;
                if(p->right) stack.push_back(p->right);
                stack.push_back(p);
                if(p->left) stack.push_back(p->left);
            }
            else
            {
                ret.push_back(p->val);
            }
            
        }
        
        return ret;
    }
};



#endif /* _4_binary_tree_inorder_traversal_h */
