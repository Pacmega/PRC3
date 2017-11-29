#include <iostream>
#include <stdlib.h>
#include <string.h>

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
    	// // std::cout << "Getting word: " << word << std::endl;
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
    	// // std::cout <<	 "Getting item at position " << position << std::endl;

        if (position >= 0 && position <= nrOfElements())
        {
            item* temp = head;

            for(int i = 0; i < position; i++)
            {
            	// std::cout << i << std::endl;
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
                // std::cout << "Head is being set. \nBefore change:" << head->getWord() << std::endl;
                itemA->setNext(head);
                head->setPrev(itemA);
                setHead(itemA);
                // std::cout << "After change:" << head->getWord() << std::endl;
            }
            else if (itemA == tail)
            {
            	// std::cout << "Item being added as tail." << std::endl;
            	// std::cout << "Tail is being set. \nBefore change:" << tail->getWord() << std::endl;
            	tail->setNext(itemA);
                itemA->setPrev(tail);
                setTail(itemA);
                // std::cout << "After change:" << tail->getWord() << std::endl;
            }
            else if (itemA->getWord() == itemB->getWord())
            {
            	// std::cout << "Trying to swap item with item of the same name." << std::endl;
            }
            else
            {
            	// std::cout << "Items being swapped in the middle of the list." << std::endl;
                
                // std::cout << "Items that should be swapped:\nItem 1 - " << itemA->getWord() << "\nItem 2 - " << itemB->getWord() << std::endl;

                // std::cout << "Printing A LOT" << std::endl;

                // std::cout << itemA->getPrev()->getWord() << std::endl;
                // std::cout << itemA->getWord() << std::endl;
                // std::cout << itemB->getWord() << std::endl;
                // std::cout << itemB->getNext()->getWord() << std::endl;

                // Change the next and previous of the items AROUND the swapped items
                // itemA->getPrev()->setNext(itemB);
                // itemB->getNext()->setPrev(itemA);

                itemA->setNext(itemB->getNext());
                itemB->setNext(itemA);
                // itemB->setPrev(itemA->getPrev());
                // itemA->setPrev(itemB);

                // std::cout << "Items that should be swapped now:\nItem 1 - " << itemA->getWord() << "\nItem 2 - " << itemB->getWord() << std::endl;
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
            // std::cout << temp->getWord() << std::endl;
            temp = temp->getNext();
        }

        return elements;
    }
};

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

void bubbleSort(List &list, int elements)
{
    item* temp = NULL;

    for (int j = 0; j < elements; j++)
    {
        for (int i = 1; i < elements - j; i++)
        {
            if(list.getItemAtPos(i-1)->getWord().compare(list.getItemAtPos(i)->getWord()) > 0)
            {
                // std::cout << "What" << std::endl;
                temp = list.getItemAtPos(i);
                list.swapItems(list.getItemAtPos(i), list.getItemAtPos(i-1));
                list.swapItems(list.getItemAtPos(i-1), temp);
            }
        }
    }
}

int main(void)
{
    List* list = new List();
    populateList(*list);

    // Debugging: check how many items the List contains
    // // std::cout << "Number of elements in List: " << list->nrOfElements() << std::endl;

    // printEntireList(*list);
    bubbleSort(*list, list->nrOfElements());
    // printEntireList(*list);
    // topDownMergesort(*list, list->nrOfElements());
}