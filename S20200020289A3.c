#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include <time.h>


//que =1(a.),   time complexity = O(n);

int main(){
 int arr[100], lower = 0, upper = 50, length = 10, KEY, flag = 0;
 srand(time(0));
    for (int i = 0; i < length; i++) {
        int num = (rand() % (upper - lower + 1)) + lower;
        arr[i] = num;
        printf("%d ", num);

    }
    printf("\n");
    printf("give me the KEY for search in array : ");
    scanf("%d", &KEY);
    for(int j = 0; j<length; j++){
        if(arr[j] == KEY)
        flag = 1;
        
    }
    if (flag == 1)
    printf("KEY found....\n");
    else if (flag == 0)
    printf("KEY not found....\n");
    return 0;
}

//que = 1(b.),   time complexity = O(n^2);


int main(){
 int arr[100], lower = 0, upper = 50, length = 10, KEY, flag = 0, a, b, temp;
 srand(time(0));
 printf("Random generated array : ");
    for (int i = 0; i < length; i++) {
        int num = (rand() % (upper - lower + 1)) + lower;
        arr[i] = num;
        printf("%d ", num);

    }
    printf("\n");
    for(a=0; a<length; a++)
    {
        
        for(b=a+1; b<length; b++)
        {
           
            if(arr[a] > arr[b])
            {
                temp     = arr[a];
                arr[a] = arr[b];
                arr[b] = temp;
            }
        }
    }

    
    printf("\nSorted array : ");
    for(a=0; a<length; a++)
    {
        printf("%d ", arr[a]);
    }
    
    printf("\n");
    printf("\nGive me the KEY for search in array : ");
    scanf("%d", &KEY);
    for(int j = 0; j<length; j++){
        if(arr[j] == KEY)
        flag = 1;
        
    }
    if (flag == 1)
    printf("\n\tKEY found....\n");
    else
    printf("\n\tKEY not found....\n");
    return 0;
}
 

//que = 2


int main(){
  int i,key,arr[20],flag=0;
  for(i=0; i<15; i++)
  {
    if(i==5)       //let us assume that vacancy is at index 5
     {
       printf("\t");
       continue;
     }

    arr[i]=(rand()%50);
    printf("%d\t",arr[i]);
  }

  int ind,x=12,n=15;
  printf("\n\nEnter the index(or say index + 1) to insert '12' in your array : ");
  scanf("%d",&ind);
  if(ind==6)
  {
    arr[ind-1]=x;
    for(i=0; i<=15; i++)
    printf("%d\t",arr[i]);
    return 0;
  }
  else
    {
      for(i=n; i>=ind; i--)
        {
          if(i==6)
          {
            arr[i]=arr[i-2];
            i--;
            continue;
          }
          arr[i]=arr[i-1];
        }
      arr[ind-1]=x;
    }
  printf("\nAfter inserting, we have :  \n");
  for(i=0; i<=15; i++)
  {
    if(i==5)
      {
        continue;
        printf("\n");
      }
    printf("%d\t",arr[i]);
  }
}


//que = 3


int main()
{
int m,n;
    printf("Value of m :");
    scanf("%d", &m);
    printf("Value of n :");
    scanf("%d", &n);
    int x = n-m+1;
        int arr[x][x];
    n = m;
    int tmp1 = n;        
    int tmp2 = m;
    int i, j;
    printf("\n");
    for(i = 0; i < x; i++)
    {
        for(j = 0; j < x; j++)
        {
        arr[i][j] = (tmp2)*(tmp1);
            printf("\t%3d", arr[i][j]);
        
        tmp1++;
        }
            printf("\n");
    tmp2++;
    tmp1 = n;
    }
    return 0;
}



//que = 4(a.)

int main() {
   int size = 4;
   int matrix[4][4] = {{4,15,14,1},{9,6,7,12},{5,10,11,8},{16,3,2,13}};
   int row, column = 0;
   int sum, sum1, sum2;
   int flag = 0;

   sum = 0;
   for (row = 0; row < size; row++) {
      for (column = 0; column < size; column++) {
         if (row == column)
            sum = sum + matrix[row][column];
      }
   }
 
   for (row = 0; row < size; row++) {
      sum1 = 0;
      for (column = 0; column < size; column++) {
         sum1 = sum1 + matrix[row][column];
      }
      if (sum == sum1)
         flag = 1;
      else {
         flag = 0;
         break;
      }
   }
 
   for (row = 0; row < size; row++) {
      sum2 = 0;
      for (column = 0; column < size; column++) {
         sum2 = sum2 + matrix[column][row];
      }
      if (sum == sum2)
         flag = 1;
      else {
         flag = 0;
         break;
      }
   }
 
   if (flag == 1)
      printf("\nYes, Magic square\n");
   else
      printf("\nNot a Magic square\n");
 
   return 0;
}


//que = 4(b.)


int main() {

   int size ;
   printf("Size : ");
   scanf("%d", &size);
   
   int matrix[size][size]; 
   int row = 0, column = 0;
   int sum, sum1, sum2;
   int flag = 0, re_inp = 1, count = 0;
    int start = time(NULL);

   printf("\nGive inputs for matrix : ");
   while(re_inp){
   for (row = 0; row < size; row++) {
      for (column = 0; column < size; column++)
         scanf("%d", &matrix[row][column]);
   }
 
    printf("Are you confirm about your inputs?\n");
    printf("\nif you are confirm then press any key.");
    printf("\nif you are NOT confirm then press 1.\n");
    scanf("%d", &re_inp);

    
    if(re_inp == 1){

count++;
   continue;
    }
re_inp=0;    
    
    
    }
   printf("Entered matrix is : \n");
   for (row = 0; row < size; row++) {
      printf("\n");

      for (column = 0; column < size; column++) {
         printf("\t%d", matrix[row][column]);
      }
   }
 
   sum = 0;
   for (row = 0; row < size; row++) {
      for (column = 0; column < size; column++) {
         if (row == column)
            sum = sum + matrix[row][column];
      }
   }
 
   for (row = 0; row < size; row++) {
      sum1 = 0;
      for (column = 0; column < size; column++) {
         sum1 = sum1 + matrix[row][column];
      }
      if (sum == sum1)
         flag = 1;
      else {
         flag = 0;
         break;
      }
   }

   for (row = 0; row < size; row++) {
      sum2 = 0;
      for (column = 0; column < size; column++) {
         sum2 = sum2 + matrix[column][row];
      }
      if (sum == sum2)
         flag = 1;
      else {
         flag = 0;
         break;
      }
   }
 
   if (flag == 1)
      printf("\n\nYes, Magic square.\n");
   else
      printf("\n\nNot a Magic square.\n");
    int end = time(NULL);
    float timetaken = end - start;
    printf("Time = %g(s)\n", timetaken);
    int alter = count;
    while(alter){

    }
    int score = timetaken + alter*100;
    printf("Your score is = %d.\n", score);
   return 0;
}


