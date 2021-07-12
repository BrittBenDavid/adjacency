#include <stdio.h>

#define N 2	/*N represent the num of row and col in the matrix*/

enum boolean {FALSE, TRUE};

typedef int adjmat[N][N];

enum boolean checkPath(adjmat A, int u, int v, int num)	/*The function check in recursion way if there is a path between the  first parm (u, that change) and the last parm (num)*/
{
	int i;
	if ((u >= N) || (v >= N))
		return FALSE;
	else
	{
		if (A[u][v] == 1)
		{
			if (v == num)	/*If we found a parm that equal to num, it means that there is a path*/
				return TRUE;
			else		/*Keep looking for a path*/
				for (i=0; i<N; i++)
					if (checkPath(A, v, i, num))
						return TRUE;
		}
	}
	return FALSE;
}

enum boolean path(adjmat A, int u, int v)	/*The function get the first parms to check if they have a path, and send the parm to the recursion function check - 'checkPath'*/
{
	int i;
	for (i=0; i<N; i++)
		if (checkPath(A, u, i, v))
			return TRUE;
	return FALSE;
}


int main()
{
	int i, j, u, v;
	adjmat matrix;
	printf("Please enter the numbers 0 or 1 into the matrix, row after row\nThe matrix size is: %dX%d\n", N, N);	/*Build the mateix*/
	for (i=0; i<N; i++)
	{
		printf("Enter row number %d\n", i);
		for (j=0; j<N; j++)
			scanf("%d", &matrix[i][j]);
	}
	printf("The matrix is: \n");	/*Print the matrix*/
	for (i=0; i<N; i++) 
	{
		for(j=0; j<N; j++)
			printf("%d\t",matrix[i][j]);
		printf("\n");
	}
	
	u = 0;
	v = 0;
	printf("Please enter 2 indexes to check:\n");
	while (!(u == -1 && v == -1) && (scanf("%d", &u) != EOF && scanf("%d", &v) != EOF)) /*Get u and v (the parms to check the path between them) and check the stop conditions*/
	{

		if (u == -1 && v == -1)
			return 0;
		else /*If the input is ok*/
		{
			printf("The indexes %d and %d ", u, v);
			if (path(matrix, u, v))	/*Check the path*/
				printf("share a common path\n");
			else
				printf("don't share a common path\n");
			printf("Please enter 2 indexes to check:\n");
		}
	}
	return 0;
}
