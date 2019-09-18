#pragma once

class MyClass
{
public:
    bool operator==(const MyClass &other) const
    {
        return m_number == other.m_number;
    }

    MyClass(int i) : m_number(i) {}

private:
    int m_number = 0;
};