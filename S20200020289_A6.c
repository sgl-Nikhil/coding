#include <stdio.h>
#include <stdlib.h>


//que - 1
//time complexity = O(n).

/*
struct Node *front = NULL;
struct Node *rear = NULL;
struct Node *front_1 = NULL;
struct Node *rear_1 = NULL;
struct Node *front_2 = NULL;
struct Node *rear_2= NULL;

struct Node
{
    int data;
    struct Node *next;
};

void enqueue(int val)
{
    struct Node *n = (struct Node *) malloc(sizeof(struct Node));
    if(n==NULL){
        printf("------OVERFLOW------");
    }
    else{
        n->data = val;
        n->next = NULL;
        if(front==NULL){
            front = n;
            rear = n;
        }
        else{
            rear->next = n;
            rear=n;
        }
    }
}

void enqueue1(int val){
    struct Node *n = (struct Node *) malloc(sizeof(struct Node));
    if(n==NULL){
        printf("------OVERFLOW------");
    }
    else{
        n->data = val;
        n->next = NULL;
        if(front_1==NULL){
            front_1 = n;
            rear_1 = n;
        }
        else{
            rear_1->next = n;
            rear_1=n;
        }
    }
}

void enqueue2(int val){
    struct Node *n = (struct Node *) malloc(sizeof(struct Node));
    if(n==NULL){
        printf("Queue is Full");
    }
    else{
        n->data = val;
        n->next = NULL;
        if(front_2==NULL){
            front_2 = n;
            rear_2 = n;
        }
        else{
            rear_2->next = n;
            rear_2=n;
        }
    }
}
void Display_org(struct Node *val){
    printf("Elements of list are : \n");
    while(val!=NULL){
    printf(" %d, ", val->data);
        val=val->next;
    }
    printf("\n");
}

void Display1(struct Node *ptr){
    printf("Printing the elements of even indices....\n");
    while (ptr != NULL)
    {
    	int val = ptr->data;
    	enqueue2(val);
    	printf("Element : %d\n", ptr->data);
        ptr = ptr->next->next;
    }
}

void Display2(struct Node *ptr){
    printf("Printing the elements of even indices....\n");
    ptr = ptr->next;
       
    
    while (ptr->next != NULL){	
    	 int val = ptr->data;
    	enqueue1(val);
        
    	 printf("Element : %d\n", ptr->data);
         ptr = ptr->next->next;
       
    }
    printf("Element : %d\n", ptr->data);
    int val = ptr->data;
    	enqueue1(val);
                  
}

int main()
{
    enqueue(13);
    enqueue(5);
    enqueue(7);
    enqueue(8);
    enqueue(1);
    enqueue(14);
    
    printf("-----------------------------------------\n");
    Display_org(front);
    printf("-----------------------------------------\n");
    Display1(front);
    printf("-----------------------------------------\n");
    Display2(front);

    return 0;
}
*/


//que - 2
//complexity - O(n).

/*
struct node {
    int data;
    struct node * next;
};

void createList(struct node **head, int n){
    int i, data;
    struct node *prev_Node, *new_Node;
    new_Node = NULL;
    prev_Node = NULL;
    
    for(i=1; i<=n; i++){
        new_Node = (struct node *) malloc(sizeof(struct node));
        printf("Enter element for %dth node : ", i);
        scanf("%d", &data);

        new_Node->data = data;
        new_Node->next = NULL;

        if (prev_Node != NULL)
            prev_Node->next = new_Node;

        prev_Node = new_Node;

        if (*head == NULL)
            *head = new_Node;
    }

    prev_Node->next = *head;

    printf("\nLIST CREATED\n");
}
void reverseList(struct node **head) {
    struct node *prev, *cur, *next, *last;

    if (*head == NULL){
        printf("Cannot be reversed [empty list.]\n");
        return;
    }

    last = *head;
    prev  = *head;
    cur   = (*head)->next;
    *head = (*head)->next;

    while (*head != last){
        *head = (*head)->next;
        cur->next = prev;
        prev = cur;
        cur  = *head;
    }
    cur->next = prev;
    *head = prev;
}

void displayList(struct node *head){
    struct node *current;
    int n = 1;
    if(head == NULL){
        printf("List is empty.\n");
        return;
    }
    current = head;
    printf("Elements of list are : \n");

    do{
        printf("%dth element = %d\n", n++, current->data);
        current = current->next;
    } while (current != head);
}

int main()
{
    int choice, n;
    struct node *head = NULL;
    while(choice != 0)
    {

        printf("\t\tCIRCULAR LINKED LIST PROGRAM\n");
        printf("--------------------------------------------------------------\n");
        printf("Press [1.] to CREATE list\n");
        printf("Press [2.] to DISPLAY list\n");
        printf("Press [3.] to REVERSE list\n");
        printf("Press [0.] to EXIT\n");
        
        printf("Enter choice accordingly : ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Number of elements in list : ");
                scanf("%d", &n);
                createList(&head, n);
                break;
            
            case 2:
                displayList(head);
                getchar(); 
                break;
            
            case 3:
                reverseList(&head);
                printf("List reversed.\n");
                getchar();
                break;

            case 0:
                printf("Exiting....\n");
                exit(0);
                break;

            default:
                printf("Error! Please choose choice either of 0/1/2/3........\n");
        }
        printf("\n");
    }
    return 0;
}
*/


//que - 3
//time complexity = O()

/*
#define MAX 10


int count=0;

struct node{
     int key;
     struct node *next;
 };

 struct node*front = NULL;
 struct node *rear = NULL;

 void enqueue(int data){
	 if(count >= MAX){
		printf("\n\t-----OVERFLOW-----\n");
		return ;
	 }

     struct node* new=(struct node*)malloc(sizeof(struct node));
     new->key = data;
     new->next = NULL;

     if(front==rear && rear==NULL){
         front = new;
         rear = new;
     }
     else{
         new->next = front;
         rear->next = new;
         rear = new;
     }
	 count++;
     printf("The value %d is inserted at node : %d\n", rear->key, count);
 }

 void dequeue(){
    struct node*ptr = front;
    if(front==rear && rear==NULL)
    printf("\n\t-----UNDERFLOW------\n");

    else if(front==rear){
        front = NULL;
        rear = NULL;
		count--;
        printf("The element %d is deleted from the queue\n",ptr->key);
        free(ptr);
    }

    else{
        front = front->next;
        rear->next = front;
		count--;
        printf("The element %d is deleted from the queue\n",ptr->key);
        free(ptr);
     }
 }

 void peek_front(){
    if(front==rear && rear==NULL) 
    printf("\nEMPTY\n");
    else{
        printf("The front element is: %d\n",front->key);
    }
 }
 
void peek_rear(){
	if(front==rear && rear==NULL)
    printf("\nEMPTY\n");
	else{
		printf("The rear element is %d\n",rear->key);
	}
}


 int main(){
    char ch;
	int n,choice;
	
	printf("The queries start from here: \n");
	printf("Query-->1: \n");
	enqueue(1);

	printf("\nQuery-->2: \n");
	enqueue(2);

	printf("\nQuery-->3: \n");
	enqueue(3);

	printf("\nQuery-->4: \n");
	peek_front();

	printf("\nQuery-->5: \n");
	dequeue();

	printf("\nQuery-->6: \n");
	dequeue();
	
    printf("\nQuery-->7: \n");
	enqueue(5);

	printf("\nQuery-->8: \n");
	peek_front();
	
    printf("\nQuery-->9: \n");
	peek_rear();
	
    printf("\nQuery-->10: \n");
	dequeue();
	
    printf("\nQuery-->11: \n");
	peek_rear();
	
	printf("\n\n\tTime Complexities are : \n");
    printf("-----------------------------------------------------");
	printf("   Enqueue---> O(1)\n");
	printf("   Dequeue---> O(1)\n");
	printf("peek_front---> O(1)\n");
	printf("peep_pop---> O(1)\n\n");
    printf("PROGRAM ENDED\n\n");
    return 0;
 }
 */