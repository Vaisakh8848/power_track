#include "main.h"

/* Function to insert the data's in BST */
int insert_into_BST(Tree_t **root,int data)
{
    Tree_t *new = malloc(sizeof(Tree_t)); //create new node
    if(new == NULL)
    {
        return FAILURE;
    }

    new->data = data;
    new->left = NULL;
    new->right = NULL;

    if (*root == NULL)
    {
        *root = new;
        return SUCCESS;
    }
    int flag;
    Tree_t *temp = *root;   //declaring two pointers to hold address
    Tree_t *parent;
    
    while(temp != NULL) //condition for traversal
    {
        parent = temp;
        if(data < temp->data)   //if data is less move to left child address
        {
            temp = temp-> left;
            flag = 1;
        }
        else if(data > temp-> data) //if data is more move to right child address
        {
            temp = temp-> right;
            flag = 0;
        }
        else    // continue if duplicate data present
        {
            printf("INFO : Duplicate found\n");
            return 0;
        }
        
    }
    if(flag == 1)
    {
        parent-> left = new;    //update LC
    }
    else
    {
        parent->right = new;    //update RC
    }
    return SUCCESS;
    

}
int insert_at_last(Slist **head, data_t data) //insert at last
{
    Slist *new = malloc(sizeof(Slist));
    if (new == NULL)
    {
        return FAILURE;
    }
    
    new->data = data;
    new->link = NULL;

    if (*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }
    Slist *temp = *head;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = new;
    return SUCCESS;
}
void print_list(Slist *head) //print list
{
    if (head == NULL)
    {
        printf("file is empty\n");
    }
    else
    {
        while (head)
        {
            printf("%d-> ",head->data);
        }
        printf("NULL\n");
    }
    
}