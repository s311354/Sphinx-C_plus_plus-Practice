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

/*
Overview:
Given the root of a binary tree, return its maximum depth.

Approach:
Native Approach: recursive approach 
Second Approach: …
Third Approach: …

Explanation: (Step by Step)
We try to do a recursive call and pass a left or right subtree plus 1 to itself. And find the maximum depth of BT.

Dry Run: (pseudo code)
1 + std::max(maxDepth(root->left), maxDepth(root->right))

Implementation:
...

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

/*
Overview:
Given the roots of two binary trees, and to check the nodes have the same value

Approach:
Native Approach: recursive approach 
Second Approach: …
Third Approach: …

Explanation: (Step by Step)
We try to do a recursive call and pass both of left subtree and both of right subtree to itself. And check the nodes have the same value.

Dry Run: (pseudo code)

if p == nullptr && q == nullptr true

if p == nullptr || q == nullptr false

if p->val != q->val return false

return isSameTree(p->left, q->left) && isSameTree(p->right, q->right)

Implementation:
...

*/

TreeNode* Solutions::invertTree(TreeNode* root) {
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

/*
Overview:
Given the root of a binary tree, invert the tree

Approach:
Native Approach: recursive approach 
Second Approach: …
Third Approach: …

Explanation: (Step by Step)
Step 1. We try to do a recursive call, and pass left subtree and right subtree respectively
Step 2. We swap left subtree and right subtree for each node

Dry Run: (pseudo code)

invertTree(root->left);
invertTree(root->right);

std::swap(root->left, root->right);

Implementation:
...

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

BNode* findMin(BNode* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

BNode* Solutions::findInOrderSuccessor(BNode *inputNode) {
    if (inputNode->right != nullptr) {
        return findMin(inputNode->right);
    }

    BNode *successor = nullptr;
    BNode *current = inputNode->parent;

    while (current != nullptr) {
        if (inputNode == current->left) {
            successor = current;
            break;
        }
        inputNode = current;
        current = current->parent;
    }

    return successor;
}
/*
Inorder traveler: 5->9->11->12->14->20->25
Test case1. the inorder successor of 9 is 11 
Test case2. the inorder successor of 14 is 20.
*/

/*
Overview:
Finds the inorder successor of a given node (inputNode) in a Binary Search Tree (BST). The inorder successor
 of a node is the node with the smallest key greater than the key of the input node.

Approach:
Native Approach: binary tree travel approach
Second Approach: …
Third Approach: …

Explanation: (Step by Step)
Step 1. we would try to travel right of BST to check the right subtree. 
Step 2. If BST has the right subtree, then this smallest node in right subtree is the successor.
Step 3. If BST has the no right subtree, then travel left of BST begining from the parent of input node to check the the left subtree.
If input node is same as the left subtree, then the parent of input node is the successor.
…

Dry Run: (pseudo code)
if (inputNode->right != nullptr) {
    return findMin(inputNode->right);
}

BNode *successor = nullptr;
BNode *current = inputNode->parent;

if (inputNode == current->left) {
    successor = current;
    break;
}
inputNode = current;
current = current->parent;

Implementation:
...
*/

} /* namespace leetcode */
