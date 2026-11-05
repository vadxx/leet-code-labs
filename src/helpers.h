#pragma once

#include <iostream>
#include <string>
#include <vector>

template <typename T> T &as_lvalue(T &&val) { return val; }

template <typename T> void print_value(const T &value) { std::cout << value; }

template <typename T>
void print_value(const std::vector<T>& v) {
    std::cout << '[';
    const char* separator = "";

    for (const auto& value : v) {
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


