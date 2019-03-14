#pragma once

// special thanks to Chili for providing WindowsMessageMap source logic

#include <unordered_map>
#include <Windows.h>
#include <string>
#include <sstream>
#include <iomanip>

// WindowsMessageMap is a specialized exception type which gives more information about where the Exception originates from.
class WindowsMessageMap
{
public:
	#pragma region CTOR 

	// CTOR provides the basic WindowsMessageMap object that formats strings for which windows message is occurring. 
	WindowsMessageMap();

	#pragma endregion

	#pragma region Methods
	
	// Operator () defines the logic to format a nice readable string for which WM_ message is occurring.
	std::string operator()( DWORD msg, LPARAM lp, WPARAM wp ) const;

	#pragma endregion
private:
	std::unordered_map<DWORD, std::string> map;				// the map of the useful WM messages private member data
};