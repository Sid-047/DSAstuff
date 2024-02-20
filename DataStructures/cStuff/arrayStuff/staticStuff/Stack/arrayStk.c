#include <stdio.h>
#define maxSize 100

struct stack{
    int array[maxSize];
    int top;
};

void initStack(struct stack *stk){
    stk->top = -1;
}

int isFull(struct stack *stk){
    return stk->top == maxSize-1;
}

int isEmpty(struct stack *stk){
    return stk->top == -1;
}

void pushStack(struct stack *stk, int x){
    if (!isFull(stk)){
        stk->top++;
        stk->array[stk->top] = x;
    } else{
        printf("Stack OverFlow!");
    }
}

void popStack(struct stack *stk){
    if (!isEmpty(stk)){
        stk->top--;
        printf("%d \n", stk->array[stk->top+1]);
    } else{
        printf("Stack UnderFlow!");
    }
}

void displayStack(struct stack *stk){
    for(int i = 0; i <= stk->top; i++){
        printf("%d \t", stk->array[i]);
    }
    printf("\n");
}

int main(){
    struct stack stk;
    initStack(&stk);

    int y;
    printf("StackMenu:");
    printf("\n1. Push");
    printf("\n2. Pop");
    printf("\n3. Display");
    printf("\n4. Exit");
    while (1) {
        printf("\nEnter Option: ");
        scanf("%d", &y);
        printf("\n");
        switch(y){
            case 1:
                int z;
                printf("Enter Element: ");
                scanf("%d", &z);
                printf("\n");
                pushStack(&stk, z);
                break;
            case 2:
                popStack(&stk);
                break;
            case 3:
                displayStack(&stk);
                break;
            case 4:
                return 0;
            default:
                printf("Option Outta Range!");
                break;
        }
    }
    return 0;
}

