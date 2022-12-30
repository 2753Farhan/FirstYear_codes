#include<stdio.h>
#include<conio.h>

int heap[101];
int heapSize=0;

int parent(int i){
    return i/2;
}

int leftChild(int i){
    return 2*i;
}

int rightChild(int i){
    return 2*i+1;
}

void swap(int i, int j){
    int temp = heap[i];
    heap[i]=heap[j];
    heap[j]=temp;
}

void display(){
    for(int i=1; i<=heapSize; i++) printf("%d ", heap[i]);
    printf("\n");
}

void heapify(int i){
    int l=leftChild(i);
    int r=rightChild(i);
    int largest=i;

    if(l<heapSize && heap[l]>heap[i]){
        largest = l;
    }
    if(r<heapSize && heap[r]>heap[largest]){
        largest = r;
    }

    if(largest!=i){
        swap(i, largest);
        heapify(largest);
    }
}

void buildMaxHeap(){
    heapSize++;
    for(int i=heapSize/2; i; i--) heapify(i);
    heapSize--;
}

void heapSort(){
    int length = heapSize;
    for(int i=length; i>=2; i--){
        swap(i, 1);

        if(i>1)heapify(1);
        heapSize=i-1;
    }
    heapSize = length;
}

void heapMaximum(){
    printf("%d\n", heap[1]);
}

int heapExtract(){
    int max = heap[1];
    heap[1] = heap[heapSize];
    heapSize--;
    heapify(1);
    return max;
}

void heapIncreaseKey(int i, int key){
    if(key<=heap[i]){
        printf("Heap underflow!\n");
        return;
    }
    heap[i]=key;
    while(i>1 && heap[parent(i)]<heap[i]){
        swap(i, parent(i));
        i=parent(i);
    }
}

void heapInsert(key){
    heapSize++;
    heap[heapSize]=-1000;
    heapIncreaseKey(heapSize, key);
}

int main(){
    heap[1] = 30;
    heapSize++;
    heap[2] = 22;
    heapSize++;
    heap[3] = 35;
    heapSize++;
    heap[4] = 17;
    heapSize++;
    heap[5] = 32;
    heapSize++;
    heap[6] = 7;
    heapSize++;
    heap[7] = 19;
    heapSize++;
    heap[8] = 9;
    heapSize++;
    heap[9] = 6;
    heapSize++;
    heap[10] = 12;
    heapSize++;
    heap[11] = 43;
    heapSize++;
    heap[12] = 26;
    heapSize++;
    heap[13] = 25;
    heapSize++;
    heap[14] = 17;
    heapSize++;
    heap[15] = 35;
    heapSize++;
    heap[16] = 10;
    heapSize++;

    printf("The initial heap: ");
    display();

    printf("\nBuilding up the heap: ");
    buildMaxHeap();
    display();

    printf("\nApplying heapsort: ");
    heapSort();
    display();

    printf("\nAgain converting the heap: ");
    buildMaxHeap();
    display();

    printf("\nThe largest element: ");
    heapMaximum();

    printf("\nHeap extraction: ");
    printf("%d\n", heapExtract());
    display();

    printf("\nIncreasing the 9th element to 31: ");
    heapIncreaseKey(9, 31);
    display();

    printf("\nInserting 29 to the heap: ");
    heapInsert(29);
    display();

    printf("\nConfirming the heap is okay by applying the heapsort: ");
    heapSort();
    display();

    return 0;
}
