#include <bits/stdc++.h>
#include <iostream>
#define MAX 5

using namespace std;

class stack1
{
private:
    int stackTop,expTop;
    string stack[MAX],expression;

public:
    stack1()
    {
     stackTop = -1;
        for (int i = 0; i < MAX; i++)
        {
            stack[i] = " ";
        }
    }
    string pop();
    void push(string expr);
    void seek();
    void display();
    bool isempty();
    bool isfull();
    string combo(string optr1,string optr2,string opr);
    void getexp();
    void check();
    bool isOperator(string ch);
};

//-----------Gets Expression From User------------------------------------------
void stack1::getexp()
{
    cout<<"Enter the Postfix Expression"<<endl;
    cin>>expression;
    expTop=expression.length()-1;
    
}

void stack1::check()
{
    string ch;
    int i=0;
    while(expression[i]!='\0')
    {
        ch=expression[i];

        if(isOperator(ch))
        {
            push(combo(pop(),ch,pop()));
        }
        else
        {
            push(ch);
        }
    }
}

/*
-------------------------------------------------------------------
    Inputs:
    takes 2 values from the stack which will be operands
    either as single characters or whole strings,these
    values will be passed as optr1 and opttr2,it will
    also take operators such as +,-,* etc.. as char.
    these will be passed in place of opr.

    working:
    combines all the passed values into a single string
    into the following format

    ( optr1 opr optr2 )

    and finaly returns this string
----------------------------------------------------------------------
*/

string stack1::combo(string optr1, string optr2, string opr)
{
    string expr;
    
    expr="("+optr1+opr+optr2+")";
    return expr;
}

/*
------------------------------------------------------------------------
    Working:
    pops the top value from the stack
    and returns it.
    decrements the top pointer
    and initializes the poped element to " "
-------------------------------------------------------------------------
*/
string stack1 ::pop()
{
    if (isempty())
    {
        cout << endl
             << "The stack1 is empty" << endl;
        return;
    }
    return stack [stackTop];
    stack [stackTop] = " ";
 stackTop--;
}

void stack1 ::push(string expr)
{
    if (isfull())
    {
        cout << endl
             << "The stack1 is full" << endl;
        return;
    }
 stackTop++;
    stack [stackTop] = expr;
}

bool stack1 ::isempty()
{
    if  (stackTop == -1)
        return true;
    else
        return false;
}

bool stack1 ::isfull()
{
    if  (stackTop == MAX - 1)
        return true;
    else
        return false;
}

bool stack1::isOperator(string ch)
{
    if (ch[0] == '*' || ch[0] == '/' || ch[0] == '+' || ch[0] == '-' || ch[0] == '^')
        return true;
    else return false;
}