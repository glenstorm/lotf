#ifndef OPTIONS_H_GUARD_
#define OPTIONS_H_GUARD_

#include <memory>

class Options
{
private:
	unsigned int flyCapacity_;
	unsigned int flyStupidity_;
	unsigned int sideOfSquare_;
public:
	typedef std::shared_ptr<Options> Ptr;

	Options();

	void flyCapacity(unsigned int);
	unsigned int flyCapacity() const;

	void flyStupidity(unsigned int);
	unsigned int flyStupidity() const;

	void sideOfSquare(unsigned int);
	unsigned int sideOfSquare() const;
};

#endif
	// OPTIONS_H_GUARD_
