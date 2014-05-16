/**
 * Copyright (C) Justin James - All Rights Reserved.
 * Unauthorized use or copying of this file via any medium is strictly prohibited.
 * This document is proprietary and confidential.
 * This document should be immediately destroyed unless given explicit permission by Justin James.
 * Written by Justin James <justin.aj@hotmail.com>
 */

#include "Timer.h"
#include "DLList.h"

Jupiter::DLList<Jupiter::Timer> timers;

/** Deallocates timers when the library is unloaded. */
struct TimerKiller
{
	~TimerKiller();
} timerKiller;

TimerKiller::~TimerKiller()
{
	killTimers();
}

struct Jupiter::Timer::Data
{
	void (*function)(unsigned int, void *);
	void (*functionNoParams)(unsigned int);
	void *parameters;
	time_t nextCall;
	time_t delay;
	int iterations;
};

Jupiter::Timer::Timer(unsigned int iterations, time_t timeDelay, void(*function)(unsigned int, void *), void *parameters, bool immediate)
{
	Jupiter::Timer::data_ = new Jupiter::Timer::Data();
	Jupiter::Timer::data_->function = function;
	Jupiter::Timer::data_->functionNoParams = nullptr;
	Jupiter::Timer::data_->parameters = parameters;
	Jupiter::Timer::data_->iterations = iterations;
	Jupiter::Timer::data_->delay = timeDelay;
	Jupiter::Timer::data_->nextCall = immediate ? time(0) : time(0) + timeDelay;
	timers.add(this);
}

Jupiter::Timer::Timer(unsigned int iterations, time_t timeDelay, void(*function)(unsigned int), bool immediate)
{
	Jupiter::Timer::data_ = new Jupiter::Timer::Data();
	Jupiter::Timer::data_->function = nullptr;
	Jupiter::Timer::data_->functionNoParams = function;
	Jupiter::Timer::data_->parameters = nullptr;
	Jupiter::Timer::data_->iterations = iterations;
	Jupiter::Timer::data_->delay = timeDelay;
	Jupiter::Timer::data_->nextCall = immediate ? time(0) : time(0) + timeDelay;
	timers.add(this);
}

Jupiter::Timer::~Timer()
{
	delete Jupiter::Timer::data_;
}

int Jupiter::Timer::think()
{
	if (Jupiter::Timer::data_->nextCall <= time(0))
	{
		int killMe = 0;

		if (Jupiter::Timer::data_->iterations != 0 && --Jupiter::Timer::data_->iterations == 0) killMe = 1;
		if (Jupiter::Timer::data_->function != nullptr) Jupiter::Timer::data_->function(Jupiter::Timer::data_->iterations, Jupiter::Timer::data_->parameters);
		else Jupiter::Timer::data_->functionNoParams(Jupiter::Timer::data_->iterations);

		Jupiter::Timer::data_->nextCall = Jupiter::Timer::data_->delay + time(0);

		return killMe;
	}

	return 0;
}

bool Jupiter::Timer::removeFromList()
{
	if (timers.size() == 0) return false;
	for (Jupiter::DLList<Jupiter::Timer>::Node *n = timers.getNode(0); n != nullptr; n = n->next)
	{
		if (n->data == this)
		{
			timers.remove(n);
			return true;
		}
	}
	return false;
}

bool Jupiter::Timer::kill()
{
	if (Jupiter::Timer::removeFromList())
	{
		delete this;
		return true;
	}
	delete this;
	return false;
}

extern "C" void addTimer(unsigned int iterations, time_t timeDelay, bool immediate, void(*function)(unsigned int, void *), void *parameters)
{
	new Jupiter::Timer(iterations, timeDelay, function, parameters, immediate);
}

extern "C" void addTimerNoParams(unsigned int iterations, time_t timeDelay, bool immediate, void(*function)(unsigned int))
{
	new Jupiter::Timer(iterations, timeDelay, function, immediate);
}

extern "C" unsigned int totalTimers()
{
	return timers.size();
}

extern "C" unsigned int checkTimers()
{
	unsigned int r = 0;
	Jupiter::Timer *t;
	Jupiter::DLList<Jupiter::Timer>::Node *o;
	Jupiter::DLList<Jupiter::Timer>::Node *n = timers.size() == 0 ? nullptr : timers.getNode(0);
	while (n != nullptr)
	{
		t = n->data;
		if (t->think() != 0)
		{
			o = n;
			n = n->next;
			delete timers.remove(o);
			r++;
		}
		else n = n->next;
	}
	return r;
}

extern "C" unsigned int killTimers()
{
	unsigned int r = timers.size();
	while (timers.size() != 0) delete timers.remove(unsigned int(0));
	return r;
}