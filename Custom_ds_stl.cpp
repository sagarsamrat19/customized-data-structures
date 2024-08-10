#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Implemetion : Generic Doubly link list 
// Language    : C++ 
// Author      : Sagar Samrat
// I/P         : int,float,double,chater
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct nodeDLL
{
    T data;
    struct nodeDLL<T> *next;
    struct nodeDLL<T> *prev;
};

template<class T>
class DoublyLL
{
    private:
        struct nodeDLL<T> *First;
        int iCount;

    public:
        DoublyLL();
        // Diplay and count call by value
        void Display();
        int Count();
        // Insertion Opeartion call by value
        void InsertFirst(T No);
        void InsertLast(T No);        
        void InsertAtPos(T No, int iPos);
        // Deletion Opeartion call by value
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};
template<class T>
DoublyLL<T>::DoublyLL()
{
    cout<<"Inside constructor"<<endl;
    First = NULL;
    iCount = 0;
}
template<class T>
void DoublyLL<T>::Display()
{
    struct nodeDLL<T> *  temp = First;
    while (temp != NULL)
    {
        cout<<"| "<<temp -> data<<" | <=>";
        temp  = temp -> next;
    }
    cout<<"| NULL |"<<endl;
}
template<class T>
int DoublyLL<T>::Count()
{
    return iCount;
}
template<class T>
void DoublyLL<T>::InsertFirst(T No)
{
    struct nodeDLL<T> *  newn = NULL;
    newn = new nodeDLL<T>;
    newn -> data = No;
    newn -> next = NULL;
    newn -> prev = NULL;
    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn -> next = First;
        First -> prev = newn;
        First = newn;
    }
    iCount++;
}
template<class T>
void DoublyLL<T>::InsertLast(T No)
{
    struct nodeDLL<T>*  newn = NULL;
    struct nodeDLL<T>*  temp = NULL;

    newn = new nodeDLL<T>;
    newn -> data = No;
    newn -> next = NULL;
    newn -> prev = NULL;
    if(First == NULL)
    {
        First = newn;

    }
    else
    {
        temp = First;
        while (temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
        newn -> prev = temp;
        
    }
    iCount++;
}
template<class T>
void DoublyLL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeDLL<T>*  newn = NULL;
    struct nodeDLL<T>*  temp = First;
    int i = 0;
    newn = new nodeDLL<T>;
    newn -> data = No;
    newn -> next = NULL;
    newn -> prev = NULL;
   if((iPos < 1) || (iPos> iCount +1))
    {
        cout<<"Invalid Pos"<<endl;
        return;
    }
    if(iPos == 1)
    {
        InsertFirst(No);

    }
    else if(iPos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        for ( i = 1; i < iPos - 1 ; i++)
        {
            temp = temp -> next;
        }
        
        newn -> next = temp -> next; // 300
        temp -> next -> prev = newn; //50
        temp  -> next = newn; //50
        newn -> prev = temp; //200
        iCount++;
    }

}
template<class T>
void DoublyLL<T>::DeleteFirst()
{
    if(First == NULL)
    {
        cout<<"DLL is Empty"<<endl;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {

        First = First-> next;
        delete First -> prev;
        First -> prev = NULL;
    }
    iCount--;
}
template<class T>
void DoublyLL<T>::DeleteLast()
{
    struct nodeDLL<T>*  temp = First;
    if(First == NULL)
    {
        cout<<"DLL is Empty"<<endl;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while (temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }
        delete temp -> next;
        temp -> next = NULL;
        
    }
    iCount--;
}
template<class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    struct nodeDLL<T>*  temp = First;
    int i = 0;
   if((iPos < 1) || (iPos> iCount +1))
    {
        cout<<"Invalid Pos"<<endl;
        return;
    }
    if(iPos == 1)
    {
        DeleteFirst();

    }
    else if(iPos == iCount + 1)
    {
        DeleteLast();
    }
    else
    {
        for ( i = 1; i < iPos - 1 ; i++)
        {
            temp = temp -> next;
        }
        temp -> next = temp -> next -> next;
        delete temp -> next -> prev;
        temp -> next -> prev = temp;
        iCount--;
    }
}  

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Implemetion : Generic singly link list 
// Language    : C++ 
// Author      : Sagar Samrat
// I/P         : int,float,double,chater
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct nodeSL
{
    T data;
    struct nodeSL *next;
};

template<class T>
class SinglyLL
{
    private:
        struct nodeSL<T> * First;
        int iCount;
    public:
        SinglyLL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};
template<class T>
SinglyLL<T>::SinglyLL()
{
    cout<<"Inside Constructor\n";
    First = NULL;
    iCount = 0;
}
template<class T>
void SinglyLL<T>::Display()
{
    struct nodeSL<T> * temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<"|-> ";
        temp = temp -> next;
    }
    cout<<"NULL\n";
}
template<class T>
int SinglyLL<T>::Count()
{
    return iCount;
}
template<class T>
void SinglyLL<T>::InsertFirst(T No)
{
    struct nodeSL<T> * newn = NULL;

    newn = new nodeSL<T>;    // malloc

    newn->data = No;
    newn->next = NULL;

    if(First == NULL) // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}
template<class T>
void SinglyLL<T>::InsertLast(T No)
{
    struct nodeSL<T> * newn = NULL;
    struct nodeSL<T> * temp = First;

    newn = new nodeSL<T>;    // malloc

    newn->data = No;
    newn->next = NULL;

    if(First == NULL) // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
    iCount++;
}
template<class T>
void SinglyLL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeSL<T> * newn = NULL;
    int i = 0;
    struct nodeSL<T> * temp;

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else 
    {
        temp = First;
        
        newn = new nodeSL<T>;
        newn->data = No;
        newn->next = NULL;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp -> next = newn;
        iCount++;
    }
}
template<class T>
void SinglyLL<T>::DeleteFirst()
{
    struct nodeSL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First -> next;
        delete temp;
    }
    iCount--;
}
template<class T>
void SinglyLL<T>::DeleteLast()
{
    struct nodeSL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp ->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}
template<class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
    struct nodeSL<T> * temp1;
    struct nodeSL<T> * temp2;

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else 
    {
        temp1 = First;

        for(i = 1; i < iPos-1; i++)
        {
            temp1 = temp1 -> next;
        }

        temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;

        iCount--;
    }    
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Implemetion : Generic Singly circular link list 
// Language    : C++ 
// Author      : Sagar Samrat
// I/P         : int,float,double,chater
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct nodeSCLL
{
    T data;
    struct nodeSCLL<T> *next;
};

template<class T>
class SinglyCL
{
    private:
        struct nodeSCLL<T> * First;
        struct nodeSCLL<T> * Last;
        int iCount;

    public:
        SinglyCL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};
template<class T>
SinglyCL<T>::SinglyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}
template<class T>
void SinglyCL<T>::Display()
{
    struct nodeSCLL<T> * temp = First;

    if((First == NULL) && (Last == NULL))
        {
            cout<<"LL is Empty"<<endl;
            return;
        }
    do
    {
        cout<<"| "<<temp -> data<<" |->";
        temp = temp ->next;
    } while (temp != Last ->next);
    cout<<endl;
}
template<class T>
int SinglyCL<T>::Count()
{
    return iCount;
}
template<class T>
void SinglyCL<T>::InsertFirst(T No)
{
    struct nodeSCLL<T> * newn = NULL;
    newn = new nodeSCLL<T>;
    newn -> data = No;
    newn -> next =NULL;
    if(First == NULL)
    {
        First = newn;
        Last = newn;
        Last -> next = newn;
    }
    else
    {
        newn -> next = First;
        First = newn;
        Last -> next = First;
    }
    iCount++;
}
template<class T>
void SinglyCL<T>::InsertLast(T No)
{
    struct nodeSCLL<T> * newn = NULL;
    newn = new nodeSCLL<T>;
    newn -> data = No;
    newn -> next =NULL;
    if(First == NULL)
    {
        First = newn;
        Last = newn;
        Last -> next = newn;
    }
    else
    {
        Last -> next = newn;
        Last = newn;
         
    }
    Last ->next = First;
    iCount++;
}
template<class T>
void SinglyCL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeSCLL<T> * newn = NULL;
    struct nodeSCLL<T> * temp = First;
    int i = 0;
    if((iPos < 1) || (iPos > iCount +1))
        {
            cout<<"Invalid Postion"<<ends;
            return;
        }
    if(iPos == 1)
        {
            InsertFirst(No);
        }
    else if(iPos == iCount + 1)
        {
            InsertLast(No);
        }
    else
    {
        for ( i = 1; i < iPos -1; i++)
        {
            temp = temp -> next;
        }
        
        newn = new nodeSCLL<T>;
        newn -> data = No;
        newn -> next = NULL;
        newn -> next = temp -> next;
        temp -> next = newn;
        iCount++;
    }

}
template<class T>
void SinglyCL<T>::DeleteFirst()
{
    if((First == NULL) && (Last == NULL))
    {
        cout<<"LL is empty"<<endl;
        return;
    }
    if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First -> next;
        delete Last -> next;
        Last -> next = First;
    }
    iCount--;
}
template<class T>
void SinglyCL<T>::DeleteLast()
{
    struct nodeSCLL<T> * temp = First;
    if((First == NULL) && (Last == NULL))
    {
        cout<<"LL is empty"<<endl;
        return;
    }
    if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        while (temp-> next != Last)
        {
            temp = temp -> next;
        }
        delete Last;
        Last = temp;
        Last -> next = First;       
    }
    iCount--;
}
template<class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
    struct nodeSCLL<T> * temp1 = NULL;
    struct nodeSCLL<T> * temp2 = NULL;
    int i =  0;
    if((iPos < 1) || (iPos > iCount +1))
        {   
           return;
        }
    if(iPos ==1)
        {
            DeleteFirst();
        }
    else if (iPos == iCount + 1)
        {
            DeleteLast();
        }
    else
    {
        temp1 = First;
        for (i = 1; i < iPos -1; i++)
        {
            temp1 = temp1 -> next;
        }
        temp2 = temp1 -> next;
        temp1 -> next = temp2 -> next;
        delete (temp2);
        iCount--;   
    }
    Last -> next = First;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Implemetion : Generic Doubly Circular link list 
// Language    : C++ 
// Author      : Sagar Samrat
// I/P         : int,float,double,chater
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct nodeDL
{
    int data;
    struct nodeDL *next;
    struct nodeDL *prev;
};

template<class T>
class DoublyCL
{
    private:
        struct nodeDL<T> *  First;
        struct nodeDL<T> *  Last;
        int iCount;
    public:
        DoublyCL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};
template<class T>
DoublyCL<T> :: DoublyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}
template<class T>
void DoublyCL<T>::Display()
{
    if(First == NULL && Last == NULL)
    {
        cout<<"Linked List is emprty\n";
        return;
    }

    cout<<"<=> ";
    do
    {
        cout<<"| "<<First->data <<"| <=> ";
        First = First -> next;
    }while(Last -> next != First);

    cout<<"\n";
}
template<class T>
int DoublyCL<T>::Count()
{
    return iCount;
}
template<class T>
void DoublyCL<T>::InsertFirst(T No)
{
    struct nodeDL<T> *  newn = NULL;

    newn = new nodeDL<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    Last -> next = First;
    First -> prev = Last;

    iCount++;
}
template<class T>
void DoublyCL<T>::InsertLast(T No)
{
    struct nodeDL<T> *  newn = NULL;

    newn = new nodeDL<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last ->next = newn;
        newn->prev = Last;
        Last = newn;
    }
    Last -> next = First;
    First -> prev = Last;

    iCount++;    
}
template<class T>
void DoublyCL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeDL<T> *  temp = NULL;
    struct nodeDL<T> *  newn = NULL;

    int i = 0;

    if(iPos < 1 || iPos > iCount+1)
    {
        cout<<"Invalid postion\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        newn = new nodeDL<T>;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;

        for(i = 1;i < iPos -1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}
template<class T>
void DoublyCL<T>::DeleteFirst()
{
    if(First == NULL && Last == NULL)   // Empty LL
    {
        return;
    }
    else if(First == Last)   // Single nodeDL
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else    // More than one nodeDL
    {
        First = First -> next;
        delete Last->next;
        First -> prev = Last;
        Last -> next = First;
    }
    iCount--;
}
template<class T>
void DoublyCL<T>::DeleteLast()
{
    if(First == NULL && Last == NULL)   // Empty LL
    {
        return;
    }
    else if(First == Last)   // Single nodeDL
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else    // More than one nodeDL
    {
        Last = Last -> prev;
        delete First -> prev;

        Last -> next = First;
        First -> prev = Last;
    }
    iCount--;    
}
template<class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    struct nodeDL<T> *  temp = NULL;

    int i = 0;

    if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid postion\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = First;

        for(i = 1; i < iPos -1; i++)
        {
            temp = temp -> next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }    
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Implemetion : Generic Queue
// Language    : C++ 
// Author      : Sagar Samrat
// I/P         : int,float,double,chater
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct nodeQ
{
    T data;
    struct nodeQ<T> *next;
};

template<class T>
class Queue
{
    private:
        struct nodeQ<T> * First;
        int iCount;

    public:
        Queue();
        void Display();
        int Count();
        void EnQueue(T No);  // InsertLast()
        T DeQueue();   // DeleteFirst()
};
template<class T>
Queue<T> :: Queue()
{
    First = NULL;
    iCount = 0;
}
template<class T>
void Queue<T>  ::Display()
{
    cout<<"Elements of Queue are : \n";
    struct nodeQ<T> * temp = First;

    while(temp != NULL)
    {
        cout<<temp->data<<"\t";
        temp = temp -> next;
    }
    cout<<"\n";
}
template<class T>
int Queue<T>  ::Count()
{
    return iCount;
}
template<class T>
void Queue<T>  ::EnQueue(T No)
{
    struct nodeQ<T> * newn = NULL;
    struct nodeQ<T> * temp = NULL;

    newn = new nodeQ<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;

        while(temp ->next != NULL)
        {
            temp = temp -> next;
        }

        temp->next = newn;
    }
    iCount++;
}
template<class T>
T Queue<T>  ::DeQueue()
{
    int iValue = 0;
    struct nodeQ<T> * temp = NULL;

    if(First == NULL)
    {
        cout<<"Unable to remove the element as queue is empty\n";
        return -1;
    }
    else
    {
        temp = First;

        iValue = First -> data;
        First = First -> next;
        delete temp;
        
        iCount--;
    }

    return iValue;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Implemetion : Generic Stack
// Language    : C++ 
// Author      : Sagar Samrat
// I/P         : int,float,double,chater
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


template<class T>
struct nodeST
{
    T data;
    struct nodeST<T>* next;  
};

template<class T>
class Stack
{
    private:
        struct nodeST<T>* First;
        int iCount;
    public:
        Stack();
        void Display();
        int Count();
        void Push(T No); // InsertFIirst
        int Pop();        // InsertLast
};
template<class T>
Stack<T>::Stack()
{
    First  = NULL;
    iCount = 0;
}
template<class T>
void Stack<T>::Display()
{
    cout<<"Elements of stack"<<endl;
    struct nodeST<T>* temp = First; 
    while (temp != NULL)
    {

        cout<<"| " <<temp-> data <<" |"<<endl;
        temp = temp-> next;
    }
    cout<<endl;
}
template<class T>
int Stack<T>::Count()
{
    return iCount;
}
template<class T>
int Stack<T>::Pop()
{   
    int ivalue = 0;
    struct nodeST<T>* temp = NULL;
    if (First == NULL)
    {
       cout<<"Unable to pop the elements as stack is empty"<<endl;
       return -1;
    }
    else
    {
        temp = First;
        ivalue = First -> data;
        First = First -> next;
        delete temp;
        iCount--;
    }
    return ivalue;
}
template<class T>
void Stack<T>::Push(T No)
{   
    struct nodeST<T>* newn = NULL;
    newn= new nodeST<T>;
    newn -> data = No;
    newn -> next = NULL;
    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn -> next = First;
        First = newn;
    }
    iCount++;   
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Main Function calling all implemtion hare
// Language    : C++ 
// Author      : Sagar Samrat
// I/P         : int,float,double,chater
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    cout<<"----------------- link list of Integer---------"<<endl;
    SinglyLL<int> *iobj = new SinglyLL<int>();
    int iRet = 0;

    iobj->InsertFirst(51);
    iobj->InsertFirst(21);
    iobj->InsertFirst(11);

    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    iobj->InsertLast(101);
    iobj->InsertLast(111);
    iobj->InsertLast(121);
    
    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    iobj->InsertAtPos(105,5);

    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    iobj->DeleteAtPos(5);
    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;
    cout<<"--------------------------------------"<<endl;
     cout<<"----------------- link list of floats---------"<<endl;
    SinglyLL<float> *fobj = new SinglyLL<float>();
    int fRet = 0;

    fobj->InsertFirst(51.07f);
    fobj->InsertFirst(21.07f);
    fobj->InsertFirst(11.07f);

    fobj->Display();
    fRet = fobj->Count();
    cout<<"Number of elemensts are : "<<fRet<<endl;

    fobj->InsertLast(101.07f);
    fobj->InsertLast(111.07f);
    fobj->InsertLast(121.07f);
    
    fobj->Display();
    fRet = fobj->Count();
    cout<<"Number of elemensts are : "<<fRet<<endl;

    fobj->InsertAtPos(105.07f,5);

    fobj->Display();
    fRet = fobj->Count();
    cout<<"Number of elemensts are : "<<fRet<<endl;

    fobj->DeleteAtPos(5);
    fobj->Display();
    fRet = fobj->Count();
    cout<<"Number of elemensts are : "<<fRet<<endl;
    cout<<"--------------------------------------"<<endl;
     cout<<"----------------- link list of character---------"<<endl;
    SinglyLL<char> *cobj = new SinglyLL<char>();

    cobj->InsertFirst('A');
    cobj->InsertFirst('B');
    cobj->InsertFirst('C');

    cobj->Display();
    fRet = cobj->Count();
    cout<<"Number of elemensts are : "<<fRet<<endl;

    cobj->InsertLast('D');
    cobj->InsertLast('E');
    cobj->InsertLast('F');
    
    cobj->Display();
    fRet = cobj->Count();
    cout<<"Number of elemensts are : "<<fRet<<endl;

    cobj->InsertAtPos('G',5);

    cobj->Display();
    fRet = fobj->Count();
    cout<<"Number of elemensts are : "<<fRet<<endl;

    cobj->DeleteAtPos(5);
    cobj->Display();
    fRet = cobj->Count();
    cout<<"Number of elemensts are : "<<fRet<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"----------------- link list of double---------"<<endl;
    SinglyLL<double> *dobj = new SinglyLL<double>();

    dobj->InsertFirst(5156.0755);
    dobj->InsertFirst(2156.0755);
    dobj->InsertFirst(1156.0755);

    dobj->Display();
    fRet = dobj->Count();
    cout<<"Number of elemensts are : "<<fRet<<endl;

    dobj->InsertLast(10156.0755f);
    dobj->InsertLast(11156.0755);
    dobj->InsertLast(12156.0755);
    
    dobj->Display();
    fRet = dobj->Count();
    cout<<"Number of elemensts are : "<<fRet<<endl;

    dobj->InsertAtPos(1056.0755,5);

    dobj->Display();
    fRet = dobj->Count();
    cout<<"Number of elemensts are : "<<fRet<<endl;

    dobj->DeleteAtPos(5);
    dobj->Display();
    fRet = dobj->Count();
    cout<<"Number of elemensts are : "<<fRet<<endl;
    cout<<"--------------------------------------"<<endl;
    // DoublyCL obj;
    cout<<"------------------------ Doubly circular link list ------------"<<endl;
    DoublyCL<int> *diobj = new DoublyCL<int>();
    diobj->InsertFirst(51);
    diobj->InsertFirst(21);
    diobj->InsertFirst(11);
    
    diobj->InsertLast(101);
    diobj->InsertLast(111);
    diobj->InsertLast(121);
    
    diobj->Display();
    iRet = diobj->Count();

    diobj->DeleteAtPos(5);
    
    diobj->Display();
    iRet = diobj->Count();
        cout<<"-----------------generic Doubly  Link  List int  input ------ "<<endl;
    DoublyLL<int> *idll = new DoublyLL<int>();
    idll->InsertFirst(21);
    idll->InsertFirst(11);
    idll->InsertLast(51);
    idll->InsertLast(101);
    idll->Display();
    cout<<"Number of node is "<<idll->Count()<<endl;
    idll->DeleteFirst();
    idll->Display();
    cout<<"Number of node is "<<idll->Count()<<endl;
    idll->DeleteLast();
    idll->InsertAtPos(72,2);
    idll->InsertAtPos(73,3);
    idll->Display();
    cout<<"Number of node is "<<idll->Count()<<endl;
    idll->DeleteAtPos(2);
    idll->Display();
    cout<<"Number of node is "<<idll->Count()<<endl;
    idll->DeleteAtPos(2);
    idll->Display();
    cout<<"Number of node is "<<idll->Count()<<endl;
    cout<<"--------------------- generic Doubly  Link  List flaot  input ------ "<<endl;
    DoublyLL<float> *fdll = new DoublyLL<float>();
    fdll->InsertFirst(21.236f);
    fdll->InsertFirst(11.236f);
    fdll->InsertLast(51.236f);
    fdll->InsertLast(101.236f);
    fdll->Display();
    cout<<"Number of node is "<<fdll->Count()<<endl;

    fdll->DeleteFirst();
    fdll->Display();
    cout<<"Number of node is "<<fdll->Count()<<endl;

    fdll->DeleteLast();
    fdll->InsertAtPos(72.236f,2);

    fdll->Display();
    cout<<"Number of node is "<<fdll->Count()<<endl;
    fdll->DeleteAtPos(2);
    fdll->Display();
    cout<<"Number of node is "<<fdll->Count()<<endl;

    cout<<"--------------------- generic Doubly  Link  List char  input ------ "<<endl;
    
    DoublyLL<char> *cdll = new DoublyLL<char>();
    cdll->InsertFirst('A');
    cdll->InsertFirst('B');
    cdll->InsertLast('C');
    cdll->InsertLast('D');
    
    cdll->Display();
    cout<<"Number of node is "<<cdll->Count()<<endl;

    cdll->DeleteFirst();
    cdll->Display();
    cout<<"Number of node is "<<cdll->Count()<<endl;

    cdll->DeleteLast();
    cdll->InsertAtPos('F',2);

    cdll->Display();
    cout<<"Number of node is "<<cdll->Count()<<endl;
    
    cdll->DeleteAtPos(2);
    cdll->Display();
    cout<<"Number of node is "<<cdll->Count()<<endl;
   
    cout<<"----------------- Queue Input as Integer---------------"<<endl;
    Queue<int>  *iqobj = new Queue<int>();
    iqobj->EnQueue(10);
    iqobj->EnQueue(20);
    iqobj->EnQueue(30);
    iqobj->EnQueue(40);
    iqobj->Display();
    cout<<"Number of elements in the Queue are : "<<iqobj->Count()<<"\n";
    cout<<"Removed element is : "<<iqobj->DeQueue()<<"\n";
    cout<<"Removed element is : "<<iqobj->DeQueue()<<"\n";
    iqobj->Display();
    cout<<"Number of elements in the Queue are : "<<iqobj->Count()<<"\n";
    iqobj->EnQueue(50);
    iqobj->Display();
    cout<<"Number of elements in the Queue are : "<<iqobj->Count()<<"\n";
    cout<<"----------------- Queue Input as float---------------"<<endl;
    Queue<float>  *fqobj = new Queue<float>();
    fqobj->EnQueue(10.09f);
    fqobj->EnQueue(200.9f);
    fqobj->EnQueue(30.9f);
    fqobj->EnQueue(40.9f);
    fqobj->Display();
    cout<<"Number of elements in the Queue are : "<<fqobj->Count()<<"\n";
    cout<<"Removed element is : "<<fqobj->DeQueue()<<"\n";
    cout<<"Removed element is : "<<fqobj->DeQueue()<<"\n";
    fqobj->Display();
    cout<<"Number of elements in the Queue are : "<<fqobj->Count()<<"\n";
    fqobj->EnQueue(50.9f);
    fqobj->Display();
    cout<<"Number of elements in the Queue are : "<<fqobj->Count()<<"\n";
    cout<<"----------------- Queue Input as double---------------"<<endl;
    Queue<double>  *dqobj = new Queue<double>();
    dqobj->EnQueue(1022.986);
    dqobj->EnQueue(200556.956);
    dqobj->EnQueue(30563.956);
    dqobj->EnQueue(404660.956);
    dqobj->Display();
    cout<<"Number of elements in the Queue are : "<<dqobj->Count()<<"\n";
    cout<<"Removed element is : "<<dqobj->DeQueue()<<"\n";
    cout<<"Removed element is : "<<dqobj->DeQueue()<<"\n";
    dqobj->Display();
    cout<<"Number of elements in the Queue are : "<<dqobj->Count()<<"\n";
    dqobj->EnQueue(50335.956);
    dqobj->Display();
    cout<<"Number of elements in the Queue are : "<<dqobj->Count()<<"\n";
    cout<<"----------------- Queue Input as char---------------"<<endl;
    Queue<char>  *cqobj = new Queue<char>();
    cqobj->EnQueue('A');
    cqobj->EnQueue('B');
    cqobj->EnQueue('C');
    cqobj->EnQueue('E');
    cqobj->Display();
    cout<<"Number of elements in the Queue are : "<<cqobj->Count()<<"\n";
    cout<<"Removed element is : "<<cqobj->DeQueue()<<"\n";
    cout<<"Removed element is : "<<cqobj->DeQueue()<<"\n";
    cqobj->Display();
    cout<<"Number of elements in the Queue are : "<<cqobj->Count()<<"\n";
    cqobj->EnQueue('F');
    cqobj->Display();
    cout<<"Number of elements in the Queue are : "<<cqobj->Count()<<"\n";
    cout<<"----------------- Satck as input Integer---------"<<endl;
    Stack<int> *istobj = new Stack<int>();
    istobj->Push(10);
    istobj->Push(20);
    istobj->Push(30);
    istobj->Push(40);
    istobj->Display();
    cout<<"Number of elements in the stack are : "<<istobj->Count()<<"\n";
    cout<<"Poped element is : "<<istobj->Pop()<<"\n";
    cout<<"Poped element is : "<<istobj->Pop()<<"\n";
    istobj->Display();
    cout<<"Number of elements in the stack are : "<<istobj->Count()<<"\n";
    istobj->Push(50);
    istobj->Display();
    cout<<"Number of elements in the stack are : "<<istobj->Count()<<"\n";
    cout<<"----------------- Satck as input float---------"<<endl;
    Stack<float> *fstobj = new Stack<float>();
    fstobj->Push(10.08f);
    fstobj->Push(20.08f);
    fstobj->Push(30.08f);
    fstobj->Push(40.08f);
    fstobj->Display();
    cout<<"Number of elements in the stack are : "<<fstobj->Count()<<"\n";
    cout<<"Poped element is : "<<fstobj->Pop()<<"\n";
    cout<<"Poped element is : "<<fstobj->Pop()<<"\n";
    istobj->Display();
    cout<<"Number of elements in the stack are : "<<fstobj->Count()<<"\n";
    fstobj->Push(50.08f);
    fstobj->Display();
    cout<<"Number of elements in the stack are : "<<fstobj->Count()<<"\n";
    cout<<"----------------- Satck as input double---------"<<endl;
    Stack<double> *dstobj = new Stack<double>();
    dstobj->Push(107644.08);
    dstobj->Push(20444.08);
    dstobj->Push(301168.08);
    dstobj->Push(41110.0555);
    dstobj->Display();
    cout<<"Number of elements in the stack are : "<<dstobj->Count()<<"\n";
    cout<<"Poped element is : "<<dstobj->Pop()<<"\n";
    cout<<"Poped element is : "<<dstobj->Pop()<<"\n";
    dstobj->Display();
    cout<<"Number of elements in the stack are : "<<dstobj->Count()<<"\n";
    dstobj->Push(5028855.08);
    dstobj->Display();
    cout<<"Number of elements in the stack are : "<<dstobj->Count()<<"\n";
    cout<<"----------------- Satck as input double---------"<<endl;
    Stack<char> *cstobj = new Stack<char>();
    cstobj->Push('A');
    cstobj->Push('B');
    cstobj->Push('C');
    cstobj->Push('D');
    cstobj->Display();
    cout<<"Number of elements in the stack are : "<<cstobj->Count()<<"\n";
    cout<<"Poped element is : "<<cstobj->Pop()<<"\n";
    cout<<"Poped element is : "<<cstobj->Pop()<<"\n";
    cstobj->Display();
    cout<<"Number of elements in the stack are : "<<cstobj->Count()<<"\n";
    cstobj->Push('E');
    cstobj->Display();
    cout<<"Number of elements in the stack are : "<<cstobj->Count()<<"\n";
 

    return 0;                               
}