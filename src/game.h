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
		LOGINFO << "Wait for players";
	}

	void options(const Options::Ptr& o)
	{
		_opts = o;
	}
};

#endif /* GAME_H */
