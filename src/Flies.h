#ifndef _FLIES_H_GUARD_
#define _FLIES_H_GUARD_

#include "Options.h"
#include "Fly.h"

#include <vector>
#include <thread>

// store for threads
class Flies
{
public:
	Flies();

	void options(const Options::Ptr& o)
	{
		opts_ = o;
	}

	void startFlying()
	{
		for (int i = 0; i < opts_->flyCapacity(); i++)
		{
			fliesThreads_.emplace_back(std::thread(Fly()));
		}

		for (int i = 0; i < opts_->flyCapacity(); i++)
		{
			fliesThreads_[i].join();
		}
	}
private:
	Options::Ptr opts_;
	std::vector<std::thread> fliesThreads_;

};

#endif
	// _FLIES_H_GUARD_
