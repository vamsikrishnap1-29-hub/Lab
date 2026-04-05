#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* top = NULL;

void push(int val){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = top;
    top = temp;
}

void pop(){
    if(top == NULL){
        printf("Stack Empty\n");
    }
    else{
        struct node* temp = top;
        printf("Popped: %d\n", temp->data);
        top = top->next;
        free(temp);
    }
}

void peek(){
    if(top == NULL){
        printf("Stack Empty\n");
    }
    else{
        printf("Top: %d\n", top->data);
    }
}

void display(){
    struct node* temp = top;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    int ch, val;

    while(1){
        printf("\n1.Push 2.Pop 3.Peek 4.Display 5.Exit\n");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                printf("Enter value: ");
                scanf("%d",&val);
                push(val);
                break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: return 0;
        }
    }
}