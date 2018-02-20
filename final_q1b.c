#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int broken_appears(const char *src, const char *lookup_a, const char *lookup_b);
int broken_str(const char *src, const char *lookup);

int main(){
    if (broken_str("yosef ben-menashe","yobfd"))
    {
        printf("found! :)\n");
    } else {
        printf("not found :(\n");
    }

    return 0;
}



int broken_str(const char *src, const char *lookup)
{
    int i;
    int len_of_lookup = strlen(lookup);

    if (strstr(src,lookup))
    {
        return 1;
    }

    for (i=1; i<len_of_lookup; i++)
    {
        if (broken_appears(src,lookup,lookup+i))
        {
            return 1;
        }
    }

    return 0;
}

int broken_appears(const char *src, const char *lookup_a, const char *lookup_b)
{
    int len_of_lookup_a;
    char *lookup_a_str;
    char *spot_of_a;
    char *spot_of_b;

    len_of_lookup_a = lookup_b-lookup_a;

    lookup_a_str = (char *) malloc((len_of_lookup_a+1)* sizeof(char));

    strncpy(lookup_a_str,lookup_a,len_of_lookup_a);
    lookup_a_str[len_of_lookup_a] = '\0';

    spot_of_a = strstr(src,lookup_a_str);
    spot_of_b = strstr(src,lookup_b);

    if (spot_of_a == NULL || spot_of_b == NULL)
    {
        return 0;
    }

    return spot_of_a < spot_of_b;
}


