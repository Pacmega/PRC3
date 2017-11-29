#include <iostream>
#include <stdlib.h>
#include <string.h>
// https://stackoverflow.com/questions/12030683/implementing-merge-sort-in-c
void populateList(List &List)
{
    List.addItem("zaterdag");
    List.addItem("zondag");
    List.addItem("maandag");
    List.addItem("dinsdag");
    List.addItem("woensdag");
    List.addItem("donderdag");
    List.addItem("vrijdag");
    List.addItem("school");
    List.addItem("laptop");
    List.addItem("pc master race");
}

int main(void)
{
    List* list = new List();
    populateList(*list);
}