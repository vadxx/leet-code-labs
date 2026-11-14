#include "helpers.h"

#include <cassert>
#include <cstdlib>
#include <initializer_list>

// 21. Merge Two Sorted Lists
// https://leetcode.com/problems/merge-two-sorted-lists/description
//
// Given the heads of two sorted linked lists list1 and list2.
// The list should be made by splicing together the nodes of the first two
// lists. Return the head of the merged linked list.
class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode dummy(0);
    ListNode *tail = &dummy;

    auto moveTail = [&](ListNode *&node) {
      tail->next = node; // prev node points to the new node
      tail = node;       // set the new node to the end of result
      node = node->next;
    };

    while (list1 && list2) {
      moveTail(list1->val <= list2->val ? list1 : list2);
    }
    tail->next = list1 ? list1 : list2;
    return dummy.next;
  }
};

void runTest(std::initializer_list<int> a, std::initializer_list<int> b) {
  static Solution s;
  ListNode *l1 = buildList(a);
  ListNode *l2 = buildList(b);
  ListNode *res = s.mergeTwoLists(l1, l2);
  printList(res);
  freeList(res);
}

int main() {
  runTest({1, 2, 4}, {1, 3, 4}); // expected: 1,1,2,3,4,4
  runTest({}, {});               // expected: {}
  runTest({}, {0});              // expected: {0}
}
