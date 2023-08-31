#include <thread>

#include "Fly.h"
#include "debug.h"

Fly::Fly()
	:num_(0)
	,age_(0)
	,isAlive_(true)
	,speed_(0.0)
	,track_(0.0)
	,position_(0, 0)
{}

Fly::Fly(unsigned int num, const Point& start_point )
	:num_(num)
	,age_(0)
	,isAlive_(true)
	,speed_(0.0)
	,track_(0.0)
	,position_(start_point)
{}


void
Fly::process()
{
	// LOGINFO << "Fly #" << num_ 	<< "age = " << age
	// 							<< " isAlive = " << isAlive_
	// 							<< " speed = " << speed_
	// 							<< " track = " << track_
	// 							<< " position = " << position_ << std::endl;
	// LOGINFO << "Game started";
	// std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void
Fly::stop()
{

}

unsigned int
Fly::age() const
{
	return age_;
}

void
Fly::age(unsigned int i)
{
	age_ = i;
}

bool
Fly::isAlive() const
{
	return isAlive_;
}

void
Fly::isAlive(bool i)
{
	isAlive_ = i;
}

double
Fly::speed() const
{
	return speed_;
}

void
Fly::speed(const double& i)
{
	speed_ = i;
}

double
Fly::track() const
{
	return track_;
}

void
Fly::track(const double& i)
{
	track_ = i;
}

Point
Fly::position() const
{
	return position_;
}

void
Fly::position(const Point& i)
{
	position_ = i;
}
