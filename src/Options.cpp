#include "Options.h"

Options::Options():
	flyCapacity_(25),
	flyStupidity_(10),
	sideOfSquare_(100)
{}

void Options::flyCapacity(unsigned int i)
{
	flyCapacity_ = i;
}

unsigned int Options::flyCapacity() const
{
	return flyCapacity_;
}

void Options::flyStupidity(unsigned int i)
{
	flyStupidity_ = i;
}

unsigned int Options::flyStupidity() const
{
	return flyStupidity_;
}

void Options::sideOfSquare(unsigned int i)
{
	sideOfSquare_ = i;
}

unsigned int Options::sideOfSquare() const
{
	return sideOfSquare_;
}
