#include<stdio.h>
#include<stdlib.h>
// Creating and traversing linked list
struct node
{
    int value;
    struct node *next;
};
struct node *head = 0;
struct node *new_node, *temp; // temp is a pointer which will point towards the node just before the newly created node
main()
{
    int choice = 1;
    do
    {  
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter data\n");
    scanf("%d",&new_node->value);
    new_node->next = 0;
    if(head == 0)
    {
        head = new_node;
        temp = new_node;
    }
    else
    {
        temp->next = new_node;
        temp = new_node;
    }
    printf("Press 1 to continue?\n");
    scanf("%d",&choice);
    }while(choice == 1);
    // Now we shall be displaying all the outputs of the linked list
    new_node = head;
    while(new_node != 0)
    {
        printf("%d\n",new_node->value);
        new_node = new_node->next;
    }
    return 0;
}
