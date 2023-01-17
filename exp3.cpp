#include<iostream.h> 
#include<conio.h> 
#include<stdlib.h> 
# define max 6 
int queue[max]; 
int front=-1; 
int rear=-1; 
void enqueue(int element) 
{ 
if(front==-1&&rear==-1) 
{ 
front=0; 
rear=0; 
queue[rear]=element; 
} 
else if((rear+1)%max==front) 
{ 
cout<<"Queue is overflow.."; 
} 
else 
{ 
rear=(rear+1)%max; 
queue[rear]=element; 
} 
} 
int dequeue() 
{ 
if((front==-1)&&(rear==-1)) 
{ 
cout<<"\nQueue is underflow.." ; 
} 
else if(front==rear) 
{ 
cout<<"\nThe dequeued element is"<<queue[front]; 
front=-1; 
rear=-1; 
} 
else 
{ 
cout<<"\nThe dequeued element is "<<queue[front]; 
front=(front+1)%max; 
} 
} 
void display() 
{ 
int i=front; 
if(front==-1&&rear==-1) 
{ 
cout<<"\nQueue is empty.."; 
} 
else 
{ 
cout<<"\nElements in a Queue are:"; 
while(i<=rear) 
{ 
cout<<queue[i]; 
i=(i+1)%max; 
} 
} 
} 
int main() 
{ 
int choise=1,x; 
while(choise<4&&choise!=0) 
{ 
cout<<"\nPress 1: insert an element"; 
cout<<"\nPress 2: Delete an element"; 
cout<<"\nPress 3: Display the element"; 
cout<<"\nEnter your choise"; 
cin>>choise; 
switch(choise) 
{ 
case 1: 
cout<<"\nEnter the element which is to be inserted"; 
cin>>x; 
enqueue(x); 
break; 
case 2: 
dequeue(); 
break; 
case 3: 
display(); 
} 
} 
return 0; 
}
