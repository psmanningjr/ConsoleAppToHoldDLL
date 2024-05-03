#pragma once
#include "ApplicationData.h"

class DoubleLinkedListNode
{
public:
	std::shared_ptr <ApplicationData> appData;
	std::shared_ptr <DoubleLinkedListNode> prevNode;
	std::shared_ptr <DoubleLinkedListNode> nextNode;

};

