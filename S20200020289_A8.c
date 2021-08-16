//This program is written by NIKHIL KUMAR, ROLL - S20200020289

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

struct BST_node{
    int data;
    struct BST_node* lchild;
    struct BST_node* rchild;
};

struct BST_node* create(int val){
	struct BST_node * tmp = malloc(sizeof(struct BST_node));
	
	tmp->data = val;
	tmp->lchild = NULL;
	tmp->rchild = NULL;	
	
	return tmp;
}

struct BST_node* insert(struct BST_node *root, int val){
	if(root == NULL)
		return create(val);

	if(root->data > val)
		root->lchild = insert(root->lchild,val);
	else if(root->data < val)
		root->rchild =   insert(root->rchild,val);

	return root;
}

struct BST_node* construct_BST(int A[], int n, struct BST_node *root){
	for(int i=0;i<n;i++){
	int val = A[i];
	root = insert(root,val);
	}
	return root;
}

void inorder(struct BST_node *root){
    if (root != NULL){
        inorder(root->lchild);
        printf("%d ", root->data);
        inorder(root->rchild);
    }
}

//2

struct BST_node* new_node(int data){
    struct BST_node* tmp = (struct BST_node*)malloc(sizeof(struct BST_node));
    tmp->data = data;
    tmp->lchild = tmp->rchild = NULL;
    return tmp;
}

struct BST_node* smallest_node(struct BST_node* Node){

    struct BST_node* current = Node;
    while (current && current->lchild != NULL)
        current = current->lchild;
    return current;
}

struct BST_node* delete_BST(struct BST_node* root, int data){
    if (root == NULL)
        return root;
 
    if (data < root->data)
        root->lchild = delete_BST(root->lchild, data);
    else if (data > root->data)
        root->rchild = delete_BST(root->rchild, data);
    else {
        if (root->lchild == NULL){
            struct BST_node* tmp1 = root->rchild;
            free(root);
            return tmp1;
        }
        else if (root->rchild == NULL) {
            struct BST_node* tmp2 = root->lchild;
            free(root);
            return tmp2;
        }

        struct BST_node* tmp3 = smallest_node(root->rchild);
        root->data = tmp3->data;
        root->rchild = delete_BST(root->rchild, tmp3->data);
    }

    return root;
}

//3
int BST_height(struct BST_node* root){
    if (root == NULL)
        return 0;
    else {
        int l_ht = BST_height(root->lchild);
        int r_ht = BST_height(root->rchild);
        if (l_ht > r_ht)
            return (l_ht + 1);
        else
            return (r_ht + 1);
    }
}

int main()
{

//que - 1----------------------------------------------------------------------------------------------------------------------------------------

/*
    int n;
    int Arr[] = {1,4,3,7,2,8,9,6,10,6};
    struct BST_node* root = NULL ;	

	n = sizeof(Arr)/sizeof(Arr[0]);			
	root = construct_BST(Arr, n, root);
	inorder(root);
*/

//que - 2----------------------------------------------------------------------------------------------------------------------------------------

/*
    struct BST_node* root = NULL;
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 3);
    root = insert(root, 13);
    root = insert(root, 5);
    root = insert(root, 7);
    
 
    printf("Inorder traversal of original tree : \n\t");
    inorder(root);
 
    printf("\n\nDeleting 3 : \n");
    printf("----------------\n");
    root = delete_BST(root, 3);
    printf("Inorder traversal of newly modified tree \n\t");
    inorder(root);
 
    printf("\n\nDeleting 1\n");
    printf("----------------\n");
    root = delete_BST(root, 1);
    printf("Inorder traversal of the modified tree \n\t");
    inorder(root);
*/


// que - 3----------------------------------------------------------------------------------------------------------------------------------------
    
/*
    struct BST_node* root = new_node(1);
    root->lchild = new_node(2);
    root->rchild = new_node(3);
    root->lchild->lchild = new_node(4);
    root->lchild->rchild = new_node(5);
    root->lchild->lchild->lchild = new_node(4);
    root->lchild->rchild->rchild = new_node(5);

    printf("\nHeight of above tree is : ");
    int x = BST_height(root);
    printf("%d\n", x);
*/


    printf("\n");
    return 0;
}