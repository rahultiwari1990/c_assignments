#include <stdio.h>
#include <stdlib.h>
//#include "include/link_list.h"
#include "link_list.h"

// Define a callback unction to print a node data
void printInt(void *data)
{
	if (data != NULL)
	{
		printf("\tNode data: [%d]\n", *(int *)data);
	}
}

// Define a callback function to compare data
int compareData(void *data1, void *data2)
{
	if(data1 != NULL && data2 != NULL)
	{
		if(*(int *)data1 == *(int *)data2)
		{	
			DEBUG("%d,%d",*(int *)data1, *(int *)data2);
			printf("\nData Matched");
			return 1;
		}
		else
		{
			DEBUG("\nData not Matched");
			return 0;
		}
	}
	else
	{
		return 0;
	}
}


// Define a Main Function 
int main()
{
        struct node_struct *head = NULL, *node_ptr=NULL;

	int list_length=0, index_val=0;
	unsigned int_size = sizeof(int);

	// Defining test data
    	int arr[] = {10, 20, 30, 40, 50}, i;
	int test_data[] = {12,15,35,25,42};

	// Initialize list with one element
	head = list_init(&arr[0], int_size);
	
	// Filling list with test data
    	for (i=1; i<5; i++)
	{
		addNodeAtEnd(head, &arr[i], int_size);
	}

    	DEBUG("Created integer linked list is \n");
	
	// Getting a list length	
	list_length = getListLength(head);
	print_list(head, printInt,getListLength(head));

	printf("\n---Testing Add operations---\n");
	// Adding some node's at begining of list
	head = addNodeBegining(head,&test_data[0], int_size);
	head = addNodeBegining(head,&test_data[1], int_size);

	print_list(head, printInt,getListLength(head));
	// Adding a node at end of list
	addNodeAtEnd(head, &test_data[2], int_size);

	// Adding a node at index value
	addNodeByIndex(head,3,&test_data[3], int_size);

	print_list(head, printInt,getListLength(head));

	printf("\n---Testing search operations---\n");
	// Search a node based on data value
	node_ptr=searchNodeByData(head,compareData,&test_data[4]);
	if(node_ptr != NULL)
	{
		printf("Node value is: %d", *(int *)node_ptr->data);
	}
	node_ptr=searchNodeByData(head,compareData,&arr[2]);
	if(node_ptr != NULL)
	{
		printf("Node value is: %d", *(int *)node_ptr->data);
	}

	// get Node index based on Node data
	index_val=getNodeIndexByData(head,compareData,&arr[2]);
	printf("\nIndex value for given node is %d",index_val);

	printf("\n---Testing delete operations---\n");
	// Delete a node at beginning of list
	head = deleteNodeAtBegining(head);
	print_list(head, printInt,getListLength(head));

	// Delete a last node
	deleteNodeAtLast(head);
	print_list(head, printInt,getListLength(head));

	// Delete a node based on index value
	deleteNodeByIndex(head,4);
	print_list(head, printInt,getListLength(head));


	printf("\n---Testing display operations---\n");
	// Displaying List data
	print_list(head, printInt,list_length);

	// Displaying First N elements of list
	//print_list(head, printInt,3);

	// Display list in reverse order
	printf("\nThe list in reverse order:");
	printReverse(head, printInt,list_length);
	
	// Display Last N elements
	printReverse(head, printInt,3);

	// Destroy a list
	destroyList(head);
        return 0;
}

