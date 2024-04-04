#ifndef LINKLIST_H
#define LINKLIST_H

typedef int ElemType;

namespace wp
{

// Define a Node structure
typedef struct {
    int data;
    Node* next;
}Node;

// Define your LinkList class
class LinkList {
private:
    Node* head;
    int m_size;

public:
    // Constructor
    LinkList();

    // Destructor
    ~LinkList();

    ElemType front();
    ElemType back();
    ElemType erase(int pos);
    ElemType insert(int pos,ElemType value);
    ElemType push_back(ElemType value);
    ElemType push_front(ElemType value);
    void pop_back();
    void pop_front();

    bool empty();
    void clear();
    int size();
    void merge(LinkList& L);
};


} // namespace wp
#endif