//This program is written by NIKHIL KUMAR, ROLL - S20200020289.


//PART = B

#include <stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

// Que - 1


/*
long long fact(int num);
void printStrongNumbers(int start, int end);


int main()
{
    int start , end;
    
    // Input the range 
    start = 1;
    printf("Enter the upper limit(n): ");
    scanf("%d", &end);
    
    printf("All strong numbers between %d to %d are: ", start, end);
    printStrongNumbers(start, end);
    printf("\n");
    
    return 0;
}



//for printing all strong numbers between 1 to n:

void printStrongNumbers(int start, int end)
{
    long long sum;
    int num;
    
    // Iterates from start to end
    while(start != end)
    {
        sum = 0;
        num = start;
        
        // Calculate sum of factorial of digits
        while(num != 0)
        {
            sum += fact(num % 10);
            num /= 10; 
        }
        
        // If sum of factorial of digits equal to current number
        if(start == sum)
        {
            printf("%d, ", start);
        }
        
        start++;
    }
}



//to find factorial
long long fact(int num)
{
    if(num == 0)
        return 1;
    else
        return (num * fact(num-1));
}
*/




// Q.2 - Student Structure and some management



/*
int ind = -1;

struct student                                                                  // Structure
{
  char name[20];
  int roll;
  int sub_1;
  int sub_2;
  int sub_3;
}s[50];

void Mean_marks()                                         // To print out the mean marks
{

 float mean;
 for(int i=0 ; i<=ind ; i++)
 {
  mean = (s[i].sub_1 + s[i].sub_2 + s[i].sub_3) / 3.0;
  printf("\n Roll : %d",s[i].roll);
  printf("\n Name : %s",s[i].name);
  printf(" Mean Marks  : %f",mean);
  printf("\n\n\n");
 }
 
}

void search_student()                                     // To search the student based on roll number
{
 
  int roll;
  printf("Enter the roll number of the student : ");
  scanf("%d",&roll);
  for(int i=0 ; i<=ind ; i++)
  {
    if(roll == s[i].roll)
    {
      printf("\n Name : %s",s[i].name);
      printf(" Marks for subject 1 : %d",s[i].sub_1);
      printf("\n Marks for subject 2: %d",s[i].sub_2);
      printf("\n Marks for subject 3 : %d",s[i].sub_3);
      printf("\n\n");
    }
  }
}

int main()
{
  int n,roll;
  char str[20];
    
  printf(" Enter total number of students (maxlimit = 50) - ");               // To take the entries of the students
  scanf("%d",&n);
  if(n<=50)
   for(int i=0 ; i<n ; i++)
   {
     getchar();
     printf("\n Enter name of student : ");
     fgets(str,20,stdin);
     strcpy(s[i].name,str);

     printf(" Enter the roll number : ");
     scanf("%d",&roll);
     s[i].roll = roll;

     printf(" Enter marks for SUB_1 : ");
     scanf("%d",&(s[i].sub_1));
     printf(" Enter marks for SUB_2 : ");
     scanf("%d",&(s[i].sub_2));
     printf(" Enter marks for SUB_3 : ");
     scanf("%d",&(s[i].sub_3));
     ind++;
   }

  Mean_marks();
  getchar();
  search_student();

  return 0;
}
*/



// Q.3- Re-Scaling the values of a matrix


/*
void Rescale(float mat[][5])                              //This function rescales the values and print them
{

  float mean=0 , min=0 , max=0;

  for(int i=0 ; i<5 ; i++)
  {
    for(int j=0 ; j<5 ; j++)
    {
      mat[i][j] = 8 * (mat[i][j] / 255.0);
      mean+=mat[i][j];

      if(i==0 && j==0)
       { min = mat[i][j]; max = mat[i][j]; }

      if(mat[i][j] < min)
       min = mat[i][j];
      if(mat[i][j] > max)
       max = mat[i][j];
    }
  }
  mean /= 25;
  printf("\n Mean : %f",mean);
  printf("\n Min : %f",min);
  printf("\n Max : %f",max);
  printf("\n\t\t\t\t\t : Rescaled matrix : \n\n");
  int c=0;
  for(int i=0 ; i<5 ; i++)
  {
    for(int j=0 ; j<5 ; j++)
    {
     if(i!= 0 && c%5==0)
      printf("\n");

     printf("%f ",mat[i][j]);
     c++;
    }
  }
}


int main()
{
  float mat[5][5];
  printf("Enter the elements of matrix(5x5) [0-255] : \n");

  for(int i=0 ; i<5 ; i++)
  {
    for(int j=0 ; j<5 ; j++)
    {
     scanf("%f",&mat[i][j]);
    }
  }

  Rescale(mat);
  printf("\n");
  return 0;
}
*/

