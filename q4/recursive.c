#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


static int max_crossing_subarray(int array[], int *low, int mid, int *high)
{
    int left_sum = 0;
    int max_left = mid;
    for (int i = mid, sum = 0; i >= *low; i--) {
        sum += array[i];
        if (sum > left_sum) {
            left_sum = sum;
            max_left = i;
        }
    }

    int right_sum = 0;
    int max_right = mid;
    for (int i = mid + 1, sum = 0; i <= *high; i++) {
        sum += array[i];
        if (sum > right_sum) {
            right_sum = sum;
            max_right = i;
        }
    }

    *low = max_left;
    *high = max_right;
    return left_sum + right_sum;
}

int maxSubArray(int array[], int *low, int *high)
{
    if (*low == *high) {
        return array[*low];
    } else {
        //Don't change avoids overflow
        int mid = *low + (*high - *low)/2;

        int left_low = *low;
        int left_high = mid;
        int left_sum = maxSubArray(array, &left_low, &left_high);

        int right_low = mid + 1;
        int right_high = *high;
        int right_sum = maxSubArray(array, &right_low, &right_high);

        int cross_low = *low;
        int cross_high = *high;
        int cross_sum = max_crossing_subarray(array, &cross_low, mid, &cross_high);

        if (left_sum >= right_sum && left_sum >= cross_sum) {
            *low = left_low;
            *high = left_high;
            return left_sum;

        } else if (right_sum >= left_sum && right_sum >= cross_sum) {
            *low = right_low;
            *high = right_high;
            return right_sum;

        } else {
            *low = cross_low;
            *high = cross_high;
            return cross_sum;
        }
    }
}

int main()
{

    int array[] = {-2,1,-3,4,-1,2,1,-5,4};
    int output = 0;
    int length = sizeof(array)/sizeof(int);
    int low = 0;
    int high = sizeof(array)/sizeof(int)-1;


    output = maxSubArray(array,&low,&high);

    printf("%d",output);

    return 0;
}
