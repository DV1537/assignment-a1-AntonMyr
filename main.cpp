#include <iostream>
#include <fstream>

/**
 * The program reads numbers from a file and prints the sum of them
 * Example: main.exe ./tests/input.in
 * @param  argc [description]
 * @param  argv [description]
 * @return      [description]
 */
int main(int argc, const char * argv[])
{


  /**
    * - should store all the numbers in an dynamic array
    * - should calculate the average
    * - Should display all the values above the average
    */
  int a = 0;
  int sum = 0;
  int charCounter = 0;

  std::ifstream myReadFile;

  myReadFile.open(argv[1]);

  while (myReadFile >> a) {
    charCounter += 1;
  }

  /**
    * Clears myReadFile from eof bit
    */
  myReadFile.clear();
  myReadFile.seekg(0, std::ios::beg);
  a = 0;

  int* numbersArray = new int[charCounter];
  for(int i = 0; i < charCounter; i++) {
    myReadFile >> a;
    numbersArray[i] = a;
    sum += a;
  }

  sum /= charCounter;

  for(int i = 0; i < charCounter; i++) {
    if(numbersArray[i] > sum) {
      std::cout << numbersArray[i] << std::endl;
    }
  }

  delete [] numbersArray;

  myReadFile.close();

  return 0;
}

