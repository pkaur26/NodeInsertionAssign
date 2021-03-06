#include <stdio.h>
#include <stdlib.h>
//defining a struct
struct node 
{
char name[100];
struct node *next;
};
//function declarations
void insertBegin(char name[100]);
void insertEnd(char name[100]);
void print_List(void);
void remove_First(void);
//introducing head pointer of type node
struct node *head=NULL;

//main method
int main(){
	int casE,total=0; 
	char name[100];
	//asking user to select the case
	printf("Select From the following options; Type end to stop:\n");
	printf("1. Insertion at the Beginning of the list \n");
	printf("2. Insertion at the End of the list\n");
	scanf("%d",&casE);
	getchar();
	int num;
	while(num=1){ 
		printf("\nEnter the Name of your friend:");
		gets(&name);
		//till the user enters the name
		if(strcmp(name,"end")== 0) { 
            break;
		}
		//when end is typed
		else{
			//increementing the count on names
		total++; 
		printf("Name Inserted!");
			//as per the chosen switch, method been called
			switch (casE){ 
			case 1:
			insertBegin(name);
			break;
			case 2:
			insertEnd(name);
			}
		}

	}
       //calling print method to print the list 
	
		print_List(); 
		printf("\nTotal Number of Friends: %d",total);
		printf("\nRemoving First element from the list.");
	//calling the method to remove the first name from the list
		remove_First(); 
	//printing after removal
		print_List();
	return 0;
}

//method to insert at the beginning
void insertBegin(char name[100]){
	//pointer of type node
		struct node *newNode;
	//allocating memory
		newNode = (struct node*)malloc(sizeof(struct node));
		strcpy(newNode->name,name);
 		
		newNode->next = head; 
		head=newNode; 
}

//method to insert at the end
void insertEnd(char name[100]){
struct node *newNode;
newNode = (struct node*)malloc(sizeof(struct node));
strcpy(newNode->name,name);
newNode->next = NULL;
	if(head==NULL){
	head=newNode;
	}
	else{
		// pointer of type node
	struct node *temp= head;
		while(temp->next!=NULL){
		temp=temp->next;
		}
		temp->next=newNode; 
	}
}

//method to print the list
void print_List(void){
	if(head==NULL){
	printf("\n List is Empty!!!");
	}
	else{
	struct node *temp =head;
	printf("\nThe List is : ");
	while(temp!=NULL){ 
			printf("%s-->",temp->name); 
			temp=temp->next;
	}
		free(temp);
	}
}

//method to remove the first element
void remove_First(void){
	if(head==NULL){
	printf("\n List is Empty!!!");
	}
	else{
		head=head->next;
	}
}

