#include<stdio.h>
#include<stdlib.h>
 
 struct Node
 {

     int data ;
     struct Node* next;

 };
  void linkedListTraversal(struct Node*ptr)
{
  while(ptr!=NULL)
  {
      printf("Element : %d\n",ptr->data );
      ptr=ptr->next;
  }
}
//case 1:delete the first element from linkedlist 
struct Node*deleteFirst(struct Node*head ){
    struct Node* ptr=head;
    head=head->next;
    free(ptr);
    return head;
}

//case 2: delete the element from the the  given index 

struct Node* deleteAtIndex (struct Node*head,int index ){
    struct Node *p=head;
    struct Node *q=head->next;
    for (int i=0;i<index-1;i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
} 
//case 3: delete at last from linked list
struct Node * deleteAtLast(struct Node*head)
{
    struct Node* p=head;
    struct Node*q=head->next ;
    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;

}

int main ()
 {
     struct Node *head;
     struct Node * second;
  struct Node * third;
  //alocate memory for nodes in linked in heap
  head = (struct Node *)malloc(sizeof (struct Node));
  second = (struct Node *)malloc(sizeof (struct Node));
 third= (struct Node *)malloc(sizeof (struct Node));

 head->data=7;
 head->next=second;

 second->data=11;
 second->next=third;

 third->data=15;
 third->next=NULL;

 printf("Linked List befor deletion \n");
 linkedListTraversal(head);
 //head=deleteFirst(head);//For deliting the first element 
 //head=deleteAtIndex(head,2);
 head = deleteAtLast(head);
 printf("Linked List after deletetion\n");
 linkedListTraversal(head);

 return 0;
   

 }
