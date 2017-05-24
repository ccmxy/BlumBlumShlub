#include <iostream>

int rng()
{
  int m = 11*19;
  int xi = 9;
  for(int i=0;  i<12; i++) {
     xi = (xi * xi) % m;
     std::cout << "The number is: " << xi << std::endl;
   }
}


int main() {
  rng();
  return 0;
}
