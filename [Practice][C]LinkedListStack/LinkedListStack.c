#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 10

typedef struct stackNode {
	int data;
	struct stackNode* next;
}Node;


Node* top;
int size;

//typedef struct {
//	Node* top;
//	int len;
//}Stack;

void initial() {
	top = NULL;
	size = 0;
}

int isFull() {
	if(size == MAXSIZE) return 1;
	else return 0;
}

int isEmpty() {
	if(!size) return 1;
	else return 0;
}

void push(int data) {
	if(!isFull()) {
		Node * newNode = (Node*)malloc(sizeof(Node));
		newNode->data = data;
		newNode->next = top;
		top = newNode;
		size++;
	} else {
		printf("stack size : %d, stack is full.\n", size);
	}
}

void pop() {
	if(!isEmpty()) {
		printf("pop : %d\n", top->data);
		top = top->next;
		size--;
	} else {
		printf("stack size : %d, stack is empty.\n", size);
	}
}

int main() {
	int i;

	initial();
	for(i = 1; i <= 11 ; i++) push(i);
	for(i = 1; i <= 11 ; i++) pop();
	return 0;
}
