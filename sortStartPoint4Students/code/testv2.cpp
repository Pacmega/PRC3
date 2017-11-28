#include <iostream>
#include <stdlib.h>
#include <string.h>

class item
{
private:
    item* next;
    item* prev;
    char* word;

public:
    item(char * Word)
    {
        word = Word;
        next = NULL;
        prev = NULL;
    }

    char* getWord()
    {
        return word;
    }

    char* setWord(char* newWord)
    {
        word = newWord;
    }

    item* getNext()
    {
        return next;
    }

    item* setNext(item* newNext)
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

    item* setPrev(item* newPrev)
    {
        if (newPrev != NULL && newPrev != this)
        {
            prev = newPrev;
        }
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

    item* getItemAtPos (int position)
    {
        if (position >= 0 && position <= nrOfElements)
        {
            item* temp = head;

            for(int i = 0; i < position; i++)
            {
                temp = temp.getNext();
            }

            return temp;
        }
        else
        {
            return NULL;
        }
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

void merge(List &ItemList, int Begin, int Middle, int End, List &sortedList)
{
    // Bas
    // Thanks to https://en.wikipedia.org/wiki/Merge_sort for helping with programming this
    int begin = Begin;
    int middle = Middle;
 
    // Note that all of the variable that start with a capital letter were parameters, while ones without a capital are local variables.
    
    for (int i = Begin; i < End; i++)
    {
        if (begin < Middle && (middle >= End || ItemList.getItem(begin).compare(ItemList.getItem(middle)) <= 0))
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
        splitMerge(array, begin, middle);
        splitMerge(array, middle+1, end);

        // Array is split up into units of 1

        merge(array, begin, middle, end, sortedList);
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

void deepCopy(List &ListToCopy, List &newList, int elements)
{
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
    List* workingList = new List();
    deepCopy(toSplitMerge, *workingList, elements);

    // Arguments: list to sort, start position of the list
    // (0 normally, gets changed during recursion) and the initial end position of the list
    // SplitMerge changes the list in place, so toSplitMerge is sorted after this function.
    splitMerge(toSplitMerge, 0, elements, workingList);
}

int main(void)
{
    List* list = new List();
    populateList(*list);

    // Debugging: check how many items the List contains
    // std::cout << "Number of elements in List: " << List->nrOfElements() << std::endl;

    topDownMergesort(*list, list->nrOfElements());
}