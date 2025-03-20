#include <functional>
#include <iostream>
#include <queue>
#include <vector>

// Priority queue - complete binary tree [CBT]: Maxheap and Minheap.

int main() {

  // Default priority queue is maxheap.
  std::priority_queue<int> mxh;

  for (int i = 1; i <= 7; i++) {
    mxh.push(i * 20);
  }

  std::cout << "Size: " << mxh.size() << " | ";
  std::cout << "Priority queue (maxheap): ";

  while (!mxh.empty()) {
    std::cout << mxh.top() << " ";
    mxh.pop();
  }

  std::cout << " | Top: " << mxh.top() << std::endl;

  // Minheap using functors such std::greater<int> comparator.
  // Or, say, std::greater<int> is a comparator functor.
  std::priority_queue<int, std::vector<int>, std::greater<int>> mih;

  for (int i = 1; i <= 5; i++) {
    mih.push(i * 50);
  }

  std::cout << "Size: " << mih.size() << " | ";
  std::cout << "Priority queue (minheap): ";

  while (!mih.empty()) {
    std::cout << mih.top() << " ";
    mih.pop();
  }

  std::cout << " | Top: " << mih.top() << std::endl;

  // Remaining all methods are same as in queue.
  // emplace(), swap(), front()
}