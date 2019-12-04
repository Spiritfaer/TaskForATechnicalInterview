#ifndef CORE_HPP
#define CORE_HPP

#include <vector>
#include "Book.hpp"
#include "File.hpp"

class Core
{
public:
	explicit Core(char const *pathName);
	~Core();

	void makeBooks();
	void booksSort();
	void booksPrint();
	void saveBooks();
private:
	File				*m_filePtr;
	std::vector<Book*>	m_books;

	Core(Core const &ref) = default;
	Core &operator=(Core const &ref) = default;
	void addCurrentNote(CarNote const &note);
};

#endif
