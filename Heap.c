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
void Max_Heapify(int i){
    int largest;
    int l=leftchild(i);
    int r=rightchild(i);
    if(l<size && a[l]>a[i]){
        largest=l;
    }
    else largest=i;
    if(r<size&&a[r]>a[largest]){
        largest=r;
    }
    if (largest!=i){
        swap(&a[i],&a[largest]);
        Max_Heapify(largest);
    }
}
void Build_Max_Heap(){
    int i;
    for(i=size/2-1;i>=0;i--){
        Max_Heapify(i);
    }
}
void Heapsort(){
    Build_Max_Heap(a);
    int length=size;
    int i;
    for(i=size-1;i>=1;i--){
        swap(&a[0],&a[i]);
        size-=1;
        Max_Heapify(0);
    }
    size=length;
}
int Heap_Extract_Max(){

    int max=a[0];
    a[0]=a[size-1];
    size--;
    Max_Heapify(0);
    return max;
}
void Heap_Increase_Key(int i,int key){
    if(key<a[i]){
        printf("new key is smaller than current key");
        return;
    }
    a[i]=key;
    while(i>=0&&a[parent(i)]<a[i]){
        swap(&a[i],&a[parent(i)]);
        i=parent(i);
    }
}
void Max_Heap_Insert(int key){
    size++;
    a[size-1]=INT_MIN;
    Heap_Increase_Key(size,key);
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
    Build_Max_Heap();
    printf("Created heap:\n");
    display();
    printf("Maximum element of the heap is %d\n",Heap_Extract_Max(a));

    printf("After extraction the heap is: \n");
    display();

    Heapsort(size);
    printf("After soring: \n");
    display();

    printf("Again convert to a heap: \n");
    Build_Max_Heap();
    display();

    printf("Enter the position of the element and value after increasing: \n");
    int x,p;
    scanf("%d %d",&p,&x);
    Heap_Increase_Key(p,x);
    display();



}
