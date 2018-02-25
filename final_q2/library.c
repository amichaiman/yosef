#include "Library.h"

void destroy_library(library *l)
{
    Node *to_delete;

    while (!l->head)
    {
        to_delete = l->head;

        l->head = to_delete->next;

        free(to_delete->my_song);
        free(to_delete);
    }
}

void create_library(library *l)
{
    l->num_of_songs = 0;
    l->head = NULL;
}

int add_song(library *l, song *s)
{
    if (l->head == NULL)
    {
        Node *new_node = (Node *) malloc (sizeof(Node));

        new_node->my_song = copy_song(s);
        new_node->next = NULL;

        l->head = new_node;
        l->num_of_songs++;
        return 1;
    }

    if (!song_appears(l,s))
    {
        Node *new_node = (Node *) malloc (sizeof(Node));

        new_node->my_song = copy_song(s);

        new_node->next = l->head;

        l->head = new_node;
        l->num_of_songs++;
        return 1;
    }

    return 0;
}

int song_appears(library *l, song *to_find)
{
    Node *cur_node = l->head;

    while (cur_node != NULL)
    {
        if (strcmp(cur_node->my_song->name, to_find->name) == 0)
            return 1;

        cur_node = cur_node->next;
    }

    return 0;
}

int remove_song(library *l, song *s)
{
    Node *cur_node;
    Node *to_delete = NULL;

    cur_node = l->head;
    while (cur_node->next != NULL)
    {
        if (strcmp(cur_node->next->my_song->name,s->name) == NULL)
        {
            cur_node->next = to_delete->next;

            free(to_delete->my_song);
            free(to_delete);
            l->num_of_songs--;
            return 1;
        }
        cur_node = cur_node->next;

    }
    return 0;
}




song *get_song(library *l, char *name) {
    Node *cur_node = l->head;

    while (cur_node != NULL)
    {
        if (strcmp(cur_node->my_song->name,name) == 0)
        {
            return cur_node->my_song;
        }
    }
    return NULL;
}

int get_num_of_songs_in_library(library *l)
{
    return l->num_of_songs;
}

void print_songs(library *l, void *print_by, void(*print_songs_by_type)(void *))
{}

song *copy_song(song *s1)
{
    song *s2 = (song *) malloc (sizeof(song));
    strcpy(s2->name,s1->name);
    strcpy(s2->singer,s1->singer);
    strcpy(s2->album_name,s1->album_name);
    s2->length = s1->length;
}
