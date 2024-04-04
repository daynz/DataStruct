#ifndef DULINKLIST_H
#define DULINKLIST_H

typedef int ElemType;

namespace wp
{

typedef struct{
    ElemType data;
    Node* prev;
    Node* next;
}Node;

class DuLinkList {
private:
    Node* head;
    int size;

public:
    DuLinkList();
    ~DuLinkList();

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
    void merge(DuLinkList& L);
};

} // namespace wp
#endif