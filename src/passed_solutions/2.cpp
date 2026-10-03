#include <cstdio>
#include <vector>
using std::vector;

// 2. Add Two Numbers - https://leetcode.com/problems/add-two-numbers/
/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *buildList(const std::vector<int> &v) {
  ListNode dummy(0);
  ListNode *tail = &dummy;
  for (int x : v) {
    tail->next = new ListNode(x);
    tail = tail->next;
  }
  return dummy.next;
}

void printList(const ListNode *head) {
  for (const ListNode *p = head; p != nullptr; p = p->next) {
    if (p != head)
      printf(" ");
    printf("%d", p->val);
  }
  printf("\n");
}
void freeList(ListNode *head) {
  while (head != nullptr) {
    ListNode *t = head; // запомнили текущий
    head = head->next;  // сдвинулись дальше
    delete t;           // освободили запомненный
  }
}

class Solution2 {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode dummy(0);
    ListNode *lastDigit = &dummy;
    int carry = 0; // carry-over from the prev digit
    int sum;
    int digitsToWrite;

    // Loop conds:
    // 1. Lists still have digits
    // 2. Pending carry from the prev column still exists
    while (l1 != nullptr || l2 != nullptr || carry) {
      sum = carry; // start the sum from incoming carry

      // sum values from lists and go to next values
      if (l1) {
        sum += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        sum += l2->val;
        l2 = l2->next;
      }

      digitsToWrite = sum % 10; // write the remainder as current digit (12 -> 2)
      carry = sum / 10; // go to next carry (12 -> 1)

      // add the new node with current digit and go to next node
      lastDigit->next = new ListNode(digitsToWrite);
      lastDigit = lastDigit->next;
    }

    // both lists ended and no carry remains
    return dummy.next;
  }
};

void runTest(Solution2 &s, std::initializer_list<int> a,
             std::initializer_list<int> b) {
  ListNode *l1 = buildList(a);
  ListNode *l2 = buildList(b);
  ListNode *res = s.addTwoNumbers(l1, l2);
  printList(res);
  freeList(l1);
  freeList(l2);
  freeList(res);
}

int main() {
  Solution2 s;
  runTest(s, {2, 4, 3}, {5, 6, 4}); // [7,0,8]
  runTest(s, {0}, {0}); // [0]
  runTest(s, {9, 9, 9, 9, 9, 9, 9}, {9, 9, 9, 9}); // [8,9,9,9,0,0,0,1]
  runTest(s, {9}, {1, 9, 9, 9, 9, 9, 9, 9, 9, 9}); // [0,0,0,0,0,0,0,0,0,0,1]
  runTest(
      s, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {5, 6,
       4}); // [6,6,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1]
  return 0;
}