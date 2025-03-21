// O(1) for things like erase, count, insert.
// Works same as map, multimap for majority of the things.

#include <iostream>
#include <unordered_map>

int main() {
  std::unordered_map<std::string, int> umap;

  umap["age"] = 25;
  umap["bmi"] = 22;
  umap["height"] = 177;
  umap["weight"] = 70;
  umap["yob"] = 1999;

  // Duplicates not allowed.
  umap["age"] = 25;
  umap["bmi"] = 22;
  umap["height"] = 177;
  umap["weight"] = 70;
  umap["yob"] = 1999;

  for (auto i = umap.begin(); i != umap.end(); i++) {
    std::cout << i->first << " : " << i->second << std::endl;
  }
}