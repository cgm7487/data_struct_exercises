#include <stdio.h>
#include <stdlib.h>

typedef struct _node_t
{
    int data;
    struct _node_t *next;
} node_t;

static void
    push_data_to_list(  node_t *list,
                        int data)
{
    node_t *current = list;

    while(current->next != NULL)
    {
        current = current->next;
    }

    current->next = (node_t *)malloc(sizeof(node_t));
    current->next->data = data;
    current->next->next = NULL;
}

static int
    find_last_n_data(   node_t *list,
                        int n)
{
    node_t *start = list;
    node_t *end = start;
    int dist = 0;

    while(end != NULL)
    {
        if(dist > n-1)
        {
            start = start->next;
            --dist;
        }

        end = end->next;
        ++dist;
    }

    if(dist != n)
        return -1;

    return start->data;
}

int main()
{
    node_t *list = (node_t *)malloc(sizeof(node_t));
    list->data = 0;
    list->next = NULL;

    int i;
    for(i = 1; i <10; ++i)
    {
        push_data_to_list(list, i);
    }

    node_t *head = list;
    while(head != NULL)
    {
        printf("data = %d\r\n", head->data);
        head = head->next;
    }

    printf("list[-%d] is %d\r\n", 1, find_last_n_data(list, 1));

    printf("list[-%d] is %d\r\n", 10, find_last_n_data(list, 10));

    printf("list[-%d] is %d\r\n", 11, find_last_n_data(list, 11));

    return 0;
}