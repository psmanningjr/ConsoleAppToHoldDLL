#include "DoubleLinkedList.h"
#include "DoubleLinkedListNode.h"

std::shared_ptr <DoubleLinkedListNode> DoubleLinkedList::getHeadPtr() {
	return head;
}

std::shared_ptr <DoubleLinkedListNode> DoubleLinkedList::getTailPtr() {
	return tail;
}

void DoubleLinkedList::insertAtFront(std::shared_ptr <DoubleLinkedListNode> newNode) {
	newNode->nextNode = head;
	if (head != nullptr) {
		head->prevNode = newNode;
	}
	head = newNode;
	if (tail == nullptr) {
		tail = newNode;
	}
}

void DoubleLinkedList::insertAtEnd(std::shared_ptr <DoubleLinkedListNode> newNode) {
	if (head == nullptr && tail == nullptr) {
		head = newNode;
		tail = newNode;
	}
	else {
		if (tail != nullptr) {
			newNode->prevNode = tail;
			tail->nextNode = newNode;
			tail = newNode;
		}
	}

}

