#include "Array.h"

// Na labu asistent nije koristio using namespace PJ1
// On je bukv citav fajl napiso samo namespace PJ1{} isto kao u Array.h fajlu
using namespace PJ1; // da ne kucam svaki put PJ1::Array
Array::Array()
{
    this->m_array = new int[1](); // kada se stave ove () onda automatski popuni niz sa 0 (isto kao broj zena sto sam pipno u zivotu HAHAHHAHA, salim se)
    this->m_capacity = 1;
    this->m_size = 0;
}  
//  Moze se napisati i ovako
//   Array::Array() : m_array(new int[1]), m_capacity(1), m_size(0){}
Array::Array(int capacity)
{
    if(capacity <= 0)
    {
        this->m_array = new int[1](); // ne moram opet objasnjavati polupani...
        this->m_capacity = 1;
        this->m_size = 0;
    }
    else
    {
        this->m_array = new int[capacity]();
        this->m_capacity = capacity;
        this->m_size = 0;
    }
}
/*  
//  Na labu je receno da se konstruise ovaj gore konstruktor ovako:
//  Array::Array(int capacity) : capacity(capacity), size(0), arr(new int[capacity]){}
//  
//  Ovo su njegova imena vrijednosti bila kod mene u kodu bi se morao promjeniti raspored
//  clanova, prvo bi bio m_capacity, m_size, m_array da bi radilo
*/
Array::~Array()
{
    delete[] this->m_array; // brise balije
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

bool Array::append(int value)
{
    if(isFull())
    {
        /*
        // Asistent je napiso:
        // TODO reallocation
        // return false (nzm sto je false al ajd)
        */ 
        int new_capacity = m_capacity * 2;
        int* new_array = new int[new_capacity]();

        // kopira/prebacuje stare clanove
        for(int i = 0; i < m_size; i++)
        {
            new_array[i] = m_array[i];
        }
        
        delete[] m_array;
        m_array = new_array;
        m_capacity = new_capacity;
    }
    m_array[m_size] = value;
    m_size++;

    return true;
}
// Podrazumijeva se da je 0 <= i <= length
int& Array::at(int index)
{
    return this->m_array[index];
}
const int& Array::at(int index) const
{
    return this->m_array[index];
}