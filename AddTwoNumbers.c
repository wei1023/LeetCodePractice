#include <stdio.h>
#include <stdlib.h>
/**
 * Definition for singly-linked list.
 **/

struct ListNode {
     int val;
     struct ListNode *next;
};
 

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *final = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *temp = final;
    
    int exceed = 0;
    while (l1 != NULL || l2 != NULL || exceed > 0)
    {
        int sum = 0;
        if (l1 == NULL && l2 == NULL){
            sum = exceed;
        } else if (l1 == NULL){
            sum = l2->val + exceed;
            l2 = l2->next;
        } else if (l2 == NULL){
            sum = l1->val + exceed;
            l1 = l1->next;
        } else {
            sum = l1->val + l2->val + exceed;
            l1 = l1->next;
            l2 = l2->next;
        }

        
        temp->val = sum % 10;
        exceed = (int)(sum / 10);
        //printf("%d %d\n", temp->val, exceed);

        
        if (l1 != NULL || l2 != NULL || exceed > 0){
            temp->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            temp = temp->next;
        } else{
            temp->next = NULL;
        }
    }

    /**
    temp = final;
    while(temp != NULL){
        printf("%d ", temp->val);
        temp = temp->next;
    }
    **/
    
    return final;
    
}

int main(){
    printf("main");
    struct ListNode* l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* l2 = (struct ListNode*)malloc(sizeof(struct ListNode));

    
    struct ListNode* l11 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* l21 = (struct ListNode*)malloc(sizeof(struct ListNode));

    struct ListNode* l12 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* l22 = (struct ListNode*)malloc(sizeof(struct ListNode));
    

    
    l1->val = 9;
    l1->next = l11;
    
    l11->val = 9;
    l11->next = l12;
    l12->val = 9;
    l12->next = NULL;

    l2->val = 9;
    l2->next = l21;
    
    l21->val = 9;
    l21->next = l22;
    l22->val = 9;
    l22->next = NULL;

    addTwoNumbers(l1, l2);
}