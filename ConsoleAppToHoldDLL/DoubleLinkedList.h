#pragma once
#include <memory>
#include "../ConsoleAppToHoldDLL/DoubleLinkedListNode.h"

class DoubleLinkedList
{
public:
	std::shared_ptr <DoubleLinkedListNode> head;
	std::shared_ptr <DoubleLinkedListNode> tail;

	void insertAtFront(std::shared_ptr <DoubleLinkedListNode>);
};

