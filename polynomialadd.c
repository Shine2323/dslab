#include <stdio.h>

struct poly{
    int coeff;
    int expo;
}p1[10],p2[10],p3[10];

//function declarations..
int readpoly(struct poly[]);
int addpoly(struct poly[],struct poly[],int,int,struct poly[]);
void displaypoly(struct poly[],int terms);



void main() {
    int t1,t2,t3;
    
    t1=readpoly(p1);
    printf("\n first polynomial ");
    displaypoly(p1,t1);
    
    t2=readpoly(p2);
    printf("\nSecond polynomial");
    displaypoly(p2,t2);
    
    t3=addpoly(p1,p2,t1,t2,p3);
    printf("\nResultant polynomial is");
    displaypoly(p3,t3);
}

int readpoly(struct poly p[10]){
    int i,t1;
    printf("\nenter the total no. of terms in polynomial:");
    scanf("%d",&t1);
    printf("Enter the coefficient and expponent in descending order");
    
    for(i=0;i<t1;i++){
        printf("\nEnter the coefficient(%d):",i+1);
        scanf("%d",&p[i].coeff);
        printf("\nEnter the exponent(%d):",i+1);
        scanf("%d",&p[i].expo);
        
    }
    return(t1);
    
}
void displaypoly(struct poly p[10],int term){
    
    int k;
    for(k=0;k<term;k++){
        if(k==0)
        printf("%dx^%d",p[k].coeff,p[k].expo);
        else
       printf("+%dx^%d",p[k].coeff,p[k].expo);
    }
}
int addpoly(struct poly p1[10],struct poly p2[10],int t1,int t2,struct poly p3[10]){
    
    int i=0,j=0,k=0;
    
    while(i<t1 && j<t2){
        if(p1[i].expo==p2[j].expo){
            p3[k].coeff=p1[i].coeff+p2[j].coeff;
            p3[k].expo=p1[i].expo;
            i++; j++; k++;
        }
        else if(p1[i].expo>p2[j].expo){
            p3[k].coeff=p1[i].coeff;
            p3[k].expo=p1[i].expo;
            i++; k++;
            
        }
        else{
            p3[k].coeff=p2[j].coeff;
            p3[k].expo=p2[j].expo;
            k++; j++;
        }
    }
    //for balance terms in polynomial 1.
    while(i<t1){
        p3[k].coeff=p1[i].coeff;
        p3[k].expo=p1[i].expo;
        i++;  k++;
    }
    //for balance terms in polynomial 2.
    while(j<t2){
        p3[k].coeff=p2[j].coeff;
        p3[k].expo=p2[j].expo;
        j++;  k++;
    }
    return(k);
}
