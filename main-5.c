#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char data [100] ;
    struct node *left;
    struct node *right;
}node;


node *newNode (char  * word)
{
    node *n = malloc(sizeof(node));
    strcpy(n->data,word);
    n->left = NULL;
    n->right = NULL;
    return n;
}


node *insert(node *root,char *word)
{
    if (root == NULL) {
        return newNode(word);
    }
    if (strcasecmp(word,root->data)<0) {
        root->left = insert(root->left, word);
    }
    else if (strcasecmp(word,root->data)>0){
        root->right = insert(root->right, word);
    }
    return root;
}


node *search(node *root , char *key)
{
    if (root == NULL) {
        return NULL;
    }
    else if (strcasecmp(key,root->data) == 0){
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

node* FindMax(node *root)
{
    if(root==NULL)
        return NULL;
    else if(root->right!=NULL)
        return FindMax(root->right);
    else
        return root;
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


node *src(node *root, char *value)
{
    while (root!=NULL)
    {
        if (strcasecmp(value,root->data)<0) {
            if (root->left == NULL)
                return root;
            else
                root = root->left;

        }
        else if (strcasecmp(value,root->data)>0){
            if (root->right == NULL)
                return root;
            else
                root=root->right;
        }
    }
}


char *successor(node *root, char * value)
{
    char *s;
    s= malloc(100);


    node *m = search(root,value);
    if(m->right != NULL)
    {
        return FindMin(m->right);
    }
    else while (root != NULL)
    {
    if (strcasecmp(value,root->data)<0)
    {
        strcpy(s,root->data);
        strcat(s,"\0");
        root=root->left;
    }
    else
    {
        root=root->right;
    }
    }
     return s;
}
node *desuccessor(node *root, char * value)
{
    char *s;
    s= malloc(100);

    node *m = search(root,value);
    if(m->left != NULL)
    {
        return FindMax(m->left);
    }
    else while (root != NULL)
    {
    if (strcasecmp(value,root->data)>0)
    {

    strcpy(s,root->data);
        root=root->right;
    }
    else
    {
        root=root->left;
    }
    }
     return s;
}


int main(int argc, const char * argv[]) {
    char words[100];
    node *root = NULL;
    FILE *fp;
    int counts;
    fp=fopen("EN.txt","r");
       if (fp!=NULL)
    {
        printf("Dictionary Loaded Successfully ... ! \n..........................................................................\n");
        while (!feof(fp))
        {
            fscanf(fp,"%[^\n]\n",words);
            root = insert(root , words);
            counts++;
        }
    }
    else
        printf("File is empty\n");
    fclose(fp);

    int x = count(root);
    printf("Size  =    %d\n..........................................................................\n",x);
    int z = height(root);
    printf("Height  =  %d\n..........................................................................\n",z);
    printf("Enter a sentence : \n");
    char sentence[250];
    gets(sentence);
    char s[2];
    strcpy(s," ");
    char *token = strtok(sentence," ");

    while (token!=NULL){
    node *m = search(root, token);
    if (m == NULL) {
        printf("%s   - Incorrect, ",token);
        printf("Suggestions : %s ", src( root , token)->data);
        char z[100] ;
        strcpy(z,src( root , token)->data);
        printf( " %s " , successor(root , z));
        printf( " %s \n" , desuccessor(root,z));
    }
    else
        printf("%s Correct\n",token);

        token = strtok(NULL," ");

    }
    return 0;
}
