#include<stdio.h>
#define size 100
int stack[size],top=-1;
void push(int n){
    if(top>=size){
        printf("overflow\n");
    }
    else {
        top++;
        stack[top]=n;
    }

}
int pop(){
    if(top==-1){
        printf("underflow\n");
    }
    else {
        int c=stack[top];
        top--;
        return c;
    }
}
int is_empty(){
    if(top==-1){
        return 1;
    }
    else return 0;
}

int main(){
    push(5);
    push(4);
    push(3);
    push(2);
    while(!is_empty()){
        printf("%d ",pop());
    }
}
