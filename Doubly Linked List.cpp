#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


typedef struct dlink{
	int no;
	struct dlink *next;
	struct dlink *prev;
}node;


void create (node **start, node **end){
	node *temp, *p;
	char ch='y';
	system("cls");
	if (*start != NULL){
		printf("\n\n\t****LIST ALREADY EXISTS****");
		getch();
		return;
	}
	fflush(stdin);
	printf("\n\n\t\t****INPUT BLOCK****\n");
	while (ch=='y'){
		temp=(node *)malloc(sizeof(node));
		printf("\n\t Enter the no:==>");
		scanf("%d",&temp->no);
		temp->next=NULL;
		if(*start==NULL){
			p=*start=temp;
			temp->prev=NULL;
		}
		else{
			p->next=temp;
			temp->prev=p;
			p=temp;
		}
		*end=temp;
		fflush(stdin);
		printf("\n\t Do you want to continue(y/n)?:");
		ch=getchar();
	}
	return;
}


void print(node *start,node *end){
	node *temp;
	system("cls");
	printf("\n\n\t\t **** DISPLAY BLOCK ****\n");
	printf("\n\n\t Base address Number Next Link");
	printf("\n\t ================================");
	for(temp=start;temp!=NULL;temp=temp->next)
		printf("\n %10u %10d %10u",temp,temp->no,temp->next);
	getch();
	printf("\n\n\t End address Number Prev Link");
	printf("\n\t ==================================");
	for (temp=end;temp!=NULL;temp=temp->prev)
		printf("\n %10u %10d %10u",temp,temp->no,temp->prev);
	printf("\n\n\t Press any ey to goto MAIN BLOCK........");
	getch();
	return;
}


//insrting a new node in the beginning
node *insf(node *start,int item){ 
	node *p;
	p=(node *)malloc(sizeof(node));
	p->no=item;
	start->prev=p;
	p->next=start;
	p->prev=NULL;
	start=p;
	printf("\n\n\t Element is sucessfully inserted");
	getch();
	return start;
}


//inserting a new node before a given node
node *insb(int item,int item1,node *start){
	node *temp,*p;
	for(temp=start;temp->no!=item1;temp=temp->next)
		if(temp==NULL){
			printf("\n\n\t No. not found in the linklist");
			getch();
			return start;
		}
	if(temp==start){
		start=insf(start,item);
		return start;
	}
	p=(node *)malloc(sizeof(node));
	p->no=item;
	p->prev=temp->prev;
	p->next=temp;
	temp->prev->next=p;
	temp->prev=p;
	printf("\n\n\t Element is successfully inserted");
	getch();
	return start;
}


//insert a new node after a given node
node *insa(int item,int item1,node *start,node *end){
	node *temp,*p;
	p=(node *)malloc(sizeof(node));
	for(temp=start;temp->no!=item1;temp=temp->next){
		if(temp==NULL){
			printf("\n\n\t No. not found in the linlist");
			getch();
			return end;
		}
	}
	p->no=item;
	p->next=temp->next;
	p->prev=temp;
	if(temp->next!=NULL){
		temp->next->prev=p;
	}
	temp->next=p;
	if (p->next==NULL){
		end=p;
		printf("\n\n\t Element is sucessfully inserted");
		getch();
		return end;
	}	
}


//Deleting the first node in a doubly linked list
node *delf(node *start){
	int item;
	node *tp;
	tp=start;   //preserving address of first node into tp
	item=start->no;
	start=start->next;
	start->prev=NULL;
	printf("\n\n\t Element [%d] is sucessfully deleted from linked list", item);
	free(tp);  //garbage collection
	getch();
	return start;
}


//deleting the last node in a doubly linked list
node *dele(node *end){
	int item;
	item=end->no;
	end=end->prev;
	end->next=NULL;
	printf("\n\n\t Element [%d] is deleted from Linked list",item);
	getch();
	return end;
}


//deleting a particular node in a doubly linked list
void delp(int item, node **start,node **end){
	node *temp,*temp1;
	for(temp=*start;temp->no!=item && temp!=NULL;temp=temp->next){
		temp1=temp;
	}
	if(temp==NULL){
		printf("\n\n\t No. not found in the linklist");
		getch();
		return;
	}
	if(temp->prev==NULL)
		*start=delf(*start);
	else if(temp->next==NULL)
		*end=dele(*end);
	else{
		temp1->next=temp->next;
		temp->next->prev=temp1;
		printf("\n\n\t Element [%d] is deleted from linklist",item);
	}
	return;
}


int main(){
	node *start,*end;
	start=end=NULL;
	int item,item1;
	char ch;
	while (1){
		system("cls");
		printf("\n\n\t\t ****MAIN BLOCK****\n");
		printf("\n\t 1. To create the Doubly Linklist");
		printf("\n\t 2. To display the Doubly linke list");
		printf("\n\t 3. To exit");
		printf("\n\t 4. To insert a new node in the beginning");
		printf("\n\t 5. To insert a new node before a given node");
		printf("\n\t 6. To insert a new node after a given node");
		printf("\n\t 7. To delete the first node in a doubly linked list");
		printf("\n\t 8. To delete the last node in a doubly linked list");
		printf("\n\t 9. To delete a particular node in a doubly linked list");
		printf("\n\n\t Enter your choice ==>");
		ch=getchar();
		switch(ch){
			case '1':
				create(&start,&end);
				break;
			case '2':
				print(start,end);
				break;
			case '3':
				exit(0);
			case '4':
				system("cls");
				printf("\n\n\t Enter the element to be inserted: ");
				scanf("%d",&item);
				start=insf(start,item);
				break;
			case '5':
				system("cls");
				printf("\n\n\t Enter the element to Inserted: ");
				scanf("%d",&item);
				printf("\n\n\t Enter the no. before which to insert: ");
				scanf("%d",&item1);
				start=insb(item,item1,start);
				break;
			case '6':
				system ("cls");
				printf("\n\n\t Enter the element to inserted: ");
				scanf("%d",&item);
				printf("\n\n\t Enter the no. after which to insert: ");
				scanf("%d",&item1);
				end=insa(item,item1,start,end);
				break;
			case '7':
				system("cls");
				start=delf(start);
				break;
			case '8':
				system("cls");
				end=dele(end);
				break;
			case '9':
				system("cls");
				printf("\n\n\t Enter the node to be deleted : ");
                scanf("%d",&item);
                delp(item,&start,&end);
                break;
		}
	}
}

