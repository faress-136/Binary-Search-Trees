#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char data[100];
    struct node *left;
    struct node *right;
}node;


//node *newNode (int value)
//{
//    node *n = malloc(sizeof(node));
//    n->data = value;
//    n->left = NULL;
//    n->right = NULL;
//    return n;
//}
//

//node *insert(node *node,int key)
//{
//    if (node == NULL) {
//        return newNode(key);
//    }
//    if (key < node ->data) {
//        node->left = insert(node->left, key);
//    }
//    else if (key > node->data){
//        node->right = insert(node->right, key);
//    }
//    return node;
//}

node *newNodeChar (char *word)
{
    node *n = malloc(sizeof(node));
    strcpy(n->data, word);
    n->left=NULL;
    n->right=NULL;
    return n;
}


node *insertCh(node *root, char *word)
{
    if (root == NULL) {
        return newNodeChar(word);
    }
    else{
        if(strcasecmp(word, root->data)<0){
            root->left=insertCh(root->left, word);
        }
        else if(strcasecmp(word, root->data)>0){
            root->right=insertCh(root->right, word);
        }
    }
    return root;
}

node *search(node *root , char *key)
{
    if (root==NULL) {
        printf("incorrect\n");
        return NULL;
    }
    else if (strcasecmp(key,root->data)==0){
        printf("correct\n");
        return root;
    }
    else if (strcasecmp(key,root->data)<0){
        return search(root->left, key);
    }
    else
        return search(root->right, key);
}


int count(node *root)
{
    if (root==NULL) {
        return 0;
    }
    else
        return 1+count(root->left)+count(root->right);
}


int max(int a, int b)
{
    return a>b?a:b;

}


node *FindMin(node *root)
{
    if (root==NULL) {
        return NULL;
    }
    else if (root->left != NULL){
        return FindMin(root->left);
    }
    else
        return root;
}
int height(node *root)
{
    if (root ==NULL) {
        return -1;
    }
    else
        return 1+max(height(root->left), height(root->right));
}


//node *src(node *root, int value)
//{
//    while (root!=NULL)
//    {
//        if (value<root->data) {
//            if (root->left == NULL)
//                return root;
//            else
//                root = root->left;
//
//        }
//        else if (value>root->data){
//            if (root->right == NULL)
//                return root;
//            else
//                return root=root->right;
//
//        }
//    }
//    return -1;
//}


//node *successor(node *root, int value)
//{
//    int *s = NULL;
////    node *found=root;
////    search(root, value);
////    found->data=value;
////    if (found->right != NULL) {
////        return FindMin(found);
////    }
//
//    while (root!=NULL) {
//    if (value<root->data) {
//        s=root->data;
//        root=root->left;
//    }
//    else if (value>=root->data){
//        root=root->right;
//    }
//    else break;
//    }
//    printf("%d\n",s);
//    return NULL;
//}

int main(int argc, const char * argv[]) {
    char words[100];
    node *root = NULL;
    FILE *fp;
//    int counts = 0;
    fp=fopen("/Users/faresmohamed/Desktop/BST/BST.txt","r");
    if (fp!=NULL)
    {
        while (!feof(fp))
        {
            fscanf(fp,"%[^\n]\n",words);
            root = insertCh(root, words);
//            counts++;
        }
    }
    else
        printf("File is empty\n");
    fclose(fp);
    printf("Dictionary Loaded Successfully\n........................\n");
    printf("%s",root->data);
        node *right = root->right;
        node *left = root->left;
        printf("%s\n",right->data);
        printf("%s\n........................\n",left->data);
//    char wordd[20];
//    gets(wordd);
//    node *m = search(root, wordd);
//    if (m == NULL) {
//        printf("incorrect\n");
//    }
//    else
//        printf("correct\n");
        int x = count(root);
    printf("Size = %d\n........................\n",x);
        int z = height(root);
        printf("Height = %d\n........................\n",z);
    
    
    
    
//    root = insert(root, 8);
//    root = insert(root, 6);
//    root = insert(root, 2);
//    root = insert(root, 4);
//    root = insert(root, 16);
//    root = insert(root, 15);
//    root = insert(root, 14);
//    root = insert(root, 13);
//    root = insert(root, 20);
//    root = insert(root, 19);
//    root = insert(root, 21);
//
//    printf("%s \n",root->data);
//    node *right = root->right;
//    node *left = root->left;
//    printf("%s\n",right->data);
//    printf("%s\n",left->data);
//    search(root, 13);
//    int x = count(root);
//    printf("%d\n",x);
//    int z = height(root);
//    printf("%d\n",z);
//    successor(root,13);

    return 0;
}
