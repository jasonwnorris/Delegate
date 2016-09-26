// main.cpp

// STL Includes
#include <iostream>
// Project Includes
#include "Delegate.hpp"

void DisplayInteger(int p_Integer)
{
  std::cout << "Here is my integer: " << p_Integer << std::endl;
}

void DisplayDoubledInteger(int p_Integer)
{
  std::cout << "Here is my doubled integer: " << (p_Integer * 2) << std::endl;
}

int main(int p_ArgCount, char** p_ArgVars)
{
  Delegate<void, int> delegate;
  delegate.Add(DisplayInteger);
  delegate.Add(DisplayDoubledInteger);
  delegate(5);

  return 0;
}
