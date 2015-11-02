#include <stdlib.h>
#include <stdio.h>

typedef struct link{
    int data;
    struct link *next;
   
}NODE;

NODE *subReverse(NODE *head){
	
	if ( head->next == NULL ) 
		return head;

	NODE *right = head->next;
	NODE *newHead;

	head->next = NULL;

	newHead = subReverse(right);

	right->next = head;

	return newHead;
}

NODE* Reverse(NODE *head, int m, int n){

	
	NODE *mStart, *subHead, *nEnd, *tmp;
	int i;

	mStart = head;
	tmp = head;

	//find the start of sub link at m node
	for (i=1;i<m-1;i++)
		mStart = mStart->next;
	
	subHead = mStart->next;

	//find the end of sub link at n node
	for (i=1;i<n;i++)
		tmp = tmp->next;
	
	//store the end of the nodes after n
	nEnd = tmp->next;
	
	//cut the nodes after n 
	tmp->next = NULL;	
	
	//Reverse the sub link and connect to the link before m node 
	mStart->next = subReverse(subHead);
	
	//coonect the link after n node to the end of the sub link
	subHead->next = nEnd;

	return head;
}

void show(NODE *pHead){
	
	if(pHead == NULL){
		
		return;
	}
	
	printf("%d",pHead->data);
	show(pHead->next);
	
}

NODE* insert(NODE *head,int data){
	
	NODE *temp = (NODE*)malloc(sizeof(NODE*));
	temp->data = data;
	temp->next = NULL;
	if(head != NULL) temp->next = head;
	head = temp;
}
