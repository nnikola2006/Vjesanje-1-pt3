#include "Array.h"

using namespace PJ1; // da ne kucam svaki put PJ1::Array

Array::Array()
{
    this->m_array = new int[1](); // kada se stave ove () onda automatski popuni niz sa 0
    this->m_capacity = 1;
    this->m_size = 0;
}
Array::Array(int capacity)
{
    if(capacity == 0)
    {
        this->m_array = new int[1](); // kada se stave ove () onda automatski popuni niz sa 0
        this->m_capacity = 1;
        this->m_size = 0;
    }
    else
    {
        this->m_array = new int[capacity](); // ne moram opet objasnjavati...
        this->m_capacity = capacity;
        this->m_size = 0;
    }
}
Array::~Array()
{
    delete[] this->m_array;
}

bool Array::isFull() const
{
    if(this->m_size == this->m_capacity)
        return true;
    return false;
}
bool Array::isEmpty() const
{
    if(this->m_size == 0)
        return true;
    return false;
}
int Array::size() const
{
    return this->m_size;
}
int Array::getCapacity() const
{
    return this->m_capacity;
}

void Array::append(int value)
{
    if(isFull())
    {
        int new_capacity = m_capacity * 2;
        int* new_array = new int[new_capacity]();

        for(int i = 0; i < m_size; i++)
        {
            new_array[i] = m_array[i];
        }
        
        delete[] m_array;
        m_array = new_array;
        m_capacity = new_capacity;
    }
    m_array[m_size++] = value;
}
int& Array::at(int index)
{
    return this->m_array[index];
}
const int& Array::at(int index) const
{
    return this->m_array[index];
}