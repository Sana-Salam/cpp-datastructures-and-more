#include<iostream>
#include<stack>
using namespace std;
bool is_Operator(char c)
 {
     if( c=='+' || c=='-' || c== '*' || c=='/' || c=='^')
         return true ;
     else
         return false;

}
int precedence(char c)
{
    if(c=='^') return 3;
    else if(c=='/'||c=='*')  return 2;
    else if(c == '+' || c== '-')  return 1;
    else return -1;
}
string infix_postfix(stack <char> *s , string infix)
{     // function for converting infix to postfix
    string postfix;

    for(int i = 0; i<infix.length() ;i++)
    {
        if((infix[i]>='a' && infix[i]<='z') || (infix[i]>='A' && infix[i]<= 'Z'))
        {
            postfix+= infix[i];
        }
        else if(infix[i] == '(')
        {
            s->push(infix[i]);
        }
        else if(infix[i] = ')')
        {
          while((s->top()!= '(' ) && (!s->empty()))
          {
              postfix+= s->top();
              s->pop();
        }
        }
        else
       if(is_Operator(infix[i]))
        {
            if(s->empty())
            {
                s->push(infix[i]);
            }
            else
         if(precedence(infix[i])> precedence(s->top()))
                {
                    s->push(infix[i]);
                }
        else
      if((precedence(infix[i])== precedence(s->top())) && (s->top()=='^'))
                {
                s->push(infix[i]);
                }
                else
                {
                    while((!s->empty() )&& (precedence(infix[i])<= (precedence(s->top()))))
                    {
                        postfix+=s->top();
                        s->pop();
                    }
                    s->push(infix[i]);
                }
            }
     while(!s->empty())
     {
        postfix+= s->top();
        s->pop();
    }}
    return postfix;
}
int main()
{
    stack <char> *st;
    string inFix , postFix;
    cout<<"\n enter infix expression \n ";
    cin>>inFix;
    postFix = infix_postfix(st , inFix);
    cout<<"\n postfix expression is"<<postFix;

}
