#include <MutantStack.hpp>

int main(){
  {
    std::cout << "the subject test:" << std::endl;
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);

    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;

    while (it != ite)
    {
      std::cout << *it << std::endl;
      ++it;
    }
    std::stack<int> s(mstack);
    std::cout << std::endl;
  }
  {
    std::cout << "test with list instead of stack:" << std::endl;
    std::list<int> list;

    list.push_back(5);
    list.push_back(17);

    std::cout << list.back() << std::endl;

    list.pop_back();

    std::cout << list.size() << std::endl;

    list.push_back(3);
    list.push_back(5);
    list.push_back(737);

    list.push_back(0);

    std::list<int>::iterator it = list.begin();
    std::list<int>::iterator ite = list.end();
    ++it;
    --it;

    while (it != ite)
    {
      std::cout << *it << std::endl;
      ++it;
    }
    std::stack<int, std::list<int> > s(list);
    std::cout << std::endl;
  }
  {
    std::cout << "stack with vector:" << std::endl;
    MutantStack<int, std::vector<int> > stack_with_vector;

    stack_with_vector.push(5);
    stack_with_vector.push(17);

    std::cout << stack_with_vector.top() << std::endl;

    stack_with_vector.pop();

    std::cout << stack_with_vector.size() << std::endl;

    stack_with_vector.push(3);
    stack_with_vector.push(5);
    stack_with_vector.push(737);

    stack_with_vector.push(0);

    MutantStack<int, std::vector<int> >::iterator it = stack_with_vector.begin();
    MutantStack<int, std::vector<int> >::iterator ite = stack_with_vector.end();
    ++it;
    --it;

    while (it != ite)
    {
      std::cout << *it << std::endl;
      ++it;
    }
    std::stack<int, std::vector<int> > s(stack_with_vector);
  }
  return 0;
}
