#ifndef STRING_H
#define STRING_H
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>

class String
{
private:
	
	int length;

public:
	char* cstring;
	String();
	String(const char* source);
	String(const String& source);
	String(String&& source) noexcept;
	~String();

	int getLength() const;

	String& operator=(const char* source);
	String& operator=(const String& source);
	String& operator=(String&& source) noexcept;
	const char& operator[](int index) const;
	friend String operator+(const String& lhs, const String& rhs);
	friend bool operator==(const String& lhs, const String& rhs);
	friend bool operator==(const String& lhs, int length);
	friend std::ostream& operator<<(std::ostream& os, const String& string);
};

namespace std {
	template <>
	struct hash<String> {
		size_t operator()(const String& s) const {
			return hash<string>()(s.cstring);
		}
	};
}

#endif