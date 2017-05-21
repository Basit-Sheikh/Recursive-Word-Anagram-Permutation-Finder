#include"utilities.h"

int main() {
	bool match = false;
	string file_name = getFileName();
	ifstream file(file_name.c_str());
	if (!file)
		cerr << "Error: Cannot open " << file_name << ".txt!" << endl;
	else 
		Loop(file, match);

	return 0;
}