//This program is written by NIKHIL KUMAR, ROLL - S20200020289
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include <time.h>
#define pi 3.14


//que - 1

/*
void list(int *a, int n) {
    srand(time(0));

    for(int i=0; i<n; i++) {
        a[i] = (rand()%n) + 1;
        printf("%d, ", a[i]);
    }

    printf("\n\n");
}

int search(int num, int n, int *a) {
    int flag=0;
    for(int i=0; i<n; i++) {
        if(a[i] == num) {
         printf("The element is found at %dth position in the random generated list.\n", i+1);
         flag=1;
        }
    }
    if(flag==0) printf("not found in this randomly generated list.\n----TRY ANOTHER.----\n\n");
    printf("No. of primitive steps = %d\n", n);
}

int main() {
    int a[100], num, n;
	printf("upperlimit for generating random numbers (n) : ");
	scanf("%d", &n);
    printf("%d Random numbers :-\n", n);
    printf("\n\n");
    list(a, n);

    printf("search key that you want to find :  ");
    scanf("%d", &num);

    search(num, n, a);

    return 0;
}
*/


//Que -2


/*
void isprime(int* x){
	int n = *x;
	int flag = 0;
	 if(n==1) {
        printf("'1' is neither prime nor composite.\n");
    }
    else {
        for(int i=2; i<=sqrt(n); i++) {
            if(n%i==0) {
                flag = 1;
                break;
            }
        }

        if(flag==1) {
            printf("'%d' is a composite number.\n", n);
        }
        else {
            printf("'%d' is a prime number.\n", n);
        }
    }
}
int main()
{
    int n, flag=0;

    printf("Give me any positive integer : ");
    scanf("%d", &n);

    isprime(&n);
	printf("\n");

    return 0;
}
*/


//Que - 3

/* Time complexity = O(n);

since for recursive function T(N) = T(N) + C, where C is constant;
So ignoring the constant (because it does not affect the time complexity);
we will get time complexity = O(n).
*/


/*
   int fibon(int* n)
    {
        int a,b,c;
        a=*n;
        b=a-1;
        c=a-2;

    if (a == 0 || a == 1)
        return a;
    else
    return fibon(&b) + fibon(&c);
    }

int main()
{    
    int n;
    printf("give the number to list fibonacci series : ");
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
    printf("%d, ",fibon(&i));
	}
	printf("\n\n");
	return 0;
}
*/


//Que -4

/*
void Generate_new_array(int A[] , int B[] , int n)
{
 for(int i=0 ; i<n-2 ; i++)
 {
  for(int j=0 ; j<n-2 ; j++)
   {
    (B + i(n-2) + j) = ((A + i(n) + j)) / 9 + ((A + i(n) + j+1)) / 9 + ((A + i(n) + j+2)) / 9 ;
    (B + i(n-2) + j) += ((A + (i+1)(n) + j)) / 9 + ((A + (i+1)(n) + j+1)) / 9 + ((A + (i+1)(n) + j+2)) / 9 ;
    (B + i(n-2) + j) += ((A + (i+2)(n) + j)) / 9 + ((A + (i+2)(n) + j+1)) / 9 + ((A + (i+2)(n) + j+2)) / 9 ;
    }
 }
}

int main()
{
  int n;
  srand(time(0));
  printf(" Enter n for the dimension of matrix ");
  scanf("%d",&n);
  int A = (int) malloc(n*n*sizeof(int));
  int B = (int) malloc((n-2)*(n-2)*sizeof(int));

  for(int i = 0 ; i<n*n ; i++)
   {
     A[i] = rand() % 256;
   }

  printf("\n Generated array is : \n");

  for(int i=0 ; i<n ; i++)
  {
   for(int j=0 ; j<n ; j++)
   {
    printf(" %d ",*(A + i*n + j) );
   }
   printf("\n");
  }

  Generate_new_array(A,B,n);

  printf("\n New convolved array is : \n");

  for(int i=0 ; i<n-2 ; i++)
  {
   for(int j=0 ; j<n-2 ; j++)
   {
    printf(" %d ",(B + i(n-2) + j) );
   }
   printf("\n");
  }


  free(B);
  free(A);
  return 0;
}
*/




/*
clock_t t;


int checkMagic(int n,int matrix[n][n]){
 
    int size = n;
   int row, column = 0;
   int sum, sum1, sum2,sum3;
   int flag = 0;
 
   for (row = 0; row < size; row++) {
      for (column = 0; column < size; column++) {
         if (row == column)
            sum = sum + matrix[row][column];
      }
   }
 sum3=0;
 for (row = 0; row < size; row++) {
     
      sum3=sum3+matrix[size-row-1][row];
   }
 if(sum3==sum){
     flag=1;
 }else{
     flag=0;
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
   
   return flag;
}


void game()
{
	printf("Enter the size of the Matrix\n");
	int n,row,col,val,change;
	  char yn;
	scanf("%d",&n);
	t = clock();
	int arr[n][n];
	for (int i = 0; i <n; i++)
    {
    	for (int j = 0; j <n; j++)
    {
        arr[i][j]=0;
    }
    }
    while(1){
	printf("--");
    for(int i=0;i<n;i++){
    	printf("%d ",i);
    }
    printf("\n");

    printf("\n");
    for (int i = 0; i <n; i++)
    {
    	printf("%d|", i);
    	for (int j = 0; j <n; j++)
    {  
        if(arr[i][j]==0){
            printf("0 ");
        }else{
            printf("%d ",arr[i][j]);
        }
    }
    printf("\n");
    }
    
    printf("Enter the row and column number and the value you want to assign separated by space ");
    scanf("%d %d %d",&row,&col,&val);
    if(row>=0 && col>=0 && row<n && col<n){
        if(arr[row][col]!=0){
          
                arr[row][col]=val;
                change++;
            
        }else{
           
                arr[row][col]=val;
     
        }
        
    }else{
        printf("Invalid row or column number.\n");
    }
    
    int check=0;
    for (int i = 0; i <n; i++)
    {
    	for (int j = 0; j <n; j++)
    {
        if(arr[i][j]==0){
            check=1;
            break;
        }
    }
    }
    
    if(check==0){
       
        if(checkMagic(n,arr)==0){
            printf("\nScore:0");
        }else{
        clock_t t2 = clock() - t;
        double time_taken = ((double)t2)/CLOCKS_PER_SEC;
        int score=change*100+time_taken;
        printf("Score:%d",score);
	
        }
        break;
    }
    
}
}

int main()
{
	game();
	int r;
	scanf("%d",r);
	return 0;
}

*/











/*
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
   */
   /*
int main(){
    char *str = "hello";
    while(*(str++))printf(str);
    return 0;
}
*/

/*
struct employee{
 char name[20];
 char post[20];
 float  salery;
   int service_time;
};
#include<stdio.h> 
#include<string.h>
int main()
{
 int empcode;
 printf("enter employee code\n");
 scanf("%d",&empcode);
 struct employee e1={"rajesh khan","maneger",42000, 8}; 
 struct employee e2={"sarad sukla","sub maneger",34000,2};
 struct employee e3={"rohal malviya","compounder",12500,4};
 switch(empcode){
 
 case (1):
            { printf("%s",e1.name);
             printf("%s",e1.post);
             printf("%.2f",e1.salery);
            printf("%d",e1.service_time);}
 
// switch(empcode)
 case (2):
 {printf("%s",e2.name);
 printf("%s",e2.post);
 printf("%.2f",e2.salery);
 printf("%d",e2.service_time);}
 break;

//empcode(empcode)
 case (3):
{printf("%s",e3.name);
 printf("%s",e3.post);
 printf("%.2f",e3.salery);
 printf("%d",e3.service_time);}
 }
 
 return 0;
}
*/

/*
int main()
{
    int n, a, b, wt, sum = 0;
    scanf("%d", &n);
    while(n--){
        scanf("%d %d", &a, &b);
        int tmp = a;
        while(tmp--){
            scanf("%d", &wt);
            sum += wt;
        }
        if(a == b || a+b == b || sum == b)
            printf("NO\n");
            else printf("YES\n");
    }
    
    return 0;
}
*/

/* 
int main(){
    int i;
    for(i = 1; i<=81; i = i*3)
    printf("%d ", i);
    return 0;
}

//function to calculate curved surface area of cylinder.

void csa_cyl(float h, float r){
    float CSA = 2*pi*r*h;
    printf("Curved surface area of given cylinder is : ");
    printf("%f", CSA);
}

//Driver code
int main(){
    float radius, height, CSA;
    radius = 5;                   //acc. to question.
    printf("Give the value of height : ");
    scanf("%f", &height);
    csa_cyl(radius, height);
    printf("\n");
    return 0;
}
*/

/*
void addmult(int, int);
int main()
{
    int i=3, j=4, m, n;
    addmult(i,j);
    addmult(i,j);
    //printf("%d %d \n",m,n);
    return 0;
}
void addmult(int a, int b){
    int k,l;
    k=a+b;
    l=a*b;
    printf("%d\t%d\n", k, l);
}
*/

/*
int printRoman(int key)
{
    int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    char rom[] = {'I','IV','V','IX','X','XL','L','XC','C','CD','D','CM','M'};
    int i=12;   
    while(key>0)
    {
      int div = key/num[i];
      key = key%num[i];
      while(div--)
      {
        printf("%c", rom[i]);
      }
      i--;
    }
}
 
int main()
{
    int key;
    printf("Give any year : ");
    scanf("%d", &key);
    printRoman(key);
    printf("\n");
    return 0;
}
*/

/*
int primefactor(int number){
    int i = 9, k[i];
    while (number>0){
        if(number%i == 0){
        k[i] = i;
        number = number
        }
        else i--;
    }
    printf("factors = %d", k[i]);
}
int main(){
    int num = 24;
    primefactor(num);
    return 0;
}
*/

/*
int main(void)
{
	int num, i, j, k;
	printf("give me a number : ");
	scanf("%d", &num);
	printf("factors of %d are as : \n", num);
	for (i = 1; i <= num; i++)
	{
		if (num % i == 0)
        for (j = 1; j <= i; j++)
        if (i % j == 0)
			printf("%d\n", j);
            else printf("%d\n", i);
            if (i||j == num)
            break;
	}
	return 0;
}
*/

/*
int main()
{
    double x = 6.0, y = 2.0;
  
    // Storing the answer in result.
    double result = pow(x, y);
    printf("%.2lf", result);
  
    return 0;
}*/

/*
void prime(int, int);
int main()
{
    prime(100, 1);
    return 0;
}
void prime(int tmp, int i){
        if(i<=tmp){
        if (tmp%i==0)
            printf("%d \n", i);
            prime(tmp, i+1);  
        //++i;
        }    
    
}
*/

/*
int main(void) {
	// your code goes here
	int t, n, j, result;
    unsigned long long fact1, fact2, fact;
	scanf("%d", &t);
	while(t--){
	scanf("%d", &n);
    fact1 = 1;
    fact2 = 1;
	for(j = 1; j<=n/2; j++){
    fact1 *= j;
    }
    for(int k = n; k>n/2; k--){
    fact2 *= k;
    }
    fact = fact1 * fact2;
	printf("%llu\n", fact); 
    }
    return 0;
}
*/

/*
int main()
{
    long int t, unit, first;
    long long int n, tmp;
    scanf("%ld", &t);
    while(t--){
        scanf("%lld", &n);
        unit = n%10;
        while (n>9){
            n/=10;
        }
        first = n;
        int sum = first + unit;
        printf("%d\n", sum);
}
    return 0;
}
*/

/*
int main(){
    int test, n;
    long long int fact;

    scanf("%d", &test);
    while (test--)
    {
        scanf("%d", &n);
        fact=1;
        for(int i=1; i<= n/2; i++){
            fact *= i*(n-i+1);
        }
        if(n%2 == 0){
            printf("%lld\n", fact);
        } else {
            printf("%lld\n", fact*(n/2 + 1));
        }
    }
    

    return 0;
}
*/

/*
int areEqual(int arr1[], int arr2[], int n)
{

    for (int i = 0; i < n; i++)
        if (arr1[i] > arr2[i])
        return 1;
      
}
 
int main()
{
    int test;
    scanf("%d", &test);
    int a[test], b[test];
    for(int i = 0; i<test; i++)
    scanf("%d", &a[i]);
    for(int j = 0; j<test; j++)
    scanf("%d", &b[j]);
 
    int x = areEqual(a, b, test);
    if(x==1)
    printf("YES\n");
    else      printf("YES\n");

    return 0;
}*/

/*
int fibbonacci(int n) {
   if(n == 0){
      return 0;
   } else if(n == 1) {
      return 1;
   } else {
      return (fibbonacci(n-1) + fibbonacci(n-2));
   }
}

int main() {
   int n = 6;
   int i;
   printf("%d", fibbonacci(n));
   return 0;
}
*/
/*
void gotoxy ( short int col, short int row ) ;
# define HLINE for ( i = 0 ; i < 79 ; i++ ) \
printf ( "%c", 196 ) ;
# define VLINE( X, Y ) { \
gotoxy ( X, Y ) ; \
printf ( "%c", 179 ) ; \
 }
int main( )
{
int i, y ;
system ( "cls" ) ;
gotoxy ( 1, 12 ) ; 
HLINE
for ( y = 1 ; y < 25 ; y++ )
VLINE ( 39, y ) ;
return 0 ;
}
void gotoxy ( short int col, short int row )
{
HANDLE hStdout = GetStdHandle ( STD_OUTPUT_HANDLE ) ;
COORD position = { col, row } ;
SetConsoleCursorPosition ( hStdout, position ) ;
}
*/
void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}
void bubblesort(int a[], int n)// best case- O(n)
{
    int c=0;
    for(int i=0;(i<n&&c!=n-i-1);i++)
    { c=0;
        for(int j=0;(j<n-i-1&&c!=n-i-1);j++)
        {
            if(a[j]>a[j+1])
            swap(&a[j],&a[j+1]);
            else
            c++;
        }
    }
}
int main(){
int a[22] = {115, 182, 873, 485, 215, 627, 79, 536, 703, 208, 903, 107, 560, 5000, 263, 883, 99, 271, 460, 727, 275, 1};
bubblesort(a, 22);
for(int i = 0; i<22; i++){
    printf("%d, ", a[i]);
}
return 0;

}

