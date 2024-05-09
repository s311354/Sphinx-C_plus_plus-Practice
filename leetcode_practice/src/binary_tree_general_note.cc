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

int Solutions::maxDepth(TreeNode* root) {
    if(root == nullptr) return 0;
    return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
}
/*
Input: root = [3,9,20,null,null,15,7]
Output: 3
*/


bool Solutions::isSameTree(TreeNode* p, TreeNode* q) {
    if(p == nullptr && q == nullptr) return true;

    if(p == nullptr || q == nullptr) return false;

    if(p->val != q->val) return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
/*
Input: p = [1,2,3], q = [1,2,3]
Output: true
*/


TreeNode* Solutions::invertTree(TreeNode* root) {
    if(root) {
        invertTree(root->left);
        invertTree(root->right);
        std::swap(root->left, root->right);
    }
    return root;

/*
    if(!root) return nullptr;

    TreeNode* temp = root->right;
    root->left = root->right;
    root->right = temp;

    invertTree(root->left);
    invertTree(root->right);

    return root;
*/
}
/*
Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]
*/

/* HARD */
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

TreeNode* Solutions::buildTree(vector<int>& preorder, vector<int>& inorder) {
    int index = 0;
    return helper(preorder, inorder, index, 0, inorder.size() - 1);
}
/*
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
*/

TreeNode* helper(const std::vector<int>& inorder, const std::vector<int>& postorder, int& index, int left, int right) {
    if(left > right) return nullptr;

    TreeNode* node = new TreeNode(postorder[index--]);
    int pivot = left;
    for(int pivot = left; pivot <= right; pivot++){
        if(node->val == inorder[pivot]){
            break;
        }
    }

    node->right = helper(inorder, postorder, index, pivot+1, right);
    node->left = helper(inorder, postorder, index, left, pivot - 1);

    return node;
}

TreeNode* Solutions::buildTreeII(vector<int>& inorder, vector<int>& postorder) {
    //std::reverse(postorder.begin(), postorder.end());
    int index = postorder.size() - 1;
    return helper(inorder, postorder, index, 0, inorder.size() - 1);
}
/*
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
*/


Node* Solutions::connect(Node* root) {
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


void Solutions::flatten(TreeNode* root) {
    if (root == nullptr) return;

    flatten(root->left);
    flatten(root->right);

    if(root->left) {
        TreeNode * right = root->right;
        root->right = root->left;
        root->left = nullptr;

        while (root->right) root = root->right;
        root->right = right;
    }
}
/*
Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
*/


bool Solutions::hasPathSum(TreeNode* root, int targetSum) {
    if(!root) return false;

    targetSum = targetSum - root->val;

    if(targetSum == 0 && !root->left && !root->right) return true;

    return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
}
/*
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.
*/


int solve(TreeNode* root, int & ans) {
    if (!root) return 0;

    int left = std::max(0, solve(root->left, ans));
    int right = std::max(0, solve(root->right, ans));
    int val = root->val;

    ans = std::max(ans, left + right + val);
    return std::max(left, right) + val;
}

int Solutions::maxPathSum(TreeNode* root) {
    int ans = INT_MIN;
    solve(root, ans);
    return ans;
}
/*
Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
*/


class BSTIterator {
public:
    std::stack<TreeNode*> stack;

    void push(TreeNode* root) {
        // in-order traversal of binary search tree
        while(root) {
            stack.push(root);
            root = root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        push(root);
    }
    
    int next() {
        auto node = stack.top();
        stack.pop();
        push(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !stack.empty();
    }
};


int Solutions::countNodes(TreeNode* root) {
    return root == nullptr ? 0 : countNodes(root->left) + countNodes(root->right) + 1;
}
/*
Input: root = [1,2,3,4,5,6]
Output: 6
*/


TreeNode* Solutions::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root || root == p || root == q) return root;

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    return !left ? right : ! right ? left : root;
}
/*
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
*/

} /* namespace leetcode */
