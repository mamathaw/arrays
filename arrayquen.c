#include <stdio.h>

void puzzle1() {
	int arr[] = { 1,2,3,4,5 };
	int i = 0;
	int k = 5;

	for (i = 0; i < 5; i++)
		printf("arr[%d]= %d\n", i, arr[i]);

	printf("-------------\n");
	printf("k = %d\n", k);
	//arr[2, 3] = 100;
	
	i = 3;
	/*
	if (3 == i) {
		arr[i] = 100;
		k *= 2;
	}
	*/
	arr[k *= 2, i] = 100;
	printf("-------------\n");

	printf("k = %d\n", k);
	for (i = 0; i < 5; i++)
		printf("arr[%d]= %d\n", i, arr[i]);

	printf("-------------\n");

}

void puzzle2() {
	//char str[] = "Wello";
	char *str = "Wello";

	//str[0] = 'H';
	printf("str= %s\n", str);
	printf("sizeof(str)= %u\n", sizeof(str));
}

void puzzle3() {
	int arr[] = { 1,2,3,4,5 };
	int *ap = &arr[2];
	int i = -1;

	for (i = 0; i < 5; i++)
		printf("arr[%d]= %d, &arr[%d]= %p\n", i, arr[i], i, &arr[i]);

	printf("-------------\n");
	printf("ap = %p, *ap= %d, ap[0]= %d \n", ap, *ap, ap[0]);
	printf("-------------\n"); 
	printf(" ap[-1]= %d \n", ap[-1]);
	printf("-------------\n");
	printf(" ap[-2]= %d \n", ap[-2]);

}


void puzzle4() {
	char str[] = "He\0llo";

	printf("str= %s\n", str);
	printf("sizeof(str)= %u\n", sizeof(str));
}

void puzzle5() {
	//int i = 12, n = 4;
	int i = 123456, n = 4;

	//printf("i=%*d\n", n, i);
	//printf("i=%5d\n", i);
	//printf("i=%7d\n", i);

	printf("Enter field-width: ");
	scanf("%d", &n);
	printf("\n");

	printf("i=%*d\n", n, i);

}

#if 0
int main() {
	//puzzle1();
	//puzzle2();
	//puzzle3();
	//puzzle4();

	puzzle5();
}
#endif
