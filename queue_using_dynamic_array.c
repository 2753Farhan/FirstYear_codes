#include<stdio.h>
#include<stdlib.h>
struct queue{
    int size;
    int f;
    int r;
    int *arr;

};
int is_full(struct queue*q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}

int is_empty(struct queue*q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
void enqueue(struct queue *q,int val){
    if(is_full(q)){
        printf("The queue is full");
    }
    else{
        q->r++;
        q->arr[q->r]=val;
        printf("Enqueued element is %d\n",val);

    }
}
int dequeue(struct queue *q){
    int a=-1;
    if(is_empty(q)){
        printf("The queue is empty");
    }
    else{
        q->f++;
        a=q->arr[q->f];
        //printf("Deueued element is %d\n",val);

    }
    return a;
}


int main(){
    struct queue q;
    q.size=100;
    q.f=q.r=0;
    q.arr=(int*)malloc(q.size*sizeof(int));
    enqueue(&q,12);
    enqueue(&q,24);
    enqueue(&q,1);
    enqueue(&q,2);
    enqueue(&q,32);
    printf("ssss is %d",dequeue(&q));




}
