#include "helpers.h"

#include <cassert>
#include <cstdlib>
// 19. Remove Nth Node From End of List
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
//
// Given the head of a linked list
// Remove the N-th node from the end of the list and
// Return its head
class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    // dummy gives the head for a previous node
    // so deleting the head will be in same way as for other nodes
    ListNode dummy(0);
    dummy.next = head;

    ListNode *fast = &dummy; // fast moves n nodes from the first
    ListNode *slow = &dummy; // when fast reaches the last node,
                             // slow is before the node to remove

    for (int i = 0; i < n; i++) {
      fast = fast->next;
    }

    // move both together until fast will reach the last node
    while (fast->next != nullptr) {
      fast = fast->next;
      slow = slow->next;
    }

    // slow is before the target to remove
    ListNode *toRemove = slow->next;
    assert(toRemove != nullptr);

    slow->next = toRemove->next; // skip deleted node
    delete toRemove;

    return dummy.next; // actual head after the removal
  }
};

void runTest(std::initializer_list<int> a, int n) {
  static Solution s;
  ListNode *l1 = buildList(a);
  ListNode *res = s.removeNthFromEnd(l1, n);
  printList(res);
  freeList(l1);
  assert(res != nullptr);
}

int main() {
  runTest({1, 2, 3, 4, 5}, 2); // expected: [1,2,3,5]
  // runTest({1}, 1);             // expected: []
  // runTest({1, 2}, 1);          // expected: [1]
}