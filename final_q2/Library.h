#ifndef _LIBRARY_H
#define _LIBRARY_H
#include <string.h>
/*              שיר עצמו        */
typedef struct{
    char name[10];
    char singer[10];
    char album_name[10];
    float length;
} song;


/*              שיר בודד            */
typedef struct{
    song *my_song;
    struct Node *next;
} Node;



/*          ספריית השירים       */
typedef struct{
    Node *head;
} library;



void create_library(library *l);
int add_song(library *l, song *s);
Node *song_appears(library *l, song *to_find);
song *copy_song(song *s1);

#endif