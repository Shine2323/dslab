#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 100

int stack[MAX];
char infix[MAX], postfix[MAX];
int top = -1;

void push(int);
int pop();
int isEmpty();
void inToPost();
void print();
int precedence(char);
int post_eval();

int main()
{
	int result;
    printf("Enter the infix expression: ");
    gets(infix);
    inToPost();
	result=post_eval();
    print();
	printf("The result obtained after postfix evaluation:");
	printf("%d\n",result);
    return 0;
}

void inToPost()
{
    int i, j = 0;
    char symbol, next;
    for (i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];
        switch (symbol)
        {
        case '(':
            push(symbol);
            break;
        case ')':
            while ((next = pop()) != '(')
                postfix[j++] = next;
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while (!isEmpty() && precedence(stack[top]) >= precedence(symbol))
                postfix[j++] = pop();
            push(symbol);
            break;
        default:
            postfix[j++] = symbol;
        }
    }

    while (!isEmpty())
        postfix[j++] = pop();
    postfix[j] = '\0';
}

int precedence(char symbol)
{
    switch (symbol)
    {
    case '^':
        return 3;
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

void print()
{
    int i = 0;
    printf("\nThe equivalent postfix expression is: ");
    while (postfix[i])
    {
        printf("%c", postfix[i++]);
    }
    printf("\n");
}

void push(int val)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = val;
}

int pop()
{
    int c;
    if (top == -1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    c = stack[top];
    top = top - 1;
    return c;
}

int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
int post_eval(){
	int i;
	int a,b;
	for(i=0;i<strlen(postfix);i++){
		//if it is a operand
		if(postfix[i]>='0' && postfix[i]<='9'){
			push(postfix[1] - '0');
		}
		else{
			//pop top 2 elements
			a=pop();
			b=pop();
			switch(postfix[i]){
				case '+':
				push(b+a);
				break;
				case '-':
				push(b-a);
				break;
				case '*':
				push(b*a);
				break;
				case '/':
				push(b/a);
				case '^':
				push(pow(b,a));
				break;
			}
		}
		
	}
	return pop();
}
