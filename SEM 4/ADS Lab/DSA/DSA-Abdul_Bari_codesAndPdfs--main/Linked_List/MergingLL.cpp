#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;
void Display(struct Node *p)
{

    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void create2(int A[], int n)
{
    int i;
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
int Count(struct Node *p)
{
    int count = 0;
    while (p != 0)
    {
        count++;
        p = p->next;
    }
    return count;
}
void Merge(struct Node *p, struct Node *q)
{
    struct Node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next=NULL;
    }
    else
    {
        third = last = q;
        q= q->next;
        third->next=NULL;
    }
    while (p && q)
    {
      if (p->data < q->data){
          last->next =p ; 
          last=p ; 
          p=p->next; 
          last->next =NULL; 
      }  else{
          last->next =q ; 
          last=q ; 
          q=q->next; 
          last->next =NULL; 
      }
    }
    if (p)
    {
        last->next= p; 
    }if (q)
    {
       last->next = q; 
    }
    
    
    
}
int main()
{
    int array[] = {10, 20, 20, 50, 70, 91, 100};
    create(array, 7);
    int Arr[] = {7, 8, 60, 500};
    create2(Arr, 4);
    Merge(first ,second) ; 
    Display(third); 
}