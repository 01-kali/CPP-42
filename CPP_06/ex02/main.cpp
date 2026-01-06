#include <typeinfo>
#include <Base.hpp>
#include <A.hpp>
#include <B.hpp>
#include <C.hpp>
#include <cstdlib>

Base* generate(void){
  unsigned int seed;
  int rd_num;

  seed = time(0);
  rd_num = rand_r(&seed) % (2 - 0 + 1);
  switch (rd_num) {
    case 0:
      return new A();
      break;
    case 1:
      return new B();
      break;
    default:
      return new C();
      break;
  }
}

void identify(Base* p){
  A *a;
  B *b;
  C *c;
  if((a = dynamic_cast<A*>(p)))
      std::cout << "A" << std::endl;
  else if((b = dynamic_cast<B*>(p)))
      std::cout << "B" << std::endl;
  else if((c =dynamic_cast<C*>(p)))
      std::cout << "C" << std::endl;
}

void identify(Base& p){
  try {
    (void)dynamic_cast<A&>(p);
    std::cout << "A" << std::endl;
  }
  catch (const std::exception &e) {}
  try {
    (void)dynamic_cast<B&>(p);
    std::cout << "B" << std::endl;
  }
  catch (const std::exception &e) {}
  try {
    (void)dynamic_cast<C&>(p);
    std::cout << "C" << std::endl;
  }
  catch (const std::exception &e) {}
}

int main(){
  Base *ptr = generate();
	Base &ref = *ptr;
	identify(ptr);
	identify(ref);
	delete ptr;
	return 0;
}
