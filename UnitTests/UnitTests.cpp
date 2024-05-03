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
		const std::string TEST_APP_NAME_3 = "my third test app";

		std::shared_ptr <DoubleLinkedList> dlList;

		UnitTests() {
			dlList = std::make_shared<DoubleLinkedList>();
		}

		std::shared_ptr <DoubleLinkedListNode> setAppDataInDllNode(std::string appName) {
			std::shared_ptr <DoubleLinkedListNode> dllNode = std::make_shared<DoubleLinkedListNode>();
			std::shared_ptr <ApplicationData> apData = std::make_shared<ApplicationData>(appName);
			Assert::AreEqual(appName, apData->name, L"name not set");
			dllNode->appData = apData;
			Assert::AreEqual(appName, dllNode->appData->name, L"Wrong app data");
			return dllNode;
		}

		TEST_METHOD(TestDoubleLinkedListConstructor)
		{
			std::shared_ptr <DoubleLinkedListNode> dllNode = std::make_shared<DoubleLinkedListNode>();
			Assert::IsTrue(dlList->getHeadPtr() == nullptr, L"head not null");
			Assert::IsTrue(dlList->getTailPtr() == nullptr, L"tail not null");
			Assert::IsTrue(dllNode->appData == nullptr, L"appData not null");
			Assert::IsTrue(dllNode->nextNode == nullptr, L"nextData not null");
			Assert::IsTrue(dllNode->prevNode == nullptr, L"prevData not null");
			std::shared_ptr <ApplicationData> apData = std::make_shared<ApplicationData>();
			Assert::AreEqual(std::string(""), apData->name, L"name default is wrong");
		}
		TEST_METHOD(TestDoubleLinkedListInsertAtFrontEmptyList)
		{
			std::shared_ptr <DoubleLinkedListNode> dllNode = setAppDataInDllNode(TEST_APP_NAME);
			dlList->insertAtFront(dllNode);
			Assert::IsTrue(dllNode == dlList->getHeadPtr(), L"head is not set correctly");
			Assert::IsTrue(dllNode == dlList->getTailPtr(), L"tail is not set correctly");
			Assert::IsTrue(dllNode->nextNode == nullptr, L"nextData not null");
			Assert::IsTrue(dllNode->prevNode == nullptr, L"prevData not null");
		}

		TEST_METHOD(TestDoubleLinkedListInsertNode2AtFrontNonEmptyList)
		{
			std::shared_ptr <DoubleLinkedListNode> dllNode = setAppDataInDllNode(TEST_APP_NAME);
			dlList->insertAtFront(dllNode);
			
			std::shared_ptr <DoubleLinkedListNode> dllNode2 = setAppDataInDllNode(TEST_APP_NAME_2);
			dlList->insertAtFront(dllNode2);

			Assert::IsTrue(dllNode2 == dlList->getHeadPtr(), L"head is not set correctly");
			Assert::IsTrue(dllNode2->nextNode == dllNode, L"head node next is not original node");
			Assert::IsTrue(dllNode2->prevNode == nullptr, L"new node prev Data not null");
			Assert::IsTrue(dllNode == dlList->getTailPtr(), L"tail is not set correctly");
			Assert::IsTrue(dllNode->nextNode == nullptr, L"old data nextData not null");
			Assert::IsTrue(dllNode->prevNode == dllNode2, L"old node previous is not second node");
		}

		TEST_METHOD(TestDoubleLinkedListInsertAtEndEmptyList)
		{
			std::shared_ptr <DoubleLinkedListNode> dllNode = setAppDataInDllNode(TEST_APP_NAME);
			dlList->insertAtEnd(dllNode);

			Assert::IsTrue(dllNode == dlList->getHeadPtr(), L"head is not set correctly");
			Assert::IsTrue(dllNode == dlList->getTailPtr(), L"tail is not set correctly");
			Assert::IsTrue(dllNode->nextNode == nullptr, L"nextData not null");
			Assert::IsTrue(dllNode->prevNode == nullptr, L"prevData not null");
		}TEST_METHOD(TestDoubleLinkedListInsertNode2AtEndNonEmptyList)
		{
			std::shared_ptr <DoubleLinkedListNode> dllNode = setAppDataInDllNode(TEST_APP_NAME);
			dlList->insertAtFront(dllNode);
			
			std::shared_ptr <DoubleLinkedListNode> dllNode2 = setAppDataInDllNode(TEST_APP_NAME_2);
			dlList->insertAtEnd(dllNode2);

			Assert::IsTrue(dllNode2 == dlList->getTailPtr(), L"tail is not set correctly");
			Assert::IsTrue(dllNode2->prevNode == dllNode, L"new node prev is not original node");
			Assert::IsTrue(dllNode2->nextNode == nullptr, L"new nextData not null");
			Assert::IsTrue(dllNode == dlList->getHeadPtr(), L"head is not set correctly");
			Assert::IsTrue(dllNode->prevNode == nullptr, L"prevData not null");
			Assert::IsTrue(dllNode->nextNode == dllNode2, L"node next is not second node");
		}
		TEST_METHOD(TestDoubleLinkedListInsertNode3BeforeNonFirstNode)
		{
			std::shared_ptr <DoubleLinkedListNode> dllNode = setAppDataInDllNode(TEST_APP_NAME);
			dlList->insertAtFront(dllNode);

			std::shared_ptr <DoubleLinkedListNode> dllNode2 = setAppDataInDllNode(TEST_APP_NAME_2);
			dlList->insertAtFront(dllNode2);

			std::shared_ptr <DoubleLinkedListNode> dllNode3 = setAppDataInDllNode(TEST_APP_NAME_3);
			dlList->insertBeforeNode(dllNode, dllNode3);

			Assert::IsTrue(dllNode3 == dllNode->prevNode, L"dll prev Node is not set correctly");
			Assert::IsTrue(dllNode3->prevNode == dllNode2, L"dl3 prev node prev is not prev node");
			Assert::IsTrue(dllNode3->nextNode == dllNode, L"new node next Data not dll inserted before");
			Assert::IsTrue(dllNode2->nextNode == dllNode3, L"old data nextData not new node");
		}
		TEST_METHOD(TestDoubleLinkedListInsertNode3BeforeFirstNode)
		{
			std::shared_ptr <DoubleLinkedListNode> dllNode = setAppDataInDllNode(TEST_APP_NAME);
			dlList->insertAtFront(dllNode);

			std::shared_ptr <DoubleLinkedListNode> dllNode2 = setAppDataInDllNode(TEST_APP_NAME_2);
			dlList->insertAtFront(dllNode2);

			std::shared_ptr <DoubleLinkedListNode> dllNode3 = setAppDataInDllNode(TEST_APP_NAME_3);
			dlList->insertBeforeNode(dllNode2, dllNode3);

			Assert::IsTrue(dllNode3 == dlList->getHeadPtr(), L"head is not set correctly");
			Assert::IsTrue(dllNode3->nextNode == dllNode2, L"head node next is not original head node");
			Assert::IsTrue(dllNode3->prevNode == nullptr, L"new node prev Data not null");
			Assert::IsTrue(dllNode == dlList->getTailPtr(), L"tail is not set correctly");
			Assert::IsTrue(dllNode2->nextNode == dllNode, L"old data nextData not null");
			Assert::IsTrue(dllNode2->prevNode == dllNode3, L"old node previous is not new node");

		}
		TEST_METHOD(TestDoubleLinkedListInsertNode3AfterLastNode)
		{
			std::shared_ptr <DoubleLinkedListNode> dllNode = setAppDataInDllNode(TEST_APP_NAME);
			dlList->insertAtFront(dllNode);

			std::shared_ptr <DoubleLinkedListNode> dllNode2 = setAppDataInDllNode(TEST_APP_NAME_2);
			dlList->insertAtFront(dllNode2);

			std::shared_ptr <DoubleLinkedListNode> dllNode3 = setAppDataInDllNode(TEST_APP_NAME_3);
			dlList->insertAfterNode(dllNode, dllNode3);

			Assert::IsTrue(dllNode3 == dlList->getTailPtr(), L"tail is not set correctly");
			Assert::IsTrue(dllNode3->prevNode == dllNode, L"new node prev is not original node");
			Assert::IsTrue(dllNode3->nextNode == nullptr, L"new nextData not null");
			Assert::IsTrue(dllNode->nextNode == dllNode3, L"node next is not second node");
		}
		TEST_METHOD(TestDoubleLinkedListInsertNode3AfterFirstNode)
		{
			std::shared_ptr <DoubleLinkedListNode> dllNode = setAppDataInDllNode(TEST_APP_NAME);
			dlList->insertAtFront(dllNode);

			std::shared_ptr <DoubleLinkedListNode> dllNode2 = setAppDataInDllNode(TEST_APP_NAME_2);
			dlList->insertAtFront(dllNode2);

			std::shared_ptr <DoubleLinkedListNode> dllNode3 = setAppDataInDllNode(TEST_APP_NAME_3);
			dlList->insertAfterNode(dllNode2, dllNode3);

			Assert::IsTrue(dllNode3 == dllNode->prevNode, L"dll prev Node is not set correctly");
			Assert::IsTrue(dllNode3->prevNode == dllNode2, L"dl3 prev node prev is not prev node");
			Assert::IsTrue(dllNode3->nextNode == dllNode, L"new node next Data not dll inserted before");
			Assert::IsTrue(dllNode2->nextNode == dllNode3, L"old data nextData not new node");
		}
		TEST_METHOD(TestDoubleLinkedListremoveLastNode)
		{
			std::shared_ptr <DoubleLinkedListNode> dllNode = setAppDataInDllNode(TEST_APP_NAME);
			dlList->insertAtFront(dllNode);

			dlList->removeNode(dllNode);

			Assert::IsTrue(dlList->getHeadPtr() == nullptr, L"head not null");
			Assert::IsTrue(dlList->getTailPtr() == nullptr, L"Tail not null");
		}
		TEST_METHOD(TestDoubleLinkedListremove2ndToLastNode)
		{
			std::shared_ptr <DoubleLinkedListNode> dllNode = setAppDataInDllNode(TEST_APP_NAME);
			dlList->insertAtFront(dllNode);

			std::shared_ptr <DoubleLinkedListNode> dllNode2 = setAppDataInDllNode(TEST_APP_NAME_2);
			dlList->insertAtFront(dllNode2);

			dlList->removeNode(dllNode2);

			Assert::IsTrue(dlList->getHeadPtr() == dllNode, L"head not last node");
			Assert::IsTrue(dlList->getTailPtr() == dllNode, L"Tail not last node");
			Assert::IsTrue(dllNode->prevNode == nullptr, L"last node prev not null");
			Assert::IsTrue(dllNode->nextNode == nullptr, L"last node next not null");
		}
		TEST_METHOD(TestDoubleLinkedListremoveLastNodeFromListOf2)
		{
			std::shared_ptr <DoubleLinkedListNode> dllNode = setAppDataInDllNode(TEST_APP_NAME);
			dlList->insertAtFront(dllNode);

			std::shared_ptr <DoubleLinkedListNode> dllNode2 = setAppDataInDllNode(TEST_APP_NAME_2);
			dlList->insertAtFront(dllNode2);

			dlList->removeNode(dllNode);

			Assert::IsTrue(dlList->getHeadPtr() == dllNode2, L"head not last node");
			Assert::IsTrue(dlList->getTailPtr() == dllNode2, L"Tail not last node");
			Assert::IsTrue(dllNode2->prevNode == nullptr, L"last node prev not null");
			Assert::IsTrue(dllNode2->nextNode == nullptr, L"last node next not null");
		}
	};
}
