#include "String.h"
#include <iostream>

String::String()
{
	m_string = new char[1];	
}

// Function to allow setting the string
String::String(const char* _str)
{
	// Get the length of the inputted string + 1 to store \0
	int length = strlen(_str) + 1;

	// Make a new char array with the length
	m_string = new char[length];

	// Copy it to the new array
	strcpy_s(
		m_string,
		length,
		_str
	);
}

// Allows setting the string using another string as it's input
String::String(const String& _other)
{
	// Get the length of the inputted string + 1 to store \0
	int length = strlen(_other.CStr()) + 1;

	// Make a new char array with the length
	m_string = new char[length];

	// Copy it to the new array
	strcpy_s(
		m_string,
		length,
		_other.CStr()
	);
}

// FIX THIS
//String::~String()
//{
//	delete[] m_string;
//}

size_t String::Length() const
{
	return strlen(m_string); // Uses strlen to get the length of the current string (m_string)
}

// Returns the character in the area of the array thats requested
char& String::CharacterAt(size_t _index)
{
	int sizeOfArray = strlen(m_string) + 1;
	if (_index < sizeOfArray || _index < 0) {
		return m_string[_index]; // Returns the char at the location requested
	}
	else {
		return m_string[sizeOfArray]; // Returns the section of the array with \0 to avoid a buffer overflow
	}
}


// Returns the character in the area of the array thats requested
const char& String::CharacterAt(size_t _index) const
{
	int sizeOfArray = strlen(m_string) + 1;
	if (_index < sizeOfArray || _index < 0) {
		return m_string[_index]; // Returns the char at the location requested
	}
	else {
		return m_string[sizeOfArray]; // Returns the section of the array with \0 to avoid a buffer overflow
	}
}

bool String::EqualTo(const String& _other) const
{
	if (strcmp(m_string, _other.CStr()) == 0) {
		return true;
	}
	else {
		return false;
	}
}

// Appends the provided string to the end of the string
String& String::Append(const String& _str)
{
	int totalSize = strlen(m_string) + strlen(_str.CStr()) + 1;

	// Create a temporary table to store char data in
	char * tmp = new char[totalSize];

	// Add the 2 strings together
	strcpy_s(tmp, totalSize, m_string);
	strcat_s(tmp, totalSize, _str.CStr());

	// Convert to a string object and delete the temp array
	String tmpString = tmp;
	delete[] tmp;
	return tmpString;
}

// Prepends the provided string to the end of the string
String& String::Prepend(const String& _str)
{
	int totalSize = strlen(m_string) + strlen(_str.CStr()) + 1;

	// Create a temporary table to store char data in
	char* tmp = new char[totalSize];

	// Add the 2 strings together
	strcpy_s(tmp, totalSize, _str.CStr());
	strcat_s(tmp, totalSize, m_string);

	// Convert to a string object and delete the temp array
	String tmpString = tmp;
	delete[] tmp;
	return tmpString;
}

// Responds with the string
const char* String::CStr() const
{
	return m_string;
}

// Writes the string to console
void String::WriteToConsole()
{
	std::cout << m_string << "\n";
}

String& String::ToLower()
{
	// Get the length of the string
	int stringLength = strlen(m_string);

	// Create a temporary table to store char data in
	char* tmp = new char[stringLength + 1];

	// Loop through all the letters and check if they're lower case
	for (int i = 0; i <= stringLength; i++) {
		if (m_string[i] >= 65 && m_string[i] <= 90) {
			std::cout << "Converting letter " << m_string[i] << " to lowercase\n";
			tmp[i] = m_string[i] + 32; // If it's lower case take 32 which'll make it upper case
		}
		else {
			tmp[i] = m_string[i];
		}
	}

	String tmpString = tmp; // Convert the char array to a string object
	delete[] tmp;
	return tmpString;
}

// Responds with an upper-case version of the string
String& String::ToUpper()
{
	// Get the length of the string
	int stringLength = strlen(m_string);

	// Create a temporary table to store char data in
	char * tmp = new char[stringLength + 1];

	// Loop through all the letters and check if they're lower case
	for (int i = 0; i <= stringLength; i++) {
		if (m_string[i] >= 97 && m_string[i] <= 122) {
			tmp[i] = m_string[i] - 32; // If it's lower case take 32 which'll make it upper case
		}
		else {
			tmp[i] = m_string[i];
		}
	}
	
	String tmpString = tmp; // Convert the char array to a string object
	delete[] tmp;
	return tmpString;
}

// Checks if the string contains the same contents as another
size_t String::Find(const String& _str)
{
	// Sets up required variables
	int stringSize = strlen(m_string);
	int letterToLookFor = 0;
	int sizeOfStr = strlen(_str.CStr());

	// Loops through every array of the string
	for (int i = 0; i < stringSize; i++) {
		// Checks if the char matches up with the char to check on the other array
		if (m_string[i] == _str.CStr()[letterToLookFor]) {
			// if it is matching, move on to the next char to look for
			letterToLookFor++;
			if (letterToLookFor >= sizeOfStr) {
				// return the position of the char
				return i - (letterToLookFor - 1);
			}
		}
		else {
			// if it doesn't match reset to the first char
			letterToLookFor = 0;
		}
	}
	return -1; // This will only be called if it doesn't contain the string
}

size_t String::Find(size_t _startIndex, const String& _str)
{
	// Sets up required variables
	int stringSize = strlen(m_string);
	int letterToLookFor = 0;
	int sizeOfStr = strlen(_str.CStr());

	if (_startIndex >= stringSize) {
		return -1;
	}

	// Loops through every array of the string
	for (int i = _startIndex; i < stringSize; i++) {
		// Checks if the char matches up with the char to check on the other array
		if (m_string[i] == _str.CStr()[letterToLookFor]) {
			// if it is matching, move on to the next char to look for
			letterToLookFor++;
			if (letterToLookFor >= sizeOfStr) {
				// return the position of the char
				return i - (letterToLookFor - 1);
			}
		}
		else {
			// if it doesn't match reset to the first char
			letterToLookFor = 0;
		}
	}
	return -1; // This will only be called if it doesn't contain the string
}

//String& String::Replace(const String& _find, const String& _replace)
//{
//	// TODO: insert return statement here
//}
//
//String& String::ReadFromConsole()
//{
//	// TODO: insert return statement here
//}

// Checks if the strings are equal and returns the results
bool String::operator==(const String& _other)
{
	if (strcmp(m_string, _other.CStr()) == 0) {
		return true;
	}
	else {
		return false;
	}
}

// Checks if the 2 strings aren't the same then returns the results
bool String::operator!=(const String& _other)
{
	if (strcmp(m_string, _other.CStr()) == 0) {
		return false;
	}
	else {
		return true;
	}
}

bool String::operator<(const String& _other)
{
	if (strcmp(m_string, _other.CStr()) == 1) {
		return true;
	}
	else {
		return false;
	}
}

bool String::operator<=(const String& _other)
{
	if (strcmp(m_string, _other.CStr()) == 1 || strcmp(m_string, _other.CStr()) == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool String::operator>(const String& _other)
{
	if (strcmp(m_string, _other.CStr()) == -1) {
		return true;
	}
	else {
		return false;
	}
}

bool String::operator>=(const String& _other)
{
	if (strcmp(m_string, _other.CStr()) == -1 || strcmp(m_string, _other.CStr()) == 0) {
		return true;
	}
	else {
		return false;
	}
}

// Allows setting the string after being set previously
String& String::operator=(const String& _str)
{
	// Get the length of the inputted string + 1 to store \0
	int length = strlen(_str.CStr()) + 1;

	// Setup a new array
	m_string = new char[length];

	// Copy it to the new array
	strcpy_s(
		m_string,
		length,
		_str.CStr()
	);

	// Convert the array to a string
	String tmpString = m_string;

	return tmpString;
}

// Returns the character in the area of the array thats requested
char& String::operator[](size_t _index)
{
	int sizeOfArray = strlen(m_string) + 1;
	if (_index < sizeOfArray || _index < 0) {
		return m_string[_index]; // Returns the char at the location requested
	}
	else {
		return m_string[sizeOfArray]; // Returns the section of the array with \0 to avoid a buffer overflow
	}
}

// Returns the character in the area of the array thats requested
const char& String::operator[](size_t _index) const
{
	int sizeOfArray = strlen(m_string) + 1;
	if (_index < sizeOfArray || _index < 0) {
		return m_string[_index]; // Returns the char at the location requested
	}
	else {
		return m_string[sizeOfArray]; // Returns the section of the array with \0 to avoid a buffer overflow
	}
}
