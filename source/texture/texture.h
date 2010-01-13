#ifndef GSC_TEXTURE
#define GSC_TEXTURE

#include "../GSC.h"

namespace gsc {

	class Texture { 
		char * data;
		std::string location;
		short width, height, bpp;
		int id, format;

		void check_texture(int error);

		public:
			Texture();
			~Texture();
			void initialise();
			void free_data();

			void set_data(char *);
			void set_location(std::string);
			void set_width(short);
			void set_height(short);
			void set_bpp(short);
			void set_format(int);
			void set_id(GLuint);

			char * get_data();
			int    get_format();
			short  get_width();
			short  get_height();
			short  get_bpp();
			GLuint get_id();
			std::string get_location();
	};

	extern GLuint TEXTURE_WRAP_T;
	extern GLuint TEXTURE_WRAP_S;
	extern GLuint TEXTURE_MIN_FILTER;
	extern GLuint TEXTURE_MAG_FILTER;

}

#endif
