#include<iostream>
#include "Data_Structures_Library.cpp"

using namespace std;

//==================================================================================
//
// Function Declarations for each demonstration
//
//==================================================================================

void Demonstrate_Queue();
void Demonstrate_Stack();
void Demonstrate_SinglyCLL();
void Demonstrate_DoublyCLL();
void Demonstrate_SinglyLinearLL();
void Demonstrate_DoublyLLL();
void Demonstrate_BST();
void Demonstrate_Sorting();
void Demonstrate_Searching();


//==================================================================================
//
//  Function Name :     Demonstrate_Queue
//  Author        :     Sarika Devidas Gadhe
//  Date          :     17/09/2025
//
//  Description   :     Manages the interactive demonstration of the QueueX class.
//
//  Parameters    :     None
//
//  Returns       :     void
//
//==================================================================================

void Demonstrate_Queue()
{
    cout<<"========================================================="<<endl;
    cout<<"===========  DEMONSTRATING QUEUE OPERATIONS ============="<<endl;
    cout<<"========================================================="<<endl;

    QueueX <int> objQueue;
    int choice, value;

    do
    {
        cout << "\n1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Count" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "Enter your choice: ";

        cin >> choice;

        switch(choice)
        {
            case 1:
                 cout << "Enter value to enqueue: ";
                 cin >> value;
                 objQueue.Enqueue(value);
                 break;

            case 2:
                if (objQueue.Count() > 0)
                {
                    cout << "Dequeued element: " << objQueue.Dequeue() << endl;
                }
                else  
                {
                    cout<<"Queue is empty"<<endl;
                }
                break;

            case 3:
                cout << "Current Queue: ";
                objQueue.Display();
                break;

            case 4:
                cout << "Number of elements in queue: " << objQueue.Count() << endl;
                break;

            case 0:
                break;

            default:
                cout << "Invalid choice." << endl;
             
        }

    }while(choice != 0);
}


//==================================================================================
//
//  Function Name :     Demonstrate_Stack
//  Author        :     Sarika Devidas Gadhe
//  Date          :     17/09/2025
//
//  Description   :     Manages the interactive demonstration of the StackX class.
//
//  Parameters    :     None
//
//  Returns       :     void
//
//==================================================================================

void Demonstrate_Stack()
{
    cout<<"========================================================="<<endl;
    cout<<"===========  DEMONSTRATING STACK OPERATIONS ============="<<endl;
    cout<<"========================================================="<<endl;

     StackX <int> objStack;
     int choice, value;

     do
    {
        cout << "\n1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. Count" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                objStack.Push(value);
                break;
                
            case 2:
                if (objStack.Count() > 0)
                {
                    cout << "Popped element: " << objStack.Pop() << endl;
                }
                break;

            case 3:
                cout << "Current Stack: ";
                objStack.Display();
                break;

            case 4:
                cout << "Number of elements in stack: " << objStack.Count() << endl;
                break;

            case 0:
                break;

            default:
                cout << "Invalid choice." << endl;

            }
    } while (choice != 0);
}

//==================================================================================
//
//  Function Name :     Demonstrate_SinglyCLL
//  Author        :     Sarika Devidas Gadhe
//  Date          :     17/09/2025
//
//  Description   :     Manages the interactive demonstration of the SinglyCLL class.
//
//  Parameters    :     None
//
//  Returns       :     void
//
//==================================================================================

void Demonstrate_SinglyCLL()
{
    cout<<"==================================================================="<<endl;
    cout<<"=========== DEMONSTRATING SINGLY CIRCULAR LINKED LIST ============="<<endl;
    cout<<"==================================================================="<<endl;
     
    SinglyCLL<int> objSCLL;

    int iChoice = 0;
    int iValue = 0;
    int iPos = 0;

    do
    {
        cout << "\n1. InsertFirst" << endl;
        cout << "2. InsertLast" << endl;
        cout << "3. InsertAtPos" << endl;
        cout << "4. DeleteFirst" << endl;
        cout << "5. DeleteLast" << endl;
        cout << "6. DeleteAtPos" << endl;
        cout << "7. Display" << endl;
        cout << "8. Count" << endl;
        cout << "9. SearchFirstOcc" << endl;
        cout << "10. SearchLastOcc" << endl;
        cout << "11. Summation" << endl;
        cout << "12. Summation of Odd elements" << endl;
        cout << "13. Summation of Even elements" << endl;
        cout << "14. Maximum element" << endl;
        cout << "15. Minimum element" << endl;
        cout << "16. Second Maximum element" << endl;
        cout << "17. Display Prime numbers" << endl;
        cout << "18. Display Perfect numbers" << endl;
        cout << "19. Display Sum of Digits" << endl;
        cout << "20. Display Reversed Digits" << endl;
        cout << "21. Display Smallest Digit" << endl;
        cout << "22. Display Largest Digit" << endl;
        cout << "23. Display Product of Digits" << endl;
        cout << "24. Display Palindrome numbers" << endl;
        cout << "0. Exit" << endl;
        cout << "===================================================================" << endl;
        cout << "Enter your choice: ";
        cin >> iChoice;

        switch (iChoice)
        {
            case 1:
                cout << "Enter element to insert at first: ";
                cin >> iValue;
                objSCLL.InsertFirst(iValue);
                break;

            case 2:
                cout << "Enter element to insert at last: ";
                cin >> iValue;
                objSCLL.InsertLast(iValue);
                break;

            case 3:
                cout << "Enter element to insert: ";
                cin >> iValue;
                cout << "Enter position to insert at: ";
                cin >> iPos;
                objSCLL.InsertAtPos(iValue, iPos);
                break;

            case 4:
                objSCLL.DeleteFirst();
                break;

            case 5:
                objSCLL.DeleteLast();
                break;

            case 6:
                cout << "Enter position to delete: ";
                cin >> iPos;
                objSCLL.DeleteAtPos(iPos);
                break;

            case 7:
                cout << "Current List: ";
                objSCLL.Display();
                break;

            case 8:
                cout << "Number of nodes: " << objSCLL.Count() << endl;
                break;

            case 9:
                cout << "Enter element to search for first occurrence: ";
                cin >> iValue;
                iPos = objSCLL.SinglyCircular_SearchFirstOcc(iValue);
                if (iPos != -1)
                {
                    cout << "First occurrence of " << iValue << " is at position: " << iPos << endl;
                }
                else
                {
                    cout << "Element not found." << endl;
                }
                break;

            case 10:
                cout << "Enter element to search for last occurrence: ";
                cin >> iValue;
                iPos = objSCLL.SinglyCircular_SearchLastOcc(iValue);
                if (iPos != -1)
                {
                    cout << "Last occurrence of " << iValue << " is at position: " << iPos << endl;
                }
                else
                {
                    cout << "Element not found." << endl;
                }
                break;

            case 11:
                cout << "Summation of all elements: " << objSCLL.SinglyCircular_Summation() << endl;
                break;

            case 12:
                cout << "Summation of odd elements: " << objSCLL.SinglyCircular_SummationOdd() << endl;
                break;

            case 13:
                cout << "Summation of even elements: " << objSCLL.SinglyCircular_SummationEven() << endl;
                break;

            case 14:
                cout << "Maximum element: " << objSCLL.SinglyCircular_Maximum() << endl;
                break;

            case 15:
                cout << "Minimum element: " << objSCLL.SinglyCircular_Minimum() << endl;
                break;

            case 16:
                cout << "Second Maximum element: " << objSCLL.SinglyCircular_SecMaximum() << endl;
                break;

            case 17:
                cout << "Prime numbers in the list:" << endl;
                objSCLL.SinglyCircular_DisplayPrime();
                break;

            case 18:
                cout << "Perfect numbers in the list:" << endl;
                objSCLL.SinglyCircular_DisplayPerfect();
                break;

            case 19:
                cout << "Sum of digits for each element:" << endl;
                objSCLL.SinglyCircular_SumDigit();
                break;

            case 20:
                cout << "Reversed digits for each element:" << endl;
                objSCLL.SinglyCircular_ReverseDigit();
                break;

            case 21:
                cout << "Smallest digit for each element:" << endl;
                objSCLL.SinglyCircular_DisplaySmallDigit();
                break;

            case 22:
                cout << "Largest digit for each element:" << endl;
                objSCLL.SinglyCircular_DisplayLargeDigit();
                break;

            case 23:
                cout << "Product of digits for each element:" << endl;
                objSCLL.SinglyCircular_DisplayProduct();
                break;

            case 24:
                cout << "Palindrome numbers in the list:" << endl;
                objSCLL.SinglyCircular_DisplayPalindrome();
                break;

            case 0:
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;

        }
     } while (iChoice != 0);    
}


//==================================================================================
//
//  Function Name :     Demonstrate_DoublyCLL
//  Author        :     Sarika Devidas Gadhe
//  Date          :     17/09/2025
//
//  Description   :     Manages the interactive demonstration of the DoublyCLL class.
//
//  Parameters    :     None
//
//  Returns       :     void
//
//==================================================================================

void Demonstrate_DoublyCLL()
{
    cout<<"==================================================================="<<endl;
    cout<<"=========== DEMONSTRATING DOUBLY CIRCULAR LINKED LIST ============="<<endl;
    cout<<"==================================================================="<<endl;
     
    DoublyCLL<int> objDCLL;
    int iChoice = 0;
    int iValue = 0;
    int iPos = 0;

    do
    {
        cout << "\n1. InsertFirst" << endl;
        cout << "2. InsertLast" << endl;
        cout << "3. InsertAtPos" << endl;
        cout << "4. DeleteFirst" << endl;
        cout << "5. DeleteLast" << endl;
        cout << "6. DeleteAtPos" << endl;
        cout << "7. Display" << endl;
        cout << "8. Count" << endl;
        cout << "9. SearchFirstOcc" << endl;
        cout << "10. SearchLastOcc" << endl;
        cout << "11. Summation" << endl;
        cout << "12. Summation of Odd elements" << endl;
        cout << "13. Summation of Even elements" << endl;
        cout << "14. Maximum element" << endl;
        cout << "15. Minimum element" << endl;
        cout << "16. Second Maximum element" << endl;
        cout << "17. Display Prime numbers" << endl;
        cout << "18. Display Perfect numbers" << endl;
        cout << "19. Display Sum of Digits" << endl;
        cout << "20. Display Reversed Digits" << endl;
        cout << "21. Display Smallest Digit" << endl;
        cout << "22. Display Largest Digit" << endl;
        cout << "23. Display Product of Digits" << endl;
        cout << "24. Display Palindrome numbers" << endl;
        cout << "0. Exit" << endl;
        cout << "===================================================================" << endl;
        cout << "Enter your choice: ";
        cin >> iChoice;

        switch (iChoice)
        {
            case 1:
                cout << "Enter element to insert at first: ";
                cin >> iValue;
                objDCLL.InsertFirst(iValue);
                break;

            case 2:
                cout << "Enter element to insert at last: ";
                cin >> iValue;
                objDCLL.InsertLast(iValue);
                break;

            case 3:
                cout << "Enter element to insert: ";
                cin >> iValue;
                cout << "Enter position to insert at: ";
                cin >> iPos;
                objDCLL.InsertAtPos(iValue, iPos);
                break;

            case 4:
                objDCLL.DeleteFirst();
                break;

            case 5:
                objDCLL.DeleteLast();
                break;

            case 6:
                cout << "Enter position to delete: ";
                cin >> iPos;
                objDCLL.DeleteAtPos(iPos);
                break;

            case 7:
                objDCLL.Display();
                break;
                
            case 8:
                cout << "Number of nodes: " << objDCLL.Count() << endl;
                break;

            case 9:
                cout << "Enter element to search for first occurrence: ";
                cin >> iValue;
                iPos = objDCLL.DoublyCircular_SearchFirstOcc(iValue);
                if (iPos != -1)
                {
                    cout << "First occurrence of " << iValue << " is at position: " << iPos << endl;
                }
                else
                {
                    cout << "Element not found." << endl;
                }
                break;

            case 10:
                cout << "Enter element to search for last occurrence: ";
                cin >> iValue;
                iPos = objDCLL.DoublyCircular_SearchLastOcc(iValue);
                if (iPos != -1)
                {
                    cout << "Last occurrence of " << iValue << " is at position: " << iPos << endl;
                }
                else
                {
                    cout << "Element not found." << endl;
                }
                break;

            case 11:
                cout << "Summation of all elements: " << objDCLL.DoublyCircular_Summation() << endl;
                break;

            case 12:
                cout << "Summation of odd elements: " << objDCLL.DoublyCircular_SummationOdd() << endl;
                break;

            case 13:
                cout << "Summation of even elements: " << objDCLL.DoublyCircular_SummationEven() << endl;
                break;

            case 14:
                cout << "Maximum element: " << objDCLL.DoublyCircular_Maximum() << endl;
                break;

            case 15:
                cout << "Minimum element: " << objDCLL.DoublyCircular_Minimum() << endl;
                break;

            case 16:
                cout << "Second Maximum element: " << objDCLL.DoublyCircular_SecMaximum() << endl;
                break;

            case 17:
                cout << "Prime numbers in the list:" << endl;
                objDCLL.DoublyCircular_DisplayPrime();
                break;

            case 18:
                cout << "Perfect numbers in the list:" << endl;
                objDCLL.DoublyCircular_DisplayPerfect();
                break;

            case 19:
                cout << "Sum of digits for each element:" << endl;
                objDCLL.DoublyCircular_SumDigit();
                break;

            case 20:
                cout << "Reversed digits for each element:" << endl;
                objDCLL.DoublyCircular_ReverseDigit();
                break;

            case 21:
                cout << "Smallest digit for each element:" << endl;
                objDCLL.DoublyCircular_DisplaySmallDigit();
                break;

            case 22:
                cout << "Largest digit for each element:" << endl;
                objDCLL.DoublyCircular_DisplayLargeDigit();
                break;

            case 23:
                cout << "Product of digits for each element:" << endl;
                objDCLL.DoublyCircular_DisplayProduct();
                break;

            case 24:
                cout << "Palindrome numbers in the list:" << endl;
                objDCLL.DoublyCircular_DisplayPalindrome();
                break;
                
            case 0:
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
    } while (iChoice != 0);
}

//==================================================================================
//
//  Function Name :     Demonstrate_SinglyLinearLL
//  Author        :     Sarika Devidas Gadhe
//  Date          :     17/09/2025
//
//  Description   :     Manages the interactive demonstration of the SinglyLinearLL class.
//
//  Parameters    :     None
//
//  Returns       :     void
//
//==================================================================================

void Demonstrate_SinglyLinearLL()
{
    cout<<"==================================================================="<<endl;
    cout<<"============ DEMONSTRATING Singly Linear LINKED LIST ==============="<<endl;
    cout<<"==================================================================="<<endl;
     
    SinglyLinearLL<int> objSLL;
    int iChoice = 0;
    int iValue = 0;
    int iPos = 0;

    do
    {
        cout << "\n1. InsertFirst" << endl;
        cout << "2. InsertLast" << endl;
        cout << "3. InsertAtPos" << endl;
        cout << "4. DeleteFirst" << endl;
        cout << "5. DeleteLast" << endl;
        cout << "6. DeleteAtPos" << endl;
        cout << "7. Display" << endl;
        cout << "8. Count" << endl;
        cout << "9. SearchFirstOcc" << endl;
        cout << "10. SearchLastOcc" << endl;
        cout << "11. Summation" << endl;
        cout << "12. Summation of Odd elements" << endl;
        cout << "13. Summation of Even elements" << endl;
        cout << "14. Maximum element" << endl;
        cout << "15. Minimum element" << endl;
        cout << "16. Second Maximum element" << endl;
        cout << "17. Display Prime numbers" << endl;
        cout << "18. Display Perfect numbers" << endl;
        cout << "19. Display Sum of Digits" << endl;
        cout << "20. Display Reversed Digits" << endl;
        cout << "21. Display Smallest Digit" << endl;
        cout << "22. Display Largest Digit" << endl;
        cout << "23. Display Product of Digits" << endl;
        cout << "24. Display Palindrome numbers" << endl;
        cout << "0. Exit" << endl;
        cout << "===================================================================" << endl;
        cout << "Enter your choice: ";
        cin >> iChoice;

        switch (iChoice)
        {
            case 1:
                cout << "Enter element to insert at first: ";
                cin >> iValue;
                objSLL.InsertFirst(iValue);
                break;

            case 2:
                cout << "Enter element to insert at last: ";
                cin >> iValue;
                objSLL.InsertLast(iValue);
                break;

            case 3:
                cout << "Enter element to insert: ";
                cin >> iValue;
                cout << "Enter position to insert at: ";
                cin >> iPos;
                objSLL.InsertAtPos(iValue, iPos);
                break;

            case 4:
                objSLL.DeleteFirst();
                break;

            case 5:
                objSLL.DeleteLast();
                break;

            case 6:
                cout << "Enter position to delete: ";
                cin >> iPos;
                objSLL.DeleteAtPos(iPos);
                break;

            case 7:
                cout << "Current List: ";
                objSLL.Display();
                break;

            case 8:
                cout << "Number of nodes: " << objSLL.Count() << endl;
                break;

            case 9:
                cout << "Enter element to search for first occurrence: ";
                cin >> iValue;
                iPos = objSLL.SinglyLinear_SearchFirstOcc(iValue);
                if (iPos != -1)
                {
                    cout << "First occurrence of " << iValue << " is at position: " << iPos << endl;
                }
                else
                {
                    cout << "Element not found." << endl;
                }
                break;

            case 10:
                cout << "Enter element to search for last occurrence: ";
                cin >> iValue;
                iPos = objSLL.SinglyLinear_SearchLastOcc(iValue);
                if (iPos != -1)
                {
                    cout << "Last occurrence of " << iValue << " is at position: " << iPos << endl;
                }
                else
                {
                    cout << "Element not found." << endl;
                }
                break;

            case 11:
                cout << "Summation of all elements: " << objSLL.SinglyLinear_Summation() << endl;
                break;

            case 12:
                cout << "Summation of odd elements: " << objSLL.SinglyLinear_SummationOdd() << endl;
                break;

            case 13:
                cout << "Summation of even elements: " << objSLL.SinglyLinear_SummationEven() << endl;
                break;

            case 14:
                cout << "Maximum element: " << objSLL.SinglyLinear_Maximum() << endl;
                break;

            case 15:
                cout << "Minimum element: " << objSLL.SinglyLinear_Minimum() << endl;
                break;

            case 16:
                cout << "Second Maximum element: " << objSLL.SinglyLinear_SecMaximum() << endl;
                break;

            case 17:
                cout << "Prime numbers in the list:" << endl;
                objSLL.SinglyLinear_DisplayPrime();
                break;

            case 18:
                cout << "Perfect numbers in the list:" << endl;
                objSLL.SinglyLinear_DisplayPerfect();
                break;

            case 19:
                cout << "Sum of digits for each element:" << endl;
                objSLL.SinglyLinear_SumDigit();
                break;

            case 20:
                cout << "Reversed digits for each element:" << endl;
                objSLL.SinglyLinear_ReverseDigit();
                break;

            case 21:
                cout << "Smallest digit for each element:" << endl;
                objSLL.SinglyLinear_DisplaySmallDigit();
                break;

            case 22:
                cout << "Largest digit for each element:" << endl;
                objSLL.SinglyLinear_DisplayLargeDigit();
                break;

            case 23:
                cout << "Product of digits for each element:" << endl;
                objSLL.SinglyLinear_DisplayProduct();
                break;

            case 24:
                cout << "Palindrome numbers in the list:" << endl;
                objSLL.SinglyLinear_DisplayPalindrome();
                break;

            case 0:
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
                
        }
            
    } while (iChoice != 0);
}

//==================================================================================
//
//  Function Name :     Demonstrate_DoublyLLL
//  Author        :     Sarika Devidas Gadhe
//  Date          :     17/09/2025
//
//  Description   :     Manages the interactive demonstration of the SinglyLinearLL class.
//
//  Parameters    :     None
//
//  Returns       :     void
//
//==================================================================================

void Demonstrate_DoublyLLL()
{
    cout<<"==================================================================="<<endl;
    cout<<"============ DEMONSTRATING DOUBLY Linear LINKED LIST ==============="<<endl;
    cout<<"==================================================================="<<endl;
     
    DoublyLLL<int> objDLL;
    int iChoice = 0;
    int iValue = 0;
    int iPos = 0;

    do
    {
        cout << "\n1. InsertFirst" << endl;
        cout << "2. InsertLast" << endl;
        cout << "3. InsertAtPos" << endl;
        cout << "4. DeleteFirst" << endl;
        cout << "5. DeleteLast" << endl;
        cout << "6. DeleteAtPos" << endl;
        cout << "7. Display" << endl;
        cout << "8. Count" << endl;
        cout << "9. SearchFirstOcc" << endl;
        cout << "10. SearchLastOcc" << endl;
        cout << "11. Summation" << endl;
        cout << "12. Summation of Odd elements" << endl;
        cout << "13. Summation of Even elements" << endl;
        cout << "14. Maximum element" << endl;
        cout << "15. Minimum element" << endl;
        cout << "16. Second Maximum element" << endl;
        cout << "17. Display Prime numbers" << endl;
        cout << "18. Display Perfect numbers" << endl;
        cout << "19. Display Sum of Digits" << endl;
        cout << "20. Display Reversed Digits" << endl;
        cout << "21. Display Smallest Digit" << endl;
        cout << "22. Display Largest Digit" << endl;
        cout << "23. Display Product of Digits" << endl;
        cout << "24. Display Palindrome numbers" << endl;
        cout << "0. Exit" << endl;
        cout << "===================================================================" << endl;
        cout << "Enter your choice: ";
        cin >> iChoice;

        switch (iChoice)
        {
        case 1:
            cout << "Enter element to insert at first: ";
            cin >> iValue;
            objDLL.InsertFirst(iValue);
            break;

        case 2:
            cout << "Enter element to insert at last: ";
            cin >> iValue;
            objDLL.InsertLast(iValue);
            break;

        case 3:
            cout << "Enter element to insert: ";
            cin >> iValue;
            cout << "Enter position to insert at: ";
            cin >> iPos;
            objDLL.InsertAtPos(iValue, iPos);
            break;

        case 4:
            objDLL.DeleteFirst();
            break;

        case 5:
            objDLL.DeleteLast();
            break;

        case 6:
            cout << "Enter position to delete: ";
            cin >> iPos;
            objDLL.DeleteAtPos(iPos);
            break;

        case 7:
            cout << "Current List: ";
            objDLL.Display();
            break;

        case 8:
            cout << "Number of nodes: " << objDLL.Count() << endl;
            break;

        case 9:
            cout << "Enter element to search for first occurrence: ";
            cin >> iValue;
            iPos = objDLL.DoublyLinear_SearchFirstOcc(iValue);
            if (iPos != -1)
            {
                cout << "First occurrence of " << iValue << " is at position: " << iPos << endl;
            }
            else
            {
                cout << "Element not found." << endl;
            }
            break;

        case 10:
            cout << "Enter element to search for last occurrence: ";
            cin >> iValue;
            iPos = objDLL.DoublyLinear_SearchLastOcc(iValue);
            if (iPos != -1)
            {
                cout << "Last occurrence of " << iValue << " is at position: " << iPos << endl;
            }
            else
            {
                cout << "Element not found." << endl;
            }
            break;

        case 11:
            cout << "Summation of all elements: " << objDLL.DoublyLinear_Summation() << endl;
            break;

        case 12:
            cout << "Summation of odd elements: " << objDLL.DoublyLinear_SummationOdd() << endl;
            break;

        case 13:
            cout << "Summation of even elements: " << objDLL.DoublyLinear_SummationEven() << endl;
            break;

        case 14:
            cout << "Maximum element: " << objDLL.DoublyLinear_Maximum() << endl;
            break;

        case 15:
            cout << "Minimum element: " << objDLL.DoublyLinear_Minimum() << endl;
            break;

        case 16:
            cout << "Second Maximum element: " << objDLL.DoublyLinear_SecMaximum() << endl;
            break;

        case 17:
            cout << "Prime numbers in the list:" << endl;
            objDLL.DoublyLinear_DisplayPrime();
            break;

        case 18:
            cout << "Perfect numbers in the list:" << endl;
            objDLL.DoublyLinear_DisplayPerfect();
            break;

        case 19:
            cout << "Sum of digits for each element:" << endl;
            objDLL.DoublyLinear_SumDigit();
            break;

        case 20:
            cout << "Reversed digits for each element:" << endl;
            objDLL.DoublyLinear_ReverseDigit();
            break;

        case 21:
            cout << "Smallest digit for each element:" << endl;
            objDLL.DoublyLinear_DisplaySmallDigit();
            break;

        case 22:
            cout << "Largest digit for each element:" << endl;
            objDLL.DoublyLinear_DisplayLargeDigit();
            break;

        case 23:
            cout << "Product of digits for each element:" << endl;
            objDLL.DoublyLinear_DisplayProduct();
            break;

        case 24:
            cout << "Palindrome numbers in the list:" << endl;
            objDLL.DoublyLinear_DisplayPalindrome();
            break;

        case 0:
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        
        }
            
    } while (iChoice != 0);
}

//==================================================================================
//
//  Function Name :     Demonstrate_BST
//  Author        :     Sarika Devidas Gadhe
//  Date          :     17/09/2025
//
//  Description   :     Manages the interactive demonstration of the class BST class.
//
//  Parameters    :     None
//
//  Returns       :     void
//
//==================================================================================

void Demonstrate_BST()
{
    cout<<"==================================================================="<<endl;
    cout<<"============== DEMONSTRATING BINARY SEARCH TREE =================="<<endl;
    cout<<"==================================================================="<<endl;

    BST<int> objBST;
    int iChoice = 0;
    int iValue = 0;

    do
    {
        cout << "\n1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Display Inorder" << endl;
        cout << "4. Display Preorder" << endl;
        cout << "5. Display Postorder" << endl;
        cout << "6. Display All Counts" << endl;
        cout << "0. Exit" << endl;
        cout << "===================================================================" << endl;        
        cout << "Enter your choice: ";
        cin >> iChoice;

        switch (iChoice)
        {
            case 1:
                cout << "Enter element to insert: ";
                cin >> iValue;
                objBST.Insert(iValue);
                break;

            case 2:
                cout << "Enter element to search for: ";
                cin >> iValue;
                if (objBST.Search(iValue))
                {
                    cout << "Element found...!" << endl;
                }
                else
                {
                    cout << "Element not found...!" << endl;
                }
                break;

            case 3:
                objBST.DisplayInorder();
                break;

            case 4:
                objBST.DisplayPreorder();
                break;

            case 5:
                objBST.DisplayPostorder();
                break;

            case 6:
                objBST.CountAll();
                break;

            case 0:
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;

        }
    } while (iChoice != 0);     

}

//==================================================================================
//
//  Function Name :     Demonstrate_Sorting
//  Author        :     Sarika Devidas Gadhe
//  Date          :     17/09/2025
//
//  Description   :     Manages the interactive demonstration of the class SortingX  class.
//
//  Parameters    :     None
//
//  Returns       :     void
//
//==================================================================================

void Demonstrate_Sorting()
{
    cout<<"==================================================================="<<endl;
    cout<<"============== DEMONSTRATING SORTING ALGORITHMS =================="<<endl;
    cout<<"==================================================================="<<endl;

    SortingX<int>* objSort = NULL;
    int iChoice = 0;
    int iSize = 0;

    do
    {
        cout << "\n1. Create Array" << endl;
        cout << "2. Bubble Sort" << endl;
        cout << "3. Optimized Bubble Sort" << endl;
        cout << "4. Selection Sort" << endl;
        cout << "5. Insertion Sort" << endl;
        cout << "6. Display array" << endl;
        cout << "0. Exit" << endl;
        cout << "===================================================================" << endl;        
        cout << "Enter your choice: ";
        cin >> iChoice;

        switch (iChoice)
        {
            case 1:
                if (objSort != NULL)
                {
                    delete objSort;
                }
                cout << "Enter the size of the array: ";
                cin >> iSize;
                objSort = new SortingX<int>(iSize);
                objSort->Accept();
                break;

            case 2:
                if (objSort == NULL)
                {
                    cout << "Please create an array first (Option 1)." << endl;
                }
                else
                {
                    cout << "Original array: " << endl;
                    objSort->Display();
                    objSort->BubbleSort();
                    cout << "Array after Bubble Sort: " << endl;
                    objSort->Display();
                }
                break;

            case 3:
                if (objSort == NULL)
                {
                    cout << "Please create an array first (Option 1)." << endl;
                }
                else
                {
                    cout << "Original array: " << endl;
                    objSort->Display();
                    objSort->BubbleSortEfficient();
                    cout << "Array after Optimized Bubble Sort: " << endl;
                    objSort->Display();
                }
                break;

            case 4:
                if (objSort == NULL)
                {
                    cout << "Please create an array first (Option 1)." << endl;
                }
                else
                {
                    cout << "Original array: " << endl;
                    objSort->Display();
                    objSort->SelectionSort();
                    cout << "Array after Selection Sort: " << endl;
                    objSort->Display();
                }
                break;

            case 5:
                if (objSort == NULL)
                {
                    cout << "Please create an array first (Option 1)." << endl;
                }
                else
                {
                    cout << "Original array: " << endl;
                    objSort->Display();
                    objSort->InsertionSort();
                    cout << "Array after Insertion Sort: " << endl;
                    objSort->Display();
                }
                break;

            case 6:
                if (objSort == NULL)
                {
                    cout << "Please create an array first (Option 1)." << endl;
                }
                else
                {
                    objSort->Display();
                }
                break;

            case 0:
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;

        }
    } while (iChoice != 0);

    // Clean up dynamically allocated memory before exiting
    if (objSort != NULL)
    {
        delete objSort;
    }
}

//==================================================================================
//
//  Function Name :     Demonstrate_Searching
//  Author        :     Sarika Devidas Gadhe
//  Date          :     17/09/2025
//
//  Description   :     Manages the interactive demonstration of the class SearchingX class.
//
//  Parameters    :     None
//
//  Returns       :     void
//
//==================================================================================

void Demonstrate_Searching()
{
    cout<<"==================================================================="<<endl;
    cout<<"============== DEMONSTRATING SEARCHING  ALGORITHMS =================="<<endl;
    cout<<"==================================================================="<<endl;

    SearchingX<int>* objSearch = NULL;
    int iChoice = 0;
    int iSize = 0;
    int iValue = 0;
    bool bFound = false;

    do
    {
        cout << "\n1. Create/Re-enter array" << endl;
        cout << "2. Display array" << endl;
        cout << "3. Linear Search" << endl;
        cout << "4. Bi-directional Search" << endl;
        cout << "5. Binary Search (Ascending)" << endl;
        cout << "6. Binary Search (Descending)" << endl;
        cout << "7. Optimized Binary Search (Ascending)" << endl;
        cout << "8. Optimized Binary Search (Descending)" << endl;
        cout << "9. Check if array is sorted (Increasing)" << endl;
        cout << "10. Check if array is sorted (Decreasing)" << endl;
        cout << "0. Exit" << endl;
        cout << "===================================================================" << endl;        
        cout << "Enter your choice: ";
        cin >> iChoice;

        switch (iChoice)
        {
            case 1:
                if (objSearch != NULL)
                {
                    delete objSearch;
                }
                cout << "Enter the size of the array: ";
                cin >> iSize;
                objSearch = new SearchingX<int>(iSize);
                objSearch->Accept();
                break;

            case 2:
                if (objSearch == NULL)
                {
                    cout << "Please create an array first (Option 1)." << endl;
                }
                else
                {
                    objSearch->Display();
                }
                break;

            case 3:
                if (objSearch == NULL)
                {
                    cout << "Please create an array first (Option 1)." << endl;
                }
                else
                {
                    cout << "Enter the value to search: ";
                    cin >> iValue;
                    bFound = objSearch->LinearSearch(iValue);
                    if (bFound)
                    {
                        cout << "Value found in the array." << endl;
                    }
                    else
                    {
                        cout << "Value not found." << endl;
                    }
                }
                break;

            case 4:
                if (objSearch == NULL)
                {
                    cout << "Please create an array first (Option 1)." << endl;
                }
                else
                {
                    cout << "Enter the value to search: ";
                    cin >> iValue;
                    bFound = objSearch->BiDirectionalSearch(iValue);
                    if (bFound)
                    {
                        cout << "Value found in the array." << endl;
                    }
                    else
                    {
                        cout << "Value not found." << endl;
                    }
                }
                break;

            case 5:
                if (objSearch == NULL)
                {
                    cout << "Please create an array first (Option 1)." << endl;
                }
                else
                {
                    cout << "Enter the value to search: ";
                    cin >> iValue;
                    if (objSearch->CheckSortedInc())
                    {
                        bFound = objSearch->BinarySearchInc(iValue);
                        if (bFound)
                        {
                            cout << "Value found in the array." << endl;
                        }
                        else
                        {
                            cout << "Value not found." << endl;
                        }
                    }
                    else
                    {
                        cout << "Error: Binary Search (Ascending) requires a sorted array." << endl;
                    }
                }
                break;

            case 6:
                if (objSearch == NULL)
                {
                    cout << "Please create an array first (Option 1)." << endl;
                }
                else
                {
                    cout << "Enter the value to search: ";
                    cin >> iValue;
                    if (objSearch->CheckSortedDec())
                    {
                        bFound = objSearch->BinarySearchDec(iValue);
                        if (bFound)
                        {
                            cout << "Value found in the array." << endl;
                        }
                        else
                        {
                            cout << "Value not found." << endl;
                        }
                    }
                    else
                    {
                        cout << "Error: Binary Search (Descending) requires a sorted array." << endl;
                    }
                }
                break;

            case 7:
                if (objSearch == NULL)
                {
                    cout << "Please create an array first (Option 1)." << endl;
                }
                else
                {
                    cout << "Enter the value to search: ";
                    cin >> iValue;
                    bFound = objSearch->BinarySearchEfficientInc(iValue);
                    if (bFound)
                    {
                        cout << "Value found in the array." << endl;
                    }
                    else
                    {
                        cout << "Value not found." << endl;
                    }
                }
                break;
                
            case 8:
                if (objSearch == NULL)
                {
                    cout << "Please create an array first (Option 1)." << endl;
                }
                else
                {
                    cout << "Enter the value to search: ";
                    cin >> iValue;
                    bFound = objSearch->BinarySearchEfficientDec(iValue);
                    if (bFound)
                    {
                        cout << "Value found in the array." << endl;
                    }
                    else
                    {
                        cout << "Value not found." << endl;
                    }
                }
                break;
                
            case 9:
                if (objSearch == NULL)
                {
                    cout << "Please create an array first (Option 1)." << endl;
                }
                else
                {
                    if (objSearch->CheckSortedInc())
                    {
                        cout << "The array is sorted in increasing order." << endl;
                    }
                    else
                    {
                        cout << "The array is NOT sorted in increasing order." << endl;
                    }
                }
                break;

            case 10:
                if (objSearch == NULL)
                {
                    cout << "Please create an array first (Option 1)." << endl;
                }
                else
                {
                    if (objSearch->CheckSortedDec())
                    {
                        cout << "The array is sorted in decreasing order." << endl;
                    }
                    else
                    {
                        cout << "The array is NOT sorted in decreasing order." << endl;
                    }
                }
                break;

            case 0:
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (iChoice != 0);

    // Clean up dynamically allocated memory before exiting
    if (objSearch != NULL)
    {
        delete objSearch;
    }
}

//==================================================================================
//
// Function Name   :    main (Entry point function)
// Author          :    Sarika Devidas Gadhe
//  Date           :    16/09/2025
// 
// Description   : The entry point for the program. Displays the main menu and
//                 calls the appropriate demonstration function based on user input.
//
//==================================================================================

int main()
{
    int choice;

    do
    {
        cout << "\n=========================================================" << endl;
        cout << "===============  DATA STRUCTURES LIBRARY MENU =============" << endl;
        cout << "===========================================================" << endl;
        cout << "1. Demonstrate QueueX" << endl;
        cout << "2. Demonstrate StackX" << endl;
        cout << "3. Demonstrate Singly Circular Linked List" << endl;
        cout << "4. Demonstrate Doubly Circular Linked List" << endl;
        cout << "5. Demonstrate Singly Linear Linked List" << endl;
        cout << "6. Demonstrate Doubly Linear Linked List" << endl;
        cout << "7. Demonstrate Binary Search Tree" << endl;
        cout << "8. Demonstrate Sorting Algorithms" << endl;
        cout << "9. Demonstrate Searching Algorithms" << endl;
        cout << "0. Exit" << endl;
        cout << "===========================================================" << endl;
        
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                Demonstrate_Queue();
                break;

            case 2:
                Demonstrate_Stack();
                break;

            case 3:
                Demonstrate_SinglyCLL();
                break;

            case 4:
                Demonstrate_DoublyCLL();
                break;

            case 5:
                Demonstrate_SinglyLinearLL();
                break;

            case 6:
                Demonstrate_DoublyLLL();
                break;

            case 7:
                Demonstrate_BST();
                break;

            case 8:
                Demonstrate_Sorting();
                break;

            case 9:
                Demonstrate_Searching();
                break;

            case 0:
                cout << "Exiting program....!" << endl;
                cout << "\n😊 Thank you for using my application.....! Have a great day! 🌟\n";
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

    } while (choice != 0);

    return 0;
}