#include<iostream.h> 
#include<conio.h> 
void heapify(int a[],int n,int i) 
{ 
int largest = i; 
int left = 2*i+1; 
int right = 2*i+2; 
if(left < n&& a[left] > a[largest]) 
largest = left; 
if(right < n&& a[right] > a[largest]) 
largest = right; 
if(largest!=i) { 
int temp = a[i]; 
a[i] = a[largest]; 
a[largest] = temp; 
heapify(a,n,largest); 
} 
} 
void heapSort(int a[],int n) 
{ 
for(int i = n/2-1;i>=0;i--) 
heapify(a,n,i); 
for (i=n-1;i>=0;i--) { 
int temp = a[0]; 
a[0] = a[i]; 
a[i] = temp; 
heapify(a,i,0); 
} 
} 
void printArr(int a[],int n) 
{ 
for (int i=0;i<n;++i) 
{ 
cout<<a[i]<<" "; 
} 
} 
int main() 
{ 
int a[] = {47,9,22,42,27,25,0}; 
int n = sizeof(a)/sizeof(a[0]); 
cout<<"Before sorting array elements are-\n"; 
printArr(a,n); 
heapSort(a,n); 
cout<<"\nAfter sorting array elements are - \n"; 
printArr(a,n); 
getch(); 
return 0; 
} 
