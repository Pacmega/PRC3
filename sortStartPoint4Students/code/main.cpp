#include <iostream>

#include "FileStructure.h"
#include "Key.h"
/* Sources:
https://www.youtube.com/watch?v=jOyYaBHyN28
https://stackoverflow.com/questions/5630994/merge-sorting-a-linked-list
*/

typedef struct Key * KeyPtr;

// This method releases the nextValue of the key from the linked list:  Current->Next(This one goes out)->After
template <typename T>
T * Split(T * itemToSplit)
{
    T * tmpKey;
    if (itemToSplit == NULL)                                             // If the key is NULL, there is nothing to be done
        return NULL;
    else 
        if (itemToSplit->getNext() == NULL)                              // If the next pointer is NULL, there is nothing to be done either
            return NULL;
    else                                                                // There is a pointer for the next key
    {
        tmpKey = itemToSplit->getNext();                                 // Set the temporary key to be the next key of the key in question
        itemToSplit->setNext(tmpKey->getNext());                         // Set the next key, of the key in question, to be the next key of the temporary key
        tmpKey->setNext(Split(tmpKey->getNext()));                      // Do this move over and over to make sure the order stays correct
        return tmpKey;                                                  // Finally, return the tmpKey
    }
}

// This method checks if the keys are in the correct spot and moves them depending on the alphabetical order
template <typename T>
T * Merge(T * firstItem, T * secondItem)
{
    if (firstItem == NULL)
        return secondItem;
    else if(secondItem == NULL)
        return firstItem;
    else if (firstItem->getText().compare(secondItem->getText()) < 0)     // If the firstItem has a textvalue that should be earlier in the alphabetical order:
    {
        firstItem->setNext(Merge(firstItem->getNext(), secondItem));       // setNext on the next key that should be after it in alphabetical order.
        (firstItem->getNext())->setPrev(firstItem);
        return firstItem;                                                // Finally, return the firstItem
    }
    else
    {
        T * tmpKey = firstItem->getPrev();
        secondItem->setNext(Merge(firstItem, secondItem->getNext()));      // If the secondItem should be in front of the firstItem, it will move the other keys aswell

        firstItem->setPrev(secondItem);
        secondItem->setPrev(tmpKey);

        return secondItem;                                               // Finally, return the secondItem
    }
}

// This method uses both methods above to sort a linked list of keys in alphabetical order.
template <typename T>
T * mergeSort(T **keyToSort)
{
    // std::cout << "Entering mergesort" << std::endl;
    T * head = *keyToSort;
    T * tmpKey;
    // std::cout << "if" << std::endl;
    if (head == NULL || head->getNext() == NULL)                         // If the key or the next key is NULL, there is nothing to sort.
        return head; 
    else
    {
        tmpKey = Split(head);                                      // Split the keys into smaller groups
        return Merge(mergeSort(&head), mergeSort(&tmpKey));                 // Merge those keys again
    }
}

int main()
{
    FileStructure f;
    Key * head = new Key();
    
    f.loadFile("data/gibberish.bin", *head);
    
    // next line is only to show what kind of data we're working with
    // remove this line to increase performance!
    
    /*
    head->addValue("Pannenkoek");
    head->addValue("Boter");
    head->addValue("Kaas");
    head->addValue("Eieren");
    head->addValue("Aardbei");
    head->addValue("Handelen");
    head->addValue("Aardappel");
    */
    
    head = mergeSort(&head);
    Key * tmp = head;

    while(tmp != NULL)
    {
        Value * value = tmp->getValuePtr();
        tmp->setValuePtr(mergeSort(&value));
        tmp = tmp->getNext();
    }
    
    // sort all data
    // todo: call your sort method(s) here!
    // save sorted data into a new file called sorted.bin
    f.saveFile(*head, "sorted.bin");

    delete head;
    head = NULL;
    delete tmp;
    tmp = NULL;
    
    return 0;
}
