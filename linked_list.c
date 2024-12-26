#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

void delete_list(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        Node *next = curr->next;
        free(curr);
        curr = next;
    }
}

void add(Node **head, int value)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        printf("Error allocating new_node.\n");
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
        Node *tmp = *head;
        new_node->value = value;
        new_node->next = tmp;
        *head = new_node;

        return;
    }
}

void print_list(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        printf("%d -> ", curr->value);
        curr = curr->next;
    }
    printf("NULL\n");
}

void revert_list(Node **head)
{
    Node *curr = *head;
    Node *prev = NULL;
    while (curr != NULL)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
    return;
}

int main(int argc, char *argv[])
{
    Node *head = NULL;

    for (int i = 1; i < argc; i++)
    {
        add(&head, atoi(argv[i]));
    }

    revert_list(&head);

    print_list(head);

    delete_list(head);

    return 0;
}
