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

void populateList(List &list)
{
    list.additem((char*)"zaterdag");
    list.additem((char*)"zondag");
    list.additem((char*)"maandag");
    list.additem((char*)"dinsdag");
    list.additem((char*)"woensdag");
    list.additem((char*)"donderdag");
    list.additem((char*)"vrijdag");
    list.additem((char*)"school");
    list.additem((char*)"laptop");
    list.additem((char*)"pc master race");
}

int main(void)
{
    List* list = new List();
    populateList(*list);

    // Debugging: check how many items the list contains
    // std::cout << "Number of elements in list: " << list->nrOfElements() << std::endl;

    //sort(list->head, 0, list->nrOfElements());//first item, left index, right index(nrOfElements)
}