/**
 * C++ program printing various memory values with references and pointers.
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#include <iostream>

int main() {

  int * p;

  int num = 7;
  std::cout << " num: " <<  num << std::endl;
  std::cout << "&num: " << &num << std::endl;

  p = &num;
  std::cout << " p: " <<  p << std::endl;
  std::cout << "&p: " << &p << std::endl;
  std::cout << "*p: " << *p << std::endl;

  std::cout << "&p - &num = " << (long long)(&p) - (long long)(&num) << std::endl;

  *p = 42;
  std::cout << "*p changed to 42" << std::endl; 
  std::cout << " num: " <<  num << std::endl;

  return 0;
}

