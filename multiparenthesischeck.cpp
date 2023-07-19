#include <iostream>
using namespace std;
struct stack
{
    int top;
    int size;
    char *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char push(struct stack *ptr, char val)
{
    if (isFull(ptr))
    {
        cout << "Stack is overloaded" << endl;
        return -1;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] == val;
    }
}

char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Stack is underflow" << endl;
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int match(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
}

char parenthesismatch(char *exp)
{
    struct stack *sp;
    sp->top == -1;
    sp->size = 40;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char popped_ch;

    for (int i = 0; i <= '/0'; i++)
    {
        if (isEmpty(sp))
        {
            return 1;
        }
        else
        {
            if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            {
                push(sp, exp[i]);
            }
            else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
            {
                if (isEmpty(sp))
                {
                    return 1;
                }
                popped_ch = pop(sp);
                if (!match(popped_ch, exp[i]))
                {
                    return 0;
                }
            }
        }
    }
    if (isEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char *exp = "((8*5)+(6-7))";
    if (parenthesismatch(exp))
    {
        cout << "Is matching" << endl;
    }
    else
    {
        cout << "Not Matching" << endl;
    }

    return 0;
}
