#include <stdio.h>

#define ROW 4
#define COL 3

// formula : base_address + row_index * sizeof(ROW) + col_index * sizeof(data-type)
// sizeof(ROW) => #of_columns * sizeof(data-type)

void ex01() {
	int arr[ROW][COL], i = -1, j = -1;
	// sub esp, sizeof(arr)
	// ROW * COL * sizeof(data-type)

	for (i = 0; i < ROW; i++)
		for (j = 0; j < COL; j++)
			arr[i][j] = i * COL + j ;


	for (i = 0; i < ROW; i++)
		for (j = 0; j < COL; j++) {
			printf("arr[%d][%d]= %d\n", i, j, arr[i][j]);
			printf("%d[arr][%d]= %d\n", i, j, i[arr][j]);
			//printf("%d[%d][arr]= %d\n", i, j, i[j][arr]); // in-valid
			printf("--------\n");
		}
	// i= 2, j=1
	// arr[i][j] or i[arr][j] =>  &arr + 2 * ( 3 * 4) + 1*4 => 952 + 24 + 4 => 980
}

//void display(int argArr[ROW][COL]) {
//void display(int argArr[][COL]) {
//void display(int argArr[2000][COL]) {


	// i= 2, j=1
	// argArr[i][j] or i[argArr][j] =>  (argArr) + 2 * ( 2 * 4) + 1*4 => 952 + 16 + 4 => 972
//void display(int argArr[][2]) {
//void display(int argArr[][]) { // In-valid

void display(int argArr[][4]) {
	int i = -1, j = -1;

	for (i = 0; i < ROW; i++)
		for (j = 0; j < COL; j++) {
			printf("argArr[%d][%d]= %d, &argArr[%d][%d]= %p\n", i, j, argArr[i][j], i, j, &argArr[i][j]);
		}
}

void ex02() {
	int arr[ROW][COL], i = -1, j = -1;
	// sub esp, sizeof(arr)
	// ROW * COL * sizeof(data-type)

	for (i = 0; i < ROW; i++)
		for (j = 0; j < COL; j++)
			arr[i][j] = i * COL + j;
	display(arr);
}

// 3-dim-arr formula :- base_address + page_index * sizeof(page) + row_index * sizeof(ROW) + col_index * sizeof(data-type)
// sizeof(page) => #of_rows * #of_col * sizeof(data-type)

#if 0
int main() {
	//ex01();
	ex02();
}
#endif