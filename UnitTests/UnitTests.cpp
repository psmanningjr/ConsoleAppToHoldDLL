#include "pch.h"
#include "CppUnitTest.h"
#include "../ConsoleAppToHoldDLL/DoubleLinkedList.h"
#include "../ConsoleAppToHoldDLL/DoubleLinkedListNode.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(TestDoubleLinkedListConstructor)
		{
			std::shared_ptr <DoubleLinkedList> dlList = std::make_shared<DoubleLinkedList>();
			std::shared_ptr <DoubleLinkedListNode> dllNode = std::make_shared<DoubleLinkedListNode>();
			Assert::IsTrue(dlList->head == nullptr, L"head not null");
			Assert::IsTrue(dlList->tail == nullptr, L"tail not null");
		}
		TEST_METHOD(TestDoubleLinkedListInsertAtFront)
		{
			std::shared_ptr <DoubleLinkedList> dlList = std::make_shared<DoubleLinkedList>();
			std::shared_ptr <DoubleLinkedListNode> dllNode = std::make_shared<DoubleLinkedListNode>();
			dlList->insertAtFront(dllNode);
		}
	};
}
