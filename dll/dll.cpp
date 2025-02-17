#include "dll.h"
DLL::DLL()
{
    m_head = nullptr;
    m_tail = nullptr;
}
DLL::~DLL()
{
    Node *temp = nullptr;
    while (!empty())
    {
        temp = m_head;
        m_head = m_head->m_next;
        delete temp;
    }
    m_head = nullptr;
    m_tail = nullptr;
}
void DLL::insertAtHead(string toInsert)
{
    // to be implemented
    /*
        1.First we need to check rather DLL is empty or not
            1.1 If Epmpt then insert node right away
        2. If not empty
            2.1 Insert node before head node
        3. Check if the DLL is circular or non-cirular
    */
    Node *nodoInsertAtHead = new Node;
    nodoInsertAtHead->m_data = toInsert;
    // Case where DLL is empty
    if (empty())
    {
        m_head = nodoInsertAtHead;
        m_tail = nodoInsertAtHead;
    }
    // Inserting of Node at the head of the DLL
    nodoInsertAtHead->m_next = m_head;
    nodoInsertAtHead->m_previous = nullptr;
    m_head->m_previous = nodoInsertAtHead; // question why not we said nodeInsert>-m_next because thats what it is??
    m_head = nodoInsertAtHead;             // update the head location with new node

    // ADDRESS CIRcular DLL case

    /* why this code is throwing seg fault
    if (m_tail->m_next == m_head)
     { // in case of multiple nodes we need to check
       // m_tail->m_next == m_head otherwise if there is only on node we can
       // just check if (m_tail == m_head)
         m_tail->m_next = m_head;
         m_head->m_previous = m_tail;
     }
    */
}
void DLL::addInBetween(string location, string toInsert)
{
    /*
        1. Check if the DDL is empty
        2. Check the location we are trying of access does exist
        3. it has one node and it is location
        4. list has one node and it is not location
        5. lsit has multiple nodes and first one is the locaiton
        6. List has multiple nodes and location is in the midlle
    */

    if (empty())
    {
        throw runtime_error("The List is empty cant access the location");
        //return; //there is no need of this because we dont have return value and program will not getinto this
    }
    Node * temp = m_head;
    while(temp != nullptr && temp->m_data != location){
        temp = temp->m_next;
    }
    if(temp == nullptr){
        throw runtime_error("The position we are looking for does not exist");
    }

    Node * nodeToAdd = new Node(toInsert);
    nodeToAdd->m_data = toInsert;
    nodeToAdd->m_next=temp->m_next;
    temp = nodeToAdd->m_previous;
    nodeToAdd=temp;

}

bool DLL::empty() const
{
    return (m_head == nullptr);
}

void DLL::dump() const
{
    if (!empty())
    {
        Node *temp = m_head;
        while (temp != nullptr)
        {
            cout << temp->m_data << " ";
            temp = temp->m_next;
        }
    }
}