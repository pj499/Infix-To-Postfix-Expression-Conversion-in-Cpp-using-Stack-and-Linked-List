#include <iostream>
#include<string>
using namespace std;

class node
{
 public:
     char data;
     node* next;
};

class STACK
{
private:
    node *top;
    int prece(char x)
    {
        if(x=='+' || x=='-')
            return 1;
        else if(x=='*' || x=='/')
            return 2;
        return 0;
    }
    int isEmpty()
    {
        return top==NULL?1:0;
    }
    int isFull()
    {
        node *t=new node;
        return t==NULL?1:0;
    }
    char stacktop()
    {
        return top==NULL?-1:top->data;
    }
public:
    STACK()
    {
        top=NULL;
    }
    void push(char n);
    char pop();
    void display();
    char* intopost(string s);
};

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

char * STACK::intopost(string s)
{
    int i=0,j=0;
    char* res=new char[s.length()+1];
    while(s[i]!='\0')
    {
        if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
        {
           if(prece(s[i])>prece(stacktop()))
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
