#include <stdio.h>

int isValid(char * s){

    int i;
    int index = -1;
    int arr[1000];
    int valid = 1;

    while (s[i] != '\0' && valid == 1)
    {
        printf("%d %c ", i, s[i]);
        

        if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
            index ++;
            printf("push\n");
            arr[index] = s[i];
            
        } else {
            printf("pop\n");
            
            if (index < 0){
                valid = 0;
                break;
            }
            char temp = arr[index];

            if ((s[i] == ')' && temp != '(') || (s[i] == ']' && temp != '[') || (s[i] == '}' && temp != '{')){
                valid = 0;
                break;
            }
            index --;
        }
        i++;
    }

    if (index > -1){
        valid = 0;
    }
    
    return valid;

}

int main(){

    char str[5] = {'(', '[', ')', '{', '}'};
    char *strPtr = &str[0];

    printf("\n%d ", isValid(strPtr));
}