#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};
typedef struct node node_t;

node_t *add_node(node_t *head, int value)
{
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL)
    {
        return NULL;
    }

    if (head == NULL)
    {
        new_node->value = value;
        new_node->next = NULL;
        return new_node;
    }
    else
    {
        node_t *tmp = head;
        new_node->value = value;
        new_node->next = tmp;
        head = new_node;

        return head;
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

node_t *revert_list(node_t *head)
{
    node_t *curr = head;
    node_t *prev = NULL;
    while (curr->next != NULL)
    {
        node_t *tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }
    return prev;
}

int main(int argc, char *argv[])
{
    node_t *head = NULL;

    for (int i = 0; i < argc; i++)
    {
        head = add_node(head, atoi(argv[i]));
    }

    print_list(revert_list(head));

    return 0;
}
