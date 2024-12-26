#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} node;

void delete_list(node *head)
{
    node *curr = head;
    while (curr != NULL)
    {
        node *aux = curr->next;
        free(curr);
        curr = aux;
    }
}

void add_node(node **head, int value)
{
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        printf("Error allocating new node.\n");
        delete_list(*head);
        exit(1);
    }

    if (*head == NULL)
    {
        new_node->value = value;
        new_node->next = NULL;
        *head = new_node;
        return;
    }
    else
    {
        node *tmp = *head;
        new_node->value = value;
        new_node->next = tmp;
        *head = new_node;

        return;
    }
}

void print_list(node *head)
{
    node *curr = head;
    while (curr != NULL)
    {
        printf("%d -> ", curr->value);
        curr = curr->next;
    }
    printf("NULL\n");
}

void revert_list(node **head)
{
    node *curr = *head;
    node *prev = NULL;
    while (curr != NULL)
    {
        node *tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }
    *head = prev;
    return;
}

int main(int argc, char *argv[])
{
    node *head = NULL;

    for (int i = 1; i < argc; i++)
    {
        add_node(&head, atoi(argv[i]));
    }

    revert_list(&head);

    print_list(head);

    delete_list(head);

    return 0;
}
