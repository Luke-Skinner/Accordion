#include "LL.h"
#include "LL.cpp"
#include "myStack.h"
#include "myStack.cpp"
#include <iostream>
#include <string>
using namespace std;

bool collapseCards(LL< myStack<string> >& accordian, LL< myStack<string> >::iterator it) {
    LL< myStack<string> >::iterator left3 = it;
    for (int i = 0; i < 3 && left3 != accordian.begin(); ++i) left3--;
    if (it != accordian.begin() && left3 != it) {
        string top = (*it).peek();
        string leftTop = (*left3).peek();
        if (top[0] == leftTop[0] || top[1] == leftTop[1]) {
            (*left3).push((*it).pop());
            if ((*it).isEmpty()) {
                LL< myStack<string> >::iterator toRemove = it;
                it++;
                accordian.removeAtPosition(toRemove);
            }
            return true;
        }
    }
    if (it != accordian.begin()) {
        LL< myStack<string> >::iterator left1 = it;
        left1--;
        string top = (*it).peek();
        string leftTop = (*left1).peek();
        if (top[0] == leftTop[0] || top[1] == leftTop[1]) {
            (*left1).push((*it).pop());
            if ((*it).isEmpty()) {
                LL< myStack<string> >::iterator toRemove = it;
                it++;
                accordian.removeAtPosition(toRemove);
            }
            return true;
        }
    }
    return false;
}

int main()
{
    string card;
    LL< myStack<string> > accordian;
    while (cin >> card) {
        myStack<string> singleCardStack;
        singleCardStack.push(card);
        accordian.tailInsert(singleCardStack);
    }

    bool moved = true;
    while (moved) {
        moved = false;
        LL< myStack<string> >::iterator it = accordian.begin();
        while (it != accordian.end()) {
            if (collapseCards(accordian, it)) {
                moved = true;
                break;
            }
            it++;
        }
    }

    size_t count = 0;
    LL< myStack<string> >::iterator it;
    for (it = accordian.begin(); it != accordian.end(); it++){
        count++;
    }
    cout << count << (count == 1 ? " Stack : " : " Stacks : ");
    bool first = true;
    for (it = accordian.begin(); it != accordian.end(); it++) {
        if (!first) cout << " ";
        cout << (*it).peek() << ":" << (*it).getSize();
        first = false;
    }
    cout << endl;
    return 0;
}