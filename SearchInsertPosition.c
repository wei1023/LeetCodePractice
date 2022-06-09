#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target){
    int index = -1;
    int i;
    for(i = 0; i < numsSize && index == -1; i++){
        printf("%d ", nums[i]);
        if (nums[i] >= target){
            index = i;
        }
    }
    if (index == -1){
        index = numsSize;
    }
    return index;
}

int main(){
    int numsArr[4] = {1, 3, 5, 6};
    int *nums = &numsArr[0];
    printf("\n%d", searchInsert(nums, 4, 7));
}