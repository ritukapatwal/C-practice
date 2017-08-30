#include<stdio.h>

void takeInput(int* matrix, int row, int col){
  printf("Enter the elements\n");
  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      scanf("%d",&(*((matrix+i*col)+j)));
    }
  }
}
void transpose(int* matrix, int* matrixTrans, int r1, int c1){
  for(int i=0;i<r1;i++){
    for(int j=0;j<c1;j++){
      (*((matrixTrans+j*r1)+i))=(*((matrix+i*c1)+j));
    }
  }

}
int isValidOperation(int r1,int c1, int r2, int c2,char op){
  int val;
  if(op=='*'){
      c1!=r2? val=-1 : val= 0;
  }else{
      (r1!=r2||c1!=c2)? val= -1: val= 0;
  }
  return val;
}

void operation(int* matrix1,int r1, int c1,int* matrix2,int r2,int c2,char operation){
  int isvalid = isValidOperation(r1,c1,r2,c2,operation);
  if(isvalid==-1){
    printf("operation cant be performed\n");
    return;
  }
  if(operation=='*'){
    int product[r1][c2];
    for(int i =0;i<r1;i++){
      for(int j=0;j<c2;j++){
        product[i][j]=0;
      }
    }
    for(int i =0;i<r1;i++){
      for(int j=0;j<c2;j++){
        for(int k=0;k<c1;k++){
          product[i][j]+=
          (*((matrix1+i*c1)+k))*(*((matrix2+k*c2)+j));
        }
      }
    }
    printf("\nResult is \n" );
    for(int i=0;i<r1;i++){
      for(int j=0;j<c2;j++){
        printf("%d\t",product[i][j]);
      }
      printf("\n");
    }
  }else{
    int result[r1][c1];
    for(int i=0;i<r1;i++){
      for(int j=0;j<c1;j++){
        result[i][j]=0;
      }
    }
    if(operation=='-'){
      for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
          result[i][j]=((*((matrix1+i*c1)+j))-(*((matrix2+i*c2)+j)));
        }
      }
    }
    if(operation=='+'){
      for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
          result[i][j]=((*((matrix1+i*c1)+j))+(*((matrix2+i*c2)+j)));
        }
      }
    }
    printf("\nResult is\n");
    for(int i=0;i<r1;i++){
      for(int j=0;j<c1;j++){
        printf("%d\t",result[i][j]);
      }
      printf("\n");
    }
  }
}
int main(){
  int r1=0,c1=0,r2=0,c2=0;
  printf("Matrix menu\n");
  printf("1)Addition\n2)Subtraction\n3)Multiplication\n4)Transpose\n\n");
  int choice=0;
  scanf("%d",&choice );
  if(choice==1||choice==2||choice==3){
    printf("Enter rows and Cols of matrix1\n" );
    scanf("%d%d",&r1,&c1);
    int matrix1[r1][c1];
    takeInput((int *)matrix1,r1,c1);
    printf("Enter rows and Cols of matrix2\n" );
    scanf("%d%d",&r2,&c2);
    int matrix2[r2][c2];
    takeInput((int *)matrix2,r2,c2);
    switch (choice) {
      case 1:
      operation((int*)matrix1,r1,c1,(int*)matrix2,r2,c2,'+');
      break;
      case 2:
      operation((int*)matrix1,r1,c1,(int*)matrix2,r2,c2,'-');
      break;
      case 3:
      operation((int *)matrix1,r1,c1,(int *)matrix2,r2,c2,'*');
      break;
    }
  }else if(choice==4){
    printf("Enter rows and Cols of matrix\n" );
    scanf("%d%d",&r1,&c1);
    int matrix[r1][c1];
    takeInput((int *)matrix,r1,c1);
    int matrixTrans[c1][r1];
    transpose((int*)matrix,(int*)matrixTrans,r1,c1);
    printf("Transpose of given matrix is\n");
    for(int i=0;i<c1;i++){
      for(int j=0;j<r1;j++){
        printf("%d\t",matrixTrans[i][j] );
      }
      printf("\n");
    }
  }else{
    printf("plz Enter within bounds\n");
  }
  return 0;
}
