#include <stdio.h>
#include <stdlib.h>
#define MAX_TREE_HT 150
struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
};
struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode** array;
};
struct MinHeapNode* newNode(char data, unsigned freq)
{
    struct MinHeapNode* temp = (struct MinHeapNode*)malloc(
        sizeof(struct MinHeapNode));

    temp->left = NULL;
    temp->right =NULL;
    temp->data = data;
    temp->freq = freq;

    return temp;
}
struct MinHeap* createMinHeap(unsigned capacity)

{

    struct MinHeap* minHeap
        = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    capacity++;
    minHeap->capacity = capacity;

    minHeap->array = (struct MinHeapNode**)malloc(
        minHeap->capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

void swapMinHeapNode(struct MinHeapNode** a,
                     struct MinHeapNode** b)

{

    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}
void minHeapify(struct MinHeap* minHeap, int i)

{

    int smallest = i;
    int left = 2 * i ;
    int right = 2 * i + 1;

    if (left <= minHeap->size
        && minHeap->array[left]->freq
               < minHeap->array[smallest]->freq)
        smallest = left;

    if (right <= minHeap->size
        && minHeap->array[right]->freq
               < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != i) {
        swapMinHeapNode(&minHeap->array[smallest],
                        &minHeap->array[i]);
        minHeapify(minHeap, smallest);
    }
}

int isSizeOne(struct MinHeap* minHeap)
{

    return (minHeap->size == 1);
}
struct MinHeapNode* extractMin(struct MinHeap* minHeap)

{

    struct MinHeapNode* temp = minHeap->array[1];
    minHeap->array[1] = minHeap->array[minHeap->size ];

    --minHeap->size;
    minHeapify(minHeap, 1);

    return temp;
}

void insertMinHeap(struct MinHeap* minHeap,
                   struct MinHeapNode* minHeapNode)

{

    ++minHeap->size;
    int i = minHeap->size;

    while (i
           && minHeapNode->freq
                  < minHeap->array[i  / 2]->freq) {

        minHeap->array[i] = minHeap->array[i / 2];
        i = i / 2;
    }

    minHeap->array[i] = minHeapNode;
}

void buildMinHeap(struct MinHeap* minHeap)
{

    int n = minHeap->size;
    int i;

    for (i = n / 2; i >= 1; --i)
        minHeapify(minHeap, i);
}

void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i <n; ++i)
        printf("%d", arr[i]);

    printf("\n");
}
int isLeaf(struct MinHeapNode* root)

{

    return !(root->left) && !(root->right);
}
struct MinHeap* createAndBuildMinHeap(char data[],
                                      int freq[], int size)

{

    struct MinHeap* minHeap = createMinHeap(size);
    int i;
    for ( i = 1; i <= size; ++i)
        minHeap->array[i] = newNode(data[i-1], freq[i-1]);

    minHeap->size = size;
    buildMinHeap(minHeap);

    return minHeap;
}

struct MinHeapNode* buildHuffmanTree(char data[],
                                     int freq[], int size)

{
    struct MinHeapNode *left, *right, *top;
    struct MinHeap* minHeap
        = createAndBuildMinHeap(data, freq, size);
    while (!isSizeOne(minHeap)) {

        left = extractMin(minHeap);
        right = extractMin(minHeap);


        top = newNode('#', left->freq + right->freq);

        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}
void printCodes(struct MinHeapNode* root, int arr[],
                int top)

{

    if (root->left) {

        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right) {

        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (isLeaf(root)) {

        printf("%c: ", root->data);
        printArr(arr, top);
    }
}

void HuffmanCodes(char data[], int freq[], int size)

{

    struct MinHeapNode* root
        = buildHuffmanTree(data, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    while(root){
        printf("%d ",root->freq);
        root=root->right;
    }

    //printCodes(root, arr, top);
}

int main()
{

   freopen("huffman4.txt","r",stdin);
   int size,i;
   scanf("%d",&size);
   char arr[size+2];
    int freq[size+1];
    for(i=0;i<size;i++)
    {
        scanf("%d",&freq[i]);

    }
    getchar();
     for(i=0;i<size;i++)
    {
        scanf("%c",&arr[i]);

    }
    // size = sizeof(arr) / sizeof(arr[0]);

    HuffmanCodes(arr, freq, size);

    return 0;
}
