#include "solutions.h"
#include <numeric>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <queue>
#include <boost/lexical_cast.hpp>

namespace leetcode {

using namespace std;

vector<int> direction(int row, int next_step) {
    int x = (next_step - 1) / row;
    int y = (next_step - 1) % row;

    // flip the direction and for every even i
    if(x % 2 == 1) y = row - 1 - y;

    x = row - 1 - x;

    return {x, y};
}

int Solutions::snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size();

    queue<int> q;
    q.push(1);

    int step = 0;

    while(!q.empty()) {
        int route = q.size();

        for(int i = 0; i < route; i ++) {
            int top = q.front(); q.pop();

            if(top == n*n) return step;

            for(int i = 1; i <= 6; i ++) {
                int next_step = top + i;

                if(next_step > n * n) break;

                auto dir = direction(n, next_step);
                int row = dir[0], col = dir[1];

                if(board[row][col] != -1) next_step = board[row][col];

                if(board[row][col] != n * n + 1) {
                    q.push(next_step);
                    board[row][col] = n * n + 1;
                }
            }
        }

        step ++;
    }

    return -1;
}
/*
Input: board = [[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]
Output: 4
Explanation: 
In the beginning, you start at square 1 (at row 5, column 0).
You decide to move to square 2 and must take the ladder to square 15.
You then decide to move to square 17 and must take the snake to square 13.
You then decide to move to square 14 and must take the ladder to square 35.
You then decide to move to square 36, ending the game.
This is the lowest possible number of moves to reach the last square, so return 4.
*/

int Solutions::minMutation(string startGene, string endGene, vector<string>& bank) {
    
    std::vector<char> mut = {'A','C','G','T'};

    std::unordered_set<std::string> dict(bank.begin(),bank.end());
    
    if(dict.find(endGene) == dict.end()) return -1;
    
    int ans = 0;
    std::queue<string> q;
    q.push(startGene);
    
    while(!q.empty()) {
        int n = q.size();
        
        for(int i = 0; i < n; i++) {
            string curr = q.front(); q.pop();

            if(curr == endGene) return ans;

            dict.erase(curr);

            for(int j = 0; j < 8 ; j++) {
                char c = curr[j];

                for(int k = 0 ; k < 4; k++) {
                    curr[j] = mut[k];
            
                    if(dict.find(curr)!=dict.end())
                        q.push(curr);
                }

                curr[j] = c;
            }
        }
        ans++;
    }

    return -1;
}
/*
Example 1:

Input: startGene = "AACCGGTT", endGene = "AACCGGTA", bank = ["AACCGGTA"]
Output: 1
*/

void addNextWords(string word, unordered_set<string>& dict, queue<string>& visit) {
    
    dict.erase(word);
    
    for(int i = 0; i < word.length(); i ++) {
        char letter = word[i];

        for(int j = 0; j < 26; j ++) {
            word[i] = 'a' + j;

            if(dict.find(word) != dict.end()) {
                visit.push(word);
                dict.erase(word);
            }
        }
        word[i] = letter;
    }
}

int Solutions::ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());

    queue<string> visit;

    addNextWords(beginWord, dict, visit);

    int ans = 2;

    while(!visit.empty()) {
        int num = visit.size();

        for(int i = 0; i < num; i ++) {
            string word = visit.front();
            visit.pop();

            if(word == endWord) return ans;

            addNextWords(word, dict, visit);
        }
        ans++;
    }

    return 0;
}
/*
Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
*/


} /* namespace leetcode */