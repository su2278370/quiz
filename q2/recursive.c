#include <stdio.h>
#include <stdlib.h>

char smallest_character_recursive(char str[],char c);


int main()
{

    char list[] = {'a','f','j','p','v'};
    char input;
    char output;

    scanf(" %c",&input);

    output = smallest_character_recursive(list,input);

    printf("\n%c",output);
}

char smallest_character_recursive(char str[],char c)
{
    char first = *str;
    if((int)*str > (int)c)
        return *str;
    else if (*str=='\0')
        return first;
    else
        return smallest_character_recursive(str+1,c);
}

