#ifndef CARNOTE_HPP
#define CARNOTE_HPP

#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include <cstring>
#include "INote.hpp"

class CarNote : public INote
{
private:
	enum {
		TIME, CARNAME, WEIGHT, MAX
	};

	std::string		m_rawInfo;
	std::string		m_car[MAX];

	CarNote() = default;

	void trim();
	void init(char const *src);
	void initRawTime();
public:

	explicit CarNote(char const *strNote);
	explicit CarNote(std::string const &strNote);
	CarNote(CarNote const &ref);
	~CarNote() override = default;
	CarNote &operator=(CarNote &ref);

	const char* toString() const override;
	char const *getName() const;
	char const *getTime() const;
	char const *getWeight() const;
	time_t const &getRawTime() const;
};

#endif
