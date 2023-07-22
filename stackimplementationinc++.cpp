#include"bits/stdc++.h"
#include<iostream>
using namespace std;
#define size 30
class stac{
    int top;
    int *arr;
    
    public:
    stac(){
        arr=new int [size];
        top==-1;
    }

    void push(int x){
        if (top==size -1){
            cout<<"Stack is overloaded"<<endl;
        }
        else{
            top++;
            arr[top]=x;
        }
    }
    int pop(){
        if(top==-1){
            cout<<"Stack is overflowed"<<endl;
            return -1;
        }
        else{
            int x = arr[top];
            top--;
            return x;
        }
    }
    bool empty(){
        if (top == - 1){
            return true;
        }
        else{
            return false;
        }
    }
    int peek(int ind){
        if (top==size -1){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        else{
            int arrind=(top-ind+1);
            if(arrind<0){
                cout<<"Innvalid"<<endl;
                return 0;
            }
            else{
                return arrind;
            }
        }
    }
    int Top(){
        if (top==-1){
            cout<<"The stack is Empty"<<endl;
            return -1;
        }
        else{
            return arr[top];
        }
    }
};
int main(){
    stac st;
    st.push(3);
    st.push(5);
    st.push(4);
    st.push(7);
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    cout<<st.empty()<<endl;

 
    return 0;
}
