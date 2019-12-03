#include "CarNote.hpp"

CarNote::CarNote(char const *strNote) : m_rawInfo(strNote) {
	if (!strNote || !strlen(strNote))
		throw std::logic_error("string error");

	init(strNote);
	trim();
	initRawTime();
}
CarNote::CarNote(std::string const &strNote) : CarNote(strNote.c_str()) {}
CarNote::CarNote(CarNote const &ref) : CarNote(ref.m_rawInfo) {}
void			CarNote::init(char const *src) {
	std::stringstream buffStream(src);
	std::string buffString;

	for (auto &i : m_car) {
		std::getline(buffStream, i, ',');
	}
}
void			CarNote::trim() {
	for (uint8_t i = 0; i < MAX; ++i) {
		char const *ptr = m_car[i].c_str();
		while (*ptr == ' ')
			ptr++;
		m_car[i] = ptr;
	}
}
void			CarNote::initRawTime() {
	struct tm *timeInfo;
	time(&m_rawTime);
	timeInfo = localtime( &m_rawTime );

	sscanf(m_car[TIME].c_str(), "%d.%d.%d %d:%d",
		   &timeInfo->tm_mday,
		   &timeInfo->tm_mon,
		   &timeInfo->tm_year,
		   &timeInfo->tm_hour,
		   &timeInfo->tm_min);

	timeInfo->tm_year -= 1900;
	timeInfo->tm_mon -= 1;
	timeInfo->tm_sec = 0;

	m_rawTime = mktime(timeInfo);
}
const char*		CarNote::toString() const {	return m_rawInfo.c_str(); }
char const*		CarNote::getName() const { return m_car[CARNAME].c_str(); }
char const*		CarNote::getTime() const { return m_car[TIME].c_str(); }
char const*		CarNote::getWeight() const { return m_car[WEIGHT].c_str(); }
time_t const&	CarNote::getRawTime() const { return m_rawTime; }
CarNote			&CarNote::operator=(CarNote &ref) {
	m_rawInfo = ref.m_rawInfo;
	m_rawTime = ref.m_rawTime;
	m_car[CARNAME] = m_car[CARNAME];
	m_car[TIME] = m_car[TIME];
	m_car[WEIGHT] = m_car[WEIGHT];
	return *this;
}
