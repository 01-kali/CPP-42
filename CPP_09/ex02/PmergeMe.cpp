#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &nw) : vect_(nw.vect_), deq_(nw.deq_) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &nw) {
  if (this != &nw) {
    vect_ = nw.vect_;
    deq_ = nw.deq_;
  }
  return *this;
}

PmergeMe::~PmergeMe() {}

size_t PmergeMe::BinarySearchBlockVect(const std::vector<int> &main, int &val, size_t &pair_size, size_t &right_bound) {
  size_t left = 0;
  size_t right = right_bound;

  while (left < right) {
    size_t mid = left + (right - left) / 2;
    if (main[(mid + 1) * pair_size - 1] < val)
      left = mid + 1;
    else
      right = mid;
  }
  return left;
}

void PmergeMe::SortVect(size_t pair_size) {
  if (vect_.size() < pair_size * 2) return;

  size_t step = pair_size * 2;

  for (size_t i = 0; i + step <= vect_.size(); i += step) {
    if (vect_[i + pair_size - 1] > vect_[i + step - 1])
      std::swap_ranges(vect_.begin() + i, vect_.begin() + i + pair_size, vect_.begin() + i + pair_size);
  }

  SortVect(pair_size * 2);

  std::vector<int> main;
  std::vector<std::vector<int> > pend;
  std::vector<int> non_participating;

  size_t num_pairs = vect_.size() / step;

  main.insert(main.end(), vect_.begin(), vect_.begin() + pair_size);
  main.insert(main.end(), vect_.begin() + pair_size, vect_.begin() + step);

  for (size_t i = 1; i < num_pairs; ++i) {
    size_t b_start = i * step;
    size_t a_start = i * step + pair_size;

    std::vector<int> b_block(vect_.begin() + b_start, vect_.begin() + b_start + pair_size);
    pend.push_back(b_block);

    main.insert(main.end(), vect_.begin() + a_start, vect_.begin() + a_start + pair_size);
  }

  if ((vect_.size() % step) >= pair_size) {
    size_t b_start = num_pairs * step;
    std::vector<int> b_block(vect_.begin() + b_start, vect_.begin() + b_start + pair_size);
    pend.push_back(b_block);
  }

  size_t non_participating_start = (vect_.size() / pair_size) * pair_size;
  for (size_t i = non_participating_start; i < vect_.size(); ++i)
    non_participating.push_back(vect_[i]);

  std::vector<size_t> jacobsthal_seq;
  jacobsthal_seq.push_back(3);
  jacobsthal_seq.push_back(5);

  while (jacobsthal_seq.back() <= pend.size()) {
    size_t next_j = jacobsthal_seq.back() + 2 * jacobsthal_seq[jacobsthal_seq.size() - 2];
    jacobsthal_seq.push_back(next_j);
  }

  size_t last_pos = 0;
  size_t added_count = 0;

  for (size_t i = 0; i < jacobsthal_seq.size(); ++i) {
    size_t limit = jacobsthal_seq[i] - 1;
    if (limit > pend.size()) limit = pend.size();

    for (size_t j = limit; j > last_pos; --j) {
      const std::vector<int> &b_block = pend[j - 1];
      int val = b_block.back();

      size_t right_bound = j + 1 + added_count;

      size_t current_main_size = main.size() / pair_size;

      if (right_bound > current_main_size)
        right_bound = current_main_size;

      size_t block_idx = BinarySearchBlockVect(main, val, pair_size, right_bound);

      std::vector<int>::iterator insert_pos = main.begin() + (block_idx * pair_size);
      main.insert(insert_pos, b_block.begin(), b_block.end());

      added_count++;
    }
    last_pos = limit;
  }

  if (!non_participating.empty())
    main.insert(main.end(), non_participating.begin(), non_participating.end());

  vect_ = main;
}

size_t PmergeMe::BinarySearchBlockDeq(const std::deque<int> &main, int &val, size_t &pair_size, size_t &right_bound) {
  size_t left = 0;
  size_t right = right_bound;

  while (left < right) {
    size_t mid = left + (right - left) / 2;
    if (main[(mid + 1) * pair_size - 1] < val)
      left = mid + 1;
    else
      right = mid;
  }
  return left;
}

void PmergeMe::SortDeq(size_t pair_size) {
  if (deq_.size() < pair_size * 2) return;

  size_t step = pair_size * 2;

  for (size_t i = 0; i + step <= deq_.size(); i += step) {
    if (deq_[i + pair_size - 1] > deq_[i + step - 1])
      std::swap_ranges(deq_.begin() + i, deq_.begin() + i + pair_size, deq_.begin() + i + pair_size);
  }

  SortDeq(pair_size * 2);

  std::deque<int> main;
  std::deque<std::deque<int> > pend;
  std::deque<int> non_participating;

  size_t num_pairs = deq_.size() / step;

  main.insert(main.end(), deq_.begin(), deq_.begin() + pair_size);
  main.insert(main.end(), deq_.begin() + pair_size, deq_.begin() + step);

  for (size_t i = 1; i < num_pairs; ++i) {
    size_t b_start = i * step;
    size_t a_start = i * step + pair_size;

    std::deque<int> b_block(deq_.begin() + b_start, deq_.begin() + b_start + pair_size);
    pend.push_back(b_block);

    main.insert(main.end(), deq_.begin() + a_start, deq_.begin() + a_start + pair_size);
  }

  if ((deq_.size() % step) >= pair_size) {
    size_t b_start = num_pairs * step;
    std::deque<int> b_block(deq_.begin() + b_start, deq_.begin() + b_start + pair_size);
    pend.push_back(b_block);
  }

  size_t non_participating_start = (deq_.size() / pair_size) * pair_size;
  for (size_t i = non_participating_start; i < deq_.size(); ++i)
    non_participating.push_back(deq_[i]);

  std::deque<size_t> jacobsthal_seq;
  jacobsthal_seq.push_back(3);
  jacobsthal_seq.push_back(5);

  while (jacobsthal_seq.back() <= pend.size()) {
    size_t next_j = jacobsthal_seq.back() + 2 * jacobsthal_seq[jacobsthal_seq.size() - 2];
    jacobsthal_seq.push_back(next_j);
  }

  size_t last_pos = 0;
  size_t added_count = 0;

  for (size_t i = 0; i < jacobsthal_seq.size(); ++i) {
    size_t limit = jacobsthal_seq[i] - 1;
    if (limit > pend.size()) limit = pend.size();

    for (size_t j = limit; j > last_pos; --j) {
      const std::deque<int> &b_block = pend[j - 1];
      int val = b_block.back();

      size_t right_bound = j + 1 + added_count;

      size_t current_main_size = main.size() / pair_size;

      if (right_bound > current_main_size)
        right_bound = current_main_size;

      size_t block_idx = BinarySearchBlockDeq(main, val, pair_size, right_bound);

      std::deque<int>::iterator insert_pos = main.begin() + (block_idx * pair_size);
      main.insert(insert_pos, b_block.begin(), b_block.end());

      added_count++;
    }
    last_pos = limit;
  }

  if (!non_participating.empty())
    main.insert(main.end(), non_participating.begin(), non_participating.end());

  deq_ = main;
}

void Parser(char **&argv, std::vector<int> &values){
  char* end;
  long value;

  for (; *argv != NULL; ++argv) {

    if(**argv == '\0')
      throw std::runtime_error("Error: invalid characters.");

    std::stringstream ss(*argv);
    std::string temp;

    while (ss >> temp){
      value = strtol(temp.c_str(), &end, 10);

      if (errno == ERANGE)
        throw std::runtime_error("Error: Number is way too big.");

      if (end == temp.c_str() || *end != '\0')
        throw std::runtime_error("Error: invalid characters: \"" + temp + "\".");

      if(value > INT_MAX || value < INT_MIN)
        throw std::runtime_error("Error: " + temp + " is too large/small for an integer.");

      if (value < 0)
        throw std::runtime_error("Error: Negative number detected: \"" + temp + "\".");

      if (std::find(values.begin(), values.end(), static_cast<int>(value)) != values.end())
        throw std::runtime_error("Error: Duplicate number detected: \"" + temp + "\".");

      values.push_back(static_cast<int>(value));
    }
  }
}

PmergeMe::PmergeMe(char **&argv) {
  argv++;

  std::vector<int> values;
  Parser(argv, values);
  
  std::cout << "Before: ";
  for (std::vector<int>::iterator it = values.begin(); it != values.end(); it++)
    std::cout << *it << " ";
  std::cout << std::endl;

  for (std::vector<int>::iterator it = values.begin(); it != values.end(); it++)
    deq_.push_back(*it);
  vect_ = values;

  clock_t start_v = clock();
  SortVect(1);
  clock_t end_v = clock();
  double time_v = static_cast<double>(end_v - start_v) / CLOCKS_PER_SEC * 1000000;

  std::cout << "After:  ";
  for (std::vector<int>::iterator itt = vect_.begin(); itt != vect_.end(); itt++)
    std::cout << *itt << " ";
  std::cout << std::endl;

  std::cout << "Time to process a range of " << vect_.size() 
    << " elements with std::vector : " << time_v << " us" << std::endl;

  start_v = clock();
  SortDeq(1);
  end_v = clock();
  time_v = static_cast<double>(end_v - start_v) / CLOCKS_PER_SEC * 1000000;
  std::cout << "Time to process a range of " << deq_.size() 
    << " elements with std::deque : " << time_v << " us" << std::endl;
}
