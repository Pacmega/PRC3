#ifndef CAR_H_
#define CAR_H_

#include <vector>
#include <string>

#include "Wheel.h"

#ifdef SHOW_CTORS
    #define TRACE(txt) std::cout << txt << std::endl
#else
    #define TRACE(txt)
#endif

class Car
{
private:
    std::vector<Wheel*> wheels;
    std::string licencePlate;
    std::string model;

    bool indexInRange(int index);
    /* pre : -
     * post: returns if wheels[index] is valid
     */
    
    void deleteAllWheels();
    /* pre : -
     * post: all wheels in this car are deleted
     */
    
    void copyCar(const Car& otherCar);
    /* pre : -
     * post: all otherCar fields are deep copied into this
     */

    void deleteWheel(int position);

public:
    void removeWheel(int index);
    /* pre : -
       post: if 0 <= index < nr wheels in <Car>
             then wheel nr index is removed from <Car>
             else out_of_range exception with text: "illegal index" is thrown
    */

    void addWheel(int diameter, const std::string& material);
    /* pre : diameter > 0
       post: a wheel with given diameter and material is added to <Car>
    */

    Car(const std::string& model, const std::string& material, int diameter, int nrWheels);
    /* pre : diameter > 0 and nrWheels > 2
       post: A Car object is created that contains nrWheels Wheel objects
             with the given material and diameter
    */

    virtual ~Car();
   	/* pre : -
	     post: the Car object is destroyed including all allocated memory
  	*/

    const std::string& getModel();
    /* pre : -
       post: getModel()= <Car> model
    */

    void setLicencePlate(const std::string& licence);
    /* pre : -
       post: <Car>'s licence plate is licence
    */

    const std::string& getLicencePlate();
    /* pre : -
       post: getLicencePlate()= <Car>'s licence plate
    */

    int getNrWheels();
    /* pre : -
       post: getNrWheels()= <Car>'s nr wheels
    */

    const Wheel* getWheel(int index);
    /* pre : 0 <= index < nr wheels in <Car>
       post: getWheel(i) = Wheel nr index of <Car>
    */

    Car(const Car& myCar);
      /* pre : -
  	     post: a Car object is created with all properties of myCar, a deep copy is performed
      */

  	Car& operator=(const Car& myCar);
  	/* pre : -
  	   post: all properties of this object are replaced with myCar's properties,
  	         all previously existing properties are properly cleaned up and new
  	         properties are deep copied
  	*/
};

#endif
