#ifndef CARBOOK_HPP
#define CARBOOK_HPP

#include <vector>
#include "CarNote.hpp"

class Book {
public:
	explicit Book(char const *name);
	explicit Book(CarNote const &carNote);
	~Book() = default;

	void sortByTyme();
	std::string toString();

	std::string &getBookName();
	std::vector<CarNote> &getNotes();
	uint64_t &getMass();
private:
	std::string				m_bookName;
	uint64_t				m_mass;
	std::vector<CarNote>	m_notes;

	Book() = default;
	Book(Book const &ref) = default;
	Book &operator=(Book const &ref) = default;
};

#endif
