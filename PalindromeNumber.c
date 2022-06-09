#include <stdio.h>
#include <stdlib.h>

int isPalindrome(int x){
    int boolean = 0;
    int temp = x;
    int count = 0;
    if (x < 0) {
        count ++;
        temp *= -1;
    }

    while (temp > 0)
    {
        count ++;
        temp /= 10;
    }
    //printf("count: %d\n", count);
    
    int *arr = (int *)malloc(sizeof(int) *count);
    
    int i = 0;
    temp = x;
    if (x < 0){
        arr[0] = '-';
        i++;
        temp *= -1;
    }

    while (temp > 0){
        arr[i] = '0' + (temp % 10);
        temp /= 10;
        i++;
    }
    
    /**
    for (i = 0; i < count; i++){
        printf("%c ", arr[i]);
    }**/

    int j;
    for(i = 0, j = (count - 1); i < count && j >=0; i++, j--){
        //printf("\n %d:%c %d:%c", i, arr[i], j, arr[j]);
        if(arr[i] != arr[j]){
            boolean = -1;
            break;
        }
    }

    
    
    return boolean;
}

int main(){
    int num = -123;
    printf("\n%d", isPalindrome(num));

    system("pause");
    return 0;
}