#include "MarioException.h"

MarioException::MarioException(int line, const char* file) noexcept
	:
	line(line),
	file(file)
{}

const char* MarioException::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl << GetOriginString();
	whatBuffer = oss.str();

	return whatBuffer.c_str();
}

const char* MarioException::GetType() const noexcept
{
	return "Mario's Exception";
}

int MarioException::GetLine() const noexcept
{
	return line;
}

const std::string& MarioException::GetFile() const noexcept
{
	return file;
}

std::string MarioException::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File] " << file << std::endl << "[Line] " << line;
	
	return oss.str();
}