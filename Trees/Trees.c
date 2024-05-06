#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *right, *left, *parent;
};

struct node *createnode(int val) {
  struct node *new = (struct node *)malloc(sizeof(struct node));
  new->data = val;
  new->right = NULL;
  new->left = NULL;
  return new;
}

struct node* insert(struct node *root, int val) {
    if (root == NULL) {
        struct node *newNode = createnode(val);
        return newNode;
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
        if (root->left != NULL) {
            root->left->parent = root; // Set parent pointer for the left child
        }
    } else {
        root->right = insert(root->right, val);
        if (root->right != NULL) {
            root->right->parent = root; // Set parent pointer for the right child
        }
    }

    return root;
}

void inorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
}

void preorder (struct node *root)
{
    if(root==NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder (struct node *root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
struct node *searchR(struct node *root, int item)   //searching for a node using recursion
{
        if (root == NULL || root->data == item)
        return root;

    struct node *left_result = searchR(root->left, item);
    if (left_result != NULL)
        return left_result;

    return searchR(root->right, item);
}

struct node *deleteByVal(struct node *root, int val) {
    if (root == NULL) {     //empty tree
        printf("Empty tree\n");
        return NULL;
        }
    struct node *current = root;//current to traverse the tree, prev to keep track of the parent node of current,
    struct node *prev = NULL, *q, *suc; // q to store the node that will replace the deleted node, and suc to keep track of the successor node (used when the node to delete has two children).

    while (current != NULL)     //This while loop is to traverse till the val to be deleted
    {
            if (val == current->data)   //when val found, breaks out
                break;
            prev = current;
            if (val < current->data)
                current = current->left;
            else
                current = current->right;
    }

    if (current == NULL) {
        printf("Element not found\n");
        return root;
  }
  if (current->left == NULL)    //this is to determine which node is q. CASE 1: when one/no children if no left child, q is right child
        q = current->right;
  if (current->right == NULL)   //if no right child, q is left child
        q = current->left;
  else                          //CASE 2: Both children there
    {
        q = suc = current->right;
        while (suc->left != NULL)
            {suc = suc->left;}        //finding the leftmost child
        suc->left = current->left;  //joining current to the leftmost child
    }
  if (prev == NULL) {   //when node to be deleted is root, prev=NULL. So, q is the new root.
    free(current);
    return q;
  }
  if (current == prev->left)    //If current was the left child of prev, prev->left is updated to point to q and vice versa
    prev->left = q;
  else
    prev->right = q;

  free(current);    //delete the node finally
  return root;
}
int countNodes(struct node *root)
{
    if(root==NULL)
        return 0;
    else
        return 1+countNodes(root->left)+countNodes(root->right);
}

struct node *max(struct node *root)
{
    struct node *current;
    if(root==NULL)
        return root;
    current=root;
    while(current->right != NULL)
        current=current->right;

    printf("\n%d ", current->data);
    return current;
}

int maximum(int a, int b)       //Important to define this function before height so that height function can use this code.
{
    if(a>b)
        return a;
    else
        return b;
}

int height (struct node *root)
{
    if(root==NULL)
        return 0;  //height of empty tree is -1(base case)
    int left_height = height(root->left);
    int right_height = height(root->right);

    return 1 + maximum(left_height, right_height);
}

int main()
{
    struct node *root = (struct node *)malloc(sizeof(struct node));
    int val, choice,count,H;
    struct node *answer,*M;
    printf("Enter the root element: ");
    scanf("%d", &val);
    root->data = val;
    root->right = NULL;
    root->left = NULL;
    do
    {
        printf("\n0. Exit.\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal.\n");
        printf("3. Post order Traversal.\n");
        printf("4. Pre order Traversal\n");
        printf("5. Search for a node.\n");
        printf("6. Delete node.\n");
        printf("7. Count nodes.\n");
        printf("8. Find maximum node.\n");
        printf("9. Height of the tree.\n");

        printf("\nCHOOSE.\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            printf("Enter value to insert: ");
            scanf("%d", &val);
            root = insert(root, val);
            break;
            case 2:
                printf("In-order traversal of the binary tree: ");
                inorder(root);
                break;
            case 3:
                printf("Post-order traversal of the binary tree: ");
                postorder(root);
                break;
            case 4:
                printf("Pre-order traversal of the binary tree: ");
                preorder(root);
                break;
            case 5:
            printf("Enter the element to be searched: ");
            scanf("%d", &val);
            answer = searchR(root, val);
            if (answer != NULL) {
                printf("The key %d is found.\n", val);
                    if (answer != root)
                        printf("The parent of %d is %d.\n", val, answer->parent->data);
                    else
                        printf("The key %d is the root (%d).\n", val, root->data);
                    }
           else
                printf("Key %d not found.\n", val);
           break;
            case 6:
                printf("Enter the key to delete: ");
                scanf("%d", &val);
                root = deleteByVal(root, val);
                break;
            case 7:
                count=countNodes(root);
                printf("The total nodes are %d.\n", count);
                break;
            case 8:
                M=max(root);
                if(M!=NULL)
                {
                    printf("\nThe node with maximum data is %d.\n", M->data);
                    if(M!=root)
                        printf("The parent of the maximum node is %d.\n", M->parent->data);
                    else
                        printf("The maximum node is the root. (%d)\n", root->data);
                }
                else
                    printf("Empty Tree.\n");
                break;
            case 9:
                H=height(root);
                if(H==0)
                    printf("Empty Tree has height -1.");
                else
                    printf("The height of the tree is %d.\n", H);
                break;

            case 0:
                break;
        }
    }while(choice!=0);
return 0;
}

