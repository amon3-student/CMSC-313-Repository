#include <stdio.h>

void matmult(int result[3][3], int first[3][3], int second[3][3]);
void matadd (int result[3][3], int first[3][3], int second[3][3]); 
void printMatrix(char name[], int matrix[3][3]);

int main()
{
  int A[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
  int B[3][3] = {{1,2,0}, {3,4,5}, {0,6,7}};
  int AmultB[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};
  int AmultBplusA[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};
  printMatrix("   A ",A);
  printMatrix("   B ",B);
  matmult(AmultB,A,B);
  matadd(AmultBplusA,AmultB,A);
  printMatrix("A*B+A",AmultBplusA);
  return 0;
}

void matmult(int result[3][3], int first[3][3], int second[3][3])
{
  for(int i = 0; i < 3; i++)
    {
      for(int j = 0; j < 3; j++)
	{
	  result[i][j] += first[i][0] * second[0][j];
	  result[i][j] += first[i][1] * second[1][j];
	  result[i][j] += first[i][2] * second[2][j];
	}
    }
  
}

void matadd(int result[3][3], int first[3][3], int second[3][3])
{
  for(int i = 0; i < 3; i++)
    {
      for(int j = 0; j < 3; j++)
	{
	  result[i][j] += first[i][j] + second[i][j];
	}
    }
}

void printMatrix(char name[], int matrix[3][3])
{
  printf("\n");
  for(int i = 0; i < 3; i++)
    {
      if(i == 1)
	{
	  printf(name);
	  printf(" = ");
	  printf("| ");
	} else {
	printf("\t");
	printf("[ ");
      }
      for(int j = 0; j < 3; j++)
	{
	  printf("%d ",matrix[i][j]);
	}
      if(i == 1)
	{
	  printf("|\n");
	} else {
	printf("]\n");
      }
      
    }
}


