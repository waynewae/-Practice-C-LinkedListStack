#include<stdio.h>

#define MAXSIZE 10

typedef struct listNode {
	int data;
	struct listNode* next;
}Node;

typedef struct {
	Node* top;
	int len;
}Stack;

void initial(Stack* stk) {
	stk->top = NULL;
	stk->len = 0;
}

int isFull(Stack* stk) {
	if(stk->len == MAXSIZE) return 1;
	else return 0;
}

int isEmpty(Stack* stk) {
	if(!stk->top) return 1;
	else return 0;
}

void push(Stack* stk, int data) {
	if(!isFull(stk)) {
		Node * newNode = (Node*)malloc(sizeof(Node));
		newNode->data = data;
		newNode->next = stk->top;
		stk->top = newNode;
		stk->len++;
	} else {
		printf("stk->len : %d, stack is full.\n", stk->len);
	}
}

void pop(Stack* stk) {
	if(!isEmpty(stk)) {
		printf("pop : %d\n", stk->top->data);
		stk->top = stk->top->next;
		stk->len--;
	} else {
		printf("stk->len : %d, stack is empty.\n", stk->len);
	}
}

int main() {
	Stack stk;
	initial(&stk);
	int i;

	for(i = 1; i <= 11 ; i++) push(&stk, i);
	for(i = 1; i <= 11 ; i++) pop(&stk);
	return 0;
}
