#include "DoubleLinkedListNode.h"
#include "DoubleLinkedList.h"
#include "ApplicationData.h"

void DoubleLinkedListNode::setAppData(std::shared_ptr <ApplicationData> appDataPtr)
{
	appData = appDataPtr;

}

std::shared_ptr <ApplicationData> DoubleLinkedListNode::getAppData()
{
	return appData;
}

void DoubleLinkedListNode::setNextNode(std::shared_ptr <DoubleLinkedListNode> nextNodePtr) {

}

std::shared_ptr <DoubleLinkedListNode> DoubleLinkedListNode::getNextNode() {
	return nullptr;
}

void DoubleLinkedListNode::setPrevNode(std::shared_ptr <DoubleLinkedListNode> prevNodePtr) {

}

std::shared_ptr <DoubleLinkedListNode> DoubleLinkedListNode::getprevNode() {
	return nullptr;
}

