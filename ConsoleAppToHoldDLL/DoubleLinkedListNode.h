#pragma once
#include "ApplicationData.h"

class DoubleLinkedListNode
{
private:
	std::shared_ptr <ApplicationData> appData;
	std::shared_ptr <DoubleLinkedListNode> prevNode;
	std::shared_ptr <DoubleLinkedListNode> nextNode;

public:
	void setAppData(std::shared_ptr <ApplicationData> appDataPtr);
	std::shared_ptr <ApplicationData> getAppData();

	void setNextNode(std::shared_ptr <DoubleLinkedListNode> nextNodePtr);
	std::shared_ptr <DoubleLinkedListNode> getNextNode();

	void setPrevNode(std::shared_ptr <DoubleLinkedListNode> prevNodePtr);
	std::shared_ptr <DoubleLinkedListNode> getprevNode();
};

