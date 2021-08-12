#include<stdio.h>
#include<stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//DEFINE THE HASTABLE DATA STRUCTURE SKELETON
struct node{
    int index_nums;
    struct node *next_p;
};

//INITIALIZATION FUNCTION
void init_hashtable(struct node *hashtable){
    
    //default values
    for(int i=0;i<263;i++){
        hashtable[i].index_nums = -1;
        hashtable[i].next_p = NULL;
    }
}

//Create hashing functionl
int hash_function(int key){
    return abs((key%263));
}


int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    
    int *result = (int *)malloc(sizeof(int)*2);
    struct node *hashtable = (struct node*)malloc(sizeof(struct node)*263);
        
    init_hashtable(hashtable);
    int hash_value;
    
    for(int i=0;i<numsSize;i++){
        hash_value = hash_function(nums[i]);
        
        //search for an empty spot
        if(hashtable[hash_value].index_nums == -1)
            hashtable[hash_value].index_nums = i;
        // if empty spot doesnt exist create a node and attach it to the next pointer
        else{
            struct node *tail = (struct node*)malloc(sizeof(struct node));
            tail->index_nums = i;
            tail->next_p = hashtable[hash_value].next_p;
            hashtable[hash_value].next_p = tail; 
        }
    }
    
    //search for target-nums[i]
    for(int i=0;i<numsSize;i++){
        int hash_diff = hash_function(target-nums[i]);
        if(hashtable[hash_diff].index_nums==-1){
            continue;
        }
        if(nums[hashtable[hash_diff].index_nums] == target-nums[i] && hashtable[hash_diff].index_nums!=i){
            result[0]=i;
            result[1]=hashtable[hash_diff].index_nums;
            *returnSize = 2;
            return result;
        }
        else{
            
            struct node *temp = hashtable[hash_diff].next_p;
            while(temp!=NULL){
                
                if(nums[temp->index_nums] == target-nums[i]){
                    result[0]=i;
            result[1]=temp->index_nums;
                *returnSize = 2;
                return result;
                    
                }
                else{
                    temp=temp->next_p;
                }
            }
        }
    }
    return NULL;
}