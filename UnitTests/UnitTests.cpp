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
		const std::string TEST_APP_NAME_2 = "my second test app";

		std::shared_ptr <DoubleLinkedList> dlList;
		std::shared_ptr <DoubleLinkedListNode> dllNode;
		std::shared_ptr <ApplicationData> apData;

		UnitTests() {
			dlList = std::make_shared<DoubleLinkedList>();
			dllNode = std::make_shared<DoubleLinkedListNode>();
		}

		void setAppDataInDllNode() {
			apData = std::make_shared<ApplicationData>(TEST_APP_NAME);
			Assert::AreEqual(TEST_APP_NAME, apData->name, L"name not set");
			dllNode->setAppData(apData);
			Assert::AreEqual(TEST_APP_NAME, dllNode->getAppData()->name, L"Wrong app data");
		}

		TEST_METHOD(TestDoubleLinkedListConstructor)
		{
			Assert::IsTrue(dlList->getHeadPtr() == nullptr, L"head not null");
			Assert::IsTrue(dlList->getTailPtr() == nullptr, L"tail not null");
			Assert::IsTrue(dllNode->getAppData() == nullptr, L"appData not null");
			Assert::IsTrue(dllNode->getNextNode() == nullptr, L"nextData not null");
			Assert::IsTrue(dllNode->getprevNode() == nullptr, L"prevData not null");
			apData = std::make_shared<ApplicationData>();
			Assert::AreEqual(std::string(""), apData->name, L"name default is wrong");
		}
		TEST_METHOD(TestDoubleLinkedListInsertAtFrontEmptyList)
		{
			setAppDataInDllNode();
			dlList->insertAtFront(dllNode);
			Assert::IsTrue(dllNode == dlList->getHeadPtr(), L"head is not set correctly");
			Assert::IsTrue(dllNode == dlList->getTailPtr(), L"tail is not set correctly");
		}

		TEST_METHOD(TestDoubleLinkedListInsertAtFrontNonEmptyList)
		{
			setAppDataInDllNode();
			dlList->insertAtFront(dllNode);
			std::shared_ptr <ApplicationData> apData2 = std::make_shared<ApplicationData>(TEST_APP_NAME_2);
			std::shared_ptr <DoubleLinkedListNode> dllNode2 = std::make_shared<DoubleLinkedListNode>();
			dllNode2->setAppData(apData2);
			dlList->insertAtFront(dllNode2);

			Assert::IsTrue(dllNode2 == dlList->getHeadPtr(), L"head is not set correctly");
			Assert::IsTrue(dllNode == dlList->getTailPtr(), L"tail is not set correctly");
		}

		TEST_METHOD(TestDoubleLinkedListInsertAtEndEmptyList)
		{
			setAppDataInDllNode();
			dlList->insertAtEnd(dllNode);

			Assert::IsTrue(dllNode == dlList->getHeadPtr(), L"head is not set correctly");
			Assert::IsTrue(dllNode == dlList->getTailPtr(), L"tail is not set correctly");
		}
	};
}
