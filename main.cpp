#include <iostream>
#include <fstream>

/**
 * The program reads numbers from a file and prints the sum of them
 * Example: main.exe ./tests/input.in
 * @param  argc [description]
 * @param  argv [description]
 * @return      [description]
 */
int main(int argc, const char * argv[]) {
  int currentNumber = 0;
  int sum = 0;
  int intCounter = 0;
  int iteration = 0;

  int currentChar;
  bool isOk;

  int* numbersArray;
  int i;

  std::ifstream myReadFile;

  myReadFile.open(argv[1]);

  while(iteration < 3) {
    if(iteration > 1) {

      myReadFile.clear();
      myReadFile.seekg(0, std::ios::beg);

      i = 0;

      numbersArray = new int[intCounter];
    }

    while (myReadFile.tellg() != -1) {
      currentChar = myReadFile.peek();
      isOk = (currentChar == 45 || isdigit(currentChar));

      if(!myReadFile.rdstate() && isOk && iteration < 2) {
        myReadFile >> currentNumber;
        intCounter += 1;
      }

      else if(!myReadFile.rdstate() && isOk) {
        myReadFile >> numbersArray[i];
        sum += numbersArray[i];
        i++;
      }

      myReadFile.clear();
      myReadFile.ignore();
    }

    iteration++;
  }

  sum /= intCounter;

  for(int i = 0; i < intCounter; i++) {
    if(numbersArray[i] > sum) {
      std::cout << numbersArray[i] << " ";
    }
  }

  delete [] numbersArray;

  myReadFile.close();

  return 0;
}
