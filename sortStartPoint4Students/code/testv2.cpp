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
        if (position >= 0 && position <= nrOfElements())
        {
            item* temp = head;

            for(int i = 0; i < position; i++)
            {
                temp = temp->getNext();
            }

            return temp;
        }
        else
        {
            return NULL;
        }
    }

    void setItemAtPos(int position, item* newItem)
    {
        if (position >= 0 && position <= nrOfElements() && newItem != NULL)
        {
            //heh
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
            temp = temp->getNext();
        }

        return elements;
    }
};

void merge(List &ItemList, int Begin, int Middle, int End, List &sortedList)
{
    // Bas
    // Thanks to https://en.wikipedia.org/wiki/Merge_sort for helping with programming this
    int begin = Begin;
    int middle = Middle;
 
    // Note that all of the variable that start with a capital letter were parameters, while ones without a capital are local variables.
    
    for (int i = Begin; i < End; i++)
    {
        if (begin < Middle && (middle >= End || ItemList.getItemAtPos(begin)->getWord().compare(ItemList.getItemAtPos(middle)->getWord()) <= 0))
        {
            B[i] = A[begin];
            begin++;
        }
        else
        {
            B[i] = A[middle];
            middle++;
        }
    }

    // Joran
    // int i, j, k;
    // int n1 = m - l + 1;
    // int n2 = r - m;

    // // Create temporary lists (LS = LeftSide)(RS = RightSide)

    // List LS, RS;

    // // Copy the data to the lists
    // for (i = 0; i < n1; ++i)
    // {
    //     LS[i] = ItemList[l + i];
    // }
    // for (j = 0; j < n2; ++j)
    // {
    //     RS[j] = ItemList[m + 1 + j];
    // }

    // // Merge the temorary lists back into the original list
    // i = 0; // Initial index of first sub-list
    // j = 0; // Initial index of second sub-list
    // k = 1; // Initial index of merged sub-list

    // while(i < n1 && j < n2)
    // {
    //     if (strcmp(LS[i].word, RS[j].word) <= 0)
    //     {
    //         ItemList[k] = LS[i]
    //         i++;
    //     }
    //     else
    //     {
    //         ItemList[k] = RS[j];
    //         j++;
    //     }
    //     k++;
    // }

    // // Copy the remaining items from RS (if any)
    // while(i < n1)
    // {
    //     ItemList[k] = LS[i];
    //     i++;
    //     k++;
    // }

    //     // Copy the remaining items from RS (if any)
    // while(j < n2)
    // {
    //     ItemList[k] = RS[j];
    //     j++;
    //     k++;
    // }
}

void splitMerge(List &array, int begin, int end, List &sortedList)
{
    if (begin < end)
    {
        // Same as (begin+end)/2, but avoids overflow for
        // large l and h
        int middle = begin+(end-begin)/2;

        // splitMerge first and second halves
        splitMerge(array, begin, middle, sortedList);
        splitMerge(array, middle+1, end, sortedList);

        // Array is split up into units of 1

        merge(array, begin, middle, end, sortedList);
    }
}

void populateList(List &List)
{
    List.addItem((std::string)"zaterdag");
    List.addItem((std::string)"zondag");
    List.addItem((std::string)"maandag");
    List.addItem((std::string)"dinsdag");
    List.addItem((std::string)"woensdag");
    List.addItem((std::string)"donderdag");
    List.addItem((std::string)"vrijdag");
    List.addItem((std::string)"school");
    List.addItem((std::string)"laptop");
    List.addItem((std::string)"pc master race");
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
    // std::cout << "Number of elements in List: " << List->nrOfElements() << std::endl;

    topDownMergesort(*list, list->nrOfElements());
}