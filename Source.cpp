#include "Header.h"
#include <iomanip>
#include <iostream>
#include <locale>
#include <fstream>

using namespace std;

//function adds element to the end of the list
void List::push_back(int number)
{
    Node* elem = new Node();
    elem->Value = number;
    count++;

    if (head == NULL)
    {
        elem->Next = NULL;
        elem->Prev = NULL;
        head = elem;
        last = head;
    }
    else
    {
        elem->Prev = last;
        last->Next = elem;
        elem->Next = NULL;
        last = elem;
    }
}   

//function adds element to the beginning of the list
void List::push_front(int number)
{
    Node* elem = new Node();
    elem->Value = number;
    count++;

    if (head == NULL)
    {
        elem->Next = NULL;
        elem->Prev = NULL;
        head = elem;
    }
    else
    {
        elem->Next = head;
        head->Prev = elem;
        elem->Prev = NULL;
        head = elem;
    }
}

//function deletes last element of the list
void List::pop_back()
{
    if (count > 1)
    {
        set_last();
        current = last->Prev;
        last->Next = NULL;
        last->Prev = NULL;
        delete last;
        current->Next = NULL;
        last = current;
        count--;
    }
    else if (count == 1)
    {
        current = head;
        last = current;
        current->Next = NULL;
        current->Prev = NULL;
        delete current;
        count--;
    }

}

//function deletes first element of the list
void List::pop_front()
{
    if (count > 1)
    {
        current = head;
        head = head->Next;
        current->Prev = NULL;
        current->Next = NULL;
        delete current;
        head->Prev = NULL;
        count--;
    }
    else if (count == 1)
    {
        current = head;
        current->Next = NULL;
        current->Prev = NULL;
        delete current;
        count--;
    }

}

//function adds an element before chosen index
void List::insert(int index, int newvalue) 
{
    Node* elem = new Node();
    elem->Value = newvalue;
    current = head;
    if (index == 0)
    {
        elem->Next = current;
        elem->Prev = NULL;
        current->Prev = elem;
        head = elem;
    }
    else
    {
        for (int i = 0; i < index; i++)
        {
            current = current->Next;
        }
        elem->Next = current;
        elem->Prev = current->Prev;
        current->Prev = elem;
        current = elem->Prev;
        current->Next = elem;
    }
    count++;
}

//function gets element by chosen index
int List::at(int index)
{
    current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->Next;
    }
    return current->Value;
}

//function deletes element by chosen index
void List::remove(int index)
{
    current = head;
    if (index == 0)
    {
        head = current->Next;
        current->Next->Prev = NULL;
        current->Next = NULL;
        current->Prev = NULL;
        delete current;
    }
    else if (index == count - 1)
    {
        for (int i = 0; i < index; i++)
        {
            current = current->Next;
        }
        last = current->Prev;
        current->Prev->Next = NULL;
        current->Next = NULL;
        current->Prev = NULL;
        delete current;
    }
    else
    {
        for (int b = 0; b < index; b++)
        {
            current = current->Next;
        }
        current->Prev->Next = current->Next;
        current->Next->Prev = current->Prev;
        current->Next = NULL;
        current->Prev = NULL;
        delete current;

    }
    count--;
}

//function outputs to console size of the list
size_t List::get_size()
{
    return count;
}

//function outputs list to the console
void List::print_to_console()
{
    current = head;
    cout << "|";
    while (1)
    {
        if (isEmpty())
        {
            cout << "\n List is empty!\n";
            break;
        }
        if (current != NULL)
        {
            cout << current->Value << "|";
            current = current->Next;
        }
        if (current == NULL)
        {
            cout << endl;
            break;
        }
    }
}

//function clears the whole list
void List::clear()
{
    {
        int i = count;
        for (int j = 0; j < count; j++)
        {
            current = head;
            head = head->Next;
            current->Next = NULL;
            current->Prev = NULL;
            delete current;
        }
        count = 0;
    }
}

//function replaces element with choosen index
void List::set(int index, int newvalue)
{
    current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->Next;
    }
    Node* elem = new Node();
    elem->Value = newvalue;

    if (index == 0)
    {
        elem->Next = current->Next;
        elem->Prev = NULL;
        current->Next->Prev = elem;
        current->Next = NULL;
        current->Prev = NULL;
        head = elem;
        delete current;
    }
    else if (index == count - 1)
    {
        elem->Next = NULL;
        elem->Prev = current->Prev;
        current->Prev->Next = elem;
        current->Next = NULL;
        current->Prev = NULL;
        delete current;
    }
    else
    {
        elem->Next = current->Next;
        elem->Prev = current->Prev;
        current->Prev->Next = elem;
        current->Next->Prev = elem;
        current->Next = NULL;
        current->Prev = NULL;
        delete current;
    }
}

//function checks if lst is epmty
bool List::isEmpty()
{
    return (count == 0);
}

// function gets the last element
void List::set_last()
{
    last = head;
    while (1)
    {
        if (last->Next != NULL)
        {
            last = last->Next;
        }
        else
        {
            break;
        }
    }
}

//function turns over the list
void List::reverse()
{
     if (last == NULL || last == head)
     {
        return;
     }
     Node* right = last;
     Node* left = right->Prev;
     while (left != NULL)
     {
        left->Next = NULL;
        right->Next = left;
        Node* tmp = left->Prev;
        left->Prev = right;
        right = left;
        left = tmp;
     }
     last->Prev = NULL;
     head = last;
     last = right;
}
