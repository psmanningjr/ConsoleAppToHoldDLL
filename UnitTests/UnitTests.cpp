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
		std::shared_ptr <DoubleLinkedListNode> dllNode;
		std::shared_ptr <ApplicationData> apData;
		std::shared_ptr <DoubleLinkedListNode> dllNode2;
		std::shared_ptr <ApplicationData> apData2;
		std::shared_ptr <DoubleLinkedListNode> dllNode3;
		std::shared_ptr <ApplicationData> apData3;

		UnitTests() {
			dlList = std::make_shared<DoubleLinkedList>();
		}

		void setAppDataInDllNode() {
			dllNode = std::make_shared<DoubleLinkedListNode>();
			apData = std::make_shared<ApplicationData>(TEST_APP_NAME);
			Assert::AreEqual(TEST_APP_NAME, apData->name, L"name not set");
			dllNode->appData = apData;
			Assert::AreEqual(TEST_APP_NAME, dllNode->appData->name, L"Wrong app data");
		}

		void set2ndAppDataInDllNode() {
			dllNode2 = std::make_shared<DoubleLinkedListNode>();
			apData2 = std::make_shared<ApplicationData>(TEST_APP_NAME_2);
			Assert::AreEqual(TEST_APP_NAME_2, apData2->name, L"name not set");
			dllNode2->appData = apData2;
			Assert::AreEqual(TEST_APP_NAME_2, dllNode2->appData->name, L"Wrong app data");
		}

		void set3rdAppDataInDllNode() {
			dllNode3 = std::make_shared<DoubleLinkedListNode>();
			apData3 = std::make_shared<ApplicationData>(TEST_APP_NAME_3);
			Assert::AreEqual(TEST_APP_NAME_3, apData3->name, L"name not set");
			dllNode3->appData = apData3;
			Assert::AreEqual(TEST_APP_NAME_3, dllNode3->appData->name, L"Wrong app data");
		}
		TEST_METHOD(TestDoubleLinkedListConstructor)
		{
			dllNode = std::make_shared<DoubleLinkedListNode>();
			Assert::IsTrue(dlList->getHeadPtr() == nullptr, L"head not null");
			Assert::IsTrue(dlList->getTailPtr() == nullptr, L"tail not null");
			Assert::IsTrue(dllNode->appData == nullptr, L"appData not null");
			Assert::IsTrue(dllNode->nextNode == nullptr, L"nextData not null");
			Assert::IsTrue(dllNode->prevNode == nullptr, L"prevData not null");
			apData = std::make_shared<ApplicationData>();
			Assert::AreEqual(std::string(""), apData->name, L"name default is wrong");
		}
		TEST_METHOD(TestDoubleLinkedListInsertAtFrontEmptyList)
		{
			setAppDataInDllNode();
			dlList->insertAtFront(dllNode);
			Assert::IsTrue(dllNode == dlList->getHeadPtr(), L"head is not set correctly");
			Assert::IsTrue(dllNode == dlList->getTailPtr(), L"tail is not set correctly");
			Assert::IsTrue(dllNode->nextNode == nullptr, L"nextData not null");
			Assert::IsTrue(dllNode->prevNode == nullptr, L"prevData not null");
		}

		TEST_METHOD(TestDoubleLinkedListInsertNode2AtFrontNonEmptyList)
		{
			setAppDataInDllNode();
			dlList->insertAtFront(dllNode);
			set2ndAppDataInDllNode();

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
			setAppDataInDllNode();
			dlList->insertAtEnd(dllNode);

			Assert::IsTrue(dllNode == dlList->getHeadPtr(), L"head is not set correctly");
			Assert::IsTrue(dllNode == dlList->getTailPtr(), L"tail is not set correctly");
			Assert::IsTrue(dllNode->nextNode == nullptr, L"nextData not null");
			Assert::IsTrue(dllNode->prevNode == nullptr, L"prevData not null");
		}TEST_METHOD(TestDoubleLinkedListInsertNode2AtEndNonEmptyList)
		{
			setAppDataInDllNode();
			dlList->insertAtFront(dllNode);
			set2ndAppDataInDllNode();

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
			setAppDataInDllNode();
			dlList->insertAtFront(dllNode);

			set2ndAppDataInDllNode();
			dlList->insertAtFront(dllNode2);

			set3rdAppDataInDllNode();
			dlList->insertBeforeNode(dllNode, dllNode3);

			Assert::IsTrue(dllNode3 == dllNode->prevNode, L"dll prev Node is not set correctly");
			Assert::IsTrue(dllNode3->prevNode == dllNode2, L"dl3 prev node prev is not prev node");
			Assert::IsTrue(dllNode3->nextNode == dllNode, L"new node next Data not dll inserted before");
			Assert::IsTrue(dllNode2->nextNode == dllNode3, L"old data nextData not new node");
		}
		TEST_METHOD(TestDoubleLinkedListInsertNode3BeforeFirstNode)
		{
			setAppDataInDllNode();
			dlList->insertAtFront(dllNode);

			set2ndAppDataInDllNode();
			dlList->insertAtFront(dllNode2);

			set3rdAppDataInDllNode();
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
			setAppDataInDllNode();
			dlList->insertAtFront(dllNode);

			set2ndAppDataInDllNode();
			dlList->insertAtFront(dllNode2);

			set3rdAppDataInDllNode();
			dlList->insertAfterNode(dllNode, dllNode3);

			Assert::IsTrue(dllNode3 == dlList->getTailPtr(), L"tail is not set correctly");
			Assert::IsTrue(dllNode3->prevNode == dllNode, L"new node prev is not original node");
			Assert::IsTrue(dllNode3->nextNode == nullptr, L"new nextData not null");
			Assert::IsTrue(dllNode->nextNode == dllNode3, L"node next is not second node");
		}
		TEST_METHOD(TestDoubleLinkedListInsertNode3AfterFirstNode)
		{
			setAppDataInDllNode();
			dlList->insertAtFront(dllNode);

			set2ndAppDataInDllNode();
			dlList->insertAtFront(dllNode2);

			set3rdAppDataInDllNode();
			dlList->insertAfterNode(dllNode2, dllNode3);

			Assert::IsTrue(dllNode3 == dllNode->prevNode, L"dll prev Node is not set correctly");
			Assert::IsTrue(dllNode3->prevNode == dllNode2, L"dl3 prev node prev is not prev node");
			Assert::IsTrue(dllNode3->nextNode == dllNode, L"new node next Data not dll inserted before");
			Assert::IsTrue(dllNode2->nextNode == dllNode3, L"old data nextData not new node");
		}
		TEST_METHOD(TestDoubleLinkedListremoveLastNode)
		{
			setAppDataInDllNode();
			dlList->insertAtFront(dllNode);

			dlList->removeNode(dllNode);

			Assert::IsTrue(dlList->getHeadPtr() == nullptr, L"head not null");
			Assert::IsTrue(dlList->getTailPtr() == nullptr, L"Tail not null");
		}
		TEST_METHOD(TestDoubleLinkedListremove2ndToLastNode)
		{
			setAppDataInDllNode();
			dlList->insertAtFront(dllNode);

			set2ndAppDataInDllNode();
			dlList->insertAtFront(dllNode2);

			dlList->removeNode(dllNode2);

			Assert::IsTrue(dlList->getHeadPtr() == dllNode, L"head not last node");
			Assert::IsTrue(dlList->getTailPtr() == dllNode, L"Tail not last node");
			Assert::IsTrue(dllNode->prevNode == nullptr, L"last node prev not null");
			Assert::IsTrue(dllNode->nextNode == nullptr, L"last node next not null");
		}
		TEST_METHOD(TestDoubleLinkedListremoveLastNodeFromListOf2)
		{
			setAppDataInDllNode();
			dlList->insertAtFront(dllNode);

			set2ndAppDataInDllNode();
			dlList->insertAtFront(dllNode2);

			dlList->removeNode(dllNode);

			Assert::IsTrue(dlList->getHeadPtr() == dllNode2, L"head not last node");
			Assert::IsTrue(dlList->getTailPtr() == dllNode2, L"Tail not last node");
			Assert::IsTrue(dllNode2->prevNode == nullptr, L"last node prev not null");
			Assert::IsTrue(dllNode2->nextNode == nullptr, L"last node next not null");
		}
	};
}
