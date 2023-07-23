#include <iostream>
#include <math.h>

int global_var = 4;

class Demo
{
public:
  int memberVar = 1;

  void demo()
  {
    std::cout << "ola mundo" << std::endl;
  };
};

int square(int value)
{
  return value * value;
}


namespace LLDBDemo{
  int add(int a, int b ){
    return a + b;
  }
}

int main(int argc, char *argv[])
{
  if (argc > 1)
  {
    std::cout << argv[1] << std::endl;
  }

  int value = 5;
  int result1 = square(value);

  std::cout << result1 << std::endl;

  Demo d;
  d.demo();

  d.memberVar = 1;
  d.memberVar = 10;

  return 0;
}
