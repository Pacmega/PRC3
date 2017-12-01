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
    
    // f.loadFile("data/gibberish.bin", head);

    // next line is only to show what kind of data we're working with
    // remove this line to increase performance!
    head.addValue("Amandelen");
    head.addValue("Pannenkoek");
    head.addValue("Boter");
    head.addValue("Kaas");
    head.addValue("Eieren");
    head.addValue("Aardbei");
    head.addValue("Handelen");

    head.print();

    std::cout << "After mergeSort" << std::endl;
    
    mergeSort(&head);

    head.print();
    // sort all data
    // todo: call your sort method(s) here!

    // save sorted data into a new file called sorted.bin
    f.saveFile(head, "sorted.bin");
    
    return 0;
}

Key* Split(Key* keyToSplit)
{
    Key* tmpKey;

    if (keyToSplit == NULL) 
        return NULL;
    else 
        if (keyToSplit->getNext() == NULL) 
            return NULL;
    else
    {
        tmpKey = keyToSplit->getNext();
        keyToSplit->setNext(tmpKey->getNext());
        tmpKey->setNext(Split(tmpKey->getNext()));
        return tmpKey;
    }
}

Key* Merge(Key* firstKey, Key* secondKey)
{
    if (firstKey == NULL)
        return secondKey;
    else if(secondKey == NULL)
        return firstKey;
    else if (firstKey->getText().compare(secondKey->getText()) < 0)
    {
        firstKey->setNext(Merge(firstKey->getNext(), secondKey));
        return firstKey;
    }
    else
    {
        secondKey->setNext(Merge(firstKey, secondKey->getNext()));
        return secondKey;
    }
}

Key* mergeSort(Key* keyToSort)
{
    Key* tmpKey;

    if (keyToSort == NULL)
        return NULL;
    else if (keyToSort->getNext() == NULL)
        return keyToSort;
    else
    {
        tmpKey = Split(keyToSort);
        return Merge(mergeSort(keyToSort), mergeSort(tmpKey));
    }
}

