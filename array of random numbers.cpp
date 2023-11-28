//Generates array 4x5 of random numbers ranging from -2 to 6.
//Takes random row and column, takes sums of their elements, compares them and prints elements of column or row depending on which sum was greater (row if sums are equal)
//loops program in case of sum of row's elements being greater happening no more than 3 times
#include <iostream>
#include <random>

struct str {
  int sum;
  bool ifRow;
};

void gen(int arr[4][5])
{
  std::random_device rd;
  std::uniform_int_distribution uid(-3,6);

  for(unsigned short int i = 0; i < 4; ++i)
    for(unsigned short int j = 0; j < 5; ++j)
      arr[i][j] = uid(rd);

  std::cout << std::endl;
  for(unsigned short int i = 0; i < 4; ++i)
  {
    for(unsigned short int j = 0; j < 5; ++j)
      std::cout << arr[i][j] << "\t";

    std::cout << std::endl;
  }
}

str sum(int arr[4][5])
{
  std::random_device rd;
  std::uniform_int_distribution rx(0,3), ry(0,4);
  int colSum = 0, rowSum = 0, x = rx(rd), y = ry(rd);
  
  for(unsigned short int i = 0; i < 4; ++i)
    colSum += arr[i][y];
  
  for(unsigned short int i = 0; i < 5; ++i)
    rowSum += arr[x][i];

  if(colSum > rowSum)
  {
    std::cout << "Column " << y << ": ";
    
    for(unsigned short int i = 0; i < 4; ++i)
      std::cout << arr[i][y] << "\t";

    return {colSum, true};
  }
  else
  {
    std::cout << "Row " << x << ": ";

    for(unsigned short int i = 0; i < 5; ++i)
      std::cout << arr[x][i] << "\t";

    return {rowSum, false};
  }
}

int main()
{
  int arr[4][5], n = 0;
  str answer;
 
  do
  {
    gen(arr); 
    answer = sum(arr);
  } while (!answer.ifRow && n++ <= 3);

  std::cout << std::endl;
  return 0;
}
