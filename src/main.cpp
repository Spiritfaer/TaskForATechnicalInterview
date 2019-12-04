#include "../includes/Core.hpp"

int main(int argc, char **argv)
{
	if (argc < 2) {
		std::cout << "You need more arguments" << std::endl;
		return 0;
	}

	try {
		Core core(argv[1]);
		core.makeBooks();
		core.booksSort();
		core.booksPrint();
		core.saveBooks();
	} catch (std::exception const &ex) {
		std::cerr << ex.what() << std::endl;
	}

	return 0;
}
