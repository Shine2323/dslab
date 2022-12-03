#include <stdio.h>

int stack[100],size,top;

//push fun.
void push(int item){
    
    if(top==size-1){
        printf("Stack is full");
        
    }else{
        top++;
        stack[top]=item;
    }
    
}
//pop fun.
void pop(){
    if(top==-1){
     printf("Stack is empty");
     
    }else{
        printf("popped element is %d",stack[top]);
        top--;
    }
}
//display fun.
void display(){
    if(top==-1){
        printf("stack is empty.");
    }else{
        printf("Elements in stack are:");
        for(int i=0;i<top;i++){
            printf("\n%d",stack[i]);
        }
    }
}
//status fun.
void status(){
    float free;
    if(top==-1){
        printf("stack is empty.");
    }else{
        printf("stack top elements is %d",stack[top]);
        if(top==size-1){
            printf("stack is full");
        }else{
            free=(float)(size-top-1)*100/size;
            printf("\nfree space=%f",free);
        }
    }
}


int main() {
    int choice,n;
    top=-1;
    printf("Enter the size of stack:");
    scanf("%d",&size);
    do
    {
        printf("\n1.PUSH \t2.POP \t3.DISPLAY \t4.STATUS \t5.EXIT");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
            printf("Enter the element to be pushed:");
            scanf("%d",&n);
            push(n);
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
            case 4:
            status();
            break;
            case 5:
            break;
            default:
            printf("Invalid choice!!");
        }
    }while(choice!=5);
}
