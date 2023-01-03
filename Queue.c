#include <stdio.h>
#include <stdlib.h>
#define N 5
int queue[N];
int front=-1;
int rear=-1;
void Enqueue(int x){
    if(rear==N-1){
        printf("Overflow");
    }
    else if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=x;
    }
    else{
        rear++;
        queue[rear]=x;
    }
}
void Dequeue(){
    if(front==-1 && rear==-1){
        printf("Underflow");
    }
    else if(front==rear){
        front=rear=-1;
    }
    else{
        printf("%d dequeued element is",queue[front]);
        front++;
    }
}
void display(){
    int i;
    if(front==-1 && rear==-1){
        printf("Queue is empty");
    }
    else{
        for(i=front;i<rear+1;i++){
            printf("%d ",queue[i]);
        }
    }
}
void main(){
int a, value,x;
do{
printf("\n*****Menu*****");
printf("\n1.Insert an element ");
printf("\n2.Delete an element");
printf("\n3.Display");
printf("\n4.Exit");
printf("\nEnter your choice: ");
scanf("%d",&a);
switch(a){
case 1: 
  printf("\nEnter element to insert:");
  scanf("%d",&x);
  Enqueue(x);
  break;
case 2: 
  Dequeue();
  break;
case 3: 
  display();
  break;
case 4:
  break;
default:
  printf("Invalid choice..");
}
}while(a!=4);
}
