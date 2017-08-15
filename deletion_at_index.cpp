#include <stdio.h>
#include <limits.h>
void deletion(int arr[],int val,int size){
  int newarr[size];
  for(int i =0,j=0;i<size;){
    if(arr[i]==val){
      i++;
    }else{
      newarr[j]=arr[i];
      i++;j++;
    }
  }
  newarr[size-1]=INT_MIN;
  for(int i =0;i<size;i++){
    arr[i]=newarr[i];
  }
}
 int main() {
   printf("Enter thr size of array\n");
   int size =0;
   scanf("%d",&size);
   int arr[size];
   printf("Enter the elements\n");
   for(int i =0;i<size;i++){
     scanf("%d",&arr[i]);
   }
   printf("Enter value to be deleted\n");
   int val=0;
   scanf("%d",&val);
   deletion(arr,val,size);
   for(int i =0;i<size;i++) {
     if(arr[i]!=INT_MIN){
       printf("%d\t",arr[i]);
     }
   }
  return 0;
}
