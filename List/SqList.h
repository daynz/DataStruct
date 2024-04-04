#pragma once

#define SQLISTINITCAPACITY 100

typedef int ElemType;

namespace wp
{

class SqList
{
public:
    SqList();
    SqList(int capacity);
    SqList(SqList& L);

    ~SqList();

    ElemType& at(int pos)const;
    ElemType& front()const;
    ElemType& back()const;
    ElemType& operator[](int i)const;
    ElemType& erase(int pos);
    ElemType& insert(int pos,const ElemType& value);
    ElemType& push_back(const ElemType& value);
    ElemType& pop_back();

    bool empty();
    void clear();
    bool sort();
    unsigned int size()const;
    bool resize(int capacity);
    unsigned int capacity()const;
    void merge(SqList& L);
    

private:
    ElemType* base;
    unsigned int m_size;
    unsigned int m_capacity;
};


}