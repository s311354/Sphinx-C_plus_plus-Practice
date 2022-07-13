


#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <regex>

namespace leetcode
{

static const std::regex INT_TYPE("[+-]?[0-9]+");
static const std::regex UNSIGNED_INT_TYPE("[+]?[0-9]+");
static const std::regex DOUBLE_TYPE("[+-]?[0-9]+[.]?[0-9]+");
static const std::regex UNSIGNED_DOUBLE_TYPE("[+]?[0-9]+[.]?[0-9]+");

#define ROW 4
#define COLUMN 4

struct TreeNode
{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode * left, TreeNode * right) : val(0), left(left), right(right) {};

};

struct LinkedListNode {
    /* data */
    int val;
    LinkedListNode * next;
    LinkedListNode() : val(0), next(nullptr) {}
    LinkedListNode(int x) : val(x), next(nullptr) {}
    LinkedListNode(int x, LinkedListNode *next) : val(x), next(next) {}
};

} /* leetcode */ 

#endif /* UTILS_H */
