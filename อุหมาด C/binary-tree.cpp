#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int data;
typedef struct node{
	int data;
	struct node* LeftChild = NULL;
	struct node* RightChild = NULL;
} node;
node* root = NULL;

node* createNode(int data){
	node* NewNode = (node*)malloc(sizeof(node));
	NewNode->data = data;
	NewNode->LeftChild = NULL;
	NewNode->RightChild = NULL;
	return NewNode;
}

input(){
	node* current = NULL;
	node* parent = NULL;
	node* temp = NULL;
	temp = createNode(data); 
	if(root == NULL){
		root = temp;
		printf("\ninput success\n");
		return 0;
	}
	current = root;
	while(true){
		parent = current;
		if(data < parent->data){
			current = current->LeftChild;
			if(current == NULL){
				parent->LeftChild = temp;
				printf("\nInput success\n");
				return 0;
			}
		}else{
			current = current->RightChild;
			if(current == NULL){
				parent->RightChild = temp;
				printf("\nInput success\n");
				return 0;
			}
		}
	}
}

search(node* root){
	node* current = NULL;
	node* parent = NULL;
	int compare = 0;
	parent = root;
	while(parent != NULL){
		compare++;
		// _____ section check
		if(parent->data != data){
			if(parent->data < data)
				parent = parent->RightChild;
			else
				parent = parent->LeftChild;
		}else{
			printf("Data : %d  is Found\n",data);
			printf("Compare : %d time\n",compare);
			compare = 0;
			return 0;
		}
		//_______end sec
	}
	if(compare != 0)
		printf("Data %d is not found in binary\n",data);
}

Menu(){
	int a;
	printf("\n Menu");
	printf("\n[1] Insert");
	printf("\n[2] Search");
	printf("\n[3] Preorder Traversal");
	printf("\n[4] Inorder Traversal");
	printf("\n[5] Posorder Traversal");
	printf("\n[0] Exit");
	printf("\nPlease Enter menu:");
	scanf("%d",&a);
	printf("\n\n");
	return a;
}

pos(node* posroot){
	if(posroot == NULL)
		return 0;
	pos(posroot->LeftChild);
	pos(posroot->RightChild);
	printf(" %d ",posroot->data);
}

in(node* inroot){
	if(inroot == NULL)
		return 0;
	in(inroot->LeftChild);
	printf(" %d ",inroot->data);
	in(inroot->RightChild);
}

pre(node* preroot){
	if(preroot == NULL)
		return 0;
	printf(" %d ",preroot->data);
	in(preroot->LeftChild);
	in(preroot->RightChild);
}

main(){
	int mn;
	do{
		mn = Menu();
		switch(mn){
			case 1 :
				printf("\nData To input : ");
				scanf("%d",&data);
				input();
				break;
			case 2 :
				printf("\nData To search : ");
				scanf("%d",&data);
				search(root);
				break;
			case 3 :
				pre(root);
				break;
			case 4 :
				in(root);
				break;
			case 5 :
				pos(root);
				break;
			default :
				printf("\n Exit Menu\nPut again\n");
				break;
		}
	}while(mn != 0);
	printf("\n\t\t completed");
}
