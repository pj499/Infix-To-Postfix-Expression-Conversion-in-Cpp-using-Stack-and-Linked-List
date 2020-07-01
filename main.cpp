#include <iostream>
#include<string>
using namespace std;

//=====node class for LinkedList node=====
class node
{
 public:
     char data;
     node* next;
};

//=====Stack class=====
class STACK
{
private:
    node *top;
 
//=====check precedance=====
    int prece(char x)
    {
        if(x=='+' || x=='-')
            return 1;
        else if(x=='*' || x=='/')
            return 2;
        return 0;
    }
 //=====check if stack is empty=====
    int isEmpty()
    {
        return top==NULL?1:0;
    }
 
 
//=====check if stack is full=====
    int isFull()
    {
        node *t=new node;
        return t==NULL?1:0; //if heap size if full, node t will not be created
    }
 
 
//=====get top element of stack=====
    char stacktop()
    {
        return top==NULL?-1:top->data;
    }
 
public:
    STACK() //Stack class constructor
    {
        top=NULL;
    }
    void push(char n);
    char pop();
    void display();
    char* intopost(string s);
};


//=====Push to insert element in stack=====
void STACK::push(char n)
{
    if(isFull())
        cout<<"STACK IS FULL"<<endl;
    else{
        node *t=new node;
        t->data=n;
        t->next=NULL;
        if(top==NULL)
            top=t;
        else{
            t->next=top;
            top=t;
        }
    }
}


//=====Pop to remove element from stack=====
char STACK::pop()
{
    char x=-1;
    if(isEmpty())
        return x;
    else{
        node *q=top;
        top=top->next;
        x=q->data;
        delete q;
    }
    return x;
}


//=====This function converts infix expression to postfix expression=====
char * STACK::intopost(string s)
{
    int i=0,j=0;
    char* res=new char[s.length()+1]; //to store postfix expression
    while(s[i]!='\0')
    {
        if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
        {
           if(prece(s[i])>prece(stacktop())) //check precedance
               push(s[i++]);
           else
            {
                res[j++]=pop();
            }
        }
        else
        {
            res[j++]=s[i++];
        }
    }
    while(top!=NULL)
    {
        res[j++]=pop();
    }
    res[j]='\0';
    return res;
}

int main()
{
    STACK stk;
    string infix;
    cout<<"Enter expression:"<<endl;
    cin>>infix;
    cout<<stk.intopost(infix);

    return 0;
}
