#ifndef CLION_FILE_HPP
#define CLION_FILE_HPP

#include <cstdint>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>

class File {
public:

	std::stringstream m_buffStream;
	File(char const *pathName, char const *key);
	~File();

	bool readLine(std::string &buff);
	void writeToFile(std::string &&buff);

private:
	char	*m_buffer;
	FILE	*m_file;
	size_t	m_lSize;
	size_t	m_result;

	File() = default;
	File(File const &ref);
	File &operator=(File const &ref);
};

#endif
