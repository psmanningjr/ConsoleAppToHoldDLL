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