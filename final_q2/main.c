#include <stdio.h>
#include <string.h>
#include "Library.h"


int main()
{
    song song1;
    song song2;

    library l;  //פה יש l אורגינל


    strcpy(song1.name,"hatikva");
    strcpy(song1.singer,"hatikva");
    strcpy(song1.album_name,"hatikva");
    song1.length = 3.14;

    create_library(&l);
    add_song(&l,&song1);

    add_song(&l,&song2);

    return 0;
}