﻿#include <cassert>
#include <iostream>
#include <vector>
#include <set>


using namespace std;

class ArrayInt
{
private:
    int m_length;
    int* m_data;

    void swap(int& a, int& b)
    {
        int x = a;
        a = b;
        b = x;
    }

    /*
     * Сортировка методом Хоара
     */
    void m_sort(int first, int last)
    {
        int i = first;
        int j = last;

        int x = m_data[(first + last) / 2];

        do
        {
            while (m_data[i] < x) i++;
            while (m_data[j] > x) j--;

            if (i <= j)
            {
                swap(m_data[i], m_data[j]);
                i++;
                j--;
            }
        } while (i <= j);

        if (i < last) m_sort(i, last);
        if (first < j) m_sort(first, j);
    }
public:
    ArrayInt() : m_length(0), m_data(nullptr)
    { }

    ArrayInt(int length) : m_length(length)
    {
        assert(length >= 0);

        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }

    void erase()
    {
        delete[] m_data;

        m_data = nullptr;
        m_length = 0;
    }

    int getLength()
    {
        return m_length;
    }

    void resize(int newLength)
    {
        if (newLength == m_length)
            return;

        if (newLength <= 0)
        {
            erase();
            return;
        }

        int* data = new int[newLength];

        if (m_length > 0)
        {
            int elementsToCopy = (newLength > m_length) ? m_length : newLength;

            for (int index = 0; index < elementsToCopy; ++index)data[index] = m_data[index];
        }

        delete[] m_data;

        m_data = data;
        m_length = newLength;
    }

    void insertBefore(int value, int index)
    {
        assert(index >= 0 && index <= m_length);

        int* data = new int[m_length + 1];

        for (int before = 0; before < index; ++before)
            data[before] = m_data[before];

        data[index] = value;

        for (int after = index; after < m_length; ++after)
            data[after + 1] = m_data[after];

        delete[] m_data;
        m_data = data;
        ++m_length;
    }

    void push_back(int value)
    {
        insertBefore(value, m_length);
    }

    void pop_back()
    {
        if (m_length == 0)
            return;

        resize(m_length - 1);
    }

    void pop_front()
    {
        if (m_length == 0)
            return;

        if (m_length - 1 == 0)
        {
            erase();
            return;
        }

        int* data = new int[m_length - 1];

        for (int index = 1; index < m_length; ++index)
            data[index - 1] = m_data[index];

        delete[] m_data;
        m_data = data;
        --m_length;
    }

    void sort()
    {
        m_sort(0, m_length - 1);
    }

    ~ArrayInt()
    {
        delete[] m_data;
    }

    friend std::ostream& operator<<(std::ostream&, ArrayInt&);

    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);

        return m_data[index];
    }
};

std::ostream& operator<<(std::ostream& s, ArrayInt& f)
{
    int length = f.getLength();

    for (int i = 0; i < length; ++i)
        s << f[i] << (((length == 1) || (length - 1 == i)) ? "" : ", ");

    return s;
}







class Card
{
public:
    enum rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
    enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };

    Card(rank r = ACE, suit s = SPADES, bool ifu = true) : m_Rank(r), m_Suit(s), m_IsFaceUp(ifu) { }

    int GetValue() const;
    void Flip();

    friend std::ostream& operator<<(std::ostream& s, const Card& aCard);
private:
    rank m_Rank;
    suit m_Suit;
    bool m_IsFaceUp;
};

int Card::GetValue() const
{
    int value = 0;
    if (m_IsFaceUp)
    {
        value = m_Rank;
        if (value > 10)
        {
            value = 10;
        }
    }
    return value;
}

void Card::Flip()
{
    m_IsFaceUp = !m_IsFaceUp;
}


void main()
{
    setlocale(LC_ALL, "rus");
    ArrayInt array;

    array.push_back(2);
    array.push_back(1);
    array.push_back(3);
    array.push_back(4);
    array.push_back(2);

    cout << "Исходный массив: " << array << endl;

    array.sort();

    cout << "Отсортированный массив: " << array << endl;

    array.pop_front();
    array.pop_front();

    cout << "После удаления двух первых элементов: " << array << endl;

    array.pop_back();
    array.pop_back();

    cout << "После удаления двух последних элементов: " << array << endl;

    ///////////////////////////////////////////////////////////////////////////

    vector<int> v = { 1, 5, 2, 2, 6, 7, 3, 1, 9, 2, 3, 5, 8, 4 };
    set<int> s(v.begin(), v.end());
    cout << s.size() << " различных значений из " << v.size() << endl;
}