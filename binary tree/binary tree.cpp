#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
     int key;
     node *left;
     node *right;
};


struct node *getNewNode(int val)
{
    struct node *newNode = new node;
    newNode->key   = val;
    newNode->left  = NULL;
    newNode->right = NULL;

    return newNode;
}

struct node *insert(node *root, int val)
{

    if(root == NULL)
        return getNewNode(val);

    if(root->key < val)
        root->right = insert(root->right,val);

    else if(root->key > val)
        root->left = insert(root->left,val);

    return root;
}
struct node* minValueNode(node* node)
{
   struct node* current = node;

   while (current && current->left != NULL)
   current = current->left;

return current;
}


struct node* deleteNode(node* root, int key)
{
  if (root == NULL)
    return root;

   if (key < root->key)
    root->left = deleteNode(root->left, key);

    else if (key > root->key)
    root->right = deleteNode(root->right, key);

   else {
      if (root->left == NULL and root->right == NULL)
           return NULL;

    else if (root->left == NULL) {
    struct node* temp = root->right;
    delete(root);
    return temp;

    }
     else if (root->right == NULL) {
        struct node* temp = root->left;
         delete(root);
         return temp;
    }
      struct node* temp = minValueNode(root->right);
      root->key = temp->key;
      root->right = deleteNode(root->right, temp->key);
    }
        return root;
}

void inorder(node *root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->key<<endl;
    inorder(root->right);
}




void printLevelOfNode(struct node* root, int currentLevel, int num) {

   if(root == NULL) {
       return;
    }

   if(root->key == num) {
     cout<<"Level of "<<num<< " is "<< currentLevel<<endl;
    }

   printLevelOfNode(root->left, currentLevel+1, num);
   printLevelOfNode(root->right, currentLevel+1, num);
}

   struct node *getParentNode(node *Node,int val){
     if(Node==NULL){
       return NULL;
    }

   node *Parent=NULL;

   while(Node!=NULL){
     if(val<Node->key){
       Parent=Node;
       Node=Node->left;
   }
  if(val>Node->key){
     Parent=Node;
     Node=Node->right;
}
else{
   break;
}
}

return Parent;
}

int main() {
node *root=new node;


    root = insert(root,8);
    root = insert(root,3);
    root = insert(root,10);
    root = insert(root,1);
    root = insert(root,6);
    root = insert(root,4);
    root = insert(root,7);
    root = insert(root,14);
    root = insert(root,13);
    root= insert(root,11);
    deleteNode(root,11);

    printLevelOfNode(root, 0, 8);
    printLevelOfNode(root, 0, 3);
    printLevelOfNode(root, 0, 10);
    printLevelOfNode(root, 0, 1);
    printLevelOfNode(root, 0, 6);
    printLevelOfNode(root, 0, 4);
    printLevelOfNode(root, 0, 7);
    printLevelOfNode(root, 0, 14);
    printLevelOfNode(root, 0, 13);
   node *parentNode=getParentNode(root,6);
   if(parentNode!=NULL){
     cout<<"Parent:"<<parentNode->key;
   }
   else{
    cout<<"Parent is not found";
   }





return 0;
}
