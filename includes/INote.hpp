
#ifndef INOTE_HPP
#define INOTE_HPP

class INote
{
protected:
	time_t	m_rawTime;
public:
	virtual const char* toString(void) const = 0;
	virtual ~INote() {};
};

#endif
