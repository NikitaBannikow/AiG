#pragma once

#include <iomanip>
#include <iostream>
#include <locale>
#include <fstream>

class Node
{
    int Value;
    class Node* Next;
    class Node* Prev;
    friend class List;
};

class List
{
    Node* head;
    Node* last;
    Node* current;
    int count = 0;
public:
    List() { head = NULL; last = head; current = NULL; }
    void push_back(int number);
    void push_front(int number); 
    void pop_back();
    void pop_front();
    void insert(int index, int newvalue);
    int at(int index);
    void remove(int index);
    size_t get_size();
    void print_to_console();
    void clear();
    void set(int index, int newvalue);
    bool isEmpty();
    void set_last();
    void reverse();
};  