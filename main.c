#include "main.h"

int mian()
{
    Tree_t *root = NULL;
    Slist *head = NULL;

    int data;
    int no;
    printf("Enter the number of data insert into BST : ");
    scanf("&d",&no);

    while (no)
    {
        printf("Enter the dta into BST : ");
        scanf("%d",&data);
        //calling the function the function to insert the dat into bst
        insert_into_BST(&root, data);

        no--;
    }

    Queue_t *front = NULL, *rear = NULL;

    if(root)
    {
        enqueue(&front,&rear,root);
        Tree_t *current = NULL;
        while (front != NULL)
        {
            current = front->node;
            insert_at_last(&head,current->data);
        }
        if (current->left != NULL)
        {
            enqueue(&front,&rear,current->left);
        }
        if (current->right != NULL)
        {
            enqueue(&front, &rear, current->right);
        }
        if(front)
        {
            dequeue(&front, &rear);
        }
        printf("Printing from Linked List\n");
        print_list(head);   
    }   
}