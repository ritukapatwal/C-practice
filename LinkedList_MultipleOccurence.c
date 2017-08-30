#include <stdio.h>
#include <stdlib.h>
struct Node{
  int val;
  struct Node *next;
};
struct Node *head=NULL;
struct Node *tail= NULL;
void createLinkedList(){

  char ch='N';
  do {
    printf("Enter value to be inserted in list\n" );
    int val=0;
    scanf("%d",&val);
    struct Node* newData = (struct Node*)malloc(sizeof(struct Node));
    newData->val=val;
    newData->next=NULL;
    if(head==NULL){
      head=newData;
      tail=newData;
    }else{
      tail->next=newData;
      tail=newData;
    }
    printf("Do you want to enter new data\n");
    scanf("%c",&ch );
    scanf("%c",&ch);
  } while(ch=='Y'||ch=='y');
}
void display(){
  struct Node *sp = head;
  if(sp==NULL){
    printf("list is empty\n");
  }else{
    while(sp!=NULL){
      printf("%d->",sp->val);
      sp=sp->next;
    }
    printf("END\n");
  }
}

void checkForMultiOccurence(int val){
  struct Node *sp = head;
  int i =0;
  int flag =0;
  if(sp==NULL){
    printf("list is empty\n");
  }else{
    while(sp!=NULL){
      if(sp->val==val){
        flag=1;
        printf("%d ocuured at %d\n",val,i);
      }
      i++;
      sp=sp->next;
    }
  }
  if(flag==0){
    printf("value not in list" );
  }
}

int main(){
  createLinkedList();
  display();
  printf("enter value to be checked\n" );
  int val=0;
  scanf("%d",&val);
  checkForMultiOccurence(val);
}
