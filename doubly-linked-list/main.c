#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
    struct Node *prev;
} Node;

void add_node(Node **head, int value)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        printf("Node allocation failed.\n");
        exit(1);
    }

    if (*head == NULL)
    {
        new_node->next = NULL;
    }
    else
    {
        Node *tmp = *head;
        new_node->next = tmp;
        tmp->prev = new_node;
    }

    new_node->prev = NULL;
    new_node->value = value;
    *head = new_node;
}

void print_list(Node *head)
{
    printf("NULL <---> ");

    Node *curr = head;
    while (curr != NULL)
    {
        printf("%d <---> ", curr->value);
        curr = curr->next;
    }

    printf("NULL\n");
}

void revert_list(Node **head)
{
    Node *curr = *head;
    while (curr != NULL)
    {
        Node *next = curr->next;
        curr->next = curr->prev;
        curr->prev = next;
        *head = curr;
        curr = next;
    }
}

void delete_list(Node **head)
{
    Node *curr = *head;
    while (curr != NULL)
    {
        Node *next = curr->next;
        free(curr);
        curr = next;
    }
}

int main(int argc, char *argv[])
{
    Node *head = NULL;
    for (int i = 1; i < argc; i++)
    {
        add_node(&head, atoi(argv[i]));
    }
    revert_list(&head);
    print_list(head);
    delete_list(&head);
}
