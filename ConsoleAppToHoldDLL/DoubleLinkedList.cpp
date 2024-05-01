#include "DoubleLinkedList.h"
void DoubleLinkedList::insertAtFront(std::shared_ptr <DoubleLinkedListNode> newNode) {
	head = newNode;
	if (tail == nullptr) {
		tail = newNode;
	}
}

void DoubleLinkedList::insertAtEnd(std::shared_ptr <DoubleLinkedListNode> newNode) {

}

