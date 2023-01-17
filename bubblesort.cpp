#include<iostream.h> 
#include<conio.h> 
int main() 
{ 
 int num,i,arr[50],j,temps; 
 cout<<"Enter no of students"; 
 cin>>num; 
 cout<<"Enter student Roll no"; 
 for(i=0;i<num;i++) 
 { 
 cin>>arr[i]; 
 } 
 cout<<"Bobble Sort"; 
 for(i=0;i<num;i++) 
 { 
 for(j=0;j<num-i;j++) 
 { 
 if(arr[j]>arr[j+1]) 
 { 
 temps = arr[j]; 
 arr[j]=arr[j+1]; 
 arr[j+1]=temps; 
 } 
 } 
 } 
 cout<<"Sorted Roll Call"; 
 for(i=0;i<num;i++) 
 { 
 cout<<arr[i]<<endl; 
 } 
 getch(); 
 return 0; }