#ifndef _LIBRARY_H
#define _LIBRARY_H
#include <string.h>
#include <stdlib.h>

/*              שיר עצמו        */
typedef struct{
    char name[10];
    char singer[10];
    char album_name[10];
    float length;
} song;


/*              שיר בודד            */
typedef struct node{
    song *my_song;
    struct node *next;
} Node;



/*          ספריית השירים       */
typedef struct{
    int num_of_songs;
    Node *head;
} library;



void create_library(library *l);
int add_song(library *l, song *s);
int song_appears(library *l, song *to_find);
song *copy_song(song *s1);
int remove_song(library *l, song *s);
song *get_song(library *l,char *name);
void print_songs(library *l, void *print_by, void(*print_songs_by_type)(void *));

#endif