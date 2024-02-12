#include "solutions.h"
#include <numeric>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <queue>
#include <boost/lexical_cast.hpp>

namespace leetcode {

using namespace std;

bool hasCycle(ListNode *head) {
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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (l1 == NULL && l2 == NULL) return l2;
    else if (l1 == NULL) return l2;
    else if (l2 == NULL) return l1;

    int num = l1->val + l2->val;

    ListNode* p = new ListNode( num % 10);
    p->next = addTwoNumbers(l1->next, l2->next);

    if( num >= 10) p->next = addTwoNumbers(p->next, new ListNode(1));

    return p;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
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

ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode *loc = new ListNode(0), *pre = loc, *cur;
    loc->next = head;

    for(int i = 0; i < left - 1; i++) {
        pre = pre->next;
    }
    cur = pre->next;

    for(int i = 0; i < right - left; i++) {
        ListNode* temp = pre->next;
        pre->next = cur->next;
        cur->next = cur->next->next;
        pre->next->next = temp;
    }

    return loc->next;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode * loc = head;
    for(int i = 0; i < k; i++) {
        if(loc == nullptr) return head;
        loc = loc->next;
    }

    ListNode* pre = nullptr;
    ListNode* cur = head;
    ListNode* tmp = nullptr;

    for(int i = 0; i < k ; i ++) {
        tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }

    head->next = reverseKGroup(cur, k);

    return pre;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
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

ListNode* deleteDuplicates(ListNode* head) {
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

ListNode* rotateRight(ListNode* head, int k) {
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

ListNode* partition(ListNode* head, int x) {
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

Node* copyRandomList(Node* head) {
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

















} /* namespace leetcode */
