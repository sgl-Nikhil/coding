#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define pi 3.14


//que - 1


/*int isEven(int k)
{
    if (k % 2 == 0)
    {
        return 0;
    }
    return 1;
}

int isOdd(int k)
{
    if (k % 2 == 0)
    {
        return 0;
    }
    return 1;
}

int findandprint(int a[10][10], int m, int n)
{
    int t = 0, b = 0, r = 0, l = 0;
    if (a[m][n + 1] % 2 == 0)
    {
        if (a[m + 1][n + 2] % 2 != 0)
        {
            if (a[m + 2][n + 1] == a[m][n + 1] + a[m + 1][n + 2])
            {
                if (a[m + 1][n] == a[m + 2][n + 1] + a[m + 1][n + 2])
                {
                    for (int k = m; k < m + 3; k++)
                    {
                        for (int l = n; l < n + 3; l++)
                        {
                            printf("%d ", a[k][l]);
                        }
                        printf("\n");
                    }
                    t = a[m][n + 1];
                    r = a[m][n + 1];
                    b = a[m + 2][n + 1];
                    l = a[m + 1][n];
                    printf("\n");
                    printf("Top: %d\n", a[m][n + 1]);
                    printf("Right: %d\n", a[m][n + 1]);
                    printf("Bottom: %d\n", a[m + 2][n + 1]);
                    printf("Left: %d\n", a[m + 1][n]);
                    printf("\n");
                    printf("\n");
                }
            }
        }
    }
    return (t + b + l + r);
}

int main()
{

    srand(time(0));

    int A[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            A[i][j] = 10 + rand() % 100;
        }
    }
    int B[10][10];
    int C[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            B[i][j] = isEven(A[i][j]);
            C[i][j] = isOdd(A[i][j]);
        }
    }

    printf("\n");

    printf("even numbers \n");
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    printf("odd numbers \n");
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("Return value of function (l+b+r+t): %d\n", findandprint(A, i, j));
        }
    }
}*/








//que - 2
struct circle{
	float x,y,radius,area;
};
typedef struct circle CIRCLE;

CIRCLE *genCircles(int n){
	CIRCLE cir[n],*ptr=cir;
	for (int i=0;i<n;i++){
		(ptr+i)->x=rand()%13+8.0;
		(ptr+i)->y=rand()%13+8.0;
		(ptr+i)->radius=rand()%5+2.0;
	}
	return *ptr;
}

void findArea(CIRCLE *c,int n){
	for(int i=0;i<n;i++){
	float area=(3.14*((c+i)->radius)*((c+i)->radius));
		printf("The area of %dth circle is: %f\n",i,area);
	}
}

void printCircles(CIRCLE *c,int n){
	if(n==20) return;
	printf("for %dth circle:\n",n+1);
	printf("center(%.1f,%.1f\n",(c+n)->x,(c+n)->y);
	printf("radius = %f\n",(c+n)->radius);
	printf("area = %f\n",(3.14*((c+n)->radius)*((c+n)->radius));
	printCircles(c,n+1);
}

int main(){
    int *ptr;
srand(time(0));
	genCircles(2);
	for(int i=0;i<2;i++) printf("%f",(ptr+i)->radius);
	return 0;
}