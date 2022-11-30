#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef  struct  nodestruct   *nodetype;
struct  nodestruct  {
   int  data;
   nodetype  next;
};
nodetype  insertfirst(nodetype,int);
nodetype  insertatend(nodetype,int);
nodetype  insertbetween(nodetype,int,int);
void  printlinkedlist(nodetype);
void  main(void)  {
   nodetype  first = NULL;
   int  position, n,data;
   int ch = 0;
   while (ch != 5)  {
   	clrscr();
      printf("[1] : insert at first \n");
      printf("[2] : insert at betaween\n");
   	printf("[3] : insert at end \n");
    	printf("[4] : print linked list\n");
    	printf("[5] : stop prgogram\n");
      printf("Your choice  ");
    	scanf("%d",&ch);
    	if (ch == 1){
        printf("Enter integer ==> ");
        scanf("%d",&data);
        first = insertfirst(first,data);
        n = n+1;
      }
      else if (ch == 2){
         printf("Enter position  ===> ");
         scanf("%d",&position);
         printf("Enter integer ==> ");
         scanf("%d",&data);
         first = insertbetween(first,data,position);
         n = n+1;
      }
      else if (ch == 3) {
        printf("Enter integer ==> ");
        scanf("%d",&data);
        first = insertatend(first,data);
        n = n+1;
      }
    else
        printlinkedlist(first);
    }

}

nodetype  insertfirst(nodetype  head,int  data)  {
   nodetype  newnode;
   newnode = (nodetype)malloc(sizeof(nodestruct));
   newnode->data = data;
   newnode->next = head;
   head = newnode;
   return(head);
}

nodetype  insertatend(nodetype  head,int  data)  {
   nodetype  newnode,before,after;
   newnode = (nodetype)malloc(sizeof(nodestruct));
   newnode->data = data;
   if (head == NULL) {
     newnode->next = head;
     head = newnode;
     return(head);
   }
   before = head;
   after = before->next;
   while (after != NULL){
      before = before->next;
      after = after->next;
   }
   newnode->next = after;
   before->next = newnode;
   return(head);
}

nodetype  insertbetween(nodetype  head,int  data,int position)  {
   nodetype  newnode,before,after;
   int  i;
   newnode = (nodetype)malloc(sizeof(nodestruct));
   newnode->data = data;
   i = 1;
   before = head;
   after =  head;
   while  ( i<position) {
      before = after;
      after = after->next;
      i = i+1;
   }
   newnode->next = after;

   before->next = newnode;
   return(head);
}

void  printlinkedlist(nodetype  head)  {
   nodetype   cur;
   char  ch;
   cur = head;
   while (cur != NULL) {
      printf("%d\n",cur->data);
      cur = cur->next;
   }
   printf("\nPress any key to continue ... ");
   ch = getchar();
   scanf("%c",&ch);
}
