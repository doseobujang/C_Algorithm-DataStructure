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
