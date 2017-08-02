#include "task.h"

int count_lines(const std::string& filename)
{
	std::ifstream input_file(filename.c_str());

	if ( !input_file.good() ) {
		std::cout << "File doesn't exists: " << filename << std::endl;
		return -1;
	}

	int result = std::count(
					std::istreambuf_iterator<char>(input_file),
			  		std::istreambuf_iterator<char>(),
			  		'\n');

	assert(result >= 0);

	return result;
}

int main(int argc, char ** argv)
{
	if ( argc != 2 ) {
		std::cout << "Wrong argument format! " << std::endl;
		std::cout << "./counter <filename>"    << std::endl;
		return -1;
	}

	std::string file(argv[1]);
	int lines_amount = count_lines(file);

	if ( lines_amount == -1 ) {
		std::cout << "Error occured, try again " << std::endl;
		return - 1;
	}

	std::cout << lines_amount << " " << file << std::endl;

	return 0;
}