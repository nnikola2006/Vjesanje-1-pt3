#pragma once

namespace PJ1
{
    class Array
    {
    public:
        Array();
        Array(int size);
        ~Array();   // KAMEHAMEHAAAAAAAAA

        bool isFull() const; 
        bool isEmpty() const;
        int size() const;   // meni je vratilo size 2 :(    
        int getCapacity() const;

        bool append(int element); // bool za provjera jel dodo clan
        int& at(int index);
        const int& at(int index) const; // Mora vracati const int& jer inace izbacuje gresku ako pokusam vratiti int&
    private:
        int* m_array;   
        int m_capacity; // nemam ga 
        int m_size;     // 2cm
    };
}