#include <stdlib.h>
#include <stdio.h>

typedef struct node{
	
	int data;
	struct node *left;
	struct node *right;
	
}tree;

void flatten(tree *pRoot)
{
    if (!pRoot) return;

    tree *pTemp = pRoot->right;
    pRoot->right = pRoot->left;
    pRoot->left = pTemp;

    flatten(pRoot->right);    // Already switching right and left so flatterning right first
    flatten(pRoot->left);

    if(pRoot->left != NULL) {    // Transplant

        pTemp = pRoot;

        while (pTemp->right != NULL)
            pTemp = pTemp->right;

        pTemp->right = pRoot->left;
        pRoot->left = NULL;
    }
}

int main(){
	
		tree *node_1 = (tree*)malloc(sizeof(tree));
        node_1->data = 1;
        node_1->left = (tree*)malloc(sizeof(tree));
        node_1->right = (tree*)malloc(sizeof(tree));
        tree *node_2 = node_1->left;
        node_2->data = 2;
        node_2->left = (tree*)malloc(sizeof(tree));
        node_2->right = (tree*)malloc(sizeof(tree));
        tree *node_3 = node_2->left;
        node_3->data = 3;
        node_3->left = NULL;
        node_3->right = NULL;
        tree *node_4 = node_2->right;
        node_4->data = 4;
        node_4->left = NULL;
        node_4->right = NULL;
        tree *node_5 = node_1->right;
        node_5->data = 5;
        node_5->left = NULL;
        node_5->right = (tree*)malloc(sizeof(tree));
        tree *node_6 = node_5->right;
        node_6->data = 6;
        node_6->left = NULL;
        node_6->right = NULL;
	
	
	printf("%d",node_1->data);
	printf("%d",node_1->left->data);
	printf("%d",node_1->right->data);
	printf("%d",node_1->left->left->data);
	printf("%d",node_1->left->right->data);
	printf("%d",node_1->right->right->data);
	
	flatten(node_1);
	
	printf("%d",node_1->data);
	printf("%d",node_1->right->data);
	printf("%d",node_1->right->right->data);
	printf("%d",node_1->right->right->right->data);
	printf("%d",node_1->right->right->right->right->data);
	printf("%d",node_1->right->right->right->right->right->data);

	
	return 0;
}
