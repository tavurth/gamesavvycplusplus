#include "../headers/GSC.h"

using namespace gsc;

void gsc::new_config (std::string location) {
	std::ofstream out (location.c_str());

	out << "SCREEN_WIDTH\t\t\t= 1024;\nSCREEN_HEIGHT\t\t\t= 512;\nSCREEN_BPP\t\t\t= 32;\nSCREEN_FOV\t\t\t= 90;\nSCREEN_ASPECT_NEAR\t\t= 0.1;\nSCREEN_ASPECT_FAR\t\t= 10000;\n";
}

double gsc::get_double (std::string line) {
	size_t location = line.find_last_of('=');
	return atof(line.substr(++location).c_str());
}

int gsc::check_var (std::string line, std::string compare) {
	return (line.compare(0, compare.size(), compare) == 0) ? 1 : 0;
}

void gsc::check_vars (std::string line) {
	if      (check_var(line, "SCREEN_WIDTH")) 
		gsc::SCREEN_WIDTH = get_double(line);
	else if (check_var(line, "SCREEN_HEIGHT"))
		gsc::SCREEN_HEIGHT = get_double(line);
	else if (check_var(line, "SCREEN_BPP"))
		gsc::SCREEN_BPP = get_double(line);
	else if (check_var(line, "SCREEN_FOV"))
		gsc::SCREEN_FOV = get_double(line);
	else if (check_var(line, "SCREEN_ASPECT_NEAR"))
		gsc::SCREEN_ASPECT_NEAR = get_double(line);
	else if (check_var(line, "SCREEN_ASPECT_FAR"))
		gsc::SCREEN_ASPECT_FAR = get_double(line);
}

void gsc::load_config (const char * location) {
	std::vector<std::string> lines = utils::get_file_text(location);
	std::vector<std::string>::iterator it;

	gsc::init_globals();

	if (lines.size() < 1) {
		new_config(location);
		return;
	}

	for (it = lines.begin(); it < lines.end(); it++)
		check_vars(*it);
}

void gsc::load_config (std::string location) {
	load_config(location.c_str());
}
