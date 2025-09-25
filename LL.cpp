#include "LL.h"

template <class type>
typename LL<type>::iterator LL<type>::iterator::operator++(int)
{
    iterator current(position);
    position = position->next;
    return current;
}

template <class type>
typename LL<type>::iterator LL<type>::iterator::operator++()
{
    position = position->next;
    return *this;
}

template <class type>
typename LL<type>::iterator LL<type>::iterator::operator--(int)
{
    iterator current(position);
    position = position->prev;
    return current;
}

template <class type>
typename LL<type>::iterator LL<type>::iterator::operator--()
{
    position = position->prev;
    return *this;
}

template <class type>
LL<type>::LL() {
    dummy = new node;
    dummy->next = dummy;
    dummy->prev = dummy;
}

template <class type>
LL<type>::LL(const LL<type>& copy) {
    dummy = new node;
    dummy->next = dummy;
    dummy->prev = dummy;
    copyList(copy);
}

template <class type>
const LL<type>& LL<type>::operator=(const LL<type>& rhs) {
    if (this != &rhs) {
        clearList();
        copyList(rhs);
    }
    return *this;
}

template <class type>
LL<type>::~LL() {
    clearList();
    delete dummy;
}

template <class type>
void LL<type>::headInsert(const type& item) {
    node* newNode = new node;
    newNode->item = item;
    newNode->next = dummy->next;
    newNode->prev = dummy;
    dummy->next->prev = newNode;
    dummy->next = newNode;
}

template <class type>
void LL<type>::tailInsert(const type& item) {
    node* newNode = new node;
    newNode->item = item;
    newNode->next = dummy;
    newNode->prev = dummy->prev;
    dummy->prev->next = newNode;
    dummy->prev = newNode;
}

template <class type>
void LL<type>::headRemove() {
    if (dummy->next == dummy) return;
    node* toDelete = dummy->next;
    dummy->next = toDelete->next;
    toDelete->next->prev = dummy;
    delete toDelete;
}

template <class type>
void LL<type>::tailRemove() {
    if (dummy->prev == dummy) return;
    node* toDelete = dummy->prev;
    dummy->prev = toDelete->prev;
    toDelete->prev->next = dummy;
    delete toDelete;
}

template <class type>
void LL<type>::removeAtPosition(LL<type>::iterator& it) {
    node* pos = it.position;
    if (pos == dummy) return;
    node* nextNode = pos->next;
    pos->prev->next = pos->next;
    pos->next->prev = pos->prev;
    delete pos;
    it.position = nextNode;
}

template <class type>
void LL<type>::clearList() {
    while (dummy->next != dummy) {
        headRemove();
    }
}

template <class type>
void LL<type>::copyList(const LL<type>& copyThisList) {
    for (node* cur = copyThisList.dummy->next; cur != copyThisList.dummy; cur = cur->next) {
        tailInsert(cur->item);
    }
}