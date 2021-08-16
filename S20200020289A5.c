//NIKHIL KUMAR; ROLL - S20200002289.

#include <stdio.h>
#include <stdlib.h>

// que = 1
// time complexity : O(n)

/*
#define QUEUE_EMPTY_MAGIC 0xdeadbeef
#define MAX 100

typedef struct _queue_s {
    int *arr;
    int rear, front, count, max;
} queue_s;
 
queue_s *queue_allocate(int n);
void toInsert(queue_s * q, int v);
int toDelete(queue_s * q);
int toCount(queue_s * q);
int isEmpty(queue_s * q);

void stack_push(queue_s * q, int v) {
    toInsert(q, v);
}
 
int stack_pop(queue_s * q) {
    int i, n = toCount(q);
    int removed_element;
 
    for (i = 0; i < (n - 1); i++) {
        removed_element = toDelete(q);
        toInsert(q, removed_element);
    }
    removed_element = toDelete(q);
 
    return removed_element;
}
 
int stack_empty(queue_s * q) {
    return isEmpty(q);
}
 
int stack_count(queue_s * q) {
    return toCount(q);
}

int toCount(queue_s * q) {
    return q->count;
}
 
queue_s *
queue_allocate(int n) {
    queue_s *queue;
 
    queue = malloc(sizeof(queue_s));
    if (queue == NULL)
        return NULL;
    queue->max = n;
 
    queue->arr = malloc(sizeof(int) * n);
    queue->rear = n - 1;
    queue->front = n - 1;
 
    return queue;
}
 
void toInsert(queue_s * q, int v) {
    if (q->count == q->max)
        return;
 
    q->rear = (q->rear + 1) % q->max;
    q->arr[q->rear] = v;
    q->count++;
}
 
int toDelete(queue_s * q) {
    int x;
    if (q->count == 0)
        return QUEUE_EMPTY_MAGIC;
 
    q->front = (q->front + 1) % q->max;
    x = q->arr[q->front];
    q->count--;
 
    return x;
}
 
int isEmpty(queue_s * q) {
    return (q->count == 0);
}


void queue_display(queue_s * q) {
    int i = (q->front + 1) % q->max, a = toCount(q);
 
    while (a--) {
        printf("[%d], ", q->arr[i]);
        i = (i >= q->max) ? 0 : (i + 1);
    }
}
 

int main(void) {
    queue_s *q;
    int x, option;
    q = queue_allocate(MAX);
 
    do {
        printf("\n\t(1.) Push\t(2.) Pop\t(0.) Exit\n");
        printf("Choice: ");
        scanf(" %d", &option);
 
        switch (option) {
        case 1:
            printf("\nEnter value to Push:");
            scanf(" %d", &x);
    
            stack_push(q, x);
 
            printf("\n\n------\tCurrent Queue is :\n");
 
            queue_display(q);
            printf("\n\nPushed Value: %d", x);
 
            printf("\n------------\n");
            break;
 
        case 2:

            x = stack_pop(q);
 
            printf("\n\n------\tCurrent Queue is :\n");
 
            queue_display(q);
            if (x == QUEUE_EMPTY_MAGIC)
                printf("\n\nNo values removed..");
            else
                printf("\n\nPopped Value is : %d", x);
 
            printf("\n------------\n");
            break;
 
        case 0:
            printf("\n\t-----Quitting.----\n");
            return 0;
 
        default:
            printf("\n\t-----Quitting.----\n");
            return 0;
        }
    } while (1);
 
    return 0;
}
*/


//QUE - 2
// time complexity : O(1)
/*
#define SIZE 16
 
int A[SIZE];
int top = -1;
int rear = SIZE;
 
void push1(int data)
{
  if(top < rear - 1)
  {
    A[++top] = data;
  }
  else
  {
    printf("\tStack overflowed....\n");
  }
}

void push2(int data)
{
  if(top < rear - 1)
  {
    A[--rear] = data; 
  }
  else
  {
    printf ("\tStack overflowed....\n");
  }
}

void pop1()
{
  if(top >= 0)
  {
    int x = A[top--];
    printf("%d is popped from Stack 1\n", x);
  }
  else
    printf("Stack is underflow/Empty...\n");
  
}
void pop2 ()
{
  if(rear < SIZE)
  {
    int x = A[rear++];
    printf("%d is popped from Stack 2\n", x);
  }
  else
    printf("Stack is underflow/Empty...\n");
}

void display1(){
  
  for(int i = top; i >= 0; --i)
    printf("%d ", A[i]);
  printf("\n");
}
void display2(){
  
  for(int i = rear;i < SIZE;++i)
    printf("%d ", A[i]);
  printf("\n");
}
 
int main(){
  int A[SIZE], total;

  printf("\t16 values can be pushed here.......\n");
 
  for(int i=1;i<=8;++i){
  	
    push1(i);
    printf("Value Pushed in Stack 1 is %d\n", i);
  }
    printf("\n");
  for (int i=1;i<=8;++i){
    push2(i);
    printf("Value Pushed in Stack 2 is %d\n", i);
  }
    printf("\n\t\t");

  display1();
  printf("\t\t");

  display2();
    printf("\n\n");
 
  return 0;
}
*/

// que = 3
// time complexity : O(n^2)

/*
#define nq 10
#define ns 10

int stack[ns];
int queue [nq];
int fr=-1;
int re=-1;
int top=-1;


void enqueue(int x)
{
    if(re==nq-1)
        printf("warning:overflow");
    else if(fr==-1&&re==-1)
      {
         fr=0;
         re=0;
         queue[re]=x;
      }
    else
        {
           re++;
        queue[re]=x;
        }
}

void dequeue()
{
    if(fr==-1&&re==-1)
        printf("warning:underflow");
    else if(fr==re)
        {
         fr=-1;
         re=-1;
        }
    else
        {
         fr++;
        }
}

int peek_q()
{
    if(fr==-1&&re==-1)
       return 1000;

    else
        {
        int tmp= queue[fr];
         return tmp;
        }
}




void push(int x)
{
     if(top==ns-1)
        printf("warning:overflow");

        else
        {
          top++;
          stack[top]=x;
        }
}

void pop()
{
    if(top==-1)
        printf("warning:overflow");

        else
        {
          top--;
        }
}
int peek_s()
{
    if(top==-1)
        return 1000;
    else
    {
      int val=stack[top];
      top--;
      return val;
    }

}


int main()
{
   int arr[10],A,B;
  for(int i=0;i<10;i++)
  {
      arr[i]=rand()%(100);
      push(arr[i]);
      enqueue(arr[i]);
      printf("%d\t",arr[i]);
  }

  while(A!=1000||B!=1000)
    {
       A=peek_q();
       B=peek_s();

       if(A>B)
       {
           printf(" 1 \n");
           pop();

       }
    else if(B>A)
      {
        printf(" 2 \n");
        dequeue();

      }
    else if(A==B&&A!=1000)
    {
         printf(" 0 \n");
    }

   }

}
*/