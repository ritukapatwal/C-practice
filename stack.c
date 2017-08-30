#include <stdio.h>
#include <stdlib.h>
struct Node {
  int val;
  struct Node *back;
};
struct Node *top=NULL;
void push(int val){
  struct Node* newData = (struct Node*)malloc(sizeof(struct Node));
  newData->val=val;
  newData->back = NULL;
  if(top==NULL){
    top=newData;
  }else{
    newData->back=top;
    top=newData;
  }
}
void createStack() {
  char ch='N';
  do {
    printf("Enter value to be inserted in list\n" );
    int val=0;
    scanf("%d",&val);
    push(val);
    printf("Do you want to enter new data\n");
    scanf("%c",&ch );
    scanf("%c",&ch);
  } while(ch=='Y'||ch=='y');
}

void pop(){
  struct Node* nodeToBeDeleted = top;
  if(top!=NULL){
    top=top->back;
    printf("%d value deleted\n",nodeToBeDeleted->val );
    nodeToBeDeleted->back=NULL;
  }else{
    printf("Stack is empty\n");
  }
}
void display(){
  struct Node* start = top;
  if(top!=NULL){
    while(start!=NULL){
      printf("%d<-",start->val);
      start=start->back;
    }
    printf("END\n" );
  }else{
    printf("List is empty\n");
  }
}
int main(){
  createStack();
  display();
  printf("do you want to pop\n" );
  char choice;
  scanf("%c",&choice );
  scanf("%c",&choice);
  if(choice=='y'){
    pop();
    display();
  }
}
