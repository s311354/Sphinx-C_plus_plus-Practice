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

void dfsTravel(TreeNode* root, int k, std::vector<int>& smallnodes) {
    if (root == nullptr) return;
    
    dfsTravel(root->left, k, smallnodes);
    smallnodes.push_back(root->val);
    dfsTravel(root->right, k, smallnodes);
}

int Solutions::kthSmallest(TreeNode* root, int k) {
    std::vector<int> smallnodes;
    dfsTravel(root, k, smallnodes);
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

} /* namespace leetcode */
