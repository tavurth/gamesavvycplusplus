#ifndef GSC_TEXT
#define GSC_TEXT

#include "../headers/GSC.h"

namespace gsc {
	class Font {
		private:
			std::vector<Texture *> letters;
			double size;
			double gap;

		public:
			Font(std::string location, int newSize = 16);
			~Font();

			void set_size(double newSize);
			double get_size() const;

			void write(std::string text, int x, int y, int z = 0);
	};
}

#endif
