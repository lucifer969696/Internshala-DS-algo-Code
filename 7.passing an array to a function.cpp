//Write a program that passes an array to a function. Return the number of even elements.
//passing array to a function
//by reference
#include<bits/stdc++.h>
using namespace std;
void array(int *pnt){
	for (int i=0;i<5;i++){
		if(*(pnt+i)%2==0){
			cout<<*(pnt+i)<<endl;
		}
	}
}
int main(){
	int arr[5]={10,21,30,41,50};
	array(arr);
}
