#pragma once

#include <exception>
#include <string>
#include <sstream>

// MarioException is a specialized exception type which gives more information about where the Exception originates from.
class MarioException : public std::exception
{
public:
	#pragma region CTOR

	// CTOR provides the basic MarioException object that reads line number and file exception caught at. 
	MarioException(int line, const char* file) noexcept;

	#pragma endregion

	#pragma region OverRide Defn

	// Returns a null terminated character sequence that may be used to identify the exception.
	const char* what() const noexcept override;

	#pragma endregion

	#pragma region Methods

	// Returns a null terminated character sequence that may be used to represent the Mario Exception.
	virtual const char* GetType() const noexcept;

	// Returns the line number in which the constructor for this Exception object originated from.
	int GetLine() const noexcept;

	// Returns the std string object which represents the fileName of where this Exception object originated from.
	const std::string& GetFile() const noexcept;

	// Returns a formatted std string for readability of the File and Line number of this Exception.
	std::string GetOriginString() const noexcept;

#pragma endregion
private:
	int line;
	std::string file;
protected:
	mutable std::string whatBuffer;
};
