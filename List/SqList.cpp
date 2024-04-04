#include"SqList.h"
#include<malloc.h>
#include<iostream>

wp::SqList::SqList()
{
    this->m_capacity = SQLISTINITCAPACITY;
    this->m_size = 0;

    this->base = (ElemType*)malloc(m_capacity * sizeof(ElemType));
    if (!this->base)
    {
        exit(OVERFLOW);
    }
}

wp::SqList::SqList(int capacity)
{
    this->m_capacity = capacity;
    this->m_size = 0;

    this->base = (ElemType*)malloc(m_capacity * sizeof(ElemType));
    if (!this->base)
    {
        exit(OVERFLOW);
    }
}

wp::SqList::SqList(SqList& L)
{
    this->m_capacity = L.capacity();
    this->m_size = L.size();

    this->base = (ElemType*)malloc(m_capacity * sizeof(ElemType));
    if (!this->base)
    {
        exit(OVERFLOW);
    }

    for(int i = 0; i < this->m_size; i++)
    {
        this->base[i] = L.base[i];
    }
}

wp::SqList::~SqList()
{
    if(this->base)
    {
        delete this->base;
        this->base = nullptr;
    }
}

ElemType& wp::SqList::at(int pos)const
{
    return this->base[pos - 1];
}

ElemType& wp::SqList::front()const
{
    return this->base[0];
}

ElemType& wp::SqList::back()const
{
    return this->base[m_size - 1];
}

ElemType& wp::SqList::operator[](int i)const
{
    if(i > this->m_size)
    {
        return this->base[0];
    }
    return this->base[i];
}

//ElemType& wp::SqList::erase(int pos)
//{
//    // TODO: 在此处插入 return 语句
//    
//}
//
//ElemType& wp::SqList::insert(int pos, const ElemType& value)
//{
//    // TODO: 在此处插入 return 语句
//    
//}
//
//ElemType& wp::SqList::push_back(const ElemType& value)
//{
//    // TODO: 在此处插入 return 语句
//    
//}
//
//ElemType& wp::SqList::pop_back()
//{
//    // TODO: 在此处插入 return 语句
//
//}

bool wp::SqList::empty()
{
    if (this->m_size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void wp::SqList::clear()
{
    this->m_size = 0;
    this->m_capacity = SQLISTINITCAPACITY;
}

bool wp::SqList::sort()
{
    return false;
}

unsigned int wp::SqList::size() const
{
    return this->m_size;
}

bool wp::SqList::resize(int capacity)
{
    return false;
}

unsigned int wp::SqList::capacity() const
{
    return this->m_capacity;
}


