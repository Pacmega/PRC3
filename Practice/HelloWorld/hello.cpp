#include <iostream>

class Hello
{
	public:
		Hello()
		{
			std::cout << "Hello class is constructed!\n";
		}

		void print()
		{
			std::cout << "Hello world!\n";
		}
};

int main(int argc, char const *argv[])
{
	Hello hi;
	hi.print();
	return 0;
}