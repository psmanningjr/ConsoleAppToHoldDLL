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

void DoubleLinkedList::insertBeforeNode(std::shared_ptr <DoubleLinkedListNode> beforeThisNode,
	std::shared_ptr <DoubleLinkedListNode> newNode) {
	if (beforeThisNode == head) {
		insertAtFront(newNode);
	}
	else {
		newNode->prevNode = beforeThisNode->prevNode;
		if (beforeThisNode->prevNode != nullptr) {
			beforeThisNode->prevNode->nextNode = newNode;
			beforeThisNode->prevNode = newNode;
		}
		newNode->nextNode = beforeThisNode;
	}
}

void DoubleLinkedList::insertAfterNode(std::shared_ptr <DoubleLinkedListNode> afterThisNode,
	std::shared_ptr <DoubleLinkedListNode> newNode) {
	if (afterThisNode == tail) {
		insertAtEnd(newNode);
	}
	else {
		newNode->prevNode = afterThisNode;
		if (afterThisNode->nextNode != nullptr) {
			newNode->nextNode = afterThisNode->nextNode;
			afterThisNode->nextNode->prevNode = newNode;
			afterThisNode->nextNode = newNode;
		}
	}
}
void DoubleLinkedList::removeNode(std::shared_ptr <DoubleLinkedListNode> removeNode) {
	if (removeNode != nullptr) {
		if (head == removeNode) {
			if (removeNode->nextNode != nullptr) {
				head = removeNode->nextNode;
			}
			else {
				head = nullptr;
				tail = nullptr;
			}
		}
		else {
			if (tail == removeNode) {
				if (tail->prevNode != nullptr) {
					tail->prevNode->nextNode = nullptr;
					tail = tail->prevNode;
				}
			}
		}
		if (removeNode->prevNode != nullptr) {
			removeNode->prevNode->nextNode = removeNode->nextNode;
		}
		if (removeNode->nextNode != nullptr) {
			removeNode->nextNode->prevNode = removeNode->prevNode;
		}
	}
}