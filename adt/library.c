#include "Library.h"

typedef struct node{
    void *object;
    struct node *next;
} Node;

struct Library{
    int num_of_objects;
    Node *head;
};

void destroy_library(library *l)
{
    Node *to_delete;

    while (!l->head)
    {
        to_delete = l->head;

        l->head = to_delete->next;

        free(to_delete->object);
        free(to_delete);
    }
}

void create_library(library *l)
{
    l->num_of_objects = 0;
    l->head = NULL;
}

int add_song(library *l, void *object, void *(*copy_object)(void *object),int (*object_appears)(library *, void *object))
{
    if (l->head == NULL)
    {
        Node *new_node = (Node *) malloc (sizeof(Node));

        new_node->object= copy_object(object);
        new_node->next = NULL;

        l->head = new_node;
        l->num_of_objects++;
        return 1;
    }

    if (!object_appears(l,object))
    {
        Node *new_node = (Node *) malloc (sizeof(Node));

        new_node->object= copy_object(object);

        new_node->next = l->head;

        l->head = new_node;
        l->num_of_objects++;
        return 1;
    }

    return 0;
}

int remove_song(library *l, void *object, int (*cmp_objects)(void *o1,void *o2))
{
    Node *cur_node;
    Node *to_delete = NULL;

    cur_node = l->head;

    while (cur_node->next != NULL)
    {
        if (cmp_objects(cur_node->object, object) == 1)
        {
            cur_node->next = to_delete->next;

            free(to_delete->object);
            free(to_delete);
            l->num_of_objects--;
            return 1;
        }
        cur_node = cur_node->next;

    }
    return 0;
}




void *get_object(library *l, char *key, int (*cmp_objects)(char *key, void *o2)) {
    Node *cur_node = l->head;

    while (cur_node != NULL)
    {
        if (cmp_objects(key,cur_node))
        {
            return cur_node->object;
        }
    }
    return NULL;
}

int get_num_of_songs_in_library(library *l)
{
    return l->num_of_objects;
}

void print_songs(library *l, void *print_by, void(*print_songs_by_type)(void *))
{}
