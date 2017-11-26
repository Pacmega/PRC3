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

void merge(item * array, int leftIndex, int m, int rightIndex)
{
    std::cout << "Merge params: \narray address: " << &array << "\nleftIndex: " << leftIndex << "\nMiddle point: " << m << "\nrightIndex: " << rightIndex << std::endl;
	// Merges two subarrays of arr[].
	// First subarray is arr[leftIndex..m]
	// Second subarray is arr[m+1..rightIndex]
	//int leftIndexFirstSub, j, k;
    int n1 = m - leftIndex + 1;
    int n2 =  rightIndex - m;
 
    /* create temp arrays */
    item* leftTemp[n1];
    item* rightTemp[n2];

    std::cout << "N1: " << n1 << "\t N2: " << n2 << std::endl;
 
    /* Copy data to temp arrays leftTemp[] and rightTemp[] */
    for (int i = 0; i < n1; i++)
    {
        //leftTemp[i] = array[leftIndex + i];
        item* temp = new item(array->word); //optimalize in full program
        for(int j = 0; j < leftIndex+i; j++)
        {
            temp = temp->next;
        }
        leftTemp[i] = temp;
    }

    for (int i = 0; i < n2; i++)
    {
        //rightTemp[i] = array[m + 1+ i];
        item* temp = new item(array->word); //optimalize in full program
        for(int j = 0; j < leftIndex+i; j++)
        {
            temp = temp->next;
        }
        rightTemp[i] = temp;
    }

    /* Merge the temp arrays back into array[leftIndex..rightIndex]*/
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = leftIndex; // Initial index of merged subarray
    
    while (i < n1 && j < n2)
    {
        if (leftTemp[i] <= rightTemp[j])
        {
            item* temp = new item(array->word);

            std::cout << "Temp address == " << &temp << std::endl;
            std::cout << "Temp ??? == " << temp << std::endl;

            int z = 0;
            for(z = 0; z < k; z++)
            {
                temp = temp->next;
            }
            //array[k] = leftTemp[i];
            
            std::cout << "jfc what?" << std::endl;
            // This line breaks the program!
            temp->prev->next = leftTemp[i];
            std::cout << "jfc what?" << std::endl;

            i++;
        }

        else
        {
            item* temp = new item(array->word);
            int z = 0;
            for(z = 0; z < k; z++)
            {
                temp = temp->next;
            }
            temp->prev->next = rightTemp[i];
            //array[k] = rightTemp[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        item* temp = new item(array->word);
            int z = 0;
            for(z = 0; z < k; z++)
            {
                temp = temp->next;
            }
            //array[k] = leftTemp[i];
            temp->prev->next = leftTemp[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        item* temp = new item(array->word);
            int z = 0;
            for(z = 0; z < k; z++)
            {
                temp = temp->next;
            }
            temp->prev->next = rightTemp[i];
        j++;
        k++;
    }
}

void sort(item * array, int leftIndex, int rightIndex)
{
	if (leftIndex < rightIndex)
    {
        // Same as (leftIndex+rightIndex)/2, but avoids overflow for
        // large l and h
        int middle = leftIndex+(rightIndex-leftIndex)/2;

        // Sort first and second halves
        sort(array, leftIndex, middle);
        sort(array, middle+1, rightIndex);

        merge(array, leftIndex, middle, rightIndex);
    }
}

int main(void)
{
    /*int random;
    int arraySize = 100;
    char array[arraySize];
    for(int i = 0; i < 100; i++)
    {
        random = (char)(rand() % 26 + 65);
        array[i] = random;
    }
    
    //sort(array, 0, arraySize - 1);

    for(int i = 0; i < 100; i++)
    {
        std::cout << array[i];
        std::cout << "\n";
    }*/

    List* list = new List();
    list->additem((char*)"zaterdag");
    list->additem((char*)"zondag");
    list->additem((char*)"maandag");
    list->additem((char*)"dinsdag");
    list->additem((char*)"woensdag");
    list->additem((char*)"donderdag");
    list->additem((char*)"vrijdag");
    list->additem((char*)"school");
    list->additem((char*)"laptop");
    list->additem((char*)"pc master race");

    std::cout << "Number of elements in list: " << list->nrOfElements() << std::endl;

    sort(list->head, 0, list->nrOfElements());//first item, left index, right index(nrOfElements)
}
