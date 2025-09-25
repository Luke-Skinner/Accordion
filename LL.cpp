/*
    Name: Luke Skinner, 2002053024, 1001, ASSIGNMENT_1
    Description: Implementation file for linked list class
    Input: Cards from input file
    Output: Varies by function linked list class variables
*/
#include "LL.h"

//Overloads the ++ operator for the iterator postfix
template <class type>
typename LL<type>::iterator LL<type>::iterator::operator++(int)
{
    //Creates a new iterator at the current position
	iterator current(position);
    //Moves the iterator to the next node
	position = position->next;
    //Returns the current iterator
	return current;
}

//Overloads the ++ operator for the iterator prefix
template <class type>
typename LL<type>::iterator LL<type>::iterator::operator++()
{

	position = position->next;

	return *this;
}

//Overloads the -- operator for the iterator postfix
template <class type>
typename LL<type>::iterator LL<type>::iterator::operator--(int)
{
	iterator current(position);
	position = position->prev;

	return current;
}

//Overloads the -- operator for the iterator prefix
template <class type>
typename LL<type>::iterator LL<type>::iterator::operator--()
{
	position = position->prev;

	return *this;
}

//Constructor for the linked list
template <class type>
LL<type>::LL() {
    //Creates a new dummy node
    dummy = new node;
    //Sets the next and prev pointers of the dummy node to itself
    dummy->next = dummy;
    dummy->prev = dummy;
}

//Copy constructor for the linked list
template <class type>
LL<type>::LL(const LL<type>& copy) {
    dummy = new node;
    dummy->next = dummy;
    dummy->prev = dummy;
    copyList(copy);
}

//Overloads the = operator for the linked list
template <class type>
const LL<type>& LL<type>::operator=(const LL<type>& rhs) {
    //Checks if the linked list is not the same as the rhs
	if (this != &rhs) {
        clearList();
        copyList(rhs);
    }
    //Returns the linked list
    return *this;
}

//Destructor for the linked list
template <class type>
LL<type>::~LL() {
    clearList();
    delete dummy;
}

//Inserts a new node at the head of the linked list
template <class type>
void LL<type>::headInsert(const type& item) {
    //Creates a new node
    node* newNode = new node;
    //Sets the item of the new node to the item passed in
    newNode->item = item;
    //Sets the next and prev pointers of the new node
    newNode->next = dummy->next;
    newNode->prev = dummy;
    dummy->next->prev = newNode;
    dummy->next = newNode;
}

//Inserts a new node at the tail of the linked list
template <class type>
void LL<type>::tailInsert(const type& item) {
    //Creates a new node
    node* newNode = new node;
    //Sets the item of the new node to the item passed in
    newNode->item = item;
    //Sets the next and prev pointers of the new node
    newNode->next = dummy;
    newNode->prev = dummy->prev;
    dummy->prev->next = newNode;
    dummy->prev = newNode;
}

//Removes the node at the head of the linked list
template <class type>
void LL<type>::headRemove() {
    //Checks if the head is the dummy node
	if (dummy->next == dummy) return;
    //Creates a new node to delete
    node* toDelete = dummy->next;
    //Sets the next pointer of the dummy node to the next node
    dummy->next = toDelete->next;
    //Sets the prev pointer of the next node to the dummy node
    toDelete->next->prev = dummy;
    delete toDelete;
}

//Removes the node at the tail of the linked list
template <class type>
void LL<type>::tailRemove() {
    //Checks if the tail is the dummy node
	if (dummy->prev == dummy) return;
	//Removes the node at the tail
    node* toDelete = dummy->prev;
    dummy->prev = toDelete->prev;
    toDelete->prev->next = dummy;
    delete toDelete;
}

//Removes the node at the position of the iterator
template <class type>
void LL<type>::removeAtPosition(LL<type>::iterator& it) {
    node* pos = it.position;
    //Checks if the position is the dummy node
	if (pos == dummy) return;
	//Removes the node at the position
    node* nextNode = pos->next;
    pos->prev->next = pos->next;
    pos->next->prev = pos->prev;
    delete pos;
    it.position = nextNode;
}

//Clears the linked list
template <class type>
void LL<type>::clearList() {
    //Removes the nodes from the linked list
	while (dummy->next != dummy) {
        headRemove();
    }
}

//Copies the linked list
template <class type>
void LL<type>::copyList(const LL<type>& copyThisList) {
    //Copies the linked list
	for (node* cur = copyThisList.dummy->next; cur != copyThisList.dummy; cur = cur->next) {
        tailInsert(cur->item);
    }
}