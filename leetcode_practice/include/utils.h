


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
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, std::unique_ptr<TreeNode> left, std::unique_ptr<TreeNode> right) : val(x), left(std::move(left)), right(std::move(right)) {};

    int val;
    std::unique_ptr<TreeNode> left;
    std::unique_ptr<TreeNode> right;
};

struct LinkedListNode {
    LinkedListNode() : val(0), next(nullptr) {}
    LinkedListNode(int x) : val(x), next(nullptr) {}
    LinkedListNode(int x, std::unique_ptr<LinkedListNode> next) : val(x), next(std::move(next)) {}

    /* data */
    int val;
    std::unique_ptr<LinkedListNode> next;
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
};

} /* leetcode */ 

#endif /* UTILS_H */
