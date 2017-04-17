
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//#include "../include/link_list.h"
#include "link_list.h"

int list_length = 0;

void test()
{
	printf("Hello world");
}


// Initialize a list with one node
struct node_struct* list_init(void* node_data, int data_size)
{
	// creating a head node
	struct node_struct *node_ptr = NULL;
	node_ptr = createNode(node_data,data_size);
	return node_ptr;
}



// Create a Node
struct node_struct* createNode(void* node_data, int data_size)
{
	struct node_struct *node_ptr = NULL;
	node_ptr = (struct node_struct*)malloc(sizeof(struct node_struct));
	DEBUG("\nNode created at %p ", node_ptr);
	if (node_ptr == NULL)
	{
		printf("Node Creation failed");
		return NULL;
	}
	else
	{
		node_ptr->data = malloc(data_size);
		memcpy(node_ptr->data,node_data,data_size);
		node_ptr->next = NULL;
		
		return node_ptr;
	}
}


// Getting a Last Node
struct node_struct* getLastNode(struct node_struct *head)
{
	struct node_struct* current = head;
	
	if(current != NULL)
	{
		while(current->next != NULL)
		{
			current = current->next;
		}
		return current;
	}
	else
	{
		return NULL;
	}
}

// Adding a node at begining
struct node_struct* addNodeBegining(struct node_struct *head, void* node_data, int data_size)
{
        if(head != NULL)
        {
                struct node_struct *current_node_ptr = NULL;
                current_node_ptr = createNode(node_data,data_size);
                if (current_node_ptr == NULL)
                {
                        return NULL;
                }
                else
                {
                        current_node_ptr->next=head;
                        head = current_node_ptr;
			return head;
                }
        }
	else
	{
		head = list_init(node_data,data_size);
		return head;
	}
}

// Adding a node at last
struct node_struct* addNodeAtEnd(struct node_struct *head, void* node_data, int data_size)
{
	struct node_struct *current_node_ptr = NULL, *new_node=NULL;
        if (head == NULL)
        {
                head = list_init(node_data,data_size);
                return head;
        }
        else
        {
        	current_node_ptr = getLastNode(head);
		new_node = createNode(node_data,data_size);
		current_node_ptr->next=new_node;
        }
	
	return EXIT_SUCCESS;
	        
}



// Adding a Node based on index value
int addNodeByIndex(struct node_struct *head, int index, void* node_data, int data_size)
{
        struct node_struct *current_ptr = head, *previous_ptr = NULL, *node_ptr=NULL;
        int count=0;
	if(current_ptr != NULL)
	{
	        while(current_ptr->next != NULL)
	        {
	                count++;
	                if (count == index)
	                {
	                        break;
	                }
	                previous_ptr = current_ptr;
	                current_ptr = current_ptr->next;
	                DEBUG("\ncurrent[%p], previous[%p],%d", current_ptr, previous_ptr, count);
	        }

		if (index <= count && index > 1)
		{	
			node_ptr = createNode(node_data,data_size);
			if(node_ptr == NULL)
			{	
				printf("Node Creation Failed");
				return -1;
			}
		        previous_ptr->next = node_ptr;
			node_ptr->next = current_ptr;
			return 0;
		}
		else
		{
			printf("Given index is invalid. valid index is 1<index<length of list");
			return -1;
		}
	}
	else
	{
		printf("\nNULL pointer received");
		return -1;
	}

}

// Replacing a node at begining
struct node_struct * replaceNodeAtBegining(struct node_struct *head,void* node_data, int data_size)
{
	struct node_struct *current_node_ptr = head, *node_ptr=NULL;
	if(current_node_ptr != NULL)
	{
	        node_ptr = createNode(node_data,data_size);
	        if (node_ptr == NULL)
	        {
	                return NULL;
	        }
	        else
	        {
			node_ptr->next = head->next;
	                head = node_ptr;
			free(current_node_ptr->data);
			free(current_node_ptr);
			return head;
	        }
	}
	else
	{
		printf("\nNULL pointer received");
		return NULL;
	}
}

// Replacing a node at the end of list
int replaceNodeAtEnd(struct node_struct *head,void* node_data, int data_size)
{
	struct node_struct *current_ptr = head, *previous_ptr=NULL, *node_ptr=NULL;
	if(current_ptr != NULL)
	{
	        while(current_ptr->next != NULL)
	        {
	                previous_ptr = current_ptr;
	                current_ptr = current_ptr->next;
	                DEBUG("\ncurrent[%p], previous[%p]", current_ptr, previous_ptr);
	        }
	
		node_ptr = createNode(node_data,data_size);
		if(node_ptr != NULL)
		{
	        	previous_ptr->next = node_ptr;
		        free(current_ptr->data);
		        free(current_ptr);
			return 0;
		}
		else
		{
			printf("\nNULL pointer received");
			return -1;
		}
	}
	else
	{
		printf("\nNULL pointer recevied");
		return -1;
	}
}


// Deleting a Node based on index value
int replaceNodeByIndex(struct node_struct *head,int index, void* node_data, int data_size)
{
        struct node_struct *current_ptr = head, *previous_ptr = NULL, *node_ptr=NULL;
        int count=0;
	if(current_ptr != NULL)
	{
	        while(current_ptr->next != NULL)
	        {
	                count++;
	                if (count == index)
	                {
	                        break;
	                }
	                previous_ptr = current_ptr;
	                current_ptr = current_ptr->next;
	                DEBUG("\ncurrent[%p], previous[%p],%d", current_ptr, previous_ptr, count);
	        }
	
		if(index <= count && index > 1)
		{
			node_ptr = createNode(node_data,data_size);
			if(node_ptr != NULL)
			{
				previous_ptr->next = node_ptr;
				node_ptr->next = current_ptr->next;
			        free(current_ptr->data);
			        free(current_ptr);
				return 0;
			}	
			else
			{
				printf("\nNULL pointer received");
				return -1;
			}
		}
		else
                {
                        printf("Given index is invalid. valid index is 1<index<length of list");
                        return -1;
                }
		
	}
	else
	{
		printf("\nNULL pointer received");
		return -1;
	}
}


// Searching a Node
struct node_struct * searchNodeByData(struct node_struct *head, int (*fptr)(void *,void *), void *data)
{
	
	DEBUG("In SearchNodeByData function");
	struct node_struct *ptr = head;
	int ret_val = -1;

	if(ptr != NULL)
	{

		while(ptr != NULL)
		{
			ret_val = (*fptr)(ptr->data, data);
			if(ret_val == 1)
			{
				DEBUG("\ncallback is returned with value %d", ret_val);
				printf("\nNode with given input data was found\n");
				break;
			}
			else
			{
				DEBUG("\ncall back is returned with value %d",ret_val);	
				ptr = ptr->next;
			}
		}
		if(ret_val != 1)
		{
			printf("\nNode with given input data was not found in list\n");
		}
		return ptr;
	}
	else
	{
		printf("\nNULL pointer received");
		return NULL;
	}
}


// Searching a Node based on index
struct node_struct * searchNodeByIndex(struct node_struct *head, int index)
{
        struct node_struct *ptr = head;
	int count = 0;
	if(ptr != NULL)
	{
	        while(ptr->next != NULL)
	        {
			count++;
			if(count  == index)
			{
				break;
			}
	                ptr = ptr->next;
	        }
		
		if(index > count)
		{
			printf("\nInvalid index received. it shoud be <= length of list");
		}
        	return ptr;
	}
	else
	{
		printf("\nNULL Pointer received");
		return NULL;
	}
}

// Deleting Node from list at begining
struct node_struct * deleteNodeAtBegining(struct node_struct *head)
{
	struct node_struct *ptr = head, *next_ptr=NULL;
	if (ptr != NULL)
	{
		next_ptr = ptr;
		head = ptr->next;
		free(next_ptr->data);
		free(next_ptr);
		return head;
	}
	else
	{
		printf("\nNULL pointer received");
		return NULL;
	}
}

// Deleting Node from list at end position
int deleteNodeAtLast(struct node_struct *head)
{
	struct node_struct *current_ptr = head, *previous_ptr=NULL;
	if(current_ptr != NULL)
	{
        	while(current_ptr->next != NULL)
        	{
			previous_ptr = current_ptr;
	                current_ptr = current_ptr->next;
			DEBUG("\ncurrent[%p], previous[%p]", current_ptr, previous_ptr);
        	}
	
		previous_ptr->next = NULL;
		free(current_ptr->data);
		free(current_ptr);
		return 0;
	}
	else
	{
		printf("\nNULL pointer received");
		return -1; 
	}
}

// Deleting a Node based on index value
int deleteNodeByIndex(struct node_struct *head,int index)
{
	struct node_struct *current_ptr = head, *previous_ptr = NULL;
	int count=0;
	if(current_ptr != NULL)
	{
		while(current_ptr->next != NULL)
	        {
			count++;
			if (count == index)
			{
				break;
			}
			previous_ptr = current_ptr;
	                current_ptr = current_ptr->next;
	                DEBUG("\ncurrent[%p], previous[%p],%d", current_ptr, previous_ptr, count);
	        }
		
		if(index <= count && index > 1)
		{
			previous_ptr->next = current_ptr->next;
			free(current_ptr->data);
			free(current_ptr);
			return 0;
		}
		else
                {
                        printf("Given index is invalid. valid index is 1<index<length of list");
                        return -1;
                }

	}
	else
	{
		printf("\nNULL pointer received");
		return -1;
	}	
}

// Get a Length of link list
int getListLength(struct node_struct *head)
{
        struct node_struct *ptr = head;
	int count = 0;
	if(ptr != NULL)
	{
	        while(ptr != NULL)
	        {
			count++;
	                ptr = ptr->next;
	        }	
		list_length = count;
		DEBUG("\nLength of linklist is: %d\n", list_length);
		return list_length;
	}
	else
	{
		printf("\nNULL pointer received");
		return -1;
	}
}


// Printing a link-list
int print_list(struct node_struct *head,void (*fptr)(void *), int node_count)
{
	struct node_struct *ptr = head;
	int count=0;

	if (ptr != NULL)
	{
		printf("\n -------Printing list Start------- \n");
		while(ptr != NULL)
		{
			if (count == node_count)
			{
				break;
			}
			printf("\nNode Address[%p]",ptr);
			(*fptr)(ptr->data);
			ptr = ptr->next;
			count++;
		}
		printf("\n -------Printing list End------- \n");
		return count;
	}
	else
	{
		printf("\nNULL pointer received");
		return -1;
	}
}


// Printing a list in reverse order
void printReverse( struct node_struct *head,void (*fptr)(void *), int node_count)
{
	printf("\n -------Printing list Start------- \n");
	if (head != NULL && node_count != 0)
	{
		printf("Node Addrress is: %p", head);
		node_count = node_count - 1;
        	printReverse(head->next,fptr,node_count);
		(*fptr)(head->data);
    	}
	printf("\n -------Printing list End------- \n");
}

// Destroy a list
int destroyList(struct node_struct *head)
{
        struct node_struct *ptr = head, *next_ptr=NULL;
	if(ptr != NULL)
	{
		while(ptr->next != NULL)
		{
        		next_ptr = ptr;
	        	ptr = ptr->next;
			free(next_ptr->data);
		        free(next_ptr);
		}
	
		printf("\nAll list nodes are deleted.\n");
		return 0;
	}
	else
	{
		printf("\nNULL pointer received. It may be empty list\n");
		return -1;
	}
	
}	


// Getting a node index based on data
int getNodeIndexByData(struct node_struct *head, int (*fptr)(void *,void *), void *data)
{

        DEBUG("In getNodeIndexByData function");
        struct node_struct *ptr = head;
        int ret_val = -1,count=0;
	if (ptr != NULL)
	{
	        while(ptr != NULL)
	        {
			count++;
	                ret_val = (*fptr)(ptr->data, data);
	                if(ret_val == 1)
	                {
	                        DEBUG("\ncallback is returned with value %d", ret_val);
	                        printf("\nNode with given input data was found\n");
	                        break;
	                }
	                else
	                {
	                        DEBUG("\ncall back is returned with value %d",ret_val);
	                	ptr = ptr->next;
	                }
	        }
	        if(ret_val != 1)
	        {
	                printf("\nNode with given input data was not found in list\n");
			return -1;
	        }
	        return count;
	}
	else
	{
		printf("\nNULL pointer received");
		return -1;
	}
}

