#include <iostream>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>

class item
{
private:
    item* next;
    item* prev;
    std::string word;

public:
    item(std::string Word)
    {
        word = Word;
        next = NULL;
        prev = NULL;
    }

    std::string getWord()
    {
    	// std::cout << "Getting word: " << word << std::endl;
        return word;
    }

    void setWord(std::string newWord)
    {
        word = newWord;
    }

    item* getNext()
    {
        return next;
    }

    void setNext(item* newNext)
    {
        if (newNext != NULL && newNext != this)
        {
            next = newNext;
        }
    }

    item* getPrev()
    {
        return prev;
    }

    void setPrev(item* newPrev)
    {
        if (newPrev != NULL && newPrev != this)
        {
            prev = newPrev;
        }
    }
};

class List
{
private:
    item* head;
    item* tail;

public:
    List()
    {
        head = NULL;
        tail = NULL;
    }

    item* getHead()
    {
        return head;
    }

    void setHead(item* newHead)
    {
        if(newHead != NULL && newHead != head)
        {
        	if (head != NULL)
        	{
        		newHead->setNext(head);
        		head->setPrev(newHead);
        	}

            head = newHead;
        }
    }

    item* getTail()
    {
        return tail;
    }

    void setTail(item* newTail)
    {
        if(newTail != NULL && newTail != tail)
        {
            tail = newTail;
        }
    }

    item* getItemAtPos (int position)
    {
    	// std::cout <<	 "Getting item at position " << position << std::endl;

        if (position >= 0 && position <= nrOfElements())
        {
            item* temp = head;

            for(int i = 0; i < position; i++)
            {
            	std::cout << i << std::endl;
                temp = temp->getNext();
            }

            return temp;
        }
        else
        {
            return NULL;
        }
    }

    void swapItems(item* itemA, item* itemB)
    {
        if (itemA != NULL && itemB != NULL)
        {
        	if (itemA == head)
            {
                // Attempting to set head.
                std::cout << "Head is being set. \nBefore change:" << head->getWord() << std::endl;
                itemA->setNext(head);
                head->setPrev(itemA);
                setHead(itemA);
                std::cout << "After change:" << head->getWord() << std::endl;
            }
            else if (itemA == tail)
            {
            	std::cout << "Item being added as tail." << std::endl;
            	std::cout << "Tail is being set. \nBefore change:" << tail->getWord() << std::endl;
            	tail->setNext(itemA);
                itemA->setPrev(tail);
                setTail(itemA);
                std::cout << "After change:" << tail->getWord() << std::endl;
            }
            else if (itemA->getWord() == itemB->getWord())
            {
            	std::cout << "Trying to swap item with item of the same name." << std::endl;
            }
            else
            {
            	std::cout << "Items being swapped in the middle of the list." << std::endl;
                
                std::cout << "Items that should be swapped:\nItem 1 - " << itemA->getWord() << "\nItem 2 - " << itemB->getWord() << std::endl;

                std::cout << "Printing A LOT" << std::endl;

                std::cout << itemA->getPrev()->getWord() << std::endl;
                std::cout << itemA->getWord() << std::endl;
                std::cout << itemB->getWord() << std::endl;
                std::cout << itemB->getNext()->getWord() << std::endl;

                sleep(5);
                // Change the next and previous of the items AROUND the swapped items
                // itemA->getPrev()->setNext(itemB);
                itemB->getNext()->setPrev(itemA);

                itemA->setNext(itemB->getNext());
                itemB->setNext(itemA);
                // itemB->setPrev(itemA->getPrev());
                itemA->setPrev(itemB);

                std::cout << "Items that should be swapped now:\nItem 1 - " << itemA->getWord() << "\nItem 2 - " << itemB->getWord() << std::endl;
            }
        }
    }

    void addItem(std::string word)
    {
        if(head == NULL)
        {
            item* object = new item(word);
            head = object;
            tail = object;
            return;
        }
        else
        {
            item* object = new item(word);
            tail->setNext(object);
            object->setPrev(tail);
            tail = object;
            return;
        }
    }

    int nrOfElements()
    {
        int elements = 0;

        item* temp = head;

        while (temp != NULL)
        {
            elements++;
            std::cout << temp->getWord() << std::endl;
            temp = temp->getNext();
        }

        return elements;
    }
};

void printEntireList(List &ItemList)
{
	std::cout << ItemList.nrOfElements() << std::endl;
	for (int i = 0; i < ItemList.nrOfElements(); ++i)
	{
		std::cout << "Item at position " << i << " of list: " << ItemList.getItemAtPos(i)->getWord() << std::endl;
	}
}

void merge(List &ItemList, int Begin, int Middle, int End, List &sortedList)
{
    // Bas
    // Thanks to https://en.wikipedia.org/wiki/Merge_sort for helping with programming this

    std::cout << "Contents of ItemList: " << std::endl;
    printEntireList(ItemList);
 
    // Note that all of the variable that start with a capital letter were parameters, while ones without a capital are local variables.
    
    for (int i = Begin; i < End; i++)
    {
    	std::cout << "For loop" << std::endl;

        if (Begin < Middle && (Middle >= End || ItemList.getItemAtPos(Begin)->getWord().compare(ItemList.getItemAtPos(Middle)->getWord()) <= 0))
        {
        	std::cout << "If" << std::endl;
        	std::cout << "Item at pos to change: " << sortedList.getItemAtPos(i)->getWord();
        	sortedList.swapItems(ItemList.getItemAtPos(i), ItemList.getItemAtPos(Begin));
        	std::cout << "Item at pos after change: " << sortedList.getItemAtPos(i)->getWord();
            // B[i] = A[begin];
            Begin++;
        }
        else
        {
        	std::cout << "Else" << std::endl;
        	sortedList.swapItems(ItemList.getItemAtPos(i), ItemList.getItemAtPos(Middle));
            // B[i] = A[middle];
            Middle++;
        }
    }
}

void splitMerge(List &array, int begin, int end, List &sortedList)
{
    if (begin < end)
    {
        // Same as (begin+end)/2, but avoids overflow for
        // large l and h
        int middle = begin+(end-begin)/2;

        // splitMerge first and second halves
        std::cout << "splitMerge called" << std::endl;
        splitMerge(array, begin, middle, sortedList);

        std::cout << "splitMerge called" << std::endl;
        splitMerge(array, middle+1, end, sortedList);

        // Array is split up into units of 1

        std::cout << "Merge called" << std::endl;
        merge(sortedList, begin, middle, end, array);

		std::cout << "Contents of sortedList" << std::endl;
		printEntireList(sortedList);
    }
}

void populateList(List &List)
{
    List.addItem("zaterdag");
    List.addItem("zondag");
    List.addItem("maandag");
    List.addItem("dinsdag");
    List.addItem("woensdag");
    List.addItem("donderdag");
    List.addItem("vrijdag");
    List.addItem("school");
    List.addItem("laptop");
    List.addItem("pc master race");
}

void deepCopy(List &ListToCopy, List &newList, int elements)
{
    for(int i = 0; i < elements; i++)
    {
        item* temp = ListToCopy.getHead();

        for(int placeInList = 0; placeInList < i; placeInList++)
        {
            if (temp != NULL)
            {
                temp = temp->getNext();
            }
        }

        if (temp != NULL)
        {
            newList.addItem(temp->getWord());
        }
        else
        {
            std::cout << "Temp == NULL? But how?" << std::endl;
        }
    }
}

void topDownMergesort(List &toSplitMerge, int elements)
{
    List* workingList = new List();
    deepCopy(toSplitMerge, *workingList, elements);

    // Arguments: list to sort, start position of the list
    // (0 normally, gets changed during recursion) and the initial end position of the list
    // SplitMerge changes the list in place, so toSplitMerge is sorted after this function.
    splitMerge(toSplitMerge, 0, elements, *workingList);
}

int main(void)
{
    List* list = new List();
    populateList(*list);

    // Debugging: check how many items the List contains
    std::cout << "Number of elements in List: " << list->nrOfElements() << std::endl;

    topDownMergesort(*list, list->nrOfElements());
}