#include "solutions.h"
#include <numeric>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <queue>
#include <boost/lexical_cast.hpp>

namespace leetcode {

using namespace std;



void dfsTravel(TreeNode* root, int& prev, int& ans){
    if (root == nullptr) return;

    dfsTravel(root->left, prev, ans);

    if (prev != -1) ans = std::min(ans, root->val - prev);
    prev = root->val;

    dfsTravel(root->right, prev, ans);
}

int Solutions::getMinimumDifference(TreeNode* root) {
    int ans = INT_MAX, prev = -1;

    dfsTravel(root, prev, ans);

    return ans;
}
/*
Input: root = [4,2,6,1,3]
Output: 1
*/

void dfsTravel(TreeNode* root, std::vector<int>& smallnodes) {
    if (root == nullptr) return;
    
    dfsTravel(root->left, smallnodes);
    smallnodes.push_back(root->val);
    dfsTravel(root->right, smallnodes);
}

int Solutions::kthSmallest(TreeNode* root, int k) {
    std::vector<int> smallnodes;

    dfsTravel(root, smallnodes);
    return smallnodes[k-1];
}
/*
Input: root = [3,1,4,null,2], k = 1
Output: 1
*/

bool bfsTravel(TreeNode* root, int* left, int* right) {
    if(root == nullptr) return true;

    if(right && root->val >= *right) return false;

    if(left && root->val <= *left) return false;

    return bfsTravel(root->left, left, &(root->val)) && bfsTravel(root->right, &(root->val), right);
}

bool Solutions::isValidBST(TreeNode* root) {
    return bfsTravel(root, nullptr, nullptr);
}
/*
Input: root = [2,1,3]
Output: true
*/

TreeNode* Solutions::deleteNode(TreeNode* root, int key) {
    if (root == nullptr ) return nullptr;

    if ( key == root->val) {
        if( root->left == nullptr && root->right == nullptr) {
            return nullptr;
        } else if (root->left == nullptr || root->right == nullptr) {
            if (root->left == nullptr) {
                root = root->right;
            } else {
                root = root->left;           
            }
        } else {
            // remove Min node from left side
            TreeNode* tmp = root->left;

            while(tmp->right != nullptr) tmp = tmp->right;

            root->val = tmp->val;
            root->left = deleteNode(root->left, root->val); // reconstruct tree
        }
    }

    if ( key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    }

    return root;   
}
/*
Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.
*/

TreeNode* Solutions::searchBST(TreeNode* root, int val) {
    if (root == NULL || root->val == val) return root;

    if (root->val >= val) 
        return searchBST(root->left, val);
    
    return searchBST(root->right, val);
}
/*
Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]
*/

} /* namespace leetcode */
