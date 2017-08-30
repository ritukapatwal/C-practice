#include <stdio.h>
void insertion(int arr[],int index, int val,int size){
  for(int i =size;i>index;i--){
    arr[i]=arr[i-1];
  }
  arr[index]=val;
}
 int main() {
  int size=0;
  printf("Enter the size of OneD array\n" );
  scanf("%d",&size );
  int arr[size];
  for (int i=0;i<size;i++) {
    arr[i]=0;
  }
  printf("Enter the elements\n" );
  for (int i=0;i<size;i++) {
    scanf("%d",&arr[i]);
  }

  printf("Enter the index and value\n" );
  int idx=0,val=0;
  scanf("%d%d",&idx,&val );
  if (idx>size-1|| idx<0) {
    printf("Index out of bounds\n");
    return -1;
  }
  insertion(arr,idx,val,size);
  printf("Now the list is\n" );
  for (int i=0;i<size;i++) {
    printf("%d\t",arr[i] );
  }
  return 0;
}
