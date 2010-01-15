#ifndef TIMELINE
#define TIMELINE

#include "../headers/GSC.h"

namespace gsc {
	namespace timeline {
		typedef void (*eventFunc)(void);

		class Event {
			protected:
				double time;
				eventFunc function;
				void erase();

			public:
				Event(double newTime, eventFunc newEventFunc);
				~Event();

				void set_function(eventFunc newEventFunc);
				void set_time(double time);

				eventFunc get_function() const;
				double get_time() const;
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
