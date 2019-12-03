#include "Core.hpp"

Core::Core(char const *pathName)
{
	m_filePtr = new File(pathName, "r");
}
Core::~Core()
{
	for (auto &book : m_books)
		delete book;
	delete m_filePtr;
}
void Core::makeBooks()
{
	std::string	buff;

	while (m_filePtr->readLine(buff)) {
		if (!buff.empty()) {
			CarNote tmpNote(buff);
			addCurrentNote(tmpNote);
		}
	}
}
void Core::addCurrentNote(CarNote const &note)
{
	for (auto & book : m_books) {
		if (book->getBookName() == note.getName()) {
			book->getNotes().push_back(note);
			book->getMass() += atoi(note.getWeight());
			return;
		}
	}
	m_books.push_back(new Book(note));
}
void Core::booksSort()
{
	for (auto &book : m_books) {
		book->sortByTyme();
	}
}
void Core::booksPrint()
{
	for (auto &book : m_books) {
		std::cout << book->getBookName() << std::endl;
		std::cout << book->toString() << std::endl;
	}
}
void Core::saveBooks()
{
	for (auto &book : m_books) {
		std::string fullName = book->getBookName();
		fullName += ".txt";
		File newBookFile(fullName.c_str(), "w");
		newBookFile.writeToFile(book->toString());
		newBookFile.writeToFile("Total " + book->getBookName() + " weight - " + std::to_string(book->getMass()) + "\n");
	}
}
