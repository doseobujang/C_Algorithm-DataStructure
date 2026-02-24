#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;

typedef struct tagNote{
	ElementType Data;
} Node;

typedef struct tagArrayStack{
	int Capacity;
	int Top;
	Node* Nodes;
} ArrayStack;

void AS_CreateStack(ArrayStack** Stack, int Capacity);
void AS_DestroyStack(ArrayStack* Stack);
void AS_Push(ArrayStack* Stack, ElementType Data);
ElementType AS_POP(ArrayStack* Stack);
ElementType AS_Top(ArrayStack* Stack);
int AS_GetSize(ArrayStack* Stack);
int AS_IsEmpty(ArrayStack* Stack);

#endif 

void AS_CreateStack(ArrayStack** Stack, int Capacity){
	// 스택을 자유 저장소에 생성
	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));
	
	// 입력된 Capacity만큼의 노드를 자유 저장소에 생성
	(*Stack)->Nodes = (Node*)malloc(sizeof(Node)*Capacity);
	
	// Capacity 및 Top 초기화
	(*Stack)->Capacity = Capacity;
	(*Stack)->Top = -1; 
}

void AS_DestroyStack(ArrayStack* Stack){
	// 노드를 자유 저장소에서 해제
	free(Stack->Nodes);
	
	// 스택을 자유 저장소에서 해제
	free(Stack); 
}

void AS_Push(ArrayStack* Stack, ElementType Data){
	Stack->Top++;
	Stack->Nodes[Stack->Top].Data = Data;
}

ElementType AS_Pop(ArrayStack* Stack){
	int Position = Stack->Top--;
	return Stack->Nodes[Position].Data;
}

ElementType AS_Top(ArrayStack* Stack){
	return Stack->Nodes[Stack->Top].Data;
}

int AS_GetSize(ArrayStack* Stack){
	return Stack->Top+1;
}

int AS_IsEmpty(ArrayStack* Stack){
	return (Stack->Top == -1);
}

int main(void){
	int i = 0;
	ArrayStack* Stack = NULL;
	
	AS_CreateStack(&Stack, 10);
	
	AS_Push(Stack, 3);
	AS_Push(Stack, 37);
	AS_Push(Stack, 11);
	AS_Push(Stack, 12);
	
	printf("Capacity: %d, size: %d, Top: %d\n\n",
			Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));
			
	for(i=0; i<4; i++)
	{
		if(AS_IsEmpty(Stack))
			break;
		
		printf("Popped: %d, ", AS_Pop(Stack));
		
		if(!AS_IsEmpty(Stack))
			printf("Current Top: %d\n", AS_Top(Stack));
		else
			printf("Stack Is Empty.\n");
	}
	
	AS_DestroyStack(Stack);
	
	return 0;
}

