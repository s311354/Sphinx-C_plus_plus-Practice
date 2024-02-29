#include "solutions.h"
#include <numeric>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <queue>
#include <boost/lexical_cast.hpp>

namespace leetcode {

using namespace std;

bool Solutions::hasCycle(ListNode *head) {
    if (head == NULL) return false;

    ListNode *fast = head;
    ListNode *slow = head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow) return true;
    }

    return false;
}
/*
Input: head = [3,2,0,-4], pos = 1
Output: true
*/


ListNode* Solutions::addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (l1 == NULL && l2 == NULL) return l2;
    else if (l1 == NULL) return l2;
    else if (l2 == NULL) return l1;

    int num = l1->val + l2->val;

    ListNode* p = new ListNode( num % 10);
    p->next = addTwoNumbers(l1->next, l2->next);

    if( num >= 10) p->next = addTwoNumbers(p->next, new ListNode(1));

    return p;
}
/*
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
*/


ListNode* Solutions::mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 != NULL && list2 != NULL) {
        if(list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }

    }
    if(list1 == NULL) return list2;
    return list1;
}
/*
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
*/


ListNode* Solutions::reverseList(ListNode* head) {
    ListNode *next, *prev = NULL;

    while (head) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
/*
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
*/


ListNode* Solutions::reverseBetween(ListNode* head, int left, int right) {

    if (!head || left == right) return head;
    
    ListNode loc(0);
    loc.next = head;
    ListNode* prev = &loc;
    
    for (int i = 0; i < left - 1; ++i) {
        prev = prev->next;
    }
    
    ListNode* current = prev->next;
    
    for (int i = 0; i < right - left; ++i) {
        ListNode* next = current->next;
        current->next = temp->next;
        temp->next = prev->next;
        prev->next = next;
    }
    
    return loc.next;
}
/*
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
*/


ListNode* Solutions::reverseKGroup(ListNode* head, int k) {

    if (!head || k == 0) return head;

    // Checker 
    ListNode * loc = head;
    for(int i = 0; i < k; i++) {
        if( loc == nullptr ) return head;
        loc = loc->next;
    }

    ListNode* pre = nullptr;
    ListNode* cur = head;

    for(int i = 0; i < k ; i ++) {
        ListNode* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }

    head->next = reverseKGroup(cur, k);

    return pre;
}
/*
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
*/


ListNode* Solutions::removeNthFromEnd(ListNode* head, int n) {
    ListNode *fast = head, *slow = head;

    for(int i = 0; i < n ; i ++) fast = fast->next;

    if (fast == nullptr) return head->next;

    while(fast->next) {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    return head;
}
/*
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
*/


ListNode* Solutions::deleteDuplicates(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return head;

    ListNode *cur = head, *prev = nullptr;

    while (cur != nullptr && cur->next != nullptr) {
        if(cur->val == cur->next->val) {
            while(cur->next != nullptr && cur->val == cur->next->val) {
                cur = cur->next;
            }

            if(prev == nullptr) head = cur->next;
            else prev->next = cur->next;

            cur = cur->next;
        } else {
            prev = cur;
            cur = cur->next;
        }
    }

    return head;
}
/*
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
*/



ListNode* Solutions::rotateRight(ListNode* head, int k) {
    if(head == nullptr || head->next == nullptr || k == 0)
        return head;

    ListNode* cur = head;
    int len = 1;
    
    while (cur->next != nullptr) {
        cur = cur->next;
        ++len;
    }

    cur->next = head;
    k = k%len;
    k = len - k;

    while(k--) cur = cur->next;

    head = cur->next;
    cur->next = nullptr;

    return head;
}
/*
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
*/


ListNode* Solutios::partition(ListNode* head, int x) {
    ListNode* small = new ListNode(0);
    ListNode* large = new ListNode(0);
    ListNode* small_head = small;
    ListNode* large_head = large;
    
    while (head){
        if (head->val < x){
            small->next = head;
            small = small->next;
            head = head -> next;
            small->next = NULL;
        }
        else{
            large->next = head;
            large = large->next;
            head = head->next;
            large->next = NULL;
        }
    }

    small->next = large_head->next;

    return small_head->next;
}
/*
Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
*/


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

Node* Solutions::copyRandomList(Node* head) {
    if(!head) return nullptr;

    std::unordered_map<Node*, Node*> orig_to_copy;

    Node* orig = head;

    while(orig) {
        orig_to_copy[orig] = new Node(orig->val);
        orig = orig->next;
    }

    orig = head;

    while(orig) {
        orig_to_copy[orig]->next = orig_to_copy[orig->next];
        orig_to_copy[orig]->random = orig_to_copy[orig->random];
        orig = orig->next;
    }

    return orig_to_copy[head];
}
/*
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
*/

} /* namespace leetcode */
