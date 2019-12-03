#include <iostream>
#include "Book.hpp"

Book::Book(char const *name) : m_bookName(name) {}
Book::Book(CarNote const &carNote) : m_bookName(carNote.getName()), m_mass(0u) {
	m_notes.push_back(carNote);
}
void Book::sortByTyme()
{
	double fakt = 1.2473309; // фактор уменьшения
	double step = m_notes.size() - 1;

	auto comp = [](CarNote const &a, CarNote const &b) -> bool {
		return a.getRawTime() > b.getRawTime();
	};

	while (step >= 1) {
		for (uint32_t i = 0, size = m_notes.size(); i + step < size; ++i) {
			if (comp(m_notes[i], m_notes[i + step])) {
				CarNote tmp = m_notes[i];
				m_notes[i] = m_notes[i + step];
				m_notes[i + step] = tmp;
			}
		}
		step /= fakt;
	}

	for (uint32_t i = 0, size = m_notes.size(); i < size - 1; ++i)
	{
		bool swapped = false;
		for (uint32_t j = 0; j < size - i - 1; ++j)
		{
			if (comp(m_notes[j], m_notes[j + 1])) {
				CarNote tmp = m_notes[j];
				m_notes[j] = m_notes[j + 1];
				m_notes[j + 1] = tmp;
				swapped = true;
			}
		}
		if (!swapped)
			break;
	}
}
std::string Book::toString()
{
	std::stringstream buff("");
	buff.clear();
	for (auto const &note : m_notes) {
		buff << note.toString() << std::endl;
	}
	return buff.str();
}
std::string& Book::getBookName() { return m_bookName; }
std::vector<CarNote>& Book::getNotes() { return m_notes; }
uint64_t &Book::getMass() { return m_mass; }
