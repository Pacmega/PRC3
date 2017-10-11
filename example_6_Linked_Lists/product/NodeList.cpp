#include <cstddef> // needed for definition of NULL
#include <iostream>

#include "NodeList.h"

NodeList::NodeList(void)
    : head(NULL)
{
}

NodeList::~NodeList(void)
{
    while (head != NULL)
    {
        Node* temp = head;
        head = head->getNext();
        delete temp;
        temp = NULL;
    }
}

void NodeList::show()
{
    Node* temp = head;
    std::cout << "\ncurrent nodelist: ";
    while (temp != NULL)
    {
        std::cout << temp->getValue() << " -> ";
        temp = temp->getNext();
    }
    std::cout << "NULL" << std::endl;
}

Node* NodeList::getFirstNode(void)
{
    return head;
}

Node* NodeList::getNodeByNr(int nr)
{
    if (nr < 0 || head == NULL)
    {
        return NULL;
    }

    Node* temp = head;
    int i = 0;
    while (i < nr && temp != NULL)
    {
        i++;
        temp = temp->getNext();
    }
    return temp;
}

bool NodeList::insertAfter(Node* newNode, Node* nodeToInsertAfter)
{
    if (newNode == NULL || nodeToInsertAfter == NULL)
    {
        return false;
    }

    // look for nodeToInsertAfter in list
    Node* temp = head;
    while (temp != nodeToInsertAfter && temp != NULL)
    {
        temp = temp->getNext();
    }

    if (temp != NULL)
    {
        // nodeToInsertAfter was found in linked list, insert newNode
        newNode->setNext(nodeToInsertAfter->getNext());
        nodeToInsertAfter->setNext(newNode);
        return true;
    }

    // nodeToInsertAfter was not found in linked list
    return false;
}

bool NodeList::insertBefore(Node* newNode, Node* nodeToInsertBefore)
{
    if (nodeToInsertBefore == head)
    {
        newNode->setNext(head);
        head = newNode;
        return true;
    }

    if (newNode == NULL || nodeToInsertBefore == NULL)
    {
        return false;
    }

    Node* temp = head;
    while (temp->getNext() != nodeToInsertBefore && temp->getNext() != NULL)
    {
        temp = temp->getNext();
    }

    if (temp->getNext() == nodeToInsertBefore)
    {
        // temp is now pointing at the node before nodeToInsertBefore
        newNode->setNext(nodeToInsertBefore);
        temp->setNext(newNode);
        return true;
    }

    // nodeToInsertBefore was not found in linked list
    return false;
}

bool NodeList::removeNode(Node* nodeToRemove)
{
    if (nodeToRemove == NULL)
    {
        return false;
    }

    if (nodeToRemove == head)
    {
        head = nodeToRemove->getNext();
        delete nodeToRemove;
        nodeToRemove = NULL;
        return true;
    }

    Node* temp = head;
    while (temp->getNext() != nodeToRemove && temp != NULL)
    {
        temp = temp->getNext();
    }

    if (temp != NULL)
    {
        // temp is now pointing at the node before nodeToRemove
        temp->setNext(nodeToRemove->getNext());
        // nodeToRemove has been "cut out of the list"
        delete nodeToRemove;
        nodeToRemove = NULL;
        return true;
    }

    // nodeToRemove is not in the list
    return false;
}
