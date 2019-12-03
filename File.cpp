#include <stdexcept>
#include "File.hpp"

File::File(char const *pathName, char const *key) : m_buffer(nullptr)
{
	// Opening file
	m_file = fopen(pathName, key);
	if (!m_file)
		throw std::logic_error("Opening file errors!");

	// obtain file size
	fseek(m_file, 0, SEEK_END);
	m_lSize = ftell (m_file);
	rewind(m_file);

	// allocate memory to contain the whole file
	m_buffer = (char*) malloc (sizeof(char) * (m_lSize + 1));
	if (!m_buffer)
		throw std::logic_error("Allocated memory error!");

	// copy the file into the m_buffer
	m_result = fread(m_buffer, 1, m_lSize, m_file);
	if (m_result != m_lSize) {
		free(m_buffer);
		throw std::logic_error("Reading error! Check your file! "
			"You should use only LF or CR endian in your file");
	}
	m_buffStream << m_buffer;
}
File::~File()
{
	if (m_file)
		fclose(m_file);
	if (m_buffer)
		free(m_buffer);
}
bool File::readLine(std::string &buff)
{
	buff.clear();
	std::getline(m_buffStream, buff);
	return !m_buffStream.eof();
}
void File::writeToFile(std::string &&buff)
{
	fwrite(buff.c_str(), sizeof(char), buff.size(), m_file);
}
