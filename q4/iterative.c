#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int maxSubArray(int array[],int length)
{

    int i,j,k;
    int temp;
    int max = 0;

    for(k=0; k<length; k++) {

        //printf("k=%d\n",k);

        for(i=0; i<length-k+1; i++) {

            for(j=0,temp=0; j<k; j++) {

                temp = temp + array[i+j];

            }

            if(temp > max)
                max = temp;

            //printf("%d,%d\n",max,temp);
        }
    }

    return max;
}


int main()
{

    int array[] = {-2,1,-3,4,-1,2,1,-5,4};
    int output;
    int length = sizeof(array)/sizeof(int);

    output = maxSubArray(array,length);

    printf("%d",output);

    return 0;
}
