#pragma once
#include "ApplicationData.h"

class DoubleLinkedListNode
{
private:
	std::shared_ptr <ApplicationData> appData;

public:
	void setAppData(std::shared_ptr <ApplicationData> appDataPtr);
	std::shared_ptr <ApplicationData> getAppData();
};

