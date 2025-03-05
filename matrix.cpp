#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 100
#define COLS 110

int main()
{
    srand(time(NULL));
    int** matrix = (int**)malloc(ROWS * sizeof(int*));
    for(int i = 0; i < ROWS; i++) 
	{
        matrix[i] = (int*)malloc(COLS * sizeof(int));
    }
    for (int i = 0; i < ROWS; i++) 
	{
        for (int j = 0; j < COLS; j++) 
		{
            matrix[i][j] = rand() % 2;
        }
    }
    FILE *file = fopen("small matrix.txt", "w");
    if (file == NULL) {
        printf("open error\n");
        return -1;
    }
    for (int i = 0; i < ROWS; i++) 
	{
        for (int j = 0; j < COLS; j++) 
		{
            fprintf(file, "%d ", matrix[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
    for (int i = 0; i < ROWS; i++) 
	{
        free(matrix[i]);
    }
    free(matrix);
    printf("矩阵数据已导出到small matrix.txt文件\n");
    return 0;
}
