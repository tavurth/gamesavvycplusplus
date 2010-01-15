#include "../headers/GSC.h"

using namespace gsc;
using namespace timeline;

std::list<Event *> timeline::timeline;
double timeline::currentTime;

void timeline::add_event (Event * newEvent) {
	std::list<Event *>::iterator it;

	if (timeline.size() > 0) {
		for (it = timeline.begin(); it != timeline.end(); it++)
			if (newEvent->get_time() > (*it)->get_time())
				timeline.insert(it, newEvent);
	}
	
	else 
		timeline.push_back(newEvent);
}

void timeline::update () {
	currentTime += 0.01;

	if (timeline.size() < 1)
		return;

	Event * current;

	while (timeline.size() > 0 && (current = timeline.front())->get_time() <= currentTime) {
		(* current->get_function())();
		timeline.pop_front();
	}
}

void timeline::clear () {
	Event * current;

	while ((current = timeline.front())) {
		delete(current);
		timeline.pop_front();
	}
}

void timeline::init () {
	currentTime = 0;
}
