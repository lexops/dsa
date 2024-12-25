#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};
typedef struct node node_t;

void add_node(node_t **head, int value)
{
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL)
    {
        printf("Error allocating new node.\n");
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
        node_t *tmp = *head;
        new_node->value = value;
        new_node->next = tmp;
        *head = new_node;

        return;
    }
}

void print_list(node_t *head)
{
    node_t *curr = head;
    while (curr != NULL)
    {
        printf("%d -> ", curr->value);
        curr = curr->next;
    }
    printf("NULL\n");
}

void revert_list(node_t **head)
{
    node_t *curr = *head;
    node_t *prev = NULL;
    while (curr != NULL)
    {
        node_t *tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }
    *head = prev;
    return;
}

void delete_list(node_t *head)
{
    node_t *curr = head;
    while (curr != NULL)
    {
      node_t *aux = curr->next;
      free(curr);
      curr = aux;
    }
}

int main(int argc, char *argv[])
{
    node_t *head = NULL;

    for (int i = 1; i < argc; i++)
    {
        add_node(&head, atoi(argv[i]));
    }

    revert_list(&head);

    print_list(head);

    delete_list(head);

    return 0;
}
