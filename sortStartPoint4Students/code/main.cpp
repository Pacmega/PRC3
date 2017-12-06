#include <iostream>

#include "FileStructure.h"
#include "Key.h"
/* Sources:
https://www.youtube.com/watch?v=jOyYaBHyN28
https://stackoverflow.com/questions/5630994/merge-sorting-a-linked-list
*/

typedef struct Key * KeyPtr;

KeyPtr mergeSort(KeyPtr *keyToSort);
KeyPtr Merge(KeyPtr firstKey, KeyPtr secondKey);
KeyPtr Split(KeyPtr keyToSplit);

int main()
{
    FileStructure f;
    Key * head = new Key();
    
    // f.loadFile("data/gibberish.bin", *head);
    
    // next line is only to show what kind of data we're working with
    // remove this line to increase performance!

    head->addValue("Pannenkoek");
    head->addValue("Boter");
    head->addValue("Kaas");
    head->addValue("Eieren");
    head->addValue("Aardbei");
    head->addValue("Handelen");
    head->addValue("Aardappel");
    
    mergeSort(&head);

    head->print();
    // sort all data
    // todo: call your sort method(s) here!

    // save sorted data into a new file called sorted.bin
    f.saveFile(*head, "sorted.bin");
    
    return 0;
}

// This method releases the nextValue of the key from the linked list:  Current->Next(This one goes out)->After
KeyPtr Split(KeyPtr keyToSplit)
{
    // std::cout << "Splitting" << std::endl;
    KeyPtr tmpKey;
    // std::cout << "if" << std::endl;
    if (keyToSplit == NULL)                                             // If the key is NULL, there is nothing to be done
        return NULL;
    else 
        if (keyToSplit->getNext() == NULL)                              // If the next pointer is NULL, there is nothing to be done either
            return NULL;
    else                                                                // There is a pointer for the next key
    {
        // std::cout << "else" << std::endl;
        tmpKey = keyToSplit->getNext();                                 // Set the temporary key to be the next key of the key in question
        // std::cout << "keyToSplit->getNext() = " << tmpKey << std::endl;
        keyToSplit->setNext(tmpKey->getNext());                         // Set the next key, of the key in question, to be the next key of the temporary key
        tmpKey->setNext(Split(tmpKey->getNext()));                      // Do this move over and over to make sure the order stays correct
        // std::cout << "setNext(Split(tmpKey->getNext())) = " << tmpKey << std::endl;
        return tmpKey;                                                  // Finally, return the tmpKey
    }
}

// This method checks if the keys are in the correct spot and moves them depending on the alphabetical order
KeyPtr Merge(KeyPtr firstKey, KeyPtr secondKey)
{
    // std::cout << "Merging" << std::endl;
    if (firstKey == NULL)
        return secondKey;
    else if(secondKey == NULL)
        return firstKey;
    else if (firstKey->getText().compare(secondKey->getText()) < 0)     // If the firstKey has a textvalue that should be earlier in the alphabetical order:
    {
        // std::cout << "else if" << std::endl;
        firstKey->setNext(Merge(firstKey->getNext(), secondKey));       // setNext on the next key that should be after it in alphabetical order.
        return firstKey;                                                // Finally, return the firstKey
    }
    else
    {
        // std::cout << "else" << std::endl;
        // secondKey->setPrev(firstKey->getPrev());
        secondKey->setNext(Merge(firstKey, secondKey->getNext()));      // If the secondKey should be in front of the firstKey, it will move the other keys aswell
        return secondKey;                                               // Finally, return the secondKey
    }
}

// This method uses both methods above to sort a linked list of keys in alphabetical order.
KeyPtr mergeSort(KeyPtr *keyToSort)
{
    // std::cout << "Entering mergesort" << std::endl;
    KeyPtr head = *keyToSort;
    KeyPtr tmpKey;
    // std::cout << "if" << std::endl;
    if (head == NULL || head->getNext() == NULL)                         // If the key or the next key is NULL, there is nothing to sort.
        return head; 
    else
    {
        // std::cout << "else" << std::endl;
        tmpKey = Split(head);                                      // Split the keys into smaller groups
        return Merge(mergeSort(&head), mergeSort(&tmpKey));                 // Merge those keys again
    }
}