#include<iostream.h> 
#include<conio.h> 
#include<stdlib.h> 
#include<string.h> 
class NodeTbt 
{ 
friend class TBT; 
private: 
int data; 
NodeTbt *left; 
NodeTbt *right; 
int lthread; 
int rthread; 
public: 
NodeTbt(); 
NodeTbt(int val); 
}; 
NodeTbt::NodeTbt() 
{ 
left=NULL; 
right=NULL; 
lthread=1; 
rthread=1; 
data=0; 
} 
NodeTbt::NodeTbt(int val) 
{ 
left=NULL; 
right=NULL; 
lthread=1; 
rthread=1; 
data=val; 
} 
class TBT 
{ 
private: 
NodeTbt *root; 
void setLeftChild(int val, NodeTbt *temp); 
void setRightChild(int val, NodeTbt *temp); 
public: 
TBT(); 
void insert(int val); 
void inOrderTraversal(); 
void preOrderTraversal(); 
void postOrderTraversal(); 
NodeTbt *post_succ(NodeTbt *); 
}; 
TBT::TBT() 
{ 
root=NULL; 
} 
void TBT::insert(int val) 
{ 
NodeTbt *temp; 
char dir; 
if (root==NULL) 
{ 
root=new NodeTbt(val); 
cout<<endl<<"\n Created TBTree...with root= "<<val; 
} 
else 
{ 
temp=root; 
while(temp !=NULL) 
{ 
cout<<"\nDo you want to insert"<<val<<"to left/right of "<<temp->data; 
cin>>dir; 
if (dir=='l'||dir=='L') 
{ 
if(temp->lthread==1) 
{ 
setLeftChild(val,temp); 
break; 
} 
else 
temp=temp->left; 
} 
else if(dir=='r'||dir=='R') 
{ 
if(temp->rthread==1) 
{ 
setRightChild(val,temp); 
break; 
} 
else 
temp=temp->right; 
} 
} 
} 
} 
void TBT::setLeftChild(int val,NodeTbt *temp) 
{ 
if(temp==NULL) 
cout<<"\nInvalid Insertion"; 
if(temp->lthread==0) 
cout<<"\nInvalid Insertion"; 
else 
{ 
NodeTbt *pNew; 
pNew=new NodeTbt(val); 
pNew->left=temp->left; 
pNew->right=temp; 
temp->lthread=0; 
temp->left=pNew; 
} 
} 
void TBT::setRightChild(int val, NodeTbt *temp) 
{ 
if(temp==NULL) 
cout<<"\nInvalid Insertion"; 
if(temp->rthread==0) 
cout<<"\nInvalid Insertion"; 
else 
{ 
NodeTbt *pNew; 
pNew=new NodeTbt(val); 
pNew->right=temp->right; 
pNew->left=temp; 
temp->rthread=0; 
temp->right=pNew; 
} 
} 
void TBT::inOrderTraversal() 
{ 
NodeTbt *temp; 
temp=root; 
while(temp->lthread !=1) 
{ 
temp=temp->left; 
} 
while(temp!=NULL) 
{ 
cout<<temp->data<<" "; 
if(temp->rthread==1) 
temp=temp->right; 
else 
{ 
temp=temp->right; 
while(temp->lthread !=1) 
{ 
temp=temp->left; 
} 
} 
} 
} 
void TBT::preOrderTraversal() 
{ 
NodeTbt *temp=root; 
while(temp!=NULL) 
{ 
cout<<temp->data<<" "; 
if(temp->lthread!=1) 
temp=temp->left; 
else 
{ 
if(temp->rthread==0) 
temp=temp->right; 
else 
{ 
while(temp->rthread==1) 
temp=temp->right; 
temp=temp->right; 
} 
} 
} 
} 
int main() 
{ 
TBT tr; 
int n; 
cout<<"\nHow many values do you want to insert:"; 
cin>>n; 
for(int i=0;i<n;i++) 
{ 
int val; 
cout<<"\nEnter value:"; 
cin>>val; 
tr.insert(val); 
} 
cout<<"\nInOrder traversal of Tree is:"; 
tr.inOrderTraversal(); 
cout<<"\nPreOrder traversal of Tree is:"; 
tr.preOrderTraversal(); 
getch(); 
return 0; 
}
