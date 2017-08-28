#include<stdio.h>
#include<malloc.h>
int j,i=0,queue[10],max=10,head=-1,tail=-1;

 void create(){
	   int num;
	   char choice;
       do{
	printf("enter data item to insert in queue\n");
	scanf("%d",&num);
	head=0;
	tail++;
	queue[tail]=num;
	printf("do you want to add more elements in queue\n");
	scanf("%c",&choice);
	scanf("%c",&choice);
	}while(choice=='y');
 }
void display(){
printf("the traversal of queue is:\n");
for(i=head,j=0;i<=tail;i++,j++){
   printf("%d<-",queue[i]);
  }
  printf("END\n");
}
void insert(int data){
if(tail==max-1){printf("insertion not possible\n");
 }
 queue[++tail]=data;
}
void delet(){

 printf("\nvalue deleted is: ");
 printf("%d\n",queue[head]);
 head++;
}

int  main(){

  create();
  display();
  insert(10);
  display();
  delet();
  display();
}
