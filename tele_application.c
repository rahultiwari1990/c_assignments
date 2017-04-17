#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./include/link_list.h"


// Define a telebook structure
struct telebook
{
	char name[20];
	int uniqueId;
	char password[20];
	char address_lin1[25];
	char address_lin2[25];
	char address_lin3[25];
	char area[20];
	char city[20];
	char state[20];
	int pincode;
	long long telephone1;
	long long telephone2;
	long long telephone3;
};

// Define global variables
struct node_struct *head=NULL;	// head pointer to list
static int subscriber_id=7;	// subscriberId

// Defining a call back for printing a node data
void displayData(void *data)
{
	struct telebook *node_ptr=NULL;
	node_ptr=(struct telebook *)data;
	printf("\t Node data: [%s,%d,%s,%s,%s,%s,%s,%s,%s,%d,%lld,%lld,%lld]",node_ptr->name,node_ptr->uniqueId,node_ptr->password,node_ptr->address_lin1,node_ptr->address_lin2,node_ptr->address_lin3,node_ptr->area,node_ptr->city,node_ptr->state,node_ptr->pincode,node_ptr->telephone1,node_ptr->telephone2,node_ptr->telephone3);
	
}


// Define a callback function to compare data
int compareUniqueId(void *data1, void *data2)
{
	struct telebook *data;

	data = (struct telebook *)data1;
	DEBUG("\nName of first field: %s", data->name);
        if(data1!= NULL && data2 != NULL)
        {
                if(data->uniqueId == *(int *)data2)
                {
                        DEBUG("\nMatched Data:%d,%d",data->uniqueId, *(int *)data2);
                        printf("\nData Matched");
                        return 1;
                }
                else
                {
                        printf("\nData not Matched");
                        return 0;
                }
        }
        else
        {
                return 0;
        }
}


struct node_struct* readDatabase(FILE *fp,struct node_struct *head)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	// reading file line by line and add file data in linklist node
	while ((read = getline(&line, &len, fp)) != -1)
        {
		struct telebook *tele_ptr = NULL;
                DEBUG("Retrieved line of length %zu :\n", read);
                DEBUG("%s", line);

		// Allocating memory
		tele_ptr = malloc(sizeof(struct telebook));
		memset(tele_ptr,0,sizeof(struct telebook));

                sscanf(line,"%[^,],%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%d,%lld,%lld,%lld",tele_ptr->name,&(tele_ptr->uniqueId), tele_ptr->password, tele_ptr->address_lin1, tele_ptr->address_lin2, tele_ptr->address_lin3,tele_ptr->area, tele_ptr->city, tele_ptr->state, &(tele_ptr->pincode) , &(tele_ptr->telephone1), &(tele_ptr->telephone2), &(tele_ptr->telephone3));
                DEBUG("testing: [%s %d %s %s %s %s %s %s %s %d %lld %lld %lld]\n",tele_ptr->name,tele_ptr->uniqueId,tele_ptr->password,tele_ptr->address_lin1,tele_ptr->address_lin2,tele_ptr->address_lin3,tele_ptr->area,tele_ptr->city, tele_ptr->state,tele_ptr->pincode, tele_ptr->telephone1, tele_ptr->telephone2,tele_ptr->telephone3);


		if(head == NULL)
		{
			head = addNodeAtEnd(head,tele_ptr,sizeof(struct telebook));
		}
		else
		{
			addNodeAtEnd(head,tele_ptr,sizeof(struct telebook));
		}
		
		// free allocated memory
		free(tele_ptr);
        }
	
	free(line);

	return head;
}

// Getting Subscriber data
void getSubscriberData(struct telebook *data)
{
	char ch='\0';
	printf("\nEnter your Name: ");
	scanf("%s", data->name);

	data->uniqueId = subscriber_id++;

	printf("\nEnter your password: ");
        scanf("%s", data->password);
	
	printf("\nEnter your address line1: ");
        scanf(" %[^\n]s", data->address_lin1);
	
   	printf("\nEnter your address line2: ");
        scanf(" %[^\n]s", data->address_lin2);
	
	printf("\nEnter your address line3: ");
        scanf(" %[^\n]s", data->address_lin3);

	printf("\nEnter your area name: ");
        scanf("%s", data->area);

	printf("\nEnter your city name: ");
        scanf("%s", data->city);

	printf("\nEnter your state Name: ");
        scanf("%s", data->state);

        printf("\nEnter your area pincode: ");
        scanf("%d", &(data->pincode));

        printf("\nEnter your telephone1: ");
        scanf("%lld", &(data->telephone1)); 

	printf("Do you want to fill data in optional field's telephone2 and telephone3. Enter y/n");
	scanf(" %c", &ch);

	if (ch == 'y')
	{
        	printf("\nEnter your telephone2: ");
        	scanf("%lld", &(data->telephone2));
       
        	printf("\nEnter your telephone3: ");
        	scanf("%lld", &(data->telephone3));
	}

	printf("\nname:%s", data->name);	
}

// Define a function to add subscriber data
struct node_struct* addSubscriber(struct node_struct *head)
{
	struct telebook *tele_record;
	char ch='\0';
	printf("\nIn addSubscriberData() function\n");

        print_list(head,displayData,getListLength(head));
	do
        {
                int index=0, Id=0;
		int choice=0;

		tele_record = malloc(sizeof(struct telebook));
		memset(tele_record,0,sizeof(struct telebook));

                printf("\n\n\n------- Subscriber Add Operations --------\n");
                printf("\t1. Add as a first subscriber\n");
                printf("\t2. Add as a last subscriber\n");
                printf("\t3. Add subscriber based on data\n");
                printf("\t4. Exit\n");
                printf("Enter Your Choice:\n");
                scanf("%d", &choice);
		printf("Entered Choice is: %d\n", choice);
                switch(choice)
                {
                        case 1: 
				getSubscriberData(tele_record);
				head = addNodeBegining(head,tele_record,sizeof(struct telebook));
                                break;
                        case 2:
				if(head == NULL)
				{
					getSubscriberData(tele_record);
					head = addNodeAtEnd(head,tele_record,sizeof(struct telebook));
				}
				else
				{
					getSubscriberData(tele_record);
					addNodeAtEnd(head,tele_record,sizeof(struct telebook));	
				}
                                break;
                        case 3:
				getSubscriberData(tele_record);
				printf("\nEnter uniqueId that you want to search:");
                                scanf("%d",&Id);
                                index = getNodeIndexByData(head,compareUniqueId,&Id);
                                addNodeByIndex(head,index,tele_record,sizeof(struct telebook));
                                break;
                        default:
				printf("\nYou have entered wrong choice");
	
			free(tele_record);	
                }

		print_list(head,displayData,getListLength(head));

                printf("\nDo you want to continue..y/n\n");
		scanf(" %c", &ch);
        }while(ch != 'n');
	
	// Display list data
	return head;
}

struct node_struct* deleteSubscriber(struct node_struct *head)
{
	char ch='\0';
	printf("\nIn deleteSubscriberData() function\n");
	print_list(head,displayData,getListLength(head));
	do
        {
                int choice = 0, index=0, Id=0;
                printf("\n\n\n------- Subscriber Delete Operations --------\n");
                printf("\t1. Delete first subscriber\n");
                printf("\t2. Delete last subscriber\n");
                printf("\t3. Delete subscriber based on data\n");
                printf("\t4. Exit\n");

                printf("Enter Your Choice:\n");
                scanf("%d", &choice);

		switch(choice)
                {
                        case 1: head = deleteNodeAtBegining(head);
                                break;
                        case 2: deleteNodeAtLast(head);
                                break;
                        case 3: printf("\nEnter uniqueId that you want to search:");
        			scanf("%d",&Id);
				index = getNodeIndexByData(head,compareUniqueId,&Id);
				deleteNodeByIndex(head,index);
				printf("\nAfter deletion of node:");
				break;
                        default: printf("\nYou have entered wrong choice");
                }
		
		print_list(head,displayData,getListLength(head));
		printf("\nDo you want to continue..y/n ");
		scanf(" %c",&ch);

	}while(ch != 'n');
	return head; 
}


int modifySubscriber(struct node_struct *head)
{
	struct node_struct *node_ptr=NULL;
        struct telebook *data_ptr=NULL;
	int Id = 0;

        printf("\nIn modifySubscriber() function\n");
        printf("\nEnter uniqueId that you want to search:");
        scanf("%d",&Id);
        node_ptr=searchNodeByData(head,compareUniqueId,&Id);

        if(node_ptr != NULL)
        {
                data_ptr=(struct telebook *)node_ptr->data;
                printf("\nuniqueId of node is: %d", data_ptr->uniqueId);
        }
	
	printf("\nEnter New value for Id:");
	scanf("%d",&(data_ptr->uniqueId));
	print_list(head,displayData,getListLength(head));
	return EXIT_SUCCESS;
}


int searchSubscriber(struct node_struct *head)
{
	int Id=0;
	struct node_struct *node_ptr=NULL;
	struct telebook *data_ptr=NULL;
	
	printf("\nIn searchSubscriber() function\n");
	printf("\nEnter uniqueId that you want to search:");
	scanf("%d",&Id);
	node_ptr=searchNodeByData(head,compareUniqueId,&Id);

	if(node_ptr != NULL)
	{
		data_ptr=(struct telebook *)node_ptr->data;
		printf("\nuniqueId of node is: %d", data_ptr->uniqueId);
	}
	return EXIT_SUCCESS;
}

int displayListData(struct node_struct *head)
{

	char ch='\0';
        int choice=0,node_count=0;

	do
        {
                printf("\n\n\n------- Display List Operations --------\n");
                printf("\t1. ALL\n");
                printf("\t2. First N data\n");
                printf("\t3. Last N data\n");
                printf("\t4. Reverse\n");
                printf("\t5. Exit\n");

                printf("Enter Your Choice:\n");
                scanf("%d", &choice);

                switch(choice)
                {
                        case 1: 
				print_list(head,displayData,getListLength(head));
                                break;
                        case 2:
				printf("\nEnter uniqueId that you want to search:");
                                scanf("%d",&node_count); 
				print_list(head,displayData,node_count);
                                break;
                        case 3: 
				printf("\nEnter uniqueId that you want to search:");
                                scanf("%d",&node_count);
                         	printReverse(head,displayData,node_count);
                                break;
			case 4:
                         	printReverse(head,displayData,getListLength(head));
                        default: printf("\nYou have entered wrong choice");
                }

                printf("\nDo you want to continue..y/n ");
                scanf(" %c",&ch);

        }while(ch != 'n');
	
	return EXIT_SUCCESS;
}


int main()
{
	// Reading a file for tele appilication
	FILE *fp;


	// Opening a text file for raeding database
	fp = fopen("tele_records.txt", "r");
	if (fp == NULL)
	{
		exit(EXIT_FAILURE);
	}
		
	// reading a data from file and prepare list of database file;
	head = readDatabase(fp,head);

	// A list after reading a database
	print_list(head,displayData,4);
	
	// Getting a data from subscriber
	while(1)
	{
		int choice = 0;
		printf("\n\n\n------- Subscriber Operations --------\n");
		printf("\t1. Add Subcriber\n");
		printf("\t2. Delete Subcriber\n");
		printf("\t3. Modify Subcriber Detail\n");
		printf("\t4. Search Subcriber Detail\n");
		printf("\t5. Display Subcriber Detail\n");
		printf("\t6. Exit\n");
	
		printf("Enter Your Choice:\n");
		scanf("%d", &choice);
		

		// Adding ramaining data in link list
		switch(choice)
		{
			case 1: printf("You have selected first choice");	
				head=addSubscriber(head);
				break;
			case 2: printf("You have selected second choice");
				head=deleteSubscriber(head);
				break;
			case 3: printf("You have selected third choice");
				modifySubscriber(head);
				break;
			case 4: printf("You have selected fourth choice");
				searchSubscriber(head);
				break;
			case 5: printf("You have selected fifth choice");
				displayListData(head);
                                break;
			case 6: printf("Terminating an application\n");
				break;
			default: exit(0);
		}
	}

	// closing a file pointer
	fclose(fp);

	// destroy list elemnets before exiting program	
	destroyList(head);
	exit(EXIT_SUCCESS);	
	
}

