#include "solutions.h"
#include <numeric>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <queue>
#include <boost/lexical_cast.hpp>

namespace leetcode {

bool Solutions::isValidSudoku(std::vector<std::vector<char>>& board)
{
    for(int row = 0; row < 9; row ++) {
        std::unordered_set<char> checkrow;
        for (int col = 0; col < 9; col ++) {
            if (board[row][col] != '.' && checkrow.find(board[row][col]) != checkrow.end())
                return false;
            checkrow.insert(board[row][col]);
        }
    }

    for(int col = 0; col < 9; col ++) {
        std::unordered_set<char> checkcol;
        for(int row = 0; row < 9; row ++) {
            if (board[row][col] != '.' && checkcol.find(board[row][col]) != checkcol.end())
                return false;
            checkcol.insert(board[row][col]);
        }
    }

    std::vector<std::unordered_set<char>> checksubbox(9);
    for(int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            int loc = (row/3) * 3 + col /3;
            if(board[row][col] != '.' && checksubbox[loc].find(board[row][col]) != checksubbox[loc].end())
                return false;

            checksubbox[loc].insert(board[row][col]);
        }
    }

    return true;
}

std::vector<int> Solutions::spiralOrder(std::vector<std::vector<int>>& matrix)
{
    std::vector<int> ans;
    int row = matrix.size(), col = matrix[0].size(), total = row * col;
    int count  = 0;
    int startRow = 0, startCol = 0, endRow = row-1, endCol = col-1;
    while( count < total )
    {
        for(int index = startCol; count<total && index<=endCol ; index++ ){
            ans.push_back(matrix[startRow][index]);
            count++;
        }
        startRow++;
        for(int index = startRow; count<total && index<=endRow ;index++){
            ans.push_back(matrix[index][endCol]);
            count++;
        }
        endCol--;
        for(int index = endCol;count<total && index>=startCol;index--){
            ans.push_back(matrix[endRow][index]);
            count++;
        }
        endRow--;
        for(int index = endRow;count<total && index>=startRow;index--){
            ans.push_back(matrix[index][startCol]);
            count++;
        }
        startCol++;
    }

    return ans;
}

std::vector<std::vector<int>> Solutions::rotatematrix(std::vector<std::vector<int>> & matrix)
{
    int n = matrix.size();

    // Diagonal
    for(int i = 0; i < n ; i ++) {
        for(int j = 0; j < n - i ; j++) {
            std::swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);        
    
        }
    }

    // Level
    for(int i = 0; i < n/2; i ++) {
        for(int j = 0; j < n ; j ++) {
            std::swap(matrix[i][j], matrix[n - 1 - i][j]);
        }
    }

    return matrix;
}

std::vector<std::vector<int>> Solutions::setZeroes(std::vector<std::vector<int>>& matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    std::vector<int> rowTrack;
    std::vector<int> columnTrack;

    for (int row = 0; row < m; row++)
    {
        for (int column = 0; column < n; column++)
        {
            if (matrix[row][column] == 0)
            {
                rowTrack.push_back(row);
                columnTrack.push_back(column);
            }
        }
    }
    for (int row : rowTrack)
    {
        for (int column = 0; column < n; column++)
            matrix[row][column] = 0;
    }
    for (int column : columnTrack)
    {
        for (int row = 0; row < m; row++)
            matrix[row][column] = 0;
    }

    return matrix;
}

std::vector<std::vector<int>> Solutions::gameOfLife(std::vector<std::vector<int>>& board)
{
    int m = board.size(), n = m ? board[0].size() : 0;

    for(int i = 0; i < m; i ++) {
        for(int j = 0; j < n ; j ++) {
            int count = 0;
            // eight neighbors
            for(int k = std::max(i-1, 0); k < std::min(i+2, m); k ++) {
                for(int l = std::max(j-1, 0); l < std::min(j+2, n); l ++)
                    // count live neighbors and itself
                    count += board[k][l] & 1;
            }
            
            // two or three live neighbors
            if (count == 3 || count - board[i][j] == 3) {
                // set the 2nd bit which is the next generation
                board[i][j] |= 2;
            }
        }
    }

    // the next state
    for(int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            board[i][j] >>= 1;
        }
    }

    return board;
}


} /* namespace leetcode */
