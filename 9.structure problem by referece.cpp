//Create a structure specification related to the band's scores by a student appearing for IELTS tests thrice with the following members �
//char reg_no[15] ;
//float bnd1,bnd2,bnd3;
//read the values and pass the structure to a function using call by reference that calculates and returns the average band score.
/*#include<stdio.h>
struct score{
	char reg_no[15] ;
	float bnd1,bnd2,bnd3;
} first;
float average(struct score *xx){
	float avg=((xx->bnd1 + xx->bnd2 + xx->bnd3)/3);
	return avg;
}
int main(){
	printf("Enter name:");
	scanf("%s",first.reg_no);
	printf("Enter numbers:");
	scanf("%u%u%u",&first.bnd1,&first.bnd2,&first.bnd3);
	float avg=average(&first);
	printf("%s average is %f",first.reg_no,avg);
}*/
#include <stdio.h>

// following is the structure specification(GLOBAL SCOPE) with declaration of 4 members
	struct IELTS
	{
		char reg_no[15];
		float bnd1,bnd2,bnd3 ;
	} ;
int main()
{
	struct IELTS ivar ; // declaration of structure variable
	
	/* following is the prototype of the function score_avg()
	float is the return type of the function as we will be returning average
	score band and "struct IELTS *" is the data type of the passing argument 
	as we will be passing the address of the structure and not value
	*/
	float score_avg(struct IELTS *);
	float band_avg ; // declaration of variable that will collect average 
	// reading the registration number & bands scored in 3 IELTS tests
	printf("Enter the registration number & IELTS bands scored in 3 tests");
	gets(ivar.reg_no);    
	scanf("%f%f%f",&ivar.bnd1,&ivar.bnd2,&ivar.bnd3); 
	band_avg=score_avg(&ivar) ;  // calling the function by reference 
    printf("Average of bans scored = %.2f",band_avg);
    	}	//end of definition of the function main()
    	
    	// following is the definition of the function score_avg()
    	float score_avg(struct IELTS *dvar)   // dvar is the pointer formal parameter as this is call by reference
		{
		/* in the following statement we are using arrow operator as dvar is not a strcuture
		but 'pointer to structure' */ 
			float avg = (dvar->bnd1 + dvar->bnd2 + dvar->bnd3)/3 ;
		return avg ;	
		   }   
