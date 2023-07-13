#pragma once

template<class T>
class TypeIdGenerator sealed
{
private:
    static unsigned int m_count;

    TypeIdGenerator() = default;
public:
    ~TypeIdGenerator() = default;

    template<class U>
    static const unsigned int GetNewID()
    {
        static const unsigned int idCounter = m_count++;
        return idCounter;
    }
};

template<class T> unsigned int TypeIdGenerator<T>::m_count = 0;