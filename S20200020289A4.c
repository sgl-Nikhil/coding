#include <stdio.h>
#include <stdlib.h>

// que 1---------------------------------------------------------------------------------------------------------------------------


struct node
{
    int data;
    struct node *next;
};

display(struct node *head)
{
    if(head == NULL)
    {
        printf("NULL\n");
    }
    else
    {
        printf("%d ", head -> data);
        display(head->next);
    }
}

void concat(struct node *x,struct node *y)
{
    if( x != NULL && y!= NULL )
    {
        if (x->next == NULL)
            x->next = y;
        else
            concat(x->next,y);
    }
    else
    {
        printf("Any of the 'x' or 'y' is NULL.\n");
    }
}


int main()
{

    struct node *prev,*x, *y, *z;
    int n,i;
    printf ("Total number of elements in x : ");
    scanf("%d",&n);
    x=NULL;
    for(i=0;i<n;i++)
    {
        z=malloc(sizeof(struct node));
        scanf("%d",&z->data);
        z->next=NULL;
        if (x==NULL)
            x = z;
        else
            prev->next=z;
        prev=z;
    }
    printf ("Total number of elements in y :");
    scanf("%d",&n);
    y=NULL;
    for(i=0;i<n;i++)
    {
        z=malloc(sizeof(struct node));
        scanf("%d",&z->data);
        z->next=NULL;
        if (y==NULL)
            y = z;
        else
            prev->next = z;
        prev = z;
    }
    concat(x, y);

    printf("\n\tAfter concatenating both lists : ");
    display (x);

    return 0;
}




// que - 2 ---------------------------------------------------------------------------------------------------------------------------


struct Node { 
    int data; 
    struct Node* next; 
}; 

void sortedInsert(struct Node** head_refer, struct Node* new_node) 
{ 
    struct Node* current; 
    if (*head_refer == NULL || (*head_refer)->data >= new_node->data) { 
        new_node->next = *head_refer; 
        *head_refer = new_node; 
    } 
    else { 
        current = *head_refer; 
        while (current->next != NULL && current->next->data < new_node->data) { 

            current = current->next; 

        } 

        new_node->next = current->next; 
        current->next = new_node; 
    } 
} 

struct Node* newNode(int new_data) 
{ 
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
    new_node->data = new_data; 
    new_node->next = NULL; 
    return new_node; 
} 

void printList(struct Node* head) 
{ 

    struct Node* temp = head; 

    while (temp != NULL) { 
        printf("%d  ", temp->data); 
        temp = temp->next; 
    } 
} 

int main() 
{ 

    struct Node* head = NULL; 

    struct Node* new_node = newNode(10); 
    sortedInsert(&head, new_node); 
    new_node = newNode(20); 
    sortedInsert(&head, new_node); 
    new_node = newNode(30); 
    sortedInsert(&head, new_node); 
    new_node = newNode(50); 
    sortedInsert(&head, new_node); 
    new_node = newNode(40); 
    sortedInsert(&head, new_node); 

    printf("\nCreated Linked List\n"); 
    printList(head); 
    printf("\n");
    return 0; 
}


// que - 3--------------------------------------------------------------------------------------------------------------------------------


struct node
{
    int data;
    struct node *link;
};
 
struct node *insert(struct node *x, int n)
{
    struct node *temp;
    if (x == NULL)
    {
        x = (struct node* ) malloc(sizeof(struct node)); 
        if (x == NULL)
        {
            printf("Error\n");
            exit(0);
        }
        x->data = n;
        x->link = x; 
    }
    else
    {
        temp = x;
        
        while (temp->link != x)
            temp = temp->link;
        temp->link = (struct node* ) malloc(sizeof(struct node));
        if (temp->link == NULL)
        {
            printf("Error\n");
            exit(0);
        }
        temp = temp->link;
        temp->data = n;
        temp->link = x;
    }
    return (x);
}
void printlist(struct node *p)
{
    struct node *temp;
    temp = p;
    printf("the data values in list : \n");
    if (p != NULL)
    {
        do
        {
            printf("%d\t", temp->data);
            temp = temp->link;
        } while (temp != p);
    }
    else
        printf("The list is empty\n");
}
struct node *merge(struct node *p, struct node *q)
{
    struct node *temp = NULL;
    struct node *r = NULL;
    r = p;
    temp = p;
    while (temp->link != p)
        temp = temp->link;
    temp->link = q;
    temp = q;
    while (temp->link != q)
        temp = temp->link;
    temp->link = r;
    return (r);
}
 
int main()
{
    int n;
    int x;
    struct node *begin1 = NULL;
    struct node *begin2 = NULL;
    struct node *begin3 = NULL;
 
    
    printf("Enter the number of nodes in the first list \n");
    scanf("%d", &n);
    while (n-- > 0)
    {
        
        scanf("%d", &x);
        begin1 = insert(begin1, x);
    }
    printf("The first list is\n");
    printlist(begin1);
 
    printf("\n\nEnter the number of nodes in the second list \n");
    scanf("%d", &n);
    while (n-- > 0)
    {
    
        scanf("%d", &x);
        begin2 = insert(begin2, x);
    }
    printf("The second list is:\n");
    printlist(begin2);
 
    begin3 = merge(begin1, begin2);
    printf("\n\nafter merging ");
    printlist(begin3);
    getchar();
    printf("\n");
    return 0;
}


// que - 4------------------------------------------------------------------------------------------------------------------
// complexity = O(n);


struct node
{

  int data;
  struct node *next;
  struct node *prev;    
};

void push(struct node** head_refer, int new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->prev = NULL;
    new_node->next = (*head_refer);    
 
    if((*head_refer) !=  NULL)
      (*head_refer)->prev = new_node ;    

  
    (*head_refer) = new_node;
}
 

void printList(struct node *node)
{

  while(node!=NULL){
   printf("%d ", node->data);
   node = node->next;
  }

} 
 
int main()
{

  struct node* head = NULL;

  struct node *prev,*x, *z;
    int n,i;
    printf ("Total number of elements in x : ");
    scanf("%d",&n);
    x=NULL;
    for(i=0;i<n;i++)
    {
        z=malloc(sizeof(struct node));
        scanf("%d",&z->data);
        push(&head, z->data);
        z->next=NULL;
        if (x==NULL)
            x = z;
        else
            prev->next=z;
        prev=z;
    }

  printf("\n\t Reversed Linked list : ");
  printList(head);
  getchar();

  printf("\n");
}



// que - 5


struct Node {
    int coeff;
    int pow;
    struct Node* next;
};

void for_node(int x, int y, struct Node** temp)
{
    struct Node *a, *b;
    b = *temp;
    if (b == NULL) {
        a = (struct Node*)malloc(sizeof(struct Node));
        a->coeff = x;
        a->pow = y;
        *temp = a;
        a->next = (struct Node*)malloc(sizeof(struct Node));
        a = a->next;
        a->next = NULL;
    }
    else {
        a->coeff = x;
        a->pow = y;
        a->next = (struct Node*)malloc(sizeof(struct Node));
        a = a->next;
        a->next = NULL;
    }
}

void view(struct Node* node)
{
    while (node->next != NULL) {
        printf("%dx^%d", node->coeff, node->pow);
        node = node->next;
        if (node->coeff >= 0) {
            if (node->next != NULL)
                printf("+");
        }
    }
}

int main()
{

    struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL;

    //3x^2 + 1x^1 + 2x^0

    for_node(3, 2, &poly1);
    for_node(1, 1, &poly1);
    for_node(2, 0, &poly1);
 
    //6x^1 - 5x^0

    for_node(6, 1, &poly2);
    for_node(-5, 0, &poly2);

    printf("1st polynomial : ");
    view(poly1);
    printf("\n2nd polynomial : ");
    view(poly2);
    printf("\n");
    return 0;
}

