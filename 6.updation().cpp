//Write a program to read 4 values of any data types in the function main() & pass them to a function updation(). In the called function raise the values of the first and last variable by 4 times and lower the values of the second and third by half. Now print the updated values back in the calling function main().
//calling function by refference
#include<bits/stdc++.h>
using namespace std;
void updation(int *a,int *b,int *c,int *d){
	*a*=4;
	*b/=2;
	*c/=2;
	*d*=4;
}
int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	updation(&a,&b,&c,&d);
	cout<<a<<" "<<b<<" "<<c<<" "<<d;
}
