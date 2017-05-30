#include <iostream>

unsigned char *Crypt(unsigned char *data, int dataLength, unsigned int initialValue){
  long m = 0xE2089EA5; //Holds the value that will serve as the modulus
  long x = initialValue; //Holds current "value" that is squared and modulus'd by m
  int i; //loop counter

  for(i = 0;  i < dataLength; i++) {
    x = (x * x) % m;
    //XOR the current value with the ascii value of the (i + 1)th letter
    int xoredValue = (x ^ data[i]);
    //Grab the lowest byte from the Xored value to serve as the byte key
    unsigned byteKey =(xoredValue) & 0xFF;
    data[i] = byteKey;
    std::cout << std::hex << byteKey << std::endl << std::endl;

  }
  return data;

}

int main() {
  unsigned char *data;
  int dataLength = 5;
  int i; //loop counter

  data[0] = 'a';
  data[1] = 'p';
  data[2] = 'p';
  data[3] = 'l';
  data[4] = 'e';

  // data[0] = 0x3a;
  // data[1] = 0xcb;
  // data[2] = 0x68;
  // data[3] = 0x10;
  // data[4] = 0x84;


  unsigned int initialValue = 65536;
  //unsigned int initialValue = 0x12345678;
  std::cout << Crypt(data, dataLength, initialValue) << "\0";


  return 0;
}
