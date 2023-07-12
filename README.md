# GString

GString is a C++ class that provides various string manipulation functions. It is designed to be a lightweight alternative to the standard library string class. It includes functions for string concatenation, comparison, manipulation, conversion, and more.

## Usage

To use the GString class, include the necessary header files and create an instance of the class.

```cpp
#include <iostream>
#include "GString.h"

int main()
{
    GString str1 = "Hello";
    GString str2 = "World";
    GString str3 = str1 + " " + str2;

    std::cout << str3 << std::endl;

    return 0;
}
```

Output:
```
Hello World
```

## Functions

### `GString(const char* str = "")`

Constructor that creates a GString object from a C-style string.

Example:
```cpp
GString str = "Hello";
```

### `GString(const GString& other)`

Copy constructor that creates a GString object from another GString object.

Example:
```cpp
GString str1 = "Hello";
GString str2 = str1;
```

### `~GString()`

Destructor that frees the memory allocated by the GString object.

Example:
```cpp
GString str = "Hello";
// ...
```

### `int length() const`

Returns the length of the GString object.

Example:
```cpp
GString str = "Hello";
int len = str.length();
```

### `const char* c_str() const`

Returns a C-style string representation of the GString object.

Example:
```cpp
GString str = "Hello";
const char* cstr = str.c_str();
```

### `GString& operator=(const GString& other)`

Assignment operator that assigns the value of another GString object to the current object.

Example:
```cpp
GString str1 = "Hello";
GString str2 = "World";
str2 = str1;
```

### `const char& operator[](int index) const`

Returns a reference to the character at the specified index in the GString object. The returned reference cannot be modified.

Example:
```cpp
GString str = "Hello";
char ch = str[0];
```

### `char& operator[](int index)`

Returns a reference to the character at the specified index in the GString object. The returned reference can be modified.

Example:
```cpp
GString str = "Hello";
str[0] = 'h';
```

### `GString operator+(const GString& other) const`

Concatenates two GString objects and returns the result as a new GString object.

Example:
```cpp
GString str1 = "Hello";
GString str2 = "World";
GString str3 = str1 + " " + str2;
```

### `GString& operator+=(const GString& other)`

Concatenates another GString object to the current GString object.

Example:
```cpp
GString str1 = "Hello";
GString str2 = "World";
str1 += " " + str2;
```

### `bool operator==(const GString& other) const`

Compares the current GString object with another GString object and returns true if they are equal, false otherwise.

Example:
```cpp
GString str1 = "Hello";
GString str2 = "World";
if (str1 == str2)
{
    // ...
}
```

### `friend std::ostream& operator<<(std::ostream& os, const GString& gstring)`

Overloads the << operator to allow printing a GString object to an output stream.

Example:
```cpp
GString str = "Hello";
std::cout << str << std::endl;
```

### `GString reverse() const`

Returns a new GString object with the characters reversed.

Example:
```cpp
GString str = "Hello";
GString reversed = str.reverse();
```

### `void replaceAll(const GString& subStr, const GString& newStr)`

Replaces all occurrences of a substring with a new string.

Example:
```cpp
GString str = "Hello World";
str.replaceAll("World", "Universe");
```

### `int find(const GString& subStr, int startPos = 0) const`

Finds the first occurrence of a substring starting from a specified position. Returns the index of the first occurrence or -1 if not found.

Example:
```cpp
GString str = "Hello World";
int index = str.find("World");
```

### `bool isPalindrome() const`

Checks if the GString object is a palindrome (reads the same forwards and backwards). Returns true if it is, false otherwise.

Example:
```cpp
GString str = "racecar";
if (str.isPalindrome())
{
    // ...
}
```

### `std::string toStdString() const`

Converts the GString object to a standard library string.

Example:
```cpp
GString str = "Hello";
std::string stdStr = str.toStdString();
```

### `int toInt() const`

Converts the GString object to an integer.

Example:
```cpp
GString str = "123";
int num = str.toInt();
```

### `float toFloat() const`

Converts the GString object to a float.

Example:
```cpp
GString str = "3.14";
float num = str.toFloat();
```

### `double toDouble() const`

Converts the GString object to a double.

Example:
```cpp
GString str = "3.14";
double num = str.toDouble();
```

### `long toLong() const`

Converts the GString object to a long.

Example:
```cpp
GString str = "123";
long num = str.toLong();
```

### `long long toLongLong() const`

Converts the GString object to a long long.

Example:
```cpp
GString str = "123";
long long num = str.toLongLong();
```

### `std::string toBinary() const`

Converts the GString object to a binary string.

Example:
```cpp
GString str = "Hello";
std::string binaryStr = str.toBinary();
```

### `std::string toHex() const`

Converts the GString object to a hexadecimal string.

Example:
```cpp
GString str = "Hello";
std::string hexStr = str.toHex();
```

### `std::string toOctal() const`

Converts the GString object to an octal string.

Example:
```cpp
GString str = "Hello";
std::string octalStr = str.toOctal();
```

### `GString operator-(const GString& other) const`

Removes all occurrences of a substring from the current GString object and returns the result as a new GString object.

Example:
```cpp
GString str = "Hello World";
GString result = str - "World";
```

### `bool isEmpty() const`

Checks if the GString object is empty (has zero length). Returns true if it is, false otherwise.

Example:
```cpp
GString str = "";
if (str.isEmpty())
{
    // ...
}
```

### `GString substr(int startPos, int length = -1) const`

Returns a new GString object that is a substring of the current GString object, starting from the specified position and with the specified length. If length is not provided, it defaults to the remaining length of the string.

Example:
```cpp
GString str = "Hello World";
GString substr = str.substr(6, 5);
```

### `GString caesarEncrypt(int shift) const`

Encrypts the GString object using the Caesar cipher with the specified shift and returns the encrypted string as a new GString object.

Example:
```cpp
GString str = "Hello";
GString encrypted = str.caesarEncrypt(3);
```

### `GString caesarDecrypt(int shift) const`

Decrypts the GString object using the Caesar cipher with the specified shift and returns the decrypted string as a new GString object.

Example:
```cpp
GString str = "Khoor";
GString decrypted = str.caesarDecrypt(3);
```

### `GString xorEncrypt(char key) const`

Encrypts the GString object using the XOR cipher with the specified key and returns the encrypted string as a new GString object.

Example:
```cpp
GString str = "Hello";
GString encrypted = str.xorEncrypt('A');
```

### `GString xorDecrypt(char key) const`

Decrypts the GString object using the XOR cipher with the specified key and returns the decrypted string as a new GString object.

Example:
```cpp
GString str = "Jgnnq";
GString decrypted = str.xorDecrypt('A');
```

### `bool startsWith(const GString& subStr) const`

Checks if the GString object starts with a specified substring. Returns true if it does, false otherwise.

Example:
```cpp
GString str = "Hello World";
if (str.startsWith("Hello"))
{
    // ...
}
```

### `bool endsWith(const GString& subStr) const`

Checks if the GString object ends with a specified substring. Returns true if it does, false otherwise.

Example:
```cpp
GString str = "Hello World";
if (str.endsWith("World"))
{
    // ...
}
```

### `GString trimmed() const`

Returns a new GString object with leading and trailing whitespace characters removed.

Example:
```cpp
GString str = "  Hello World  ";
GString trimmed = str.trimmed();
```

### `std::vector<GString> split(const GString& delimiter) const`

Splits the GString object into a vector of substrings based on a specified delimiter and returns the result as a vector of GString objects.

Example:
```cpp
GString str = "Hello,World";
std::vector<GString> parts = str.split(",");
```

### `int count(const GString& subStr) const`

Counts the number of occurrences of a substring in the GString object and returns the count.

Example:
```cpp
GString str = "Hello World";
int count = str.count("l");
```

### `GString UpperCase() const`

Converts all characters in the GString object to uppercase and returns the result as a new GString object.

Example:
```cpp
GString str = "hello";
GString upper = str.UpperCase();
```

### `GString LowerCase() const`

Converts all characters in the GString object to lowercase and returns the result as a new GString object.

Example:
```cpp
GString str = "HELLO";
GString lower = str.LowerCase();
```

### `std::vector<GString> splitLines() const`

Splits the GString object into a vector of lines (based on newline characters) and returns the result as a vector of GString objects.

Example:
```cpp
GString str = "Hello\nWorld";
std::vector<GString> lines = str.splitLines();
```

### `bool isNumeric() const`

Checks if the GString object contains only numeric characters. Returns true if it does, false otherwise.

Example:
```cpp
GString str = "123";
if (str.isNumeric())
{
    // ...
}
```

### `void replace(const GString& oldStr, const GString& newStr)`

Replaces the first occurrence of a substring with a new string.

Example:
```cpp
GString str = "Hello World";
str.replace("World", "Universe");
```

### `int countOccurrences(const GString& subStr) const`

Counts the number of occurrences of a substring in the GString object and returns the count.

Example:
```cpp
GString str = "Hello World";
int count = str.countOccurrences("l");
```

### `void insert(int index, const GString& str)`

Inserts a substring into the GString object at the specified index.

Example:
```cpp
GString str = "Hello";
str.insert(2, "XYZ");
```

### `void remove(int index, int count)`

Removes a specified number of characters from the GString object starting at the specified index.

Example:
```cpp
GString str = "Hello World";
str.remove(6, 5);
```

### `GString toUpper() const`

Converts all characters in the GString object to uppercase and returns the result as a new GString object.

Example:
```cpp
GString str = "hello";
GString upper = str.toUpper();
```

### `GString toLower() const`

Converts all characters in the GString object to lowercase and returns the result as a new GString object.

Example:
```cpp
GString str = "HELLO";
GString lower = str.toLower();
```

### `bool contains(const GString& subStr) const`

Checks if the GString object contains a specified substring. Returns true if it does, false otherwise.

Example:
```cpp
GString str = "Hello World";
if (str.contains("World"))
{
    // ...
}
```

### `bool isAlphaNumeric() const`

Checks if the GString object contains only alphanumeric characters. Returns true if it does, false otherwise.

Example:
```cpp
GString str = "Hello123";
if (str.isAlphaNumeric())
{
    // ...
}
```

### `void replaceAllChars(char oldChar, char newChar)`

Replaces all occurrences of a character with a new character.

Example:
```cpp
GString str = "Hello World";
str.replaceAllChars('o', 'x');
```

### `void reverseInPlace()`

Reverses the characters of the GString object in place.

Example:
```cpp
GString str = "Hello";
str.reverseInPlace();
```

### `GString stripLeft() const`

Returns a new GString object with leading whitespace characters removed.

Example:
```cpp
GString str = "  Hello World";
GString stripped = str.stripLeft();
```

### `GString stripRight() const`

Returns a new GString object with trailing whitespace characters removed.

Example:
```cpp
GString str = "Hello World  ";
GString stripped = str.stripRight();
```

### `GString strip() const`

Returns a new GString object with leading and trailing whitespace characters removed.

Example:
```cpp
GString str = "  Hello World  ";
GString stripped = str.strip();
```

### `void replaceFirst(const GString& subStr, const GString& newStr)`

Replaces the first occurrence of a substring with a new string.

Example:
```cpp
GString str = "Hello World";
str.replaceFirst("World", "Universe");
```

### `void replaceLast(const GString& subStr, const GString& newStr)`

Replaces the last occurrence of a substring with a new string.

Example:
```cpp
GString str = "Hello World";
str.replaceLast("World", "Universe");
```

### `GString toTitleCase() const`

Converts the GString object to title case (capitalizes the first letter of each word) and returns the result as a new GString object.

Example:
```cpp
GString str = "hello world";
GString title = str.toTitleCase();
```

### `void replaceChars(const GString& chars, char newChar)`

Replaces all occurrences of specified characters with a new character.

Example:
```cpp
GString str = "Hello World";
str.replaceChars("lo", 'x');
```
