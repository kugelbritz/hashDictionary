/* 
--------------------------------- Simple Timer --------------------------------------------

- Vachik Dave
*/
#include <cstddef>
#include <stdio.h>
#include <ctime>
#include <time.h>
/*
struct timeval{
long    tv_sec;         // seconds
long    tv_usec;        // microseconds
};
*/
class TimeInterval{
public:
	 time_t start_time;
	 time_t end_time;
	public:
		TimeInterval();
		void start();
		void stop();
		float GetInterval();
};

TimeInterval::TimeInterval(){}

void TimeInterval::start()
{
	1000*(time(&(this->start_time)));
}

void TimeInterval::stop()
{
	1000*(time(&(this->end_time)));
}

float TimeInterval::GetInterval()
{
	float t = difftime(end_time, start_time);
//	t = t / 1000000.0		// in sec

	return t;
}
