#include <stdlib.h>
#include <stdio.h>

typedef struct linked_list {

    struct linked_list *next;
    int data;

} list;


list *detectCycle(list *node)
{

    list * slow = node;
    list * fast = node;
    list * ptr1;
    list * ptr2;
    int k =1, loop_found =0, i;

    while(slow && fast && fast->next) {
        slow = slow->next;
        /*Moving fast pointer two steps at a time */
        fast = fast->next->next;
        if(slow == fast) {
            loop_found = 1;
            break;
        }
    }

    if(loop_found) {
        /* We have detected a loop */
        /*Let's count the number of nodes in this loop node */

        ptr1  = fast;
        while(ptr1 && ptr1->next != slow) {
            ptr1 = ptr1->next;
            k++;
        }
        /* Now move the other pointer by K nodes */
        ptr2 = node;
        ptr1 = node;

        for(i=0; i<k; i++) {
            ptr2 = ptr2->next;
        }

        /* Now if we move ptr1 and ptr2 with same speed they will meet at start of loop */

        while(ptr1 != ptr2) {
            ptr1  = ptr1->next;
            ptr2 =  ptr2->next;
        }

        return ptr1;

    }
}

int main()
{

    list *node  = NULL;
    list *cycle = NULL;

    node = (list *)malloc(sizeof(list));
    node->data = 1;
    node->next = (list *)malloc(sizeof(list));
    node->next->data = 2;
    node->next->next = (list *)malloc(sizeof(list));
    node->next->next->data = 3;
    node->next->next->next = (list *)malloc(sizeof(list));
    node->next->next->next->data = 4;
    node->next->next->next->next = (list *)malloc(sizeof(list));
    node->next->next->next->next->data = 5;
    node->next->next->next->next->next = (list *)malloc(sizeof(list));
    node->next->next->next->next->next->data = 6;
    node->next->next->next->next->next->next = node->next->next->next;

    cycle = detectCycle(node);
    printf("%d",cycle->data);


    return 0;
}
