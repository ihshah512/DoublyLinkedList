#ifndef DLL_H
#define DLL_H
#include <string>
#include <iostream>
using namespace std;
class DLL;
class Node{
    public:
    friend class DLL;
    Node(string data="", Node * next=nullptr, Node * previous=nullptr){
        m_data = data; m_next = next; m_previous = previous;
    }
    private:
    string m_data;
    Node * m_next;
    Node * m_previous;
};

class DLL{
    public:
    DLL();
    ~DLL();
    void insertAtHead(string toInsert);
    void addInBetween(string location, string toInsert);
    bool empty() const;
    void dump() const;
    private:
    Node * m_head;
    Node * m_tail;
};
#endif
