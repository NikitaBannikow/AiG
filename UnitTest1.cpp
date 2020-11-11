//UnitTest
#include "pch.h"
#include "CppUnitTest.h"
#include <stdexcept>
#include "../Algoritmi_i_structuri_1/Header.h"
#include "\Users\pavel\source\repos\Algoritmi_i_structuri_1\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(HeaderTests)
    {
	public:
		List* list;
		//before each test creating a new one 
		TEST_METHOD_INITIALIZE(setUp)
		{
			list = new List();
		}
		//after each test cleaning the list
		TEST_METHOD_CLEANUP(cleanUP)
		{
			delete list;
		}

		TEST_METHOD(correct_push_back)
		{
			size_t size = 2;
			list->push_back(5);
			list->push_back(4);
			Assert::AreEqual(list->get_size(), size);
		}

		TEST_METHOD(correct_push_front)
		{
			size_t size = 2;
			list->push_front(5);
			list->push_front(4);
			Assert::AreEqual(list->get_size(),size);
		}

		TEST_METHOD(correct_pop_back)
		{
			size_t size = 2;
			list->push_back(4);
			list->push_back(5);
			list->push_back(6);
			list->pop_back();
			Assert::AreEqual(list->get_size(), size);
		}

		TEST_METHOD(correct_pop_front)
		{
			size_t size = 2;
			list->push_back(4);
			list->push_back(5);
			list->push_back(6);
			list->pop_front();
			Assert::AreEqual(list->get_size(), size);
		}

		TEST_METHOD(correct_insert)
		{
			size_t size = 3;
			list->push_front(4);
			list->push_front(6);
			list->insert(1, 5);
			Assert::AreEqual(list->get_size(), size);
		}

		TEST_METHOD(correct_index_at)
		{
			list->push_back(4);
			list->push_back(5);
			list->push_back(6);
			Assert::AreEqual(list->at(1), 5);
		}

		TEST_METHOD(correct_remove)
		{
			size_t size = 1;
			list->push_front(5);
			list->push_front(6);
			list->remove(0);
			Assert::AreEqual(list->get_size(), size);
		}


		TEST_METHOD(correct_get_size)
		{
			list->push_back(1);
			list->push_back(2);
			list->push_back(3);
			list->push_back(4);
			list->push_back(5);
			size_t size = 5;
			Assert::AreEqual(list->get_size(), size);
		}

		TEST_METHOD(correct_clear)
		{
			size_t b = 0;
			list->push_front(1);
			list->push_front(2);
			list->push_front(3);
			list->clear();
			Assert::AreEqual(list->get_size(), b);
		}

		TEST_METHOD(correct_set)
		{
			size_t size = 3;
			list->push_front(1);
			list->push_front(2);
			list->push_front(3);
			list->set(1, 3);
			Assert::AreEqual(list->get_size(), size);
		}


		TEST_METHOD(correct_isEmpty)
		{
			list->push_front(1);
			list->push_front(2);
			list->push_front(3);
			Assert::AreEqual(list->isEmpty(), false);

		}
		
		TEST_METHOD(correct_is_equal_to_reversed_one)
		{
			size_t size = 3;
			list->push_front(1);
			list->push_front(2);
			list->push_front(3);
			list->reverse();
			Assert::AreEqual(list->get_size(), size);
		}
	};
}
