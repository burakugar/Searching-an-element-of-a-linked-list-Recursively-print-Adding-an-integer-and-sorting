#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node
{
    int data;
    float number;
    char* name;
    struct node *next;
};


void insert_end(struct node **head, int val, float num, char* name_)
{
    //create a new node
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->number = num;
    newNode->name = name_;
    newNode->next = NULL;

    //if head is NULL, it is an empty list
    if(*head == NULL)
         *head = newNode;
    //Otherwise, find the last node and add the newNode
    else
    {
        struct node *lastNode = *head;

        //last node's next address will be NULL.
        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }

        //add the newNode at the end of the linked list
        lastNode->next = newNode;
    }

}

void printList_withLoop(struct node *head)
{	struct node *current_node = head;
    while(current_node!=NULL){
    	  printf(" %d ->", current_node->data);
    	  printf(" %.2f ->", current_node->number);
    	  printf(" %s ", current_node -> name);
    	  current_node= current_node->next;
    	  printf("\n");
	}
	printf("NULL");
	
}
void printList_withRecursive(struct node *list) {
   if(list==NULL){
   	return;	
   }
    printf(" %d ->", list->data);
    printf(" %.2f ->", list->number);
    printf(" %s ", list -> name);
    
   printList_withRecursive(list->next);
}

void sortedInsert(struct node** head_ref, struct node* new_node)
{	struct node* temp= (struct node*) malloc(sizeof(struct node));
   // Sort according to string into the node struct.
   // It's name is "name".
   // You will sort ascending order
   temp=*head_ref;
    if (new_node)
    {
         new_node->next = temp;
         temp = new_node;
        
    }
    
    else
    {
        printf("NULL\n");
    }
	
}
 
 
/* A utility function to create a new node */
struct node* newNode(int new_data, float num, char* name_)
{
    /* allocate node */
	struct node* temp= (struct node*) malloc(sizeof(struct node));
    /* put in the data  */
	temp->data= new_data;
	strcpy(temp->name,name_);
	temp->number=num;
	temp->next=NULL; 
	}


bool search(struct node* head, int x)
{	
    // Search according to "data" which defined in node struct.
	// You will control x number comparision with "data" which struct element.
	while(head!=NULL){
		if(head->data == x){
			return true;
		}
	}
		return false;
	
}

int main()
{
     struct node *head = NULL;

     insert_end(&head,10,5.5,"hello1");
     insert_end(&head,20,5.5,"hello2");
     insert_end(&head,30,5.5,"hello3");

     printf("Print List with Loop: \n");
     printList_withLoop(head);
     
     struct node* new_node = newNode(1,5.5, "a");
     sortedInsert(&head, new_node);

     
     new_node = newNode(3,5.5, "c");
     sortedInsert(&head, new_node);
     
     new_node = newNode(2,5.5, "d");
     sortedInsert(&head, new_node);
     
     new_node = newNode(2,5.5, "b");
     sortedInsert(&head, new_node);
     
     printf("Print List with Recursive: \n");
     printList_withRecursive(head);
	 
	 printf("\nIs 20 belong this linked list?: " );
     printf(search(head, 20) ? "YES \n" : "NO \n");
     
     printf("\nIs 18 belong this linked list?: " );
     printf(search(head, 18) ? "YES \n" : "NO \n");


     return 0;
}
