#include "solutions.h"
#include <numeric>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <queue>
#include <boost/lexical_cast.hpp>

namespace leetcode {

using namespace std;

void dfsTravel(std::vector<std::vector<char>>& grid, int row, int col) {
    int m = grid.size(), n = grid[0].size();
    
    if( row < 0 || row == m || col < 0 || col == n || grid[row][col] == '0') return;

    grid[row][col] = '0';

    dfsTravel(grid, row - 1, col);
    dfsTravel(grid, row + 1, col);
    dfsTravel(grid, row, col - 1);
    dfsTravel(grid, row, col + 1);
}

int Solutions::numIslands(vector<vector<char>>& grid) {
    int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0;

    for(int i = 0; i < m; i ++) {
        for(int j = 0; j < n; j ++) {
            if(grid[i][j] == '1') {
                islands++;
                dfsTravel(grid, i, j);
            }
        }
    }

    return islands;
}
/*
Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
*/

void dfsTravel(std::vector<std::vector<char>>& board, int row, int col) {
    if (row < 0 || row == board.size() || col < 0 || col == board[0].size() || board[row][col] != 'O') return;

    board[row][col]='#';

    dfsTravel(board, row + 1, col);
    dfsTravel(board, row, col + 1);
    dfsTravel(board, row - 1, col);
    dfsTravel(board, row, col - 1);
}

void Solutions::solve(vector<vector<char>>& board) {
    int m = board.size(),n = board[0].size();

    for(int i = 0; i < m; i ++) {
        for(int j = 0; j < n; j ++){
            if ((i == 0 || i == m -1 || j == 0 || j == n-1) && board[i][j] == 'O') dfsTravel(board, i, j);
        }
    }

    for(int i = 0; i < m ; i ++){
        for(int j = 0; j < n; j ++) {
            if(board[i][j]!='#') board[i][j]='X';
            else board[i][j]='O';
        }
    }
}
/*
Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Notice that an 'O' should not be flipped if:
- It is on the border, or
- It is adjacent to an 'O' that should not be flipped.
The bottom 'O' is on the border, so it is not flipped.
The other three 'O' form a surrounded region, so they are flipped.
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

double dfsTravel(std::unordered_map<std::string, std::unordered_map<std::string , double>>& graph, std::string a , std::string& b , std::unordered_set<std::string>&visited){
    
    if(graph[a].find(b) != graph[a].end()) 
        return graph[a][b];
    
    for(auto v : graph[a]){
        if(visited.find(v.first) == visited.end()){
            visited.insert(v.first);

            double dist = dfsTravel(graph,v.first,b,visited );

            if(dist) {
                graph[a][b] = v.second * dist;
                return graph[a][b];
            }
        }
    }
    
    return 0;
}

vector<double> Solutions::calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    std::vector<double> result; 
    std::unordered_map<std::string, std::unordered_map<std::string , double>> graph;

    for(int i = 0;i < equations.size(); i++){
        graph[equations[i][0]][equations[i][1]] = (values[i]); 
        graph[equations[i][1]][equations[i][0]] = (double) 1/(values[i]); 
    }
    for(int i=0;i<queries.size();i++){           
        std::unordered_set<string> visited;             
        
        double val = dfsTravel(graph , queries[i][0] , queries[i][1] , visited );
        
        if(!val)
            result.push_back(double(-1.0));
        else 
            result.push_back(val);
    }
        
    return result;
}
/*
Example 1:

Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? 
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
note: x is undefined => -1.0
*/

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    std::vector<std::vector<int>> adjustment(numCourses);
    std::vector<int> indegree(numCourses, 0);

    for(auto& course: prerequisites) {
        adjustment[course[1]].push_back(course[0]);
        ++indegree[course[0]];
    }

    std::queue<int> q;

    for(int i = 0; i < numCourses; i++) {
        if(indegree[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int node = q.front(); q.pop();

        for(auto & next: adjustment[node]) {

            if(--indegree[next] == 0) q.push(next);
        }

        --numCourses;
    }

    return numCourses == 0;
}
/*
Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
*/


vector<int> Solutions::findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    std::vector<std::vector<int>> adjustment(numCourses);
    std::vector<int> indegree(numCourses, 0);

    std::vector<int> ans;

    for(auto& course: prerequisites) {
        adjustment[course[1]].push_back(course[0]);
        ++indegree[course[0]];
    }

    std::queue<int> q;

    for(int i = 0; i < numCourses; i++) {
        if(indegree[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int node = q.front(); q.pop();
        ans.push_back(node);
        
        for(auto & next: adjustment[node]) {

            if(--indegree[next] == 0){
                q.push(next);
            }
        }
    }

    if (ans.size() == numCourses) return ans;
    
    return {};
}
/*
Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
*/


} /* namespace leetcode */