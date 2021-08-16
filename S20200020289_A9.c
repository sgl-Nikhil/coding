#include <stdio.h>
#include<stdlib.h>

int tree_array_size = 11;
int heap_size = 10;
int A[21];

void swap(int *x, int *y){
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

//function to get left child:
int get_Lchild(int A[], int array_index) {
    if(((2*array_index) < tree_array_size) && (array_index >= 1))
        return 2*array_index;
    return -1;
}

//function to get the parent node:
int get_parent(int A[], int array_index) {
  if ((array_index > 1) && (array_index < tree_array_size)) {
    return array_index/2;
  }
  return -1;
}

//function to get right child:
int get_Rchild(int A[], int array_index) {
  if((((2*array_index)+1) < tree_array_size) && (array_index >= 1))
    return (2*array_index)+1;
  return -1;
}

void max_heapify(int A[], int array_index) {
  int left_child_index = get_Lchild(A, array_index);
  int right_child_index = get_Rchild(A, array_index);

  int largest = array_index;

  if ((left_child_index <= heap_size) && (left_child_index>0)){
    if (A[left_child_index] > A[largest]){
      largest = left_child_index;
    }
  }

  if ((right_child_index <= heap_size && (right_child_index>0))){
    if (A[right_child_index] > A[largest]){
      largest = right_child_index;
    }
  }

  if (largest != array_index){
    swap(&A[array_index], &A[largest]);
    max_heapify(A, largest);
  }
}

void build_max_heap(int A[]){
  int i;
  for(i=heap_size/2; i>=1; i--) {
   max_heapify(A, i);
  }
}

//...
void insert(int num)
{
    int n = sizeof(A)/sizeof(int);
    if((heap_size+1)<n){
        heap_size++;
        A[heap_size] = num;

        build_max_heap(A);
    }
    else
        printf("Heap is Full\n");
        return;
}

//...

void upward_heapify(int arr[], int size, int index)  
{  
int largest = index;    
int right = 2*index + 2;
int left = 2*index + 1;        
  
if (left < size && arr[left] >arr[largest])  
largest = left;  
  
if (right < size && arr[right] > arr[largest])  
largest = right;  
  
if (largest != index){  
int temp = arr[index];  
    arr[index]= arr[largest];   
    arr[largest] = temp;  
upward_heapify(arr, size, largest);  
}  
}  

void Sort(int arr[], int size){  
    int i;  
    for (i = size / 2 - 1; i >= 0; i--)  
    upward_heapify(arr, size, i);  
    for (i=size; i>0; i--)  
    {  
    int temp = arr[0];  
    arr[0]= arr[i];   
    arr[i] = temp;  
    upward_heapify(arr, i, 0);  
    }  
}  

//...
int update(int A[],int key,int alpha){
	int flag = 0;

	for(int i=1; i<heap_size+1; i++){
		if(A[i] == key){
		flag = 1;
		A[i] = key+alpha;

		for(int j=heap_size/2; j>=0; j--)
        max_heapify(A, j);

		break;
		}
	}

	if(flag == 1)
	return key+alpha;

	else
	return -1;

}

int main() {

//que - 1
printf("\n**que = 1------Time complexity = O(nlog(n))...\n");


  //starting from index 1 and not 0
for (int i = 1; i < 11; i++) {
    //generating random values b/w 0 to 30
    A[i] = rand()%31;
}

  build_max_heap(A);
  int i;
  printf("\nLevel wise parent and child nodes are : \n");

  for(i=1; i<10; i++) {
    printf("%d, ",A[i]);
  }


//que - 2
printf("\n\n**que = 2---------Time complexity = O(log(n))...\n\n");


    insert(13);
    insert(0);
    insert(7);
    for (int j = 1; j < 14; j++)
    printf("%d, ", A[j]);


//que - 3
printf("\n\n**que = 3--------------------Time complexity = O(n^2)...\n");

    update(A, 0,99);
    for (int k = 1; k < 14; k++)
    printf("%d, ", A[k]);
//que - 4
printf("\n\nque = 4--------------------Time complexity = O(nlog(n))...\n");

    Sort(A,10);
    for(i=10; i>0; i--){
    printf("%d, ",A[i]);
  }

  printf("\n");
  return 0;
}