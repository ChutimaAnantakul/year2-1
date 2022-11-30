#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define V 4

int matrix[V][V];
int i,j,first;

typedef struct node{
	int data;
	node* next;
} node;

node* visit = NULL;
node* add = NULL;
node* waitee = NULL;
node* temp = NULL;
node* createNode(int data){
	node* NewNode = (node*)malloc(sizeof(node));
	NewNode->data = data;
	NewNode->next = NULL;
	return NewNode;
}

node* addnode(node* head,int data){
    node* headnode = createNode(data);
    if(head == NULL){
    	head = headnode;
    	add = head;
	}else{
		add->next = headnode;
	}
}


setedge(){
    for(i = 0; i < V; i++)
        for(j = 0; j < V; j++)
            matrix[i][j] = 0;
}

addEdge(){
	int start,dest;
	printf("\tVertice Start : ");
	scanf("%d",&start);
	printf("\tVertice dest : ");
	scanf("%d",&dest);
	matrix[start][dest] = 1;
}

deleteEdge(){
	int start,dest;
	printf("\tVertice Start : ");
	scanf("%d",&start);
	printf("\tVerticedest : ");
	scanf("%d",&dest);
	matrix[start][dest] = 0;
}

showEdge(){
	printf("\t  ");
	for(i = 0;i < V;i++)
		printf("%d ",i);
	printf("\n");
    for(i = 0; i < V; i++){
    	printf("\t%d ",i);
        for(j = 0; j < V; j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

menu(){
	int a;
	printf("\t__________________________\n");
	printf("\t1 : Add Edge\n");
	printf("\t2 : Delete Edge\n");
	printf("\t3 : Show All Edge In Martix\n");
	//printf("\t4 : DFS\n");
	//printf("\t5 : BFS\n");
	printf("\t0 : exit\n");
	printf("\t::: ");
	scanf("%d",&a);
	return a;
}
/*
printBfs(node* temp){
	if(temp == NULL)
		return 0;
	printBfs(temp->next);
	printf(" %d ",temp->data);
}

check(){
	int ii = 0;
	node* currentv = NULL;
	node* currentw = NULL;
	node* rear = NULL;
	currentv = visit;
	currentw = waitee;
	while(currentv != NULL){
		while(currentw != NULL){
			ii++;
			if(currentw->data == currentv->data){
				if(ii = 1){
					waitee = waitee->next;
					currentw = waitee;
				}else{
					rear->next = rear->next->next;
				}
			}
			rear = currentw;
			currentw = currentw->next;
		}
		ii = 0;
		currentv = currentv->next;
	}
}


bfs(){
	visit = addnode(visit,first);
	node* temp = NULL;
	node* wait = NULL;
	for(i=0;i<V;i++){
		if(matrix[first][i] == 1){
			waitee = addnode(waitee,i);	
		}
	}
	check();
	printf("Visited : ");
	printBfs(visit);
	printf("Wait : ");
	printBfs(waitee);
	printf("\n");
	getch();
	
	bfs();
}

*/
main(){
	int mn;
	setedge();
	do{
		mn = menu();
		switch(mn){
			case 1 :
				addEdge();
				break;
			case 2 :
				deleteEdge();
				break;
			case 3 :
				showEdge();
				break;
			/*case 4 :
				break;
			case 5 :
				printf("Enter start vertices : ");
				scanf("%d",&first);
				bfs();
				break;*/
			default :
				printf("Unknow Menu\n");
				break;
		}
	}while(mn != 0);
}
