#include <stdio.h>
void bubbleSort(int arr[],int size) {
  for(int i=0;i<size;i++){
    for(int j=0;j<size-i;j++){
      if(arr[j]>arr[j+1]){
        int temp =arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
      }
    }
  }
}

int main(){
  printf("Enter thr size of array\n");
  int size =0;
  scanf("%d",&size);
  int arr[size];
  printf("Enter %d elements\n",size);
  for(int i =0;i<size;i++){
    scanf("%d",&arr[i]);
  }
  bubbleSort(arr,size);
  printf("Now the list is\n" );
  for (int i=0;i<size;i++) {
    printf("%d\t",arr[i] );
  }
}
