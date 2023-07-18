#include<iostream>
using namespace std;
struct stack{
    int top;
    int *arr;
    int size;
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

void push(struct stack *ptr,int val){
    if (isFull(ptr)){
        cout<<"Stack overloaded"<<endl;
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]= val;

    }
}

int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        cout<<"Stack Underflow"<<endl;
        return -1;
    }
    else{
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int stacktop(struct stack *ptr){
    return ptr->arr[ptr->top];
}

int stackbottom(struct stack *ptr){
    return ptr->arr[0];
}

int peek(struct stack *ptr,int i){
    int arrind=ptr->top-i+1;
    if (arrind<0){
        cout<<"Invalid"<<endl;
        return -1;
    }
    else{
        return ptr->arr[arrind];
    }
}
int main(){
    struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
    sp->top=-1;
    sp->size=56;
    sp->arr=(int*)malloc(sp->size * sizeof(int));
    cout<<"Stack Created"<<endl;

    cout<<"Before"<<endl;
    cout<<isEmpty(sp)<<endl;
    cout<<isFull(sp)<<endl;

    push(sp,5);
    push(sp,56);
    push(sp,86);
    push(sp,81);
    pop(sp);

    cout<<"After"<<endl;
    cout<<isEmpty(sp)<<endl;
    cout<<isFull(sp)<<endl;

    cout<<stacktop(sp)<<endl;
    cout<<stackbottom(sp)<<endl;

    for(int j=1;j<sp->top+2;j++){
        cout<<"The "<<j<<"element in the stack is "<<peek(sp,j)<<endl;
    }

return 0;
}
