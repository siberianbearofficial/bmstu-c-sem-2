#include <stdio.h>
#include <stdlib.h>

#define MIN_SIZE 1
#define MAX_SIZE 10

typedef int matrix[MAX_SIZE][MAX_SIZE];

char input_matrix_size(int *n)
{
	char exit_code = EXIT_FAILURE;
	if (scanf("%d", n) == 1)
	{
		if (*n >= MIN_SIZE)
		{
			if (*n <= MAX_SIZE)
				exit_code = EXIT_SUCCESS;
		}
	}
	return exit_code;
}

char input_matrix(matrix mtx, int n)
{
	char exit_code = EXIT_SUCCESS;
	for (int i = 0; i < n && !exit_code; i++)
	{
		for (int j = 0; j < n && !exit_code; j++)
		{
			if (scanf("%d", &mtx[i][j]) != 1)
				exit_code = EXIT_FAILURE;
		}
	}
	return exit_code;
}

char print_matrix(matrix mtx, int n)
{
	printf("%d\n", n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", mtx[i][j]);
		}
		printf("\n");
	}
	return EXIT_SUCCESS;
}

int valid_part(matrix mtx, int i, int j, int n)
{
	int exit_code = 0;
	
	// is part of vertical ship
	int is_vert = 0;
	if (i == n - 1)
	{
		is_vert += mtx[i - 1][j];
	}
	else if (!i)
	{
		is_vert += mtx[i + 1][j];
	}
	else
	{
		is_vert += mtx[i - 1][j] || mtx[i + 1][j];
	}
	
	// is part of horizontal ship
	int is_hor = 0;
	if (j == n - 1)
	{
		is_hor += mtx[i][j - 1];
	}
	else if (!j)
	{
		is_hor += mtx[i][j + 1];
	}
	else
	{
		is_hor += mtx[i][j - 1] + mtx[i][j + 1];
	}
	
	exit_code += is_hor * is_vert;
	
	// diagonal elements
	if (!i && !j)
		exit_code += mtx[i + 1][j + 1];
	else if (!i && j == n - 1)
		exit_code += mtx[i + 1][j - 1];
	else if (i == n - 1 && !j)
		exit_code += mtx[i - 1][j + 1];
	else if (i == n - 1 && j == n - 1)
		exit_code += mtx[i - 1][j - 1];
	else
		exit_code += mtx[i - 1][j - 1] + mtx[i + 1][j + 1] + mtx[i - 1][j + 1] + mtx[i + 1][j - 1];
	
	return exit_code;
}

char valid(matrix mtx, int n)
{
	char exit_code = EXIT_SUCCESS;
	
	for (int i = 0; i < n && !exit_code; i++)
	{
		for (int j = 0; j < n && !exit_code; j++)
		{
			if (mtx[i][j] && valid_part(mtx, i, j, n))
			{
				exit_code = EXIT_FAILURE;
			}
		}
	}
	
	return exit_code;
}

int main(void)
{
	char exit_code = EXIT_FAILURE;
	
	int n;
	if (!input_matrix_size(&n))
	{
		matrix mtx;
		if (!input_matrix(mtx, n))
		{
			print_matrix(mtx, n);
			exit_code = valid(mtx, n);
			if (exit_code)
				printf("FAIL");
			else
				printf("SUCCESS");
		}
	}
	
	return exit_code;
}
