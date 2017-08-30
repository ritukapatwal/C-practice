#include <stdio.h>
#include <stdlib.h>
struct Node {
  char name[20];
  int id;
  struct Node *next;
  struct Node *back;
};
struct Node *head= NULL;
struct Node *tail= NULL;
int size=0;

void insertAtBegin( int id){
  struct Node* newData = (struct Node*)malloc(sizeof(struct Node));
  newData->id=id;
  if(head==NULL){
    head = newData;
    head->next=NULL;
    head->back=NULL;
    tail= newData;
    tail->next=NULL;
    tail->back=NULL;
    size++;
  }else{
    newData->next=head;
    newData->back=NULL;
    size++;
    head=newData;
  }

}

void insertAtEnd(int id){
  printf("%d\n",id);

  if(head==NULL){
    insertAtBegin(id);
  }else{
    struct Node* newData = (struct Node*)malloc(sizeof(struct Node));
    newData->id=id;
    tail->next=newData;
    newData->back=tail;
    tail=newData;
    tail->next=NULL;
    size++;
  }
}
void insertAtIndex(int id, int index){
  if(index==0){
    insertAtBegin(id);
    return;
  }
  if(index==size){
    insertAtEnd(id);
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
  newData->id=id;
  struct Node *prevNode = marker;
  struct Node* nextNode = marker->next;
  prevNode->next=newData;
  newData->back=prevNode;
  newData->next=nextNode;
  nextNode->back=newData;
  size++;
}
void display(struct Node *node, int isHead){
  if(node==NULL){
    printf("List is empty\n" );
    return;
  }
  if(isHead==1){
    printf("Disply from start\n" );
    while(node!=NULL){
      printf("%d->",node->id );
      node=node->next;
    }
    printf("END\n");
  }else{
    printf("Disply from End\n" );
    while(node!=NULL){
      printf("%d->",node->id );
      node=node->back;
    }
    printf("END\n");
  }

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
    struct Node* prevNode=marker;
    struct Node* nextNode = marker->next->next;
    //printf("prevNode %d\n",prevNode->id );
    printf("Node to be deleted %d\n",nodeToBeDeleted->id );
    // if(nextNode!=NULL){
    //   printf("nextNode %d\n",nextNode->id );
    // }
    prevNode->next=nodeToBeDeleted->next;
    if(nextNode!=NULL){
      nextNode->back=nodeToBeDeleted->back;
    }
    //printf("nodeDelete back : %d\n",nodeToBeDeleted->back->id );
    // if(nextNode!=NULL){
    //   printf("nodeDelete back : %d\n",nextNode->back->id );
    // }
    if(index==size-1){
      printf("Tail case\n");
      tail=prevNode;
    }
    nodeToBeDeleted->next=NULL;
    nodeToBeDeleted->back=NULL;
    size--;

  }
}

int main(){
  insertAtBegin(20);

  insertAtEnd(40);

  insertAtEnd(60);

  display(head,1);
  display(tail,0);

  insertAtIndex(50,2);

  display(head,1);
  display(tail,0);
  printf("Now the list is after deletion\n" );
  deleteAt(2);

  display(head,1);

  display(tail,0);
}
