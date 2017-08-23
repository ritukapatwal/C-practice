#include <stdio.h>
#include <stdlib.h>
struct Node {
  int rollNo;
  struct Node *next;
};
struct Node* head= NULL;
struct Node* tail= NULL;
int size=0;

void insertAtBegin( int rollNo){
  struct Node* newData = (struct Node*)malloc(sizeof(struct Node));
  newData->rollNo=rollNo;
  if(head==NULL){
    head = newData;
    head->next=NULL;
    tail= newData;
    tail->next=NULL;
    size++;
  }else{
    newData->next=head;
    size++;
    head=newData;
  }

}

void insertAtEnd(int rollNo){
  printf("%d\n",rollNo );

  if(head==NULL){
    insertAtBegin(rollNo);
  }else{
    struct Node* newData = (struct Node*)malloc(sizeof(struct Node));
    newData->rollNo=rollNo;
    tail->next=newData;
    tail=newData;
    tail->next=NULL;
    size++;
  }
}
void insertAtIndex(int rollNo, int index){
  if(index==0){
    insertAtBegin(rollNo);
    return;
  }
  if(index==size){
    insertAtEnd(rollNo);
    return;
  }
  if(index<0|| index>size){
    printf("Index out of bounds\n" );
    return;
  }
  struct Node* marker = head;
  for(int i =0;i<index-1;i++){
    marker=marker->next;
  }
  struct Node* newData = (struct Node*)malloc(sizeof(struct Node));
  newData->rollNo=rollNo;
  newData->next=marker->next;
  marker->next=newData;

}
void display(struct Node *node){
  if(node==NULL){
    printf("List is empty\n" );
    return;
  }
  while(node!=NULL){
    printf("%d->",node->rollNo );
    node=node->next;
  }
  printf("END\n");
}
void deleteAt(int index){
  if(index==0){
    struct Node* nodeToBeDeleted = head;
    head=head->next;
    nodeToBeDeleted->next=NULL;
    size--;
    return;
  }
  if(index<0|| index>size){
    printf("Index out of bounds\n" );
    return;
  }else{
    struct Node* marker = head;
    for(int i =0;i<index-1;i++){
      marker= marker->next;
    }
    struct Node* nodeToBeDeleted = marker->next;
    printf("%d\n",nodeToBeDeleted->rollNo );
    marker->next=nodeToBeDeleted->next;
    if(nodeToBeDeleted->next!=NULL)
    printf("%d\n",nodeToBeDeleted->next->rollNo );
    if(index==size-1){
      tail=marker;
    }
    nodeToBeDeleted->next=NULL;
    size--;

  }
}
int main(){
  insertAtBegin(20);
  insertAtEnd(40);
  insertAtEnd(60);
  display(head);
  printf("Now list is after insertion\n");
  insertAtIndex(50,2);
  display(head);
  printf("Now the list is after deletion\n" );
  deleteAt(3);
  display(head);
}
