//NIKHIL KUMAR; Roll - S202000020289; Assign - 11;

#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<limits.h>

//functions


int maximum(int A[], int n){
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < A[i]){
            max = A[i];
        }
    }
    return max;
    
}

void countSort(int * A, int n){
   int i, j;
   int max = maximum(A, n); 

   int* count = (int *) malloc((max+1)*sizeof(int));

   for (i = 0; i < max+1; i++)
   count[i] = 0; 

   for (i = 0; i < n; i++)
      count[A[i]] = count[A[i]] + 1;

    i =0; 
    j = 0;

    while(i<= max){
        if(count[i]>0){
            A[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else{
            i++;
        }
    } 
}

int count_sort_MP(int array[], int n) {
   int i, j, maxElement, count;
   int maxCount = 0;
   for(i = 0; i< n; i++)   {
      count = 1;
      for(j = i+1; j < n; j++){
         if(array[j] == array[i]){
               count++;    
               if(count > maxCount)
                  maxElement = array[j];
            }
        }
    }
   return maxElement;
}

int quick_sort_(int number[25], int first, int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quick_sort_(number,first,j-1);
      quick_sort_(number,j+1,last);

   }
   
}
int get_max (int a[], int n){
   int max = a[0];
   for (int i = 1; i < n; i++)
      if (a[i] > max)
         max = a[i];
   return max;
}
void radix_sort (int a[], int n){
   int bucket[10][10], bucket_cnt[10];
   int i, j, k, r, NOP = 0, divisor = 1, lar, pass;
   lar = get_max (a, n);
   while (lar > 0){
      NOP++;
      lar /= 10;
   }
   for (pass = 0; pass < NOP; pass++){
      for (i = 0; i < 10; i++){
         bucket_cnt[i] = 0;
      }
      for (i = 0; i < n; i++){
         r = (a[i] / divisor) % 10;
         bucket[r][bucket_cnt[r]] = a[i];
         bucket_cnt[r] += 1;
      }
      i = 0;
      for (k = 0; k < 10; k++){
         for (j = 0; j < bucket_cnt[k]; j++){
            a[i] = bucket[k][j];
            i++;
         }
      }
      divisor *= 10;
      printf ("After pass %d : ", pass + 1);
      for (i = 0; i < n; i++)
         printf ("%d ", a[i]);
      printf ("\n");
   }
}

void printpair(int a[], int n, int k){
    int i=0, j=n-1, ci, cj, check =0, count=1;
    while(i<=j){
        if(ci != a[i] || cj != a[j]){
            if(a[i] + a[j] == k){
                if(check == 0){
                    printf("YES, pairs found are: \n");
                }
                check=1;
                printf("pair %d -> (%d %d)\n", count, a[i], a[j]);
                count++;
            }
            ci = a[i];
            cj = a[j];
        }
        i++;
        j--;
    }
    if(check == 0){
        printf("NO, pairs found !!!\n");
    }
    printf("\n");
}


int main()
{
   // question - 1
   
   printf("\n\t***** QUESTION = 1 *****\n");
   printf("Time Complexity : O(n*Log n)\nAuxiliary Space : O(1)");
   int A[] = {4,2,5,6,3,3,4,3,2,1};
   int m = sizeof(A)/sizeof(A[0]); //size of array
   printf("The element with max repetition is : %d.\n", count_sort_MP(A, m));
    

   // question - 2
   
   printf("\n\t***** QUESTION = 2 *****\n");
   printf("Time Complexity : O(n^2)\nAuxiliary Space : O(1)");
   int B[] = {0,1,6,3,4,10,3,20,8,40,5};
   int n = sizeof(B)/sizeof(B[0]);
   quick_sort_(B, 0, n-1);
   printf("\nHence, max product of this array is : %d*%d = %d\n", B[n-2], B[n-1], B[n-2]*B[n-1]);
   

   //question = 3
   printf("\n\t***** QUESTION = 3 *****\n");
   printf("Time Complexity : O(n)\nAuxiliary Space : O(n)");
   int C[] = {3,2,5,1,7,0,4,6,9};
   srand(time(0));
   int k = rand() % 26;  // randoms bw 1 to 25
   int n2 = sizeof(C)/sizeof(C[0]);
   printf("\nRandom K = %d\n", k);
   printpair(C, n2, k);
   return 0;
}
