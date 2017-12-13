#include "sluice.h"
#include "button.h"
#include "levelSensor.h"
#include "networkInterface.h"
#include "trafficLight.h"
#include "cameraSystem.h"
#include "door.h"

int main(int argc, char const *argv[])
{
	while (choice != 'q')
    {
        printf ("\nMenu\n"
                "========\n"
                "   [n]    create new semaphore\n"
                "   [o]    open existing semaphore\n"
                "Enter choice: "
               );
        fgets (line, sizeof (line), stdin);
        choice = line[0];
        printf ("\n");
        
        switch (choice)
        {

        }
    }
	return 0;
}