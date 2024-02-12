#include "solutions.h"
#include <numeric>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <queue>
#include <boost/lexical_cast.hpp>

namespace leetcode {

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

int maxDepth(TreeNode* root) {
    if(root == nullptr) return 0;
    return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
}
/*
Input: root = [3,9,20,null,null,15,7]
Output: 3
*/


bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == nullptr && q == nullptr) return true;

    if(p == nullptr || q == nullptr) return false;

    if(p->val == q->val) return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

    return false;
}
/*
Input: p = [1,2,3], q = [1,2,3]
Output: true
*/


TreeNode* invertTree(TreeNode* root) {
    if(root) {
        invertTree(root->left);
        invertTree(root->right);
        std::swap(root->left, root->right);
    }
    return root;
}
/*
Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]
*/


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int index = 0;
    return helper(preorder, inorder, index, 0, inorder.size() - 1);
}

TreeNode* helper(const std::vector<int>& preorder, const std::vector<int>& inorder, int& index, int left, int right) {
    if(left > right) return nullptr;

    int pivot = left;
    while(inorder[pivot] != preorder[index]) pivot++;
    ++index;

    TreeNode* root = new TreeNode(inorder[pivot]);
    root->left = helper(preorder, inorder, index, left, pivot - 1);
    root->right = helper(preorder, inorder, index, pivot+1, right);
    return root;
}
/*
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
*/


TreeNode* buildTreeII(vector<int>& inorder, vector<int>& postorder) {
    //std::reverse(postorder.begin(), postorder.end());
    int index = postorder.size() - 1;
    return helper(inorder, postorder, index, 0, inorder.size() - 1);
}

TreeNode* helper(const std::vector<int>& inorder, const std::vector<int>& postorder, int& index, int left, int right) {
    if(left > right) return nullptr;

    TreeNode* node = new TreeNode(postorder[index--]);
    int pivot = left;
    for(pivot = left; pivot <= right; pivot++){
        if(node->val == inorder[pivot]){
            break;
        }
    }

    node->right = helper(inorder, postorder, index, pivot+1, right);
    node->left = helper(inorder, postorder, index, left, pivot - 1);

    return node;
}
/*
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
*/


Node* connect(Node* root) {
    if (!root) return root;

    std::queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(q.size()>1) {
        Node* cur = q.front();
        q.pop();

        if(!cur) {
            q.push(NULL);
            continue;
        }

        cur->next = q.front();

        if(cur->left) q.push(cur->left);
        if(cur->right) q.push(cur->right);
    }
    return root;
}
/*
Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
*/

} /* namespace leetcode */
