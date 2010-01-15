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
