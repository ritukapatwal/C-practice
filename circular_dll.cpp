#include <iostream>

using namespace std;

 struct Node{
  int employId;
  Node *pre;
  Node *next;
};
Node *head=NULL;


Node *tail=NULL;

void insertBeg(int id){

  Node *ptr=new Node;
  ptr->employId=id;
  if(head==NULL){
  head=ptr;
  tail=ptr;
  ptr->pre=NULL;
  ptr->next=NULL;
  }

  else{
    tail->next=ptr;
    ptr->pre=tail;
    ptr->next=head;
    head->pre=ptr;
    tail=ptr;
  }
}

void display(){
  Node *temp=head;
  cout<<"List is:\n";
  while(temp!=tail){
    cout<<temp->employId<<"->";
    temp=temp->next;
  }
  cout<<temp->employId<<"->"<<temp->next->employId<<"\n";
}

void deleteAt(int index){
  Node *del=head;
  for(int i=0;i<index;i++){
    del=del->next;
  }
  if(del==head||index<0){
    cout<<"\nIndex out of bounds!!";
  }
  else{
    del->pre->next=del->next;
    del->next->pre=del->pre;
    del->pre=NULL;
    del->next=NULL;
    display();
  }
}

int main(){
  int id,index;
  char ch;
  do{
    cout<<"Enter value: ";
    cin>>id;
    insertBeg(id);
    cout<<"Do you want to enter more values? ";
    cin>>ch;
  }while(ch=='y'||ch=='Y');
  display();
  cout<<"Enter the index of the value to be deleted: ";
  cin>>index;
  deleteAt(index);
  return 0;
}
