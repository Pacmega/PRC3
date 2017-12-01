#include <iostream>

#include "FileStructure.h"
#include "Key.h"

//https://stackoverflow.com/questions/5630994/merge-sorting-a-linked-list

Key* mergeSort(Key* keyToSort);
Key* Merge(Key* firstKey, Key* secondKey);
Key* Split(Key* keyToSplit);

int main()
{
    FileStructure f;
    Key head;
    
    f.loadFile("data/gibberish.bin", head);

    // next line is only to show what kind of data we're working with
    // remove this line to increase performance!

    /*
    head.addValue("Amandelen");
    head.addValue("Pannenkoek");
    head.addValue("Boter");
    head.addValue("Kaas");
    head.addValue("Eieren");
    head.addValue("Aardbei");
    head.addValue("Handelen");
    head.addValue("Aardappel");
    */

    std::cout << "After mergeSort" << std::endl;
    
    mergeSort(&head);

    head.print();
    // sort all data
    // todo: call your sort method(s) here!

    // save sorted data into a new file called sorted.bin
    f.saveFile(head, "sorted.bin");
    
    return 0;
}

// This method releases the nextValue of the key from the linked list:  Current->Next(This one goes out)->After
Key* Split(Key* keyToSplit)
{
    Key* tmpKey;

    if (keyToSplit == NULL)                                             // If the key is NULL, there is nothing to be done
        return NULL;
    else 
        if (keyToSplit->getNext() == NULL)                              // If the next pointer is NULL, there is nothing to be done either
            return NULL;
    else                                                                // There is a pointer for the next key
    {
        tmpKey = keyToSplit->getNext();                                 // Set the temporary key to be the next key of the key in question
        keyToSplit->setNext(tmpKey->getNext());                         // Set the next key, of the key in question, to be the next key of the temporary key
        tmpKey->setNext(Split(tmpKey->getNext()));                      // Do this move over and over to make sure the order stays correct
        return tmpKey;                                                  // Finally, return the tmpKey
    }
}

// This method checks if the keys are in the correct spot and moves them depending on the alphabetical order
Key* Merge(Key* firstKey, Key* secondKey)
{
    if (firstKey == NULL)
        return secondKey;
    else if(secondKey == NULL)
        return firstKey;
    else if (firstKey->getText().compare(secondKey->getText()) < 0)     // If the firstKey has a textvalue that should be earlier in the alphabetical order:
    {
        firstKey->setNext(Merge(firstKey->getNext(), secondKey));       // setNext on the next key that should be after it in alphabetical order.
        return firstKey;                                                // Finally, return the firstKey
    }
    else
    {
        secondKey->setNext(Merge(firstKey, secondKey->getNext()));      // If the secondKey should be in front of the firstKey, it will move the other keys aswell
        return secondKey;                                               // Finally, return the secondKey
    }
}

// This method uses both methods above to sort a linked list of keys in alphabetical order.
Key* mergeSort(Key* keyToSort)
{
    Key* tmpKey;

    if (keyToSort == NULL)                                              // If the key is NULL, do nothing.
        return NULL;
    else if (keyToSort->getNext() == NULL)                              // If it has no other keys, do nothing.
        return keyToSort;
    else
    {
        tmpKey = Split(keyToSort);                                      // Split the keys into smaller groups
        return Merge(mergeSort(keyToSort), mergeSort(tmpKey));          // Merge those keys again
    }
}