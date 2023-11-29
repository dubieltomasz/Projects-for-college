//Generates 1D array of random odd numbers in a range given by user (min 1, max 100)
//All numbers in array are odd, and theres a function that returns greates value
//Program executes till till index of the greatest value is even and executions happend less than 5 times 
#include <iostream>
#include <random>

int greatest_value(int array[20])
{
  int max = 0;

  for(unsigned int index = 0; index < 20; ++index)
    if(array[index] > max)
      max = array[index];

  return max;
}

bool if_Even_Index(int array[20], int number)
{
  unsigned short index = 0;
  while(array[index] != number) ++index;
  return index % 2;
}

int main()
{  
  long long min, max;

  do {
    std::cout << "Enter minimal(> 0) possoble number: ";
    std::cin >> min;

    std::cout << "Enter maximal(< 101) possoble number: ";
    std::cin >> max;
  } while(min < 1 || min >= max || max > 100);

  std::random_device rd;
  std::uniform_int_distribution<int> uid(min,max);

  int array[20];
  unsigned short executions{};

  do
  {
    for(unsigned short index = 0; index < 20; ++index)
      if((array[index] = uid(rd)) %2 == 0) --index;

    std::cout << std::endl;
    for(int number : array) std::cout << number << "\t";
    std::cout << std::endl;
    
    std::cout << "Greatest value from array: " << greatest_value(array) << std::endl;
    std::cout << "Executions of program: " << executions << std::endl;
  } while (!if_Even_Index(array, greatest_value(array)) && executions++ < 5);

  return 0;
}
