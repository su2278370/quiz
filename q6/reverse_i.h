#include <stdlib.h>
#include <stdio.h>

typedef struct link{
    int data;
    struct link *next;
   
}NODE;

NODE* Reverse(NODE* pHead, int nStart, int nEnd){
	int n = nEnd - nStart + 1;
	
    if (pHead == NULL || nStart < 1 || n < 1)
        return pHead;
 
    NODE* pX = NULL;
    NODE* pIter = pHead;
    for (int i = 1; i < nStart && pIter != NULL; i++)
    {
        pX = pIter;
        pIter = pIter->next;
    }
 
    if (pIter == NULL) return pHead;
 
    NODE* pEnd = pIter;
    NODE* pPrev = NULL;
    for (int i = 0; i < n && pIter != NULL; i++)
    {
        NODE* pTmp = pIter->next;
        pIter->next = pPrev;
        pPrev = pIter;
        pIter = pTmp;
    }
 
    pEnd->next = pIter;
    if (NULL == pX)
        return pPrev;
 
    pX->next = pPrev;
    return pHead;
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
