#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

int stack[12],top = -1;
int data;
typedef struct node{
    int data;
    struct node* next;
} node;

typedef void (*callback)(node* data);

node* stackdynamic = NULL;
node* endstack = NULL;
node* create(int data){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = stackdynamic;
    return new_node;
}

node* prepend(int data){
    node* headnode = create(data);
    stackdynamic = headnode;
    //return stackdynamic;
}

pushstack(int x){
    stack[++top] = x;
    prepend(x);
}

popstack(){
    if(top == -1)
        return -1;
    else
        return stack[top--];
}
popnode(){
	stackdynamic = stackdynamic->next;
}

traverse(node* stackdynamic,callback f){//ptint
    node* cursor = stackdynamic;
    while(cursor != NULL){
        f(cursor);
        cursor = cursor->next;
    }
}

printlist(){
	int num = top;
	while(num != -1){
		printf("%d ",stack[num--]);
	}
}

void display(node* n){
    if(n != NULL)
        printf("%d ", n->data);
}

menu(){
	int m;
	printf("\n\t\t====welcome====\n");
	printf("\t\t 1.Push data\n");
	printf("\t\t 2.Pop data\n");
	printf("\t\t 3.Show list\n");
	printf("\t\t 0.Exit\n");
	printf("\t\t : ");
	scanf("%d",&m);
	printf("\t\t================\n");
	return m;
}

input(){
	int data;
	printf("\t\tinput data : ");
	scanf("%d",&data);
	return data;
}

main(){
	callback disp = display;
	int mn;
	while(1){
		mn = menu();
		if(mn == 0)
			break;
		switch(mn){
			case 1 : //push
				if(top == 12)
					printf("\n\t\tStack overflow\n");
				else{
					data = input();
					pushstack(data);
					printf("\n\t\tPushSuccessful\n");
				}
				break;
			case 2 : //pop
				if(top == -1)
					printf("\n\t\tStack underflow\n");
				else{
					printf("\t\t\t%d is pop out stack\n",popstack());
					popnode();
					printf("\n\t\tPop Successful\n");
				}
				break;
			case 3 :
				printf("\t\tDynamic data : ");
				traverse(stackdynamic,disp);
				printf("\n\t\tDenlist data : ");
				printlist();
				printf("\n");
				break;
		}
	}
}

