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
 * @author Shelton Liu
 * @date 07/12/2022
 * @version 0.0.2
 * @note Hello God!
 */
namespace leetcode {

using namespace std;

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
    * @brief 1647 Miniumum Deletions to Make Character Frequencies Uniqe (Medium)
    *
    * A string s is called good if there are no two different characters is s that 
    * have the same frequency.
    * 
    * Given a string s, return the minimum number of characters you need to delete
    * to make a good.
    *
    * The frequency of a character in a string is the number of times it apears in the string.
    *
    * For example, in the string "aab", the frequency of 'a' is 2, while the frequency 
    * of 'b' is 1.
    *
    * @param s a string
    * @return the minimum number of characters you need to delete to make s good
    */
    int minDeletions(std::string s);

    /**
     * @brief  347 Top K Frequent Elements (Medium)
     * 
     * Given an integer array nums and an integer k, 
     * return the k most frequent elements. You may return the answer in any order.
     *
     * @param nums an integer array nums
     * @param k the most frequent elements
     * @return top k frequent elements
    */
    std::vector<int> topKFrequent(std::vector<int>& nums, int k);

    /**
     * @brief  1768. Merge Strings Alternately
     * 
     * You are given two strings word1 and word2. Merge the strings by adding letters
     * in alternating order, starting with word1. If a string is longer than the other,
     * append the additional letters onto the end of the merged string.
     * Return the merged string.

     * @param word1 a string 
     * @param word2 a string
     * @return the merged string
    */
    string mergeAlternately(string word1, string word2);

    /**
     * @brief  1071. Greatest Common Divisor of Strings
     * 
     * For two strings s and t, we say "t divides s" if and only 
     * if s = t + t + t + ... + t + t (i.e., t is concatenated with itself one or more times).
     *
     * Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.
     *
     * @param str1 a string 
     * @param str2 a string
     * @return the merged string
    */
    string gcdOfStrings(string str1, string str2);

    /**
     * @brief  1431. Kids With the Greatest Number of Candies
     * 
     * There are n kids with candies. You are given an integer array candies,
     * where each candies[i] represents the number of candies the ith kid has, and an integer extraCandies,
     * denoting the number of extra candies that you have.
     * 
     * Return a boolean array result of length n, where result[i] is true if, after 
     * giving the ith kid all the extraCandies, they will have the greatest number of candies among all the kids, or false otherwise.
     *
     * Note that multiple kids can have the greatest number of candies.
     * @param str1 a string 
     * @param str2 a string
     * @return the merged string
    */
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies);

    /**
     * @brief  605. Can Place Flowers
     * 
     * You have a long flowerbed in which some of the plots are planted, and some are not. However, 
     * flowers cannot be planted in adjacent plots.
     *
     * Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means
     *  not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.
     * @param flowered an integer array flowered containing 0's and 1's 
     * @param n a integer
     * @return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.
    */
    bool canPlaceFlowers(vector<int>& flowerbed, int n);

    /**
     * @brief  345. Reverse Vowels of a String
     * 
     * Given a string s, reverse only all the vowels in the string and return it.
     *
     * The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower
     * and upper cases, more than once.
     * @param s a string 
     * @return the reverse vowels of a string
    */
    string reverseVowels(string s);

    /**
     * @brief  334. Increasing Triplet Subsequence
     * 
     * Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k].
     * If no such indices exists, return false.
     * @param nums an integer arrays 
     * @return true if there exists a triple of indices
    */
    bool increasingTriplet(vector<int>& nums);

    /**
     * @brief  443. String Compression
     * 
     * Given an array of characters chars, compress it using the following algorithm:
     * Begin with an empty string s. For each group of consecutive repeating characters in chars:
     *
     * If the group's length is 1, append the character to s.
     * Otherwise, append the character followed by the group's length.
     * 
     * The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.
     *
     * After you are done modifying the input array, return the new length of the array.
     * 
     * You must write an algorithm that uses only constant extra space.
     * @param nums an integer arrays 
     * @return true if there exists a triple of indices
    */
    int compress(vector<char>& chars);

    /**
    * @brief OA 2019  Minimum Adjacent Swaps to Make Palindrome (Hard) - SKIP
    *
    * Given a string, what is the minimum number of adjacent swaps required to 
    * convert a string into a palindrome. If not possible, return -1.
    *
    * @param s a string
    * @return the minimum number of adjacent swaps required to convert a string into palindrome.
    */
    int minSwaps(std::string s);

    /**
    * @brief 1 Two Sum (Easy)
    * 
    * Given an array of integers nums and an integer target, return indices
    * of the two numbers such that they add up to target.
    *
    * You may assume that each input would have exactly one solution, and 
    * you may not use the same element twice.
    * 
    * You can return the answer in any order.
    *
    * @param num an array of integers nums
    * @param target an integer
    * @return the indices of the two numbers such that they add up to target
    */
    std::vector<int> twoSum(std::vector<int>& num, int target);

    /**
     * @brief  1200 Minimum Absolute Difference (Easy)
     *
     * Given an array of distinct integers arr, find all pairs of elements with 
     * the minimum absolute difference of any two elements.
     * 
     * Return a list of pairs in ascending order (with respect to pairs), each 
     * pair [a, b] follows
     * 
     * - a, b are from arr
     * - a < b
     * - b - a equals to the minimum absolute difference of any two elements in arr
     *
     * @param numbers an array of distinct integers
     * @return the minimum absolute difference of any two elements.
    */
    std::vector< std::vector<int> > closestNumbers(std::vector<int> &numbers);

    /**
    * @brief OA 2019 Min Steps to Make Piles Equal Height (Medium)
    *
    *  Alex is given n piles of equal or unequal heights. In one step, Alex can remove any number 
    *  of boxes from the pile which has the maximum height and try to make it equal to the one 
    *  which is just lower then the maximum height of the stack.
    * 
    *  Determine the minimum number of steps required to make all of the piles equal in height.
    *
    * @param nums n piles of equal or unequal heights
    * @return min steps
    */
    int minSteps( std::vector<int>& nums );

    /**
    * @brief 1239 Maximum length of a Concatenated String with Unique Characters. (Medium)
    *
    * You are given an array of strings arr. A string s is formed by the concatenation 
    * of a subsequence of arr that has unique characters.
    *
    * Return the maximum possible length of s.
    *
    * A subsequence is an array that can be derived from another array by deleting some
    *  or no elements without changing the order of the remaining elements.
    *
    * @param arr an array of string
    * @return the maximum possible length of string formed by the concatenation of a subsequence of array
    */
    int maxLength( std::vector< std::string > & arr);

     /* @brief 56. Merge Intervals
     *
     * Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
     *
     * @param intervals an array
     * @return an array of the non-overlapping intervals that cover all the intervals in the input.
     */
     std::vector< std::vector<int> > mergeInterval(std::vector< std::vector<int>> &input_interval);

     /* @brief 258. Add Digits
     *
     * Given an integer num, repeatedly add all its digits 
     * until the result has only one digit, and return it. 
     *
     * @param num an integer num
     * @return add all its digits
     */
     int addDigits(int num);

     /* @brief 450. Delete Node in a BST
     *
     * Given a root node reference of a BST and a key, delete the node with the given key in the BST. 
     * Return the root node reference (possibly updated) of the BST.
     * 
     * Basically, the deletion can be divided into two stages:
     * 
     * Search for a node to remove. If the node is found, delete the node.
     *
     * @param root a root node reference of a BST
     * @param key a key
     * @return the root node reference (possibly updated) of the BST
     */
    TreeNode* deleteNode(TreeNode* root, int key);

     /* @brief 700. Search in a Binary Search Tree
     *
     * You are given the root of a binary search tree (BST) and an integer val.
     * 
     * Find the node in the BST that the node's value equals val and return the subtree rooted with that node. 
     * If such a node does not exist, return null.
     *
     * @param root the root of a binary search tree (BST)
     * @param val an integer 
     * @return the subtree rooted with that node
     */
    TreeNode* searchBST(TreeNode* root, int val);
  
    /**
    * @brief 1304 Find N Unique Integers Sum up to Zero (Easy)
    *
    * Given an integer n, return any array containing n unique integers such that they add 
    * up to 0.
    *
    * @param n an integer
    * @return any array containing n unique integers such that they add up tp 0
    */
    std::vector<int> sumZero(int n);

    /**
    * @brief 31 Next Permutation (Medium)
    *
    * A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
    *
    * For example, for arr = [1,2,3], the following are considered permutations of arr: [1,2,3], [1,3,2], [3,1,2], [2,3,1].
    *
    * The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).
    *
    * @param nums a permutation of an array of integers
    * @return the next permutation of an array
    */
    void nextPermutation( std::vector<int> & nums);

    /**
    * @brief 1822 Sign of the Product of an Array (Easy)
    *
    * There is a function signFunc(x) that returns:
    * 
    *  1 if x is positive.
    * -1 if x is negative.
    *  0 if x is equal to 0.
    * 
    * You are given an integer array nums. Let product be the product of all values in the array nums.
    *
    * Return signFunc(product).
    *
    * @param nums an integer array nums
    * @return sign of the product of all values in the array nums
    */
    int arraySign( std::vector<int> & nums);

    /**
    * @brief 1448 Count Good Nodes in Binary Tree (Medium)
    *
    * Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.
    *
    * Return the number of good nodes in the binary tree.
    *
    * @param root a binary tree root
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
    * @brief 450 Delete Node in a BST (Medium)
    *
    *  Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.
    *  Basically, the deletion can be divided into two stages:
    *  Search for a node to remove.
    *  If the node is found, delete the node
    *
    * @param  root a binary tree root node
    * @param  key the key in the BST
    * @return the updated root node reference of the BST
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
    * @brief 1578 Minmum Time to Make Rope Colorful (Medium)
    *
    * Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.
    *
    * Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, so she asks Bob for help. Bob can remove some balloons from the rope to make it colorful. You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) that Bob needs to remove the ith balloon from the rope.
    *
    * Return the minimum time Bob needs to make the rope colorful.
    *
    * @param colors a 0-indexed string colors where colors[i] is the color of the ith ballon
    * @param neededTime 0-indexed integer array neededTime where neededTime[i] is the time (in seconds)
    * @return the minimum time Bob needs to make the rope colorful
    */
    int minCost( std::string colors, std::vector<int> & neededTime );

    /**
    * @brief 57. Insert Interval
    *
    * You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
    * 
    * Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
    * 
    * Return intervals after the insertion.
    *
    * @param intervals an array of non-overlapping intervals
    * @return intervals after the insertion
    */
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval);

    /**
    * @brief 14 Longest Common Prefix (Easy)
    *
    * Write a function to find the longest common prefix string amongst an array of strings.
    * If there is no common prefix, return an empty string "".
    *
    * @param strs array of strings
    * @return the longest common prefix string amongst an array of strings
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
    * @brief OA Maximum sequence of consecutive zeros
    *
    * A binary gap within a positive integer N is any maximum sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N. For example, number 9 has binary representation 1001 and contains a binary gap of length 2
    *
    * @param N a binary gap within a positive integer N
    * @return maximum sequence of consecutive zeros
    */
    int lengthBin(uint32_t N);

    /**
    * @brief 317 Shortest Distance from All Buildings (Medium)
    *
    * You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:
    * Each 0 marks an empty land which you can pass by freely.
    * Each 1 marks a building which you cannot pass through.
    * Each 2 marks an obstacle which you cannot pass through.
    *
    * For example, given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2):
    *
    * @param grid 2D grid of values 0, 1, 2
    * @return the shortest distance from all buildings
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
    * @brief OA Minimum number of letters (HARD)
    *
    * You are given a string S consisting of N lowercase letters. In one move you can remove any substring from S, which starts and ends with the same letter and is at least two letters long.
    *
    * What is the minimum number of letters that may remain in S after any number of such moves?
    *
    * @param S a string S consisting of N lowercase letters
    * @return minimum number of letters
    */
    int lowercaseLetters(std::string &S);

    /**
    * @brief Codeforces Balanced Stone Heaps (Easy)
    *
    *  There are n heaps of stone. The i-th heap has hi stones. You want to change the number of stones in the heap by performing the following process once:
    *
    *  - You go through the heaps from the 3-rd heap to the n-th heap, in this order.
    *  - Let i be the number of the current heap
    *  - You can choose a number d, move d stones from the i-th heap to the (i-1)th heap, and 2*d stones from the i-th heap to the (i-2)th heap.
    *  - So after that hi is decreased by 3*d, hi-1 is increased by d, and hi-2 is increased by 2*d.
    *  - You can choose different or same d for different operations. Some heaps may become empty, but they still count as heaps.
    *
    * @param A heaps of stone
    * @return the maximum number of stones in the smallest heap after the process.
    */
    int balancedStone( std::vector<int> &A);

    /**
    * @brief Course Schedule III (HARD)
    *
    * There are n different online courses numbered from 1 to n, You are given an array courses where courses[i] = [durationi, lastDayi] indicate that the ith course should be taken continuously for durationi days and must be finished before or on lastDayi.
    *
    *  You will start on the 1st day and you cannot take two or more courses simultaneously.
    *
    * @param courses an array courses where courses[i] = [durationi, lastDayi]
    * @return the maximum number of courses that you can take
    */
    int scheduleCourse( std::vector< std::vector<int> > & courses );

    int uniqueString( std::string &S);

    /**
    * @brief 252 Meeting rooms (Medium)
    *
    * Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.
    *
    * @param rooms an array of meeting time intervals consisting of start and end times
    * @return Whether or not a person could attend all meetings
    */
    int storeMeetingrooms( std::vector< std::vector<int> > & rooms);

    /**
    * @brief 452 Minimum Number of Arrows to Brust Balloons (Medium)
    *
    * There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. You do not know the exact y-coordinates of the balloons.
    * 
    * Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.
    * 
    * Given the array points, return the minimum number of arrows that must be shot to burst all balloons.
    *
    * @param points an a 2D array points
    * @return the minimum number of arrows that must be shot to burst all balloons
    */
    int findMinArrowShots( std::vector< std::vector<int> > &points);

    int maxFullRound( std::string &A, std::string &B);

    int solutions2( std::vector<int> &A);

    int maximumSum( int N, std::vector<int> &A, std::vector<int > &B);

    /**
    * @brief 217 Contains Duplicate (Easy)
    * 
    * Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
    *
    * @param nums an integer array nums
    *
    * @return true if any value appears at least twice in the array
    */
    bool containDup ( std::vector<int> & nums);

    /**
    * @brief 136 Single Number (Easy)
    *
    * Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
    * You must implement a solution with a linear runtime complexity and use only constant extra space.
    *
    * @param nums a non-empty array of integers
    *
    * @return single number
    */
    int singleNumber( std::vector<int> & nums);

    /**
    * @brief 349 Intersection of Two Arrays
    *
    * Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.
    *
    * @param nums1 integer array
    * @param nums2 integer array
    *
    * @return an array of their intersection
    */
    std::vector<int> intersection( std::vector<int> & nums1, std::vector<int> & nums2);

    /*! \brief 202. Happy Number
     *
     *  Write an algorithm to determine if a number n is happy.
     *
     *  Starting with any positive integer, replace the number by the
     *  sum of the squares of its digits.
     *  Repeat the process until the number equals 1 (where it will stay), 
     * or it loops endlessly in a cycle which does not include 1.
     *  Those numbers for which this process ends in 1 are happy.
     *
     *  Runtime: 3 ms, faster than 55.97% of C++ online submissions for 
     * Happy Number.
     *
     *  Memory Usage: 5.9 MB, less than 62.07% of C++ online submissions 
     * for Happy Number.
     *
     * \return true if n is a happy number, and false if not
     */
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

    /*! \brief 2. Add Two Numbers
     *
     *  You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
     *
     *  You may assume the two numbers do not contain any leading zero, except the number 0 itself.
     *
     * \return the sum as a linked list.
     */
    std::unique_ptr<LinkedListNode> addTwoNumbers(std::unique_ptr<LinkedListNode> l1, std::unique_ptr<LinkedListNode> l2);

    /*! \brief 2. Add Two Numbers
     *
     *  You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
     *
     *  You may assume the two numbers do not contain any leading zero, except the number 0 itself.
     *
     * \return the sum as a linked list.
     */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

    /**
     * @brief 21. Merge Two Sorted Lists
     * 
     * You are given the heads of two sorted linked lists list1 and list2.
     * 
     * Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
     * 
     * Return the head of the merged linked list.
     * 
     * @param list1 sorted linked list
     * @param list2 sorted linked list
     * @return the head of the merged linked list
    */
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);

    /**
     * @brief 92. Reverse Linked List II
     * 
     * Given the head of a singly linked list and two integers left 
     * and right where left <= right, reverse the nodes of the list 
     * from position left to position right, and return the reversed list.
     * 
     * @param head singly linked list
     * @param left integer
     * @param right integer
     * @return the reversed list
    */
    ListNode* reverseBetween(ListNode* head, int left, int right);

    /**
     * @brief 25. Reverse Nodes in k-Group
     * 
     * Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
     * 
     * k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
     * 
     * You may not alter the values in the list's nodes, only nodes themselves may be changed.

     * @param head the head of a linked list
     * @param k positive integer
     * @return the modified list
    */
    ListNode* reverseKGroup(ListNode* head, int k);    

    /**
     * @brief 19. Remove Nth Node From End of List
     * 
     * Given the head of a linked list, remove the nth node from the end of the list and return its head.
     * 
     * @param head the head of a linked list
     * @param n  the nth node from the end of the list
     * @return its head
    */
    ListNode* removeNthFromEnd(ListNode* head, int n);

    /**
     * @brief 82. Remove Duplicates from Sorted List II
     * 
     * Given the head of a sorted linked list, delete all nodes
     * that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.     * 
     * 
     * @param head the head of a sorted linked list
     * @return the linked list sorted as well
    */
    ListNode* deleteDuplicates(ListNode* head);

    /**
     * @brief 61. Rotate List
     * 
     * Given the head of a linked list, rotate the list to the right by k places.
     * 
     * @param head the head of a linked list
     * @param k places
     * @return rotate the list to the right by k places
    */
    ListNode* rotateRight(ListNode* head, int k);

    /**
     * @brief 138. Copy List with Random Pointer
     * 
     * A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.
     * Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. 
     * Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the
     * pointers in the new list should point to nodes in the original list.
     *      * 
     * @param head brand new nodes
     * @param k places
     * @return the head of the copied linked list
    */
    Node* copyRandomList(Node* head);

    /**
     * @brief 86. Partition List
     * 
     * Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
     * 
     * You should preserve the original relative order of the nodes in each of the two partitions.
     *
     * @param head the head of a linked list
     * @param x value
     * @return preserve the original relative order of the nodes in each of the two partitions.
    */
    ListNode* partition(ListNode* head, int x);


    // Interview reverse LinkedList 
    std::unique_ptr<LinkedListNode> reversedLinkedList(std::unique_ptr<LinkedListNode> l1);

    /*! \brief 83 Remove Duplicates from Sorted List
     *
     *  Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
     *
     * \return Return parameter description
     */
    std::unique_ptr<LinkedListNode> deleteDuplicates(std::unique_ptr<LinkedListNode> head);

    /*! \brief 1456. Maximum Number of Vowels in a Substring of Given Length
     *
     *  Given a string s and an integer k, return the maximum number of vowel
     *  letters in any substring of s with length k.
     * 
     * @param nums an integer array nums
     * @return the minumum element of this array
     */
    int maxVowels(string s, int k);

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

    /*! \brief 51. N-Queens
    *
    *  The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
    *
    *  Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
    *
    * Runtime: 9 ms, faster than 58.05% of C++ online submissions for N-Queens.
    *
    *
    * Memory Usage: 7 MB, less than 95.04% of C++ online submissions for N-Queens.
    *
    * \return Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
    */
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
    //bool canFinish(int numCourse, std::vector< std::vector<int> > & prerequisities);

    // 1136. Parallel Courses
    int minimumSemesters(int courses, std::vector< std::vector<int> > &relations);

    // 1494. Parallel Courses II
    int minNumberOfSemesters(int n, std::vector< std::vector<int> > & relations, int k);

    // 547. Number of Provinces
    int findCircleNum( std::vector< std::vector<int> > & isConnected);

    // 1568 Miniumum Number of Days to Disconnect Island
    int minDays( std::vector< std::vector<int> > & grid );

    /*! \brief 122 Best Time to Buy and Sell Stock II
     *
     *  You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
     *
     *  On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
     *
     * \return the maximum profit you can achieve.
     */
    int maxProfit( std::vector<int> & prices);

    // 746 Min Cost Climbing Stairs
    int minCostClimbingStairs( std::vector<int> & cost);

    // 168. Excel Sheet Column Title
    std::string converToTitle(int columnNumber);

    // 10. Regular Expression Matching
    bool isMatch( std::string s, std::string p);

    // 125. Valid Palindrome
    bool isPalindrome(std::string s);

    // 9. Valid Palindrome
    bool isPalindrome(int x);


    /**
     * @brief 169. Majority Element
     * 
     * Given an array nums of size n, return the majority element. 
     * The majority element is the element that appears more 
     * than #n / 2# times. You may assume that the 
     * majority element always exists in the array.
     *
     * @param nums an integer array nums
     * @return the majority element always exists in the array
    */
    int majorityElement(std::vector<int> & nums); 

   /**
     * @brief 130. Surrounded Regions
     * 
     * Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.
     * 
     * A region is captured by flipping all 'O's into 'X's in that surrounded region.
     *
     * @param nums an integer array nums
     * @return the majority element always exists in the array
    */
    void solve(vector<vector<char>>& board);

   /**
     * @brief 399. Evaluate Division
     * 
     * You are given an array of variable pairs equations and an array of real numbers values, 
     * where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. 
     * Each Ai or Bi is a string that represents a single variable.
     * 
     * You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query 
     * where you must find the answer for Cj / Dj = ?.
     * 
     * Return the answers to all queries. If a single answer cannot be determined, return -1.0.
     * 
     * @param equations an array of variable pairs
     * @param values values[i] represent the equation Ai / Bi = values[i].
     * @param queries queries[j] = [Cj, Dj] represents the jth query 
     * @return all queries
    */
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries);

   /**
     * @brief 207. Course Schedule
     * 
     * There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
     * You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
     * 
     * For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
     * 
     * Return true if you can finish all courses. Otherwise, return false.
     * 
     * @param numCourses a total of numCourses courses you have to take
     * @param prerequisites an array prerequisites].
     * @return true if you can finish all courses. Otherwise, return false.
    */
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites);

   /**
     * @brief 210. Course Schedule II
     * 
     * There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
     * You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
     * 
     * For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
     * 
     * Return the ordering of courses you should take to finish all courses. 
     * 
     * If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.
     * 
     * @param numCourses a total of numCourses courses you have to take
     * @param prerequisites an array prerequisites].
     * @return the ordering of courses you should take to finish all courses. 
    */
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites);

    /**
     * @brief 200. Number of Islands
     * 
     * Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), 
     * return the number of islands.
     * 
     * An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
     *
     * @param grid an m x n 2D binary grid
     * @return the number of islands
    */
    int numIslands(vector<vector<char>>& grid);

    /**
     * @brief Array Quadruplet
     * 
     * Given an unsorted array of integers arr and a number s, write a function findArrayQuadruplet that finds four numbers (quadruplet) in arr that sum up to s. Your function should return an array of these numbers in an ascending order. 
     * If such a quadruplet doesn’t exist, return an empty array.
     * 
     * Note that there may be more than one quadruplet in arr whose sum is s. You’re asked to return the first one you encounter (considering the results are sorted).
     * 
     * @param grid an m x n 2D binary grid
     * @return the number of islands
    */
    vector<int> findArrayQuadruplet(const vector<int> &arr, int s);

    /**
     * @brief 189. Rotate Array
     * 
     * Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
     *
     * @param nums an integer array nums
     * @return rorated array
    */
    std::vector<int> rotate(std::vector<int> & nums, int k);

    /**
     * @brief 238. Product of Array Except Self
     * 
     * Given an integer array nums, return an array answer such that answer[i] is 
     * equal to the product of all the elements of nums except nums[i]. 
     *
     * @param nums an integer array nums
     * @return the product of all elements of nums except self
    */
    std::vector<int> productExceptself(std::vector<int> & nums); 

    // NVIDIA Coding Interview
    std::string Duplicates(std::string & str);

    /* @brief Move Zeroes
    *
    * Given an integer array nums, move all 0's to the end of it
    * while maintaining the relative order of the non-zero elements.
    *
    * @param nums an integer array nums
    * @return the array nums, move all 0's to the end of it
    */
    std::vector<int> moveZeros(std::vector<int> & nums);

     /* @brief hackerrank diagional Difference
     *
     * Given a square matrix, calculate the absolute difference between the sums of 
     * its diagonals. 
     *
     * @param arr a square matrix
     * @return the absolute diagional difference 
     */
    int diagionalDifference( std::vector< std::vector<int>  > arr );

     /* @brief hackerrank insertion Sort
     *
     * Insertion Sort is a simple sorting technique which was covered in previous 
     * challenges. Sometimes, arrays may be too large for us to wait around for 
     * insertion sort to finish. Is there some other way we can calculate the 
     * number of shifts an insertion sort performs when sorting an array?
     *
     * @param insertionSort std::vector<int> & arr 
     * @return the number of shifts an insertion sort performs when sorting an array
     */
    int insertionSort(std::vector<int> & arr );

     /* @brief 26. Remove Duplicates from Sorted Array
     *
     * Given an integer array nums sorted in non-decreasing order, remove
     * the duplicates in-place such that each unique element appears only once.
     * The relative order of the elements should be kept the same.
     * Then return the number of unique elements in nums.
     * 
     * @param  
     * @return the number of shifts an insertion sort performs when sorting an array
     */
     int removeDuplicates(std::vector<int> & nums);

     /* @brief 27. Remove Element
     *
     * Given an integer array nums and an integer val, 
     * remove all occurrences of val in nums in-place. 
     * The order of the elements may be changed. 
     * Then return the number of elements in nums which are not equal to val.
     * 
     * @param nums an integer array 
     * @return the number of elements in nums which are not equal to val
     */
     int removeElement(std::vector<int> & nums, int val);

     /* @brief 1929. Concatenation of Array
     *
     * Given an integer array nums of length n, you want to create an array ans of length
     * 2n where ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).
     * 
     * Specifically, ans is the concatenation of two nums arrays.
     * 
     * Return the array ans.
     * 
     * @param nums an integer array 
     * @return the array ans
     */
    vector<int> getConcatenation(vector<int>& nums);

     /* @brief 1920. Build Array from Permutation
     *
     * Given a zero-based permutation nums (0-indexed), build an array ans of the same
     * length where ans[i] = nums[nums[i]] for each 0 <= i < nums.length and return it.
     * 
     * A zero-based permutation nums is an array of distinct integers from 0 to 
     * nums.length - 1 (inclusive).
     * 
     * @param nums a zero-based permutation 
     * @return a zero-based permutation nums
     */
    vector<int> buildArray(vector<int>& nums);

     /* @brief 1512. Number of Good Pairs
     *
     * Given an array of integers nums, return the number of good pairs.
     * 
     * A pair (i, j) is called good if nums[i] == nums[j] and i < j. 
     * 
     * @param nums an array of integers
     * @return the number of good pairs
     */
    int numIdenticalPairs(vector<int>& nums);

     /* @brief 2011. Final Value of Variable After Performing Operations
     *
     * There is a programming language with only four operations and one variable X:
     * 
     * ++X and X++ increments the value of the variable X by 1.
     * --X and X-- decrements the value of the variable X by 1.
     * 
     * Initially, the value of X is 0.
     * 
     * Given an array of strings operations containing a list of operations, 
     * return the final value of X after performing all the operations.
     * 
     * @param operations an array of strings operations
     * @return the final value of X after performing all the operations
     */
    int finalValueAfterOperations(vector<string>& operations);

     /* @brief 1470. Shuffle the Array
     *
     * Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].
     * 
     * Return the array in the form [x1,y1,x2,y2,...,xn,yn].
     * 
     * @param nums the array nums consisting of 2n elements
     * @param n n elements
     * @return the array in the form [x1,y1,x2,y2,...,xn,yn]
     */
    vector<int> shuffle(vector<int>& nums, int n);

     /* @brief 2942. Find Words Containing Character
     *
     * You are given a 0-indexed array of strings words and a character x.
     * 
     * Return an array of indices representing the words that contain the character x.
     * 
     * Note that the returned array may be in any order.
     * 
     * @param words a 0-indexed array of strings 
     * @param x a character
     * @return an array of indices representing the words that contain the character x.
     */
    vector<int> findWordsContaining(vector<string>& words, char x);

     /* @brief 2373. Largest Local Values in a Matrix
     *
     * You are given an n x n integer matrix grid.
     * 
     * Generate an integer matrix maxLocal of size (n - 2) x (n - 2) such that:
     * 
     * maxLocal[i][j] is equal to the largest value of the 3 x 3 matrix in grid 
     * centered around row i + 1 and column j + 1.
     * 
     * In other words, we want to find the largest value in every contiguous 3 x 3 matrix in grid.
     * 
     * Return the generated matrix.
     * 
     * @param grid an n x n integer matrix grid
     * @return the generated matrix
     */
    vector<vector<int>> largestLocal(vector<vector<int>>& grid);

     /* @brief 1672. Richest Customer Wealth
     *
     * You are given an m x n integer grid accounts where accounts[i][j] is 
     * the amount of money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank. 
     * Return the wealth that the richest customer has.
     * 
     * A customer's wealth is the amount of money they have in all their bank accounts.
     * The richest customer is the customer that has the maximum wealth.
     * 
     * @param accounts an m x n integer grid accounts
     * @return the wealth that the richest customer has
     */
    int maximumWealth(vector<vector<int>>& accounts);

     /* @brief 1863. Sum of All Subset XOR Totals
     *
     * The XOR total of an array is defined as the bitwise XOR of all
     *  its elements, or 0 if the array is empty.
     * 
     * For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.
     * Given an array nums, return the sum of all XOR totals for every subset of nums. 
     * 
     * Note: Subsets with the same elements should be counted multiple times.
     * 
     * An array a is a subset of an array b if a can be obtained from b by deleting some
     *  (possibly zero) elements of b.
     * 
     * @param nums an array
     * @return the sum of all XOR totals for every subset of nums.
     */
    int subsetXORSum(vector<int>& nums);

     /* @brief 2037. Minimum Number of Moves to Seat Everyone
     *
     * There are n seats and n students in a room. You are given an array seats of 
     * length n, where seats[i] is the position of the ith seat. You are also given
     *  the array students of length n, where students[j] is the position of the jth student.
     * 
     * You may perform the following move any number of times:
     * 
     * Increase or decrease the position of the ith student by 1 (i.e., moving the ith student
     *  from position x to x + 1 or x - 1)
     * 
     * Return the minimum number of moves required to move each student to a seat such that
     *  no two students are in the same seat.
     * 
     * Note that there may be multiple seats or students in the same position at the beginning.
     * 
     * @param seats n seats
     * @param seats n seats
     * @return the sum of all XOR totals for every subset of nums.
     */
    int minMovesToSeat(vector<int>& seats, vector<int>& students);

     /* @brief 2798. Number of Employees Who Met the Target
     *
     *  There are n employees in a company, numbered from 0 to n - 1. Each employee
     *  i has worked for hours[i] hours in the company.
     * 
     * The company requires each employee to work for at least target hours.
     * 
     * You are given a 0-indexed array of non-negative integers hours of length 
     * n and a non-negative integer target.
     * 
     * Return the integer denoting the number of employees who worked at least target hours.
     * 
     * @param hours Each employee i has worked for hours[i] hours in the company.
     * @param target a non-negative integer
     * @return the integer denoting the number of employees who worked at least target hours
     */
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target);

     /* @brief 1431. Kids With the Greatest Number of Candies
     *
     *  There are n kids with candies. You are given an integer array candies, 
     *  where each candies[i] represents the number of candies the ith kid has, 
     *  and an integer extraCandies, denoting the number of extra candies that you have.
     * 
     *  Return a boolean array result of length n, where result[i] is true if, after giving
     *  the ith kid all the extraCandies, they will have the greatest number of candies
     *  among all the kids, or false otherwise.
     * 
     * Note that multiple kids can have the greatest number of candies.
     * 
     * @param candies an integer array
     * @param extraCandies an integer extraCandies, denoting the number of extra candies that you have
     * @return a boolean array result of length n
     */
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies);

     /* @brief 1637. Widest Vertical Area Between Two Points Containing No Points
     *
     *  Given n points on a 2D plane where points[i] = [xi, yi], 
     * Return the widest vertical area between two points such that no points are inside the area.
     * 
     * A vertical area is an area of fixed-width extending infinitely along the y-axis 
     * (i.e., infinite height). The widest vertical area is the one with the maximum width.
     * 
     * Note that points on the edge of a vertical area are not considered included in the area.
     * 
     * @param points n points on a 2D plane 
     * @return the widest vertical area between two points such that no points are inside the area.
     */
    int maxWidthOfVerticalArea(vector<vector<int>>& points);

     /* @brief 2824. Count Pairs Whose Sum is Less than Target
     *
     *  Given a 0-indexed integer array nums of length n and an integer target, 
     * return the number of pairs (i, j) where 0 <= i < j < n and nums[i] + nums[j] < target.
     * 
     * @param nums a 0-indexed integer array
     * @param target an integer target
     * @return the number of pairs (i, j)
     */
    int countPairs(vector<int>& nums, int target);

     /* @brief 3162. Find the Number of Good Pairs I
     *
     *  You are given 2 integer arrays nums1 and nums2 of lengths n and m respectively.
     *  You are also given a positive integer k.
     * 
     * A pair (i, j) is called good if nums1[i] is divisible by nums2[j] * k 
     * (0 <= i <= n - 1, 0 <= j <= m - 1).
     * 
     * Return the total number of good pairs.
     * 
     * @param nums1 a integer array
     * @param nums2 a integer array
     * @param k a positive integer
     * @return the total number of good pairs
     */
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k);

     /* @brief 1480. Running Sum of 1d Array
     *
     *  Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
     * 
     *  Return the running sum of nums.
     *
     * @param nums an array
     * @return the running sum of nums
     */
    vector<int> runningSum(vector<int>& nums);

     /* @brief 80. Remove Duplicates from Sorted Array II
     *
     * Given an integer array nums sorted in non-decreasing order,
     * remove some duplicates in-place such that each unique element
     * appears at most twice. The relative order of the elements should be kept the same.
     * 
     * Return k after placing the final result in the first k slots of nums.
     *
     * @param nums an array
     * @return k after placing the final result in the first k slots of nums. 
     */                                                                          
     int removeDuplicatesII(std::vector<int> & nums);

     /* @brief Smallest Substring of All Characters
     *
     * Given an array of unique characters arr and a string str, Implement a function getShortestUniqueSubstring 
     * that finds the smallest substring of str containing all the characters in arr. Return "" (empty string)
     * if such a substring doesn’t exist.
     * 
     * Come up with an asymptotically optimal solution and analyze the time and space complexities.
     *
     * @param arr an array of unique characters
     * @param str a string
     * @return the smallest substring of str containing all the characters in arr. 
     */                                                                          
    string getShortestUniqueSubstring( const vector<char>& arr, const string &str );

     /* @brief 4. Median of Two Sorted Arrays
     *
     * Given two sorted arrays nums1 and nums2 of size m
     * and n respectively, return the median of the two sorted arrays.
     *
     * The overall run time complexity should be O(log (m+n)).
     *
     * @param nums1 an array
     * @param nums2 an array
     * @return the median of the two sorted arrays
     */                                                                          
     double findMedianSortedArray(std::vector<int>& nums1, std::vector<int> & nums2);

     /* @brief 128. Longest Consecutive Sequence
     *
     * Given an unsorted array of integers nums, return 
     * the length of the longest consecutive elements sequence.
     *
     * You must write an algorithm that runs in O(n) time.
     *
     * @param nums an array
     * @return the length of the longest consecutive elements sequence.
     */                                                                          
     int longestConsecutive(std::vector<int>& nums);

     /* @brief 15. 3Sum
     *
     * Given an integer array nums, return all the triplets [nums[i], nums[j], 
     * nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
     *
     * Notice that the solution set must not contain duplicate triplets.
     *
     * @param nums an array
     * @return all the triplets
     */                                                                          
     std::vector<std::vector<int>> threeSum(std::vector<int> & nums);

     /* @brief 11. Container With Most Water 
     *
     * You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
     * 
     * Find two lines that together with the x-axis form a container, such that the container contains the most water.
     * 
     * Return the maximum amount of water a container can store.
     * 
     * Notice that you may not slant the container. 
     *
     * @param height an integer array
     * @return the maximum amount of water of a container can store
     */                                                                          
     int maxArea(std::vector<int>& height);

     /* @brief 16. 3Sum Closest
     *
     * Given an integer array nums of length n and an integer target, 
     * find three integers in nums such that the sum is closest to target.
     *
     * Return the sum of the three integers. 
     *
     * You may assume that each input would have exactly one solution. 
     *
     * @param nums an array
     * @return the sum of the three integers
     */                                                                          
     int threeSumClosest(std::vector<int> & nums, int target);

     /* @brief 88. Merge Sorted Array
     *
     * You are given two integer arrays nums1 and nums2,
     * sorted in non-decreasing order, and two integers m and n,
     * representing the number of elements in nums1 and nums2 respectively. 
     *
     * Merge nums1 and nums2 into a single array sorted in non-decreasing order.
     *
     * @param nums1 an integer array
     * @param nums2 an integer array
     * @return merged single array sorted in non-decreasing order
     */
     std::vector<int> sortedmerge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n);

     /* @brief 121. Best Time to Buy and Sell Stock 
     *
     * You are given an array prices where prices[i] is the price of a given stock on the ith day.
     *
     * You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
     *
     * Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
     *
     * @param prices an array prices
     * @return the maximum profit you can achieve from this transaction
     */
     int maxProfitI(std::vector<int> & prices);

     /* @brief 48. Rotate Image
     *
     * You are given an n x n 2D matrix representing an image, 
     * rotate the image by 90 degrees (clockwise).
     *
     * You have to rotate the image in-place, which means you have 
     * to modify the input 2D matrix directly. DO NOT allocate another
     * 2D matrix and do the rotation. 
     *
     * @param martix n x n matrix representing an image
     * @return rotated image
     */
     std::vector<std::vector<int>> rotatematrix(std::vector<std::vector<int>> & matrix);

     /* @brief 73. Set Matrix Zeroes
     *
     * Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

     *
     * @param matrix m x n integer matrix
     * @return matrix which set its entire row and column to 0's
     */
     std::vector<std::vector<int>> setZeroes(std::vector<std::vector<int>>& matrix);

     /* @brief 289. Game of Life
     *
     * According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
     * 
     * The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):
     * 
     * Any live cell with fewer than two live neighbors dies as if caused by under-population.
     * Any live cell with two or three live neighbors lives on to the next generation.
     * Any live cell with more than three live neighbors dies, as if by over-population.
     * Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
     * The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.
     * 
     * The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.
     *
     * @param board made up od an m x n grid of cells
     * @return the next state 
     */
     std::vector<std::vector<int>> gameOfLife(std::vector<std::vector<int>>& board);

     /* @brief 55. Jump Game 
     *
     * You are given an integer array nums. You are initially 
     * positioned at the array's first index, and each element
     * in the array represents your maximum jump length at that 
     * position. 
     *
     * Return true if you can reach the last index, or false 
     * otherwise.
     *
     * @param nums an integer array
     * @return true if you can reach the last index, or false otherwise.
     */
     bool canJump(std::vector<int> & nums);

     /* @brief 45. Jump Game II
     *
     * You are given a 0-indexed array of integers nums of
     * length n. You are initially positioned at nums[0].
     *
     * Each element nums[i] represents the maximum length of
     * a forward jump from index i. In other words, 
     * if you are at nums[i], you can jump to any nums[i + j]
     *
     * Return the minimum number of jumps to reach nums[n - 1]. 
     * The test cases are generated such that you can
     *  reach nums[n - 1].
     *
     * @param nums a 0-indexed array of integers nums of length n
     * @return the minimum number of jumps to reach nums[n -1]
     */
     int jump(std::vector<int> & nums);

     /* @brief 274. H-Index
     *
     * Given an array of integers citations where citations[i]
     * is the number of citations a researcher received for their ith paper,
     * return the researcher's h-index.
     *
     * @param citations an array of integers
     * @return the researcher's h-index
     */
     int hIndex(std::vector<int> & citations); 

     /* @brief 134. Gas Station
     *
     * There are n gas stations along a circular route,
     * where the amount of gas at the ith station is gas[i].
     *
     * You have a car with an unlimited gas tank and it costs cost[i] of gas
     * to travel from the ith station to its next (i + 1)th station.
     * You begin the journey with an empty tank at one of the gas stations.
     *
     * Given two integer arrays gas and cost, return the starting gas station's
     * index if you can travel around the circuit once in the clockwise direction,
     * otherwise return -1. If there exists a solution, it is guaranteed to be unique
     *
     * @param costs cost of gas to travel from the ithe station to its next station 
     * @param gas gas station
     * @return the starting gas station's index
     */
     int canCompleteCircuit(std::vector<int> & gas, std::vector<int> & cost);

     /* @brief 135. Candy 
     *
     * There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.
     *
     * You are giving candies to these children subjected to the following requirements:
     *
     * Each child must have at least one candy.
     * Children with a higher rating get more candies than their neighbors.
     *
     * Return the minimum number of candies you need to have to distribute the candies to the children.
     *
     * @param rating the integer array ratings
     * @return the minimum number of candies you need to have to distribute the candies to the children
     */
     int candy(std::vector<int>& ratings);

     /* @brief 42. Trapping Rain Water 
     *
     * Given n non-negative integers representing an elevation
     *  map where the width of each bar is 1, compute 
     * how much water it can trap after raining.
     *
     * @param height n non-negative integers
     * @return how much water it can trap after raining
     */
     int trap(std::vector<int>& height);

     /* @brief 13. Roman to Integer 
     *
     * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
     * Roman numerals are usually written largest to smallest from left to right.
     * However, the numeral for four is not IIII. Instead, the number four is written as IV.
     * Because the one is before the five we subtract it making four.
     *
        Symbol       Value
        I             1
        V             5
        X             10
        L             50
        C             100
        D             500
        M             1000
     * The same principle applies to the number nine, which is written as IX. 
     * There are six instances where subtraction is used:
     * I can be placed before V (5) and X (10) to make 4 and 9.
     * X can be placed before L (50) and C (100) to make 40 and 90. 
     * C can be placed before D (500) and M (1000) to make 400 and 900. 
     *
     * @param s a roman numeral
     * @return integer
     */
     int romanToInt(std::string s);

     /* @brief 12. Integer to Roman 
     *
     * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
     *
     * Roman numerals are usually written largest to smallest from left to right. However,
     * the numeral for four is not IIII. Instead, the number four is written as IV.
     * Because the one is before the five we subtract it making four. The same principle 
     * applies to the number nine, which is written as IX. There are six instances where subtraction is used:
     *
     * Given an integer, convert it to a roman numeral.
     *
     * @param num an integer
     * @return a roman numeral
     */
     std::string intToRoman(int num);

     /* @brief 58. Length of Last Word 
     *
     * Given a string s consisting of words and spaces, return 
     * the length of the last word in the string.
     *
     * A word is a maximal substring consisting of non-space characters only.
     *
     * @param s a string consisting of words and spaces
     * @return the length of the last word in the string
     */
     int lenghtofLastword(std::string s);

     /* @brief 14. Longest Common Prefix
     *
     * Write a function to find the longest common prefix string amongst an array of strings.
     *
     * If there is no common prefix, return an empty string "".
     *
     * @param strs an array of strings
     * @return the longest common prefix string
     */
     std::string longestCommonPrefix(std::vector<std::string> & strs);

     /* @brief 2932. Maximum Strong Pair XOR I
     *
     * You are given a 0-indexed integer array nums. A pair of integers x and y is called a strong pair if it satisfies
     * the condition: |x - y| <= min(x, y) 
     * 
     * You need to select two integers from nums such that they form a strong pair and
     * their bitwise XOR is the maximum among all strong pairs in the array.
     * 
     * Return the maximum XOR value out of all possible strong pairs in the array nums.
     * 
     * Note that you can pick the same integer twice to form a pair.
     *
     * @param nums a 0-indexed integer array nums
     * @return the maximum XOR value out of all possible strong pairs in the array nums
     */
    int maximumStrongPairXor(vector<int>& nums);

     /* @brief 1876. Substrings of Size Three with Distinct Characters
     *
     * A string is good if there are no repeated characters.
     * 
     * Given a string s​​​​​, return the number of good substrings of length three in s​​​​​​.
     * 
     * Note that if there are multiple occurrences of the same substring, every occurrence should be counted.
     * 
     * A substring is a contiguous sequence of characters in a string.
     *
     * @param s a string
     * @return the number of good substrings of length three in s​​​​​​
     */
    int countGoodSubstrings(string s);

     /* @brief 1652. Defuse the Bomb
     *
     * You have a bomb to defuse, and your time is running out! Your informer will provide
     * you with a circular array code of length of n and a key k.
     * 
     * To decrypt the code, you must replace every number. All the numbers are replaced simultaneously.
     * 
     * If k > 0, replace the ith number with the sum of the next k numbers.
     * If k < 0, replace the ith number with the sum of the previous k numbers.
     * If k == 0, replace the ith number with 0.
     * 
     * As code is circular, the next element of code[n-1] is code[0], and the previous element of code[0] is code[n-1].
     * 
     * Given the circular array code and an integer key k, return the decrypted code to defuse the bomb!
     *
     * @param code a circular array code of length of n
     * @param k a key
     * @return the decrypted code to defuse the bomb
     */
    vector<int> decrypt(vector<int>& code, int k);

     /* @brief 151. Reverse Words in a String
     *
     * Given an input string s, reverse the order of the words.
     * 
     * A word is defined as a sequence of non-space characters. 
     * The words in s will be separated by at least one space.
     * 
     * Return a string of the words in reverse order concatenated by a single space.
     * 
     * Note that s may contain leading or trailing spaces or multiple 
     * spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.
     *
     * @param s string
     * @return a string of the words in reverse order concatenated by a single space
     */
     std::string reverseWords(std::string s);

     /* @brief 6. Zigzag Conversion
     *
     * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
     * 
     * And then read line by line: "PAHNAPLSIIGYIR"
     *
     * @param s string
     * @return a string of the words in reverse order concatenated by a single space
     */
     std::string convert(std::string s, int numRows);

     /* @brief 28. Find the Index of the First Occurrence in a String
     *
     * Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
     *
     * @param heystack
     * @param needle
     * @return the index of the first occurrence of needle in haytack
     */
     int strStr(std::string haystack, std::string needle);

     /* @brief 68. Text Justification
     *
     * Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.
     *
     * You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.
     *
     * Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
     *
     * For the last line of text, it should be left-justified, and no extra space is inserted between words
     *
     * @param words an array of strings words
     * @param maxWidth Each word's length is guaranteed to be greater than 0 and not exceed maxWidth
     * @return extra spaces between words should be distributed as evenly as possible
     */
     std::vector<std::string> fullyJustify(std::vector<std::string> & words, int maxWidth);

     /* @brief 392. Is Subsequence
     *
     * Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
     *
     * A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
     *
     * @param s string
     * @param t string
     * @return if s is a subsequence of t
     */
     bool isSubsequence(std::string s, std::string t);

     /* @brief 209. Minimum Size Subarray Sum
     *
     * Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray
     * whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
     *
     * @param nums an array of positive integers
     * @param target a positive
     * @return the minimal length of a subarray
     */
     int minSubArrayLen(int target, std::vector<int> nums);

     /* @brief 3. Longest Substring Without Repeating Characters
     *
     * Given a string s, find the length of the longest substring without repeating characters.
     *
     * @param s string
     * @return the length of the longest substring without repeating characters.
     */
     int lengthOfLongestSubstring(std::string s);

     /* @brief 30. Substring with Concatenation of All Words
     *
     * You are given a string s and an array of strings words. All the strings of words are of the same length.
     * 
     * A concatenated substring in s is a substring that contains all the strings of any permutation of words concatenated.
     *
     * Return the starting indices of all the concatenated substrings in s. You can return the answer in any order.
     *
     * @param s a string
     * @param words an array of strings
     * @return the starting indices of all the concatenated substrings in s.
     */
     std::vector<int> findSubstring(std::string s, std::vector<std::string>& words);

     /* @brief 76. Minimum Window Substring
     *
     * Given two strings s and t of lengths m and n respectively, return the minimum window 
substring of s such that every character in t (including duplicates) is included in the window.
     * If there is no such substring, return the empty string "".
     *
     * @param s string of length m
     * @param t string of length n
     * @return the minimum window substring of s such that every character in t is included in the window.
     */
     std::string minWindow(std::string s, std::string t);

     /* @brief 36. Valid Sudoku
     *
     * Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
     * 
     * Each row must contain the digits 1-9 without repetition.
     * Each column must contain the digits 1-9 without repetition.
     * Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
     *
     * @param 
     * @param t string of length n
     * @return the minimum window substring of s such that every character in t is included in the window.
     */
     bool isValidSudoku(std::vector<std::vector<char>>& board);

     /* @brief 20. Valid Parentheses
     *
     * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
     * 
     * An input string is valid if:
     * 
     * Open brackets must be closed by the same type of brackets.
     * Open brackets must be closed in the correct order.
     * Every close bracket has a corresponding open bracket of the same type.
     *
     * @param s a string 
     * @return determine if the input string is valid
     */
     bool isValid(std::string s);

     /* @brief 71. Simplify Path
     *
     * Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the simplified canonical path.
     * 
     * In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory up a level, and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'. For this problem, any other format of periods such as '...' are treated as file/directory names.
     * 
     * The canonical path should have the following format:
     * 
     * The path starts with a single slash '/'.
     * Any two directories are separated by a single slash '/'.
     * The path does not end with a trailing '/'.
     * The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')
     * Return the simplified canonical path.
     *
     * @param path a string path 
     * @return the simplified canonical path
     */
     std::string simplifyPath(std::string path);

     /* @brief 150. Evaluate Reverse Polish Notation
     *
     * You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
     * 
     * Evaluate the expression. Return an integer that represents the value of the expression.
     * 
     * Note that:
     * 
     * The valid operators are '+', '-', '*', and '/'.
     * Each operand may be an integer or another expression.
     * The division between two integers always truncates toward zero.
     * There will not be any division by zero.
     * The input represents a valid arithmetic expression in a reverse polish notation.
     * The answer and all the intermediate calculations can be represented in a 32-bit integer.
     *
     * @param tokens an array of strings
     * @return an integer that represents the value of the expression
     */
     int evalRPN(std::vector<std::string>& tokens);

     /* @brief 224. Basic Calculator
     *
     * Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.
     * 
     * Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval(). 
     *
     * @param s a string representing a valid expression
     * @return the result of the evaluation
     */
     int calculate(std::string s);

     /* @brief 141. Linked List Cycle
     *
     * Given head, the head of a linked list, determine if the 
     * linked list has a cycle in it.
     * 
     * There is a cycle in a linked list if there is some 
     * node in the list that can be reached again by continuously 
     * following the next pointer. Internally, pos is used to denote
     *  the index of the node that tail's next pointer is connected to.
     *  Note that pos is not passed as a parameter.
     * 
     * Return true if there is a cycle in the linked list. 
     * Otherwise, return false.
     *
     * @param head the head of a linked list
     * @param pos used to denote the index of the node that tail's next pointer is connected to.
     * @return true if there is a cycle in the linked list
     */
     bool hasCycle(std::unique_ptr<leetcode::LinkedListNode> *head, int pos);

     /* @brief 141. Linked List Cycle
     *
     * Given head, the head of a linked list, determine if the linked list has a cycle in it.
     * 
     * There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
     * 
     * Return true if there is a cycle in the linked list. Otherwise, return false.
     *
     * @param head the head of a linked list
     * @return true if there is a cycle in the linked list
     */
     bool hasCycle(ListNode *head);

     /* @brief 206. Reverse Linked List
     *
     * Given the head of a singly linked list, reverse the list, and 
     * return the reversed list.
     * 
     * @param head the head of a singly linked list
     * @return the reversed list
     */
     ListNode* reverseList(ListNode* head);

     /* @brief 35. Search Insert Position
     *
     * Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, 
     * return the index where it would be if it were inserted in order.
     * 
     * You must write an algorithm with O(log n) runtime complexity.
     * 
     * @param nums a sorted array of distinct integers
     * @param target a target value
     * @return the index where it would be if it were inserted in order
     */
    int searchInsert(vector<int>& nums, int target);

     /* @brief 74. Search a 2D Matrix
     *
     * You are given an m x n integer matrix matrix with the following two 
     * properties:
     * 
     * Each row is sorted in non-decreasing order.
     * 
     * The first integer of each row is greater than the last integer of the previous row.
     * 
     * Given an integer target, return true if target is in matrix or 
     * false otherwise.
     * 
     * You must write a solution in O(log(m * n)) time complexity.
     * 
     * @param matrix m x n integer matrix
     * @param target a target value
     * @return true if target is in matrix or false otherwise.
     */
    bool searchMatrix(vector<vector<int>>& matrix, int target);

     /* @brief 162. Find Peak Element
     *
     * A peak element is an element that is strictly greater than its neighbors.
     * 
     * Given a 0-indexed integer array nums, find a peak element, and return its index. If the array
     * contains multiple peaks, return the index to any of the peaks.
     * 
     * You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered 
     * to be strictly greater than a neighbor that is outside the array.
     * 
     * You must write an algorithm that runs in O(log n) time.
     * 
     * @param nums a 0-indexed integer array
     * @return the index to any of the peaks
     */
    int findPeakElement( std::vector<int> & nums);

     /* @brief 1161. Maximum Level Sum of a Binary Tree
     *
     * Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
     * Return the smallest level x such that the sum of all the values of nodes at level x is maximal.
     * 
     * @param root the root of a binary tree
     * @return the smallest level x such that the sum of all the values of nodes at level x is maximal.
     */
    int maxLevelSum(TreeNode* root);

     /* @brief 3090. Maximum Length Substring With Two Occurrences
     *
     * Given a string s, return the maximum length of a substring such that it contains at most two occurrences of each character.
     * 
     * @param s string
     * @return he maximum length of a substringsuch that it contains at most two occurrences of each character.
     */
    int maximumLengthSubstring(string s);

     /* @brief 2269. Find the K-Beauty of a Number
     *
     * The k-beauty of an integer num is defined as the number of substrings of num when it is read as a string that meet the following conditions:
     * 
     * It has a length of k.
     * It is a divisor of num.
     * 
     * Given integers num and k, return the k-beauty of num.
     * 
     * Note: Leading zeros are allowed. 
     * 0 is not a divisor of any value.
     * A substring is a contiguous sequence of characters in a string.
     * 
     * @param num an integer defined as the number of substrings of num
     * @param k the k-beauty of an integer 
     * @return the k-beauty of num
     */
    int divisorSubstrings(int num, int k);

     /* @brief 1984. Minimum Difference Between Highest and Lowest of K Scores
     *
     * You are given a 0-indexed integer array nums, where nums[i] represents the score of the ith student. You are also given an integer k.
     * 
     * Pick the scores of any k students from the array so that the difference between the highest and the lowest of the k scores is minimized.
     * 
     * Return the minimum possible difference.
     * 
     * @param nums a 0-indexed integer array 
     * @param K the scores of any k students from the array 
     * @return the minimum possible difference
     */
    int minimumDifference(vector<int>& nums, int k);

     /* @brief 594. Longest Harmonious Subsequence
     *
     * We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.
     * 
     * Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.
     * 
     * A subsequence of array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.
     * 
     * @param nums an integer array 
     * @param K the scores of any k students from the array 
     * @return the minimum possible difference
     */
    int findLHS(vector<int>& nums);

     /* @brief 2379. Minimum Recolors to Get K Consecutive Black Blocks
     *
     * You are given a 0-indexed string blocks of length n, where blocks[i] is either 'W' or 'B', 
     * representing the color of the ith block. The characters 'W' and 'B' denote the colors white and black, respectively.
     * 
     * You are also given an integer k, which is the desired number of consecutive black blocks.
     * 
     * In one operation, you can recolor a white block such that it becomes a black block.
     * 
     * Return the minimum number of operations needed such that there is at least one occurrence of k consecutive black blocks.
     * 
     * @param blocks a 0-indexed string blocks of length n
     * @param k an integer 
     * @return the minimum number of operations needed such that there is at least one occurrence of k consecutive black blocks.
     */
    int minimumRecolors(string blocks, int k);

     /* @brief 33
     *
     * There is an integer array nums sorted in ascending order (with distinct values).
     * 
     * Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
     * 
     * Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
     * 
     * You must write an algorithm with O(log n) runtime complexity.
     * 
     * @param nums an integer array nums sorted in ascending order
     * @param target an integer
     * @return the index of target if it is in nums, or -1 if it is not in nums
     */
    int search(vector<int>& nums, int target);

     /* @brief 34. Find First and Last Position of Element in Sorted Array
     *
     * Given an array of integers nums sorted in non-decreasing order, 
     * find the starting and ending position of a given target value.
     * 
     * If target is not found in the array, return [-1, -1].
     * 
     * You must write an algorithm with O(log n) runtime complexity.
     * 
     * @param nums an array of integers nums sorted in non-decreasing order
     * @param target an integer
     * @return the starting and ending position of a given target value
     */
    vector<int> searchRange(vector<int>& nums, int target);

     /* @brief 219. Contains Duplicate II
     *
     * Given an integer array nums and an integer k, return true if there are two distinct 
     * indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
     * 
     * @param nums an array of integers nums sorted in non-decreasing order
     * @param target an integer
     * @return the starting and ending position of a given target value
     */
    bool containsNearbyDuplicate(vector<int>& nums, int k);

     /* @brief 643. Maximum Average Subarray I
     *
     * You are given an integer array nums consisting of n elements, and an integer k.
     * 
     * Find a contiguous subarray whose length is equal to k that has the maximum average value and return 
     * this value. Any answer with a calculation error less than 10-5 will be accepted.
     * 
     * @param nums an integer array
     * @param k an integer
     * @return a contiguous subarray whose length is equal to k that has the maximum average value
     */
    double findMaxAverage(vector<int>& nums, int k);

     /* @brief 3095. Shortest Subarray With OR at Least K I
     *
     * You are given an array nums of non-negative integers and an integer k.
     * 
     * An array is called special if the bitwise OR of all of its elements is at least k.
     * 
     * Return the length of the shortest special non-empty subarray of nums, or return -1 if no special subarray exists.
     * 
     * @param nums an array nums of non-negative integers
     * @param k an integer
     * @return the length of the shortest special non-empty subarray of nums
     */
    int minimumSubarrayLength(vector<int>& nums, int k);

     /* @brief 2760. Longest Even Odd Subarray With Threshold
     *
     * You are given a 0-indexed integer array nums and an integer threshold.
     * 
     * Find the length of the longest subarray of nums starting at index l and ending at 
     * index r (0 <= l <= r < nums.length) that satisfies the following conditions:
     * 
     * nums[l] % 2 == 0
     * For all indices i in the range [l, r - 1], nums[i] % 2 != nums[i + 1] % 2
     * For all indices i in the range [l, r], nums[i] <= threshold
     * 
     * Return an integer denoting the length of the longest such subarray.
     * 
     * Note: A subarray is a contiguous non-empty sequence of elements within an array.
     * 
     * @param nums a 0-indexed integer array
     * @param threshold an integer
     * @return an integer denoting the length of the longest such subarray
     */
    int longestAlternatingSubarray(vector<int>& nums, int threshold);

     /* @brief Validate IP Address
     *
     * Validate an IP address (IPv4). An address is valid if and only 
     * if it is in the form "X.X.X.X", where each X is a number from 0 to 255.
     * 
     * For example, "12.34.5.6", "0.23.25.0", and "255.255.255.255" are valid
     * IP addresses, while "12.34.56.oops", "1.2.3.4.5", and "123.235.153.425" are invalid IP addresses.
     * 
     * @param ip an IP address
     * @return validate an IP address
     */
    bool validateIP(const string& ip);

     /* @brief Bracket Match
     *
     * A string of brackets is considered correctly matched if every opening bracket in the 
     * string can be paired up with a later closing bracket, and vice versa. For instance, 
     * “(())()” is correctly matched, whereas “)(“ and “((” aren’t. For instance, 
     * “((” could become correctly matched by adding two closing brackets at the end, so you’d return 2.
     * 
     * Given a string that consists of brackets, write a function bracketMatch that takes a bracket string 
     * as an input and returns the minimum number of brackets you’d need to add to the input in order to make it correctly matched.
     * 
     * @param text a string that consists of brackets
     * @return the minimum number of brackets you’d need to add to the input in order to make it correctly matched.
     */
    int bracketMatch( const string& text );

     /* @brief 153. Find Minimum in Rotated Sorted Array
     *
     * Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, 
     * the array nums = [0,1,2,4,5,6,7] might become:
     * 
     * [4,5,6,7,0,1,2] if it was rotated 4 times.
     * [0,1,2,4,5,6,7] if it was rotated 7 times.
     * 
     * Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in 
     * the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
     * 
     * Given the sorted rotated array nums of unique elements, return the minimum element of this array.
     * 
     * You must write an algorithm that runs in O(log n) time.
     * 
     * @param nums an array of length n sorted in ascending order is rotated between 1 and n times.
     * @return the minimum element of this array.
     */
    int findMin(vector<int>& nums);

     /* @brief 4. Median of Two Sorted Arrays
     *
     * Given two sorted arrays nums1 and nums2 of size m and n respectively, 
     * return the median of the two sorted arrays.
     * 
     * The overall run time complexity should be O(log (m+n)).
     * 
     * @param nums1 a sorted array
     * @param nums2 a sorted array
     * @return the median of the two sorted arrays.
     */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

     /* @brief 199. Binary Tree Right Side View
     *
     * Given the root of a binary tree, imagine yourself standing on the right side of it, 
     * return the values of the nodes you can see ordered from top to bottom.
     * 
     * @param root the root of a binary tree
     * @return the values of the nodes you can see ordered from top to bottom.
     */
     vector<int> rightSideView(TreeNode* root);

    /* @brief 637. Average of Levels in Binary Tree
     *
     * Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. 
     * Answers within 10-5 of the actual answer will be accepted.
     * 
     * @param root the root of a binary tree
     * @return the average value of the nodes on each level in the form of an array.
     */
     vector<double> averageOfLevels(TreeNode* root);

    /* @brief 102. Binary Tree Level Order Traversal
     *
     * Given the root of a binary tree, return the level order traversal 
     * of its nodes' values. (i.e., from left to right, level by level).
     * 
     * @param root the root of a binary tree
     * @return the level order traversal of its nodes' values.
     */
     vector<vector<int>> levelOrder(TreeNode* root);

    /* @brief 103. Binary Tree Zigzag Level Order Traversal
     *
     * Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right,
     *  then right to left for the next level and alternate between).
     * 
     * @param root the root of a binary tree
     * @return the zigzag level order traversal of its nodes' values.
     */
    vector<vector<int>> zigzagLevelOrder(TreeNode* root);

    /* @brief 909. Snakes and Ladders
     *
     * You are given an n x n integer matrix board where the cells are labeled 
     * from 1 to n2 in a Boustrophedon style starting from the bottom left 
     * of the board (i.e. board[n - 1][0]) and alternating direction each row.
     * 
     * You start on square 1 of the board. In each move, starting from square curr, do the following:
     * 
     * Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n2)].
     * 
     * This choice simulates the result of a standard 6-sided die roll: i.e., there are always at most 6 destinations, regardless of the size of the board.
     * 
     * If next has a snake or ladder, you must move to the destination of that snake or ladder. Otherwise, you move to next.
     * 
     * The game ends when you reach the square n2.
     * 
     * @param board an n x n integer matrix board
     * @return the least number of moves required to reach the square n2. If it is not possible to reach the square, return -1.
     */
    int snakesAndLadders(vector<vector<int>>& board);

    /* @brief 433. Minimum Genetic Mutation
     *
     * A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.
     * 
     * Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where one 
     * mutation is defined as one single character changed in the gene string.
     * 
     * There is also a gene bank bank that records all the valid gene mutations. 
     * A gene must be in bank to make it a valid gene string.
     * 
     * Given the two gene strings startGene and endGene and the gene bank bank, return
     * the minimum number of mutations needed to mutate from startGene to endGene. 
     * If there is no such a mutation, return -1.
     * 
     * @param startGene a gene string
     * @param endGene a gene string
     * @param bank the gene bank
     * @return the minimum number of mutations needed to mutate from startGene to endGene
     */
    int minMutation(string startGene, string endGene, vector<string>& bank);

    /* @brief 127. Word Ladder
     *
     * A transformation sequence from word beginWord to word endWord using a dictionary wordList is 
     * a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
     * 
     * Every adjacent pair of words differs by a single letter
     * 
     * Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
     * 
     * sk == endWord
     * 
     * Given two words, beginWord and endWord, and a dictionary wordList, return the number of words
     * in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
     * 
     * @param beginWord a word
     * @param endWord a word
     * @param wordList a dictionary
     * @return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
     */
    int ladderLength(string beginWord, string endWord, vector<string>& wordList);

    /* @brief Array Index & Element Equality
     *
     * Given a sorted array arr of distinct integers, write a function indexEqualsValueSearch that returns
     * the lowest index i for which arr[i] == i. 
     * 
     * Return -1 if there is no such index. Analyze the time and space complexities of your solution and explain its correctness.
     * 
     * @param arr a sorted array
     * @return the lowest index i for which arr[i] == i. Otherwise, -1 if there is no such index
     */
    int indexEqualsValueSearch(const vector<int> &arr);

    /* @brief 212. Word Search II
     *
     * Given an m x n board of characters and a list of strings words, 
     * return all words on the board.
     * 
     * Each word must be constructed from letters of sequentially adjacent cells, 
     * where adjacent cells are horizontally or vertically neighboring. The same 
     * letter cell may not be used more than once in a word.
     * 
     * @param board an m x n board of characters
     * @param words a list of strings words
     * @return all words on the board.
     */
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words);

    /* @brief 17. Letter Combinations of a Phone Number
     *
     * Give a string containing digitals from 2-9 inclusive, return all possible letter combinations that
     * the number could represent. Return the answer in any order.
     * 
     * A mapping of digits to letters (just like on the telephone button) is given below.
     * Note that 1 dose not map to any letters.
     * 
     * @param digits a mapping of digits to letters
     * @return the answer in any order
     */
    vector<string> letterCombinations(string digits);

    /* @brief 77. Combinations
     *
     * Give two integers n and k, return all possbile combinations of k numbers chosen from 
     * the range [1, n]
     * 
     * You may return the answer in any order.
     * 
     * @param n integer
     * @param k integer
     * @return the answer in any order
     */
    vector<vector<int>> combine(int n, int k);

    /* @brief 46. Permutations
     *
     * Given an array nums of distinct integers, return all the possible permutations.
     * 
     * You can return the answer in any order.
     * 
     * @param nums an array nums of distinct integers
     * @return all the possible permutations
     */
    vector<vector<int>> permute(vector<int>& nums);

    /* @brief 39. Combination Sum
     *
     * Given an array of distinct integers candidates and a target integer target, return
     * a list of all unique combinations of candidates where the chosen numbers sum to target. 
     * 
     * You may return the combinations in any order.
     * 
     * The same number may be chosen from candidates an umlimited number of times.
     * Two combinations are unique if the frequency of at least one of the chosen numbers is 
     * different.
     * 
     * @param candidates an array of distinct integers
     * @param target a target integer
     * @return a list of all unique combinations of candidates where the chosen numbers sum to target
     */
    vector<vector<int>> combinationSum(vector<int>& candidates, int target);
  
    /* @brief 52. N-Queens II
     *
     * The n-queens puzzle is the problem of place n queens on an n x n chessboard such that 
     * no two queens attack each other.
     * 
     * Given an integer n, return the number of distinct solutions to the n-queens puzzle.
     * 
     * The same number may be chosen from candidates an umlimited number of times.
     * Two combinations are unique if the frequency of at least one of the chosen numbers is 
     * different.
     * 
     * @param n queens on an n x n chessboard
     * @return  the number of distinct solutions to the n-queens puzzle.
     */
    int totalNQueens(int n);

    /* @brief 22. Generate Parentheses
     *
     * Given n pairs of parenthese, write a function to generate all combinations of well-formed parentheses
     * 
     * @param n pairs of parenthese
     * @return well-formed parentheses
     */
    vector<string> generateParenthesis(int n);

    /* @brief 79. Word Search
     *
     * Given an mxn grid of characters board and a string word, return 
     * true if word exists in the grid.
     * 
     * The word can be constructed from letters of sequentially adjacent cells,
     * where adjacent cells are horizontally or vertically neighboring.
     * 
     * The same letter cell may not be used more than once.
     * 
     * @param board an mxn grid of characters
     * @param word a string
     * @return true if word exists in the grid.
     */
    bool exist(vector<vector<char>>& board, string word);

    /* @brief 530. Minimum Absolute Difference in BST
     *
     * Given the root of a Binary Search Tree (BST), return the minimum absolute difference 
     * between the values of any two different nodes in the tree.
     * 
     * @param root the root of a binary tree
     * @return the minimum absolute difference between the values of any two different nodes in the tree.
     */
    int getMinimumDifference(TreeNode* root);

    /* @brief 230. Kth Smallest Element in a BST
     *
     * Given the root of a binary search tree, and an integer k, return the kth smallest value 
     * (1-indexed) of all the values of the nodes in the tree.
     * 
     * @param root the root of a binary tree
     * @return  the kth smallest value (1-indexed) of all the values of the nodes in the tree.
     */
    int kthSmallest(TreeNode* root, int k);

    /* @brief 98. Validate Binary Search Tree
     *
     * Given the root of a binary tree, determine if it is a valid binary search tree (BST).
     * 
     * A valid BST is defined as follows:
     * 
     * The left subtree of a node contains only nodes with keys less than the node's key.
     * The right subtree of a node contains only nodes with keys greater than the node's key.
     * Both the left and right subtrees must also be binary search trees.
     * 
     * @param root the root of a binary tree
     * @return determine if it is a valid binary search tree
     */
     bool isValidBST(TreeNode* root);

     /* @brief 54. Spiral Matrix
     *
     * Given an m x n matrix, return all elements of the matrix in spiral order.
     *
     * @param matrix
     * @return all elements of the matrix in spiral order
     */
     std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix);

     /* @brief 383. Ransom Note
     *
     * Given two strings ransomNote and magazine, return true if
     *  ransomNote can be constructed by using the letters from 
     * magazine and false otherwise.
     * 
     * Each letter in magazine can only be used once in ransomNote.
     *
     * @param ransomNote a string
     * @param magazine a string
     * @return true if ransomNote can be constructed by using the letters
     *  from magazine and false otherwise
     */
     bool canConstruct(std::string ransomNote, std::string magazine);

     /* @brief 205. Isomorphic Strings
     *
     * Given two strings s and t, determine if they are isomorphic.
     * 
     * Two strings s and t are isomorphic if the characters in s can be 
     * replaced to get t.
     * 
     * All occurrences of a character must be replaced with another 
     * character while preserving the order of characters. No two 
     * characters may map to the same character, but a character 
     * may map to itself.
     * 
     * @param s a string
     * @param t a string
     * @return determine if they are isomorphic
     */
     bool isIsomorphic(std::string s, std::string t);

    /* @brief 104. Maximum Depth of Binary Tree
     *
     * Given the root of a binary tree, return its maximum depth.
     * 
     * A binary tree's maximum depth is the number of nodes along the longest path from
     *  the root node down to the farthest leaf node.
     * 
     * @param root the root of a binary tree
     * @return its maximum depth
     */
    int maxDepth(TreeNode* root);

    /* @brief 100. Same Tree
     *
     * Given the roots of two binary trees p and q, write a function to 
     * check if they are the same or not.
     * 
     * Two binary trees are considered the same if they are structurally 
     * identical, and the nodes have the same value.
     * 
     * @param p binary trees
     * @param q binary trees
     * @return if two binary trees are structurally identical, and the nodes have the same value
     */
    bool isSameTree(TreeNode* p, TreeNode* q);

    /* @brief 226. Invert Binary Tree
     *
     * Given the root of a binary tree, invert the tree, and 
     * return its root.
     * 
     * @param root binary tree
     * @return its root
     */
    TreeNode* invertTree(TreeNode* root);

    /* @brief 101. Symmetric Tree
     *
     * Given the root of a binary tree, check whether it is 
     * a mirror of itself (i.e., symmetric around its center).
     * 
     * @param root the root of a binary tree
     * @return check whether it is a mirror of itself
     */
    bool isSymmetric(TreeNode* root);

    /* @brief 105. Construct Binary Tree from Preorder and Inorder Traversal
     *
     * Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder 
     * traversal of the same tree, construct and return the binary tree.
     * 
     * @param preorder the preorder traversal of a binary tree
     * @param inorder the inorder traversal of a binary tree
     * @return the binary tree
     */
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);

    /* @brief 106. Construct Binary Tree from Inorder and Postorder Traversal
     *
     * Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder 
     * traversal of the same tree, construct and return the binary tree.
     * 
     * @param inorder the inorder traversal of a binary tree
     * @param postorder the postorder traversal of a binary tree
     * @return the binary tree
     */
    TreeNode* buildTreeII(vector<int>& inorder, vector<int>& postorder);

    /* @brief 117. Populating Next Right Pointers in Each Node II
     *
     * Populate each next pointer to point to its next right node. If there is
     *  no next right node, the next pointer should be set to NULL.
     * 
     * Initially, all next pointers are set to NULL.
     * 
     * @param root the root of a binary tree
     * @return t Populate each next pointer to point to its next right node
     */
    Node* connect(Node* root);

    /* @brief 114. Flatten Binary Tree to Linked List
     *
     * Given the root of a binary tree, flatten the tree into a "linked list":
     * 
     * The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
     * The "linked list" should be in the same order as a pre-order traversal of the binary tree.
     * 
     * @param root the root of a binary tree
     * @return The "linked list" should be in the same order as a pre-order traversal of the binary tree.
     */
    void flatten(TreeNode* root);

    /* @brief 112. Path Sum
     *
     * Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
     * 
     * A leaf is a node with no children.
     * 
     * @param root the root of a binary tree
     * @param targetSum an integer
     * @return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
     */
    bool hasPathSum(TreeNode* root, int targetSum);

    /* @brief 129. Sum Root to Leaf Numbers
     *
     * You are given the root of a binary tree containing digits from 0 to 9 only.
     * 
     * Each root-to-leaf path in the tree represents a number.
     * 
     * For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
     * Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.
     * 
     * A leaf node is a node with no children.
     * 
     * @param root the root of a binary tree
     * @return the total sum of all root-to-leaf numbers. 
     */
    int sumNumbers(TreeNode* root);

    /* @brief 124. Binary Tree Maximum Path Sum
     *
     * A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
     * 
     * The path sum of a path is the sum of the node's values in the path.
     * 
     * Given the root of a binary tree, return the maximum path sum of any non-empty path.
     * 
     * @param root the root of a binary tree
     * @return the maximum path sum of any non-empty path.
     */
    int maxPathSum(TreeNode* root);

    /* @brief 173. Binary Search Tree Iterator
     *
     * Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):
     * 
     * BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
     * boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
     * int next() Moves the pointer to the right, then returns the number at the pointer.
     * Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.
     * 
     * You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.
     * 
     * @param root the root of a binary tree
     * @return the maximum path sum of any non-empty path.
     */
    // class BSTIterator{};

    /* @brief 222. Count Complete Tree Nodes
     *
     * Given the root of a complete binary tree, return the number of the nodes in the tree.
     * 
     * According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
     * 
     * Design an algorithm that runs in less than O(n) time complexity.
     * 
     * @param root the root of a complete binary tree
     * @return the number of the nodes in the tree.
     */
    int countNodes(TreeNode* root);

    /* @brief 236. Lowest Common Ancestor of a Binary Tree
     *
     * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
     * 
     * According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
     * 
     * @param root the root of a complete binary tree
     * @param p node
     * @param q node
     * @return the lowest common ancestor
     */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);

     /* @brief 290. Word Pattern
     *
     * Given a pattern and a string s, find if s follows 
     * the same pattern.
     * 
     * Here follow means a full match, such that there is 
     * a bijection between a letter in pattern and a non-empty 
     * word in s.
     * 
     * @param s a string
     * @param pattern a string
     * @return if s follows the same pattern
     */
     bool wordPattern(std::string pattern, std::string s);

     /* @brief 228. Summary Ranges
     *
     * You are given a sorted unique integer array nums.
     * 
     * A range [a,b] is the set of all integers from a to b (inclusive).
     * 
     * Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.
     * 
     * Each range [a,b] in the list should be output as:
     * 
     * "a->b" if a != b
     * "a" if a == b
     *
     * @param nums a sorted unique integer array
     * @return the smallest sorted list of ranges that cover all the numbers in the array exactly.
     */
     std::vector<std::string> summaryRanges(std::vector<int>& nums);


     /* @brief 242. Valid Anagram
     *
     * Given two strings s and t, return true if t is an anagram of s, 
     * and false otherwise.
     * 
     * An Anagram is a word or phrase formed by rearranging the 
     * letters of a different word or phrase, typically using all 
     * the original letters exactly once.
     * 
     * @param s a string
     * @param t a string
     * @return if t is an anagram of s, and false otherwise
     */
     bool isAnagram(std::string s, std::string t);

     /* @brief Word Count Engine
     *
     * Implement a document scanning function wordCountEngine, which receives a string document and returns a list of all unique 
     * words in it and their number of occurrences, sorted by the number of occurrences in a descending order. If two or more words 
     * have the same count, they should be sorted according to their order in the original sentence. Assume that all letters are in english alphabet. You function 
     * should be case-insensitive, so for instance, the words “Perfect” and “perfect” should be considered the same word.
     * 
     * @param s a string
     * @param t a string
     * @return if t is an anagram of s, and false otherwise
     */
     std::vector<std::vector<std::string>> word_count_engine(std::string document);

     /* @brief 49. Group Anagrams 
     *
     * Given an array of strings strs, group the anagrams together. You can 
     * return the answer in any order.
     * 
     * An Anagram is a word or phrase formed by rearranging the letters of a 
     * different word or phrase, typically using all the original letters 
     * exactly once.
     * 
     * @param strs a string
     * @return the group the anagrams in any order.
     */
     std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs);

     /* @brief 219. Contains Duplicate II 
     *
     * Given an integer array nums and an integer k, return true if there
     *  are two distinct indices i and j in the array such that nums[i] == 
     * nums[j] and abs(i - j) <= k. 
     * 
     * @param nums an integer array
     * @param k an integer
     * @return true if there are two distinct indices i and j in the 
     * array such that nums[i] == nunms[j]
     */
     bool containsNearbyDuplicate(std::vector<int>& nums, int k);

    /* @brief 283. Move Zeroes
     *
     * Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
     *
     * Note that you must do this in-place without making a copy of the array.
     *
     * @param nums an integer array
     * @return move all 0's to the end of it while maintaining the relative order of the non-zero elements.
     */
     std::vector<int> moveZeroes(vector<int>& nums);


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
