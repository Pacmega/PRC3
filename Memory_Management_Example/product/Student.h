#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "Person.h"


class Student: public Person
{
	private:
		int debt;

	public:
		Student();
		/*	pre :
			post: object Student has a debt == ""
		*/

		Student(std::string firstName, std::string lastName, int debt);
		/*	pre :
			post: object Student has debt == debt
		*/

		virtual ~Student();
        /*  pre :
            post:
        */
};

#endif
