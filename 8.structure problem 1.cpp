//Create a structure specification related to the band's scores by a student appearing for IELTS tests thrice with the following members –
//char reg_no[15] ;
//float bnd1,bnd2,bnd3 ;
//read the values and pass the structure to a function that calculates and returns the average band score.
#include<stdio.h>
struct scores{
	char reg_no[15];
	float bnd1,bnd2,bnd3;
} marks;
float avgr(struct scores marks){
	return (marks.bnd1+marks.bnd2+marks.bnd3)/3;
}
int main(){
	printf("Enter name:");
	scanf("%s",marks.reg_no);
	printf("Enter values:");
	scanf("%f%f%f",&marks.bnd1,&marks.bnd2,&marks.bnd3);
	float avg=avgr(marks);
	printf("%s average is %0.2f",marks.reg_no,avg);
}
