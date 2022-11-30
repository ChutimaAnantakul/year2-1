#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
 int round = 0,i = -1;
typedef struct node{
    int data;
    struct node* next;
} node;
 
typedef void (*callback)(node* data);
 
node* create(int data,node* head){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = head;
    return new_node;
}
node* prepend(node* head,int data){
	i++;
    node* headnode = create(data,head);
    head = headnode;
    return head;
}
traverse(node* head,callback f){//ptint
    node* cursor = head;
    while(cursor != NULL){
        f(cursor);
        cursor = cursor->next;
    }
}
node* remove_front(node* head){
    if(head == NULL)
        return NULL;
    node *front = head;
    head = head->next;
    front->next = NULL;
    /* is this the last node in the list */
    if(front == head)
        head = NULL;
    free(front);
    return head;
}
node* remove_back(node* head){
    if(head == NULL)
        return NULL;
 
    node *cursor = head;
    node *back = NULL;
    while(cursor->next != NULL)
    {
        back = cursor;
        cursor = cursor->next;
    }
 
    if(back != NULL)
        back->next = NULL;
    if(cursor == head)
        head = NULL;
 
    free(cursor);
 
    return head;
}
node* remove_any(node* head,node* nd){
    if(nd == NULL)
        return NULL;
    if(nd == head)
        return remove_front(head);
    if(nd->next == NULL)
        return remove_back(head);
    node* cursor = head;
    while(cursor != NULL)
    {
        if(cursor->next == nd)
            break;
        cursor = cursor->next;
    }
 
    if(cursor != NULL)
    {
        node* tmp = cursor->next;
        cursor->next = tmp->next;
        tmp->next = NULL;
        free(tmp);
    }
    return head;
}

void display(node* n){
    if(n != NULL)
        printf("%d ", n->data);
}

node* search(node* head,int data){
    node *cursor = head;
    while(cursor!=NULL)
    {
    	round++;
        if(cursor->data == data)
            return cursor;
        cursor = cursor->next;
    }
    return NULL;
}
//sort
node* insertion_sort(node* head){
    node *x, *y, *e;
    x = head;
    head = NULL;
    while(x != NULL){
        e = x;
        x = x->next;
        if (head != NULL){
            if(e->data > head->data){
                y = head;
                while ((y->next != NULL) && (e->data> y->next->data)){
                    y = y->next;
                }
                e->next = y->next;
                y->next = e;
            }
            else{
                e->next = head;
                head = e ;
            }
        }
        else{
            e->next = NULL;
            head = e ;
        }
    }
    return head;
}
menu(){
    printf("Welcome To programe\n\n");
    printf("1.input data\n");
    printf("2.search for an element\n");
    printf("3.remove any node\n");
    printf("4.print list\n");
    printf("5.revers list\n");
    printf("6.even list\n");
    printf("7.odd list\n");
    printf("8.sum of node\n");
    printf("-1.exit program\n");
 
}
check(node* head,int data){
	int ab = 0;
    node* cursor = head;
    while(cursor != NULL){
        if(cursor->data == data){
        	ab = 1;
        	goto loop1;
		}
		else{
			ab = 0;
		}
        cursor = cursor->next;
    }
loop1 :    if(ab == 1){
    	return true;
    	exit(0);
	}else{
		return false;
		exit(0);
	}
}
node* reverse(node* p){ 
    node* prev = NULL; 
    node* current = p; 
    node* next = NULL; 
    while (current != NULL){ 
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    } 
    p = prev; 
} 


int sum = 0;
sumofnode(node* p){
	while(p != NULL){
		sum = sum+p->data;
		p = p->next;
	}
}
node* evennode = NULL;
node* oddnode = NULL;
main(){
    int command = 0;
    int data;
    node* reversenode = NULL;
    node* evennode = NULL;
	node* oddnode = NULL;
    node* head = NULL;
    node* tmp = NULL;
    callback disp = display;
    menu();
    while(1){
        printf("\nEnter Manu :");
        scanf("%d",&command);
        if(command == -1)
            break;
        switch(command){
        case 0:
            menu();
            break;
        case 1:
loop:    printf("Please enter data:");
            scanf("%d",&data);
            if(check(head,data)){
            	printf("\n\tData Same input again\n");
            	goto loop;
				}
            head = prepend(head,data); //get in node
            head = insertion_sort(head);
            if(data % 2 == 0){
            	evennode = prepend(evennode,data);
            	evennode = insertion_sort(evennode);
			}else{
				oddnode = prepend(oddnode,data);
				oddnode = insertion_sort(oddnode);
			}
            break;
        case 2:
            printf("Please enter data to search:");
            scanf("%d",&data);
            tmp = search(head,data);
            if(tmp != NULL){
                printf("Element with value %d found.",data);
                printf("\ncompare %d found.",round);
                round = 0;
            }
            else{
                printf("Element with value %d not found.",data);
            }
            break;
        case 3:
            printf("Enter the element value to remove:");
            scanf("%d",&data);
            tmp = search(head,data);
            if(tmp != NULL){
                remove_any(head,tmp);
                if(head != NULL)
                    traverse(head,disp);
            }
            else{
                printf("Element with value %d not found.",data);
            }
            break;
        case 4:
        	traverse(head,disp);
            break;
        case 5:
        	head = reverse(head);
        	traverse(head,disp);
            break;
        case 6:
        	traverse(evennode,disp);
            break;
        case 7:
        	traverse(oddnode,disp);
            break;
        case 8:
        	sumofnode(head);
        	printf("%d\n",sum);
            break;
        }
    }
    return 0;
}
