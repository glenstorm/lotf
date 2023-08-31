#ifndef _FLIES_H_GUARD_
#define _FLIES_H_GUARD_

#include "Options.h"
#include "Fly.h"

#include <vector>
#include <thread>

// store for threads
class Flies : public QObject
{
	Q_OBJECT
public:
	Flies(const Options::Ptr& o);

	void options(const Options::Ptr& o);
	void addThread(unsigned int num, const Point& start_point);
	void stopThreads();
	void startFlying();

private:
	Options::Ptr opts_;
	QVector<Fly> fliesThreads_;
};

#endif
	// _FLIES_H_GUARD_
