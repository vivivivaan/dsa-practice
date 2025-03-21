// Same as map but can have duplicate keys.
// [] can't be used, insert() or emplace() is used to add data.
// O(log_n) as it is internally implemented as self-balancing tree.

#include <iostream>
#include <map>

int main() {
  std::multimap<std::string, int> mmap;

  mmap.insert({"age", 25});
  mmap.emplace("height", 177);
  mmap.insert({"weight", 70});
  mmap.emplace("yob", 1999);
  mmap.insert({"bmi", 22});
  mmap.insert({"age", 25});
  mmap.emplace("height", 177);
  mmap.insert({"weight", 70});
  mmap.emplace("yob", 1999);
  mmap.insert({"bmi", 22});

  for (auto &x : mmap) {
    std::cout << x.first << " : " << x.second << std::endl;
  }

  mmap.erase("bmi");
  std::cout << "\nErasing BMI data..\n" << std::endl;

  for (auto &x : mmap) {
    std::cout << x.first << " : " << x.second << std::endl;
  }
}