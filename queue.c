#include "main.h"

int enqueue(Queue_t **front, Queue_t **rear, Tree_t* node)
{
    //create new node
    Queue_t *new = malloc(sizeof(Queue_t));
    
    if(new == NULL)
    {
        return FAILURE;
    }
    //update values
    new->node = node;
    new->link = NULL;
    //if list is empty
    if(*rear == NULL)
    {
        *front = *rear = new;
        new->link = new;
        return SUCCESS;
    }
    //if list not empty

    (*rear)->link = new;    //update last node
    *rear = new;
    new->link = *front; //make circular link
    return SUCCESS;
}

int dequeue(Queue_t **front, Queue_t **rear)
{
    //if list is empty
    if(*front == NULL )
    {
        return FAILURE;
    }
    
    if(*rear == *front)
    {// for single node case
        *rear = *front = NULL;
        return SUCCESS;
    }
    //for multiple node case
    Queue_t *temp = *front;

    *front = (*front)->link;    //update front pointer to next node
    (*rear)->link = *front;     //make circular link
    free(temp);
    
    return SUCCESS;
}