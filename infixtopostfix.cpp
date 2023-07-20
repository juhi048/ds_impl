#include<iostream>
#include<string.h>
using namespace std;
struct stack {
    int top;
    int size;
    char *arr;
};

int isEmpty(struct stack *ptr){
    if(ptr->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack *ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

char stacktop(struct stack *ptr){
    return ptr->arr[ptr->top];
}

char push(struct stack *ptr , char val){
    if(isFull(ptr)){
        cout<<"Stack overloaded"<<endl;
        return -1;
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;    
    }
}

char pop(struct stack *ptr){
    if(isEmpty(ptr)){
        cout<<"stack underflow"<<endl;
        return -1;
    }
    else{
        char val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int precedence( char ch){
    if(ch == '/' || ch == '*'){
        return 3;
    }
    else if (ch=='+' || ch == '-'){
        return 2;
    }
    else{
        return 0;
    }
}

int isOperator( char ch){
    if(ch=='/' || ch =='*' || ch == '+' || ch == '-'){
        return 1;
    }
    else{
        return 0;
    }

}

char* infixtopostfix(char *infix){
    struct stack *sp = (struct stack*)malloc( sizeof(struct stack));
    sp->top=-1;
    sp->size=200;
    sp->arr=(char*)malloc(sp->size * sizeof(char));
    char * postfix=(char *)malloc((strlen(infix)+1) * sizeof(char));
    int i=0;
    int j=0;
    while(infix[i]!='\0'){
        if(!isOperator(infix[i])){
            postfix[j]=infix[i];
            j++;
            i++;
        }
        else{
            if(precedence(infix[i])>precedence(stacktop(sp))){
                push(sp,infix[i]);
                i++;
            }
            else{
                postfix[j]=pop(sp);
                j++;
            }

        }

    }
    while(!isEmpty(sp)){
        postfix[j]=pop(sp);
        j++;
    }
    postfix[j]= '\0';
    return postfix;


}


int main(){
    char * infix = "a-b+t/6";
    cout<<"The postfix is "<<infixtopostfix(infix)<<endl;    
    return 0;
}
