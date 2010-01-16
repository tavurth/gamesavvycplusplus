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

#ifndef GSC_TIMELINE
#define GSC_TIMELINE

#include "../headers/GSC.h"

namespace gsc {
	namespace timeline {
		typedef void (*eventFunc)(void *);

		class Event {
			protected:
				double time;
				eventFunc function;
				void * data;

				void erase();

			public:
				Event(double newTime, eventFunc newEventFunc, void * newData = NULL);
				~Event();

				void set_function(eventFunc newEventFunc);
				void set_data(void * newData);
				void set_time(double time);

				eventFunc get_function() const;
				void * get_data() const;
				double get_time() const;

				void call() const;
		};

		extern std::list<Event *> timeline;
		extern double currentTime;

		void init();
		void add_event(Event * newEvent);
		void update();

		void clear();
	}
}

#endif
