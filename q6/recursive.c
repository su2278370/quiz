#include <stdlib.h>
#include <stdio.h>
#include "reverse_r.h"

int main(){
		
	NODE *head = NULL;
    
    head = insert(head,5);
    head = insert(head,4);
    head = insert(head,3);
    head = insert(head,2);
    head = insert(head,1);
    
    show(head);
    printf("\n");
    
    head = Reverse(head,2,4);
    
   	show(head);
    
	
	return 0;
}
