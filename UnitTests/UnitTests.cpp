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

		std::shared_ptr <DoubleLinkedList> dlList;
		std::shared_ptr <DoubleLinkedListNode> dllNode;
		std::shared_ptr <ApplicationData> apData;

		UnitTests() {
			dlList = std::make_shared<DoubleLinkedList>();
			dllNode = std::make_shared<DoubleLinkedListNode>();
			apData = std::make_shared<ApplicationData>(TEST_APP_NAME);
			Assert::AreEqual(TEST_APP_NAME, apData->name, L"name not set");

			dllNode->setAppData(apData);
			Assert::AreEqual(TEST_APP_NAME, dllNode->getAppData()->name, L"Wrong app data");
		}
		TEST_METHOD(TestDoubleLinkedListConstructor)
		{
			Assert::IsTrue(dlList->head == nullptr, L"head not null");
			Assert::IsTrue(dlList->tail == nullptr, L"tail not null");
			apData = std::make_shared<ApplicationData>();
			Assert::AreEqual(std::string(""), apData->name, L"name default is wrong");
		}
		TEST_METHOD(TestDoubleLinkedListInsertAtFrontEmptyList)
		{
			dlList->insertAtFront(dllNode);
			Assert::IsTrue(dllNode == dlList->head, L"head is not set correctly");
			Assert::IsTrue(dllNode == dlList->tail, L"tail is not set correctly");
		}
		TEST_METHOD(TestDoubleLinkedListInsertAtEndEmptyList)
		{
			dlList->insertAtEnd(dllNode);

			Assert::IsTrue(dllNode == dlList->head, L"head is not set correctly");
			Assert::IsTrue(dllNode == dlList->tail, L"tail is not set correctly");
		}
	};
}
