/** 
 * @mainpage Solutions Library Documentation
 * @section intro_sec Introduction
 * This is the Leetcode C++ library for C++ Documentation Tutorial.
 */


#ifndef SOLUTION_H
#define SOLUTION_H
#include "utils.h"
#include <iostream>
#include <ctype.h>

// STL Containers
#include <set>
#include <unordered_set>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <queue>
#include <stack>
#include <numeric>
#include <regex>

#include <ctype.h>


/**
 * @brief Solutions of Leetcode quiz library namespace.
 * @author Louis Liu
 * @date 07/12/2022
 * @version 0.0.1
 * @note Hello God!
 */
namespace leetcode {

/**
 * @brief Solutions class used for leetcode quizs.
 */
class Solutions
{
public:

    /**
     * Create a new Solutions object.
     * @brief Default constructor.
     */
    Solutions();

    /**
    * Create a new Solutions object with high level input Operations on character streams.
    * @brief Constructor.
    * @param  s character streams
    */
    Solutions(std::istream& s);

    /**
    * Nutshell destructor
    * @brief Default destructor.
    */
    virtual ~Solutions();

    std::vector<int> PrintBFS(std::unique_ptr<TreeNode> node);
    std::unique_ptr<TreeNode> insertBTNode(std::unique_ptr<TreeNode> node, int value, int index);
    std::vector<int> PrintLinkedlist(std::unique_ptr<LinkedListNode> node);
    std::unique_ptr<LinkedListNode> insertLinkedlistNode(std::unique_ptr<LinkedListNode> node, int value);

    /* ========== Microsoft OA ============ */

    /**
    * @brief 1647 Miniumum Deletions to Make Character Frequencies Uniqe
    *
    * A string s is called good if there are no two different characters is s that have the same frequency.
    * Given a string s, return the minimum number of characters you need to delete to make a good.
    *
    * The frequency of a character in a string is the number of times it apears in the string.
    *
    * For example, in the string "aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.
    *
    * @param s a string
    * @return the minimum number of characters you need to delete to make s good
    */
    int minDeletions(std::string s);

    /**
    * @brief OA 2019  Minimum Adjacent Swaps to Make Palindrome (HARD)
    *
    * Given a string, what is the minimum number of adjacent swaps required to convert a string into a palindrome. If not possible, return -1.
    *
    * @param s a string
    * @return the minimum number of adjacent swaps required to convert a string into palindrome.
*/
    int minSwaps(std::string s);

    /**
    * @brief 1 Two Sum (Easy)
    * 
    * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
    * You may assume that each input would have exactly one solution, and you may not use the same element twice.
    * You can return the answer in any order.
    *
    * @param num an array of integers nums
    * @param target an integer
    *
    * @return the indices of the two numbers such that they add up to target
    */
    std::vector<int> twoSum(std::vector<int>& num, int target);

    /**
    * @brief OA 2019 Min Steps to Make Piles Equal Height
    *
    *  Alex is given n piles of equal or unequal heights. In one step, Alex can remove any number of boxes from the pile which has the maximum height and try to make it equal to the one which is just lower then the maximum height of the stack. Determine the minimum number of steps required to make all of the piles equal in height.
    *
    * @param nums n piles of equal or unequal heights
    * @return min steps
    */
    int minStpes( std::vector<int>& nums );

    /**
    * @brief 1239 Maximum length of a Concatenated String with Unique Characters. (Medium)
    *
    * You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.
    *
    * Return the maximum possible length of s.
    *
    * A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
    *
    * @param arr an array of string
    * @return the maximum possible length of string formed by the concatenation of a subsequence of array
    */
    int maxLength( std::vector< std::string > & arr);

    /**
    * @brief 1304 Find N Unique Integers Sum up to Zero (Easy)
    *
    * Given an integer n, return any array containing n unique integers such that they add up to 0.
    *
    * @param n an integer
    * @return any array containing n unique integers such that they add up tp 0
    */
    std::vector<int> sumZero(int n);

    /**
    * @brief 31 Next Permutation (Medium)
    *
    * A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
    * For example, for arr = [1,2,3], the following are considered permutations of arr: [1,2,3], [1,3,2], [3,1,2], [2,3,1].
    *
    * The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).
    *
    * @param nums a permutation of an array of integers
    * @return the next permutation of an array
    */
    void nextPermutation( std::vector<int> & nums);

    /**
    * @brief 1822. Sign of the Product of an Array
    *
    * Detailed There is a function signFunc(x) that returns:
    * - 1 of x is positive
    * - -1 of x is negative
    * - 0 of x is equal to 0
    *
    * You are given an integer array nums. Let products be the product of all values in the array nums
    *
    * @param nums an integer array nums
    * @return signFunc
    */
    int arraySign( std::vector<int> & nums);

    /**
    * @brief 1448. Count Good Nodes in Binary Tree
    *
    * Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.
    *
    * @param root binary tree root
    * @return the number of good nodes in the binary tree
    */
    int goodNodes(std::unique_ptr<TreeNode> root);

    /**
    * @brief OA 2019 Min Moves to Make String Without 3 Identical Consecutive Letters
    *
    * Given a string a having lowercase English letters, returns a string with no instances of three identical consecutive letters, obtained from s by deleting the minimum possible number of letters.
    *
    * @param s a string having lowercase English letters
    * @return a string with no instances of three identical consecutive letters, obtained from s
    */
    std::string filterString(std::string &s);

    /**
    * @brief OA 2019 Maximum possible value by insert 5 digit
    *
    * Write a function that returns the maximum possible value obtained by inserting 5 digit inside the decimal representation of integer N.
    *
    * @param num 5 digit
    * @param digit the decimal representation of integer N
    * @return the maximum possible value
    */
    int maxPossible(int num, int digit);

    /**
    * @brief Delete Node in a BST
    *
    * Given a root node reference of a BST and a key, delete the node with the given key in the BST.
    *
    * @param root root node reference of BST
    * @param key delete node with the given key
    * @return Return Parameter description
    */
    std::unique_ptr<TreeNode> deleteNode(std::unique_ptr<TreeNode> root, int key);

    /**
    * @brief OA 2020 Number of Fractions that Sum to 1
    *
    * You are given a list of lists fractions where each list contains [numerator, denominator] which represents the number number/denominator
    *
    * @param fraction a list of lists fractions
    * @return the number of pairs of fractions there are that sums to 1
    */
    int sumFraction( std::vector< std::vector<int> > & fraction);

    /**
    * @brief 1578. Minimum Time to Make Rope Colorful
    *
    * Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith ballon
    *
    * Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, so she asks Bob for help. Bob can remove some ballons from the rope to make it colorful/
    *
    * @param colors 0-indexed string colors 
    * @param neededTime time to make rope colorful
    * @return Return the minimum time Bob beed to make the rope colorful
    */
    int minCost( std::string colors, std::vector<int> & neededTime );

    /**
    * @brief 14. Longest Common Prefix
    * 
    * Write a function to find the longest common prefix string amongst an array of strings
    *
    * If there is no common prefix, return an empty string ""
    *
    * @param strs an array of strings
    * @return longest common prefix
    */
    std::string longestPrefix( std::vector< std::string > & strs);

    /**
    * @brief OA Largest K such that both K and -K exist in array
    *
    *  Write a function that, given an array A of N integers, returns the lagest integer K > 0 such that both values K and -K exist in array A.
    *
    * @param nums an array A of N integer
    * @return lagest K
    */
    int getLargestK( std::vector<int> & nums);

    /**
    * @brief Smallest Positive Integer
    *
    * Write a function that given an array A of N integer, return the smallest positive integer (greater than 0) that does not occur in A
    *
    * For example, given A = [1, 3, 6. 4. 1. 2], the function should return 5.
    *
    * Given A = [1, 2, 3]. the function should return 4.
    *
    * @param A of N integer
    * @return smallest positive integer
    */
    int smallestInt( std::vector<int> &A);

    /**
    * @brief  Maximum sequence of consecutive zeros
    *
    * A binary gap within a positive integer N is any maximum sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N. For example, number 9 has binary representation 1001 and contains a binary gap of length 2
    *
    * @param N a binary gap within a positive integer N
    * @return maximum sequence of consecutive zeros
    */
    int lengthBin(uint32_t N);

    /**
    * @brief  317. Shortest Distance from All Buildings
    *
    * You want to build a house on an empty land which reaches all buildings in the shortest amount of distance.
    *
    * You can only move up, down, left, and right. You are given a 2D grid of values 0, 1, or 2, where:
    * Each 0 marks an empty land which you can pass by freely.
    * Each 1 marks a building which you cannot pass through
    * Each 2 marks an obstacle which you cannot pass through
    *
    * @param grid 2D grid of values 0, 1, 2
    * @return the shortest distance
    */
    int shortestDistance( std::vector< std::vector<int> > & grid );

    /**
    * @brief  The Monty Hall Problem
    *
    * The Monty Hall problem is a famous conundrum in probability which takes the form of a hypothetical game show. The contestant is presented which three doors; behind one is a car and behind each of the other two is a goat. The contestant picks a door and then the gameshow host opens a different door to reveal a goat. The host knows which door conceals the car. The contestant is then invited to switch to the other closed door or stick with their initial choice.
    *
    * @param guess
    * @return probability
    */
    float montyHall(int guess);

    /**
    * @brief  Minimum number of letters
    *
    * You are given a string S consisting of N lowercase letters. In one move you can remove any substring from S, which starts and ends with the same letter and is at least two letters long. What is the minimum number of letters that may remain in S after any any number of such moves?
    *
    * @param S a string S consisting of N lowercase letters
    * @return minimum number of letters
    */
    int lowercaseLetters( std::string &S);

    // Balanced Stone Heaps
    int balancedStone( std::vector<int> &A);

    // Heap 
    // Course Schedule III
    int scheduleCourse( std::vector< std::vector<int> > & courses );

    int uniqueString( std::string &S);

    // 252 Meeting rooms (Greedy Algorithms)
    int storeMeetingrooms( std::vector< std::vector<int> > & rooms);

    // 452. Minimum Number of Arrows to Brust Balloons
   int findMinArrowShots( std::vector< std::vector<int> > &points);

    int maxFullRound( std::string &A, std::string &B);

    int solutions2( std::vector<int> &A);

    int maximumSum( int N, std::vector<int> &A, std::vector<int > &B);

    // 217. Contains Duplicate
    bool containDup ( std::vector<int> & nums);

    // 136. Single Number 
    int singleNumber( std::vector<int> & nums);

    // 349. Intersection of Two Arrays
    std::vector<int> intersection( std::vector<int> & nums1, std::vector<int> & nums2);

    // 202. Happy Number
    bool isHappy(int n);

    void dictionaries();

    // 18. 4Sum
    std::vector< std::vector<int> >  fourSum( std::vector<int> & nums, int target);

    // 100 Same Tree
    bool isSameTree(std::unique_ptr<TreeNode> p, std::unique_ptr<TreeNode> q);

    // 648. Replace Words
    std::string replaceWords( std::vector< std::string > & dictionary, std::string  sentence);

    // Google interview
    int uncovered_interval(std::vector< std::pair<int, int> > unserviceinterval, int thirdservice);

    // 2134. Minimum Swaps to Group All's Together II
    int minSwapsnums(std::vector<int> & nums);

    int minDistance( std::vector< std::vector<int> > & edges, int n, int x);

    std::vector< std::string > commonSubstring( std::vector<std::string> a, std::vector<std::string> b);

    int countDuplicates( std::vector<int> number);

    std::vector<float> plusMinus( std::vector<int> arr);

    // Codility Test
    int minChange(std::string &S, int k);

    // Codility Test
    int minDeleteCost( std::string &S, std::vector<int> &C);

    // Get Number of K
    int getNumberofK( std::vector<int>& data, int K);

    // Find Numbers with Sum
    std::vector<int> findNumberswithSum( std::vector<int> &nums, int sum);

    // median
    int getMedian(int x, int y, int z);

    // Almost Sorted
    bool almostSorted( std::vector<int> & nums);

    // 657. Robot Return to Origin
    bool judgeCircle( std::string moves);

    // 1192. Critical Connections in a Network
    std::vector< std::vector<int> > criticalConnections(int n, std::vector< std::vector<int> > & connections);

    // 162. Find Peak Element
    int findPeakElement( std::vector<int> & nums);

    // 2. Add Two Numbers
    std::unique_ptr<LinkedListNode> addTwoNumbers(std::unique_ptr<LinkedListNode> l1, std::unique_ptr<LinkedListNode> l2);

    // 83. Remove Duplicate from Sorted List
    std::unique_ptr<LinkedListNode> deleteDuplicates(std::unique_ptr<LinkedListNode> head);

    // Interview Question
    int balancedSum( std::vector<int> arr);

    // Interview Question
    bool addExpression( std::string& S);

    // 565 Array Nesting
    int arrayNexting( std::vector<int>& nums);

    // 282. Expression Add Operations
    std::vector< std::string> addOperators( std::string num, int target);

    // 110 Balanced Binary Tree
    bool isBalanced(std::unique_ptr<TreeNode> root);

    // 108 Convert Sorted Array to Binary Search Tree
    std::unique_ptr<TreeNode> sortedArrayToBST( std::vector<int> &nums);

    // 130. Surrounded Regions
    std::vector< std::vector<char> > surroundedRegions( std::vector< std::vector<char> > & board );

    // 338. Counting Bits
    std::vector<int> countBits(int n);

    // 191. Number of 1 Bits
    int hammingWeight(uint32_t n);

    // 336. Palindrome Pairs
    int palindromePairsSum( std::vector< std::string> & input_array);

    // 1927. Sum Game
    bool sumGame( std::string num);

    // 877. Stone Game
    bool stoneGame( std::vector<int> piles);

    // 51. N-Queens
    std::vector< std::vector< std::string> > solveNQueens(int n);

    // 1307.Verbal Arithmetic Puzzle
    bool isSolvable( std::vector< std::string > & words, std::string result);

    // 743. Network Delay Time
    int networkDelayTime( std::vector< std::vector<int> >  & time, int n, int k);

    // 785. Is Graph Bipartite
    bool isBipartite( std::vector< std::vector<int> > & graph );

    // 1820. Maximum Number of Accepted Invitations
    int maximumInvitations( std::vector< std::vector<int> > & grid);

    // Interview
    std::vector< std::vector<int> > isPairWithSum(int mat[ROW][COLUMN], int sum);

    // 207. Course Schedule
    bool canFinish(int numCourse, std::vector< std::vector<int> > & prerequisities);

    // 1136. Parallel Courses
    int minimumSemesters(int courses, std::vector< std::vector<int> > &relations);

    // 1494. Parallel Courses II
    int minNumberOfSemesters(int n, std::vector< std::vector<int> > & relations, int k);

    // 547. Number of Provinces
    int findCircleNum( std::vector< std::vector<int> > & isConnected);

    // 1568 Miniumum Number of Days to Disconnect Island
    int minDays( std::vector< std::vector<int> > & grid );

    // 122 Best Time to Buy and Sell Stock II
    int maxProfit( std::vector<int> & prices);

    // 746 Min Cost Climbing Stairs
    int minCostClimbingStairs( std::vector<int> & cost);

    // 3. Longest Substring Without Repeating Character
    int lengthOfLongestSubstring(std::string s);

    // 168. Excel Sheet Column Title
    std::string converToTitle(int columnNumber);

    // 10. Regular Expression Matching
    bool isMatch( std::string s, std::string p);

    // 125. Valid Palindrome
    bool isPalindrome(std::string s);

private:

    bool isValidChar(char c);
    bool isValidString(std::string s);
    bool isUniqieString( const std::string s);
    void checkLen( const std::vector<std::string> & arr, std::string str, int index, int& count);
    void bfs_distance(int column, int row, std::vector< std::vector<int> > &grid, std::vector< std::vector<int> > &distance, std::vector< std::vector<int> >  &visit);
    void countGoodNode(std::unique_ptr<TreeNode> node, int value, int& count);

    void PrintInorder(std::unique_ptr<TreeNode> node);

    int getRandom(int low, int high, int badNum);
    int gcd (int a, int b);


    std::vector<int> parseInts(const std::string & str);

    std::unique_ptr<TreeNode> getNewNode(int value);

    std::unique_ptr<TreeNode> getMinNode(std::unique_ptr<TreeNode> node);

    std::unique_ptr<LinkedListNode> getNewHead(int value);
};









































} /* namespace leetcode */

#endif /* SOLUTION_H */
