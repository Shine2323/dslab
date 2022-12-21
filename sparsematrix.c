#include<stdio.h>

typedef struct{
	int row;
	int column;
	int value;
}Triplet;

int main(){
	int row,column;
	printf("Enter the number of rows of the matrix ");
	scanf("%d",&row);
	printf("Enter the number of columns of the matrix ");
	scanf("%d",&column);
	int matrix[row][column],nonZero = 0;
	printf("Enter the elements of matrix \n");
	for (int i = 0; i < row; i++){
		for (int j = 0; j < column; j++){
			scanf("%d",&matrix[i][j]);
			if (matrix[i][j] != 0){
				nonZero++;
			}
		}
	}

	int zeroValue = (row * column) - nonZero;

	printf("Entered matrix is \n");
	for (int i = 0; i < row; i++){
		for (int j = 0; j < column; j++){
			printf("%d\t",matrix[i][j]);
		}
		printf("\n");
	}

	Triplet trip[nonZero];

	trip[0].row = row;
	trip[0].column = column;
	trip[0].value = nonZero;

	int z = 1;
	for (int i = 0; i < row; i++){
		for (int j = 0; j < column; j++){
			if (matrix[i][j] != 0){
				trip[z].row = i;
				trip[z].column = j;
				trip[z].value = matrix[i][j];
				z++;
			}
		}
	}

	for (int i = 0; i < z; i++){
		printf("%d %d %d\n",trip[i].row,trip[i].column,trip[i].value);
	}

	float sparse = (float)zeroValue/(column * row);
	printf("Sparcity is : %0.2f\n",sparse);





	return 0;
}
