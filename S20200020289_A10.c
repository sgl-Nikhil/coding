//NIKHIL KUMAR; Roll - S202000020289; Assign - 10;

#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

// functions 

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
 
void Insertion_Sort(int arr[], int size){
    int key;
    int j;
    for (int i = 1; i < size; i++){
        key = arr[i];
        j = i - 1;
            while (arr[j] > key && j >= 0){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void Selection_Sort(int arr[], int size)
{
    int min_indx;
    for (int i = 0; i < size-1; i++){
        min_indx = i;
        for (int j = i+1; j < size; j++)
          if (arr[j] < arr[min_indx])
            min_indx = j;

 // to swap minimum element with first
        swap(&arr[min_indx], &arr[i]);
    }
}

void Bubble_Sort(int arr[], int size){
   for (int i = 0; i < size-1; i++)     
       for (int j = 0; j < size-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}

void merge(int A[], int mid, int low, int high){
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high){
        if (A[i] < A[j]){
            B[k] = A[i];
            i++;
            k++;
        }
        else{
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid){
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high){
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
        A[i] = B[i];
}

void Merge_Sort(int A[], int low, int high){
    int mid; 
    if(low<high){
        mid = (low + high) /2;
        Merge_Sort(A, low, mid);
        Merge_Sort(A, mid+1, high);
        merge(A, mid, low, high);
    }
}

void Display_Array(int arr[], int n){
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    //que 1:
    printf("\t-----***QUE = 1***-----\n\n");
    int arr[50];
    srand((int)time(NULL));
    for(int i=0; i<50; i++){
        arr[i]=rand()%100;
    }
    printf("Original randomly generated array is :  \n");
    Display_Array(arr, 50);
    printf("\nSorted array by Insertion sorting : \n");
    printf("(1.) - Time complexity = O[n^2]\n");

    Insertion_Sort(arr, 50);
    Display_Array(arr, 50);

    // que - 2:
    printf("\n\t-----***QUE = 2***-----\n");

    printf("\nSorted array by Selection sorting : \n");
    printf("(2(a).) - Time complexity = O[n^2]\n");

    double start = clock();  
    Selection_Sort(arr, 50);
    double finish = (clock());
    double elapsed = (finish - start)/CLOCKS_PER_SEC; 
    
    Display_Array(arr, 50);
    printf("Selection sorting took %f seconds to execute...\n", elapsed);

    printf("\nSorted array by Bubble sorting : \n");
    printf("(2(b).) - Time complexity = O[n^2]\n");

    double start1 = clock();
    Bubble_Sort(arr, 50);
    double finish1 = clock();
    double elapsed1 = (finish1 - start1)/CLOCKS_PER_SEC; 
    
    Display_Array(arr, 50);
    printf("Bubble sorting took %f seconds to execute...\n", elapsed1);


    // que - 3:
    printf("\n\t-----***QUE = 3***-----\n");
    int X[] = {1,2,3,4,5,6,7,8,9,10};       //sorted input
    int Y[] = {10,9,8,7,6,5,4,3,2,1};       //reversed input
    int Z[] = {13,5,7,8,4,43,54,1,14,14};   //random input
    int size = 10;

    //(a.) Sorted
    printf("\n(3(a.)) - Sorted array by Merge sorting : \n");
    Merge_Sort(X, 0, size);
    Display_Array(X, size);
    printf("(3(a.)) - Time complexity = O[nlog(n)]\n");

    //(b.) reversed
    printf("\n(3(b.)) - Sorted array by Merge sorting : \n");
    Merge_Sort(Y, 0, size);
    Display_Array(Y, size);
    printf("(3(c.)) - Time complexity = O[nlog(n)]\n");

    //(c.) Random
    printf("\n(3(c.)) - Sorted array by Merge sorting : \n");
    Merge_Sort(Z, 0, size);
    Display_Array(Z, size);
    printf("(3(c.)) - Time complexity = O[nlog(n)]\n");


    printf("\n");
    return 0;
}


//4th question

/*
struct Item{
   int value;
   struct Item* next;
};

struct Item* new_item(int val){
    struct Item* pom = (struct Item*)malloc(sizeof(struct Item));
    pom -> value = val;
    pom -> next = NULL;
  
  return pom;
}
void print(struct Item* begin){
   struct Item * help = begin;
   while(help != NULL)
   {
      printf("%d ",help->value);
      help = help->next;
   }
}
struct Item* push_front(struct Item* begin, int new_value){
   struct Item* pom = new_item(new_value);
   pom -> next = begin;
   return pom;
 
}
void push_back(struct Item* begin, int new_value){
    struct Item* pom = begin;
    struct Item* new_end = new_item(new_value);
    while(pom->next != NULL) {
        pom = pom -> next;
    }
    pom -> next = new_end;
}
struct Item* insert(struct Item* begin, struct Item* position, struct Item* new_Item){
   if(begin == position) {
       new_Item -> next = begin;
       return new_Item;
   }
   
   struct Item* pom = begin;
   while(pom -> next != position) {
       pom = pom -> next;
   }
   
   new_Item -> next = pom -> next;
   pom -> next = new_Item;
   
   return begin;
 
}
int rand_number(int down, int up) {
    return (rand()%(up-down))+down;
}
struct Item* generate_random(int count, int down_bound, int up_bound) {
    int i;
    struct Item* start = new_item(rand_number(down_bound,up_bound));
    for(i=1;i<count;i++) {
        start = push_front(start, rand_number(down_bound,up_bound));
    }
    return start;
}

struct Item* insertion_sort(struct Item* begin)
{

   struct Item* sorted = begin;
   struct Item* preaktual = begin; 
   struct Item* pom;
   struct Item* pom1;
   
   while(preaktual -> next != NULL) {
       
       pom = sorted;
	   while( preaktual ->next  != NULL && pom != preaktual -> next && pom -> value < preaktual->next->value)
        pom = pom -> next;
       
       if(preaktual -> next != pom) { 
           pom1 = preaktual -> next;
           preaktual -> next = preaktual -> next -> next;
           sorted = insert(sorted,pom, pom1);
            
       }else{
        
        preaktual = preaktual -> next;
       }

   }
   
   

   return sorted;
}


int main( )
{
    struct Item* zoznam1 = generate_random(30,0,60);
    struct Item* zoznam2;
    print(zoznam1);
    printf("\n");
    zoznam2 = insertion_sort(zoznam1);
    print(zoznam2);
    printf("\n");
}
*/