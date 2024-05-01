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
		
		const std::string TEST_APP_NAME = "my test app";
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
			std::shared_ptr <ApplicationData> apData = std::make_shared<ApplicationData>();
			Assert::AreEqual(std::string(""), apData->name, L"name default is wrong");
			
			apData = std::make_shared<ApplicationData>(TEST_APP_NAME);
			Assert::AreEqual(TEST_APP_NAME, apData->name, L"name not set");

			dllNode->setAppData(apData);
			Assert::AreEqual(TEST_APP_NAME, dllNode->getAppData()->name, L"Wrong app data");

			dlList->insertAtFront(dllNode);

			Assert::IsTrue(dllNode == dlList->head, L"head is not set correctly");
		}
	};
}
