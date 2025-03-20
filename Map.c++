#include <iostream>
#include <map>

int main() {
  std::map<std::string, int> dict;

  std::cout << "# Basic map demo # " << std::endl;

  // Keys are sorted alphabetically by default.
  // Uppercase is prioritized as ASCII of A is 65
  // and ASCII of a is 97.

  dict["age"] = 25;
  dict["height"] = 177;
  dict["weight"] = 70;
  dict["yob"] = 1999;
  dict["bmi"] = 22.1;

  for (auto &x : dict) {
    std::cout << x.first << " : " << x.second << std::endl;
  }

  std::cout << "\nInserting new k/v into the map: " << std::endl;

  dict.insert({"thinkPad_PSeries", 15});

  for (auto &x : dict) {
    std::cout << x.first << " : " << x.second << std::endl;
  }

  std::cout << "\nEmplacing new k/v into the map: " << std::endl;

  dict.emplace("RAM_GB", 24);

  for (auto &x : dict) {
    std::cout << x.first << " : " << x.second << std::endl;
  }

  std::cout << "\nPrinting map using iterators: " << std::endl;

  for (auto i = dict.begin(); i != dict.end(); i++) {
    std::cout << i->first << " : " << i->second << std::endl;
  }

  // Count the number of key instances.
  std::cout << "\nCount of BMI: " << dict.count("bmi")
            << " | BMI Value: " << dict["bmi"] << std::endl;

  std::cout << "\nErasing a key.. " << std::endl;

  // Erase uppercase key(s)
  dict.erase("RAM_GB");

  std::cout << "Removed capital letter key: " << std::endl;

  for (auto itr = dict.begin(); itr != dict.end(); itr++) {
    std::cout << itr->first << " : " << itr->second << std::endl;
  }

  std::cout << "\nTrying to find a key.." << std::endl;

  // .find() - found: return itr else: m.end() which is a random or garbage
  // value.
  if (dict.find("RAM_GB") != dict.end()) {
    std::cout << "Found 'RAM_GB' key!" << std::endl;
  } else {
    std::cout << "Didn't find the 'RAM_GB' key!" << std::endl;
  }

  // Other remaining functions: size(), empty() and more.

  std::cout << "\nErasing a key.. " << std::endl;

  dict.erase("thinkPad_PSeries");

  if (dict.find("thinkpad_PSeries") == dict.end()) {
    std::cout << "Successfully deleted the 'thinkpad_PSeries' key."
              << std::endl;
    for (auto itr = dict.begin(); itr != dict.end(); itr++) {
      std::cout << itr->first << " : " << itr->second << std::endl;
    }
  } else {
    std::cout << "Couldn't delete the key OR couldn't find the key"
              << std::endl;
  }
}