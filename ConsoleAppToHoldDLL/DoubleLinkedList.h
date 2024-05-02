#pragma once
#include <memory>
#include "../ConsoleAppToHoldDLL/DoubleLinkedListNode.h"

class DoubleLinkedList
{
protected:
	std::shared_ptr <DoubleLinkedListNode> head;
	std::shared_ptr <DoubleLinkedListNode> tail;

public:
	std::shared_ptr <DoubleLinkedListNode> getHeadPtr();
	std::shared_ptr <DoubleLinkedListNode> getTailPtr();
	void insertAtFront(std::shared_ptr <DoubleLinkedListNode> newNode);
	void insertAtEnd(std::shared_ptr <DoubleLinkedListNode> newNode);
	void insertBeforeNode(std::shared_ptr <DoubleLinkedListNode> beforeThisNode,
	                      std::shared_ptr <DoubleLinkedListNode> newNode);
	void insertAfterNode(std::shared_ptr <DoubleLinkedListNode> afterThisNode,
		std::shared_ptr <DoubleLinkedListNode> newNode);
};

