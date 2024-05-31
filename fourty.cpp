#include <bits/stdc++.h>
using namespace std;
int start_row(int x, int y)
{
  int t = x / 3;
  if (t == 0)
  {
    return 0;
  }
  else if (t == 1)
  {
    return 3;
  }
  else
  {
    return 6;
  }
}
int start_col(int x, int y)
{
  int t = y / 3;
  if (t == 0)
  {
    return 0;
  }
  else if (t == 1)
  {
    return 3;
  }
  else
  {
    return 6;
  }
}

bool isSafe(int **arr, int num, int x, int y)
{
  // row check
  for (int i = 0; i < 9; i++)
  {
    if (arr[x][i] == num)
    {
      return false;
    }
  }
  // col check
  for (int i = 0; i < 9; i++)
  {
    if (arr[i][y] == num)
    {
      return false;
    }
  }
  // 3*3 matrix check
  for (int i = start_row(x, y); i < start_row(x, y) + 3; i++)
  {
    for (int j = start_col(x, y); j < start_col(x, y) + 3; j++)
    {
      if (arr[i][j] == num)
      {
        return false;
      }
    }
  }

  // otherwise
  return true;
}

bool sudoku(int **arr, int emptycells)
{
  // base case
  if (emptycells == 0)
  {
    return true;
  }

  // iterate through entire 9*9 matrix to find the empty cells one by one
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      if (arr[i][j] != 0)
      {
        continue;
      }
      // you got the vacant cell
      // try all numbers 1-9 in that cell
      for (int x = 1; x <= 9; x++)
      {
        if (isSafe(arr, x, i, j))
        {
          arr[i][j] = x;
          bool temp = sudoku(arr, emptycells - 1);
          if (temp)
          {
            return true;
          }
          // otherwise backtrack
          arr[i][j] = 0;
        }
      }
      // koi number place nhi hua means you are in the wrong way
      return false;
    }
  }
  return true;
}

int main()
{
  // SUDOKU SOLVER USING RECURSION AND BACKTRACKING
  // RULES OF SUDOKU GAME :-
  /*
  1.) Given a 9*9 matrix board with some integers filled and some vacant cells
  2.) Sudoku solution has following characteristics :-
      -> each row contains digits 1-9 exactly once (9 cells)
      -> each col contains digits 1-9 exactly once (9 cells)
      -> 9*9 matrix is made of 9 "3*3" matrices. Each 3*3 matrix has digits 1-9 exactly once. (9 cells)
  */

  int **arr = new int *[9];
  for (int i = 0; i < 9; i++)
  {
    arr[i] = new int[9];
  }
  // fill the question values in sudoku
  // also count the vacant cells
  int emptycells = 0;

  cout << "\nfill the values in sudoku. Fill 0 in the vacant place.\n";
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      cin >> arr[i][j];
      if (arr[i][j] == 0)
      {
        emptycells++;
      }
    }
  }
  cout << endl;

  bool x = sudoku(arr, emptycells);

  cout << endl;
  cout << "solution : " << endl;
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}