#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct node {
	int value;
	struct node *next;
}Node;

typedef struct stack {
	Node *head;
	int size;
} Stack;


void menu(Stack *stack);
Stack* create_stack();
int pop(Stack *stack);
void push(Stack *stack, int value);
int size(Stack *stack);
bool empty(Stack *stack);



int main() {
	Stack* new_stack = create_stack();
	menu(new_stack);
	return 0;
}

void menu(Stack *stack) {
	int option = 0;
	int value = 0;
	int v;
	system("clear");
	puts("This is a test of a Stack structure, what action you wish do: ");
	puts("1.- Insert an element");
	puts("2.- Extract an element");
	puts("3.- Know if the stack is empty");
	puts("4.- Know the size of stack");
	puts("5.- Exit");
	printf("Enter the option: ");
	scanf("%i", &option);
	getchar();
	switch(option) {
		case 1:
			do {
				system("clear");
				printf("Enter the number to add: ");
				scanf("%i", &value);
				getchar();
			}while(isdigit(value));
			push(stack, value);
			break;
		case 2:
			v = pop(stack);
			if (v != -1) 
				printf("The pop function return: %d \n", v);
			getchar();
			break;
		case 3:
			printf("Stack is empty? %s", empty(stack) ? "True": "False");
			getchar();
			break;
		case 4:
			printf("The size of stack is: %d", size(stack));
			getchar();
			break;
		case 5:
			exit(0);
			break;
		default:
			puts("INVALID OPTION.");
			getchar();

	}
	menu(stack);
}

Stack* create_stack() {
	Stack* stack = malloc(sizeof(Stack));
	if(stack == NULL)
		return NULL;
	stack->size = 0;
	stack->head = NULL;
	return stack;
}

int pop(Stack *stack) {
	if (stack->size == 0 && stack->head == NULL) {
		puts("Stack is empty");
		return -1;
	} else {
		int value = stack->head->value;
		Node *temp = stack->head;
		stack->head = temp->next;
		free(temp->next);
		stack->size -= 1;
		return value;
	}
}


void push(Stack *stack, int value) {
	Node *node = malloc(sizeof(Node));
	if (node == NULL) {
		puts("Error: cannot allocate memory.");
		exit(1);
	}

	node->value = value;
	node->next = stack->head;
	stack->head = node;
	stack->size += 1;
}

int size(Stack *stack) {
	return stack->size;
}

bool empty(Stack *stack) {
	if (stack->size == 0 && stack->head == NULL)
		return true;
	return false;
}
