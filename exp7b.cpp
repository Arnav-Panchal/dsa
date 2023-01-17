#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define max 10
#define infy 999
class prims
{
int prims[10][3];
int graph[max][max];
int vert;

public:
prims()
{
for(int i=0;i<max;i++)
{
for(int j=0;j<max;j++)
{
graph[i][j]=infy;
}
}
vert=0;
}
void accept()
{
int edge,dest,source,cost;
cout<<"\nEnter Number of vertices: ";
cin>>vert;
cout<<"\nEnter number of edges : ";
cin>>edge;
for(int i=1;i<=edge;i++)
{
cout<<"\nEnter Source Destination cost :";
cin>>source;
cin>>dest;
cin>>cost;
graph[source][dest]=graph[dest][source]=cost;
}
}
void display()
{
cout<<"\nAdjecency Matrix : "<<endl;
cout<<"\n\n";
int s=0;
cout<<"\t";
for(int k=0;k<vert;k++)
{
cout<<s++<<"\t";
}
s=0;
for(int i=0;i<vert;i++)
{
cout<<"\n"<<s++;
for(int j=0;j<vert;j++)
{
cout<<"\t"<<graph[i][j];
}
}
}
void primsalgo()
{
int visited[10];
int EdgesInTree=0,vertex=0;
int min,x,y,cost=0;

for(int i=0;i<10;i++)
visited[i]=0;
visited[0]=1;
while(EdgesInTree<vert-1)
{
min=infy;
for(int i=0;i<vert;i++)
{
if(visited[i])
{
for(int j=0;j<vert;j++)
{
if(visited[j]==0)
{
if(min>graph[i][j])
{
min=graph[i][j];
x=i;
y=j;
}
}
}
}
}
EdgesInTree++;
visited[y]=1;
prims[vertex][0]=x;
prims[vertex][1]=y;
prims[vertex++][2]=graph[x][y];
cost=cost+graph[x][y];
}
cout<<"\nFrom House to house Distance\n";
cout<<"\n----------------------------\n";
for(i=0;i<vertex;++i)
{
for(int j=0;j<3;++j)
cout<<prims[i][j]<<"\t";
cout<<"\n";
}
cout<<"\n----------------------------\n";
cout<<"\nMinimum distance to travel "<<cost;
}
};
int main()
{
prims p1;
int ch=-1;
while(ch!=0)
{
cout<<"\nGraphs";
cout<<"\n1.Create Graph";
cout<<"\n2.Display Graph";
cout<<"\n3.Prims";
cout<<"\0.Exit";
cout<<"\n\nEnter your choice:";
cin>>ch;
switch(ch)
{
case 1:
p1.accept();
break;
case 2:
p1.display();
break;
case 3:
p1.primsalgo();
break;
case 0:
break;
default:
cout<<"\nInvalid option!!";
break;
}
}
getch();
return 0;
}

