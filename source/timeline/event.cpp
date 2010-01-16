//		Copyright (c) William Whitty 2010
//
//     This file is part of GSC. 
//
//     GSC is free software: you can redistribute it and/or modify
//     it under the terms of the GNU Lesser General Public License as published by
//     the Free Software Foundation, either version 3 of the License, or
//     (at your option) any later version.
//
//     GSC is distributed in the hope that it will be useful,
//     but WITHOUT ANY WARRANTY; without even the implied warranty of
//     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//     GNU Lesser General Public License for more details.
//
//     You should have received a copy of the GNU Lesser General Public License
//     along with GSC.  If not, see <http://www.gnu.org/licenses/>.

#include "../headers/GSC.h"

using namespace gsc;
using namespace timeline;

Event::Event(double newTime, eventFunc newEventFunc, void * newData) {
	time = newTime; function = newEventFunc; data = newData;

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

void Event::set_data(void * newData) {
	data = newData;
}

void Event::set_time(double newTime) {
	time = newTime;
}

eventFunc Event::get_function() const {
	return function;
}

void * Event::get_data() const {
	return data;
}

double Event::get_time() const {
	return time;
}

void Event::call () const {
	(* function)(data);
}
