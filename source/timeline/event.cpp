#include "../headers/GSC.h"

using namespace gsc;
using namespace timeline;

Event::Event(double newTime, eventFunc newEventFunc) {
	time = newTime; function = newEventFunc;

	timeline::add_event(this);
}

void Event::erase() {
	std::list<Event *>::iterator it;

	for (it = timeline.begin(); it != timeline.end(); it++)
		if ((*it) == this)
			timeline.erase(it);
}

Event::~Event() {
	this->erase();
}

void Event::set_function(eventFunc newEventFunc) {
	function = newEventFunc;
}

void Event::set_time(double newTime) {
	time = newTime;
}

eventFunc Event::get_function() const {
	return function;
}

double Event::get_time() const {
	return time;
}
