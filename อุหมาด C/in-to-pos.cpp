#include <stdio.h>
#include <ctype.h>
char stack[20],pos[20];
int top = -1,topp = -1,i=0;

push(char x){
    stack[++top] = x;
}
 
pop(){
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

priority(char x){
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
}

main(){
    char exp[20];
    char *e, x;
    printf("Enter the expression :: ");
    scanf("%s",exp);
    e = exp;
    while(*e != '\0'){
        if(isalnum(*e))
            pos[++topp] = *e;
        else if(*e == '(')
            push(*e);
        else if(*e == ')'){
            while((x = pop()) != '(')
                pos[++topp] = x;
        }
        else{
            while(priority(stack[top]) >= priority(*e))
                pos[++topp] = pop();
            push(*e);
        }
        e++;
    }
    while(top != -1){
        pos[++topp] = pop();
    }
    printf("%s",pos);
}

