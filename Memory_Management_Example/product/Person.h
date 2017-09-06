#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{
	private:
		std::string firstName;
		std::string lastName;

	public:
		Person();
		/*	pre :
			post: object Person has a name == ""
		*/

		Person(std::string firstName, std::string lastName);
		/*	pre :
			post: object Person has name == name
		*/

		virtual ~Person();
        /*  pre :
            post:
        */
};

#endif
