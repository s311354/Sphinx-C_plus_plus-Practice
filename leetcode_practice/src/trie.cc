#include "solutions.h"
#include <numeric>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <queue>
#include <boost/lexical_cast.hpp>

namespace leetcode {

using namespace std;

struct TrieNode {
    vector<TrieNode*> child;
    string word;
    TrieNode() : word(""), child(vector<TrieNode*>(26, nullptr)) {}
};

TrieNode* buildTrie(vector<string>& words) {
    TrieNode* root = new TrieNode();
    for (string w : words) {
        TrieNode* curr = root;
        for (char c : w) {
            int i = c - 'a';
            if (curr->child[i] == NULL) curr->child[i] = new TrieNode();
            curr = curr->child[i];
        }
        curr->word = w;
    }
    return root;
}

void dfs(vector<vector<char>>& board, int i, int j, TrieNode* curr, vector<string>& ans) {
    char c = board[i][j];
    if(c == '#' || curr->child[c - 'a'] == NULL) return;
    curr = curr->child[c - 'a'];
    if (curr->word != "") {
        ans.push_back(curr->word);
        curr->word = "";
    }
    board[i][j] = '#';
    if(i > 0) dfs(board, i - 1, j , curr, ans); 
    if(j > 0) dfs(board, i, j - 1, curr, ans);
    if(i < board.size() - 1) dfs(board, i + 1, j, curr, ans); 
    if(j < board[0].size() - 1) dfs(board, i, j + 1, curr, ans); 
    board[i][j] = c;
}

vector<string> Solutions::findWords(vector<vector<char>>& board, vector<string>& words) {
    
    vector<string> ans;
    TrieNode* root = buildTrie(words);

    for(int i = 0; i < board.size(); ++i) 
        for(int j = 0; j < board[0].size(); ++j) 
            dfs(board, i, j, root, ans);
    return ans;
}
/*
Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]
*/

} /* namespace leetcode */