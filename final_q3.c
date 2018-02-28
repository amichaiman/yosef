#include <stdio.h>

void cycle_byte_array_left(unsigned char *pb, int pbsize, unsigned int n);
void shift_left_once(unsigned char *pb, int pbsize);
unsigned char cycle_byte_left(unsigned char b, unsigned int n);

int main()
{
    unsigned char pb[4];
    int i;

    pb[0] = 2;
    pb[1] = 2;
    pb[2] = 2;
    pb[3] = 2;

    for(i=0; i<4; i++)
    {
        printf("%x\t",pb[i]);
    }

    cycle_byte_array_left(pb,4,2);

    for(i=0; i<4; i++)
    {
        printf("%x\t",pb[i]);
    }
    return 0;
}


unsigned char cycle_byte_left(unsigned char b, unsigned int n)
{
    int i;
    unsigned char left_most_bit;

    n %= 8;

    for (i=0; i<n; i++)
    {
        left_most_bit = b>>7;   //שומרים את הסיבית הכי שמאלית
        b <<= 1;
        b |= left_most_bit;     //מכניסים אותה בהתחלה
    }

    return b;
}


void cycle_byte_array_left(unsigned char *pb, int pbsize, unsigned int n)
{
    int i;

    for (i=0; i<n; i++)
        shift_left_once(pb,pbsize);

}


void shift_left_once(unsigned char *pb, int pbsize)
{
    unsigned char bit_to_add;
    unsigned char leftmost_bit;

    int i;

    bit_to_add = pb[0] >> 7;        //שומר את הסיבית השמאלית ביותר של התא הראשון

    for (i=pbsize-1; i>=0; i--){

        leftmost_bit = pb[i]>>7;            //הסיבית השמאלית ביותר של התא הנוכחי
        pb[i] <<= 1;
        pb[i] |= bit_to_add;

        bit_to_add = leftmost_bit;  //השמאלי ביותר של הנוכחי, זה מיש שצריך להוסיף לאחד הבא
    }
}