#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct clist{
	int data;
	struct clist *link;
};
typedef struct clist node;


node * create(node *start){
	node *temp, *ptr;  //ptr will be used to store the address of previous node
	char ch;
	int num;
	do{
		printf("\n\t Enter the value of number : ");
		scanf("%d",&num);
		temp =(node*)malloc(sizeof(node));
		temp->data=num;
		if (start==NULL){
			start=temp;
			ptr=start;
		}
		else{
			ptr->link=temp;
			ptr=ptr->link;  //ptr=temp
		}
		temp->link = start;
		printf("\n\t Do you want to add more nodes (y/n) : ");
		fflush(stdin);
		scanf("%c",&ch);
	}
	while(ch=='y'||ch=='Y');
	return (start);
}


//Inserting a new node in the beginning of a circular linked list
node* insertbeg(node *start){
	node *temp,*end,*ptr;
	int num;
	char ch;
	ptr=start;
	do{
		end=ptr;
		ptr=ptr->link;
	}while(ptr!=start);
	printf("\n\n\t Enter the number to insert: ");
	scanf("%d",&num);
	temp=(node*)malloc(sizeof(node));
	temp->data=num;
	temp->link=start;
	end->link=temp;
	start=temp;
	return (start);
}


node *search(node *start,int num){
	node *temp,*loc;
	loc=NULL;
	temp=start;
	do{
		if(num==temp->data){
			loc=temp;
			break;
		}
		temp=temp->link;
	}while(temp!=start);
	return(loc);
}


//Inserting a new node after a particular node in circular linked list
void insertafter(node *start){
	node *temp,*loc;
	int num,data;
	printf("\n\n\t Enter the no. after which you want to insert: ");
	scanf("%d",&data);
	loc=search(start,data);
	if(loc==NULL){
		printf("\n\t The number is not present in the linklist");
	}
	else{
		printf("\n\n\t Enter the number to be inserted: ");
		scanf("%d",&num);
		temp=(node*)malloc(sizeof(node));
		temp->data=num;
		temp->link=loc->link;
		loc->link=temp;
	}
}


//Program to delete a aprticular node in a circular linked list
node* del(node *start){
	node *temp,*ptr,*end,*loc,*i;
	char ch;
	int num;
	loc=start;
	do{
		end=loc;
		loc=loc->link;
	}while(loc!=start);
	printf("\n\n\t Enter the number you want to delete: ");
	scanf("%d",&num);
	i=search(start,num);
	if(i==NULL){
		printf("\n\n\t This number does not exist in list");
		getch();
		return(start);
	}
	temp=start;
	do{
		if(temp==start && temp->link==start && temp->data==num){    //only one node in the circular linked list
			free(start);
			start=NULL;
			break;
		}
		else if(temp==start && temp->data==num){    //fisrt node but not only single node
			ptr=start;
			start=start->link;
			end->link=start;
			free(ptr);    //deallocation or garbage collection
			break;
		}
		else if(temp->link->data==num){
			ptr=temp->link;
			temp->link=temp->link->link;
			free(ptr);
			break;
		}
		else if(temp->link->link==start && temp->link->data==num){
			ptr=temp->link;
			temp->link=start;
			free(ptr);
		}
		temp=temp->link;  //updating temp
	}while(temp!=start);  //end of inner loop
	return (start);
}


void display(node *start){
	node *temp;
	printf("\n\n Base address Number Link");
	printf("\n ===========================");
	printf("\n%10u %10d %10u",start,start->data,start->link);
	for(temp=start->link;temp!=start;temp=temp->link)
	printf("\n%10u %10d %10u",temp,temp->data,temp->link);
	getch();
	return;
}


int main(){
	node *start;
	int choice,num,data;
	char ch;
	start=NULL;
	while(1){
		system("cls");
		fflush(stdin);
		printf("\n\t\t **** MAIN BLOCK ****\n");
		printf("\n\t 1. To Create the Circular Linklist");
		printf("\n\t 2. To insert in the beginning");
		printf("\n\t 3. To Display the Circular Linklist");
		printf("\n\t 4. Exit");
		printf("\n\t 5. To insert after a given node");
		printf("\n\t 6. To delete a given node");
		printf("\n\n\t Enter your choice ==> ");
		scanf("%d",&choice);
		system("cls");
		switch(choice){
			case 1:
				printf("\n\t\t **** CREATE BLOCK ****\n");
				start = create (start);
				break;
			case 2:
				start=insertbeg(start);
				break;
			case 3:
				printf("\n\t\t **** DISPLAY BLOCK ****\n");
				display(start);
				break;
			case 4:
				exit(0);
			case 5:
				insertafter(start);
				break;
			case 6:
				start=del(start);
				break;
		}
	}
}
