#include "solutions.h"
#include <numeric>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <queue>
#include <boost/lexical_cast.hpp>

namespace leetcode {

bool Solutions::hasCycle(std::unique_ptr<leetcode::LinkedListNode> * head, int pos) {

}

std::unique_ptr<LinkedListNode> Solutions::addTwoNumbers(std::unique_ptr<LinkedListNode> l1, std::unique_ptr<LinkedListNode> l2)
{
    if(l1 == NULL && l2 == NULL) return l2;
    else if (l1 == NULL) return l2;
    else if (l2 == NULL) return l1;

    int num = l1->val + l2->val;

    std::unique_ptr<LinkedListNode> node (new LinkedListNode(num%10));
    node->next = std::move(addTwoNumbers(std::move(l1->next), std::move(l2->next)));

    std::unique_ptr<LinkedListNode> round (new LinkedListNode(1));   
    if(num >= 10) node->next = addTwoNumbers(std::move(node->next), std::move(round));

    return node;
}

std::unique_ptr<LinkedListNode> Solutions::getNewHead(int value)
{
    std::unique_ptr<LinkedListNode> node(new LinkedListNode(value, nullptr));

    return node;
}

std::unique_ptr<LinkedListNode> Solutions::reversedLinkedList(std::unique_ptr<LinkedListNode> l1)
{
    if (l1 == nullptr) return getNewHead(0);

    std::unique_ptr<LinkedListNode> prev, next = nullptr;

    while (l1 != nullptr) {
        next = std::move(l1->next);
        l1->next = std::move(prev);
        prev = std::move(l1);
        l1 = std::move(next);
    }

    return prev;
}

std::unique_ptr<LinkedListNode> Solutions::deleteDuplicates(std::unique_ptr<LinkedListNode> head)
{
    if (!head) return head;

    std::unique_ptr<LinkedListNode> tmp(std::move(head));

    while (tmp && tmp->next) {
        if (tmp->val == tmp->next->val)
            tmp->next = std::move(tmp->next->next);
        else tmp = std::move(tmp->next);
        head = insertLinkedlistNode(std::move(head), tmp->val);
    }

    return head;
}

std::unique_ptr<LinkedListNode> Solutions::insertLinkedlistNode(std::unique_ptr<LinkedListNode> node, int value)
{
    if (node == nullptr) {

        if (value != -1) node = getNewHead(value);
        return node;
    }

    node->next = insertLinkedlistNode(std::move(node->next), value);

    return node;
}

} /* namespace leetcode */
