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

    void additem (char * word)
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