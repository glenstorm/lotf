#include "Flies.h"
#include <QThread>

Flies::Flies(const Options::Ptr& o)
{
	options(o);
}

void Flies::options(const Options::Ptr& o) {
	opts_ = o;
}


void Flies::addThread(unsigned int num, const Point& start_point)
{
	Fly* aFly = new Fly(num, start_point);
	QThread* thread = new QThread;
	aFly->moveToThread(thread);

	// connect(thread, SIGNAL(started()), worker, SLOT(process()));
	// connect(worker, SIGNAL(finished()), thread, SLOT(quit()));
	// connect(this, SIGNAL(stopAll()), worker, SLOT(stop()));
	// connect(worker, SIGNAL(finished()), worker, SLOT(deleteLater()));
	// connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
	thread->start();
}


void Flies::stopThreads()
{
	// emit stopAll();
}


void Flies::startFlying()
{
	stopThreads();
	// receive position of flies from map

}
