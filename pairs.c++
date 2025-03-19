#include <iostream>
#include <utility>
#include <vector>

// Pairs are a part of Utility header.

int main() {

  std::cout << "Vector of pairs: " << std::endl;
  std::vector<std::pair<int, int>> vec{{1, 2}, {3, 4}, {5, 6}};
  for (auto &x : vec) {
    std::cout << " => " << x.first << " " << x.second << std::endl;
  }

  // std::pair<std::vector<std::pair<std::pair<char,int>,std::vector<int>>>std::pair<std::pair<char,std::vector<char>>,std::vector<int>>>
  // pair(vec(pair(pair(ch,ch), vec(int)), pair(pair(ch,vec(ch)), vec(int)))
  std::pair<std::vector<std::pair<std::pair<char, int>, std::vector<int>>>,
            std::pair<std::pair<char, std::vector<char>>, std::vector<int>>>
      vals{
          // First part of the outer pair (std::vector of pairs of (pair<char,
          // int>, vector<int>))
          {
              {{'c', 10},
               {10, 20, 30}} // First pair with char, int and vector<int>
          },
          // Second part of the outer pair (pair<char, vector<char>> and
          // vector<int>)
          {{'a', {'b', 'c', 'd'}},
           {1, 2, 3}} // First pair with char, vector<char> and vector<int>
      };

  // Outermost pair first part.
  std::cout << "First part of the outermost pair<>: " << std::endl;
  std::cout << "pair(vec(pair(pair(ch,ch), vec(int)), ): ";
  for (auto &i : vals.first) {
    std::cout << i.first.first << ", " << i.first.second << std::endl;
    std::cout << "Vector of ints: [";
    for (auto &j : i.second) {
      std::cout << j << ", ";
    }
  }
  std::cout << "]" << std::endl;

  // Outermost pair second part.
  std::cout << "Second part of the outermost pair<>: " << std::endl;
  std::cout << "pair(, pair(pair(ch,vec(ch)), vec(int))): "
            << vals.second.first.first << " | [";
  for (auto &x : vals.second.first.second) {
    std::cout << x << ", ";
  }
  std::cout << "]" << std::endl;

  std::cout << "Second element of the outer pair - vec(int): ";
  for (auto &x : vals.second.second) {
    std::cout << x << ", ";
  }
  std::cout << std::endl;

  return 0;
}