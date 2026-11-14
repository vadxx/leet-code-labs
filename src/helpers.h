#pragma once

#include <iostream>
#include <string>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

inline ListNode *buildList(const std::initializer_list<int> &list) {
  ListNode dummy(0);
  ListNode *tail = &dummy;
  for (int x : list) {
    tail->next = new ListNode(x);
    tail = tail->next;
  }
  return dummy.next;
}

inline void printList(const ListNode *head) {
  for (const ListNode *p = head; p != nullptr; p = p->next) {
    if (p != head)
      printf(" ");
    printf("%d", p->val);
  }
  printf("\n");
}

inline void freeList(ListNode *head) {
  while (head != nullptr) {
    ListNode *t = head; // запомнили текущий
    head = head->next;  // сдвинулись дальше
    delete t;           // освободили запомненный
  }
}
template <typename T> T &as_lvalue(T &&val) { return val; }

template <typename T> void print_value(const T &value) { std::cout << value; }

template <typename T> void print_value(const std::vector<T> &v) {
  std::cout << '[';
  const char *separator = "";

  for (const auto &value : v) {
    std::cout << separator;
    print_value(value);
    separator = ",";
  }

  std::cout << ']';
}

template <typename T> void print_vector(const std::vector<T> &v) {
  for (const auto &value : v) {
    print_value(value);
  }
  std::cout << '\n';
}
