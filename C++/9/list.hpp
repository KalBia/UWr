#pragma once
#include <initializer_list>
#include <iostream>
//*******************************************

namespace calc
{
    template<typename T>
    class lista
    {
        class node
        {
            friend class lista;

            T value;
            node *next;

            node() noexcept
            : value(0), next(nullptr)
            {}

            node(T val) noexcept
            : value(val), next(nullptr)
            {}
        };

        //*******************************************

        node *first = nullptr;

        //*******************************************

    public:
        lista() noexcept
            : first(nullptr)
        {}

        lista(const lista<T> &other) noexcept //konstruktor kopiujacy
        {
            if (other.first == nullptr)
            {
                lista();
            }
            else
            {
                node* start = other.first;
                first = new node(start->value);
                node* temp = first;
                start = start->next;

                while (start != nullptr)
                {
                    temp->next = new node(start->value);
                    start = start->next;
                    temp = temp->next;
                }
            }
        }

        lista(std::initializer_list<T> lst) //konstruktor z lista wartosci
        {
            node* temp;
            for (auto elem : lst)
            {
                if (first == nullptr)
                {
                    first = new node(elem);
                    temp = first;
                }
                else
                {
                    temp->next = new node(elem);
                    temp = temp->next;
                }
            }
        }

        //*******************************************

        lista<T>& operator=(const lista<T> &other) noexcept //przypisanie kopiujace
        {
            if (this != &other)
            {
                this->~lista();
                node* start = other.first;
                first = new node(start->value);
                node* temp = first;
                start = start->next;

                while (start != nullptr)
                {
                    temp->next = new node(start->value);
                    start = start->next;
                    temp = temp->next;
                }
            }

            return *this;
        }

        lista<T>& operator=(lista<T> &&other) //przypisanie przenoszace
        {
            if (this != &other)
            {
                swap(this->first, other->first);
            }

            return *this;
        }

        //*******************************************

        void insert(T thing, int i) noexcept
        {
            if (i == 0)
            {
                push_front(thing);
                return;
            }

            if (is_empty())
                first = new node();

            int index = 0;
            node* temp = first;
            while (temp->next != nullptr && index != (i-1))
            {
                index++;
                temp = temp->next;
            }

            if (temp->next == nullptr) // dotarlismy do ostatniego elementu na liscie
            {
                while (index != (i-1)) // tworzymy zerowe elementy i wtedy dodajemy na koniec
                {
                    temp->next = new node();
                    index++;
                }

                temp->next = new node(thing);
            }
            else
            {
                node* nowy = new node(thing);
                node* NEXT = temp->next;
                temp->next = nowy;
                nowy->next = NEXT;
            }
        }

        void push_front(T thing) noexcept
        {
            if (is_empty())
            {
                first = new node(thing);
                return;
            }

            node* nowy = new node(thing);
            nowy->next = first;
            first = nowy;
        }

        void push_back(T thing) noexcept
        {
            if (is_empty())
            {
                first = new node(thing);
                return;
            }

            node* nowy = new node(thing);
            node* temp = first;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }

            temp->next = nowy;
        }

        //*******************************************

        T get_elem(int i) const
        {
            if (is_empty())
                throw std::logic_error("lista is empty");

            if (i >= length())
                throw std::invalid_argument("index out of range");

            int index = 0;
            node* temp = first;
            while (index != i)
            {
                temp = temp->next;
                index++;
            }

            return temp->value;
        }

        T get_front() const
        {
            return get_elem(0);
        }

        T get_back() const
        {
            return get_elem(length()-1);
        }

        //*******************************************

        void pop_position(int i)
        {
            if (is_empty())
                throw std::logic_error("lista is empty");

            if (i >= length())
                throw std::invalid_argument("index out of range");

            node* prev = first;
            if (i == 0)
            {
                first = first->next;
                delete prev;
                return;
            }

            int index = 0;
            node* temp = first;
            while (index != i)
            {
                prev = temp;
                temp = temp->next;
                index++;
            }

            prev->next = temp->next;
            delete temp;
        }

        void pop_front()
        {
            pop_position(0);
        }

        void pop_back()
        {
            pop_position(length()-1);
        }

        //*******************************************

        void pop_value(T thing)
        {
            if (is_empty())
                throw std::logic_error("lista is empty");

            node* temp = first;
            node* prev = nullptr;
            while(temp != nullptr && temp->value != thing)
            {
                prev = temp;
                temp = temp->next;
            }

            if (temp != nullptr)
            {
                if (prev == nullptr)
                {
                    prev = first;
                    first = first->next;
                    delete prev;
                    return;
                }

                prev->next = temp->next;
                delete temp;
            }
        }

        void pop_all_value(T thing)
        {
            int repeat = count(thing);
            for (int i = 0; i < repeat; i++)
            {
                pop_value(thing);
            }
        }

        //*******************************************

        int find(T thing) const noexcept
        {
            if (is_empty())
                return -1;

            node* temp = first;
            int index = 0;
            while (temp != nullptr && temp->value != thing)
            {
                temp = temp->next;
                index++;
            }

            if (temp == nullptr)
                return -1;

            return index;
        }

        int count(T thing) const noexcept
        {
            if (is_empty())
                return 0;

            node* temp = first;
            int counter = 0;
            while (temp != nullptr)
            {
                if (temp->value == thing)
                    counter++;

                temp = temp->next;
            }

            return counter;
        }

        //*******************************************

        int length() const noexcept
        {
            if (is_empty())
                return 0;

            node* temp = first;
            int counter = 0;
            while (temp != nullptr)
            {
                counter++;
                temp = temp->next;
            }

            return counter;
        }

        bool is_empty() const noexcept
        {
            if (first == nullptr)
                return true;
            return false;
        }

        //*******************************************

        ~lista()
        {
            node* temp = first;
            node* prev = temp;
            while (temp != nullptr)
            {
                prev = temp;
                temp = temp->next;
                delete prev;
            }

            firtst = nullptr;
        }

        //*******************************************

        template <typename U>
        friend std::ostream& operator<<(std::ostream& wyj, const lista<U>& L);
    };

    //*******************************************

    template<typename T>
    std::ostream& operator<<(std::ostream& wyj, const lista<T>& L)
    {
        if (L.is_empty())
        {
            wyj<< "empty";
            return wyj;
        }

        int index = 0;
        while (index < L.length())
        {
            wyj << index << " : " << L.get_elem(index) << "\n";
            index++;
        }

        return wyj;
    }
}

