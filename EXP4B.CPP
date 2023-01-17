#include<conio.h> 
#include<iostream.h> 
#include<stdio.h> 
#include<stdlib.h> 
typedef struct node{ 
char data; 
struct node*left,*right; 
}node; 
char*add(node**p,char*a) 
{ 
if(*a=='\0') 
return '\0'; 
while(1){ 
char* q="null"; 
if(*p==NULL){ 
node* nn=(node*)malloc(sizeof(node)); 
nn->data=*a; 
nn->left=NULL; 
nn->right=NULL; 
*p=nn; 
} 
else{ 
if(*a>='a'&&*a<='z'){ 
return a; 
} 
q=add(&(*p)->left,a+1); 
q=add(&(*p)->right,q+1); 
return q; 
} 
} 
} 
void inr(node*p) 
{ 
if(p==NULL){ 
return; 
} 
else{ 
inr(p->left); 
cout<<p->data; 
inr(p->right); 
} 
} 
void postr(node*p) 
{ 
if(p==NULL){ 
return; 
} 
else{ 
postr(p->left); 
postr(p->right); 
cout<<p->data; 
} 
} 
int main() 
{
clrscr();
node*s=NULL; 
char a[]="*+ab-cd"; 
add(&s,a); 
cout<<"The infix expression is :\n"; 
inr(s); 
cout<<"\n"; 
cout<<"The postfix expression is :\n"; 
postr(s); 
getch(); 
return 0; 
} 