#include "solutions.h"

#include <numeric>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <queue>
#include <boost/lexical_cast.hpp>

namespace leetcode {

using namespace std;

void backtrack(std::string digits, std::string & combination, int index, \
    std::vector<std::string>& letter, std::vector<std::string>& result) {

    if(index == digits.length()) { 
        result.push_back(combination);
        return;
    } 
        
    for(char c : letter[digits[index] - '0']) {
        combination.push_back(c);
        backtrack(digits, combination, index + 1, letter, result);
        combination.pop_back();
    }
}

vector<string> Solutions::letterCombinations(string digits) {
    std::vector<std::string> result;

    if(digits.empty()) return result;

    std::vector<std::string> letter = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", \
                                        "tuv", "wxyz"};

    std::string combination = "";
    
    backtrack(digits, combination, 0, letter, result);

    return result;                        
}
/*
Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
*/

void backtrack(int n, int k, std::vector<int>& combination, int start, std::vector<std::vector<int>>& result) {
    if(combination.size() == k) {
        result.push_back(combination);
        return;
    }

    for(int i = start; i <= n; i++) {
        combination.push_back(i);
        backtrack(n, k, combination, i + 1, result);
        combination.pop_back();
    }
}

vector<vector<int>> Solutions::combine(int n, int k) {
    std::vector<std::vector<int>> result;
    std::vector<int> combination;

    backtrack(n, k, combination, 1, result);
    return result;
}
/*
Example 1:

Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
*/

void backtrack(std::vector<int> nums, int i, std::vector<std::vector<int>>& ans) {
    
    if(i == nums.size()) {
        ans.push_back(nums);
        return;
    }

    for(int j = i; j < nums.size(); j++) {
        std::swap(nums[i], nums[j]);
        backtrack(nums, i + 1, ans);
        std::swap(nums[i], nums[j]); // backtracking 
    }
}

vector<vector<int>> Solutions::permute(vector<int>& nums) {
    std::vector<std::vector<int>> ans;
    backtrack(nums, 0, ans);
    return ans;
}
/*
Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

void backtrack(std::vector<int> & candidates, int target, std::vector<int>& combination, \
int index, std::vector<std::vector<int>>& result) {
    
    if(target < 0) return;

    if(target == 0) {
        result.push_back(combination);
        return;
    }

    for(int i = index; i < candidates.size(); i ++) {
        combination.push_back(candidates[i]);
        backtrack(candidates, target - candidates[i], combination, i, result);
        combination.pop_back();
    }

}

vector<vector<int>> Solutions::combinationSum(vector<int>& candidates, int target) {
    std::vector<std::vector<int>> result;
    std::vector<int> combination;

    backtrack(candidates, target, combination, 0, result);

    return result;
}
/*
Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
*/

bool is_safe( vector< string> & board, int row, int col)
{
    // check column
    for (int i = row; i >= 0; --i) 
        if(board[i][col] == 'Q') return false;
    
    // check left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
        if(board[i][j] == 'Q') return false;
    
    // check right diagonal
    for (int i = row, j = col;  i >= 0 && j < board.size(); --i, ++j)
        if(board[i][j] == 'Q') return false;
    
    return true;
}

void backtracking_dfs( vector< string> & board, int row, int & ans)
{
    if ( row == board.size()) {
        ans ++;
        return;
    }

    for (int i = 0; i < board.size(); ++i) {
        if(is_safe(board, row, i)) {
            // make decision
            board[row][i] = 'Q';
            backtracking_dfs(board, row + 1, ans);
            board[row][i] = '.';
        }
    } 
}

int Solutions::totalNQueens(int n) {

    int ans = 0;
    vector< string> board(n, string(n, '.'));

    backtracking_dfs(board, 0, ans);

    return ans; 
}
/*
Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
*/

void backtrack(int n, int left, int right, string combination, vector<string>& result) {
    if(combination.length() == 2*n) {
        result.push_back(combination);
        return;
    }

    if(left < n)
        backtrack(n, left + 1, right, combination + "(", result);

    if(right < left)
        backtrack(n, left, right + 1, combination + ")", result);
}

vector<string> Solutions::generateParenthesis(int n) {
    vector<string> result;
    string combination = "";

    backtrack(n, 0, 0, combination, result);

    return result;
}
/*
Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
*/

bool backtrack(vector<vector<char>>& board, string word, int n , int m , \
int row, int col, int index) {
    if(index == word.size()) return true;

    if(row < 0 || col < 0 | row >=n || col >= m || board[row][col] != word[index])
        return false;

    char temp = board[row][col];
    board[row][col] = '*';
    bool ans1 = backtrack(board, word, n, m, row+1, col, index + 1);
    bool ans2 = backtrack(board, word, n, m, row, col+1, index + 1);
    bool ans3 = backtrack(board, word, n, m, row-1, col, index + 1);
    bool ans4 = backtrack(board, word, n, m, row, col-1, index + 1);
    board[row][col] = temp;

    return ans1 || ans2 || ans3 || ans4;
}

bool Solutions::exist(vector<vector<char>>& board, string word) {
    int n = board.size(), m = board[0].size();

    for(int i = 0; i < n ; i ++) {
        for(int j = 0; j < m ; j ++) {
            if(backtrack(board, word, n, m, i, j, 0))
                return true;
        }
    }

    return false;
}
/*
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
*/

void backtracking_dfs( std::vector< std::string> & board, int row, std::vector< std::vector< std::string> > & result)
{
    if ( row == board.size()) {
        result.push_back(board);
        return;
    }

    for (int i = 0; i < board.size(); ++i) {
        if(is_safe(board, row, i)) {
            // make decision
            board[row][i] = 'Q';
            backtracking_dfs(board, row + 1, result);
            // backtrack to move our queen to next col within same row to get other combinations.
            board[row][i] = '.';
        }

    } 
}

std::vector< std::vector< std::string> > Solutions::solveNQueens(int n) {

    if ( n <= 0 ) return {{}};

    std::vector< std::vector< std::string> > result;
    std::vector< std::string> board(n, std::string(n, '.'));

    backtracking_dfs(board, 0, result);

    return result;
}
/*
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
*/

} /* namespace leetcode */