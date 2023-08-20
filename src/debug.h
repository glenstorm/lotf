#ifndef DEBUG_H
#define DEBUG_H

#include <boost/log/trivial.hpp>
#include <boost/filesystem.hpp>

#define LOGOUTPUT(x, c)                                                        \
	BOOST_LOG_TRIVIAL(x)                                                       \
	    << c << boost::filesystem::path((char *)__FILE__).filename() << ":"    \
	    << __LINE__ << ": \033[0m"

#define LOGTRACE LOGOUTPUT(trace, "\033[1;30m")
#define LOGDEBUG LOGOUTPUT(debug, "\033[1;37m")
#define LOGINFO LOGOUTPUT(info, "\033[32m")
#define LOGWARNING LOGOUTPUT(warning, "\033[33m")
#define LOGERROR LOGOUTPUT(error, "\033[31m")
#define LOGFATAL LOGOUTPUT(fatal, "\033[41m")

#endif /* DEBUG_H */
