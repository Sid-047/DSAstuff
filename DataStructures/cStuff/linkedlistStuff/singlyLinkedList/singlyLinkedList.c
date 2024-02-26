#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct linkedList{
    struct node *head;
};

struct node *createNode(int x){
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
};

void insertAtIndex(struct linkedList *lList, int x, int idx){
    struct node *newNode = createNode(x);
    if (lList->head==NULL){
        lList->head = newNode;
    } else{
        if(idx==0){
            newNode->next = lList->head;
            lList->head = newNode;
        } else{
            int idxVal = 1;
            struct node *tempNode = lList->head;
            while(idxVal!=idx && tempNode!=NULL){
                tempNode = tempNode->next;
                idxVal++;
            }
            newNode->next = tempNode->next;
            tempNode->next = newNode;
        }
    }
}

void deleteAtIndex(struct linkedList *lList, int idx){
    if (lList->head!=NULL){
        if(idx==0){
            struct node *tempNode = lList->head;
            lList->head = lList->head->next;
            free(tempNode);
        } else{
            int idxVal = 1;
            struct node *tempNode = lList->head;
            while(idxVal!=idx && tempNode!=NULL){
                tempNode = tempNode->next;
                idxVal++;
            }
            struct node *outNode = tempNode->next;
            tempNode->next = tempNode->next->next;
            free(outNode);
        }
    }
}

void insertAtBeginning(struct linkedList *lList, int x){
    insertAtIndex(lList, x, 0);
}

void insertAtEnd(struct linkedList *lList, int x){
    struct node *newNode = createNode(x);
    if (lList->head==NULL){
        lList->head = newNode;
    } else{
        struct node *tempNode = lList->head;
        while(tempNode->next!=NULL){
            tempNode = tempNode->next;
        }
        newNode->next = tempNode->next;
        tempNode->next = newNode;
    }
}

void displayList(struct linkedList *lList){
    printf("\n LinkedList:\n");
    struct node *tempNode = lList->head;
    while(tempNode!=NULL){
        printf("%d \t", tempNode->data);
        tempNode = tempNode->next;
    }
}

int main(){
    struct linkedList lList;
    lList.head = NULL;
    insertAtEnd(&lList, 77);
    insertAtEnd(&lList, 88);
    insertAtEnd(&lList, 99);
    insertAtIndex(&lList, 11, 1);
    insertAtBeginning(&lList, 55);
    displayList(&lList);
    deleteAtIndex(&lList, 1);
    displayList(&lList);
    return 0;
}