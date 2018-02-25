#ifndef _LIBRARY_H
#define _LIBRARY_H

#include <string.h>
#include <stdlib.h>

typedef struct Library library;

void create_library(library *l);
void print_songs(library *l, void *print_by, void(*print_object)(void *));
int add_song(library *l, void *object, void *(*copy_object)(void *object),int (*object_appears)(library *, void *object));
int remove_song(library *l, void *object, int (*cmp_objects)(void *o1,void *o2));

#endif