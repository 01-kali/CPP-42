
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <map>
#include <algorithm>
#include <climits>
#include <cerrno>
#include <ctime>
#include <exception>

class PmergeMe{
private:
  std::vector<int> vect_;
  std::deque<int> deq_;
public:
  PmergeMe();
  PmergeMe(char **&argv);
  PmergeMe(const PmergeMe &nw);
  PmergeMe &operator=(const PmergeMe &nw);
  ~PmergeMe();

  size_t BinarySearchBlockVect(const std::vector<int> &main, int &val, size_t &pair_size, size_t &right_bound);
void SortVect(size_t pair_size);
size_t BinarySearchBlockDeq(const std::deque<int> &main, int &val, size_t &pair_size, size_t &right_bound);
void SortDeq(size_t pair_size);
};

#endif
