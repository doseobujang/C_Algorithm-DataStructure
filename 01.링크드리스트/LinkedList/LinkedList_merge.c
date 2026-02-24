#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;

typedef struct tagNode{
	ElementType Data;
	struct tagNode* NextNode;
} Node;

// 함수 원형 선언
Node* SLL_CreateNode(ElementType NewData);
void SLL_DestroyNode(Node* Node);
void SLL_AppendNode(Node** Head, Node* NewNode);
void SSL_InsertAfter(Node* Current, Node* NewNode);
void SSL_InsertNewHead(Node** Head, Node* NewHead);
void SSL_RemoveNode(Node** Head, Node* Remove);
Node* SSL_GetNodeAt(Node* Head, int Location);
int SSL_GetNodeCount(Node* Head);

#endif 

// 노드 생성
Node* SLL_CreateNode(ElementType NewData){
	Node* NewNode = (Node*)malloc(sizeof(Node));
	
	NewNode->Data = NewData; // 데이터 저장
	NewNode->NextNode = NULL; // 다음 노드에 대한 포인터는 NULL로 초기화
	
	return NewNode; // 노드의 주소 반환 
}

// 노드 소멸
void SLL_DestroyNode(Node* Node){
	free(Node);
}

// 노드 추가
void SLL_AppendNode(Node** Head, Node* NewNode){
	// 헤드 노드가 NULL이라면 새로운 노드가 Head가 됨
	if((*Head) == NULL)
	{
		*Head = NewNode;
	}
	else
	{
		// 테일을 찾아 NewNode 연결
		Node* Tail = (*Head);
		while(Tail->NextNode != NULL)
		{
			Tail = Tail->NextNode;
		} 
		
		Tail->NextNode = NewNode;
	}
}

// 노드 삽입 
void SSL_InsertAfter(Node* Current, Node* NewNode){
	NewNode->NextNode = Current->NextNode;
	Current->NextNode = NewNode;
}

void SSL_InsertNewHead(Node** Head, Node* NewHead){
	if((*Head) == NULL)
	{
		(*Head) = NewHead;
	}
	else
	{
		NewHead->NextNode = (*Head);
		(*Head) = NewHead;
	}
}

// 노드 제거
void SSL_RemoveNode(Node** Head, Node* Remove){
	if((*Head) == Remove)
	{
		*Head = Remove->NextNode;
	}
	else
	{
		Node* Current = *Head;
		while(Current != NULL && Current->NextNode != Remove)
		{
			Current = Current->NextNode;
		}
		
		if(Current != NULL)
			Current->NextNode = Remove->NextNode;
	}
}

// 노드 탐색
Node* SSL_GetNodeAt(Node* Head, int Location){
	Node* Current = Head;
	
	while(Current != NULL && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}
	
	return Current;
} 

// 노드 개수 세기
int SSL_GetNodeCount(Node* Head){
	int Count = 0;
	Node* Current = Head;
	
	while(Current != NULL)
	{
		Current = Current->NextNode;
		Count++;
	}
	
	return Count;
}

int main(void){
	int i = 0;
	int Count = 0;
	Node* List = NULL;
	Node* Current = NULL;
	Node* NewNode = NULL;
	
	// 노드 5개 추가
	for(i=0; i<5; i++)
	{
		NewNode = SLL_CreateNode(i);
		SLL_AppendNode(&List, NewNode);
	}
	
	NewNode = SLL_CreateNode(-1);
	SSL_InsertNewHead(&List, NewNode);
	
	NewNode = SLL_CreateNode(-2);
	SSL_InsertNewHead(&List, NewNode);
	
	// 리스트 출력
	Count = SSL_GetNodeCount(List);
	for(i=0; i<Count; i++)
	{
		Current = SSL_GetNodeAt(List, i);
		printf("List[%d]: %d\n", i, Current->Data);
	} 
	
	// 리스트의 세 번째 노드 뒤에 새 노드 삽입
	printf("\nInserting 3000 After [2]...\n\n");
	
	Current = SSL_GetNodeAt(List, 2);
	NewNode = SLL_CreateNode(3000);
	
	SSL_InsertAfter(Current, NewNode);
	
	// 리스트 출력
	Count = SSL_GetNodeCount(List);
	for(i=0; i<Count; i++)
	{
		Current = SSL_GetNodeAt(List, i);
		printf("List[%d]: %d\n", i, Current->Data);
	}
	
	// 모든 노드를 메모리를 제거
	printf("\nDestroying List...\n");
	
	for(i=0; i<Count; i++)
	{
		Current = SSL_GetNodeAt(List, 0);
		
		if(Current != NULL)
		{
			SSL_RemoveNode(&List, Current);
			SLL_DestroyNode(Current);
		}
	}
	
	return 0; 
}
