/*
    Name: Luke Skinner, 2002053024, 1001, ASSIGNMENT_1
    Description: Main file for Accordian Patience
    Input: Cards from input file
    Output: Number of stacks and the stacks
*/
#include "LL.h"
#include "LL.cpp"
#include "myStack.h"
#include "myStack.cpp"
#include <iostream>
#include <string>
using namespace std;

//Function to collapse cards
bool collapseCards(LL< myStack<string> >& accordian, LL< myStack<string> >::iterator it) {
    //Checks if there are 3 cards to the left
    LL< myStack<string> >::iterator left3 = it;
	//Moves the iterator 3 cards to the left
    for (int i = 0; i < 3 && left3 != accordian.begin(); ++i) left3--;
	//Checks if the top card of the current stack matches the top card of the 3 cards to the left
    if (it != accordian.begin() && left3 != it) {
        string top = (*it).peek();
        string leftTop = (*left3).peek();
        if (top[0] == leftTop[0] || top[1] == leftTop[1]) {
            (*left3).push((*it).pop());
			//Checks if the current stack is empty
            if ((*it).isEmpty()) {
                LL< myStack<string> >::iterator toRemove = it;
                it++;
                accordian.removeAtPosition(toRemove);
            }
            return true;
        }
    }
    //Checks if there is 1 card to the left
    if (it != accordian.begin()) {
        LL< myStack<string> >::iterator left1 = it;
		//Moves the iterator 1 card to the left
        left1--;
		//Checks if the top card of the current stack matches the top card of the 1 card to the left
        string top = (*it).peek();
        string leftTop = (*left1).peek();
		//Checks if the top card of the current stack matches the top card of the 1 card to the left
        if (top[0] == leftTop[0] || top[1] == leftTop[1]) {
            (*left1).push((*it).pop());
			//Checks if the current stack is empty
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

//Main function of Accordian Patience
int main()
{
    // Reads cards from input creating a stack for each, and inserts them into the linked list
    string card;
    LL< myStack<string> > accordian;
	//Reads cards from input creating a stack for each and inserts them into the linked list
    while (cin >> card) {
        myStack<string> singleCardStack;
        singleCardStack.push(card);
        accordian.tailInsert(singleCardStack);
    }

	//Boolean to check if a move was made
    bool moved = true;
	//While a move was made keeps moving cards until no more moves are made
    while (moved) {
        moved = false;
        LL< myStack<string> >::iterator it = accordian.begin();
        while (it != accordian.end()) {
            if (collapseCards(accordian, it)) {
                moved = true;
                break; // Only one move per pass and restarts from leftmost
            }
            it++;
        }
    }

    //Counts the number of stacks and prints them
    size_t count = 0;
    LL< myStack<string> >::iterator it;
	//Counts the number of stacks
    for (it = accordian.begin(); it != accordian.end(); it++){
		count++;
	}
    cout << count << (count == 1 ? " Stack : " : " Stacks : ");
    bool first = true;
	//Prints the stacks
    for (it = accordian.begin(); it != accordian.end(); it++) {
		//Checks if it is not the first stack
        if (!first) cout << " ";
        cout << (*it).peek() << ":" << (*it).getSize();
        first = false;
    }
    cout << endl;
    return 0;
}