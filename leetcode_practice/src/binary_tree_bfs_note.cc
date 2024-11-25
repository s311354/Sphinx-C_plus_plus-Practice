#include "solutions.h"
#include <numeric>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <queue>
#include <boost/lexical_cast.hpp>

namespace leetcode {

using namespace std;


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

void dfsTravel(TreeNode* root,int depth, std::vector<int>& ans) {
    if(root == nullptr) return;
    
    if(ans.size() == depth) {
        ans.push_back(root->val);
    }

    dfsTravel(root->right, depth+1, ans);
    dfsTravel(root->left, depth+1, ans);
}

vector<int> Solutions::rightSideView(TreeNode* root) {
    std::vector<int> ans;

    dfsTravel(root, 0, ans);

    return ans;
}
/*
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
*/

void dfsTravel(TreeNode* root, int depth, std::vector<int>& count,std::vector<double>& sum) {
    if(root == nullptr) return;

    if(count.size() <= depth) count.push_back({});

    if(sum.size() <= depth) sum.push_back({});

    count[depth] ++;
    sum[depth] += root->val;
    dfsTravel(root->left, depth + 1, count, sum);
    dfsTravel(root->right, depth + 1, count, sum);
}

vector<double> Solutions::averageOfLevels(TreeNode* root) {
    std::vector<int> count;
    std::vector<double> ans;

    dfsTravel(root, 0, count, ans);

    for(int i = 0; i < count.size(); i++) {
        ans[i]/=count[i];
    }

    return ans;
}
/*
Input: root = [3,9,20,null,null,15,7]
Output: [3.00000,14.50000,11.00000]
Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
Hence return [3, 14.5, 11].
*/

void dfsTravel(TreeNode* root, int depth, std::vector<std::vector<int>>& nodes) {
    if(root == nullptr) return;

    if(nodes.size() <= depth) nodes.push_back({});

    nodes[depth].push_back(root->val);

    dfsTravel(root->left, depth + 1, nodes);
    dfsTravel(root->right, depth + 1, nodes);
}

vector<vector<int>> Solutions::levelOrder(TreeNode* root) {
    std::vector<std::vector<int>> ans;

    dfsTravel(root, 0, ans);
    return ans;

    /* BFS traversal
    std::queue<TreeNode*> q;
    std::vector<vector<int>> result;

    if(!root) return result;

    q.push(root);

    while(!queue.empty()) {
        int level = q.size();
        std::vector<int> currentLevel;  

        for(int I = 0; I < levle; i++) {
            TreeNode* node = q.front();
            q.pop();
            currentLevel.push_back(node->val);

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }

        result.push_back(currentLevel);
    }

    return result;
    
    */
}
/*
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
*/


void dfsTravel(TreeNode* root, int depth, std::vector<std::vector<int>> & ans) {

    if (root == nullptr) return;

    if (ans.size() <= depth) ans.push_back({});

    ans[depth].push_back(root->val);

    dfsTravel(root->left, depth + 1, ans);
    dfsTravel(root->right, depth + 1, ans);
}

vector<vector<int>> Solutions::zigzagLevelOrder(TreeNode* root) {
    std::vector<std::vector<int>> ans;

    dfsTravel(root, 0, ans);

    for(int i = 1; i < ans.size(); i+=2){
        std::reverse(ans[i].begin(), ans[i].end());
    }
    return ans;
}
/*
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
*/

void dfsTravel(TreeNode* node, int level, vector<int>& sum) {
    if (!node) return;

    if(sum.size() == level) sum.push_back(node->val);
    else sum[level] += node->val;

    dfsTravel(node->left, level + 1, sum);
    dfsTravel(node->right, level + 1, sum);
}

int Solutions::maxLevelSum(TreeNode* root) {
    vector<int> sum = {INT_MIN};

    dfsTravel(root, 1, sum);

    return max_element(sum.begin(), sum.end()) - sum.begin();
}
/*
Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.
*/

Void dfsReach(vector<vector<int>>& heights, int rows, int cols, vector<vector<int>> & Reach) {
    int m = heights.size();
    int n = heights[0].size();

    reach[rows][cols] = 1;

    vector<int> directions = {-1, 0, 1, 0, -1};

    for(int i = 0; i < 4; i ++ ){
        int ni = rows + directions[i];
        int nj = cols + directions[i + 1];

        for(ni >= 0 && ni < rows && nj >=0 && nj < cols && !Reach[ni][nj]  && Reach[ni][nj] >= Reach[rows][cols]) {
               dfsReach(hieghts, ni, nj, Reach);
        }
     }
}

vector<vector<int>> Solutions::pacificAtlantic(vector<vector<int>>& heights)
{
    int m = heights.size();
    int n = heights[0].size();

    vector<vector<int>> pacificReach(m, vector<int>(n, 0));
    vector<vector<int>> atlanticReach(n, vector<int>(m, 0));

    vector<vector<int>> result;

    for(int i = 0; i < m ; i++) dfsReach(heights, i, 0, pacificReach);
    for(int i = 0; i < n; i++) dfsReach(heights,0, i, atlanticReach);

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(pacificReach[i][j] && atlanticReach[i][j]) result.push_back({i, j});
        }
    }

    return result;
}

} /* namespace leetcode */
