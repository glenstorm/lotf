#ifndef GAME_H
#define GAME_H

#include "Options.h"
#include "Flies.h"

class Game
{
public:
	typedef std::vector<unsigned int> MapRow;
	typedef std::vector<MapRow> MapCont;

private:
	// inside map cell: current fly count
	MapCont map_;
	Flies flies_;
	Options::Ptr opts_;

public:
	Game()
		:map_()
		,flies_()
		,opts_()
	{}

	void start()
	{
		LOGINFO << "Start";
	}

	void stop()
	{
		LOGINFO << "Stop";
	}

	void changeLivingAreaSize(unsigned int n)
	{
		for_each(map_.begin(), map_.end(), [](MapRow& row)
		{
			row.resize(n);
		});

		map.resize(n);

		opts_.sideOfSquare(n);
	}

	void flyStupidity(unsigned int n)
	{
		opts_.flyStupidity(n);
	}

	void options(const Options::Ptr& o)
	{
		opts_ = o;
		flies_.options(o);
	}
};

#endif /* GAME_H */
