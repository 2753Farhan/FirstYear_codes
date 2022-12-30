#include<stdio.h>
#include<limits.h>
int size=0;
int a[100];
void swap(int *a,int *b){
    int temp=*b;
    *b=*a;
    *a=temp;
}

int leftchild(int i){
    return 2*i+1;
}
int rightchild(int i){
    return 2*i+2;
}
int parent(int i){
    return (i-1)/2;
}
void Min_Heapify(int i){
    int lowest;
    int l=leftchild(i);
    int r=rightchild(i);
    if(l<size && a[l]<a[i]){
        lowest=l;
    }
    else lowest=i;
    if(r<size&&a[r]<a[lowest]){
        lowest=r;
    }
    if (lowest!=i){
        swap(&a[i],&a[lowest]);
        Min_Heapify(lowest);
    }
}
void Build_Min_Heap(){
    int i;
    for(i=size/2-1;i>=0;i--){
        Min_Heapify(i);
    }
}
void Heapsort(){
    Build_Min_Heap(a);
    int length=size;
    int i;
    for(i=size-1;i>=1;i--){
        swap(&a[0],&a[i]);
        size-=1;
        Min_Heapify(0);
    }
    size=length;
}
int Heap_Extract_Min(){

    int min=a[0];
    a[0]=a[size-1];
    size--;
    Min_Heapify(0);
    return min;
}
void Heap_Decrease_Key(int i,int key){
    if(key>a[i]){
        printf("new key is greater than current key");
        return;
    }
    a[i]=key;
    while(i>=0&&a[parent(i)]>a[i]){
        swap(&a[i],&a[parent(i)]);
        i=parent(i);
    }
}
void Min_Heap_Insert(int key){
    size++;
    a[size-1]=INT_MIN;
    Heap_Decrease_Key(size,key);
}
void display(){
    for(int i=0; i<size; i++) printf("%d ", a[i]);
    printf("\n");
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        size++;
    }
    Build_Min_Heap();
    printf("Created heap:\n");
    display();
    printf("Maximum element of the heap is %d\n",Heap_Extract_Min(a));

    printf("After extraction the heap is: \n");
    display();

    Heapsort(size);
    printf("After soring: \n");
    display();

    printf("Again convert to a heap: \n");
    Build_Min_Heap();
    display();

    printf("Enter the position of the element and value after deccreasing: \n");
    int x,p;
    scanf("%d %d",&p,&x);
    Heap_Decrease_Key(p,x);
    display();



}
