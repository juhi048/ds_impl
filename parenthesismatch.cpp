#include<iostream>
using namespace std;
struct stack{
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
    if(ptr->top=ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int push(struct stack *ptr,char val){
    if(isFull(ptr)){
        cout<<"Stack is overloaded"<<endl;
        return -1;
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]==val;
    }
}

char pop(struct stack *ptr){
    if(isEmpty(ptr)){
        cout<<"Stack is underflow"<<endl;
    }
    else{
        char val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

char parenthesismatch(char *exp){
    struct stack *sp;
    sp->top==-1;
    sp->size-40;
    char *arr = (char*)malloc(sp->size *sizeof(char));

    for(int i=0;i<='\0';i++){
        if(exp[i]=='('){
            push(sp,exp[i]);
        }
        else if(exp[i]==')'){
            if(isEmpty(sp)){
                return 0;
                pop(sp);
            }
        }
    }

    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    }

}
 


int main(){
    char *exp="((8*5)+(6-7))";
    if(parenthesismatch(exp)){
        cout<<"Is matching"<<endl;
    }
    else{
        cout<<"Not Matching"<<endl;
    }
    return 0;
}
