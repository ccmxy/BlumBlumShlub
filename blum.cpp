#include <iostream>
#include <bitset>

// unsigned char *Crypt(unsigned char *data, int dataLength, unsigned int initialValue){
void Crypt(unsigned char *data, int dataLength, unsigned int initialValue){
  long m = 3792215717; //Holds the value that will serve as the modulus
  long x = initialValue; //Holds current "value" that is squared and modulus'd by m

    for(int i = 0;  i < dataLength; i++) {
      x = (x * x) % m;
      //XOR the current value with the ascii value of the (i + 1)th letter
      int xoredValue = (x ^ data[i]);
      //Grab the lowest byte from the Xored value to serve as the byte key
      unsigned byteKey =(xoredValue) & 0xFF;
      std::cout << std::hex << byteKey << std::endl << std::endl;

    }
  return;

}

int main() {
  unsigned char *data;
  char const apple = 'A';
  data[0] = apple;

  int dataLength = 1;

  unsigned int initialValue = 65536;
  Crypt(data, dataLength, initialValue);

  return 0;
}
