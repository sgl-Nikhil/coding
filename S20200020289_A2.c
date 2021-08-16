//This program is written by NIKHIL KUMAR, ROLL - S20200020289
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include <time.h>


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

since for recursive function T(N) = T(N) + C[since for loo], where C is constant;
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


// complexity = O(n^2);
/*
int main()
{
    int n;
    printf("Enter the size of square matrix : ");
    scanf("%d", &n);

    float a[n][n];
    srand(time(0));
    printf("Original Matrix is-\n\n\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = rand() % 256;
            printf("%f ,", a[i][j]);
        }

        printf("\n");
    }

    float b[n - 2][n - 2];
    printf("\n\n---Convolved matrix is---\n\n");
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            b[i - 1][j - 1] = a[i - 1][j - 1] / 9 + a[i][j - 1] / 9 + a[i + 1][j - 1] / 9 + a[i - 1][j] / 9 + a[i][j] / 9 + a[i + 1][j] / 9 + a[i - 1][j + 1] / 9 + a[i][j + 1] / 9 + a[i + 1][j + 1] / 9;
            printf("%f ,", b[i - 1][j - 1]);
        }

        printf("\n");
    }

    return 0;
}
*/