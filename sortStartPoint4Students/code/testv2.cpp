#include <iostream>
#include <stdlib.h>

class item
{
public:
    item* next;
    item* prev;
    char* word;

    item(char * Word)
    {
        word = Word;
        next = NULL;
        prev = NULL;
    }
};

class List
{
public:
    item* head;
    item* tail;

    List()
    {
        head = NULL;
        tail = NULL;
    }

    void addItem (char * word)
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
            tail->next = object;
            object->prev = tail;
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
            temp = temp->next;
        }

        return elements;
    }
};

void merge()
{
    std::cout << "Wait for 3 days, or pay $1 to sort your list now!" << std::endl;
}

void splitMerge(List &array, int begin, int end)
{
    if (begin < end)
    {
        // Same as (begin+end)/2, but avoids overflow for
        // large l and h
        int middle = begin+(end-begin)/2;

        // splitMerge first and second halves
        splitMerge(array, begin, middle);
        splitMerge(array, middle+1, end);

        // Array is split up into units of 1

        merge();
        // Are these args correct?
        // merge(array, begin, middle, end);
    }
}

void populateList(List &List)
{
    List.addItem((char*)"zaterdag");
    List.addItem((char*)"zondag");
    List.addItem((char*)"maandag");
    List.addItem((char*)"dinsdag");
    List.addItem((char*)"woensdag");
    List.addItem((char*)"donderdag");
    List.addItem((char*)"vrijdag");
    List.addItem((char*)"school");
    List.addItem((char*)"laptop");
    List.addItem((char*)"pc master race");
}

List* deepCopy(List &ListToCopy, int elements)
{
    List* newList = new List();

    for(int i = 0; i < elements; i++)
    {
        item* temp = ListToCopy.head;

        for(int placeInList = 0; placeInList < i; placeInList++)
        {
            if (temp != NULL)
            {
                temp = temp->next;
            }
        }

        if (temp != NULL)
        {
            newList->addItem(temp->word);
        }
        else
        {
            std::cout << "Temp == NULL? But how?" << std::endl;
        }
        
    }
}

void topDownMergesort(List &toSplitMerge, int elements)
{
    List* workingList = deepCopy(toSplitMerge, elements);

    // Arguments: list to sort, start position of the list
    // (0 normally, gets changed during recursion) and the initial end position of the list
    // SplitMerge changes the list in place, so toSplitMerge is sorted after this function.
    splitMerge(toSplitMerge, 0, elements);
}

int main(void)
{
    List* list = new List();
    populateList(*list);

    // Debugging: check how many items the List contains
    // std::cout << "Number of elements in List: " << List->nrOfElements() << std::endl;

    topDownMergesort(*list, list->nrOfElements());
}