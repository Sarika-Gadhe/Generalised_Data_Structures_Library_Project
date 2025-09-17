#include<iostream>
using namespace std;

//----------------------------------------------------------------------------------
//
//  Class Name     :   QueueX
//  Description    :   Generic Queue implementation using singly linked list
//  Author         :   Sarika Devidas Gadhe
//  Date           :   16/09/2025
// 
//----------------------------------------------------------------------------------

template <class T>
struct Queuenode
{
    T data;
    struct Queuenode<T> *next;
};

template <class T>
class QueueX
{
    private:
        struct Queuenode<T> *first;      // Pointer to first node of queue
        int iCount;                      // Count of nodes in queue

    public:
        QueueX();

        void Enqueue (                   // Insert element at the end
                             T
                        );

        T Dequeue();                     // Remove element from the front    

        void Display();                  // Display all elements

        int Count();                     // Return count of elements
};

//----------------------------------------------------------------------------------
//
//  Function Name        : QueueX
//  Function Date        : 16/09/2025
//  Function Author      : Sarika Devidas Gadhe
//  Parameters           : NONE
//
//  Description          : 
//              This is constructor of class QueueX, initializes queue
//
//  Returns              : NONE
// 
//----------------------------------------------------------------------------------

template <class T>
QueueX<T> :: QueueX()
{
    first = NULL;
    iCount = 0;
}

//----------------------------------------------------------------------------------
//
//	Function Name			:	Enqueue
//	Function Date			:	16/09/2025
//	Function Author			:	Sarika Devidas Gadhe
//
//	Parameters :
//
//	      [IN] T no
//		  Holds the data which is to be inserted into the queue.
//
//  Description :
//       This function inserts a new node at the end of the queue.
//       If the queue is empty, the new node becomes the first node.
//       Otherwise, it traverses to the last node and links the new node there.
//
//  Returns:
//       void
//       The function does not return a value.
// 
//----------------------------------------------------------------------------------

template <class T>
void QueueX<T> :: Enqueue(
                                    T no
                            ) 
{
    struct Queuenode<T> *temp = NULL;

    //
    // Create a new node
    //
    struct Queuenode<T> * newn = NULL;
    newn = new Queuenode<T>;
    
    //
    // Assign data and set next pointer to NULL
    //
    newn->data = no;
    newn->next = NULL;
    
    //
    // If queue is empty, new node becomes first
    //
    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;

        //
        // Traverse to the last node
        // 
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }

        temp->next = newn;
    }

    iCount++;
}

//----------------------------------------------------------------------------------
//
//	Function Name			:	Enqueue
//	Function Date			:	16/09/2025
//	Function Author			:	Sarika Devidas Gadhe
//
//	Parameters :         
//	      NONE
//
//  Description :
//       This function removes a node from the front of the queue.
//       If the queue is empty, it prints a message and returns a NULL value.
//       Otherwise, it returns the data of the removed node.
//
//  Returns :
//       T
//       The value removed from the queue. If empty, returns NULL.
// 
//----------------------------------------------------------------------------------

template <class T>
T QueueX<T> :: Dequeue()          // DeleteFirst
{
    struct Queuenode<T> *temp = NULL;
    T value;

    //
    // If queue is empty,return NULL
    //
    if(first == NULL)
    {
        cout<<"Unable to remove as queue is empty\n";
        return NULL;
    }
    else
    {
        temp = first;
        value = temp->data;

        first = first -> next;
        
        //
        // Free memory of removed node
        //
        delete temp;
        
        //
        // Decrement node count
        //
        iCount--;

        return value;
    }
}

//----------------------------------------------------------------------------------
//
//	Function Name			:	Display
//	Function Date			:	16/09/2025
//	Function Author			:	Sarika Devidas Gadhe
//
//	Parameters:
//	      NONE
//
//  Description:
//       This function traverses the queue from first to last and prints each node's data.
//
//  Returns:
//       void
//       The function does not return a value.
//
//----------------------------------------------------------------------------------

template <class T>
void QueueX<T> :: Display()
{
    struct Queuenode<T> *temp = NULL;

    temp = first;
    
    //
    // Traverse and print each node
    //
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |-";
        temp = temp->next;
    }
    cout<<"\n";
}


//----------------------------------------------------------------------------------
//
//	Function Name			:	Count
//	Function Date			:	16/09/2025
//	Function Author			:	Sarika Devidas Gadhe
//
//	Parameters:
//	      NONE
//
//  Description:
//       This function returns the total number of nodes currently present in the queue.
//
//  Returns:
//       int
//       The total count of nodes.
//
//---------------------------------------------------------------------------------

template <class T>
int QueueX<T> :: Count()
{
    //
    // Return total number of nodes in queue
    //
    return iCount;
}

//----------------------------------------------------------------------------------
//
//  Class Name     :   StackX
//  Description    :   Generic Stack implementation using singly linked list
//  Author         :   Sarika Devidas Gadhe
//  Date           :   16/09/2025
// 
//----------------------------------------------------------------------------------

template<class T>
struct Stacknode
{
    T data;
    struct Stacknode<T> *next;
};

template<class T>
class StackX
{
    private:
        struct Stacknode<T> *first;         // Pointer to top node of stack
        int iCount;                         // Count of nodes in stack

    public:
        StackX();

        void Push(
                             T
                    );

        T Pop();

        void Display();

        int Count();
};


//----------------------------------------------------------------------------------
//
//	Function Name			:	StackX
//	Function Date			:	16/09/2025
//	Function Author			:	Sarika Devidas Gadhe
//
//	Parameters:
//	      NONE
//
//  Description:
//       This is the constructor which initializes the stack.
//       Sets first pointer to NULL and node count to 0.
//
//  Returns:
//       void
//       The function does not return a value.
//
//----------------------------------------------------------------------------------

template<class T>
StackX<T> :: StackX()
{
    first = NULL;
    iCount = 0;
}


//----------------------------------------------------------------------------------
//
//	Function Name			:	Push
//	Function Date			:	16/09/2025
//	Function Author			:	Sarika Devidas Gadhe
//
//	Parameters:
//	      [IN] T no
//		  Holds the data which is to be inserted into the stack.
//
//  Description:
//       This function inserts a new node at the top of the stack.
//       The new node's next pointer points to the previous top node.
//
//  Returns:
//       void
//       The function does not return a value.
//
//----------------------------------------------------------------------------------

template<class T>
void StackX<T> :: Push(             // InsertFirst
                                T no

                        ) 
{
    //
    // Create a new node
    //
    struct Stacknode<T> * newn = NULL;
    newn = new Stacknode<T>;

    newn->data = no;
    newn->next = NULL;

    //
    // Link new node at top
    //
    newn->next = first;
    first = newn;

    iCount++;
}


//------------------------------------------------------------------------------------------
//
//	Function Name			:	Pop
//	Function Date			:	16/09/2025
//	Function Author			:	Sarika Devidas Gadhe
//
//	Parameters:
//	      NONE
//
//  Description:
//       This function removes a node from the top of the stack.
//       If the stack is empty, it prints a message and returns a default value.
//       Otherwise, it returns the data of the removed node.
//
//  Returns:
//       T
//       The value removed from the stack. If empty, returns NULL.
//
//-----------------------------------------------------------------------------------------

template<class T>
T StackX<T> :: Pop()         // DeleteFirst
{
    struct Stacknode<T> *temp = NULL;
    T value;

    //
    // If stack is empty, show message and return NULL.
    //
    if(first == NULL)
    {
        cout<<"Unable to pop as stack is empty\n";
        return NULL;
    }
    else
    {
        temp = first;
        value = temp->data;
        
        //
        // Move first pointer to next node
        //
        first = first -> next;

        delete temp;

        iCount--;

        return value;
    }
}

//----------------------------------------------------------------------------------------
//
//	Function Name			:	Display
//	Function Date			:	16/09/2025
//	Function Author			:	Sarika Devidas Gadhe
//
//	Parameters:
//	      NONE
//
//  Description:
//       This function traverses the stack from top to bottom and prints each node's data.
//
//  Returns:
//       void
//       The function does not return a value.
//
//----------------------------------------------------------------------------------------

template<class T>
void StackX<T> :: Display()
{
    struct Stacknode<T> *temp = NULL;

    temp = first;

    //
    // Traverse and print each node
    //
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |-";
        temp = temp->next;
    }
    cout<<"\n";
}

//----------------------------------------------------------------------------------------
//
//	Function Name			:	Count
//	Function Date			:	16/09/2025
//	Function Author			:	Sarika Devidas Gadhe
//
//	Parameters:
//	      NONE
//
//  Description:
//       This function returns the total number of nodes currently present in the stack.
//
//  Returns:
//       int
//       The total count of nodes.
//
//----------------------------------------------------------------------------------------

template<class T>
int StackX<T> :: Count()
{
    //
    // Return total number of nodes in stack
    //
    return iCount;
}


//----------------------------------------------------------------------------------------
//
//  Class Name     :   SinglyCLL
//  Description    :   Generic implementation of singly circular linked list
//  Author         :   Sarika Devidas Gadhe
//  Date           :   16/09/2025
//
//----------------------------------------------------------------------------------------

template <class T>
struct SinglyCLLnode
{
    T data;                                               // Data stored in node
    struct SinglyCLLnode<T> *next;                        // Pointer to next node
};

template <class T>
class SinglyCLL
{
    private:
        struct SinglyCLLnode<T> * first;                  // Pointer to first node
        struct SinglyCLLnode<T> * last;                  // Pointer to last node  
        int iCount;                                      // Number of nodes in list

    public:
        SinglyCLL();

        void InsertFirst(                                                // Insert node at beginning
                                    T no
                            );

        void InsertLast(                                                 // Insert node at end
                                    T no
                            );

        void InsertAtPos(                                                 // Insert node at position
                                    T no, 
                                    int pos
                            );

        void DeleteFirst();                                                // Delete first node

        void DeleteLast();                                                 // Delete last node  

        void DeleteAtPos(                                                  // Delete node at position
                                    int pos
                            );

        int Count();                                                        // Return number of nodes  

        void Display();                                                     // Display all nodes

        int SinglyCircular_SearchFirstOcc(                                  // Search first occurrence
                                                        T no
                                            );

        int SinglyCircular_SearchLastOcc(                                    // Search last occurrence
                                                        T no
                                            );

        int SinglyCircular_Summation();                                     // Sum of all elements
        
        int SinglyCircular_SummationOdd();                                  // Sum of odd elements

        int SinglyCircular_SummationEven();                                 // Sum of even elements

        int SinglyCircular_Maximum();                                       // Maximum element    

        int SinglyCircular_Minimum();                                       // Minimum element

        int SinglyCircular_SecMaximum();                                    // Second maximum element

        void SinglyCircular_DisplayPrime();                                 // Display prime numbers

        void SinglyCircular_DisplayPerfect();                               // Display perfect numbers

        void SinglyCircular_SumDigit();                                     // Sum of digits of all elements

        void SinglyCircular_ReverseDigit();                                 // Reverse digits of each element

        void SinglyCircular_DisplaySmallDigit();                            // Display smallest digit of elements

        void SinglyCircular_DisplayLargeDigit();                            // Display largest digit of elements

        void SinglyCircular_DisplayProduct();                               // Display product of digits

        void SinglyCircular_DisplayPalindrome();                            // Display palindrome numbers
};

//----------------------------------------------------------------------------------------
//
//  Function Name     :   SinglyCLL
//  Function Date     :   16/09/2025
//  Function Author   :   Sarika Devidas Gadhe
//
//  Parameters :
//             NONE
//
//  Description :   
//             Constructor initializes first and last pointers as NULL
//             and node count to zero. Prepares empty circular list.
//
//  Returns :  
//               void
//
//----------------------------------------------------------------------------------------

template <class T>
SinglyCLL<T>::SinglyCLL()
{
    cout<<"Inside constructor of SinglyCLL\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

//----------------------------------------------------------------------------------------
//
//	Function Name			:	InsertFirst
//	Function Date			:	16/09/2025
//	Function Author			:	Sarika Devidas Gadhe
//
//	Parameters:
//		    [IN] T no
//          data to insert at beginning
//
//	Description:
//		    This function inserts a new node at the beginning of the circular list.
//		    If list is empty, new node becomes first and last.
//		    Otherwise, node is linked before first and last->next is updated.
//
//	Returns :
//      	void
//
//----------------------------------------------------------------------------------------

template <class T>
void SinglyCLL<T>::InsertFirst(
                                            T no
                                )
{
    //
    // Allocate memory for new node
    //
    struct SinglyCLLnode<T> * newn = NULL;
    newn = new struct SinglyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    //
    // Case 1: List is empty
    //
    if(first == NULL && last == NULL)                   
    {
        first = newn;
        last = newn;

        last->next = first;
    }

    //
    // Case 2: List has nodes
    //
    else
    {
        newn->next = first;
        first = newn;

        last->next = first;
    }

    iCount++;
}

//----------------------------------------------------------------------------------------
//
//	Function Name			:	InsertLast
//	Function Date			:	16/09/2025
//	Function Author			:	Sarika Devidas Gadhe
//
//	Parameters:
//		  [IN] T no
//        -> data to insert at the end of the circular list
//
//	Description:
//		  This function inserts a new node at the end of the circular linked list.
//		  It updates the last pointer and maintains the circular link.
//
//	Returns:
//        void
//
//----------------------------------------------------------------------------------------

template <class T>
void SinglyCLL<T>::InsertLast(
                                        T no
                                )
{
    //
    // Allocate memory for new node
    //
    struct SinglyCLLnode<T> * newn = NULL;
    newn = new struct SinglyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    //
    // if the list is empty
    //
    if(first == NULL && last == NULL)   
    {
        first = newn;
        last = newn;

        last->next = first;
    }
    else
    {
        last->next = newn;
        last = newn;

        last->next = first;
    }

    //
    //  increment node count
    //
    iCount++;
}

//----------------------------------------------------------------------------------------
//
//	Function Name			:	DeleteFirst
//	Function Date			:	16/09/2025
//	Function Author			:	Sarika Devidas Gadhe
//
//	Parameters:
//		    NONE
//
//	Description:
//		This function deletes the first node from a singly circular linked list.
//		If the list is empty, it does nothing.
//		If the list has only one node, it deletes it and resets first and last pointers.
//		Otherwise, it removes the first node and updates the first pointer and circular link.
//
//	Returns:
//		void
//
//----------------------------------------------------------------------------------------

template <class T>
void SinglyCLL<T>::DeleteFirst()
{
    //
    // if list is empty
    //
    if(first == NULL && last == NULL)
    {
        return;
    }

    //
    // if only one node in list
    //
    else if(first == last)
    {
        delete first;

        first = NULL;
        last = NULL;
    }

    //
    // if more than one node
    //
    else
    {
        first = first -> next;
        delete last->next;

        last->next = first;
    }

    //
    // decrement node count
    //
    iCount--;
}

//----------------------------------------------------------------------------------------
//
//	Function Name			:	DeleteLast
//	Function Date			:	16/09/2025
//	Function Author			:	Sarika Devidas Gadhe
//
//	Parameters:
//		    NONE
//
//	Description:
//		This function deletes the last node from a singly circular linked list.
//		If the list is empty, it does nothing.
//		If there is only one node, it deletes it and resets first and last pointers.
//		Otherwise, it traverses to the second-last node, deletes the last node, 
//		and updates the last pointer and circular link.
//
//	Returns:
//		void
//
//----------------------------------------------------------------------------------------

template <class T>
void SinglyCLL<T>::DeleteLast()
{
    struct SinglyCLLnode<T> * temp = NULL;

    //
    // if list is empty
    //
    if(first == NULL && last == NULL)
    {
        return;
    }

    //
    // if only one node in list
    //
    else if(first == last)
    {
        delete first;

        first = NULL;
        last = NULL;
    }
    
    //
    // if more than one node
    //
    else
    {
        temp = first;

        while(temp -> next != last)
        {
            temp = temp -> next;
        }

        delete last;
        last = temp;

        last->next = first;
    }
    iCount--;
}

//----------------------------------------------------------------------------------------
//
//	Function Name			:	Display
//	Function Date			:	16/09/2025
//	Function Author			:	Sarika Devidas Gadhe
//
//	Parameters:
//		    NONE
//
//	Description:
//		This function displays all nodes in the singly circular linked list.
//		It traverses from first node to last and prints node data.
//
//	Returns:
//		void
//
//----------------------------------------------------------------------------------------

template <class T>
void SinglyCLL<T>::Display()
{
    //
    // if list is empty
    //
    if(first == NULL && last == NULL)
    {
        return;
    }

    //
    // start from first node
    //
    struct SinglyCLLnode<T> * temp = first;

    do
    {
        //
        // print node data
        //
        cout<<"| "<<temp->data<<" | -> ";

        temp = temp -> next;
    } while (temp != last ->next);
    
    cout<<"\n";
}

//----------------------------------------------------------------------------------------
//
//	Function Name			:	Count
//	Function Date			:	16/09/2025
//	Function Author			:	Sarika Devidas Gadhe
//
//	Parameters:
//		  NONE
//
//	Description:
//		This function returns the number of nodes present in the singly circular linked list.
//
//	Returns:
//		int
//	    number of nodes
//
//----------------------------------------------------------------------------------------

template <class T>
int SinglyCLL<T>::Count()
{
    //
    // return node count
    //
    return iCount;
}

//----------------------------------------------------------------------------------------
//
//	Function Name			:	DeleteAtPos
//	Function Date			:	16/09/2025
//	Function Author			:	Sarika Devidas Gadhe
//
//	Parameters:
//		[IN] int pos
//	    position of node to delete in singly circular linked list
//
//	Description:
//		This function deletes a node from a specified position in the singly circular linked list.
//		If the position is invalid, it prints a message and returns.
//		If the position is 1, it calls DeleteFirst().
//		If the position is the last node, it calls DeleteLast().
//		Otherwise, it traverses to the previous node, deletes the target node, 
//		and updates the next pointer to maintain the circular link.
//
//	Returns:
//		void
//
//----------------------------------------------------------------------------------------

template <class T>
void SinglyCLL<T>::DeleteAtPos(
                                            int pos
                                )
{
    struct SinglyCLLnode<T> * temp = NULL;
    struct SinglyCLLnode<T> * target = NULL;
    
    int i = 0;
    
    //    
    // check for invalid position
    //
    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    //
    // delete first node
    //
    if(pos == 1)
    {
        DeleteFirst();
    }

    //   
    // delete last node
    //
    else if(pos == iCount)
    {
        DeleteLast();
    }

    //   
    // delete node at middle position
    // 
    else
    {
        temp = first;

        for(i = 1; i < pos-1; i++)
        {
            temp = temp -> next;
        }

        target = temp -> next;

        temp->next = target->next;
        delete target;

        iCount--;
    }
}

//----------------------------------------------------------------------------------------
//
//	Function Name			:	InsertAtPos
//	Function Date			:	16/09/2025
//	Function Author			:	Sarika Devidas Gadhe
//
//	Parameters:
//		[IN] T no
//			-> data to insert
//		[IN] int pos
//			-> position to insert the node in singly circular linked list
//
//	Description:
//		This function inserts a node at a specified position in the singly circular linked list.
//		If the position is invalid, it prints a message and returns.
//		If the position is 1, it calls InsertFirst().
//		If the position is at the end, it calls InsertLast().
//		Otherwise, it traverses to the node before the insertion point, inserts the new node, 
//		and updates the next pointers to maintain the circular link.
//
//	Returns:
//		void
//
//----------------------------------------------------------------------------------------

template <class T>
void SinglyCLL<T>::InsertAtPos(
                                            T no, 
                                            int pos
                                )
{
    struct SinglyCLLnode<T> * temp = NULL;
    struct SinglyCLLnode<T> * newn = NULL;

    int i = 0;

    //
    // check for invalid position
    //
    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    //  
    // insert at first position
    //
    if(pos == 1)
    {
        InsertFirst(no);
    }

    //
    // insert at last position
    //
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        // allocate new node
        newn = new struct SinglyCLLnode<T>;

        newn->data = no;
        newn->next = NULL;

        // start from first node
        temp = first;

        for(i = 1; i < pos -1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp->next = newn;

        iCount++;
    }
}

//----------------------------------------------------------------------------------------
//
//	Function Name		:	SinglyCircular_SearchFirstOcc
//	Function Date		:	16/09/2025
//	Function Author		:	Sarika Devidas Gadhe
//
//	Parameters:
//		[IN] T no
//			-> element to search in the singly circular linked list
//
//	Description:
//		This function searches for the first occurrence of an element in the 
//		singly circular linked list. 
//		It traverses nodes one by one until it finds the element. 
//		If found, it returns the position
//		If not found, it returns -1.
//
//	Returns:
//		int
//			-> position of first occurrence (1-based index), or -1 if not found
//
//----------------------------------------------------------------------------------------

template <class T>
int SinglyCLL <T>:: SinglyCircular_SearchFirstOcc(
                                                            T no
                                                    )
{
     // start from first node
    struct SinglyCLLnode<T>* temp = first;
    int iPos = 1;

    // if list is empty
    if (temp == NULL) 
    {
        return -1;
    } 

    do
    {
        // check if current node matches
        if (temp->data == no)
        {
            return iPos;
        }

        temp = temp->next;
        iPos++;
    } while (temp != first);   // stop when full circle is completed  

    return -1;  
}

//----------------------------------------------------------------------------------------
//
//	Function Name		:	SinglyCircular_SearchLastOcc
//	Function Date		:	16/09/2025
//	Function Author		:	Sarika Devidas Gadhe
//
//	Parameters:
//		[IN] T no
//			-> element to search in the singly circular linked list
//
//	Description:
//		This function searches for the last occurrence of an element in the 
//		singly circular linked list. 
//		It traverses all nodes and keeps updating the last found position. 
//		If found, it returns the last position (1-based index).
//		If not found, it returns -1.
//
//	Returns:
//		int
//			-> position of last occurrence (1-based index), or -1 if not found
//
//----------------------------------------------------------------------------------------

template <class T>
int SinglyCLL<T> :: SinglyCircular_SearchLastOcc(
                                                            T no
                                                    )
{
    // start from first node
    struct SinglyCLLnode<T>* temp = first;
    int iPos = 1;
    int iLastPos = -1;

     // if list is empty
    if (temp == NULL) 
    {
        return -1;
    } 

    do
    {
        // check if current node matches
        if (temp->data == no)
        {
            iLastPos = iPos;
        }

        // move to next node
        temp = temp->next;
        iPos++;
    } while (temp != first);  

    return iLastPos;  
}

//----------------------------------------------------------------------------------------
//
//	Function Name		:	SinglyCircular_Summation
//	Function Date		:	16/09/2025
//	Function Author		:	Sarika Devidas Gadhe
//
//	Parameters:
//		None
//
//	Description:
//		This function calculates the summation of all elements
//		present in the singly circular linked list. 
//		It traverses through every node, accumulates their values, 
//		and finally returns the total sum.
//		If the list is empty, it returns 0.
//
//	Returns:
//		int
//			-> summation of all node elements in the list
//
//----------------------------------------------------------------------------------------

template <class T>
int SinglyCLL <T> :: SinglyCircular_Summation()
{

    //   
    // Pointer to traverse the list
    //
    struct SinglyCLLnode<T>* temp = first;

    // Variable to store summation
    int iSum = 0;

    // If list is empty
    if (temp == NULL) 
        return 0;

    do
    {
        // Add current node's data
        iSum += temp->data;

        temp = temp->next;
    } while (temp != first);  

    return iSum;
}

//----------------------------------------------------------------------------------------
//
//	Function Name		:	SinglyCircular_Maximum
//	Function Date		:	16/09/2025
//	Function Author		:	Sarika Devidas Gadhe
//
//	Parameters:
//		None
//
//	Description:
//		This function finds the maximum element from the singly 
//		circular linked list. 
//		It traverses all nodes, compares each node's data, 
//		and keeps track of the largest value.
//		If the list is empty, it displays a message and returns -1.
//
//	Returns:
//		int
//			-> maximum element from the list, or -1 if the list is empty
//
//----------------------------------------------------------------------------------------

template <class T>
int SinglyCLL <T> :: SinglyCircular_Maximum()
{
    // Pointer to traverse the list 
    struct SinglyCLLnode<T>* temp = first;  

    if (temp == NULL)   
    {
        cout << "List is empty." << endl;
        return -1;
    }
      
    // Assume first element is maximum
    int iMax = temp->data;

    do
    {
        if (temp->data > iMax)
        {
            iMax = temp->data;
        }

        temp = temp->next;
    } while (temp != first); 
    
    
    // Return maximum element
    return iMax;
}

//----------------------------------------------------------------------------------------
//
//	Function Name		:	SinglyCircular_Minimum
//	Function Date		:	16/09/2025
//	Function Author		:	Sarika Devidas Gadhe
//
//	Parameters:
//		None
//
//	Description:
//		This function finds the minimum element from the singly 
//		circular linked list.
//		It traverses all nodes, compares each node's data, 
//		and keeps track of the smallest value.
//		If the list is empty, it displays a message and returns -1.
//
//	Returns:
//		int
//			-> minimum element from the list, or -1 if the list is empty
//
//----------------------------------------------------------------------------------------

template <class T>
int SinglyCLL <T> :: SinglyCircular_Minimum()
{
    //  
    // Pointer to traverse the list  
    //
    struct SinglyCLLnode<T>* temp = first;  

    // If list is empty
    if (temp == NULL)  
    {
        cout << "List is empty." << endl;
        return -1;
    }

    // Assume first element is minimum
    int iMin = temp->data;

    do
    {
        if (temp->data < iMin)
        {
            iMin = temp->data;
        }

        temp = temp->next;
    } while (temp != first);  

    return iMin;
}

//----------------------------------------------------------------------------------------
//
//	Function Name		:	SinglyCircular_DisplayPerfect
//	Function Date		:	16/09/2025
//	Function Author		:	Sarika Devidas Gadhe
//
//	Parameters:
//		None
//
//	Description:
//		This function traverses the singly circular linked list 
//		and checks each element to determine if it is a Perfect number.
//		
//		A Perfect number is a number that is equal to the sum of 
//		its proper divisors (excluding itself).
//		
//		For each node, the function calculates the sum of divisors 
//		and compares it with the node’s data. 
//		If they match, the number is printed as Perfect.
//
//		If the list is empty, it prints a message.
//
//	Returns:
//		void
//
//----------------------------------------------------------------------------------------

template <class T>
void SinglyCLL <T> :: SinglyCircular_DisplayPerfect()
{
    //
    // Pointer to traverse the list  
    //
    struct SinglyCLLnode<T>* temp = first;  
    int iSum = 0, iCnt = 0;

    //  
    // If list is empty
    //
    if (temp == NULL)  
    {
        printf("Linked list is empty.\n");
        return;
    }

    do
    {
        iSum = 0;

        // Calculate sum of divisors of current node data
        for (iCnt = 1; iCnt <= temp->data / 2; iCnt++)
        {
            if (temp->data % iCnt == 0)
            {
                iSum += iCnt;
            }
        }

        //   
        // If sum of divisors equals the number → Perfect number
        //
        if (iSum == temp->data)
        {
            printf("Perfect number is : %d\n", temp->data);
        }

        temp = temp->next;
    } while (temp != first);  

    printf("\n");
    
}

//----------------------------------------------------------------------------------------
//
//  Function Name       :   SinglyCircular_DisplayPrime
//  Function Date       :   16/09/2025
//  Function Author     :   Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      This function traverses the singly circular linked list and checks each element 
//      to determine if it is a Prime number.
//
//      A Prime number is a number greater than 1 that has no divisors other than 
//      1 and itself.
//
//      For each node, the function checks divisibility of the data value by all numbers 
//      up to data/2. If no divisor is found, the number is identified as Prime and printed.
//
//      If the list is empty, it prints a message.
//
//  Returns:
//      void
//
//----------------------------------------------------------------------------------------

template <class T>
void SinglyCLL <T> :: SinglyCircular_DisplayPrime()
{
    struct SinglyCLLnode<T>* temp = first;  

    if (temp == NULL)              
    {
        printf("Linked list is empty.\n");
        return;
    }

    int iCnt = 0, iFactCnt = 0;

    do
    {
        iFactCnt = 0;

        //  
        // Check divisibility for Prime test
        //
        for(iCnt = 2; iCnt <= temp->data / 2; iCnt++)
        {
            if(temp->data % iCnt == 0)
            {
                iFactCnt++;
                break;
            }
        }

        //   
        // Prime condition
        //
        if((iFactCnt == 0) && (temp->data > 1))
        {
            printf("Prime number is : %d\n", temp->data);
        }

        temp = temp->next;

    } while(temp != first);  

}

//----------------------------------------------------------------------------------------
//
//  Function Name       :   SinglyCircular_SummationEven
//  Function Date       :   16/09/2025
//  Function Author     :   Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      This function traverses the singly circular linked list 
//      and calculates the summation of all EVEN elements.
//
//      For each node, the function checks whether the data value 
//      is divisible by 2 (even). If true, it adds the value to iSum.
//
//      If the list is empty, the function returns 0.
//
//  Returns:
//      int
//          -> The total summation of all even numbers in the list.
//             Returns 0 if the list is empty.
//
//----------------------------------------------------------------------------------------

template <class T>
int SinglyCLL <T> :: SinglyCircular_SummationEven()
{
    //  
    // Pointer to traverse the list
    //
    struct SinglyCLLnode<T>* temp = first;
    int iSum = 0;

    if (temp == NULL)
    {
        return 0;
    }

    do
    {
        //   
        // Check if current data is even
        //
        if (temp->data % 2 == 0)
        {
            iSum += temp->data;
        }

        temp = temp->next;
    } while (temp != first);

    return iSum;
}

//----------------------------------------------------------------------------------------
//
//  Function Name       :   SinglyCircular_SummationOdd
//  Function Date       :   16/09/2025
//  Function Author     :   Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      This function traverses the singly circular linked list 
//      and calculates the summation of all ODD elements.
//
//      For each node, the function checks whether the data value 
//      is not divisible by 2 (odd). If true, it adds the value to iSum.
//
//      If the list is empty, the function returns 0.
//
//  Returns:
//      int
//          -> The total summation of all odd numbers in the list.
//             Returns 0 if the list is empty.
//
//----------------------------------------------------------------------------------------

template <class T>
int SinglyCLL <T> :: SinglyCircular_SummationOdd()
{
    //  
    // Pointer to traverse the list
    //
    struct SinglyCLLnode<T>* temp = first;
    int iSum = 0;

    if (temp == NULL)
    {
        return 0;
    }

    do
    {
        // Check if current data is odd
        if (temp->data % 2 != 0)
        {
            iSum += temp->data;
        }

        temp = temp->next;
    } while (temp != first);

    return iSum;
}

//----------------------------------------------------------------------------------------
//
//  Function Name       :   SinglyCircular_SecMaximum
//  Function Date       :   16/09/2025
//  Function Author     :   Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      This function traverses the singly circular linked list 
//      and finds the **second largest element**.
//
//  Returns:
//      int
//          -> The second largest element in the list.
//             Returns -1 if the list is empty or second maximum does not exist.
//
//---------------------------------------------------------------------------------

template <class T>
int SinglyCLL <T> :: SinglyCircular_SecMaximum()
{
    struct SinglyCLLnode<T>* temp = first;
    if (temp == NULL)
    {
        return -1;
    }

    //
    // Store maximum element
    //
    int iMax = temp->data;

     // Store second maximum element
    int secondMax = -1;
    temp = temp->next;

    do
    {
        if (temp->data > iMax)
        {
            secondMax = iMax;
            iMax = temp->data;
        }
        else if (temp->data > secondMax && temp->data != iMax)
        {
            secondMax = temp->data;
        }
        temp = temp->next;

    } while (temp != first);   // Loop until back at start

    return secondMax;
   
}

//----------------------------------------------------------------------------------------
//
//  Function Name       :   SinglyCircular_SumDigit
//  Function Date       :   16/09/2025
//  Function Author     :   Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      This function traverses the singly circular linked list 
//      and for each node, calculates the sum of its digits.
//
//      Example:
//          Node data = 123 → Sum = 1 + 2 + 3 = 6
//
//      It prints the original number along with the calculated sum.
//
//      If the list is empty, the function simply returns.
//
//  Returns:
//      void
//
//----------------------------------------------------------------------------------------

template <class T>
void SinglyCLL <T> :: SinglyCircular_SumDigit()
{
    //    
    // Pointer to traverse the lis
    //
    struct SinglyCLLnode<T>* temp = first;
    int iDigit = 0, iSum = 0, iNo = 0;

    //  
    // If list is empty
    //
    if (temp == NULL)
    {
        return;
    }

    do
    {
        iNo = temp->data;
        iSum = 0;

        //    
        // Extract digits and calculate sum
        //
        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iSum += iDigit;
            iNo = iNo / 10;
        }

        printf("%d : Sum of Digits is : %d\n", temp->data, iSum);

        temp = temp->next;
        
    } while (temp != first);
   
}


//----------------------------------------------------------------------------------------
//
//  Function Name       :   SinglyCircular_ReverseDigit
//  Function Date       :   16/09/2025
//  Function Author     :   Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      This function traverses the singly circular linked list 
//      and for each node, reverses the digits of the number.
//
//      Example:
//          Node data = 1234 → Reversed = 4321
//
//      It prints the reversed numbers in linked list style format.
//
//      If the list is empty, the function simply returns.
//
//  Returns:
//      void
//
//----------------------------------------------------------------------------------------

template <class T>
void SinglyCLL <T> :: SinglyCircular_ReverseDigit()
{
    struct SinglyCLLnode<T>* temp = first;
    int iDigit = 0, iNo = 0, iRev = 0;

    if (temp == NULL)
    {
        return;
    }

    do
    {
        iNo = temp->data;
        iRev = 0;

         // Extract digits and build reversed number
        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iRev = (iRev * 10) + iDigit;
            iNo = iNo / 10;
        }

        printf("| %d | -> ", iRev);
        temp = temp->next;
    } while (temp != first);

    printf("NULL\n");
}

//----------------------------------------------------------------------------------------
//
//  Function Name       :   SinglyCircular_DisplayPalindrome
//  Function Date       :   16/09/2025
//  Function Author     :   Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      This function traverses the singly circular linked list 
//      and checks each node’s data to determine whether it is a palindrome number.
//
//  Returns:
//      void
//
//----------------------------------------------------------------------------------------

template <class T>
void SinglyCLL <T> :: SinglyCircular_DisplayPalindrome()
{
    struct SinglyCLLnode<T>* temp = first;
    int iDigit = 0, iNo = 0, iRev = 0;

    if (temp == NULL)
    {
        return;
    }

    do
    {
        iNo = temp->data;
        iRev = 0;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iRev = (iRev * 10) + iDigit;
            iNo = iNo / 10;
        }

        //   
        // If reversed number equals original → Palindrome
        //
        if(iRev == temp->data)
        {
            printf("Palindrome number is: %d\n", iRev);
        }

        temp = temp->next;
    } while (temp != first);

    printf("\n");
}

//----------------------------------------------------------------------------------------
//
//  Function Name       :   SinglyCircular_DisplayProduct
//  Function Date       :   16/09/2025
//  Function Author     :   Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      This function traverses the singly circular linked list 
//      and for each node’s data, calculates the product of its digits.
//
//      Important:
//          - While calculating product, digit '0' is ignored 
//            (because multiplying by 0 would make the entire product 0).
//
//      Example:
//          Number = 423 → Digits = 4,2,3 → Product = 24
//          Number = 101 → Digits = 1,0,1 → Product = 1 (ignoring 0)
//
//      If the list is empty, a message "Linked list is empty" is displayed.
//
//  Returns:
//      void
//
//----------------------------------------------------------------------------------------

template <class T>
void SinglyCLL <T> :: SinglyCircular_DisplayProduct()
{
    //
    // Pointer to traverse the list
    //
    struct SinglyCLLnode<T>* temp = first;
   
    if (temp == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }
     
    int iDigit = 0, iNo = 0, iProduct = 1;

    do
    {
        iNo = temp->data;
        iProduct = 1;

        //  
        // Calculate product of digits (ignoring zero)
        //
        while (iNo != 0)
        {
            iDigit = iNo % 10;
            if (iDigit != 0)
            {
                iProduct = iProduct * iDigit;
            }
            iNo = iNo / 10;
        }

        // Print result for current node
        printf("Number : %d → Product of digits = %d\n", temp->data, iProduct);

        temp = temp->next;
    } while (temp != first);

    printf("\n");
}

//----------------------------------------------------------------------------------------
//
//  Function Name       :   SinglyCircular_DisplaySmallDigit
//  Function Date       :   16/09/2025
//  Function Author     :   Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      This function traverses the singly circular linked list 
//      and for each node’s data, finds the smallest digit present in that number.
//
//  Returns:
//      void
//
//----------------------------------------------------------------------------------------

template <class T>
void SinglyCLL <T> :: SinglyCircular_DisplaySmallDigit()
{
    struct SinglyCLLnode<T>* temp = first;

    if (temp == NULL)
        return;

    int iDigit = 0, iNo = 0, iSmall = 0;

    do
    {
        // Get current node data
        iNo = temp->data;

        // Initialize with max possible digit
        iSmall = 10;

        while (iNo != 0)
        {
            iDigit = iNo % 10;
            if (iDigit <= iSmall)
                iSmall = iDigit;
            iNo = iNo / 10;
        }

        printf("Small number is : %d\n", iSmall);

        temp = temp->next;
    } while (temp != first);

    printf("\n");
}

//----------------------------------------------------------------------------------------
//
//  Function Name       :   SinglyCircular_DisplayLargeDigit
//  Function Date       :   16/09/2025
//  Function Author     :   Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      This function traverses the singly circular linked list 
//      and for each node’s data, finds the largest digit present in that number.
//
//  Returns:
//      void
//
//----------------------------------------------------------------------------------------

template <class T>
void SinglyCLL <T> :: SinglyCircular_DisplayLargeDigit()
{
    struct SinglyCLLnode<T>* temp = first;

    if (temp == NULL)
        return;

    int iDigit = 0, iNo = 0, iLarge = 0;

    do
    {
        //  
        // Get current node data
        //
        iNo = temp->data;

        //
        // Initialize with min possible digit
        //
        iLarge = 0;

        while (iNo != 0)
        {
            iDigit = iNo % 10;
            if (iDigit > iLarge)
                iLarge = iDigit;
            iNo = iNo / 10;
        }

        printf("Large number is : %d\n", iLarge);

        temp = temp->next;
    } while (temp != first);

    // New line after traversal
    printf("\n");
}


//----------------------------------------------------------------------------------------
//
//  Class Name     :   DoublyCLL
//  Description    :   Generic implementation of Doubly circular linked list
//  Author         :   Sarika Devidas Gadhe
//  Date           :   16/09/2025
//
//----------------------------------------------------------------------------------------


template <class T>
//
// Node structure for Doubly Circular Linked List
//
struct DoublyCLLnode
{
    // Data of generic type
    T data;

    // Pointer to next node
    struct DoublyCLLnode<T> *next;

    // Pointer to previous node
    struct DoublyCLLnode<T> *prev;
};

//
// Class definition for Doubly Circular Linked List
//
template <class T>
class DoublyCLL
{
    private:
        
        // Pointer to first node
        struct DoublyCLLnode<T> * first;

        // Pointer to last node
        struct DoublyCLLnode<T> * last;

        // Count of nodes in list
        int iCount;

    public:
    
        // Constructor
        DoublyCLL();

        // Insert node at beginning
        void InsertFirst(
                                    T
                            );

        // Insert node at end                    
        void InsertLast(
                                    T
                            );

        // Insert node at specific position                    
        void InsertAtPos(
                                    T,
                                    int
                            );
        
        // Display entire list                    
        void Display();
        
        // Count total nodes
        int Count();

        // Delete first node
        void DeleteFirst();

        // Delete last node
        void DeleteLast();

        // Delete node at specific position
        void DeleteAtPos(
                                    int
                            );
        
        // Search first occurrence                    
        int DoublyCircular_SearchFirstOcc(
                                                        T no
                                            );

        // Search last occurrence                                    
        int DoublyCircular_SearchLastOcc(
                                                    T no
                                            );

        // Sum of all elements                                    
        int DoublyCircular_Summation();

        // Sum of odd numbers
        int DoublyCircular_SummationOdd();

        // Sum of even numbers
        int DoublyCircular_SummationEven();

        // Find maximum element
        int DoublyCircular_Maximum();

        // Find minimum element
        int DoublyCircular_Minimum();

        // Find second maximum element
        int DoublyCircular_SecMaximum();

        // Display sum of digits of each number
        void DoublyCircular_SumDigit();

        // Display reverse of digits of each number
        void DoublyCircular_ReverseDigit();

        // Display smallest digit of each number
        void DoublyCircular_DisplaySmallDigit();

        // Display largest digit of each number
        void DoublyCircular_DisplayLargeDigit();

        // Display perfect numbers
        void DoublyCircular_DisplayPerfect();

        // Display prime numbers
        void DoublyCircular_DisplayPrime();

        // Display palindrome numbers
        void DoublyCircular_DisplayPalindrome();

        // Display product of digits of each number
        void DoublyCircular_DisplayProduct();
};

//----------------------------------------------------------------------------------------
//
//  Function Name    :   DoublyCLL
//  Function Date    :   16/09/2025
//  Function Author  :   Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      This is the constructor for the Doubly Circular Linked List class.
//      It initializes the list pointers (first, last) to NULL and 
//      sets the node count (iCount) to zero.
//
//  Returns:
//      None

//
//----------------------------------------------------------------------------------------

template <class T>
DoublyCLL<T> :: DoublyCLL()
{
    cout<<"Inside Constructor\n";
    
    // Initialize first pointer
    first = NULL;

    // Initialize last pointer
    last = NULL;

    // Initialize node count
    iCount = 0;
}

//----------------------------------------------------------------------------------------
//
//  Function Name       :   InsertFirst
//  Function Date       :   16/09/2025
//  Function Author     :   Sarika Devidas Gadhe
//
//  Parameters:
//      [IN] T no
//          -> data to be inserted at the beginning of the doubly circular linked list
//
//  Description:
//      This function inserts a new node at the beginning of the doubly circular linked list.
//
//  Returns:
//      void
//
//----------------------------------------------------------------------------------------

template <class T>
void DoublyCLL<T> :: InsertFirst(
                                            T no
                                    )
{
    struct DoublyCLLnode<T> * newn = NULL;

    //  
    // Allocate memory for new node
    //
    newn = new struct DoublyCLLnode<T>;
    
    //
    // Initialize new node
    //
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    //
    // LL is empty
    //
    if(first == NULL && last == NULL)  
    {
        first = newn;
        last = newn;
    }   

    //  
    // LL contains atleast one node
    //
    else   
    {
        newn->next = first;
        first->prev = newn;

        first = newn;
    } 

    last->next = first;
    first->prev = last;

    iCount++;
}

//----------------------------------------------------------------------------------------
//
//  Function Name       :   InsertLast
//  Function Date       :   16/09/2025
//  Function Author     :   Sarika Devidas Gadhe
//
//  Parameters:
//      [IN] T no
//          -> data to be inserted at the end of the doubly circular linked list
//
//  Description:
//      This function inserts a new node at the end of the doubly circular linked list.
//
//  Returns:
//      void
//
//----------------------------------------------------------------------------------------

template <class T>
void DoublyCLL<T> :: InsertLast(
                                            T no
                                    )
{
    struct DoublyCLLnode<T> * newn = NULL;

    //    
    // Allocate memory for new node
    //
    newn = new struct DoublyCLLnode<T>;
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    //  
    // LL is empty
    //
    if(first == NULL && last == NULL)   
    {
        first = newn;
        last = newn;
    }   

    //   
    // LL contains atleast one node
    //
    else    
    {
        last->next = newn;
        newn->prev = last;

        // Update last pointer
        last = newn;
    } 

    last->next = first;
    first->prev = last;
    
    //   
    // Increment node count
    //
    iCount++;
}

//----------------------------------------------------------------------------------------
//
//  Function Name       :   Display
//  Function Date       :   16/09/2025
//  Function Author     :   Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      This function traverses and displays all elements of the doubly circular linked list.
//
//  Returns:
//      void
//
//----------------------------------------------------------------------------------------

template <class T>
void DoublyCLL<T> :: Display()
{
    struct DoublyCLLnode<T> * temp = NULL;
    cout<<"Elements of the LinkedList are : \n";

    temp = first;

    //  
    // Check if list is empty
    //
    if(first == NULL && last == NULL)
    {
        cout<<"LinkedList is empty\n";
        return;
    }

    //  
    // Traverse and display each node
    //
    do
    {
        cout<<"| "<< temp->data <<" | <=> ";
        temp = temp->next;   
    } while (temp != first);
    cout<<"\n";
}

//----------------------------------------------------------------------------------------
//
//  Function Name       :   Count
//  Function Date       :   16/09/2025
//  Function Author     :   Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      Returns the total number of nodes currently present in the doubly circular linked list.
//
//  Returns:
//      int
//          -> Number of nodes in the list (iCount)
//
//----------------------------------------------------------------------------------

template <class T>
int DoublyCLL<T> :: Count()
{
    return iCount;  
}

//----------------------------------------------------------------------------------------
//
//  Function Name       :   DeleteFirst
//  Function Date       :   16/09/2025
//  Function Author     :   Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      Deletes the first node of the doubly circular linked list.
//
//  Returns:
//      void
//
//----------------------------------------------------------------------------------------

template <class T>
void DoublyCLL<T> :: DeleteFirst()
{
    //
    // LL is empty
    //
    if(first == NULL && last == NULL)   
    {
        return;
    }

    //
    // LL contains 1 node
    //
    else if(first == last)  
    {
        delete first;
    
        first = NULL;
        last = NULL;
    }

    //
    // LL contains more than 1 nodes
    //
    else   
    {
        first = first -> next;
        delete first->prev;     

        last->next = first;
        first->prev = last;
    }

    iCount--;
}

//----------------------------------------------------------------------------------------
//
//  Function Name       :   DeleteLast
//  Function Date       :   16/09/2025
//  Function Author     :   Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      Deletes the last node of the doubly circular linked list.
//
//  Returns:
//      void
//
//----------------------------------------------------------------------------------------

template <class T>
void DoublyCLL<T> :: DeleteLast()
{
    //
    // LL is empty
    //
    if(first == NULL && last == NULL)   
    {
        return;
    }

    //   
    // LL contains 1 node
    //
    else if(first == last)  
    {
        delete last;
    
        first = NULL;
        last = NULL;
    }

    //  
    // LL contains more than 1 nodes
    //
    else    
    {
        last = last -> prev;
        delete last->next;

        last->next = first;
        first->prev = last;
    }

    iCount--;
}

//----------------------------------------------------------------------------------------
//
//  Function Name       :   InsertAtPos
//  Function Date       :   16/09/2025
//  Function Author     :   Sarika Devidas Gadhe
//
//  Parameters:
//      [IN] T no
//          -> data to insert into the doubly circular linked list
//      [IN] int pos
//          -> position at which the new node should be inserted
//
//  Description:
//      Inserts a new node at a specific position in the doubly circular linked list.
//  Returns:
//      void
//
//--------------------------------------------------------------------------------------

template <class T>
void DoublyCLL<T> :: InsertAtPos(
                                                T no, 
                                                int pos
                                    )
{
    //   
    // Temporary pointer for traversal
    //
    struct DoublyCLLnode<T> * temp = NULL;

    //
    // Pointer for new node
    //
    struct DoublyCLLnode<T> * newn = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    //  
    // Insert at first position
    //
    if(pos == 1)
    {
        InsertFirst(no);
    }

    //  
    // Insert at last position
    //
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }

    //   
    // Insert in middle
    //
    else
    {
        newn = new struct DoublyCLLnode<T>;
        
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

//----------------------------------------------------------------------------------------
//
//  Function Name       :   DeleteAtPos
//  Function Date       :   16/09/2025
//  Function Author     :   Sarika Devidas Gadhe
//
//  Parameters:
//      [IN] int pos
//          -> position of the node to delete (1-based index)
//
//  Description:
//      Deletes a node at a specific position in the doubly circular linked list.
//
//  Returns:
//      void
//
//----------------------------------------------------------------------------------------

template <class T>
void DoublyCLL<T> :: DeleteAtPos(
                                             int pos
                                    )
{
    struct DoublyCLLnode<T> * temp = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    //  
    // Delete first node
    //
    if(pos == 1)
    {
        DeleteFirst();
    }

    //   
    // Delete last node
    //
    else if(pos == iCount)
    {
        DeleteLast();
    }

    //  
    // Delete middle node
    //
    else
    {
        temp = first;

        // Traverse to (pos-1)th node
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}

//----------------------------------------------------------------------------------------
//
//  Function Name       :   DoublyCircular_SearchFirstOcc
//  Function Date       :   16/09/2025
//  Function Author     :   Sarika Devidas Gadhe
//
//  Parameters:
//      [IN] T no
//          -> element to search in the doubly circular linked list
//
//  Description:
//      This function searches for the first occurrence of an element in the 
//      doubly circular linked list. 
//
//  Returns:
//      int
//          -> position of first occurrence (1-based index), or -1 if not found
//
//----------------------------------------------------------------------------------------

template <class T>
int DoublyCLL <T>:: DoublyCircular_SearchFirstOcc(
                                                                T no
                                                    )
{
    struct DoublyCLLnode<T>* temp = first;
    int iPos = 1;

    //  
    // List is empty
    //
    if (temp == NULL) 
    {
        return -1;
    } 

    do
    {
        if (temp->data == no)
        {
            return iPos;
        }

        temp = temp->next;
        iPos++;
    } while (temp != first);  

    return -1;  
}

//----------------------------------------------------------------------------------------
//
//  Function Name       :   DoublyCircular_SearchLastOcc
//  Function Date       :   16/09/2025
//  Function Author     :   Sarika Devidas Gadhe
//
//  Parameters:
//      [IN] T no
//          -> element to search in the doubly circular linked list
//
//  Description:
//      This function searches for the last occurrence of an element in the 
//      doubly circular linked list. 
//
//  Returns:
//      int
//          -> position of last occurrence (1-based index), or -1 if not found
//
//----------------------------------------------------------------------------------------

template <class T>
int DoublyCLL<T> :: DoublyCircular_SearchLastOcc(
                                                            T no
                                                    )
{
    struct DoublyCLLnode<T>* temp = first;
    int iPos = 1;
    int iLastPos = -1;

    //   
    // List is empty
    //
    if (temp == NULL) 
    {
        return -1;
    } 

    do
    {
        if (temp->data == no)
        {
            iLastPos = iPos;
        }

        temp = temp->next;
        iPos++;
    } while (temp != first);  

    return iLastPos;  
}

//----------------------------------------------------------------------------------------
//
//  Function Name       :   DoublyCircular_Summation
//  Function Date       :   16/09/2025
//  Function Author     :   Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      This function traverses the doubly circular linked list and calculates 
//      the sum of all node data values. 
//      It starts from the 'first' node and iterates until it comes back to 'first'.
//
//  Returns:
//      int
//          -> Sum of all elements in the doubly circular linked list
//          -> Returns 0 if the list is empty
//
//------------------------------------------------------------------------------

template <class T>
int DoublyCLL <T> :: DoublyCircular_Summation()
{

    //
    // Pointer to traverse the list
    //
    struct DoublyCLLnode<T>* temp = first;
    int iSum = 0;

    if (temp == NULL) 
        return 0;

    do
    {
        // Add current node data to sum
        iSum += temp->data;

        temp = temp->next;

        // Stop after full traversal
    } while (temp != first);  

    return iSum;
}

//----------------------------------------------------------------------------------------
//
//  Function Name       :   DoublyCircular_Maximum
//  Function Date       :   16/09/2025
//  Function Author     :   Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      This function traverses the doubly circular linked list and finds 
//      the maximum value among all the nodes.
//      It starts from the 'first' node and iterates until it comes back to 'first'.
//
//  Returns:
//      int
//          -> Maximum value present in the doubly circular linked list
//          -> Returns -1 if the list is empty
//
//----------------------------------------------------------------------------------------

template <class T>
int DoublyCLL <T> :: DoublyCircular_Maximum()
{
    //
    // Pointer to traverse the list
    //
    struct DoublyCLLnode<T>* temp = first;  

    //
    // List is empty
    //
    if (temp == NULL)   
    {
        cout << "List is empty." << endl;
        return -1;
    }

    //    
    // Initialize maximum with first node's data
    //
    int iMax = temp->data;

    do
    {
        if (temp->data > iMax)
        {
            iMax = temp->data;
        }

        temp = temp->next;
    } while (temp != first); 

    return iMax;
}

//----------------------------------------------------------------------------------------
//
//  Function Name       :   DoublyCircular_Minimum
//  Function Date       :   16/09/2025
//  Function Author     :   Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      This function traverses the doubly circular linked list and finds 
//      the minimum value among all the nodes.
//      It starts from the 'first' node and iterates until it comes back to 'first'.
//
//  Returns:
//      int
//          -> Minimum value present in the doubly circular linked list
//          -> Returns -1 if the list is empty
//
//----------------------------------------------------------------------------------------

template <class T>
int DoublyCLL <T> :: DoublyCircular_Minimum()
{
    //
    // Pointer to traverse the list
    //
    struct DoublyCLLnode<T>* temp = first;  
    
    //
    // List is empty
    //
    if (temp == NULL)  
    {
        cout << "List is empty." << endl;
        return -1;
    }

    //  
    // Initialize minimum with first node's data
    //
    int iMin = temp->data;

    do
    {
        //  
        // Update minimum if current data is smaller
        //
        if (temp->data < iMin)
        {
            iMin = temp->data;
        }

        temp = temp->next;

        // Stop after full traversal
    } while (temp != first);  

    return iMin;
}

//----------------------------------------------------------------------------------------
//
//  Function Name       :   DoublyCircular_DisplayPerfect
//  Function Date       :   16/09/2025
//  Function Author     :   Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      This function traverses the doubly circular linked list and checks 
//      each node's data to determine if it is a Perfect number.
//
//  Returns:
//      void
//
//----------------------------------------------------------------------------------------

template <class T>
void DoublyCLL <T> :: DoublyCircular_DisplayPerfect()
{
    struct DoublyCLLnode<T>* temp = first;  
    int iSum = 0, iCnt = 0;

    if (temp == NULL)  
    {
        printf("Linked list is empty.\n");
        return;
    }

    do
    {
        iSum = 0;

        //   
        // Calculate sum of proper divisors
        //
        for (iCnt = 1; iCnt <= temp->data / 2; iCnt++)
        {
            if (temp->data % iCnt == 0)
            {
                iSum += iCnt;
            }
        }

        //   
        // If sum of divisors equals the number, it's a perfect number
        // 
        if (iSum == temp->data)
        {
            printf("Perfect number is : %d\n", temp->data);
        }

        temp = temp->next;
    } while (temp != first);  

    //
    // Print a new line after traversal
    //
    printf("\n");
    
}

//----------------------------------------------------------------------------------------
//
//  Function Name       :   DoublyCircular_DisplayPrime
//  Function Date       :   16/09/2025
//  Function Author     :   Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      This function traverses the doubly circular linked list and checks 
//      each node's data to determine if it is a prime number.
//
//      A Prime number is a number greater than 1 that has no divisors 
//      other than 1 and itself.
//
//      For each node, the function checks divisibility from 2 to half of the number.
//      If no divisors are found, the number is printed as prime.
//
//      If the list is empty, it prints a message.
//
//  Returns:
//      void
//
//---------------------------------------------------------------------------------

template <class T>
void DoublyCLL <T> :: DoublyCircular_DisplayPrime()
{
    struct DoublyCLLnode<T>* temp = first;  

    //
    // Check if the list is empty
    //
    if (temp == NULL)              
    {
        printf("Linked list is empty.\n");
        return;
    }

    int iCnt = 0, iFactCnt = 0;

    do
    {
        iFactCnt = 0;

        for(iCnt = 2; iCnt <= temp->data / 2; iCnt++)
        {
            if(temp->data % iCnt == 0)
            {
                iFactCnt++;
                
                // If a divisor is found, no need to check further
                break;
            }
        }

        //  
        // If no divisors found and number > 1, it is prime
        //
        if((iFactCnt == 0) && (temp->data > 1))
        {
            printf("Prime number is : %d\n", temp->data);
        }

        temp = temp->next;

    } while(temp != first);  

}

//----------------------------------------------------------------------------------------
//
//  Function Name       :   DoublyCircular_SummationEven
//  Function Date       :   16/09/2025
//  Function Author     :   Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      This function traverses the doubly circular linked list and calculates 
//      the summation of all even numbers present in the list.
//
//  Returns:
//      int
//          -> The sum of all even numbers in the list.
//
//----------------------------------------------------------------------------------------

template <class T>
int DoublyCLL <T> :: DoublyCircular_SummationEven()
{
    struct DoublyCLLnode<T>* temp = first;
    int iSum = 0;

    if (temp == NULL)
    {
        return 0;
    }

    do
    {
        //   
        // Check if data is even
        //
        if (temp->data % 2 == 0)
        {
            iSum += temp->data;
        }

        temp = temp->next;
    } while (temp != first);

    return iSum;
}

//----------------------------------------------------------------------------------------
//
//  Function Name       :   DoublyCircular_SummationOdd
//  Function Date       :   16/09/2025
//  Function Author     :   Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      This function traverses the doubly circular linked list and calculates 
//      the summation of all odd numbers present in the list.
//
//  Returns:
//      int
//          -> The sum of all odd numbers in the list.
//
//----------------------------------------------------------------------------------------

template <class T>
int DoublyCLL <T> :: DoublyCircular_SummationOdd()
{
    struct DoublyCLLnode<T>* temp = first;

    //  
    // Initialize sum
    //
    int iSum = 0;

    if (temp == NULL)
    {
        return 0;
    }

    do
    {
        //  
        // Check if data is odd
        //
        if (temp->data % 2 != 0)
        {
            iSum += temp->data;
        }

        temp = temp->next;
    } while (temp != first);

    return iSum;
}

//----------------------------------------------------------------------------------------
//
//  Function Name       :   DoublyCircular_SecMaximum
//  Function Date       :   16/09/2025
//  Function Author     :   Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      This function finds the second maximum element in a doubly circular linked list.
//
//  Returns:
//      int
//          -> The second maximum value in the list, or -1 if it does not exist.
//
//----------------------------------------------------------------------------------------

template <class T>
int DoublyCLL <T> :: DoublyCircular_SecMaximum()
{
    struct DoublyCLLnode<T>* temp = first;

    //
    // Empty list check
    //
    if (temp == NULL)
    {
        return -1;
    }

    int iMax = temp->data;
    int secondMax = -1;
    temp = temp->next;

    do
    {
        if (temp->data > iMax)
        {
            secondMax = iMax;
            iMax = temp->data;
        }
        else if (temp->data > secondMax && temp->data != iMax)
        {
            secondMax = temp->data;
        }
        temp = temp->next;

    } while (temp != first);

    return secondMax;
   
}

//----------------------------------------------------------------------------------------
//
//  Function Name       :   DoublyCircular_SumDigit
//  Function Date       :   16/09/2025
//  Function Author     :   Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      This function traverses the doubly circular linked list and computes 
//      the sum of digits for each node’s data.
//
//  Returns:
//      void
//
//------------------------------------------------------------------------------------

template <class T>
void DoublyCLL <T> :: DoublyCircular_SumDigit()
{
    struct DoublyCLLnode<T>* temp = first;
    int iDigit = 0, iSum = 0, iNo = 0;

    if (temp == NULL)
    {
        return;
    }

    do
    {
        iNo = temp->data;
        iSum = 0;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iSum += iDigit;
            iNo = iNo / 10;
        }

        printf("%d : Sum of Digits is : %d\n", temp->data, iSum);

        temp = temp->next;
        
    } while (temp != first);
   
}

//----------------------------------------------------------------------------------------
//
//  Function Name       :   DoublyCircular_ReverseDigit
//  Function Date       :   16/09/2025
//  Function Author     :   Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      This function traverses the doubly circular linked list and reverses the digits
//      of each node’s data. 
//
//  Returns:
//      void
//
//-------------------------------------------------------------------------------------

template <class T>
void DoublyCLL <T> :: DoublyCircular_ReverseDigit()
{
    //    
    // Pointer to traverse the list
    //
    struct DoublyCLLnode<T>* temp = first;
    int iDigit = 0, iNo = 0, iRev = 0;

    //    
    // Check if list is empty
    //
    if (temp == NULL)
    {
        return;
    }

    do
    {
        // Current node value
        iNo = temp->data;
        iRev = 0;

        //
        // Reverse digits of the current node
        // 
        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iRev = (iRev * 10) + iDigit;
            iNo = iNo / 10;
        }

        //  
        // Print reversed number in linked format
        //
        printf("| %d | -> ", iRev);
        temp = temp->next;
    } while (temp != first);

    printf("NULL\n");
}

//----------------------------------------------------------------------------------------
//
//  Function Name       :   DoublyCircular_DisplayPalindrome
//  Function Date       :   16/09/2025
//  Function Author     :   Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      This function traverses the doubly circular linked list and identifies nodes
//      whose data is a palindrome number.
//
//  Returns:
//      void
//
//----------------------------------------------------------------------------------------

template <class T>
void DoublyCLL <T> :: DoublyCircular_DisplayPalindrome()
{
    //
    // Pointer to traverse the list
    //
    struct DoublyCLLnode<T>* temp = first;
    int iDigit = 0, iNo = 0, iRev = 0;

    // Check if list is empty
    if (temp == NULL)
    {
        return;
    }

    do
    {
        iNo = temp->data;
        iRev = 0;

        //
        // Reverse digits of the current node
        // 
        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iRev = (iRev * 10) + iDigit;
            iNo = iNo / 10;
        }

        //
        // Check if the number is a palindrome
        //
        if(iRev == temp->data)
        {
            printf("Palindrome number is: %d\n", iRev);
        }

        temp = temp->next;
    } while (temp != first);

    printf("\n");
}

//----------------------------------------------------------------------------------------
//
//  Function Name       :   DoublyCircular_DisplayProduct
//  Function Date       :   16/09/2025
//  Function Author     :   Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      This function traverses the doubly circular linked list and calculates the 
//      product of digits for each node's data.
//
//  Returns:
//      void
//
//-------------------------------------------------------------------------------------

template <class T>
void DoublyCLL <T> :: DoublyCircular_DisplayProduct()
{
    //
    // Pointer to traverse the list
    //
    struct DoublyCLLnode<T>* temp = first;
   
    //   
    // Check if list is empty
    //
    if (temp == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }
     
    int iDigit = 0, iNo = 0, iProduct = 1;

    do
    {
        iNo = temp->data;
        iProduct = 1;

        while (iNo != 0)
        {
            iDigit = iNo % 10;
            if (iDigit != 0)
            {
                iProduct = iProduct * iDigit;
            }
            iNo = iNo / 10;
        }

        // Print the result for current node
        printf("Number : %d → Product of digits = %d\n", temp->data, iProduct);

        temp = temp->next;
    } while (temp != first);

    printf("\n");
}

//----------------------------------------------------------------------------------------
//
//  Function Name       :   DoublyCircular_DisplaySmallDigit
//  Function Date       :   16/09/2025
//  Function Author     :   Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      This function traverses the doubly circular linked list and finds the 
//      smallest digit in each node's data.
//
//  Returns:
//      void
//
//---------------------------------------------------------------------------------------

template <class T>
void DoublyCLL <T> :: DoublyCircular_DisplaySmallDigit()
{
    //
    // Pointer to traverse the list
    //
    struct DoublyCLLnode<T>* temp = first;

    if (temp == NULL)
        return;

    int iDigit = 0, iNo = 0, iSmall = 0;

    do
    {
        iNo = temp->data;
        iSmall = 10;

        while (iNo != 0)
        {
            iDigit = iNo % 10;

            // Compare with current smallest
            if (iDigit <= iSmall)
                iSmall = iDigit;
            iNo = iNo / 10;
        }

        printf("Small number is : %d\n", iSmall);

        temp = temp->next;
    } while (temp != first);

    printf("\n");
}

//----------------------------------------------------------------------------------------
//
//  Function Name       :   DoublyCircular_DisplayLargeDigit
//  Function Date       :   16/09/2025
//  Function Author     :   Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      This function traverses the doubly circular linked list and finds the 
//      largest digit in each node's data.
//
//  Returns:
//      void
//
//----------------------------------------------------------------------------------------

template <class T>
void DoublyCLL <T> :: DoublyCircular_DisplayLargeDigit()
{
    //
    // Pointer to traverse the list
    //
    struct DoublyCLLnode<T>* temp = first;

    if (temp == NULL)
        return;

    int iDigit = 0, iNo = 0, iLarge = 0;

    do
    {
        iNo = temp->data;
        iLarge = 0;

        while (iNo != 0)
        {
            iDigit = iNo % 10;
            if (iDigit > iLarge)
                iLarge = iDigit;
            iNo = iNo / 10;
        }

        //    
        // Print the largest digit for this node
        //
        printf("Large number is : %d\n", iLarge);

        temp = temp->next;
    } while (temp != first);

    printf("\n");
}


//----------------------------------------------------------------------------------------
//
//  Class Name     :   SinglyLinearLL
//  Description    :   Generic implementation of Singly Linear linked list
//  Author         :   Sarika Devidas Gadhe
//  Date           :   16/09/2025
//
//----------------------------------------------------------------------------------------


template <class T>
struct SinglyLinearLLnode
{
    //
    // Data part of the node
    //
    T data;

    // Pointer to the next node
    struct SinglyLinearLLnode<T> * next;
    
};

template <class T>
class SinglyLinearLL
{
    private:
        
        // Pointer to first node of the list
        struct SinglyLinearLLnode <T> *first;
        int iCount;

    public:
    
        // Constructor
        SinglyLinearLL();
    

        // Insert node at beginning
        void InsertFirst(
                                    T
                            );

        // Insert node at end                    
        void InsertLast(
                                    T
                            );

        // Insert node at specific position                    
        void InsertAtPos(
                                    T,
                                    int
                            );
        
        // Display entire list                    
        void Display();
        
        // Count total nodes
        int Count();

        // Delete first node
        void DeleteFirst();

        // Delete last node
        void DeleteLast();

        // Delete node at specific position
        void DeleteAtPos(
                                    int
                            );
        
        // Search first occurrence                    
        int SinglyLinear_SearchFirstOcc(
                                                        T no
                                            );

        // Search last occurrence                                    
        int SinglyLinear_SearchLastOcc(
                                                    T no
                                            );

        // Sum of all elements                                    
        int SinglyLinear_Summation();

        // Sum of odd numbers
        int SinglyLinear_SummationOdd();

        // Sum of even numbers
        int SinglyLinear_SummationEven();

        // Find maximum element
        int SinglyLinear_Maximum();

        // Find minimum element
        int SinglyLinear_Minimum();

        // Find second maximum element
        int SinglyLinear_SecMaximum();

        // Display sum of digits of each number
        void SinglyLinear_SumDigit();

        // Display reverse of digits of each number
        void SinglyLinear_ReverseDigit();

        // Display smallest digit of each number
        void SinglyLinear_DisplaySmallDigit();

        // Display largest digit of each number
        void SinglyLinear_DisplayLargeDigit();

        // Display perfect numbers
        void SinglyLinear_DisplayPerfect();

        // Display prime numbers
        void SinglyLinear_DisplayPrime();

        // Display palindrome numbers
        void SinglyLinear_DisplayPalindrome();

        // Display product of digits of each number
        void SinglyLinear_DisplayProduct();

};

//----------------------------------------------------------------------------------------
//
//  Function Name   : SinglyLinearLL
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      Initializes an empty singly linear linked list.
//      Sets the first pointer to NULL and node count to 0.
//
//  Returns:
//      void
//
//----------------------------------------------------------------------------------------

template <class T>
SinglyLinearLL <T>:: SinglyLinearLL()
{
    cout<<"Inside Constructor\n";
    first = NULL;
    iCount = 0;
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : InsertFirst
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters:
//      [IN] T no
//          -> Element to insert at the beginning of the list
//
//  Description:
//      Creates a new node and inserts it at the start of the singly linear linked list.
//      Updates the first pointer and increments node count.
//
//  Returns:
//      void
//
//----------------------------------------------------------------------------------------

template <class T>
void SinglyLinearLL <T> :: InsertFirst(
                                                    T no
                                        )
{
    struct SinglyLinearLLnode<T> *newn = NULL;

    newn = new struct SinglyLinearLLnode <T>;
    newn->data = no;
    newn->next = NULL;

    //  
    // List is empty
    //
    if(first == NULL)
    {
        first = newn;
    }

    //   
    // List contains at least one node
    //
    else
    {
        newn->next = first;
        first = newn;
    }

    iCount++;

}

//----------------------------------------------------------------------------------------
//
//  Function Name   :   InsertLast
//  Function Date   :   16/09/2025
//  Function Author :   Sarika Devidas Gadhe
//
//  Parameters:
//      [IN] T no
//          -> Element to insert at the end of the list
//
//  Description:
//      Creates a new node and inserts it at the end of the singly linear linked list.
//      Traverses the list to find the last node and updates its next pointer.
//
//  Returns:
//      void
//
//----------------------------------------------------------------------------------------

template <class T>
void SinglyLinearLL <T>:: InsertLast(
                                                T no
                                        )
{
    //  
    // Memory allocated
    //
    struct SinglyLinearLLnode <T> *newn = NULL;
    newn = new struct SinglyLinearLLnode <T>;

    struct SinglyLinearLLnode <T> *temp = NULL;

    newn->data = no;
    newn->next = NULL;

    //  
    // If list is empty
    //
    if(first == NULL)
    {
        first = newn;
    }

    //  
    // List contains at least one node
    //  
    else
    {
       temp = first;

       while(temp->next != NULL)
       {
            temp = temp->next;
       }
       temp->next = newn;

    }

    iCount++;
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : DeleteFirst
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      Deletes the first node of the singly Linear linked list.
//      - If the list is empty, does nothing.
//      - If the list has one node, deletes it and sets 'first' to NULL.
//      - If the list has multiple nodes, updates 'first' to the next node and deletes the old first node.
//      - Decrements the node count 'iCount'.
//
//  Returns:
//      void
//
//------------------------------------------------------------------------------------

template <class T>
void SinglyLinearLL<T> :: DeleteFirst()
{
    struct SinglyLinearLLnode <T>*temp = NULL;

    //  
    // Empty list
    //
    if(first == NULL)
    {
        return;
    }

    //
    // Only one node
    //
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }

    //
    // More than one node
    //
    else
    {
        temp = first;
        
        first = first->next;
        delete temp;
    }
    iCount--;
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : DeleteLast
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      Deletes the last node of the singly Linear linked list.
//
//  Returns:
//      void
//
//------------------------------------------------------------------------------------

template <class T>
void SinglyLinearLL<T> :: DeleteLast()
{
    struct SinglyLinearLLnode <T>*temp = NULL;

    //
    // If the list is empty, nothing to delete
    //
    if(first == NULL)
    {
        return;
    }

    //  
    // If the list has only one node
    //
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }

    //
    // If the list has more than one node
    //
    else
    {
        temp = first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : InsertAtPos
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters:
//      T no     : The data to insert
//      int pos  : Position at which to insert the node (1-based index)
//
//  Description:
//      Inserts a new node with the given data at the specified position
//      in the singly linear linked list. Handles three cases:
//          1. Insert at the beginning (pos == 1)
//          2. Insert at the end (pos == iCount + 1)
//          3. Insert at a middle position
//
//  Returns:
//      void
//
//----------------------------------------------------------------------------------------

template <class T>
void SinglyLinearLL <T>:: InsertAtPos(
                                                    T no, 
                                                    int pos
                                        )
{
    struct SinglyLinearLLnode <T>*newn = NULL;
    struct SinglyLinearLLnode <T>*temp = NULL;
    int i = 0;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid Position\n";
        return;
    }

    //  
    // Insert at beginning
    //
    if(pos == 1)
    {
        InsertFirst(no);
    }

    //  
    // Insert at end
    //
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        temp = first;

        //  
        // Allocate memory
        //
        newn = new struct SinglyLinearLLnode<T>;
        newn->data = no;
        newn->next = NULL;

        for(int i = 1;i<pos-1;i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : DeleteAtPos
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters:
//      int pos  : Position of the node to delete (1-based index)
//
//  Description:
//      Deletes the node at the specified position in the singly linear linked list.
//      Handles three cases:
//          1. Delete the first node (pos == 1)
//          2. Delete the last node (pos == iCount)
//          3. Delete a node in between
//
//  Returns:
//      void
//
//----------------------------------------------------------------------------------------

template <class T>
void SinglyLinearLL<T> :: DeleteAtPos(
                                                    int pos
                                        )
{
    struct SinglyLinearLLnode <T>*temp = NULL;
    struct SinglyLinearLLnode <T>*target = NULL;
    int i = 0;

     // Validate position
    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid Position\n";
        return;
    }

    //  
    // Delete first node
    //
    if(pos == 1)
    {
        DeleteFirst();
    }

    //  
    // Delete last node
    //
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;
         
        // Traverse to node before target
        for(int i = 1;i<pos-1;i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        delete target;

        iCount--;
    }
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : Display
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      Traverses and prints all nodes of the singly linear linked list in order.
//      The list is displayed in the format: | data | -> ... -> NULL
//
//  Returns:
//      void
//
//----------------------------------------------------------------------------------------

template <class T>
void SinglyLinearLL <T>:: Display()
{
    struct SinglyLinearLLnode <T>* temp = NULL;

    //  
    // Start from first node
    //
    temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    }
    cout<<"NULL\n";

}

//----------------------------------------------------------------------------------------
//
//  Function Name   : Count
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      Returns the total number of nodes currently present in the singly linear linked list.
//
//  Returns:
//      int : Number of nodes (iCount)
//
//------------------------------------------------------------------------------------

template <class T>
int SinglyLinearLL <T>:: Count()
{
    // Simply return node count
    return iCount;
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : SinglyLinear_SearchFirstOcc
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters:
//      T no  : Data value to search for
//
//  Description:
//      Searches for the first occurrence of the specified value in the singly linear linked list.
//      Traverses the list from the beginning and returns the position (1-based index) of the first match.
//
//  Returns:
//      int : Position of first occurrence, or undefined if value not found
//
//----------------------------------------------------------------------------------------

template <class T>
int SinglyLinearLL <T>:: SinglyLinear_SearchFirstOcc(
                                                                T no
                                                        )
{
    //  
    // Start from first node
    //
    struct SinglyLinearLLnode <T>* temp = NULL;

    temp = first;

    int iPos = 1;

    while(temp->data != no)
    {
        iPos++;
        temp = temp->next;
    }

    return iPos;
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : SinglyLinear_SearchLastOcc
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters:
//      T no  : Data value to search for
//
//  Description:
//      Searches for the last occurrence of the specified value in the singly linear linked list.
//
//  Returns:
//      int : Position of last occurrence, or -1 if value not found
//
//----------------------------------------------------------------------------------------

template <class T>
int SinglyLinearLL <T> :: SinglyLinear_SearchLastOcc(
                                                                T no
                                                        )
{

    struct SinglyLinearLLnode <T>* temp = NULL;

    //  
    // Start from first node
    //
    temp = first;

    int iPos = 1;
    int iLastPos = -1;

    while(temp != NULL)
    {
        if(temp->data == no)
        {
            iLastPos = iPos;
        }

        temp = temp->next;
        iPos++;
    }

    //
    // Return last occurrence position or -1
    //
    return iLastPos;
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : SinglyLinear_Summation
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      Traverses the singly linear linked list and calculates the sum of all node data values.
//
//  Returns:
//      int : Sum of all elements in the linked list
//
//----------------------------------------------------------------------------------------

template <class T>
int SinglyLinearLL <T> :: SinglyLinear_Summation()
{
    struct SinglyLinearLLnode <T>* temp = NULL;

    temp = first;

    //  
    // Initialize sum
    //
    int iSum = 0;

    while(temp != NULL)
    {
        iSum = iSum + temp->data;
        temp = temp->next;
    }

    return iSum;
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : SinglyLinear_Maximum
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      Traverses the singly linear linked list to find the maximum element.
//
//  Returns:
//      int : Maximum element in the linked list, or -1 if the list is empty
//
//----------------------------------------------------------------------------------------

template <class T>
int SinglyLinearLL <T> :: SinglyLinear_Maximum()
{
    struct SinglyLinearLLnode <T>* temp = NULL;

    // Start from first node
    temp = first;

    // Check for empty list
    if (temp == NULL)   
    {
        cout << "List is empty." << endl;
        return -1;    
    }

    //  
    // Initialize maximum with first node's data
    //
    int iMax = temp->data;

    while(temp != NULL)
    {
        if(iMax < temp->data)
        {
            iMax = temp->data;
        }
        temp = temp->next;
    }

    return iMax;
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : SinglyLinear_Minimum
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      Traverses the singly linear linked list to find the minimum element.
//
//  Returns:
//      int : Minimum element in the linked list, or -1 if the list is empty
//
//----------------------------------------------------------------------------------------

template <class T>
int SinglyLinearLL <T> :: SinglyLinear_Minimum()
{
    struct SinglyLinearLLnode <T>* temp = NULL;

    //
    // Start from first node
    //
    temp = first;

    if (temp == NULL)   
    {
        cout << "List is empty." << endl;
        return -1;    
    }

    //  
    // Initialize minimum with first node's data
    //
    int iMin = temp->data;

    while(temp != NULL)
    {
        if(iMin > temp->data)
        {
            iMin = temp->data;
        }
        temp = temp->next;
    }

    return iMin;
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : SinglyLinear_DisplayPerfect
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      Traverses the singly linear linked list and checks each node’s data to determine
//       if it is a Perfect number.
//
//  Returns:
//      void
//
//----------------------------------------------------------------------------------------

template <class T>
void SinglyLinearLL <T> :: SinglyLinear_DisplayPerfect()
{
    
    struct SinglyLinearLLnode <T>* temp = NULL;

    // Pointer to traverse the list
    temp = first;

    int iSum = 0;
    int iCnt = 0;

    while(temp != NULL)
    {
        iSum = 0;
        for(iCnt = 1; iCnt <= (temp->data)/2; iCnt++)
        {
            if((temp->data) % iCnt == 0)
            {
                iSum = iSum + iCnt;
            }
        }

        // Check if sum equals the number itself
        if(iSum == temp->data)
        {
            printf("Perfect number is : %d\n",temp->data);
        }
        temp = temp->next;
    }
    
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : SinglyLinear_DisplayPrime
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      Traverses the singly linear linked list and checks each node’s data to determine
//      if it is a Prime number.
//
//  Returns:
//      void
//
//---------------------------------------------------------------------------------

template <class T>
void SinglyLinearLL <T> :: SinglyLinear_DisplayPrime()
{
    struct SinglyLinearLLnode <T>* temp = NULL;

     // Pointer to traverse the list
    temp = first;

    int iCnt = 0;
    int iFactCnt = 0;

    while(temp != NULL)
    {
        iFactCnt = 0;

        //  
        // Check divisibility from 2 to data/2
        //
        for(iCnt = 2; iCnt <= (temp->data)/2; iCnt++)
        {
            if(temp->data % iCnt == 0)
            {
                iFactCnt++;
                break;   
            }
        }

        //
        // If no divisors found and number > 1, it is prime
        //
        if((iFactCnt == 0) && (temp->data > 1))
        {
            printf("Prime number is : %d\n", temp->data);
        }

        temp = temp->next;
    }
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : SinglyLinear_SummationEven
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      Traverses the singly linear linked list and calculates the sum of all even numbers.
//
//  Returns:
//      int : Sum of all even numbers in the linked list.
//
//----------------------------------------------------------------------------------------

template <class T>
int SinglyLinearLL <T> :: SinglyLinear_SummationEven()
{
    struct SinglyLinearLLnode <T>* temp = NULL;

    //  
    // Pointer to traverse the list
    //
    temp = first;

    int iSum = 0;

    while(temp != NULL)
    {
        //  
        // Check if node's data is even
        //
        if(temp->data % 2 == 0)
        {
            iSum = iSum + temp->data;
            temp = temp->next;
        }
    }

    return iSum;
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : SinglyLinear_SummationOdd
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      Traverses the singly linear linked list and calculates the sum of all odd numbers.
//
//  Returns:
//      int : Sum of all odd numbers in the linked list.
//
//----------------------------------------------------------------------------------------

template <class T>
int SinglyLinearLL <T> :: SinglyLinear_SummationOdd()
{
    struct SinglyLinearLLnode <T>* temp = NULL;

    //
    // Pointer to traverse the list
    //
    temp = first;

    int iSum = 0;

    while(temp != NULL)
    {
        //  
        // Check if node's data is odd
        //
        if(temp->data % 2 != 0)
        {
            iSum = iSum + temp->data;
            temp = temp->next;
        }
    }

    return iSum;
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : SinglyLinear_SecMaximum
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      Traverses the singly linear linked list and finds the second largest element.
//
//  Returns:
//      int : The second largest element in the list. Returns -1 if not found.
//
//----------------------------------------------------------------------------------------

template <class T>
int SinglyLinearLL <T> :: SinglyLinear_SecMaximum()
{
    struct SinglyLinearLLnode <T>* temp = NULL;

    temp = first;

    int iMax = 0;
    int secondMax = 0;

    iMax = temp->data;
    temp = temp->next;

    if(temp->data > iMax)
    {
        secondMax = iMax;
        iMax = temp->data;
    }
    else if(temp->data < iMax)
    {
        secondMax = temp->data;
    }
    else
    {
        secondMax = -1;
    }

    temp = temp->next;

    while(temp != NULL)
    {
        if(temp->data > iMax)
        {
           secondMax = iMax;
           iMax = temp->data;
        }
        else if(temp->data > secondMax && temp->data != iMax)
        {
            secondMax = temp->data;
        }
        temp = temp->next;
    }
    
    return secondMax;
   
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : SinglyLinear_SumDigit
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      Traverses the singly linear linked list and calculates the sum of digits 
//      for each node's data.
//
//  Returns:
//      void
//
//----------------------------------------------------------------------------------------

template <class T>
void SinglyLinearLL <T> :: SinglyLinear_SumDigit()
{
    struct SinglyLinearLLnode <T>* temp = NULL;

    //  
    // Start from first node
    //
    temp = first;

    int iDigit = 0, iSum = 0, iNo = 0;

    while(temp != NULL)
    {
        iNo = temp->data;
        iSum = 0;

        //  
        // Calculate sum of digits
        //
        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iSum = iSum + iDigit;
            iNo = iNo /10;
        }
        printf("%d : Sum of Digits is : %d\n",temp->data,iSum);
        temp = temp->next;
    }
   
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : SinglyLinear_ReverseDigit
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      Reverses and displays the digits of each node's data in the singly linear linked list.
//
//  Returns:
//      void
//
//----------------------------------------------------------------------------------------

template <class T>
void SinglyLinearLL <T> :: SinglyLinear_ReverseDigit()
{
    struct SinglyLinearLLnode <T>* temp = NULL;

    temp = first;

    int iDigit =  0, iNo = 0,iRev = 0;

    while(temp != NULL)
    {
        iNo = temp->data;
        iRev = 0;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iRev = (iRev * 10) + iDigit;
            iNo = iNo / 10;
        }
        printf("| %d | -> ",iRev);
        temp = temp->next;
    }

    printf("NULL\n");
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : SinglyLinear_DisplayPalindrome
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      Checks each node's data in the singly linear linked list and prints it if it's a palindrome.
//
//  Returns:
//      void
//
//----------------------------------------------------------------------------------------

template <class T>
void SinglyLinearLL <T> :: SinglyLinear_DisplayPalindrome()
{
    struct SinglyLinearLLnode <T>* temp = NULL;

    temp = first;

    int iDigit =  0, iNo = 0,iRev = 0;

    while(temp != NULL)
    {
        iNo = temp->data;
        iRev = 0;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iRev = (iRev * 10) + iDigit;
            iNo = iNo / 10;
        }

        if(iRev == temp->data)
        {
            printf(" Pallindrome number is : %d\n",iRev);
        }
        temp = temp->next;
    }

    printf("\n"); 
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : SinglyLinear_DisplayProduct
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      Traverses the singly linear linked list and prints the product of digits of each node's data.
//      Digits with value 0 are ignored in the multiplication.
//
//  Returns:
//      void
//
//----------------------------------------------------------------------------------------

template <class T>
void SinglyLinearLL <T> :: SinglyLinear_DisplayProduct()
{
    struct SinglyLinearLLnode <T>* temp = NULL;

    temp = first;

    int iDigit = 0, iNo = 0, iProduct = 1;

    if (temp == NULL)
    {
        printf(" Linked list is empty.\n");
        return;
    }

    while (temp != NULL)
    {
        iNo = temp->data;
        iProduct = 1;

        while (iNo != 0)
        {
            iDigit = iNo % 10;

            if (iDigit != 0)   
            {
                iProduct = iProduct * iDigit;
            }

            iNo = iNo / 10;
        }

        printf("Number : %d → Product of digits = %d\n", temp->data, iProduct);

        temp = temp->next;
    }

    printf("\n"); 
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : SinglyLinear_DisplaySmallDigit
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      Traverses the singly linear linked list and prints the smallest digit of each node's data.
//
//  Returns:
//      void
//
//----------------------------------------------------------------------------------------

template <class T>
void SinglyLinearLL <T> :: SinglyLinear_DisplaySmallDigit()
{
    struct SinglyLinearLLnode <T>* temp = NULL;

    temp = first;

    int iDigit = 0, iNo = 0,iSmall = 0;

    while(temp != NULL)
    {
        iNo = temp->data;
        iSmall = 10;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            if(iDigit <= iSmall)
            {
                iSmall = iDigit;   
            }
            iNo = iNo / 10;
        }
       printf("Small number is : %d\n",iSmall);
        temp = temp->next;
       
    }

    printf("\n"); 
}

template <class T>
void SinglyLinearLL <T> :: SinglyLinear_DisplayLargeDigit()
{
     struct SinglyLinearLLnode <T>* temp = NULL;

    temp = first;

    int iDigit = 0, iNo = 0,iLarge = 0;

    while(temp != NULL)
    {
        iNo = temp->data;
        iLarge = 0;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            if(iDigit > iLarge)
            {
                iLarge = iDigit;   
            }
            iNo = iNo / 10;
        }
       printf("Large number is : %d\n",iLarge);
        temp = temp->next;
       
    }

    printf("\n"); 
}

//----------------------------------------------------------------------------------------
//
//  Class Name     :   DoublyLLL
//  Description    :   Generic implementation of Doubly Linear linked list
//  Author         :   Sarika Devidas Gadhe
//  Date           :   16/09/2025
//
//----------------------------------------------------------------------------------------

template<class T>
struct node
{
        T data;
        struct node<T>* next;
        struct node<T>* prev;
};

template<class T>
class DoublyLLL
{
    private:
        struct node<T>* first;
        int iCount;

    public:
        
        // Constructor
        DoublyLLL();

        // Insert node at beginning
        void InsertFirst(
                                    T
                            );

        // Insert node at end                    
        void InsertLast(
                                    T
                            );

        // Insert node at specific position                    
        void InsertAtPos(
                                    T,
                                    int
                            );
        
        // Display entire list                    
        void Display();
        
        // Count total nodes
        int Count();

        // Delete first node
        void DeleteFirst();

        // Delete last node
        void DeleteLast();

        // Delete node at specific position
        void DeleteAtPos(
                                    int
                            );
        
        // Search first occurrence                    
        int  DoublyLinear_SearchFirstOcc(
                                                        T no
                                            );

        // Search last occurrence                                    
        int  DoublyLinear_SearchLastOcc(
                                                    T no
                                            );

        // Sum of all elements                                    
        int  DoublyLinear_Summation();

        // Sum of odd numbers
        int  DoublyLinear_SummationOdd();

        // Sum of even numbers
        int  DoublyLinear_SummationEven();

        // Find maximum element
        int  DoublyLinear_Maximum();

        // Find minimum element
        int  DoublyLinear_Minimum();

        // Find second maximum element
        int DoublyLinear_SecMaximum();

        // Display sum of digits of each number
        void  DoublyLinear_SumDigit();

        // Display reverse of digits of each number
        void  DoublyLinear_ReverseDigit();

        // Display smallest digit of each number
        void  DoublyLinear_DisplaySmallDigit();

        // Display largest digit of each number
        void  DoublyLinear_DisplayLargeDigit();

        // Display perfect numbers
        void  DoublyLinear_DisplayPerfect();

        // Display prime numbers
        void  DoublyLinear_DisplayPrime();

        // Display palindrome numbers
        void  DoublyLinear_DisplayPalindrome();

        // Display product of digits of each number
        void  DoublyLinear_DisplayProduct();

};

//----------------------------------------------------------------------------------------
//
//  Function Name   : DoublyLLL 
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameter:
//        None
//  
//  Description:
//       - Constructor Initializes the Doubly Linear Linked List.
//      - Sets 'first' pointer to NULL.
//      - Sets node count 'iCount' to 0.
//
//
//  Returns:
//      void
//
//----------------------------------------------------------------------------------------

template<class T>
DoublyLLL<T> :: DoublyLLL()
{
    first = NULL;
    iCount = 0;
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : InsertFirst
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters:
//      no : Data of type T to insert at the start.
//
//  Description:
//      Inserts a new node at the beginning of the doubly linked list.
//
//  Returns:
//      void
//
//----------------------------------------------------------------------------------------


template<class T>
void DoublyLLL<T> :: InsertFirst(
                                            T no
                                    )
{
    struct node<T> * newn = NULL;
    newn = new struct node<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        first->prev = newn;
        newn->next = first;
        first = newn;
    }
    iCount++;

}

//----------------------------------------------------------------------------------------
//
//  Function Name   : InsertLast
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters:
//      no : Data of type T to insert at the end.
//
//  Description:
//      Inserts a new node at the end of the doubly linked list.
//
//  Returns:
//      void
//
//----------------------------------------------------------------------------------------

template<class T>
void DoublyLLL<T> :: InsertLast(
                                            T no
                                    )
{
    struct node<T> * newn = NULL;
    struct node<T> * temp = NULL;
    newn = new struct node<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : InsertAtPos
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters:
//      no  : Data of type T to insert.
//      pos : Position at which to insert the new node.
//
//  Description:
//      Inserts a new node at the specified position in the doubly Linear linked list.
//
//  Returns:
//      void
//
//----------------------------------------------------------------------------------------

template<class T>
void DoublyLLL<T> :: InsertAtPos(
                                            T no,
                                            int pos
                                    )
{
    struct node<T> * newn = NULL;
    struct node<T> * temp = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct node<T>;
    
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = first;

        for(iCnt = 1; iCnt< pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;

        iCount++;

    }
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : DeleteFirst
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      Deletes the first node of the doubly Linear linked list.
//
//  Returns:
//      void
//
//----------------------------------------------------------------------------------------

template<class T>
void DoublyLLL<T> :: DeleteFirst()
{
    struct node<T> * temp = NULL;

    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        temp = first;

        first = first->next;
        first->prev = NULL;

        delete temp;
    }
    iCount--;

}

//----------------------------------------------------------------------------------------
//
//  Function Name   : DeleteLast
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      Deletes the last node of the doubly Linear linked list.
//
//  Returns:
//      void
//
//----------------------------------------------------------------------------------------

template<class T>
void DoublyLLL<T> :: DeleteLast()
{
    struct node<T> * temp = NULL;

    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
       temp = first;

       while(temp->next->next != NULL)
       {
            temp = temp->next;
       }

       delete temp->next;
       temp->next = NULL;

    }
    iCount--;
    
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : DeleteAtPos
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters:
//      pos : Position of the node to delete.
//
//  Description:
//      Deletes the node at the specified position in the doubly linear linked list.
//
//  Returns:
//      void
//
//----------------------------------------------------------------------------------------

template<class T>
void DoublyLLL<T> :: DeleteAtPos(
                                            int pos
                                    )
{
    struct node<T> * temp = NULL;
    struct node<T> * target = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {

        temp = first;

        for(iCnt = 1; iCnt< pos-1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;
        target->next->prev = temp;

        delete target;

        iCount--;

    }
    
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : Display
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      Displays all nodes of the doubly linear linked list
//      in a forward direction using "<=>" links.
//
//  Returns:
//      void
//
//----------------------------------------------------------------------------------------

template<class T>
void DoublyLLL<T>:: Display()
{
    struct node<T> * temp = NULL;

    temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->next;
    }
    cout<<"NULL\n";
}


//----------------------------------------------------------------------------------------
//
//  Function Name   : Count
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      Returns the total number of nodes present in the
//      doubly linear linked list.
//
//  Returns:
//      int  → Number of nodes
//
//----------------------------------------------------------------------------------------

template<class T>
int DoublyLLL<T> :: Count()
{
    return iCount;
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : DoublyLinear_SearchFirstOcc
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters:
//      [IN] T no
//          -> element to search in the doubly linear linked list
//
//  Description:
//      Searches for the first occurrence of the given element
//      in the doubly linear linked list. Traverses nodes one by one,
//      and returns the position of the first match.
//
//  Returns:
//      int → Position (1-based index) of first occurrence.
//             -1 if element is not found or list is empty.
//
//----------------------------------------------------------------------------------------

template <class T>
int DoublyLLL<T>::DoublyLinear_SearchFirstOcc(
                                                            T no
                                                )   
{
    struct node<T>* temp = first;
    int iPos = 1;

    if (temp == NULL)
    {
        return -1;
    }

    while (temp != NULL)
    {
        if (temp->data == no)
        {
            return iPos;  
        }
        iPos++;
        temp = temp->next;
    }

    return -1;
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : DoublyLinear_SearchLastOcc
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters:
//      [IN] T no
//          -> element to search in the doubly linear linked list
//
//  Description:
//      Searches for the last occurrence of the given element in the
//      doubly linear linked list. 
//
//  Returns:
//      int
//          -> position of last occurrence (1-based index), or -1 if not found
//
//----------------------------------------------------------------------------------------

template <class T>
int DoublyLLL <T> :: DoublyLinear_SearchLastOcc(T no)
{
    struct node <T>* temp = NULL;

    temp = first;

    int iPos = 1;
    int iLastPos = -1;

    while(temp != NULL)
    {
        if(temp->data == no)
        {
            iLastPos = iPos;
        }

        temp = temp->next;
        iPos++;
    }

    return iLastPos;
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : DoublyLinear_Summation
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      Calculates and returns the summation of all elements present 
//      in the doubly linear linked list by traversing each node.
//
//  Returns:
//      int
//          -> summation of all node elements
//
//----------------------------------------------------------------------------------------


template <class T>
int DoublyLLL <T> :: DoublyLinear_Summation()
{
    struct node <T>* temp = NULL;

    temp = first;

    int iSum = 0;

    while(temp != NULL)
    {
        iSum = iSum + temp->data;
        temp = temp->next;
    }

    return iSum;
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : DoublyLinear_Maximum
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      Returns the maximum element from the doubly linear linked list.
//      If the list is empty, returns -1.
//
//  Returns:
//      int -> maximum element, or -1 if empty
//
//----------------------------------------------------------------------------------------


template <class T>
int DoublyLLL <T> :: DoublyLinear_Maximum()
{
    struct node <T>* temp = NULL;

    temp = first;
    if (temp == NULL)   
    {
        cout << "List is empty." << endl;
        return -1;    
    }

    int iMax = temp->data;

    while(temp != NULL)
    {
        if(iMax < temp->data)
        {
            iMax = temp->data;
        }
        temp = temp->next;
    }

    return iMax;
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : DoublyLinear_Minimum
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      Finds and returns the minimum element from the doubly linear linked list.
//      If the list is empty, it prints a message and returns -1.
//
//  Returns:
//      int -> minimum element, or -1 if the list is empty
//
//----------------------------------------------------------------------------------------

template <class T>
int DoublyLLL <T> :: DoublyLinear_Minimum()
{
    struct node <T>* temp = NULL;

    temp = first;

    if (temp == NULL)   
    {
        cout << "List is empty." << endl;
        return -1;    
    }

    int iMin = temp->data;

    while(temp != NULL)
    {
        if(iMin > temp->data)
        {
            iMin = temp->data;
        }
        temp = temp->next;
    }

    return iMin;
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : DoublyLinear_DisplayPerfect
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters:
//      None
//
//  Description:
//      Traverses the doubly linear linked list and checks each node’s value to determine
//      whether it is a perfect number (sum of proper divisors equals the number).
//      If a perfect number is found, it is displayed on the console.
//
//  Returns:
//      void
//
//----------------------------------------------------------------------------------------

template <class T>
void DoublyLLL <T> :: DoublyLinear_DisplayPerfect()
{
    struct node <T>* temp = NULL;

    temp = first;

    int iSum = 0;
    int iCnt = 0;

    while(temp != NULL)
    {
        iSum = 0;
        for(iCnt = 1; iCnt <= (temp->data)/2; iCnt++)
        {
            if((temp->data) % iCnt == 0)
            {
                iSum = iSum + iCnt;
            }
        }

        if(iSum == temp->data)
        {
            printf("Perfect number is : %d\n",temp->data);
        }
        temp = temp->next;
    }
    
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : DoublyLinear_DisplayPrime
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters : 
//       None
//
//  Description :
//       Displays all prime numbers present in the doubly linear linked list.
//
//  Returns : 
//       void
//
//----------------------------------------------------------------------------------------

template <class T>
void DoublyLLL <T> :: DoublyLinear_DisplayPrime()
{
    struct node <T>* temp = NULL;

    temp = first;

    int iCnt = 0;
    int iFactCnt = 0;

    while(temp != NULL)
    {
        iFactCnt = 0;

        for(iCnt = 2; iCnt <= (temp->data)/2; iCnt++)
        {
            if(temp->data % iCnt == 0)
            {
                iFactCnt++;
                break;   
            }
        }

        if((iFactCnt == 0) && (temp->data > 1))
        {
            printf("Prime number is : %d\n", temp->data);
        }

        temp = temp->next;
    }
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : DoublyLinear_SummationEven
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters : 
//        None
//
//  Description : 
//        Calculates and returns the sum of all even elements 
//        in the doubly linear linked list.
//
//  Returns : 
//        int
//            -> Sum of even elements
//
//----------------------------------------------------------------------------------------

template <class T>
int DoublyLLL <T> :: DoublyLinear_SummationEven()
{
    struct node <T>* temp = NULL;

    temp = first;

    int iSum = 0;

    while(temp != NULL)
    {
        if(temp->data % 2 == 0)
        {
            iSum = iSum + temp->data;
            temp = temp->next;
        }
    }

    return iSum;
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : DoublyLinear_SummationOdd
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters : 
//         None
//
//  Description : 
//        Calculates and returns the sum of all odd elements 
//        in the doubly linear linked list.
//
//  Returns : 
//        int
//            -> Sum of odd elements
//
//----------------------------------------------------------------------------------------

template <class T>
int DoublyLLL <T> :: DoublyLinear_SummationOdd()
{
    struct node <T>* temp = NULL;

    temp = first;

    int iSum = 0;

    while(temp != NULL)
    {
        if(temp->data % 2 != 0)
        {
            iSum = iSum + temp->data;
            temp = temp->next;
        }
    }

    return iSum;
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : DoublyLinear_SecMaximum
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters : 
//           None
//
//  Description : 
//          Finds and returns the second largest element in the 
//          doubly linear linked list. 
//
//  Returns : 
//          int
//            -> Second maximum element, or -1 if not found
//
//----------------------------------------------------------------------------------------

template <class T>
int DoublyLLL <T> :: DoublyLinear_SecMaximum()
{
    struct node <T>* temp = NULL;

    temp = first;

    int iMax = 0;
    int secondMax = 0;

    iMax = temp->data;
    temp = temp->next;

    if(temp->data > iMax)
    {
        secondMax = iMax;
        iMax = temp->data;
    }
    else if(temp->data < iMax)
    {
        secondMax = temp->data;
    }
    else
    {
        secondMax = -1;
    }

    temp = temp->next;

    while(temp != NULL)
    {
        if(temp->data > iMax)
        {
           secondMax = iMax;
           iMax = temp->data;
        }
        else if(temp->data > secondMax && temp->data != iMax)
        {
            secondMax = temp->data;
        }
        temp = temp->next;
    }
    
    return secondMax;
   
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : DoublyLinear_SumDigit
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters : 
//           None
//
//  Description : 
//      Traverses each node of the doubly linked list, 
//      extracts its digits, and calculates the sum of digits 
//      for every node’s data. 
//      Prints the original number along with its digit sum.
//
//  Returns : 
//      void
//
//----------------------------------------------------------------------------------------

template <class T>
void DoublyLLL <T> :: DoublyLinear_SumDigit()
{
    struct node <T>* temp = NULL;

    temp = first;

    int iDigit = 0, iSum = 0, iNo = 0;

    while(temp != NULL)
    {
        iNo = temp->data;
        iSum = 0;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iSum = iSum + iDigit;
            iNo = iNo /10;
        }
        printf("%d : Sum of Digits is : %d\n",temp->data,iSum);
        temp = temp->next;
    }
   
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : DoublyLinear_ReverseDigit
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters :
//           None
//
//  Description : 
//         Reverses the digits of each node’s data and displays the reversed numbers.
//
//  Returns : void
//
//-----------------------------------------------------------------------------------

template <class T>
void DoublyLLL <T> :: DoublyLinear_ReverseDigit()
{
    struct node <T>* temp = NULL;

    temp = first;

    int iDigit =  0, iNo = 0,iRev = 0;

    while(temp != NULL)
    {
        iNo = temp->data;
        iRev = 0;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iRev = (iRev * 10) + iDigit;
            iNo = iNo / 10;
        }
        printf("| %d | -> ",iRev);
        temp = temp->next;
    }

    printf("NULL\n");
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : DoublyLinear_DisplayPalindrome
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters :
//           None
//
//  Description : 
//         Checks each node’s data to see if it is a palindrome number.
//         If yes, it displays that number.
//
//  Returns : void
//
//----------------------------------------------------------------------------------------

template <class T>
void DoublyLLL <T> :: DoublyLinear_DisplayPalindrome()
{
    struct node <T>* temp = NULL;

    temp = first;

    int iDigit =  0, iNo = 0,iRev = 0;

    while(temp != NULL)
    {
        iNo = temp->data;
        iRev = 0;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iRev = (iRev * 10) + iDigit;
            iNo = iNo / 10;
        }

        if(iRev == temp->data)
        {
            printf(" Pallindrome number is : %d\n",iRev);
        }
        temp = temp->next;
    }

    printf("\n"); 
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : DoublyLinear_DisplayProduct
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters :
//           None
//
//  Description : 
//         Calculates and displays the product of digits for each node’s data 
//         in the doubly linear linked list. Zeros are ignored in multiplication.
//
//  Returns : void
//
//----------------------------------------------------------------------------------------

template <class T>
void DoublyLLL <T> :: DoublyLinear_DisplayProduct()
{
    struct node <T>* temp = NULL;

    temp = first;

    int iDigit = 0, iNo = 0, iProduct = 1;

    if (temp == NULL)
    {
        printf(" Linked list is empty.\n");
        return;
    }

    while (temp != NULL)
    {
        iNo = temp->data;
        iProduct = 1;

        while (iNo != 0)
        {
            iDigit = iNo % 10;

            if (iDigit != 0)   
            {
                iProduct = iProduct * iDigit;
            }

            iNo = iNo / 10;
        }

        printf("Number : %d → Product of digits = %d\n", temp->data, iProduct);

        temp = temp->next;
    }

    printf("\n"); 
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : DoublyLinear_DisplaySmallDigit
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters :
//           None
//
//  Description : 
//         Finds and displays the smallest digit in each node’s data 
//         in the doubly linear linked list.
//
//  Returns : void
//
//----------------------------------------------------------------------------------------


template <class T>
void DoublyLLL <T> :: DoublyLinear_DisplaySmallDigit()
{
    struct node <T>* temp = NULL;

    temp = first;

    int iDigit = 0, iNo = 0,iSmall = 0;

    while(temp != NULL)
    {
        iNo = temp->data;
        iSmall = 10;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            if(iDigit <= iSmall)
            {
                iSmall = iDigit;   
            }
            iNo = iNo / 10;
        }
       printf("Small number is : %d\n",iSmall);
        temp = temp->next;
       
    }

    printf("\n"); 
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : DoublyLinear_DisplayLargeDigit
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters :
//           None
//
//  Description : 
//         Finds and displays the largest digit in each node’s data 
//         in the doubly linear linked list.
//
//  Returns : void
//
//----------------------------------------------------------------------------------------

template <class T>
void DoublyLLL <T> :: DoublyLinear_DisplayLargeDigit()
{
     struct node <T>* temp = NULL;

    temp = first;

    int iDigit = 0, iNo = 0,iLarge = 0;

    while(temp != NULL)
    {
        iNo = temp->data;
        iLarge = 0;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            if(iDigit > iLarge)
            {
                iLarge = iDigit;   
            }
            iNo = iNo / 10;
        }
       printf("Large number is : %d\n",iLarge);
        temp = temp->next;
       
    }

    printf("\n"); 
}


//----------------------------------------------------------------------------------------
//
//  Class Name     :   BST
//  Description    :   Generic implementation of a Binary Search Tree (BST)
//  Author         :   Sarika Devidas Gadhe
//  Date           :   16/09/2025
//
//----------------------------------------------------------------------------------------

template <class T>
struct BSTnode
{
    T data;
    struct BSTnode <T> * lchild;
    struct BSTnode <T>* rchild;
};

template <class T>
class BST
{
    private:
       //
       // Root node
       //
       struct BSTnode <T>*first;
       int iCount = 0; 

    public:

        // Constructor
        BST();

        // Insert node into BST
        void Insert(
                                T
                        );

         // Inorder traversal                
        void Inorder(
                                struct BSTnode <T> *
                        ); 

        // Display inorder traversal                
        void DisplayInorder(); 

         // Preorder traversal
        void Preorder(
                                struct BSTnode <T>*
                        ); 

        // Display preorder traversal                
        void DisplayPreorder();  

        // Postorder traversal
        void Postorder(
                                struct BSTnode <T>*
                        );   
        
        // Display postorder traversal        
        void DisplayPostorder(); 
        
        // Search for a value
        bool Search(
                                    T
                        );
        
        // Count total nodes from a node                
        int Count(
                                struct BSTnode <T>*
                    );
        
        // Count leaf nodes            
        int CountLeafNodes(
                                struct BSTnode <T>*
                            );
              
        // Count parent node                    
        int CountParentNodes(
                                    struct BSTnode <T>*
                                );
        
        // Display all counts                        
        void CountAll();

};

//----------------------------------------------------------------------------------------
//
//  Function Name   : BST
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters : 
//         None
//
//  Description : 
//      Constructor to initialize an empty Binary Search Tree (BST).
//      Sets the root pointer 'first' to NULL and node count 'iCount' to 0.
//
//  Returns : void
//
//----------------------------------------------------------------------------------------

template <class T>
BST <T> :: BST()
{
    //  
    // Root of BST initially NULL
    //
    this->first = NULL;

    //
    // Node count initialized to 0
    // 
    this->iCount = 0;
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : Insert
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters :
//      [In] T no : The value to insert into the BST
//
//  Description : 
//      Inserts a new node with the specified value into the BST while maintaining BST properties.
//
//  Returns : 
//       void
//
//----------------------------------------------------------------------------------------

template <class T>
void BST <T>:: Insert(
                                    T no
                        )
{
    //  
    // Pointer to traverse the tree
    //
    struct BSTnode <T>* temp = NULL;

    //
    // Pointer for the new node
    //
    struct BSTnode <T>* newn = NULL;

    //   
    // Allocate and initialize new node
    //
    newn = new struct BSTnode <T>;

    newn->data = no;
    newn->lchild = NULL;
    newn->rchild = NULL;

    //  
    // If tree is empty, insert as root
    //
    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;

        while(1)
        {
            // Duplicate element check
            if(no == temp->data)
            {
                cout<<"Duplicate Element : Unable to insert node"<<"\n";
                delete newn;
                break;
            }

            // Go to right subtree
            else if(no > temp->data)
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp  = temp->rchild;
            }

             // Go to left subtree
            else if(no < temp->data)
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;
            }
        }
    }

}

//----------------------------------------------------------------------------------------
//
//  Function Name   : Inorder
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters :
//      [In] struct BSTnode<T>* first : Pointer to the root or current node
//
//  Description : 
//      Performs an inorder traversal (Left, Root, Right) of the BST
//      recursively and prints the node values.
//
//  Returns : 
//      void
//
//----------------------------------------------------------------------------------------

template <class T>
void BST <T> :: Inorder(
                                        struct BSTnode <T>* first
                            )
{
    //   
    // Temporary pointer for traversal
    //
    struct BSTnode <T> * temp = first;

    if(temp != NULL)
    {
        // Recur on left subtree
        Inorder(temp->lchild);

        // Visit current node
        cout<<temp->data<<"\t";

        // Recur on right subtree
        Inorder(temp->rchild);
       
    }
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : DisplayInorder
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters : None
//
//  Description : 
//      Initiates inorder traversal of the BST starting from root
//      and prints the values in inorder sequence.
//
//  Returns : 
//      void
//
//----------------------------------------------------------------------------------------

template <class T>
void BST <T>:: DisplayInorder()
{
    cout<<"Inorder Traversal : \n";

    //
    // Start recursive inorder from root
    //
    Inorder(first);

    cout<<"\n";
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : Preorder
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters :
//      [In] struct BSTnode<T>* first : Pointer to the root or current node
//
//  Description : 
//      Performs a preorder traversal (Root, Left, Right) of the BST
//      recursively and prints the node values.
//
//  Returns : 
//      void
//
//---------------------------------------------------------------------------------------

template <class T>
void BST <T> :: Preorder(
                                        struct BSTnode <T>* first
                            )
{
    struct BSTnode <T> *temp = first;

    if(temp != NULL)
    {
        // Visit current node
        cout<<temp->data<<"\t";

         // Recur on left subtree
        Preorder(temp->lchild);

        // Recur on right subtree
        Preorder(temp->rchild);
       
    }
}


//----------------------------------------------------------------------------------------
//
//  Function Name   : DisplayPreorder
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters : 
//        None
//
//  Description : 
//      Initiates preorder traversal of the BST starting from root
//      and prints the values in preorder sequence.
//
//  Returns : 
//      void
//
//---------------------------------------------------------------------------------

template <class T>
void BST <T> :: DisplayPreorder()
{
    cout<<"Preorder Traversal : \n";

    // Start recursive preorder from root
    Preorder(first);

    cout<<"\n";
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : Postorder
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters :
//      [In] struct BSTnode<T>* first : Pointer to the root or current node
//
//  Description : 
//      Performs a postorder traversal (Left, Right, Root) of the BST
//      recursively and prints the node values.
//
//  Returns : 
//      void
//
//----------------------------------------------------------------------------------------

template <class T>
void BST <T> :: Postorder(
                                        struct BSTnode <T>* first
                            )
{
    struct BSTnode <T> *temp = first;

    if(temp != NULL)
    {
        // Recur on left subtree
        Postorder(temp->lchild);

        // Recur on right subtree
        Postorder(temp->rchild);

        // Visit current node
        cout<<temp->data<<"\t";
       
    }
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : DisplayPostorder
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters : 
//       None
//
//  Description : 
//      Initiates postorder traversal of the BST starting from root
//      and prints the values in postorder sequence.
//
//  Returns : 
//      void
//
//----------------------------------------------------------------------------------------

template <class T>
void BST <T> :: DisplayPostorder()
{
    cout<<"Postorder Traversal : \n";

    // Start recursive postorder from root
    Postorder(first);

    cout<<"\n";
}


//----------------------------------------------------------------------------------------
//
//  Function Name   : Search
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters :
//      [In] T no : The value to search in the BST
//
//  Description : 
//      Searches for a given value in the BST.
//      Traverses the tree starting from root, moving left or right
//      depending on the comparison with current node value.
//      Tracks the number of steps as "Time Complexity".
//
//  Returns : 
//      bool : true if value is found, false otherwise
//
//--------------------------------------------------------------------------------------

template <class T>
bool BST <T> :: Search(
                                    T no
                        )
{
    bool bFlag = false;

    //
    // Counter for number of steps
    //
    int TimeComplexity = 0;

    //    
    // Start from root
    //
    struct BSTnode <T> *temp = first;

    while(temp != NULL)
    {
         // Value found
        if(no == temp->data)
        {
            bFlag = true;
            break;
        }

         // Move to right subtree
        else if(no > temp->data)
        {
            temp = temp->rchild;
        }

        // Move to left subtree
        else if(no < temp->data)
        {
            temp = temp->lchild;
        }

        TimeComplexity++;
    }

    cout<<"Time Complexity of Search is : "<<TimeComplexity<<"\n";
    return bFlag;
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : Count
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters :
//      [In] struct BSTnode<T>* first : Pointer to the root node (or subtree root)
//
//  Description : 
//      Recursively counts the total number of nodes in the BST.
//      Uses a static variable to accumulate the count across recursive calls.
//
//  Returns : 
//      int : Total number of nodes in the BST
//
//----------------------------------------------------------------------------------------

template <class T>
int BST <T> :: Count(
                                    struct BSTnode <T>*first
                        )
{
    //   
    // Static variable to store count across recursion
    //
    int static iCount = 0;

    struct BSTnode <T> *temp = first;

    if(temp != NULL)
    {
        iCount++;

        //  
        // Recurse left subtree
        //
        Count(first->rchild);

        //  
        // Recurse right subtree
        //
        Count(first->lchild);
    }

    return iCount;
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : CountLeafNodes
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters :
//      [In] struct BSTnode<T>* first : Pointer to the root node (or subtree root)
//
//  Description : 
//      Recursively counts the total number of leaf nodes in the BST.
//      A leaf node is a node that has no left or right child.
//
//  Returns : 
//      int : Total number of leaf nodes in the BST
//
//----------------------------------------------------------------------------------------

template <class T>
int BST <T> :: CountLeafNodes(
                                                struct BSTnode <T> *first
                                )
{
    struct BSTnode <T> *temp = first;
    int static iCount = 0;

    if(first != NULL)
    {
         // Check if the current node is a leaf
        if(first->lchild == NULL && first->rchild == NULL)
        {
            iCount++;
        }

        //  
        // Recurse into left and right subtrees
        //
        CountLeafNodes(temp->rchild);
        CountLeafNodes(temp->lchild);
    }
    return iCount;
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : CountParentNodes
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters :
//      [In] struct BSTnode<T>* first : Pointer to the root node (or subtree root)
//
//  Description : 
//      Recursively counts the total number of parent (non-leaf) nodes in the BST.
//      A parent node is a node that has at least one child.
//
//  Returns : 
//      int : Total number of parent nodes in the BST
//
//----------------------------------------------------------------------------------------

template <class T>
int BST <T> :: CountParentNodes(struct BSTnode <T>*first)
{
    struct BSTnode <T> * temp = first;
    int static iCount = 0;

    if(temp != NULL)
    {
         // Check if the current node is a parent
        if(temp->lchild != NULL || temp->rchild != NULL)
        {
            iCount++;
        }

        //
        // Recurse into left and right subtrees
        //
        CountParentNodes(temp->rchild);
        CountParentNodes(temp->lchild);
    }

    return iCount;
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : CountAll
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters :
//      None
//
//  Description : 
//      Displays the total number of nodes, leaf nodes, and parent nodes
//      in the Binary Search Tree by calling the respective functions.
//
//  Returns : 
//      void
//
//----------------------------------------------------------------------------------------

template <class T>
void BST <T> :: CountAll()
{
    cout<<"Number of Nodes are : "<<Count(first)<<"\n";
    cout<<"Number of Leaf Nodes are : "<<CountLeafNodes(first)<<"\n";
    cout<<"Number of Parent Nodes are : "<<CountParentNodes(first)<<"\n";
}


//----------------------------------------------------------------------------------------
//
//  Class Name     :   SortingX
//  Description    :   Generic implementation of sorting algorithms
//  Author         :   Sarika Devidas Gadhe
//  Date           :   16/09/2025
//
//----------------------------------------------------------------------------------------

template <class T>
class SortingX                  
{
    public:

        // Pointer to dynamically allocated array
        T *Arr ;

        // Size of the array
        int iSize;
        bool Sorted;

        //Constructor to initialize array of size 'no'
        SortingX(
                            int no
                    );

        // Destructor to free dynamic memory            
        ~SortingX();

        // Accept array elements from user
        void Accept();

        // Display array elements
        void Display();

        // Standard Bubble Sort
        void BubbleSort();   

        // Optimized Bubble Sort
        void BubbleSortEfficient();   

        //Selection Sort
        void SelectionSort();

        //Insertion Sort
        void InsertionSort();
};

//----------------------------------------------------------------------------------------
//
//  Function Name   : SortingX 
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters :
//      [In] int no : Size of the array to be created
//
//  Description : 
//      - Constructor Initializes the array size.
//      - Dynamically allocates memory for the array.
//      - Sets the Sorted flag to true initially.
//
//  Returns : 
//      void
//
//----------------------------------------------------------------------------------------

template <class T>
SortingX <T>:: SortingX(
                                    int no
                            )
{
    //  
    // Set the array size
    //
    iSize = no;

    //
    // Dynamically allocate memory for array
    //
    Arr = new T[iSize];

    //
    // Initially consider the array sorted
    //
    Sorted = true;
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : ~SortingX
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters :
//      None
//
//  Description : 
//      Destructor to deallocate the dynamically allocated array.
//
//  Returns : void
//
//----------------------------------------------------------------------------------------

template <class T>
SortingX <T> :: ~SortingX()
{
    //
    // Free the allocated memory
    //
    delete []Arr;
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : Accept
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters :
//      None
//
//  Description : 
//      - Accepts 'iSize' number of elements from the user and stores them in the array 'Arr'.
//
//  Returns : void
//
//----------------------------------------------------------------------------------------

template <class T>
void SortingX <T>::  Accept()
{
    cout<<"Enter "<<iSize<<" elements : \n";

    int i = 0;                     

    for(i  = 0; i < iSize; i++)
    {
        cout<<"Enter the element no : "<<i+1<<"\n";
        cin>>Arr[i];

        //
        // Check if the array remains sorted after adding this element
        //
        if((i > 0) && (Sorted == true))          
        {
            if(Arr[i] < Arr[i-1])
            {
                Sorted = false;
            }
        }
    }
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : Display
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters :
//      None
//
//  Description : 
//      Displays all elements of the array 'Arr'.
//
//  Returns : void
//
//----------------------------------------------------------------------------------------


template <class T>
void SortingX <T>:: Display()
{
        // Print message indicating array element
        cout<<"Elements of the array are : \n";

    int i = 0;

    // Traverse the array and print each element
    for(i  = 0; i < iSize; i++)
    {
        cout<<Arr[i]<<"\t";
    }
    cout<<"\n";
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : BubbleSort
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters :
//      None
//
//  Description : 
//      Sorts the array 'Arr' in ascending order using the bubble sort algorithm.
//
//  Returns : 
//       void
//
//----------------------------------------------------------------------------------------

template <class T>
void SortingX <T>::  BubbleSort()                
{
    int i = 0, j = 0 ,temp = 0;

    //
    // If array is already sorted, no need to sort again
    //
    if(Sorted == true)
    {
        return;
    }
    
    // Outer loop for number of passes
    for(i = 0; i < iSize ; i++)              
    {
         // Inner loop for comparing adjacent elements
        for(j = 0; j < iSize - 1; j++)          
        {
             // Swap if elements are in wrong order
            if(Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
            }
        }

         // Display array after each pass
        cout<<"Data after pass : "<<i+1<<"\n";
        
        Display();
    }
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : BubbleSortEfficient
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters :
//      None
//
//  Description : 
//      Sorts the array 'Arr' in ascending order using an optimized bubble sort algorithm.
//
//  Returns : 
//       void
//
//----------------------------------------------------------------------------------------

template <class T>
void SortingX <T> :: BubbleSortEfficient()               
{
    int i = 0, j = 0 ,temp = 0;
    bool bFlag = true;

    if(Sorted == true)
    {
        return;
    }
    
    for(i = 0; (i < iSize && bFlag == true) ; i++)              
    {
        bFlag = false;

        for(j = 0; j < iSize - 1 - i ; j++)          
        {
            if(Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;

                bFlag = true;
            }
        }

        cout<<"Data after pass : "<<i+1<<"\n";
        
        Display();
    }
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : SelectionSort
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters :
//      None
//
//  Description : 
//      Sorts the array 'Arr' in ascending order using the selection sort algorithm.
//
//  Returns : void
//
//----------------------------------------------------------------------------------------


template <class T>
void SortingX <T>:: SelectionSort()
{
    int i = 0, j = 0, min_index = 0, temp = 0;

    //
    // Traverse through all array elements
    //
    for(i = 0; i < iSize - 1; i++)
    {
        // Assume the current index has the minimum element
        min_index = i;

        for(j = i +1; j < iSize; j++)
        {
            if(Arr[j] < Arr[min_index])
            {
                min_index = j;
            }

        }
        // Swap the found minimum element with the first element
        if(i != min_index)
        {
            temp = Arr[i];
            Arr[i] = Arr[min_index];
            Arr[min_index] = temp;
        }
    }
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : InsertionSort
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters :
//      None
//
//  Description : 
//      Sorts the array 'Arr' in ascending order using the insertion sort algorithm.
//
//  Returns : 
//      void
//
//----------------------------------------------------------------------------------------


template <class T>
void SortingX <T>:: InsertionSort()
{
    int  i = 0, j = 0, selected = 0;

    for(i = 1; i < iSize; i++)
    {
        for(j = i - 1,selected = Arr[i]; (j >= 0) && (Arr[j] > selected); j--)
        {
            Arr[j + 1] = Arr[j];
        }
        Arr[j + 1] = selected;
    }
}



//----------------------------------------------------------------------------------------
//
//  Class Name     :   SearchingX
//  Description    :   Generic implementation of searching algorithms
//  Author         :   Sarika Devidas Gadhe
//  Date           :   16/09/2025
//
//----------------------------------------------------------------------------------------

template <class T>
class SearchingX                
{
    public:
        T *Arr;
        int iSize;
        bool Sorted;

        // Constructor to initialize array
        SearchingX(
                                int no
                    );
        
        // Destructor to free memory            
        ~SearchingX();

        void Accept();

        void Display();

        // Searches element using linear search
        bool LinearSearch(
                                        T no
                            );
               
        // Bi-directional linear search                    
        bool BiDirectionalSearch(
                                            T no
                                    ); 
        
        // Binary search in ascending sorted array                            
        bool BinarySearchInc(
                                            T no
                                ); 

        // Binary search in descending sorted array                                        
        bool BinarySearchDec(
                                        T no
                                );           
        
        // Optimized binary search                      
        bool BinarySearchEfficientInc(
                                                    T no
                                        );

         // Optimized binary search                                 
        bool BinarySearchEfficientDec(T no);

         // Checks if array is sorted 
        bool CheckSortedInc();

        // Checks if array is sorted
        bool CheckSortedDec();
};

//----------------------------------------------------------------------------------------
//
//  Function Name   : SearchingX 
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters :
//      [In] int no : Size of the array to allocate
//
//  Description : 
//      (Constructor) Dynamically allocates memory for an array of type T with size 'no'.
//      Initializes the array as sorted by default.
//
//  Returns : 
//      void
//
//----------------------------------------------------------------------------------------

template <class T>
SearchingX <T> :: SearchingX(
                                            int no
                                )
{
    // Set array size
    iSize = no;

    // Allocate memory
    Arr = new T[iSize];

    // Assume array is initially sorted
    Sorted = true;
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : ~SearchingX 
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters :
//      None
//
//  Description : 
//      (Destructor) Frees the dynamically allocated memory for the array.
//
//  Returns : 
//      void
//
//----------------------------------------------------------------------------------------

template <class T>
SearchingX <T> :: ~SearchingX()
{
    //  
    // Free allocated memory
    //
    delete []Arr;
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : Accept
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters :
//      None
//
//  Description : 
//      Accepts 'iSize' number of elements from the user and stores them in the array 'Arr'.
//
//  Returns : 
//      void
//
//----------------------------------------------------------------------------------------

template <class T>
void SearchingX <T> :: Accept()
{
    cout<<"Enter "<<iSize<<" elements : \n";

    int i = 0;                     

    for(i  = 0; i < iSize; i++)
    {
        cout<<"Enter the element no : "<<i+1<<"\n";
        cin>>Arr[i];

        if((i > 0) && (Sorted == true))           
        {
            if(Arr[i] < Arr[i-1])
            {
                Sorted = false;
            }
        }
    }
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : Display
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters :
//      None
//
//  Description : 
//      Displays all elements stored in the array 'Arr' of the SearchingX class.
//
//  Returns : 
//      void
//
//----------------------------------------------------------------------------------------

template <class T>
void SearchingX <T> :: Display()
{
        cout<<"Elements of the array are : \n";

    int i = 0;

    for(i  = 0; i < iSize; i++)
    {
        cout<<Arr[i]<<"\t";
    }
    cout<<"\n";
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : LinearSearch
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters :
//      [IN] T no : The value to search in the array 'Arr'
//
//  Description : 
//      Searches for the specified element 'no' in the array 'Arr' using a linear search approach.
//
//  Returns : 
//      bool
//          -> true if element is found, false otherwise
//
//----------------------------------------------------------------------------------------

template <class T>
bool SearchingX <T> :: LinearSearch(
                                                    T no
                                        )                      
{
    int i = 0;
    bool bFlag = false;

    //  
    // If array is sorted, use efficient binary search
    //
    if(Sorted == true)
    {
        cout<<"data is Sorted\n";
        return BinarySearchEfficientInc(no);
    }

    //
    // Linear search for unsorted array
    //
    for(i = 0; i< iSize; i++)
    {
        if(Arr[i] == no)
        {

            bFlag = true;
            break;
        }
    }

    return bFlag;

}

template <class T>
bool SearchingX <T> :: BiDirectionalSearch(
                                                        T no
                                                )                          
{
    int iStart = 0;
    int iEnd = 0;
    bool bFlag = false;

    for(iStart = 0,iEnd = iSize-1 ; iStart <= iEnd ; iStart++,iEnd--)
    {
        if(Arr[iStart] == no || Arr[iEnd] == no)
        {

            bFlag = true;
            break;
        }
    }

    return bFlag;

}

//----------------------------------------------------------------------------------------
//
//  Function Name   : BiDirectionalSearch
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters :
//      [IN] T no : The value to search in the array 'Arr'
//
//  Description : 
//      Searches for the specified element 'no' using a bidirectional search approach.

//  Returns : 
//      bool
//          -> true if element is found, false otherwise
//
//----------------------------------------------------------------------------------------

template <class T>
bool SearchingX <T> :: BinarySearchInc(
                                                    T no
                                        )                
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;


    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if(Arr[iMid] == no)
        {
            bFlag = true;
            break;
        }
        else if(no < Arr[iMid])     
        {
            iEnd = iMid - 1;
        }
        else if(no > Arr[iMid])    
        {
            iStart = iMid + 1;
        }

    } // End of while

    return bFlag;
    
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : BinarySearchDec
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters :
//      [IN] T no : The value to search in the array 'Arr'
//
//  Description : 
//      Performs a binary search on a descending sorted array to find the element 'no'.

//
//  Returns : 
//      bool
//          -> true if element is found, false otherwise
//
//----------------------------------------------------------------------------------------

template <class T>
bool SearchingX <T> :: BinarySearchDec(
                                                    T no
                                            )                
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;


    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if(Arr[iMid] == no)
        {
            bFlag = true;
            break;
        }
        else if(no > Arr[iMid])     
        {
            iEnd = iMid - 1;
        }
        else if(no < Arr[iMid])    
        {
            iStart = iMid + 1;
        }

    } // End of while

    return bFlag;
    
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : BinarySearchEfficientInc
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters :
//      [IN] T no : The value to search in the array 'Arr'
//
//  Description : 
//      Performs an efficient binary search on an ascending sorted array to find the element 'no'.
//
//  Returns : 
//      bool
//          -> true if element is found, false otherwise
//
//----------------------------------------------------------------------------------------

template <class T>
bool SearchingX <T> :: BinarySearchEfficientInc(
                                                            T no
                                                    )
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;

    if(Sorted = false)           // New
    {
        cout<<"Data is not sorted\n";
        return LinearSearch(no);             
    }

    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if((Arr[iMid] == no) || (Arr[iStart] == no) || (Arr[iEnd] == no))    
        {
            bFlag = true;
            break;
        }
        else if(no < Arr[iMid])     
        {
            iEnd = iMid - 1;
        }
        else if(no > Arr[iMid])    
        {
            iStart = iMid + 1;
        }

    } // End of while

    return bFlag;
    
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : BinarySearchEfficientDec
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters :
//      [IN] T no : The value to search in the array 'Arr'
//
//  Description : 
//      Performs an efficient binary search on a descending sorted array to find the element 'no'.
//
//  Returns : 
//      bool
//          -> true if element is found, false otherwise
//
//----------------------------------------------------------------------------------------

template <class T>
bool SearchingX <T> :: BinarySearchEfficientDec(
                                                            T no
                                                    )
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;


    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if((Arr[iMid] == no) || (Arr[iStart] == no) || (Arr[iEnd] == no))      
        {
            bFlag = true;
            break;
        }
        else if(no > Arr[iMid])    
        {
            iEnd = iMid - 1;
        }
        else if(no < Arr[iMid])    
        {
            iStart = iMid + 1;
        }

    } // End of while

    return bFlag;
    
}


//----------------------------------------------------------------------------------------
//
//  Function Name   : CheckSortedInc
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters :
//      None
//
//  Description : 
//      Checks whether the array 'Arr' is sorted in ascending order.
//
//  Returns : 
//      bool
//          -> true if sorted in ascending order, false otherwise
//
//----------------------------------------------------------------------------------------

template <class T>
bool SearchingX <T> :: CheckSortedInc()
{
    bool bFlag= true;
    int i = 0;

    for(i = 0; i < iSize - 1; i++)
    {
        if(Arr[i] > Arr[i+1])                 
        {
            bFlag = false;
            break;
        }
        
    }

    return bFlag;
}

//----------------------------------------------------------------------------------------
//
//  Function Name   : CheckSortedDec
//  Function Date   : 16/09/2025
//  Function Author : Sarika Devidas Gadhe
//
//  Parameters :
//      None
//
//  Description : 
//      Checks whether the array 'Arr' is sorted in descending order.
//
//  Returns : 
//      bool
//          -> true if sorted in descending order, false otherwise
//
//----------------------------------------------------------------------------------------

template <class T>
bool SearchingX <T> :: CheckSortedDec()                            
{
    bool bFlag= true;
    int i = 0;

    for(i = 0; i < iSize - 1; i++)
    {
        if(Arr[i] < Arr[i+1])                 
        {
            bFlag = false;
            break;
        }
        
    }

    return bFlag;
}



