#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//STRUCTURE OF LINKED LIST

struct Node {
	int data;
	struct Node *next;
}*head;

//CREATION

void create_list(int size) {
	struct Node *newNode,*temp;
	int data, i;
	head=(struct Node*)malloc(sizeof(struct Node));
	if(head==NULL) {
		printf("Memory not allocated!\n");
	}
	printf("Enter the data for the node 1: ");
	scanf("%d",&data);
	head->data=data;
	head->next=NULL;
	temp=head;
	for(i=2; i<=size; i++) {
		newNode=(struct Node*)malloc(sizeof(struct Node));
		if(newNode==NULL) {
			printf("Unable to allocate the memory");
			break;
		}
		printf("enter the data of New Node %d: ", i);
		scanf("%d",&data);
		newNode->data=data;
		newNode->next=NULL;
		temp->next=newNode;
		temp=temp->next;
	}
}

//INSERTION

void insertion_start() {
	if(head==NULL) printf("Create a list first\n");
	else {
		int num;
		struct Node *new_Node;
		printf("Enter an element you want to add at the start of the list : ");
		scanf("%d",&num);
		new_Node=(struct Node*)malloc(sizeof(struct Node));
		new_Node->data=num;
		if(head==NULL) {
			head->next=new_Node;
			new_Node->next=NULL;
			printf("Element succesfully added!\n");
		} else {
			new_Node->next=head;
			head=new_Node;
			printf("Element succesfully added!\n");
		}
	}
}

void insertion_middle(int size) {
	if(head==NULL) printf("Create a list first\n");
	else {
		int i=0,mid=size/2,num;
		struct Node *current,*prev;
		current=head;
		while(current) {
			prev=current;
			current=current->next;
			++i;
			if(i==mid) break;
		}
		struct Node *new_Node=(struct Node*)malloc(sizeof(struct Node));
		new_Node->next=prev->next;
		printf("Enter the element you want to enter at the middle: ");
		scanf("%d",&num);
		new_Node->data=num;
		prev->next=new_Node;
		printf("Element succesfully added!\n");
	}
}

void insertion_end(int size) {
	if(head==NULL) printf("Create a list first\n");
	else {
		int num,i=0;
		struct Node *new_Node, *temp=head;
		printf("Enter an element you want to add at the end of the list : ");
		scanf("%d",&num);
		new_Node=(struct Node*)malloc(sizeof(struct Node));
		new_Node->data=num;
		while(i!=size+1) {
			if(temp->next==NULL) {
				temp->next=new_Node;
				new_Node->next=NULL;
				break;
			}
			temp=temp->next;
			++i;
		}
		printf("Element succesfully added!\n");
	}
}

void insertion_particular_element() {
	if(head==NULL) printf("Create a list first\n");
	else {
		int element_find,element_add,ctr=0;
		struct Node *temp,*new_Node;
		temp=head;
		printf("Enter the element you want after the particular element\n");
		scanf("%d",&element_find);
		printf("Enter the element you want to add\n");
		scanf("%d",&element_add);
		while(temp) {
			if(temp->data==element_find) {
				new_Node=(struct Node*)malloc(sizeof(struct Node));
				new_Node->data=element_add;
				new_Node->next=temp->next;
				temp->next=new_Node;
				++ctr;
				break;
			}
			temp=temp->next;
		}
		if(ctr==0) printf("Element not found!\n");
		else printf("Element succesfully added!\n");
	}
}

void insertion_particular_node(int size) {
	if(head==NULL) printf("Create a list first\n");
	else {
		int element_add,number_of_node,ctr=0;
		struct Node *temp, *newNode;
		temp=head;
		printf("Enter the number of node you want the element after\n");
		scanf("%d",&number_of_node);
		if(number_of_node>size || number_of_node<=0) printf("Enter a valid node!\n");
		else {
			while(ctr!=number_of_node-1) {
				temp=temp->next;
				++ctr;
			}
			printf("Enter the element you want to add after the node\n");
			scanf("%d",&element_add);
			newNode=(struct Node*)malloc(sizeof(struct Node));
			newNode->data=element_add;
			newNode->next=temp->next;
			temp->next=newNode;
			printf("Element succesfully added!\n");
		}
	}
}

//DELETION

void deletion_start() {
	if(head==NULL) printf("Create a list first\n");
	else {
		struct Node *temp;
		temp=head;
		temp=temp->next;
		head=temp;
	}
}

void deletion_middle(int size) {
	if(head==NULL) printf("Create a list first\n");
	else {
		int i=0,mid=size/2;
		struct Node *current,*prev;
		current=head;
		while(current) {
			prev=current;
			current=current->next;
			++i;
			if(i==mid) break;
		}
		prev->next=current->next;
		printf("Element deleted succesfully!\n");
	}
}

void deletion_end() {
	if(head==NULL) printf("Create a list first\n");
	else {
		struct Node *current,*prev;
		current=head;
		while(current->next!=NULL) {
			prev=current;
			current=current->next;
		}
		prev->next=NULL;
		printf("Element deleted succesfully!\n");
	}
}

void deletion_particular_element() {
	if(head==NULL) printf("Create a list first\n");
	else {
		int element,ctr=0;
		struct Node *current,*prev;
		current=head;
		printf("Enter the element you want to delete\n");
		scanf("%d",&element);
		while(current->data!=element) {
			prev=current;
			current=current->next;
			++ctr;
		}
		prev->next=current->next;
		if(ctr==0) printf("Element not found!\n");
		else printf("Element deleted successfully!\n");
	}
}

void deletion_particular_node(int size) {
	if(head==NULL) printf("Create a list first\n");
	else {
		int i=0,num;
		struct Node *current,*prev;
		current=head;
		printf("Enter the number of node you want to delete\n");
		scanf("%d",&num);
		if(num<size || num<=0) printf("Enter a valid node!\n");
		else {
			if(num==1) deletion_start();
			else {
				while(current) {
					prev=current;
					current=current->next;
					++i;
					if(i==num-1) break;
				}
				prev->next=current->next;
				printf("Node deleted succesfully!\n");
			}
		}
	}
}

//DISPLAY

void traverse_list() {
	struct Node *current;
	if(head==NULL) {
		printf("List is empty!\n");
	} else {
		current=head;
		printf("The data will be as following: \n");
		while(current!=NULL) {
			printf("%d\t", current->data);
			current = current->next;
		}
		printf("\n");
	}
}

void reverse_traverse_list(int size) {
	if(head==NULL) {
		printf("List is empty!\n");
	} else {
		int i,j;
		struct Node *current;
		current=head;
		printf("Reverse list will be as follows: \n");
		for(i=size; i>0; --i) {
			for(j=i-1; j>0; --j) {
				current=current->next;
			}
			printf("%d\t",current->data);
			current=head;
		}
		printf("\n");
	}
}

void after_element() {
	if(head==NULL) printf("Create a list first\n");
	else {
		int element;
		struct Node *current;
		current=head;
		printf("Enter the element you want to see the elements after\n");
		scanf("%d",&element);
		printf("Elements after %d will be: \n",element);
		while(current->data!=element) {
			current=current->next;
		}
		current=current->next;
		while(current!=NULL) {
			printf("%d\t",current->data);
			current=current->next;
		}
		printf("\n");
	}
}

void before_element() {
	if(head==NULL) printf("Create a list first\n");
	else {
		int element,ctr=0;
		struct Node *block,*current;
		block=head;
		current=head;
		printf("Enter the element you want to see the elements before\n");
		scanf("%d",&element);
		while(block->data!=element) {
			block=block->next;
			++ctr;
		}
		block=block->next;
		if(ctr==0) printf("Element not found!\n");
		else {
			printf("Elements before %d will be: \n",element);
			while(current->next!=block) {
				printf("%d\t",current->data);
				current=current->next;
			}
			printf("\n");
		}
	}
}

void traverse_particular_node(int size) {
	if(head==NULL) printf("Create a list first\n");
	else {
		int number,i=0;
		struct Node *current, *start;
		start=head;
		printf("Enter the number of node you want to traverse from\n");
		scanf("%d",&number);
		if(number>size || number<=0) printf("Enter a valid node!\n");
		else {
			printf("list from %d node will be\n",number);
			while(start) {
				start=start->next;
				++i;
				if(i==number) break;
			}
			current=start;
			while(current!=NULL) {
				printf("%d\t",current->data);
				current=current->next;
			}
			printf("\n");
		}
	}
}

void reverse_traverse_particular_node(int size) {
	if(head==NULL) printf("Create a list first\n");
	else {
		int i,j,number;
		struct Node *current;
		current=head;
		printf("Enter the number of node you want to reverse travel from\n");
		scanf("%d",&number);
		if(number>size || number<=0) printf("Enter a valid node!\n");
		else {
			printf("Reversed list from %d node will be\n",number);
			for(i=number; i>0; --i) {
				for(j=i-1; j>0; --j) {
					current=current->next;
				}
				printf("%d\t",current->data);
				current=head;
			}
			printf("\n");
		}
	}
}

//SORTING

void sort_ascending(int size) {
	if(head==NULL) printf("Create a list first\n");
	else {
		int temp,i,j;
		struct Node *current, *prev;
		current=head;
		prev=head;
		for(i=0; i<size; ++i) {
			for(j=i; j<size; ++j) {
				if(prev->data>current->data) {
					temp=prev->data;
					prev->data=current->data;
					current->data=temp;
				}
				current=current->next;
			}
			prev=prev->next;
			current=prev;
		}
		printf("Sorted succesfully!\n");
	}
}

void sort_descending(int size) {
	if(head==NULL) printf("Create a list first\n");
	else {
		int temp,i,j;
		struct Node *current, *prev;
		current=head;
		prev=head;
		for(i=0; i<size; ++i) {
			for(j=i; j<size; ++j) {
				if(prev->data<current->data) {
					temp=prev->data;
					prev->data=current->data;
					current->data=temp;
				}
				current=current->next;
			}
			prev=prev->next;
			current=prev;
		}
		printf("Sorted succesfully!\n");
	}
}

//MISCELLANEOUS

int remove_duplicate(int size) {
	if(head==NULL) printf("Create a list first\n");
	else {
		int temp,i,j,ctr=0;
		struct Node *check, *current, *prev;
		check=head;
		while(check!=NULL) {
			prev=check;
			current=check->next;
			while(current!=NULL) {
				if(check->data==current->data) {
					prev->next=current->next;
					++ctr;
				} else {
					prev=current;
				}
				current=current->next;
			}
			check=check->next;
		}
		printf("Succesfully removed duplicates!\n");
		return ctr;
	}
}

void rotate() {
	if(head==NULL) printf("Create a list first\n");
	else {
		int num,i=0;
		struct Node *temp,*last;
		last=head;
		temp=head;
		printf("Enter the number of nodes you want to rotate: ");
		scanf("%d",&num);
		while(last->next!=NULL) {
			last=last->next;
		}
		while(temp) {
			temp=temp->next;
			++i;
			if(i==num-1) break;
		}
		last->next=head;
		head=temp->next;
		temp->next=NULL;
		printf("Successfully rotated list!\n");
	}
}

void reverse_list() {
	if(head==NULL) printf("Create a list first\n");
	else {
		struct Node *prev,*current,*next;
		current=head;
		while(current!=NULL) {
			next=current->next;
			current->next=prev;
			prev=current;
			current=next;
		}
		head=prev;
		printf("Successfully reversed list!\n");
	}
}

int remove_odd() {
	if(head==NULL) printf("Create a list first\n");
	else {
		int ctr=0;
		struct Node *current,*prev;
		current=head;
		prev=head;
		while(current!=NULL) {
			if(head->data%2!=0) {
				deletion_start();
				++ctr;
			} else if(current->data%2!=0) {
				prev->next=current->next;
				++ctr;
			} else {
				prev=current;
			}
			current=current->next;
		}
		printf("Removed odd elements from the list!\n");
		return ctr;
	}
}

int remove_even() {
	if(head==NULL) printf("Create a list first\n");
	else {
		int ctr=0;
		struct Node *current,*prev;
		current=head;
		prev=head;
		while(current!=NULL) {
			if(head->data%2==0) {
				deletion_start();
				++ctr;
			} else if(current->data%2==0) {
				prev->next=current->next;
				++ctr;
			} else {
				prev=current;
			}
			current=current->next;
		}
		printf("Removed even elements from the list!\n");
		return ctr;
	}
}

//MAIN

int main() {
	int size,Q=-1,ctr=0;
	printf(" SINGLE LINKED LIST!\n");
	printf(" LIST OF OPERATIONS YOU CAN PERFORM \n");
	printf(" CREATION\n 01: Create List\n");
	printf(" INSERTION\n 02: Insert an element at start\n 03: Insert an element at middle\n 04: Insert an alement at end\n 05: Insert an element after a particular element\n 06: Insert an element after a particular node\n");
	printf(" DELETION\n 07: Delete an element at start\n 08: Delete an element at middle\n 09: Delete an element at end\n 10: Delete a particular element\n 11: Delete a particular node\n");
	printf(" DISPLAY\n 12: Display list\n 13: Reverse Display list\n 14: Display elements after an element\n 15: Display elements before an element\n 16: Display list from a particular node\n 17: Reverse Display list from a particular node\n");
	printf(" SORTING\n 18: Sort the list in ascending order\n 19: Sort the list in descending order\n");
	printf(" MISCELLANEOUS\n 20: Remove duplicate elements from list\n 21: Rotate list\n 22: Reverse List\n 23: Remove odd elements\n 24: Remove even elements\n");
	printf("TO EXIT ENTER 0\n");
	while(Q!=0) {
		printf("ENTER YOUR CHOICE: ");
		scanf("%d",&Q);
		switch(Q) {
			case 0:
				break;
			case 1:
				printf("Enter the number of nodes you want: ");
				scanf("%d",&size);
				create_list(size);
				ctr=0;
				break;
			case 2:
				insertion_start();
				++ctr;
				break;
			case 3:
				insertion_middle(size+ctr);
				++ctr;
				break;
			case 4:
				insertion_end(size+ctr);
				++ctr;
				break;
			case 5:
				insertion_particular_element();
				++ctr;
				break;
			case 6:
				insertion_particular_node(size+ctr);
				++ctr;
				break;
			case 7:
				deletion_start();
				printf("Element deleted succesfully!\n");
				--ctr;
				break;
			case 8:
				deletion_middle(size+ctr);
				--ctr;
				break;
			case 9:
				deletion_end();
				--ctr;
				break;
			case 10:
				deletion_particular_element();
				--ctr;
				break;
			case 11:
				deletion_particular_node(size+ctr);
				--ctr;
				break;
			case 12:
				traverse_list();
				break;
			case 13:
				reverse_traverse_list(size+ctr);
				break;
			case 14:
				after_element();
				break;
			case 15:
				before_element();
				break;
			case 16:
				traverse_particular_node(size+ctr);
				break;
			case 17:
				reverse_traverse_particular_node(size+ctr);
				break;
			case 18:
				sort_ascending(size+ctr);
				break;
			case 19:
				sort_descending(size+ctr);
				break;
			case 20:
				ctr-=remove_duplicate(size+ctr);
				break;
			case 21:
				rotate();
				break;
			case 22:
				reverse_list();
				break;
			case 23:
				ctr-=remove_odd();
				break;
			case 24:
				ctr-=remove_even();
				break;
			default:
				printf("Please choose valid option!\n");
				break;
		}
	}
	printf("Thank you for using the program!\n");
	return 0;
}
