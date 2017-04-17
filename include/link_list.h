
/**
  * Define a node structure
  */
struct node_struct
{
	void* data;
	struct node_struct *next;
};

#ifdef DEBUG_ENABLE
    #define DEBUG(msg, ...) printf( msg"\n", ##__VA_ARGS__);
#else
    #define DEBUG(msg, ...)
#endif

void test();

/**
  * @brief Initialize a list with head node
  * @param[in] void* input data which needs to be stored
  * @param[in] int size of input data
  * @return ptr It returns a pointer to head node
  */

struct node_struct* list_init(void* node_data, int data_size);


/**
  * @brief Create a new list Node
  * @param[in] void* input data which needs to be stored
  * @param[in] int size of input data
  * @return ptr It returns a pointer to created node
  */

struct node_struct* createNode(void* node_data, int data_size);

/**
  * @brief Getting a last Node from list
  * @param[in] list the list to operate upon
  * @return the pointer to last node of list
  */

struct node_struct* getLastNode(struct node_struct *head);


/**
  * @brief It adds a node at begining of list
  * @param[in] list the list to operate upon
  * @param[in] void* input data which needs to be stored
  * @param[in] int size of input data
  * @return ptr It returns a updated head pointer of list
  */

struct node_struct* addNodeBegining(struct node_struct *head, void* node_data, int data_size);

/**
  * @brief It adds a node at end of list
  * @param[in] list the list to operate upon
  * @param[in] void* input data which needs to be stored
  * @param[in] int size of input data
  * @return ptr It returns a head pointer in case of Fisrt element of list otherwise returns 0.
  */

struct node_struct* addNodeAtEnd(struct node_struct *head, void* node_data, int data_size);

/**
  * @brief It adds a node at given position in list
  * @param[in] list the list to operate upon
  * @param[in] void* input data which needs to be stored
  * @param[in] int size of the input data
  * @return int It returns 0 on success
  */

int addNodeByIndex(struct node_struct *head, int index, void* node_data, int data_size);

/**
  * @brief It search a node based on input data in a list
  * @param[in] list the list to operate upon
  * @param[in] function ptr Need to pass callback function
  * @param[in] void* data which needs to be compared
  * @return int LLIST_SUCCESS if success
  */

struct node_struct * searchNodeByData(struct node_struct *head, int (*fptr)(void *,void *), void *data);

/**
  * @brief It search a node based on index value in a list
  * @param[in] list the list to operate upon
  * @param[in] int position index where node will be inserted
  * @return ptr It returns a pointer to node which was search based on index value
  */

struct node_struct * searchNodeByIndex(struct node_struct *head, int index);

/**
  * @brief It deletes a first node of given list
  * @param[in] list the list to operate upon
  * @return ptr It returns updated head pointer of list
  */

struct node_struct* deleteNodeAtBegining(struct node_struct *head);

/**
  * @brief It deletes last node of given list
  * @param[in] list the list to operate upon
  * @return void None
  */

int deleteNodeAtLast(struct node_struct *head);

/**
  * @brief It deletes a node based on index value from a list
  * @param[in] list the list to operate upon
  * @param[in] int position index where node will be deleted
  * @return void None
  */

int deleteNodeByIndex(struct node_struct *head, int index);

/**
  * @brief It displays a list's node data
  * @param[in] list the list to operate upon
  * @param[in] ptr gives a function pointer to callback function
  * @param[in] int value for number of nodes that we want to display. 
  * @return void None
  */

int print_list(struct node_struct *head, void (*fptr)(void *), int node_count);

/**
  * @brief It gives a length of list
  * @param[in] list the list to operate upon
  * @return int It returns a length of given list
  */

int getListLength(struct node_struct *head);


/**
  * @brief It replace a node at begining of list
  * @param[in] list the list to operate upon
  * @param[in] void* input data which needs to be stored
  * @param[in] int size of the input data
  * @return ptr It returns a updated head pointer 
  */
struct node_struct* replaceNodeAtBegining(struct node_struct *head, void* node_data, int data_size);

/**
  * @brief It replace a node at end of list
  * @param[in] list the list to operate upon
  * @param[in] void* input data which needs to be stored
  * @param[in] int size of the input data
  * @return int EXIT_SUCCESS if success
  */

int replaceNodeAtEnd(struct node_struct *head, void* node_data, int data_size);


/**
  * @brief It replace a node at given position
  * @param[in] list the list to operate upon
  * @param[in] void* input data which needs to be stored
  * @param[in] int size of the input data
  * @return void None 
  */

int replaceNodeByIndex(struct node_struct *head, int index, void* node_data, int data_size);


/**
  * @brief It prints a list data in a reverse order
  * @param[in] list the list to operate upon
  * @param[in] function pointer a callback function
  * @return void None
  */

void printReverse( struct node_struct *head, void (*fptr)(void *), int node_count);



/**
  * @brief It destroy a given list and free allocated memory
  * @param[in] list the list to operate upon
  * @return void None
  */

int destroyList(struct node_struct *head);


/**
  * @brief It search a node based on input data in a list
  * @param[in] list the list to operate upon
  * @param[in] function ptr Need to pass callback function
  * @param[in] void* data which needs to be compared
  * @return int It returns index value based on search otherwise returns 0;
  */

int getNodeIndexByData(struct node_struct *head, int (*fptr)(void *,void *), void *data);


