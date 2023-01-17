#include<iostream.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
class test
{
public:
int SIZE;
int stack[50];
int top,nn;
char s[50];
test()
{
SIZE=50;
}
void push(char ch)
{
if(top==SIZE-1)
{
cout<<"\n\tSTACK is over flow";
}
else
{
top++;
stack[top]=ch;
}
}
char pop()
{
cout<<"\n\tSTACK is under flow";
return(-1);
}
else
{
char ch= stack[top];
top--;
return (ch);
}
}
void calculate()
{
int n1,n2,n3,i;
i=0;
while(s[i])
{
if(s[i]==' '||s[i]=='\t')
{
i++;
continue;
}
if(isdigit(s[i]))
{
nn=s[i]-'0';
push(nn);
}
else
{
n1=pop();
n2=pop();
switch(s[i])
{
case '+':
n3=n2+n1;
break;
case '-':
n3=n2-n1;
break;
case '/':
n3=n2/n1;
break;
case '*':
n3=n2*n1;
break;
case '%':
n3=n2%n1;
break;
case '$':
n3=pow(n2,n1);
break;
default:
cout<<"Unknown operation";
exit(1);
}
push(n3);
}
i++;
}
cout<<"\tResult is :"<<n3;
}
};
int main()
{
test obj;
obj.top=-1;
cout<<"/nEnter an expression in postfix form:  ";
cin>>obj.s;
obj.calculate();
getch();
return 0;
}

