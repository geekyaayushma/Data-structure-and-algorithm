//Inserting and Appending in a Array 
#include<stdio.h>
struct Array
{
 int A[10];
 int size;
 int length;
};
 void Display(struct Array arr)
 {
  int i;
  printf("\nElements are\n");
  for(i=0;i<arr.length;i++)
  printf("%d ",arr.A[i]);
 }
 void Append(struct Array *arr,int x)
 {
  if(arr->length<arr->size)
  arr->A[arr->length++]=x;
 }
 void Insert(struct Array *arr,int index,int x)
 {
  int i;
  if(index>=0 && index <=arr->length)
  {
    for(i=arr->length;i>index;i--)
    arr->A[i]=arr->A[i-1];
    arr->A[index]=x;
    arr->length++;
  }
 }
int main()
{
 struct Array arr1={{2,3,4,5,6},10,5};
 Append(&arr1,10);
 Insert(&arr1,0,12);
 Display(arr1);
 return 0;
}
// The time complexity of append is O(1).
// The best time complexity of insert is O(1) and the worst time complexity is O(n).