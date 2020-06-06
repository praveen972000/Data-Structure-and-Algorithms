//
//  main.c
//  work1
//
//  Created by PRAVEEN KUMAR on 26/05/18.
//  Copyright © 2018 PRAVEEN KUMAR. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
int n,a[111];


struct node
{
    int data,datas;
    struct node *next,*right,*left,*prev;
    int data1;
    struct node *Left,*Right;
    int ht;
}typedef node;

struct node *head,*cur,*par,*root=NULL;





void print_array(int a[],int n)
{
    int i;
    printf("\nArray after sorting:\n");
    for(i=0;i<n;i++)
        printf("%d \t",a[i]);
    printf("\n\n");
    
}
void swap(int steps,int i)
{                         //SWAPPING FUNCTION
    int temp;
    temp=a[steps];
    a[steps]=a[i];
    a[i]=temp;
}



void Take_input(int a[],int n)
{
    int i;
    printf("Enter the Number of elements:\n");
    scanf("%d",&n);
    printf("Enter the Numbers...\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
}


//PROCEEDING InsertionSort

int insertion_sort(int a[],int n)
{
    int i,j,temp;
    for(i=1;i<=n;i++)
    {
        temp=a[i];
        j=i-1;
        while(temp<a[j] && j>=0)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=temp;
    }
    return 0;
}
//CLOSING INSERTION Sort


//PROCEEDING BUBBLE SORT
int bubble_sort(int a[])
{
    int n;
    int i,j;
    printf("Enter the Number of elements:\n");
    scanf("%d",&n);
    
    printf("Enter the Numbers...\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
                swap(j,j+1);
        }
    }
    printf("Elements after sorting :\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
    printf("\n");
    return 0;
}
//FINISHING BUBBLE SORT


/* Starting Selection Sort */
int selection_sort(int a[])
{
    int i,n,steps;
    printf("Enter the number of elements to be sorted:\n ");
    scanf("%d",&n);
    for(i=0;i<n;++i)
    {
        printf("%d. Enter element: ",i+1);
        scanf("%d",&a[i]);
    }
    for(steps=0;steps<n;++steps)
        for(i=steps+1;i<n;++i)
        {
            if(a[steps]>a[i])
            /* To sort in descending order, change > to <. */
                swap(steps,i);
        }
    printf("In ascending order: \n");
    for(i=0;i<n;++i)
        printf("%d \t ",a[i]);
    printf("\n");
    return 0;
}
/*FINISING SELECTION Sort*/



/////SORTING FOR COUNT_SORTING
int k=2222;
void sortneg(int a[],int n1) ///////COUNTSORTing for Negative Integers
{
    int c[k+1],b[n1],i;
    
    for(i=0;i<k+1;i++)
        c[i]=0;     //Put 0 in every box of new Array
    
    for(i=0;i<n1;i++)
        c[-a[i]]++;
    
    for(i=1;i<=k;i++)   //
        c[i]=c[i]+c[i-1];
    
    for(i=0;i<n1;i++)
    {
        b[c[-a[i]]-1]=a[i];
        c[-a[i]]--;
    }
    printf("\nSORTED ARRAY IS : \n");
    for(i=n1-1;i>=0;i--)
        printf("%d  ",b[i]);
}
void sortpos(int a[],int n1) /////Count Sorting for POSITIVE Integers
{
    int c[k+1],b[n1],i;
    
    for(i=0;i<k+1;i++)
        c[i]=0;   ////Put 0 in every box of new Array
    
    for(i=0;i<n1;i++)
        c[a[i]]++;
    
    for(i=1;i<=k;i++)
    {
        c[i]=c[i]+c[i-1];
    }
    
    for(i=0;i<n1;i++)
    {
        b[c[a[i]]-1]=a[i];
        c[a[i]]--;
    }
    for(i=0;i<n1;i++)
        printf("%d  ",b[i]);
}



int count_sort(int d[])  /*Function of COUNTSORT*/
{
    int m,n;
    printf("\nENTER NUMBER OF INTEGERS\n ");
    scanf("%d",&n);
    printf("\n ENTER NUMBERS :\n");
    for(m=0;m<n;m++)
        scanf("%d",&a[m]);
    
    int i,p=0,j=0;
    int a1[n];
    
    for(i=0;i<n;i++)
    {
        if(d[i]>0)
        {a[p]=d[i];p++;}
        else
        {a1[j]=d[i];j++;}
    }
    sortneg(a1,j);
    sortpos(a,p);
    
    return 0;
}
/////END OF COUNT SORTING



////PROCEED FOR MERGE SORTING

int merge_sort(int a[],int low,int high);
void merge(int a[],int l1,int u1,int l2,int u2);

void merge(int a[],int l1,int u1,int l2,int u2)
{
    int temp[50];    //array used for merging
    int low,high,k;
    low=l1;    //beginning of the first list
    high=l2;    //beginning of the second list
    k=0;
    
    while(low<=u1 && high<=u2)    //while elements in both lists
    {
        if(a[low]<a[high])
            temp[k++]=a[low++];
        else
            temp[k++]=a[high++];
    }
    
    while(low<=u1)    //copy remaining elements of the first list
        temp[k++]=a[low++];
    
    while(high<=u2)    //copy remaining elements of the second list
        temp[k++]=a[high++];
    
    //Transfer elements from temp[] back to a[]
    for(low=l1,high=0;low<=u2;low++,high++)
        a[low]=temp[high];
}

int merge_sort(int a[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        merge_sort(a,low,mid);        //left recursion
        merge_sort(a,mid+1,high);    //right recursion
        merge(a,low,mid,mid+1,high);    //merging of two sorted sub-arrays
    }
    return 0;
}

//CLOSE of MERGE Sort


/*Proceeding For QuickSort*/
int partition(int a[],int l,int u)
{
    int pivot,i,j,temp;
    pivot=a[l];
    i=l;
    j=u+1;
    do
    {
        do
            i++;
        while(a[i]<pivot && i<=u);
        do
            j--;
        while(pivot<a[j] && j<=u);
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);
    
    a[l]=a[j];
    a[j]=pivot;
    
    
    return(j);
}



void quick_sort(int a[],int l,int u)
{
    int j;
    if(l<u)
    {
        j=partition(a,l,u);
        quick_sort(a,l,j-1);
        quick_sort(a,j+1,u);
    }
}
//Finishing Quick Sort


            /*Proceeding RADIXSORT*/

int largest(int a[], int n)
{                      /*Function for getting Largest one*/
    int large = a[0], i;
    for(i = 1; i < n; i++)
    {
        if(large < a[i])
            large = a[i];
    }
    return large;
}
int radix_sort(int a[])
{
    int bucket[10][10], bucket_count[10];
    int i, j, k, remainder, NOP=0, divisor=1, large, pass;
    
    large = largest(a, n);  //Calling Largesst Function
    
    while(large > 0)
    {
        NOP++;
        large/=10;
    }
    for(pass = 0; pass < NOP; pass++)
    {
        for(i = 0; i < 10; i++)
        {
            bucket_count[i] = 0;
        }
        for(i = 0; i < n; i++)
        {
            remainder = (a[i] / divisor) % 10;
            bucket[remainder][bucket_count[remainder]] = a[i];
            bucket_count[remainder] += 1;
        }
        
        i = 0;
        for(k = 0; k < 10; k++)
        {
            for(j = 0; j < bucket_count[k]; j++)
            {
                a[i] = bucket[k][j];
                i++;
            }
        }
        divisor *= 10;
    }
    return 0;
}
//FINISHING RADIX Sorting




                    /*Proceeding MaxHeapSorting*/
void heap_sort(int[],int);
void heapify(int[],int);
int build_MaxHeap(int a[],int n);

void heap_sort(int a[],int n)
{
    int i,t;
    
    heapify(a,n);
    
    for (i=n-1;i>0;i--)
    {
        t=a[0];
        a[0]=a[i];
        a[i]=t;
        build_MaxHeap(a,i);
    }
}

void heapify(int a[],int n)
{
    int k,i,j,item;
    for (k=1;k<n;k++) {
        item=a[k];
        i=k;
        j=(i-1)/2;
        while((i>0)&&(item>a[j]))
        {
            a[i]=a[j];
            i=j;
            j=(i-1)/2;
        }
        a[i]=item;
    }
}


int build_MaxHeap(int a[],int n)
{
    int l,j,item;
    j=0;
    item=a[j];   //parant = j
    l=2*j+1;   //left child
    while(l<=n-1)
    {
        if(l+1 <= n-1)   //right child
            if(a[l] < a[l+1])
                l++;
        if(item<a[l])
        {
            a[j] = a[l];
            j = l;
            l = 2*j+1;
        }
        else
            break;
    }
    a[j] = item;
    return 0;
}
//Finishing MaxHeapSorting

void minheap_sort(int a[],int n)
{
    
}




            /*LINKED LIST FUNCTIONS */
                               //SINGLE LINKED LIST FUNCTIONS





void display()
{
    if(head == NULL)
    {
        printf("Link is Empty ");
        return;
    }
    else
    {
        struct node *temp;
        temp=head;
        while(temp->next != NULL)
        {
            printf("%d-> ",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }
}


void deletion_place(int x)
{
    int count=1;
    struct node *temp,*current;
    current=head;
    while(x != count+1 && current->next != NULL)
    {
        current=current->next;
    }
    if(x == count+1)
    {
        temp=current->next;
        current->next=temp->next;
        printf("Deleted element is %d",temp->data);
        free(temp);
    }
    
}




void deletion_end()
{
    struct node *temp,*current;
    current=head;
    while(current->next->next != NULL)
    {
        current=current->next;
    }
    temp=current->next;
    current->next=NULL;
    printf("Deleted value is %d\n",temp->data);
    free(temp);
}


void deletion_beg()
{
    struct node *temp;
    temp=head;
    head=head->next;
    printf("%d is deleted..",temp->data);
    free(temp);
}



void deletion_value(int x)
{
    int flag=0;
    struct node *temp,*c;
    //temp=(struct node *)malloc(sizeof(struct node));
    c=head;
    //temp->data=x;
    if(head==NULL)
        printf("No element to delete");
    while(c->next->next != NULL)
        if(c->next->data==x)
        {
            flag=1;
            
            break;
        }
        else
        {
            c=c->next;
        }
    if(flag==1)
    {
        temp=c->next;
        c->next=temp->next;
        free(temp);
    }
    else
    {
        printf("not matched");
    }
}


void look_for(int x)
{
    int flag=0;
    struct node *temp;
    temp=head;
    if (head == NULL)
    {
        printf("Link is Empty..");
    }
    while(temp != NULL)
    {
        if(temp->data == x)
        {
            flag=1;
            break;
        }
        else
        {
            temp=temp->next;
        }
    }
    if(flag==1)
        printf("%d is present in link list",x);
    else
    {
        printf("%d is not present in list",x);
        
    }
}


int length()
{
    int count=0;
    struct node *temp;
    temp=(struct node *)(sizeof(struct node));
    temp=head;
    if(head == NULL)
        printf("There is no any element in the list ..");
    else
    {
        while(temp != NULL)
        {
            count++;
            temp=temp->next;
        }
        printf("The size of list is %d",count);
    }
    return 1;
}


void insert_beg(int x)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=x;
    if(head == NULL)
    {
        temp->next=NULL;
        head=temp;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
}


void insert_end(int x)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->next=NULL;
    temp->data=x;
    if(head == NULL)
    {
        head=temp;
    }
    else
    {
        struct node *t;
        t=head;
        while(t->next != NULL)
        {
            t=t->next;
        }
        t->next = temp;
    }
}


int insert_place(int x,int position)
{
    int count=1;
    struct node *temp,*current;
    temp=(struct node *)malloc(sizeof(struct node));
    current=head;
    while(position != count+1 && current != NULL)
    {
        current=current->next;
        count++;
    }
    if(position == count+1)
    {
        
        temp->next=current->next;
        temp->data=x;
        printf("%d is inserted",temp->data);
        current->next=temp;
        
    }
    return 0;
}

/*
 void reverse()
 {
 struct node *prevNode, *curNode;
 
 if(head != NULL)
 {
 prevNode = head;
 curNode = head->next;
 head = head->next;
 
 prevNode->next = NULL; // Make first node as last node
 
 while(head != NULL)
 {
 head = head->next;
 curNode->next = prevNode;
 
 prevNode = curNode;
 curNode = head;
 }
 
 head = prevNode; // Make last node as head
 
 printf("SUCCESSFULLY REVERSED LIST\n");
 
 
 display();      //printing all number in reversed order
 }
 }
 */

void reverse()
{
    struct node *cur,*curprev=NULL,*curnext=NULL;
    cur=head;
    while(cur!=NULL)
    {
        curnext=cur->next;
        //curnext->next=cur;
        cur->next=curprev;
        
        curprev=cur;
        cur=curnext;
    }
    head=curprev;
    display();
}
/*Finishing Single linked List*/
            //FINISH SINGLE LINKED LIST


#define size 100
int top = -1;



        /*STACK PROCEED*/
                //STACK STARTING
int insertorPUSH(int x)
{
    if (top == size-1)
        printf("Stack is full.....\n");
    else
    {
        top++;
        a[top]=x;
    }
    return 0;
}




int POP()
{
    if(top==-1)
        printf("Sorry!...No element to delete..\n");
    else
    {
        printf("%d is deleted ..\n",a[top]);
        top--;
    }
    return 0;
}


void Display()
{
    int i;
    
    if(top==-1)
        printf("Stack is Empty....\n");
    else
    {
        printf("Stack Elements are.....\n*********************\n\n ");
        for(i=top;i>=0;i--)
            printf("%d\t",a[i]);
        printf("\n");
    }
}
        //STACK FINISHING
                /*STACK CLOSING*/



            /*Program for QUEUE */
                        //Initiating program for Queue
#define max 100
int first=-1;
int last = -1;

void enqueue(int n){
    if(last==max-1){
        printf("\nQueue is full");
    }
    else{
        if(first==-1)
            first=0;
        last++;
        a[last]=n;
    }
}
void dequeue(){
    if(first==-1||first>last){
        printf("\nQueue is empty");
    }
    else{
        printf("%d is dequeued",a[first]);
        first++;
    }
}
void displayed()
{
    int i;
    if(first==-1)
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("\nQueue is:\n***************\n  ");
        for(i=first;i<=last;i++)
        {
            printf("%d \t ",a[i]);
        }
        printf("\n");
    }
}
        /*Finishing for Queue*/




            /*EXPRESSION TREE*/
                        //  Tree EXPRESSION


//-------INORDER-------
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%c\t",root->data);
        inorder(root->right);
    }
}

//-------pre_order-------
void pre_order(struct node *root)
{
    if(root!=NULL)
    {
        printf("%c\t",root->data);
        pre_order(root->left);
        pre_order(root->right);
    }
}

//-------post_order-------
void post_order(struct node *root)
{
    if(root!=NULL)
    {
        post_order(root->left);
        post_order(root->right);
        printf("%c\t",root->data);
    }
}

int expression_tree()
{
char a[100];
int len,i;
struct node *new_node;


printf("Enter Expression:\n");
//gets(a);
scanf("%s",a);
len=strlen(a);
for(i=len-1 ; i>=0 ; i--)
{
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=a[i];
    new_node->left=new_node->right=new_node->prev=NULL;
    if(root==NULL)
    {
        root=new_node;
        cur=par=root;
    }
    else
    {
        if(a[i]=='+' ||a[i]=='-' ||a[i]=='*'||a[i]=='/')
        {
            if(par->right==NULL)
            {
                cur=new_node;
                par->right=cur;
                cur->prev=par;
                par=cur;
            }
            else if(par->left==NULL)
            {
                cur=new_node;
                par->left=cur;
                cur->prev=par;
                par=cur;
            }
            else
            {
                while(par->left!=NULL)
                {
                    par=par->prev;
                }
                cur=new_node;
                par->left=cur;
                cur->prev=par;
                par=cur;
            }
        }
        
        else
        {
            if(par->right==NULL)
            {
                cur=new_node;
                par->right=cur;
                cur->prev=par;
            }
            else if(par->left==NULL)
            {
                cur=new_node;
                par->left=cur;
                cur->prev=par;
            }
            else
            {
                while(par->left!=NULL)
                {
                    par=par->prev;
                }
                cur=new_node;
                par->left=cur;
                cur->prev=par;
            }
        }
    }
}
    
    /*
printf("\nInorder Traversal: \n");
inorder(root);
 printf("\n\nPreorder Traversal: \n");
 pre_order(root);
 printf("\n\nPostorder Traversal: \n");
 post_order(root);
 */
printf("\n");
return 0;
}
        /*----------Finishing Expressin TREE_______*/



/*___________Progam for AVL Tree___________*/

int height(node *T)
{
    int lh,rh;
    if(T==NULL)
        return(0);
    
    if(T->Left==NULL)
        lh=0;
    else
        lh=1+T->Left->ht;
    
    if(T->Right==NULL)
        rh=0;
    else
        rh=1+T->Right->ht;
    
    if(lh>rh)
        return(lh);
    
    return(rh);
}

node * rotateright(node *x)
{
    node *y;
    y=x->Left;
    x->Left=y->Right;
    y->Right=x;
    x->ht=height(x);
    y->ht=height(y);
    return(y);
}

node * rotateleft(node *x)
{
    node *y;
    y=x->Right;
    x->Right=y->Left;
    y->Left=x;
    x->ht=height(x);
    y->ht=height(y);
    
    return(y);
}

node * RR(node *T)
{
    T=rotateleft(T);
    return(T);
}

node * LL(node *T)
{
    T=rotateright(T);
    return(T);
}

node * LR(node *T)
{
    T->Left=rotateleft(T->Left);
    T=rotateright(T);
    
    return(T);
}

node * RL(node *T)
{
    T->Right=rotateright(T->Right);
    T=rotateleft(T);
    return(T);
}

int BF(node *T)
{
    int lh,rh;
    if(T==NULL)
        return(0);
    
    if(T->Left==NULL)
        lh=0;
    else
        lh=1+T->Left->ht;
    
    if(T->Right==NULL)
        rh=0;
    else
        rh=1+T->Right->ht;
    
    return(lh-rh);
}


node * Delete(node *T,int x)
{
    node *p;
    
    if(T==NULL)
    {
        return NULL;
    }
    else
        if(x > T->data1)        // insert in Right subtree
        {
            T->Right=Delete(T->Right,x);
            if(BF(T)==2)
            {
                if(BF(T->Left)>=0)
                    T=LL(T);
                else
                    T=LR(T);
            }
        }
        else
            if(x<T->data1)
            {
                T->Left=Delete(T->Left,x);
                if(BF(T)==-2)
                {    //Rebalance during windup
                    if(BF(T->Right)<=0)
                        T=RR(T);
                    else
                        T=RL(T);
                }
            }
            else
            {
                //data1 to be deleted is found
                if(T->Right!=NULL)
                {    //delete its inorder succesor
                    p=T->Right;
                    
                    while(p->Left!= NULL)
                        p=p->Left;
                    
                    T->data1=p->data1;
                    T->Right=Delete(T->Right,p->data1);
                    
                    if(BF(T)==2)
                        {//Rebalance during windup
                        if(BF(T->Left)>=0)
                            T=LL(T);
                        else
                            T=LR(T);
                        }
                }
                else
                    return(T->Left);
            }
    T->ht=height(T);
    return(T);
}

node *insert(node *T,int x)
{
    if(T==NULL)
    {
        T=(node*)malloc(sizeof(node));
        T->data1=x;
        T->Left=NULL;
        T->Right=NULL;
    }
    else
        if(x > T->data1)        // insert in Right subtree
        {
            T->Right=insert(T->Right,x);
            if(BF(T)==-2)
            {
                if(x>T->Right->data1)
                    T=RR(T);
                else
                    T=RL(T);
            }
        }
        else
            if(x<T->data1)
            {
            T->Left=insert(T->Left,x);
                if(BF(T)==2)
                {
                if(x < T->Left->data1)
                        T=LL(T);
                    else
                        T=LR(T);
                }
            }
    
    T->ht=height(T);
    
    return(T);
}





void Pre_order(node *T)
{
    if(T!=NULL)
    {
        printf("%d(Bf=%d)   ",T->data1,BF(T));
        Pre_order(T->Left);
        Pre_order(T->Right);
    }
}

void Inorder(node *T)
{
    if(T!=NULL)
    {
        Inorder(T->Left);
        printf("%d(Bf=%d)   ",T->data1,BF(T));
        Inorder(T->Right);
    }
}

void Post_order(node *t)
{
    if(t != NULL)
    {
        Post_order(t->Left);
        Post_order(t->Right);
        printf("%d(BF=%d)  ",t->data1,BF(t));
    }
}

node *root1=NULL;
void printing_AVL(node *root1)
{
printf("\nPreorder sequence:\n\t");
Pre_order(root1);
printf("\n\nPostorder sequence:\n\t");
Post_order(root1);
printf("\n\nInorder sequence:\n\t");
Inorder(root1);
printf("\n");
}

void creating_AVL()
{
    int i,x;
printf("\nEnter no. of elements:");
scanf("%d",&n);
printf("\n__________Enter tree data..._______\n");
//root1=NULL;
for(i=0;i<n;i++)
{
    scanf("%d",&x);
    root1=insert(root1,x);
}
}
            //___________FINISHING AVL Tree______________//












node* createnode(int data)
{
    node* newnode;
    newnode=(node*)malloc(sizeof(newnode));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}



node* findmin(node* root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}

node* insert_BST(node* root,int data)
{
    if(root==NULL)
        return createnode(data);
    if(data<root->data)
        root->left=insert_BST(root->left,data);
    else if(data>root->data)
        root->right=insert_BST(root->right,data);
    return root;
    
}

int search_BST(node* root,int value)
{
    if(root==NULL)
        printf("\n!!!!No data is to delete\n");
    else if(root->data==value)
    {
        printf("Data found...");
        return 1;
    }
    else if(value<root->data)
        search_BST(root->left,value);
    else if(value>root->data)
        search_BST(root->right,value);
    else
        printf("OOps!! Data is not present");
    
    return 0;
    
}



node* delete_BST(node* root,int value)
{
    int c;
    c=search_BST(root,value);
    if(root==NULL)
        return root;
    else if(value<root->data)
    {
        root->left=delete_BST(root->left,value);
    }
    else if(value>root->data)
    {
        root->right=delete_BST(root->right,value);
    }
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            root=NULL;
            return root;
        }
        else if(root->left==NULL)
        {
            node* temp=root;
            root=root->right;
            free(temp);
            return root;
        }
        else if(root->right==NULL)
        {
            node* temp=root;
            root=root->left;
            free(temp);
            return root;
        }
        else
        {
            node* temp=findmin(root->right);
            root->data=temp->data;
            root->right=delete_BST(root->right,temp->data);
        }
    }
    return root;
}
void inorder_BST(struct node *root)
{
    if (root != NULL)
    {
        inorder_BST(root->left);
        printf("%d \t\t",root->data);
        inorder_BST(root->right);
    }
}



            /*_________HEAP in BST_________*/
                    //_____Proceeding_____//


int array[100], nn;


int display_heap(int nn)
{
    int i;
    printf("\n");
    if (nn == 0)
    {
        printf("********Heap is empty******* \n");
        //return 1;
    }
    printf("______MAX_Heap_______\n");
    for (i = 0; i < nn; i++)
        printf("%d\t ", array[i]);
    printf("\n");
    return 0;
}





int insert_HEAP(int num, int location)
{
    int parentnode;
    while (location > 0)
    {
        parentnode =(location - 1)/2;      //for getting parant location..
        if (num <= array[parentnode])
        {
            array[location] = num;
            return 2;
        }
        array[location] = array[parentnode];
        location = parentnode;
    }
    array[0] = num;      /*assign number to the root node */
    return 0;
}

int deletion_heap(int num,int nn)
{
    int left, right, i, temp, parentnode;
    
    for (i = 0; i < num; i++)
    {
        if (num == array[i])
            break;
    }
    if (num != array[i])
    {
        printf("%d not found in heap list\nn", num);
        //return 4;
    }
    array[i] = array[nn - 1];
    nn = nn - 1;
    parentnode =(i - 1) / 2; /*find parentnode of node i */
    if (array[i] > array[parentnode])
    {
        insert_HEAP(array[i], i);
        return 5;
    }
    left = 2 * i + 1; /*left child of i*/
    right = 2 * i + 2; /* right child of i*/
    
    while (right < nn)
    {
        if (array[i] >= array[left] && array[i] >= array[right])
            return 6;
        if (array[right] <= array[left])
        {
            temp = array[i];
            array[i] = array[left];
            array[left] = temp;
            i = left;
        }
        else
        {
            temp = array[i];
            array[i] = array[right];
            array[right] = temp;
            i = right;
        }
        left = 2 * i + 1;
        right = 2 * i + 2;
    }
    
    if (left == nn - 1 && array[i])
    {
        temp = array[i];
        array[i] = array[left];
        array[left] = temp;
    }
    return 0;
}




            //___________Closing of MAX_HEAP in BST__________//





int heap[1000000], heapSize;

void Init()
{
    heapSize = 0;
    //heap[0] = -INT_MAX;
}


void insert_min_heap(int element) {
    heapSize++;
    heap[heapSize] = element;
    
    int now = heapSize;
    while (heap[now / 2] > element) {
        heap[now] = heap[now / 2];
        now /= 2;
    }
    heap[now] = element;
}

int DeleteMin_heap() {
    
    int minElement, lastElement, child, now;
    minElement = heap[1];
    lastElement = heap[heapSize--];
    
    for (now = 1; now * 2 <= heapSize; now = child)
    {
        
        child = now * 2;
        
        if (child != heapSize && heap[child + 1] < heap[child])
        {
            child++;
        }
        
        if (lastElement > heap[child])
        {
            heap[now] = heap[child];
        } else
        {
            break;
        }
    }
    heap[now] = lastElement;
    return minElement;
}













                    /*INITIATING MAIN FUNCTION*/
            //_________Starting MAIN Function_______//
int main()
{
    int s1,s2,s3,s4,s5,s6,s7,s8,s9,s10,s11;
    int low;
    int i;
    int choice,x,position;
    int ch;
    int op;
    int iter;
    int element;
    int nn=0,num;
    do
    {
        printf("\n1.Exit\n2.Sorting\n3.Linked List\n4.Stack\n5.Queue\n6.Tree in Data Structure\n7.Graph\nEnter your choice:\n");
            scanf("%d",&s1);
        
        switch(s1)
        {
            case 1:exit(0);
                break;
                
            case 2:printf("\n1.Exit\n2.Using Array\n3.using Liked List\n4.Heap Sort\nEnter your choice:\n");
                    scanf("%d",&s2);
                // nested switch
                switch(s2)
            {
                case 1:exit(0);
                    break;
                    
                case 2:printf("\n1.Bubble Sort\n2.Insertion Sort\n3.Selection Sort\n4.Count Sort\n5.Merge Sort\n6.Quick Sort\n7.Radix Sort\n\nEnter your Option\n");
                        scanf("%d",&s3);
                    //third nested switch
                    switch(s3)
                {
                    case 1:bubble_sort(a);  //Done
                        break;
                    case 2:
                        printf("Enter the Number of elements:\n");
                            scanf("%d",&n);
                        printf("Enter the Numbers...\n");
                        for(i=1;i<=n;i++)
                            scanf("%d",&a[i]);
                        insertion_sort(a,n);    //CALLING Insertion Sorting
                        printf("Sorted Elements are:\n");
                        for(i=1;i<=n;i++)
                            printf("%d\t",a[i]);
                        break;
                    case 3:selection_sort(a);
                        break;
                    case 4:count_sort(a);
                        break;
                    case 5:
                        printf("Enter no of elements:\n");
                            scanf("%d",&n);
                        printf("Enter array elements:\n");
                        for(low=0;low<n;low++)
                            scanf("%d",&a[low]);
                        merge_sort(a,0,n-1);  //MergeSort CALL
                        print_array(a,n);
                        break;
                    case 6:printf("Enter the Number of elements:\n");
                            scanf("%d",&n);
                        printf("Enter the Numbers...\n");
                        for(i=0;i<n;i++)
                            scanf("%d",&a[i]);
                        quick_sort(a,0,n-1); //Calling  QuickSort Function
                        print_array(a,n);
                        break;
                    case 7:printf("Enter no of elements:\n");
                        scanf("%d",&n);
                        printf("Enter array elements:\n");
                        for(low=0;low<n;low++)
                            scanf("%d",&a[low]);
                        radix_sort(a);    //FUNCTION CALL RadixSort
                        print_array(a,n);
                        break;
                }
            
                
                break;
        case 4:printf("1.MaxHeap\n2.MinHeap\nEnter your choice:\n");
                scanf("%d",&s4);
                
                switch(s4)
                {
                    case 1:printf("Enter no of elements:\n");
                        scanf("%d",&n);
                        printf("Enter array elements:\n");
                        for(low=0;low<n;low++)
                            scanf("%d",&a[low]);
                        heap_sort(a,n);  //MaxHeapSort CALL
                        print_array(a,n);
                        break;
                    case 2:printf("Enter no of elements:\n");
                        scanf("%d",&n);
                        printf("Enter array elements:\n");
                        for(low=0;low<n;low++)
                            scanf("%d",&a[low]);
                        minheap_sort(a,n);  //MinHeapSort CALL
                        print_array(a,n);
                        break;
                }
                break;
            }
        
            case 3:printf("\n1.Single Linked List\n2.Double Linked List \n3.Circular Linked List\nEnter your choice:\n");
                scanf("%d",&s5);
                switch(s5)
                {
                    do
                    {case 1:printf("\n1.Exit\n2.display\n3.insert_beg\n4.insert_end\n5.insert_position\n6.deletion_beg\n7.Deletion_end\n8.Deletion_place\n9.Search\n10.Length\n11.Deletionvalue\n12.Reverse\nEnter your choice:\n");
                        scanf("%d",&choice);
                        
                        switch (choice)
                    {
                        case 1:
                            exit(0);
                            break;
                        case 3:
                            printf("Enter the value to be inserted:");
                            scanf("%d", &x);
                            insert_beg(x);
                            break;
                            
                        case 4:
                            printf("Enter the value to be inserted:");
                            scanf("%d", &x);
                            insert_end(x);
                            break;
                            
                        case 5:
                            printf("Enter the value to be inserted:");
                            scanf("%d", &x);
                            printf("Enter the position of inserting element:");
                            scanf("%d",&position);
                            insert_place(x,position);
                            break;
                            
                        case 2: display();
                            break;
                            
                        case 6: deletion_beg();
                            break;
                            
                        case 7: deletion_end();
                            break;
                            
                        case 8: printf("Enter the element place to delete:");
                            scanf("%d",&x);
                            deletion_place(x);
                            break;
                            
                        case 9: printf("Enter the element to be searchead:");
                            scanf("%d",&x);
                            look_for(x);
                            
                        case 10: length();
                            break;
                            
                        case 12: reverse();
                            break;
                            
                        case 11:printf("Enter value to be deleted:");
                            scanf("%d",&x);
                            deletion_value(x);
                    }
                            
                  }while(choice != 1);
                        break;
                    case 2://doublelinked_list
                        break;
                    case 3://circularlinked_list
                        break;
                        
                }
        break;
            case 4: do
            {
                printf("1.Exit\n2.Display\n3.Push Element\n4.Pop Element\nEnter your choice:");
                scanf("%d",&s6);
                
                switch(s6)
                {
                    case 1:exit(0);
                        break;
                    case 2:Display();
                        break;
                    case 3:printf("Enter the value to be inserted:");
                        scanf("%d",&x);
                        insertorPUSH(x);
                        break;
                    case 4:
                        POP();
                        break;
                    default:
                        printf("Wrong choice....\n");
                        break;
                }
            }while(s6 != 1);
                break;
            case 5:
                    while(1)
                    {
                        
                        printf("1. Enqueue \n2. Dequeue \n3. Display \n4. Exit\nEnter your choice");
                        scanf("%d",&ch);
                        switch(ch)
                        {
                            case 1:
                                printf("Enter value : ");
                                scanf("%d",&n);
                                enqueue(n);
                                break;
                            case 2:
                                dequeue();
                                break;
                            case 3:
                                displayed();
                                break;
                            case 4:
                                exit(0);
                                break;
                        }
                    }
                break;
            
            case 6:printf("1:)Binary Search Tree\n2:)AVL Tree\n3:)HEAP\n4:)Expression Tree\n5:)Spanning Tree\nEnter your choice:\n");
                scanf("%d",&s7);
                switch(s7)
                {
                    case 1:do
                    {
                        printf("\n1.Exit\n2.Insert\n3.Search\n4.Delete\n5.Display\nEnter your choice:)\n");
                        scanf("%d",&s8);
                        switch(s8)
                        {
                            case 1:exit(0);
                                break;
                            case 2:printf("enter the number to insert_BST\n");
                                scanf("\t%d",&x);
                                root=insert_BST(root,x);
                                break;
                            case 3:printf("Element to search_BST:");
                                scanf("%d",&x);
                                search_BST(root,x);
                                break;
                            case 4: printf("enter the number to delete_BST\n");
                                scanf("%d",&x);
                                root=delete_BST(root,x);
                                break;
                            case 5:printf("\t\t____Inorder______\n");
                                inorder_BST(root);
                                printf("\n");
                        }
                    }while(s8 != 1);
                
                        break;
                    case 2:do
                    {
                        printf("\n1)Create:\n2)Insert:\n3)Delete:\n4)Print:\n5)Quit:\nEnter Your Choice:\n");
                        scanf("%d",&op);
                        
                        switch(op)
                        {
                            case 1: creating_AVL();
                                break;
                                
                            case 2: printf("\nEnter a data:");
                                scanf("%d",&x);
                                root1=insert(root1,x);
                                break;
                                
                            case 3: printf("\nEnter a data:");
                                scanf("%d",&x);
                                root1=Delete(root1,x);
                                break;
                                
                            case 4: printing_AVL(root1);
                                break;
                        }
                    }while(op!=5);
                        
                        break;
                    case 3:printf("\n1.MaxHeap\n2.MinHeap\nEnter your choice:---\n");
                        scanf("%d",&s9);
                        switch(s9)
                        {
                            case 1:
                                do
                                {
                                    printf("\n1.Insert the element \n2.Delete the element \n3.Display_heap all elements \n4.Quit \nEnter your choice:)\n");
                                scanf("%d",&s10);
                                switch(s10)
                                {
                                    case 1:
                                        printf("Enter the element to be inserted to the list : ");
                                        scanf("%d", &num);
                                        insert_HEAP(num, nn);
                                        nn = nn + 1;
                                        break;
                                    case 2:
                                        printf("Enter the elements to be deleted from the list:\n ");
                                        scanf("%d", &x);
                                        deletion_heap(x,n);
                                        break;
                                    case 3:
                                        display_heap(nn);
                                        break;
                                    case 4:
                                        exit(0);
                                }
                                }while(s10 != 4);
                                break;
                            case 2://MIN_HEAP
                                do
                            {
                                printf("\n1.Insert the element \n2.Delete the element \n3.Display all elements \n4.Quit \nEnter your choice:)\n");
                                scanf("%d",&s11);
                                switch(s11)
                                {
                                case 1:
                                    
                                    printf("\nEnter the number of elements: ");
                                    scanf("%d",&n);
                                    
                                    Init();
                                    printf("Enter the elements: \n");
                                    for (iter = 0; iter < n ; iter++) {
                                        scanf("%d", &element);
                                        insert_min_heap(element);
                                    }
                                    break;
                                case 2:
                                    printf("Enter the elements to be deleted from the list:\n ");
                                    scanf("%d", &x);
                                    DeleteMin_heap();
                                    break;
                                case 3:
                                    display_heap(n);
                                    break;
                                case 4:
                                    exit(0);
                                break;
                                }
                            }while(s11 != 4);
                        }
                        break;
                    case 4:printf("\n1.Prefix Order\n2.Postfix Order \nEnter your choice??\n ");
                        scanf("%d",&s7);
                        switch(s7)
                        {
                        case 1:expression_tree();
                            inorder(root);
                            printf("\n");
                            break;
                        case 2:expression_tree();
                            post_order(root);
                            printf("\n");
                                break;
                        }
                }
                break;
                
            case 8://GRAPH
                break;
        }
                
    }while(s1 != 1);
    
    return 0;
}

