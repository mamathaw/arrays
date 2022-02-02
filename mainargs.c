#include <stdio.h>

#if 0
int main(int argc, char *argv[], char *env[]) {
//int main() {
	int i = 0;

	printf("Total args passed are: %d\n", argc);
	for (i = 0; i < argc; i++)
		printf("argv[%d]= %s\n", i, argv[i]);
	printf("--------------------\n");
	printf("argv[%d]= %s\n", i, argv[i]);
	printf("--------------------\n");

	for (i = 0; env[i]; i++)
		printf("env[%d]= %s\n", i, env[i]);
	printf("--------------------\n");
	printf("Total environment variables received: %d\n", i);
	printf("--------------------\n");
	for (; *env; ++env)
		printf("*env= %s\n", *env);
	printf("--------------------\n");
}
#endif

#if 0
int main(int argc) {
	printf("Total args passed are: %d\n", argc);
}
#endif

#if 0
int main(int argc, char *argv[], char *env[]) {

	printf("Total args passed are: %d\n", argc);
	printf("args array base address: %p\n", argv);
	printf("env array base address: %p\n", env);
}

#endif