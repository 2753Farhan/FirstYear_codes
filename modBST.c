#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
    struct node* parent;

} ;
struct node * root=NULL;
struct node *newnode(int key)
{
    struct node * temp=(struct node*)malloc(sizeof(struct node));
    temp->data=key;
    temp->left=temp->right=temp->parent=NULL;
    return temp;
}
struct node * Extract_max(struct node* x)
{
    while(x->right!=NULL)
    {
        x=x->right;
    }
    return x;
}
struct node * Extract_min(struct node* x)
{
    while(x->left!=NULL)
    {
        x=x->left;
    }
    return x;
}
struct node* Insert(struct node * z)
{
    struct node *y=NULL;
    struct node * x=root;

    while(x!=NULL)
    {
        y=x;
        if(z->data<x->data)
        {
            x=x->left;
        }
        else x=x->right;
    }
    z->parent=y;

    if(y==NULL)
    {
        root=z;
    }
    else if(z->data<y->data)
    {
        y->left=z;
    }
    else y->right=z;
    return root;

}
void inorder(struct node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
struct node* search(struct node * x,int k)
{
    if (x==NULL || k==x->data)
    {
        return x;
    }
    if(k<x->data)
    {
        return search(x->left,k);
    }
    else return search(x->right,k);
};
struct node * successor(int val)
{
    struct node* x=search(root,val);
    if (x->right!=NULL)
    {
        return Extract_min(x->right);
    }
    struct node* y=x->parent;
    while(y!=NULL&&x==y->right)
    {
        x=y;
        y=y->parent;
    }
    return y;

}
void Tree_delete(struct node * z)
{
    struct node* y;
    struct node* x;

    if (z->left==NULL||z->right==NULL)
    {
        y=z;
    }
    else y=successor(z->data);
    if(y->left!=NULL)
    {
        x=y->left;
    }
    else x=y->right;
    if(x!=NULL)
    {
        x->parent=y->parent;
    }
    if(y->parent==NULL)
    {
        root=x;
    }
    else if(y==y->parent->left)
    {
        y->parent->left=x;
    }
    else y->parent->right=x;
    if(y!=z)
    {
        z->data=y->data;
    }

};
int main()
{
    freopen("bst.txt","r",stdin);
    int n;
    printf("How many elements do you want to insert in bst?\n");
    scanf("%d",&n);

    int r;
    printf("Enter the root of the binary search tree\n");
    scanf("%d",&r);
    root=Insert(newnode(r));
    printf("Enter the other elements of binary search tree\n");
    for(int i=1; i<n; i++)
    {
        int x;
        scanf("%d",&x);
        Insert(newnode(x));
    }


    printf("Printing in inorder format we have : \n");
    inorder(root);
    printf("\n");

    struct node * max=Extract_max(root);
    printf("Maximum value is %d\n",max->data);

    struct node * min=Extract_min(root);
    printf("Minimum value is %d\n",min->data);

    printf("Enter the element you want to search:\n");
    int a;
    scanf("%d",&a);
    struct node * s=search(root,a);
    if(s==NULL)
    {
        printf("Element not found\n");
    }
    else
        printf("searched element is %d\n",s->data);

    printf("Successor of which element do you want to find ?\n");
    scanf("%d",&a);
    struct node * su=successor(a);
    if(su==NULL)
    {
        printf("No Successor\n");
    }
    else
        printf("successor is %d\n",su->data);

    printf("Enter the element you want to delete \n");
    scanf("%d",&a);
    Tree_delete(search(root,a));
    printf("After deletion:\n");
    inorder(root);
    printf("\n");



}

