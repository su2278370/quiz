#include <stdio.h>
#include <stdlib.h>

char min(char *list,int length);

int main()
{

    char list[] = {'a','f','j','p','v'};
    char input;
    char output;
    char temp;
    int i;

    while(1) {

        temp = '~';

        scanf(" %c",&input);


        if(input == '1')
            break;

        for(i=0; i<sizeof(list)/sizeof(list[0]); i++) {

            if((int)input < (int)list[i] && (int)list[i] < (int)temp)
                temp = list[i];
        }

        if(temp=='~')
            output = min(list,sizeof(list)/sizeof(list[0]));
        else
            output = temp;

        printf("Output: %c \n",output);

    }

    return 0;
}

char min(char *list,int length)
{

    char min;
    char *ptr1,*ptr2;
    int i;

    ptr1 = &list[0];
    ptr2 = &list[1];

    for(i=0; i<length-1; i++,ptr2++) {

        if(*ptr2 < *ptr1)
            ptr1 = ptr2;
    }

    min = *ptr1;

    return min;
}
