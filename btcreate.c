 #include<stdio.h>
 #include<stdlib.h>
 typedef struct node
 {
    int data;
    struct node * left;
    struct node *right;
 }node;
// void create1(node **root, char name[50], int data)
// {

//     int choice;

//     (*root) = (node *)malloc(sizeof(node));
//     if (data == -123)
//     {
//         printf("Enter the data for the %s node or root node of the tree:\n", name);
//         // (*root)->parent=NULL;
//     }
//     else
//         printf("Enter the data for the %s node of %d: \n", name, data);
//     scanf("%d", &(*root)->data);
//     printf("Does %d have a left node? (1 for Yes and 0 for No)\n", (*root)->data);
//     scanf("%d", &choice);
//     if (choice == 0)
//         (*root)->left = NULL;
//     else if (choice == 1)
//     {
//         // (*root)->left = (node *)malloc(sizeof(node));
//         // (*root)->left->parent = *root;
//         create1(&((*root)->left), "left", (*root)->data);
//     }
//     printf("Does %d have a right node? (1 for Yes and 0 for No)\n", (*root)->data);
//     scanf("%d", &choice);
//     if (choice == 0)
//         (*root)->right = NULL;
//     else if (choice == 1)
//     {
//         // (*root)->right = (node *)malloc(sizeof(node));
//         // (*root)->right->parent = *root;
//         create1(&((*root)->right), "right", (*root)->data);
//     }
// }
 void inorder(node * btree)
{
   node * current=btree;
   if(btree==NULL)
   return;
   inorder(current->left);
   printf("%d",current->data);
   inorder(current->right);


}
 void postorder(node * btree)
{
   node * current=btree;
   if(btree==NULL)
   return;
   postorder(current->right);
   postorder(current->left);
   printf("%d",current->data);


}
 void preorder(node * btree)
{
   node * current=btree;
   if(btree==NULL)
   return;
   printf("%d",current->data);
   preorder(current->left);
   preorder(current->right);


}
void createtree(node *root)
{
node* ptr=NULL;
    printf("Enter data for left of %d\n",root->data);
    ptr=(node *)malloc(sizeof(node));
    scanf("%d",&ptr->data);
    if(ptr->data!=-1) {root->left=ptr; createtree(ptr);}
    else root->left=NULL;
    printf("Enter data for right of %d\n",root->data);
    ptr=(node *)malloc(sizeof(node));
    scanf("%d",&ptr->data);
    if(ptr->data!=-1) {root->right=ptr; createtree(ptr);}
    else root->right=NULL;
}
node * copybtree(node * root)
{
   if(root!=NULL)
   {node *ptr=(node *)malloc(sizeof(node));
   ptr->data=root->data;
   ptr->left=copybtree(root->left);
   ptr->right=copybtree(root->right);
   return ptr;
   }
   else return NULL;

}
node * mirror(node * root)
{
    if(root!=NULL)
   {node *ptr=(node *)malloc(sizeof(node));
   ptr->data=root->data;
   ptr->right=mirror(root->left);
   ptr->left=mirror(root->right);
   return ptr;
   }
   else return NULL;
   
}
int check_equal(node * root,node * root1)
{
   if(root==NULL && root1==NULL)
   return 1;
   if(root==NULL && root1!=NULL)
   return 0;
   if(root1==NULL && root!=NULL)
   return 0;
   if(root->data==root1->data)
   {
     int a=check_equal(root->left,root1->left);
      if(a==0)
      return a;
      a=check_equal(root->right,root1->right);
      if(a==0)
      return a;
      return 1;if(root==NULL && root1!=NULL)
   return 0;

   }
   else
   {
      return 0;
   }
}
int check_bst(node *root)
{
    if (root == NULL)
        return 1;

    if (root->left != NULL && root->data < root->left->data)
        return 0;

    if (root->right != NULL && root->data > root->right->data)
        return 0;

    int left_bst = check_bst(root->left);
    if (!left_bst)
        return 0;

    int right_bst = check_bst(root->right);
    if (!right_bst)
        return 0;

    return 1;
}\
 int main()
 {
    node * root;
    node * mirror1;
    node *copy;
    printf("enter root data\n");
    scanf("%d",&root->data);
    createtree(root);
   int a=check_bst(root);
   printf("%d",a);
   
  


    
 }