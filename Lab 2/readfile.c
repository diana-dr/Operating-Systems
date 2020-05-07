#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
	FILE *file;
	int lines;
	int col;
	int **matrice;

	file = fopen(argv[1], "r");
	
	fscanf(file, "%d", &lines);
	fscanf(file, "%d", &col);
	
	
	matrice = (int **)malloc(lines * sizeof(int *));
	
	for (int i = 0; i < lines; i++)
	{
		matrice[i] = (int *)malloc(col * sizeof(int *));
	}
	
	for (int i = 0; i < lines; i++)
	{
		for(int j = 0; j < col; j++)
		{
			fscanf(file, "%d", &matrice[i][j]);
			printf("%d ", matrice[i][j]);
		}
		printf("\n");
	}

	free(matrice);
	
	fclose(file);
	
	return 0;

}
