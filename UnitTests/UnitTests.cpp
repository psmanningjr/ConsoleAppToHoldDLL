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
		
		TEST_METHOD(TestDoubleLinkedList)
		{
			std::shared_ptr <DoubleLinkedList> dlList = std::make_shared<DoubleLinkedList>();
			std::shared_ptr <DoubleLinkedListNode> dllNode = std::make_shared<DoubleLinkedListNode>();
			Assert::AreEqual(nullptr, dlList->head(), L"head not null");
		}
	};
}
