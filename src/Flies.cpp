#include "Flies.h"
#include "Options.h"
#include "Fly.h"

#include <thread>

Flies::Flies(const Options& opts)
{
	std::thread myThreads[opts.flyCapacity()];

	for( int i=0; i < opts.flyCapacity(); i++ )
	{
		myThreads[i] = std::thread(Fly());
	}

	for (int i = 0; i < opts.flyCapacity(); i++)
	{
		myThreads[i].join();
	}
}
