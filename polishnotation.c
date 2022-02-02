#include <stdio.h>
#include <ctype.h>

#define MAX 25

char postfix[MAX];
int pIndx = 0;

// Stack
int myStack[MAX];
int top = -1;

void push(int op) { myStack[++top] = op; }
int pop() { return myStack[top--]; }
int stack_top() { return myStack[top]; }
int is_empty() { return -1 == top; }


int precedance(int op) {
	switch (op) {
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	}
	return -1;
}

char * convert(char *inf) {
	int i = -1;

	for (i = 0; inf[i]; i++) {
		if (isalpha(inf[i]))
			postfix[pIndx++] = inf[i];
		else {
			if (!is_empty()) {
				if (')' == inf[i]) {
					while (!is_empty() && '(' != stack_top())
						postfix[pIndx++] = pop();
					if ('(' == stack_top())
						pop();
				}
				else
					while(!is_empty() && precedance(inf[i]) <= precedance(stack_top() ))
						postfix[pIndx++] = pop();
			}

			if (')' != inf[i])
				push(inf[i]);
		}
	}

	while (!is_empty())
		postfix[pIndx++] = pop();
	postfix[pIndx] = '\0';
	return postfix;
}

int evaluate(char pf[]) {
	int i = -1;

	top = -1; // empty-stack

	for (i = 0; pf[i]; i++) {
		if (isalpha(pf[i])) {
			printf(" Enter the value for %c operand: ", pf[i]);
			scanf("%d", &myStack[++top]);
			printf("\n");
		}
		else {
			int op2 = myStack[top--];
			int op1 = myStack[top--];

			switch (pf[i]) {
			case '+': myStack[++top] = op1 + op2; break;
			case '-': myStack[++top] = op1 - op2; break;
			case '*': myStack[++top] = op1 * op2; break;
			case '/': myStack[++top] = op1 / op2; break;
			}
		}
	}
	return myStack[top--];
}
#if 0
int main() {
	//char inf[] = "a+b-c/d+e*f-g"; 
	char inf[] = "a+(b-c)/d+e*(f-g)";

	printf("Infix expression: %s\n", inf);
	printf("postfix expression is: %s\n", convert(inf));
	printf("Evaluated value: %d\n", evaluate(postfix));
}
#endif


/*
"a+(b-c)/d+e*(f-g)"
 a+   (bc-d/) + (efg-*)
 abc-d/efg-*++

	"a+b-c/d+e*f-g";
	 1 + 2 - 10/ 5 + 3*4-6
	 => 3-2+12-6
	 => +7

	c/d => cd/ => H
	e*f => ef* => I

	a + b - H + I - g

	ab+ => J
	J-H => JH- => K
	K+I => KI+ => L

	L-g => Lg- 


	KI+g-
	JH-df*+g-
	ab+cd/-ef*+g-
*/





















