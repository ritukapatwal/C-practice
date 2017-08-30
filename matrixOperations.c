#include <stdio.h>
void prinSparceMatrix(int* matrix, int row, int col, int choice){
  if(row!=col){
    printf("its not square matrix\n");
    return;
  }
  // case of upper triangle
  if(choice==1){
    for(int i =0;i<row;i++){
      for(int j =0;j<col;j++){

        if(i<j){
          printf("0\t");
        }else{
          printf("%d\t",(*((matrix+i*col)+j)) );
        }
      }
      printf("\n");
    }
  }
  //case of lower triangle
  else if(choice==2){
    for(int i =0;i<row;i++){
      for(int j =0;j<col;j++){
        if(i>j){
          printf("%d\t",0);
        }else{
          printf("%d\t",(*((matrix+i*col)+j)) );
        }
      }
      printf("\n");
    }
  }
  // case of diagonal
  else if(choice==3){
    for(int i =0;i<row;i++){
      for(int j =0;j<col;j++){
        if(i!=j){
          printf("%d\t",0);
        }else{
          printf("%d\t",(*((matrix+i*col)+j)) );
        }
      }
      printf("\n");
    }
  }else{
    printf("enter option within bounds\n");
    return;
  }
}
int main(){
  printf("Enter the rows and cols of matrix\n");
  int rows=0,cols =0;
  scanf("%d%d",&rows,&cols);
  printf("enter the elements\n");
  int matrix[rows][cols];
  for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
      scanf("%d",&matrix[i][j]);
    }
  }
  printf("1)Upper triangle Matrix\n2)Lower triangle Matrix\n3)Diagonal Matrix\n");
  int choice;
  scanf("%d",&choice );

  prinSparceMatrix((int*)matrix,rows,cols,choice);
  return 0;
}
