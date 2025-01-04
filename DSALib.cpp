#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////
//
// Code of Singly Linear
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeSL
{
    T data;
    struct nodeSL *next;
};

template <class T>
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

        T Addition();
        int EvenCount();
        int OddCount();
        int Frequency(T iNo);
        bool Search(T iNo);
        int SearchFirstOccurnce(T iNo);
        int SearchLastOccurance(T iNo);
        void SumDigits();
        T FactorsAddition(T iNo);
        bool CheckPerfect(T iNo);
        void DisplayPerfect();
        void SumFactors();
        T MiddleElement();
};

template <class T>
SinglyLL<T>::SinglyLL()
{
    cout<<"Inside Constructor\n";
    First = NULL;
    iCount = 0;
}

template <class T>
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

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template <class T>
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

template <class T>
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

template <class T>
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

template <class T>
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

template <class T>
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

template <class T>
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
template<class T>
T SinglyLL<T>::Addition()
{
    int iSum = 0;
    struct nodeSL <T>* temp = NULL;
    temp = First;

    while(temp != NULL)
    {
        iSum = iSum + temp->data;
        temp = temp->next;
    }
    return iSum;
}

template<class T>
int SinglyLL<T>::EvenCount()
{
    int iCnt = 0;
    struct nodeSL <T>* temp = NULL;
    temp = First;
    while(temp != NULL)
    {
        if((temp->data) % 2 == 0)
        {
            iCnt++;
        }
        temp = temp->next;
    }
    return iCnt;
}

template<class T>
int SinglyLL<T>::OddCount()
{
    int iCnt = 0;
    struct nodeSL <T>* temp = NULL;
    temp = First;
    while(temp != NULL)
    {
        if((temp->data) % 2 != 0)
        {
            iCnt++;
        }
        temp = temp->next;
    }
    return iCnt;
}

template<class T>
int SinglyLL<T>::Frequency(T iNo)
{
    int iFreq = 0;
    struct nodeSL <T>* temp = NULL;
    temp = First;

    while(temp != NULL)
    {
        if(temp->data == iNo)
        {
            iFreq++;
        }
        temp = temp->next;
    }
    return iFreq;
}

template<class T>
bool SinglyLL<T>::Search(T iNo)
{
    bool bFlag = false;
    struct nodeSL <T>* temp = NULL;
    temp = First;
    while(temp != NULL)
    {
        if(temp->data == iNo)
        {
            bFlag = true;
            break;
        }
        temp = temp->next;
    }
    return bFlag;
}

template<class T>
int SinglyLL<T>::SearchFirstOccurnce(T iNo)
{
    int iCnt = 1;
    int iPose = -1;
    struct nodeSL <T>* temp = NULL;
    temp = First;

    while(temp != NULL)
    {
        if(temp->data == iNo)
        {
            iPose = iCnt;
            break;
        }
        iCnt++;
        temp = temp->next;
    }
    return iPose;
}

template<class T>
int SinglyLL<T>::SearchLastOccurance(T iNo)
{
    int iCnt = 1;
    int iPose = -1;
    struct nodeSL <T>* temp = NULL;
    temp = First;

    while(temp != NULL)
    {
        if(temp->data == iNo)
        {
            iPose = iCnt;
        }
        iCnt++;
        temp = temp->next;
    }
    return iPose;
}

template<class T>
void SinglyLL<T>::SumDigits()
{
    int iDigit = 0;
    int iNo = 0;
    int iSum = 0;
    struct nodeSL <T>* temp = NULL;
    temp = First;

    while(temp != NULL)
    {
        iNo = temp->data;

        while(iNo > 0)
        {
            iDigit = iNo % 10;
            iSum = iSum + iDigit;
            iNo = iNo / 10;
        }
        cout<<"Addition of digit is : "<<iSum<<endl;
        iSum = 0;
        temp = temp->next;
    }
}

template<class T>
T SinglyLL<T>::FactorsAddition(T iNo)
{
    int iSum = 0;
    int i = 0;

    for(i = 1; i <= iNo/2; i++)
    {
        if((iNo % i) == 0)
        {
            iSum = iSum + i;
        }
    }
    return iSum;
}

template<class T>
bool SinglyLL<T>::CheckPerfect(T iNo)
{
    int iSum = 0;
    int i = 0;

    for(i = 1; i <= iNo/2; i++)
    {
        if(iNo % i == 0)
        {
            iSum = iSum + i;
        }
    }
    if(iSum == iNo)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<class T>
void SinglyLL<T>::DisplayPerfect()
{
    struct nodeSL <T>* temp = NULL;
    temp = First;

    while(temp != NULL)
    {
        if(CheckPerfect(temp->data) == true)
        {
            cout<<"Perfect number from LL is : "<<temp->data<<endl;
        }
        temp = temp->next;
    }
}

template<class T>
void SinglyLL<T>::SumFactors()
{
    struct nodeSL <T>* temp = NULL;
    temp = First;

    while(temp != NULL)
    {
        cout<<"LL Sum of factors is : "<<FactorsAddition(temp->data)<<endl;
        temp = temp->next;
    }
}

template<class T>
T SinglyLL<T>::MiddleElement()
{
    struct nodeSL <T>* Teacher = First;
    struct nodeSL <T>* Student = First;

    while((Teacher != NULL) &&(Teacher->next != NULL))
    {
        Teacher = Teacher->next->next;
        Student = Student -> next;
    }
    return (Student->data);
}


/////////////////////////////////////////////////////////////
//
// Code of Doubly Circular
//
/////////////////////////////////////////////////////////////
template <class T>
struct nodeDC
{
    T data;
    struct nodeDC *next;
    struct nodeDC *prev;
};

template <class T>
class DoublyCL
{
    private:
        struct nodeDC<T> * First;
        struct nodeDC<T> * Last;
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

        T Addition();
        int EvenCount();
        int OddCount();
        int Frequency(T iNo);
        bool Search(T iNo);
        int SearchFirstOccurrence(T iNo);
        int SearchLastOccurrence(T iNo);
        void SumDigits();
        T FactorsAddition(T iNo);
        bool CheckPerfect(T iNo);
        void DisplayPerfect();
        void SumFactors();
        T MiddleElement();
};

template <class T>
DoublyCL<T>:: DoublyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
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

template <class T>
int DoublyCL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCL<T>::InsertFirst(T No)
{
    struct nodeDC<T> * newn = NULL;

    newn = new nodeDC<T>;

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

template <class T>
void DoublyCL<T>::InsertLast(T No)
{
    struct nodeDC<T> * newn = NULL;

    newn = new nodeDC<T>;

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

template <class T>
void DoublyCL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeDC<T> * temp = NULL;
    struct nodeDC<T> * newn = NULL;

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
        newn = new nodeDC<T>;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;

        for(i = 1; i < iPos -1; i++)
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

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if(First == NULL && Last == NULL)   
    {
        return;
    }
    else if(First == Last)   
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else 
    {
        First = First -> next;
        delete Last->next;
        First -> prev = Last;
        Last -> next = First;
    }
    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if(First == NULL && Last == NULL)   
    {
        return;
    }
    else if(First == Last)   
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else    
    {
        Last = Last -> prev;
        delete First -> prev;

        Last -> next = First;
        First -> prev = Last;
    }
    iCount--;    
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    struct nodeDC<T> * temp = NULL;

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
template <typename T>
T DoublyCL<T>::Addition()
{
    T sum = 0;
    if (First == NULL)
        return sum;

    nodeDC<T>* temp = First;
    do
    {
        sum += temp->data;
        temp = temp->next;
    } while (temp != Last->next);

    return sum;
}

template <typename T>
int DoublyCL<T>::EvenCount()
{
    int count = 0;
    if (First == NULL)
        return count;

    nodeDC<T>* temp = First;
    do
    {
        if (temp->data % 2 == 0)
            count++;
        temp = temp->next;
    } while (temp != Last->next);

    return count;
}

template <typename T>
int DoublyCL<T>::OddCount()
{
    int count = 0;
    if (First == NULL)
        return count;

    nodeDC<T>* temp = First;
    do
    {
        if (temp->data % 2 != 0)
            count++;
        temp = temp->next;
    } while (temp != Last->next);

    return count;
}

template <typename T>
int DoublyCL<T>::Frequency(T iNo)
{
    int count = 0;
    if (First == NULL)
        return count;

    nodeDC<T>* temp = First;
    do
    {
        if (temp->data == iNo)
            count++;
        temp = temp->next;
    } while (temp != Last->next);

    return count;
}

template <typename T>
bool DoublyCL<T>::Search(T iNo)
{
    if (First == NULL)
        return false;

    nodeDC<T>* temp = First;
    do
    {
        if (temp->data == iNo)
            return true;
        temp = temp->next;
    } while (temp != Last->next);

    return false;
}

template <typename T>
int DoublyCL<T>::SearchFirstOccurrence(T iNo)
{
    int index = 0;
    if (First == NULL)
        return -1;

    nodeDC<T>* temp = First;
    do
    {
        if (temp->data == iNo)
            return index;
        index++;
        temp = temp->next;
    } while (temp != Last->next);

    return -1;
}

template <typename T>
int DoublyCL<T>::SearchLastOccurrence(T iNo)
{
    int index = 0, lastIndex = -1;
    if (First == NULL)
        return -1;

    nodeDC<T>* temp = First;
    do
    {
        if (temp->data == iNo)
            lastIndex = index;
        index++;
        temp = temp->next;
    } while (temp != Last->next);

    return lastIndex;
}

template <typename T>
void DoublyCL<T>::SumDigits()
{
    if (First == NULL)
        return;

    nodeDC<T>* temp = First;
    do
    {
        int sum = 0;
        int num = static_cast<int>(temp->data);
        while (num != 0)
        {
            sum += num % 10;
            num /= 10;
        }
        cout << "Sum of digits of " << temp->data << " is " << sum << endl;
        temp = temp->next;
    } while (temp != Last->next);
}

template <typename T>
T DoublyCL<T>::FactorsAddition(T iNo)
{
    T sum = 0;
    for (T i = 1; i <= iNo / 2; i++)
    {
        if (iNo % i == 0)
            sum += i;
    }
    return sum;
}

template <typename T>
bool DoublyCL<T>::CheckPerfect(T iNo)
{
    return (FactorsAddition(iNo) == iNo);
}

template <typename T>
void DoublyCL<T>::DisplayPerfect()
{
    if (First == NULL)
        return;

    nodeDC<T>* temp = First;
    do
    {
        if (CheckPerfect(temp->data))
            cout << temp->data << " is a perfect number." << endl;
        temp = temp->next;
    } while (temp != Last->next);
}

template <typename T>
void DoublyCL<T>::SumFactors()
{
    if (First == NULL)
        return;

    nodeDC<T>* temp = First;
    do
    {
        cout << "Sum of factors of " << temp->data << " is " << FactorsAddition(temp->data) << endl;
        temp = temp->next;
    } while (temp != Last->next);
}

template <typename T>
T DoublyCL<T>::MiddleElement()
{
    if (First == NULL)
        return T(); 

    nodeDC<T>* slow = First;
    nodeDC<T>* fast = First;

    while (fast != Last && fast->next != Last->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

/////////////////////////////////////////////////////////////
//
// Code of Doubly Linear
//
/////////////////////////////////////////////////////////////

template<class T>
struct nodeDL
{
    T data;
    struct nodeDL *next;
    struct nodeDL *prev;
};

template<class T>
class DoublyLL
{
    private:
        struct nodeDL<T> * First;
        int iCount;

    public:
        DoublyLL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);        
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

        T Addition();
        int EvenCount();
        int OddCount();
        int Frequency(T iNo);
        bool Search(T iNo);
        int SearchFirstOccurrence(T iNo);
        int SearchLastOccurrence(T iNo);
        void SumDigits();
        T FactorsAddition(T iNo);
        bool CheckPerfect(T iNo);
        void DisplayPerfect();
        void SumFactors();
        T MiddleElement();
};

template<class T>
DoublyLL<T>::DoublyLL()
{
    First = NULL;
    iCount = 0;
}

template<class T>
void DoublyLL<T>::Display()
{
    struct nodeDL <T> * temp = First;

    cout<<"NULL<=>";
    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|"<<"<=>";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

template<class T>
int DoublyLL<T>::Count()
{
    return iCount;
}

template<class T>
void DoublyLL<T>::InsertFirst(T No)
{
   struct nodeDL<T> * newn = NULL;
    newn = new nodeDL<T>;

    newn -> data = No;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First ->  prev = newn;

        First = newn;
    }
    iCount++;
}

template<class T>
void DoublyLL<T>::InsertLast(T No)
{
    struct nodeDL <T>* newn = NULL;
    newn = new nodeDL<T>;
    struct nodeDL <T>* temp = NULL;

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
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}

template<class T>
void DoublyLL<T>::InsertAtPos(T No, int iPos)
{
    int i = 0;
    struct nodeDL<T> * temp = NULL;
    struct nodeDL <T>* newn = NULL;
    if((iPos < 1) || (iPos > iCount + 1))
    {
        cout<<"Invalid position"<<endl;
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
        temp = First;
        newn = new nodeDL<T>;
        newn -> data = No;
        newn -> next = NULL;
        newn -> prev = NULL;

        for (i = 1; i < iPos - 1; i++)
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
void DoublyLL<T>::DeleteFirst()
{
    if(First == NULL)
    {
        cout<<"Unable to delete the node as LL is empty\n";
        return;
    }
    if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct nodeDL<T> * temp = First;
        First = First->next;
        First->prev = NULL;
        delete temp;
    }
    iCount--;
}

template<class T>
void DoublyLL<T>::DeleteLast()
{
    struct nodeDL <T>* temp = NULL;
    if(First == NULL)
    {
        cout<<"Unable to delete the node as LL is empty\n";
        return;
    }
    if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete(temp->next);
        temp->next = NULL;
    }
    iCount--;
}

template<class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
    struct nodeDL <T>* temp = NULL;

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position"<<endl;
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
        for (i = 1; i < iPos - 1; i++)
        {
            temp = temp -> next;
        }
        temp->next = temp->next->next;
        delete(temp->next->prev);
        temp->next->prev = temp;

        iCount--;
    }

}
template <typename T>
T DoublyLL<T>::Addition()
{
    T iSum = 0;
    nodeDL<T>* temp = First;

    while (temp != NULL)
    {
        iSum += temp->data;
        temp = temp->next;
    }
    return iSum;
}

template <typename T>
int DoublyLL<T>::EvenCount()
{
    int iCount = 0;
    nodeDL<T>* temp = First;

    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
        {
            iCount++;
        }
        temp = temp->next;
    }
    return iCount;
}

template <typename T>
int DoublyLL<T>::OddCount()
{
    int iCount = 0;
    nodeDL<T>* temp = First;

    while (temp != NULL)
    {
        if (temp->data % 2 != 0)
        {
            iCount++;
        }
        temp = temp->next;
    }
    return iCount;
}

template <typename T>
int DoublyLL<T>::Frequency(T iNo)
{
    int iFreq = 0;
    nodeDL<T>* temp = First;

    while (temp != NULL)
    {
        if (temp->data == iNo)
        {
            iFreq++;
        }
        temp = temp->next;
    }
    return iFreq;
}

template <typename T>
bool DoublyLL<T>::Search(T iNo)
{
    nodeDL<T>* temp = First;
    while (temp != NULL)
    {
        if (temp->data == iNo)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

template <typename T>
int DoublyLL<T>::SearchFirstOccurrence(T iNo)
{
    int iPos = 1;
    nodeDL<T>* temp = First;

    while (temp != NULL)
    {
        if (temp->data == iNo)
        {
            return iPos;
        }
        iPos++;
        temp = temp->next;
    }
    return -1; // Not found
}

template <typename T>
int DoublyLL<T>::SearchLastOccurrence(T iNo)
{
    int iPos = 1, iLastPos = -1;
    nodeDL<T>* temp = First;

    while (temp != NULL)
    {
        if (temp->data == iNo)
        {
            iLastPos = iPos;
        }
        iPos++;
        temp = temp->next;
    }
    return iLastPos;
}

template <typename T>
void DoublyLL<T>::SumDigits()
{
    nodeDL<T>* temp = First;

    while (temp != NULL)
    {
        int iSum = 0, iNo = temp->data;
        while (iNo != 0)
        {
            iSum += iNo % 10;
            iNo /= 10;
        }
        cout << "Sum of digits of " << temp->data << " is: " << iSum << endl;
        temp = temp->next;
    }
}

template <typename T>
T DoublyLL<T>::FactorsAddition(T iNo)
{
    T iSum = 0;
    for (T i = 1; i <= iNo / 2; i++)
    {
        if (iNo % i == 0)
        {
            iSum += i;
        }
    }
    return iSum;
}

template <typename T>
bool DoublyLL<T>::CheckPerfect(T iNo)
{
    return (FactorsAddition(iNo) == iNo);
}

template <typename T>
void DoublyLL<T>::DisplayPerfect()
{
    nodeDL<T>* temp = First;
    while (temp != NULL)
    {
        if (CheckPerfect(temp->data))
        {
            cout << "Perfect number: " << temp->data << endl;
        }
        temp = temp->next;
    }
}

template <typename T>
void DoublyLL<T>::SumFactors()
{
    nodeDL<T>* temp = First;

    while (temp != NULL)
    {
        cout << "Sum of factors of " << temp->data << " is: " << FactorsAddition(temp->data) << endl;
        temp = temp->next;
    }
}

template <typename T>
T DoublyLL<T>::MiddleElement()
{
    nodeDL<T>* slow = First;
    nodeDL<T>* fast = First;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (slow != NULL)
    {
        return slow->data;
    }

    return -1; 
}

/////////////////////////////////////////////////////////////
//
// Code of Singly Circular
//
/////////////////////////////////////////////////////////////

template<class T>
struct nodeSC
{
    T data;
    struct nodeSC *next;
};


template<class T>
class SinglyCL 
{
    private:
        struct nodeSC <T> * First;
        struct nodeSC <T> *Last;
        int iCount;
    public:
        SinglyCL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int Pos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int Pos);

        T Addition();
        int EvenCount();
        int OddCount();
        int Frequency(T iNo);
        bool Search(T iNo);
        int SearchFirstOccurrence(T iNo);
        int SearchLastOccurrence(T iNo);
        void SumDigits();
        T FactorsAddition(T iNo);
        bool CheckPerfect(T iNo);
        void DisplayPerfect();
        void SumFactors();
        T MiddleElement();
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
    PNODE temp = First;
    if (First == NULL && Last == NULL) 
    {
        cout << "LL is empty\n";
        return;
    }
    do 
    {
        cout << "|" << temp->data << "|->";
        temp = temp->next;
    } while (temp != Last->next);
    cout << endl;
}

template<class T>
int SinglyCL<T>::Count() 
{
    return iCount;
}

template<class T>
void SinglyCL<T>::InsertFirst(T No) 
{
    struct nodeSC <T>* newn = NULL;
    newn = new nodeSC<T>;
    newn->data = No;
    newn->next = NULL;

    if (First == NULL && Last == NULL) 
    {
        First = newn;
        Last = newn;
    } else 
    {
        newn->next = First;
        First = newn;
    }
    Last->next = First;
    iCount++;
}

template<class T>
void SinglyCL<T>::InsertLast(T No) 
{
    struct nodeSC <T>* newn = NULL;
    newn = new nodeSC<T>;
    newn->data = No;
    newn->next = NULL;

    if (First == NULL && Last == NULL)
    {
        First = newn;
        Last = newn;
    } else 
    {
        Last->next = newn;
        Last = newn;
    }
    Last->next = First;
    iCount++;
}

template<class T>
void SinglyCL<T>::InsertAtPos(T No, int Pos) 
{
    struct nodeSC <T>* newn = NULL;
    if (Pos < 1 || Pos > iCount + 1) {
        cout << "Invalid position\n";
        return;
    }
    if (Pos == 1) 
    {
        InsertFirst(No);
    } else if (Pos == iCount + 1) 
    {
        InsertLast(No);
    } else 
    {
        newn = new nodeSC<T>;
        newn->data = No;
        newn->next = NULL;

        struct nodeSC <T> * temp = First;
        for (int i = 1; i < Pos - 1; i++) {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        iCount++;
    }
}

template<class T>
void SinglyCL<T>::DeleteFirst() 
{
    struct nodeSC <T>* temp = NULL;
    if (First == NULL && Last == NULL) 
    {
        return;
    } else if (First == Last) 
    {
        delete First;
        First = NULL;
        Last = NULL;
    } else 
    {
        temp = First;
        First = First->next;
        delete temp;
        Last->next = First;
    }
    iCount--;
}

template<class T>
void SinglyCL<T>::DeleteLast() 
{
    struct nodeSC <T> * temp = NULL;
    if (First == NULL && Last == NULL) 
    {
        return;
    } else if (First == Last) 
    {
        delete First;
        First = NULL;
        Last = NULL;
    } else 
    {
        temp = First;
        while (temp->next != Last) 
        {
            temp = temp->next;
        }
        delete Last;
        Last = temp;
        Last->next = First;
    }
    iCount--;
}

template<class T>
void SinglyCL<T>::DeleteAtPos(int Pos) 
{
    struct nodeSC <T>* temp2 = NULL;
    struct nodeSC <T>* temp1 = NULL;
    if (Pos < 1 || Pos > iCount) {
        cout << "Invalid position\n";
        return;
    }
    if (Pos == 1) 
    {
        DeleteFirst();
    } else if (Pos == iCount) 
    {
        DeleteLast();
    } else 
    {
        temp1 = First;
        struct nodeSC <T>* temp1 = First;
        for (int i = 1; i < Pos - 1; i++) 
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
        iCount--;
    }
}
template <typename T>
T SinglyCL<T>::Addition()
{
    T sum = 0;
    if (First == NULL)
        return sum;

    nodeSC<T>* temp = First;
    do
    {
        sum += temp->data;
        temp = temp->next;
    } while (temp != Last->next);

    return sum;
}

template <typename T>
int SinglyCL<T>::EvenCount()
{
    int count = 0;
    if (First == NULL)
        return count;

    nodeSC<T>* temp = First;
    do
    {
        if (temp->data % 2 == 0)
            count++;
        temp = temp->next;
    } while (temp != Last->next);

    return count;
}

template <typename T>
int SinglyCL<T>::OddCount()
{
    int count = 0;
    if (First == NULL)
        return count;

    nodeSC<T>* temp = First;
    do
    {
        if (temp->data % 2 != 0)
            count++;
        temp = temp->next;
    } while (temp != Last->next);

    return count;
}

template <typename T>
int SinglyCL<T>::Frequency(T iNo)
{
    int count = 0;
    if (First == NULL)
        return count;

    nodeSC<T>* temp = First;
    do
    {
        if (temp->data == iNo)
            count++;
        temp = temp->next;
    } while (temp != Last->next);

    return count;
}

template <typename T>
bool SinglyCL<T>::Search(T iNo)
{
    if (First == NULL)
        return false;

    nodeSC<T>* temp = First;
    do
    {
        if (temp->data == iNo)
            return true;
        temp = temp->next;
    } while (temp != Last->next);

    return false;
}

template <typename T>
int SinglyCL<T>::SearchFirstOccurrence(T iNo)
{
    int index = 0;
    if (First == NULL)
        return -1;

    nodeSC<T>* temp = First;
    do
    {
        if (temp->data == iNo)
            return index;
        index++;
        temp = temp->next;
    } while (temp != Last->next);

    return -1;
}

template <typename T>
int SinglyCL<T>::SearchLastOccurrence(T iNo)
{
    int index = 0, lastIndex = -1;
    if (First == NULL)
        return -1;

    nodeSC<T>* temp = First;
    do
    {
        if (temp->data == iNo)
            lastIndex = index;
        index++;
        temp = temp->next;
    } while (temp != Last->next);

    return lastIndex;
}

template <typename T>
void SinglyCL<T>::SumDigits()
{
    if (First == NULL)
        return;

    nodeSC<T>* temp = First;
    do
    {
        int sum = 0;
        int num = static_cast<int>(temp->data);
        while (num != 0)
        {
            sum += num % 10;
            num /= 10;
        }
        cout << "Sum of digits of " << temp->data << " is " << sum << endl;
        temp = temp->next;
    } while (temp != Last->next);
}

template <typename T>
T SinglyCL<T>::FactorsAddition(T iNo)
{
    T sum = 0;
    for (T i = 1; i <= iNo / 2; i++)
    {
        if (iNo % i == 0)
            sum += i;
    }
    return sum;
}

template <typename T>
bool SinglyCL<T>::CheckPerfect(T iNo)
{
    return (FactorsAddition(iNo) == iNo);
}

template <typename T>
void SinglyCL<T>::DisplayPerfect()
{
    if (First == NULL)
        return;

    nodeSC<T>* temp = First;
    do
    {
        if (CheckPerfect(temp->data))
            cout << temp->data << " is a perfect number." << endl;
        temp = temp->next;
    } while (temp != Last->next);
}

template <typename T>
void SinglyCL<T>::SumFactors()
{
    if (First == NULL)
        return;

    nodeSC<T>* temp = First;
    do
    {
        cout << "Sum of factors of " << temp->data << " is " << FactorsAddition(temp->data) << endl;
        temp = temp->next;
    } while (temp != Last->next);
}

template <typename T>
T SinglyCL<T>::MiddleElement()
{
    if (First == NULL)
        return T(); 

    nodeSC<T>* slow = First;
    nodeSC<T>* fast = First;

    while (fast != Last && fast->next != Last->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

/////////////////////////////////////////////////////////////
//
// Code of Stack
//
/////////////////////////////////////////////////////////////

template<class T>
struct nodeS
{
    T data;
    struct nodeS *next;
};

template<class T>
class Stack
{
    private:
        struct nodeS <T>* First;
        int iCount;

    public:
        Stack();
        void Display();
        int Count();
        void Push(T No);  
        int Pop();   
};

template<class T>
Stack <T>:: Stack()
{
    First = NULL;
    iCount = 0;
}

template<class T>
void Stack <T>::Display()
{
    cout<<"Elements of stack are : \n";
    struct nodeS <T>* temp = NULL;
    temp = First;

    while(temp != NULL)
    {
        cout<<temp->data<<"\n";
        temp = temp -> next;
    }
    cout<<"\n";
}

template<class T>
int Stack <T>::Count()
{
    return iCount;
}

template<class T>
void Stack <T>::Push(T No)
{
    struct nodeS <T>* newn = NULL;

    newn = new nodeS<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
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
int Stack <T>::Pop()
{
    T iValue = 0;
    struct nodeS <T>* temp = NULL;

    if(First == NULL)
    {
        cout<<"Unable to pop the element as stack is empty\n";
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


/////////////////////////////////////////////////////////////
//
// Code of Queue
//
/////////////////////////////////////////////////////////////

template<class T>
struct nodeQ
{
    T data;
    struct nodeQ *next;
};


template<class T>
class Queue
{
    private:
        struct nodeQ<T> *  First;
        int iCount;

    public:
        Queue();
        void Display();
        int Count();
        void EnQueue(T No);  // InsertLast()
        int DeQueue();   // DeleteFirst()
};

template<class T>
Queue <T>:: Queue()
{
    First = NULL;
    iCount = 0;
}

template<class T>
void Queue <T>::Display()
{
    cout<<"Elements of Queue are : \n";
    struct nodeQ <T>*  temp = First;

    while(temp != NULL)
    {
        cout<<temp->data<<"\t";
        temp = temp -> next;
    }
    cout<<"\n";
}

template<class T>
int Queue <T>::Count()
{
    return iCount;
}

template<class T>
void Queue <T>::EnQueue(T No)
{
    struct nodeQ <T>*  newn = NULL;
    struct nodeQ <T>*  temp = NULL;

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
int Queue <T>::DeQueue()
{
    T iValue = 0;
    struct nodeQ <T>*  temp = NULL;

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

/////////////////////////////////////////////////////////////
//
// Code of Searching Sorting
//
/////////////////////////////////////////////////////////////

template <class T>
class ArrayX
{
    public:
        T *Arr;
        int iSize;

        ArrayX(int Value);
        ~ArrayX();

        void Accept();
        void Display();
        
        bool LinearSearch(T Value);
        bool BiDirectionalSearch(T Value);
        bool BinarySearch(T Value);

        void BubbleSort();
        void BubbleSortEfficient();

        void SelectionSort();

        void InsertionSort();
};

template <class T>
ArrayX<T>::ArrayX(int Value)
{
    this->iSize = Value;
    this->Arr = new T[iSize];
}

template <class T>
ArrayX<T>::~ArrayX()
{
    delete []Arr;
}

template <class T>
void ArrayX<T>::Accept()
{
    int i = 0;

    cout<<"Enter the elements : \n";
    for(i = 0; i < iSize; i++)
    {
        cin>>Arr[i];
    }
}

template <class T>
void ArrayX<T>::Display()
{
    int i = 0;

    for(i = 0; i < iSize; i++)
    {
        cout<<Arr[i]<<"\t";
    }
}

template <class T>
bool ArrayX<T>::LinearSearch(T Value)
{
    bool flag = false;
    int i = 0;

    for(i = 0; i < iSize; i++)
    {
        if(Arr[i] == Value)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

template <class T>
bool ArrayX<T>::BiDirectionalSearch(T Value)
{
    int iStart = 0;
    int iEnd = iSize-1;
    bool flag = false;

    while(iStart <= iEnd)
    {
        if(Arr[iStart] == Value || Arr[iEnd] == Value)
        {
                flag = true;
                break;
        }
        iStart++;
        iEnd--;
    }
    return flag;
}

template <class T>
bool ArrayX<T>::BinarySearch(T Value)
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool flag = false;

    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if((Arr[iMid] == Value) || (Arr[iStart] == Value) || (Arr[iEnd] == Value))
        {
            flag = true;
            break;
        }
        else if(Value < Arr[iMid])
        {
            iStart = iMid + 1;
        }
        else if(Value > Arr[iMid])
        {
            iEnd = iMid -1;
        }
    }

    return flag;
}

template <class T>
void ArrayX<T>::BubbleSort()
{
    T temp;
    int i = 0, j = 0;

    //     1        2      3  
    for(i = 0; i < iSize -1; i++)  // Outer
    {   //    1         2         3  
        for(j = 0; j< iSize - 1 - i; j++)   // Inner
        {
            if(Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
            }
        }
        cout<<"\nArray after pass : "<<i+1<<"\n";
        Display();
    }
}   

template <class T>
void ArrayX<T>::BubbleSortEfficient()
{
    T temp;
    int i = 0, j = 0;
    bool flag = true;

    //     1        2      3  
    for(i = 0; (i < iSize -1) && (flag == true) ; i++)  // Outer
    {
        flag = false;
           //    1         2         3  
        for(j = 0; j< iSize - 1 - i; j++)   // Inner
        {
            if(Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
                flag = true;
            }
        }
    
        cout<<"\nArray after pass : "<<i+1<<"\n";
        Display();
    }
}  

template <class T>
void ArrayX<T>::SelectionSort()
{
    int i = 0, j = 0, min_index = 0;
    T temp;

    for(i = 0; i < iSize -1; i++)
    {
        min_index = i;

        for(j = i + 1; j < iSize; j++)
        {
            if(Arr[j] < Arr[min_index])
            {
                min_index = j;
            }
        }
        temp = Arr[i];
        Arr[i] = Arr[min_index];
        Arr[min_index] = temp;
    }
}  

template <class T>
void ArrayX<T>::InsertionSort()
{
    int i = 0, j = 0;
    T selected;

    for(i =1 ; i < iSize; i++)
    {
        for(j = i -1, selected = Arr[i]; (j >= 0) && (Arr[j] > selected); j--)
        {
            Arr[j + 1] = Arr[j];
        }
        Arr[j+1] = selected;
    }
}  

/////////////////////////////////////////////////////////////
//
// Binary Search tree
//
/////////////////////////////////////////////////////////////
template <typename T>
struct node
{
    T data;
    struct node *rchild;
    struct node *lchild;
};

template <typename T>
class BSTX
{
public:
    struct node<T>* Root;

public:
    BSTX();
    void Insert(T iNo);
    void Inorder();
    void Inorder(struct node<T>* Head);
    void Preorder();
    void Preorder(struct node<T>* Head);
    void Postorder();
    void Postorder(struct node<T>* Head);
    bool Search(T iNo);
    int CountLeaf();
    int CountLeaf(struct node<T>* Head);
    int CountParent();
    int CountParent(struct node<T>* Head);
    int CountAll();
    int CountAll(struct node<T>* Head);
};

template <typename T>
BSTX<T>::BSTX()
{
    Root = NULL;
}

template <typename T>
void BSTX<T>::Insert(T iNo)
{
    struct node<T>* newn = new struct node<T>;
    newn->data = iNo;
    newn->rchild = NULL;
    newn->lchild = NULL;

    if (Root == NULL)
    {
        Root = newn;
    }
    else
    {
        struct node<T>* temp = Root;

        while (true)
        {
            if (temp->data == iNo)
            {
                cout << "Unable to insert Node as element is already present\n";
                delete newn;
                return;
            }
            else if (iNo > temp->data)
            {
                if (temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;
            }
            else
            {
                if (temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;
            }
        }
    }
}

template <typename T>
void BSTX<T>::Inorder()
{
    Inorder(Root);
}

template <typename T>
void BSTX<T>::Inorder(struct node<T>* Head)
{
    if (Head != NULL)
    {
        Inorder(Head->lchild);
        cout << Head->data << " ";
        Inorder(Head->rchild);
    }
}

template <typename T>
void BSTX<T>::Preorder()
{
    Preorder(Root);
}

template <typename T>
void BSTX<T>::Preorder(struct node<T>* Head)
{
    if (Head != NULL)
    {
        cout << Head->data << " ";
        Preorder(Head->lchild);
        Preorder(Head->rchild);
    }
}

template <typename T>
void BSTX<T>::Postorder()
{
    Postorder(Root);
}

template <typename T>
void BSTX<T>::Postorder(struct node<T>* Head)
{
    if (Head != NULL)
    {
        Postorder(Head->lchild);
        Postorder(Head->rchild);
        cout << Head->data << " ";
    }
}

template <typename T>
bool BSTX<T>::Search(T iNo)
{
    struct node<T>* temp = Root;

    while (temp != NULL)
    {
        if (temp->data == iNo)
        {
            return true;
        }
        else if (iNo > temp->data)
        {
            temp = temp->rchild;
        }
        else
        {
            temp = temp->lchild;
        }
    }
    return false;
}

template <typename T>
int BSTX<T>::CountLeaf()
{
    return CountLeaf(Root);
}

template <typename T>
int BSTX<T>::CountLeaf(struct node<T>* Head)
{
    if (Head == NULL)
    {
        return 0;
    }

    if (Head->lchild == NULL && Head->rchild == NULL)
    {
        return 1;
    }

    return CountLeaf(Head->lchild) + CountLeaf(Head->rchild);
}

template <typename T>
int BSTX<T>::CountParent()
{
    return CountParent(Root);
}

template <typename T>
int BSTX<T>::CountParent(struct node<T>* Head)
{
    if (Head == NULL)
    {
        return 0;
    }

    int count = 0;
    if (Head->lchild != NULL || Head->rchild != NULL)
    {
        count = 1;
    }

    return count + CountParent(Head->lchild) + CountParent(Head->rchild);
}

template <typename T>
int BSTX<T>::CountAll()
{
    return CountAll(Root);
}

template <typename T>
int BSTX<T>::CountAll(struct node<T>* Head)
{
    if (Head == NULL)
    {
        return 0;
    }

    return 1 + CountAll(Head->lchild) + CountAll(Head->rchild);
}

////////////////////////////////////////////////////////////////////////////
//
//  Matrix Code
//
////////////////////////////////////////////////////////////////////////////
template <typename T>
class Matrix
{
private:
    int iRow, iCol;
    T** Arr;

public:
    Matrix(int A, int B);
    ~Matrix();
    void Accept();
    void Display();
    T Summation();
    T Maximum();
    T Minimum();
    void RowSum();
    T DiagonalSum();
    void SumEvenOdd();
    void UpdateMatrix();
    void UpdateMatrixEven();
    void AdditionDigits();
    void SwapRow();
};

template <typename T>
Matrix<T>::Matrix(int A, int B)
{
    iRow = A;
    iCol = B;
    Arr = new T*[iRow];
    for (int i = 0; i < iRow; i++)
    {
        Arr[i] = new T[iCol];
    }
}

template <typename T>
Matrix<T>::~Matrix()
{
    for (int i = 0; i < iRow; i++)
    {
        delete[] Arr[i];
    }
    delete[] Arr;
    cout << "Destructor: Releasing the memory of the matrix object" << endl;
}

template <typename T>
void Matrix<T>::Accept()
{
    cout << "Please enter the data: ";
    for (int i = 0; i < iRow; ++i)
    {
        for (int j = 0; j < iCol; ++j)
        {
            cin >> Arr[i][j];
        }
    }
}

template <typename T>
void Matrix<T>::Display()
{
    cout << "Elements of the matrix: " << endl;
    for (int i = 0; i < iRow; ++i)
    {
        for (int j = 0; j < iCol; ++j)
        {
            cout << Arr[i][j] << "\t";
        }
        cout << endl;
    }
}

template <typename T>
T Matrix<T>::Summation()
{
    T iSum = 0;
    for (int i = 0; i < iRow; ++i)
    {
        for (int j = 0; j < iCol; ++j)
        {
            iSum += Arr[i][j];
        }
    }
    return iSum;
}

template <typename T>
T Matrix<T>::Maximum()
{
    T iMax = Arr[0][0];
    for (int i = 0; i < iRow; ++i)
    {
        for (int j = 0; j < iCol; ++j)
        {
            if (iMax < Arr[i][j])
            {
                iMax = Arr[i][j];
            }
        }
    }
    return iMax;
}

template <typename T>
T Matrix<T>::Minimum()
{
    T iMin = Arr[0][0];
    for (int i = 0; i < iRow; ++i)
    {
        for (int j = 0; j < iCol; ++j)
        {
            if (iMin > Arr[i][j])
            {
                iMin = Arr[i][j];
            }
        }
    }
    return iMin;
}

template <typename T>
void Matrix<T>::RowSum()
{
    for (int i = 0; i < iRow; ++i)
    {
        T iSum = 0;
        for (int j = 0; j < iCol; ++j)
        {
            iSum += Arr[i][j];
        }
        cout << "Summation of all elements from row no: " << i << " is: " << iSum << endl;
    }
}

template <typename T>
T Matrix<T>::DiagonalSum()
{
    if (iRow != iCol)
    {
        cout << "Unable to perform addition of diagonal elements because the matrix is not square." << endl;
        return -1;
    }

    T iSum = 0;
    for (int i = 0; i < iRow; ++i)
    {
        iSum += Arr[i][i];
    }
    return iSum;
}

template <typename T>
void Matrix<T>::SumEvenOdd()
{
    T iSumEven = 0, iSumOdd = 0;
    for (int i = 0; i < iRow; ++i)
    {
        for (int j = 0; j < iCol; ++j)
        {
            if ((Arr[i][j] % 2) == 0)
            {
                iSumEven += Arr[i][j];
            }
            else
            {
                iSumOdd += Arr[i][j];
            }
        }
    }
    cout << "Addition of even elements: " << iSumEven << endl;
    cout << "Addition of odd elements: " << iSumOdd << endl;
}

template <typename T>
void Matrix<T>::UpdateMatrix()
{
    for (int i = 0; i < iRow; ++i)
    {
        for (int j = 0; j < iCol; ++j)
        {
            if (Arr[i][j] % 5 == 0)
            {
                Arr[i][j] = 0;
            }
        }
    }
}

template <typename T>
void Matrix<T>::UpdateMatrixEven()
{
    for (int i = 0; i < iRow; ++i)
    {
        for (int j = 0; j < iCol; ++j)
        {
            if (Arr[i][j] % 2 == 1)
            {
                Arr[i][j]++;
            }
        }
    }
}

template <typename T>
void Matrix<T>::AdditionDigits()
{
    for (int i = 0; i < iRow; ++i)
    {
        for (int j = 0; j < iCol; ++j)
        {
            int iNo = Arr[i][j];
            int iSum = 0;

            while (iNo != 0)
            {
                iSum += iNo % 10;
                iNo /= 10;
            }
            Arr[i][j] = iSum;
        }
    }
}

template <typename T>
void Matrix<T>::SwapRow()
{
    for (int i = 0; i < iRow - 1; i += 2)
    {
        for (int j = 0; j < iCol; ++j)
        {
            T temp = Arr[i][j];
            Arr[i][j] = Arr[i + 1][j];
            Arr[i + 1][j] = temp;
        }
    }
}

int main()
{
    
    return 0;
}