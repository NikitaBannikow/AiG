// This programm was made by Bannikov Nikita, group 9309
#include <iomanip>
#include <iostream>
#include <locale>
#include <fstream>
#include "Header.h"

using namespace std;

void main()  //main function
{
	int value = 0;
	List* Pr = new List();
	int a = 0;
	int index = 0;
	int newvalue = 0;
	while (1) {
	begin:
	cout << "Choose method:\n"
		<< "1. Enter the element, which you want add to the end of the List.\n"
		<< "2. Enter the element, which you want add to the beginning of the List.\n"
		<< "3. Delete last element.\n"
		<< "4. Delete first element.\n"
		<< "5. Adding an element before chosen index.\n"
		<< "6. Get element by chosen index.\n"
		<< "7. Delete element by chosen index.\n"
		<< "8. Getting the size of the List.\n"
		<< "9. Print List to console.\n"
		<< "10. Clear the List.\n"
		<< "11. Replace element with choosen index.\n"
		<< "12. Checking list for emptyness.\n"
		<< "13. Reverse the order of elements.\n"
		<< "14. Exit.\n\n";
	cin >> a;
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
		switch (a)
		{
		case 1:
		{
			cout << "\n\nEnter the value of the new element:  ";
			cin >> value;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			Pr->push_back(value);
			cout << "Changed List: ";
			Pr->print_to_console();
			cout << "==============================================\n";
			goto begin;
		}
		case 2:
		{
			cout << "\n\nEnter the value of the new element:  ";
			cin >> value;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			Pr->push_front(value);
			cout << "Changed List: ";
			Pr->print_to_console();
			cout << "===============================================\n";
			goto begin;
		}
		case 3:
		{
				Pr->pop_back();
				cout << "Changed List: ";
				Pr->print_to_console();
				cout << "===============================================\n";
				goto begin;
		}
		case 4:
		{
			Pr->pop_front();
				cout << "Changed List: ";
				Pr->print_to_console();
				cout << "===============================================\n";
				goto begin;
		}
		case 5:
		{
			cout << "Enter the value of new element:  ";
			cin >> newvalue;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "Enter the index (place where you want to add the value):  ";
			cin >> index;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			if (index <= Pr->get_size())
			{
				Pr->insert(index, newvalue);
				cout << "Changed List: ";
				Pr->print_to_console();
			}
			else
			{
			cout << "\n\nChoose index lesser or equal to list size";
			}
			cout << "\n==============================================\n";
			goto begin;
		}
		case 6:
		{
			cout << "\n\nEnter index of the element: ";
			cin >> index;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			if (index <= Pr->get_size())
			{
			cout << "Element with choosen index:  " << Pr->at(index);
			}
			else
			{
			cout << "\n\nChoose index lesser or equal to list size";
			}
			cout << "\n==============================================\n";
			goto begin;
		}
		case 7:
		{
			cout << "\n\nEnter index of the element: ";
			cin >> index;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			if (index <= Pr->get_size())
			{
			Pr->remove(index);
			cout << "Changed List: ";
			Pr->print_to_console();
			}
			else
			{
				cout << "\n\nChoose index lesser or equal to list size";
			}
			cout <<"\n==============================================\n";
			goto begin;
		}
		case 8:
		{
			cout << "\n\n List size:  " << Pr->get_size();
			cout << "\n==============================================\n";
			goto begin;
		}
		case 9:
		{
			cout << "List:  ";
			Pr->print_to_console();
			cout << "==============================================\n";
			goto begin;
		}
		case 10:
		{
			Pr->clear();
			cout << "List is cleared.\n";
			cout << "==============================================\n";
			goto begin;
		}
		case 11:
		{
			cout << "\n\nEnter the value of the new element: ";
			cin >> newvalue;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "\n\nEnter the index of element for change: ";
			cin >> index;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			if (index <= Pr->get_size())
			{
				Pr->set(index, newvalue);
				cout << "List after change: ";
				Pr->print_to_console();
			}
			else
			{
				cout << "\n\nChoose index lesser or equal to  the list size";
			}
			cout << "\n==============================================\n";
			goto begin;
		}
		case 12:
		{
			if (!Pr->isEmpty())
			{
				cout << "List is not empty.";
			}
			else
			{
				cout << "List is empty.";
			}
			cout << "==============================================\n";
			goto begin;
		}
		case 13:
		{
			Pr->reverse();
			cout << "List after change: ";
			Pr->print_to_console();
			cout << "==============================================\n";
			goto begin;
		}
		case 14:
		{
			exit(1);
		}
		default:
		{
			cout << "Error. Enter the number between 1 and 14" << endl;
			goto begin;
		}
		}
	}
}