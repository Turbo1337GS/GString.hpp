#include <iostream>
#include <bitset>
#include <sstream>
#include <vector>


class GString
{
private:
    char* m_data;

public:
    GString(const char* str = "")
    {
        int length = customStrlen(str);
        m_data = new char[length + 1];
        customStrcpy(m_data, str);
    }
    GString(const GString& other)
    {
        int length = customStrlen(other.m_data);
        m_data = new char[length + 1];
        customStrcpy(m_data, other.m_data);
    }
    ~GString()
    {
        delete[] m_data;
    }
    int length() const
    {
        return customStrlen(m_data);
    }
    const char* c_str() const
    {
        return m_data;
    }
    GString& operator=(const GString& other)
    {
        if (this != &other)
        {
            delete[] m_data;
            int length = customStrlen(other.m_data);
            m_data = new char[length + 1];
            customStrcpy(m_data, other.m_data);
        }
        return *this;
    }
    const char& operator[](int index) const
    {
        return m_data[index];
    }
    char& operator[](int index)
    {
        return m_data[index];
    }
    GString operator+(const GString& other) const
    {
        int length1 = length();
        int length2 = other.length();
        int newLength = length1 + length2;
        char* newData = new char[newLength + 1];
        customStrcpy(newData, m_data);
        customStrcpy(newData + length1, other.m_data);
        GString result(newData);
        delete[] newData;
        return result;
    }
    GString& operator+=(const GString& other)
    {
        *this = *this + other;
        return *this;
    }
    bool operator==(const GString& other) const
    {
        return customStrcmp(m_data, other.m_data) == 0;
    }
    friend std::ostream& operator<<(std::ostream& os, const GString& gstring)
    {
        os << gstring.m_data;
        return os;
    }
    GString reverse() const
    {
        int length = this->length();
        char* reversedData = new char[length + 1];
        for (int i = 0; i < length; i++)
        {
            reversedData[i] = m_data[length - i - 1];
        }
        reversedData[length] = '\0';
        GString result(reversedData);
        delete[] reversedData;
        return result;
    }
    void replaceAll(const GString& subStr, const GString& newStr)
    {
        int subStrLength = subStr.length();
        int newStrLength = newStr.length();
        GString result;
        int start = 0;
        int foundPos = 0;
        while ((foundPos = find(subStr, start)) != -1)
        {
            result += GString(getSubstring(m_data, start, foundPos - start));
            result += newStr;
            start = foundPos + subStrLength;
        }
        result += GString(getSubstring(m_data, start));
        *this = result;
    }
    int find(const GString& subStr, int startPos = 0) const
    {
        int length = this->length();
        int subStrLength = subStr.length();
        if (subStrLength == 0 || startPos >= length)
        {
            return -1;
        }
        for (int i = startPos; i <= length - subStrLength; i++)
        {
            bool found = true;
            for (int j = 0; j < subStrLength; j++)
            {
                if (m_data[i + j] != subStr[j])
                {
                    found = false;
                    break;
                }
            }
            if (found)
            {
                return i;
            }
        }
        return -1;
    }
    bool isPalindrome() const
    {
        int length = this->length();
        int halfLength = length / 2;
        for (int i = 0; i < halfLength; i++)
        {
            if (m_data[i] != m_data[length - i - 1])
            {
                return false;
            }
        }
        return true;
    }
    std::string toStdString() const
    {
        return std::string(m_data);
    }
    int toInt() const
    {
        return customAtoi(m_data);
    }
    float toFloat() const
    {
        return customAtof(m_data);
    }
    double toDouble() const
    {
        return customAtof(m_data);
    }
    long toLong() const
    {
        return customAtol(m_data);
    }
    long long toLongLong() const
    {
        return customAtoll(m_data);
    }
    std::string toBinary() const
    {
        std::stringstream ss;
        int length = this->length();
        for (int i = 0; i < length; i++)
        {
            ss << std::bitset<8>(m_data[i]);
        }
        return ss.str();
    }
    std::string toHex() const
    {
        std::stringstream ss;
        int length = this->length();
        for (int i = 0; i < length; i++)
        {
            ss << std::hex << (int)m_data[i];
        }
        return ss.str();
    }
    std::string toOctal() const
    {
        std::stringstream ss;
        int length = this->length();
        for (int i = 0; i < length; i++)
        {
            ss << std::oct << (int)m_data[i];
        }
        return ss.str();
    }
    GString operator-(const GString& other) const
    {
        GString result(*this);
        result.replaceAll(other, "");
        return result;
    }
    
    bool isEmpty() const
    {
        return length() == 0;
    }
    GString substr(int startPos, int length = -1) const
    {
        if (length == -1)
        {
            length = this->length() - startPos;
        }
        return GString(getSubstring(m_data, startPos, length));
    }
    GString caesarEncrypt(int shift) const
    {
        GString result(*this);
        int length = this->length();
        for (int i = 0; i < length; i++)
        {
            if (isalpha(result[i]))
            {
                if (isupper(result[i]))
                {
                    result[i] = ((result[i] - 'A' + shift) % 26) + 'A';
                }
                else
                {
                    result[i] = ((result[i] - 'a' + shift) % 26) + 'a';
                }
            }
        }
        return result;
    }
    GString caesarDecrypt(int shift) const
    {
        return caesarEncrypt(26 - shift);
    }
    GString xorEncrypt(char key) const
    {
        GString result(*this);
        int length = this->length();
        for (int i = 0; i < length; i++)
        {
            result[i] = result[i] ^ key;
        }
        return result;
    }
    GString xorDecrypt(char key) const
    {
        return xorEncrypt(key);
    }
    bool startsWith(const GString& subStr) const
    {
        int subStrLength = subStr.length();
        if (subStrLength > length())
        {
            return false;
        }
        for (int i = 0; i < subStrLength; i++)
        {
            if (m_data[i] != subStr[i])
            {
                return false;
            }
        }
        return true;
    }
    bool endsWith(const GString& subStr) const
    {
        int subStrLength = subStr.length();
        int strLength = length();
        if (subStrLength > strLength)
        {
            return false;
        }
        for (int i = 0; i < subStrLength; i++)
        {
            if (m_data[strLength - subStrLength + i] != subStr[i])
            {
                return false;
            }
        }
        return true;
    }
    GString trimmed() const
    {
        int start = 0;
        int end = length() - 1;
        while (start <= end && isspace(m_data[start]))
        {
            start++;
        }
        while (end >= start && isspace(m_data[end]))
        {
            end--;
        }
        return substr(start, end - start + 1);
    }
    std::vector<GString> split(const GString& delimiter) const
    {
        std::vector<GString> result;
        int startPos = 0;
        int foundPos = find(delimiter, startPos);
        while (foundPos != -1)
        {
            result.push_back(getSubstring(m_data, startPos, foundPos - startPos));
            startPos = foundPos + delimiter.length();
            foundPos = find(delimiter, startPos);
        }
        result.push_back(getSubstring(m_data, startPos));
        return result;
    }
    int count(const GString& subStr) const
    {
        int subStrLength = subStr.length();
        int count = 0;
        int startPos = 0;
        int foundPos = find(subStr, startPos);
        while (foundPos != -1)
        {
            count++;
            startPos = foundPos + subStrLength;
            foundPos = find(subStr, startPos);
        }
        return count;
    }
GString UpperCase() const
{
    GString result(*this);
    int length = this->length();
    for (int i = 0; i < length; i++)
    {
        if (islower(result[i]))
        {
            result[i] = toupper(result[i]);
        }
    }
    return result;
}
GString LowerCase() const
{
    GString result(*this);
    int length = this->length();
    for (int i = 0; i < length; i++)
    {
        if (isupper(result[i]))
        {
            result[i] = tolower(result[i]);
        }
    }
    return result;
}

std::vector<GString> splitLines() const
{
    std::vector<GString> result;
    GString delimiter = "\n";
    result = split(delimiter);
    return result;
}
bool isNumeric() const
{
    int length = this->length();
    for (int i = 0; i < length; i++)
    {
        if (!isdigit(m_data[i]))
        {
            return false;
        }
    }
    return true;
}
void replace(const GString& oldStr, const GString& newStr)
{
    replaceAll(oldStr, newStr);
}

int countOccurrences(const GString& subStr) const
{
    int count = 0;
    int startPos = 0;
    int foundPos = find(subStr, startPos);
    while (foundPos != -1)
    {
        count++;
        startPos = foundPos + subStr.length();
        foundPos = find(subStr, startPos);
    }
    return count;
}

void insert(int index, const GString& str)
{
    int length = this->length();
    if (index < 0 || index > length)
    {
        return;
    }
    int strLength = str.length();
    char* newData = new char[length + strLength + 1];
    customStrncpy(newData, m_data, index);
    customStrcpy(newData + index, str.c_str());
    customStrcpy(newData + index + strLength, m_data + index);
    delete[] m_data;
    m_data = newData;
}

void remove(int index, int count)
{
    int length = this->length();
    if (index < 0 || index >= length || count <= 0)
    {
        return;
    }
    if (index + count > length)
    {
        count = length - index;
    }
    int newLength = length - count;
    char* newData = new char[newLength + 1];
    customStrncpy(newData, m_data, index);
    customStrcpy(newData + index, m_data + index + count);
    delete[] m_data;
    m_data = newData;
}

GString toUpper() const
{
    GString result(*this);
    int length = this->length();
    for (int i = 0; i < length; i++)
    {
        result[i] = toupper(result[i]);
    }
    return result;
}

GString toLower() const
{
    GString result(*this);
    int length = this->length();
    for (int i = 0; i < length; i++)
    {
        result[i] = tolower(result[i]);
    }
    return result;
}

bool contains(const GString& subStr) const
{
    return find(subStr) != -1;
}

bool isAlphaNumeric() const
{
    int length = this->length();
    for (int i = 0; i < length; i++)
    {
        if (!isalnum(m_data[i]))
        {
            return false;
        }
    }
    return true;
}
void replaceAllChars(char oldChar, char newChar)
{
    int length = this->length();
    for (int i = 0; i < length; i++)
    {
        if (m_data[i] == oldChar)
        {
            m_data[i] = newChar;
        }
    }
}
void reverseInPlace()
{
    int length = this->length();
    int halfLength = length / 2;
    for (int i = 0; i < halfLength; i++)
    {
        char temp = m_data[i];
        m_data[i] = m_data[length - i - 1];
        m_data[length - i - 1] = temp;
    }
}



GString stripLeft() const
{
    int start = 0;
    int end = length() - 1;
    while (start <= end && isspace(m_data[start]))
    {
        start++;
    }
    return substr(start);
}

GString stripRight() const
{
    int start = 0;
    int end = length() - 1;
    while (end >= start && isspace(m_data[end]))
    {
        end--;
    }
    return substr(0, end - start + 1);
}

GString strip() const
{
    return stripLeft().stripRight();
}
void replaceFirst(const GString& subStr, const GString& newStr)
{
    int startPos = find(subStr);
    if (startPos != -1)
    {
        replaceAll(subStr, newStr);
    }
}

void replaceLast(const GString& subStr, const GString& newStr)
{
    int startPos = find(subStr);
    if (startPos != -1)
    {
        int subStrLength = subStr.length();
        int endPos = startPos + subStrLength;
        GString substringBefore = substr(0, startPos);
        GString substringAfter = substr(endPos);
        *this = substringBefore + newStr + substringAfter;
    }
}
GString toTitleCase() const
{
    GString result(*this);
    int length = this->length();
    bool newWord = true;
    for (int i = 0; i < length; i++)
    {
        if (isspace(result[i]))
        {
            newWord = true;
        }
        else if (newWord)
        {
            result[i] = toupper(result[i]);
            newWord = false;
        }
        else
        {
            result[i] = tolower(result[i]);
        }
    }
    return result;
}

void replaceChars(const GString& chars, char newChar)
{
    int length = this->length();
    int charsLength = chars.length();
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < charsLength; j++)
        {
            if (m_data[i] == chars[j])
            {
                m_data[i] = newChar;
                break;
            }
        }
    }
}


private:
    const char* getSubstring(const char* str, int start, int length = -1) const
    {
        if (length == -1)
        {
            length = customStrlen(str + start);
        }
        char* result = new char[length + 1];
        customStrncpy(result, str + start, length);
        result[length] = '\0';
        return result;
    }
    int customStrlen(const char* str) const
    {
        int length = 0;
        while (str[length] != '\0')
        {
            length++;
        }
        return length;
    }
    void customStrcpy(char* dest, const char* src) const
    {
        int i = 0;
        while (src[i] != '\0')
        {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }
    int customStrcmp(const char* str1, const char* str2) const
    {
        int i = 0;
        while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i])
        {
            i++;
        }
        return str1[i] - str2[i];
    }
    void customStrncpy(char* dest, const char* src, int n) const
    {
        int i = 0;
        while (i < n && src[i] != '\0')
        {
            dest[i] = src[i];
            i++;
        }
        while (i < n)
        {
            dest[i] = '\0';
            i++;
        }
    }
    int customAtoi(const char* str) const
    {
        int result = 0;
        int sign = 1;
        int i = 0;
        if (str[0] == '-')
        {
            sign = -1;
            i++;
        }
        while (str[i] != '\0')
        {
            result = result * 10 + (str[i] - '0');
            i++;
        }
        return result * sign;
    }
    float customAtof(const char* str) const
    {
        float result = 0.0f;
        float fraction = 1.0f;
        int sign = 1;
        int i = 0;
        if (str[0] == '-')
        {
            sign = -1;
            i++;
        }
        while (str[i] != '\0' && str[i] != '.')
        {
            result = result * 10 + (str[i] - '0');
            i++;
        }
        if (str[i] == '.')
        {
            i++;
            while (str[i] != '\0')
            {
                fraction *= 0.1f;
                result = result + (str[i] - '0') * fraction;
                i++;
            }
        }
        return result * sign;
    }
    long customAtol(const char* str) const
    {
        long result = 0;
        int sign = 1;
        int i = 0;
        if (str[0] == '-')
        {
            sign = -1;
            i++;
        }
        while (str[i] != '\0')
        {
            result = result * 10 + (str[i] - '0');
            i++;
        }
        return result * sign;
    }
    long long customAtoll(const char* str) const
    {
        long long result = 0;
        int sign = 1;
        int i = 0;
        if (str[0] == '-')
        {
            sign = -1;
            i++;
        }
        while (str[i] != '\0')
        {
            result = result * 10 + (str[i] - '0');
            i++;
        }
        return result * sign;
    }
}
;

/*
int main()
{
    
    GString str1("Hello");
    GString str2("World");
    GString str3("This is a test string");

    
    std::cout << "Length of str1: " << str1.length() << std::endl;

    
    const char* cstr = str2.c_str();
    std::cout << "C-string representation of str2: " << cstr << std::endl;

    
    char ch = str1[0];
    std::cout << "First character of str1: " << ch << std::endl;

    
    GString str4 = str1 + str2;
    std::cout << "Concatenation of str1 and str2: " << str4 << std::endl;

    
    str1 += str2;
    std::cout << "Concatenation of str1 and str2 (using +=): " << str1 << std::endl;

    
    bool equal = (str1 == str2);
    std::cout << "Are str1 and str2 equal? " << (equal ? "Yes" : "No") << std::endl;

    
    std::cout << "str3: " << str3 << std::endl;

    
    GString reversed = str3.reverse();
    std::cout << "Reversed str3: " << reversed << std::endl;

    
    str3.replaceAll("is", "was");
    std::cout << "str3 after replacing 'is' with 'was': " << str3 << std::endl;

    
    int pos = str3.find("test");
    std::cout << "Position of 'test' in str3: " << pos << std::endl;

    
    bool palindrome = str3.isPalindrome();
    std::cout << "Is str3 a palindrome? " << (palindrome ? "Yes" : "No") << std::endl;

    
    std::string stdStr = str3.toStdString();
    std::cout << "str3 as std::string: " << stdStr << std::endl;

    
    int intValue = str3.toInt();
    std::cout << "str3 as int value: " << intValue << std::endl;

    
    float floatValue = str3.toFloat();
    std::cout << "str3 as float value: " << floatValue << std::endl;

    
    double doubleValue = str3.toDouble();
    std::cout << "str3 as double value: " << doubleValue << std::endl;

    
    long longValue = str3.toLong();
    std::cout << "str3 as long value: " << longValue << std::endl;

    
    long long longLongValue = str3.toLongLong();
    std::cout << "str3 as long long value: " << longLongValue << std::endl;

    
    std::string binaryStr = str3.toBinary();
    std::cout << "str3 as binary string: " << binaryStr << std::endl;

    
    std::string hexStr = str3.toHex();
    std::cout << "str3 as hexadecimal string: " << hexStr << std::endl;

    
    std::string octalStr = str3.toOctal();
    std::cout << "str3 as octal string: " << octalStr << std::endl;

    
    GString str5 = str3 - "is";
    std::cout << "str3 after removing 'is': " << str5 << std::endl;


    
    bool empty = str3.isEmpty();
    std::cout << "Is str3 empty? " << (empty ? "Yes" : "No") << std::endl;

    
    GString substring = str3.substr(5, 2);
    std::cout << "Substring of str3 from position 5 with length 2: " << substring << std::endl;

    
    GString encrypted = str3.caesarEncrypt(1);
    std::cout << "str3 encrypted using Caesar cipher: " << encrypted << std::endl;

    
    GString decrypted = encrypted.caesarDecrypt(1);
    std::cout << "Decrypted version of encrypted: " << decrypted << std::endl;

    
    GString xorEncrypted = str3.xorEncrypt('k');
    std::cout << "str3 encrypted using XOR with key 'k': " << xorEncrypted << std::endl;

    
    GString xorDecrypted = xorEncrypted.xorDecrypt('k');
    std::cout << "Decrypted version of xorEncrypted: " << xorDecrypted << std::endl;

    
    bool startsWith = str3.startsWith("This");
    std::cout << "Does str3 start with 'This'? " << (startsWith ? "Yes" : "No") << std::endl;

    
    bool endsWith = str3.endsWith("string");
    std::cout << "Does str3 end with 'string'? " << (endsWith ? "Yes" : "No") << std::endl;

    
    GString trimmed = str3.trimmed();
    std::cout << "str3 after trimming: " << trimmed << std::endl;

    
    std::vector<GString> splitStrings = str3.split(" ");
    std::cout << "Splitting str3 by space: ";
    for (const GString& splitString : splitStrings)
    {
        std::cout << splitString << " ";
    }
    std::cout << std::endl;

    
    int occurrences = str3.count("is");
    std::cout << "Number of occurrences of 'is' in str3: " << occurrences << std::endl;

    
    GString upperCase = str3.UpperCase();
    std::cout << "str3 in uppercase: " << upperCase << std::endl;

    
    GString lowerCase = str3.LowerCase();
    std::cout << "str3 in lowercase: " << lowerCase << std::endl;

    
    std::vector<GString> lines = str3.splitLines();
    std::cout << "Splitting str3 into lines: ";
    for (const GString& line : lines)
    {
        std::cout << line << " ";
    }
    std::cout << std::endl;

    
    bool numeric = str3.isNumeric();
    std::cout << "Is str3 numeric? " << (numeric ? "Yes" : "No") << std::endl;

    
    str3.replace("is", "was");
    std::cout << "str3 after replacing 'is' with 'was': " << str3 << std::endl;

    
    int occurrenceCount = str3.countOccurrences("is");
    std::cout << "Number of occurrences of 'is' in str3: " << occurrenceCount << std::endl;

    
    str3.insert(8, "not ");
    std::cout << "str3 after inserting 'not ' at position 8: " << str3 << std::endl;

    
    str3.remove(5, 4);
    std::cout << "str3 after removing 4 characters starting from position 5: " << str3 << std::endl;

    
    GString upper = str3.toUpper();
    std::cout << "str3 in uppercase: " << upper << std::endl;

    
    GString lower = str3.toLower();
    std::cout << "str3 in lowercase: " << lower << std::endl;

    
    bool contains = str3.contains("test");
    std::cout << "Does str3 contain 'test'? " << (contains ? "Yes" : "No") << std::endl;

    
    bool alphaNumeric = str3.isAlphaNumeric();
    std::cout << "Is str3 alphanumeric? " << (alphaNumeric ? "Yes" : "No") << std::endl;

    
    str3.replaceAllChars('i', '!');
    std::cout << "str3 after replacing all 'i' characters with '!': " << str3 << std::endl;

    
    str3.reverseInPlace();
    std::cout << "str3 after reversing in place: " << str3 << std::endl;

    
    GString strippedLeft = str3.stripLeft();
    std::cout << "str3 after left stripping: " << strippedLeft << std::endl;

    
    GString strippedRight = str3.stripRight();
    std::cout << "str3 after right stripping: " << strippedRight << std::endl;

    
    GString stripped = str3.strip();
    std::cout << "str3 after stripping: " << stripped << std::endl;

    
    str3.replaceFirst("is", "was");
    std::cout << "str3 after replacing first 'is' with 'was': " << str3 << std::endl;

    
    str3.replaceLast("is", "was");
    std::cout << "str3 after replacing last 'is' with 'was': " << str3 << std::endl;

    
    GString titleCase = str3.toTitleCase();
    std::cout << "str3 in title case: " << titleCase << std::endl;

    
    str3.replaceChars("aeiou", '*');
    std::cout << "str3 after replacing vowels with '*': " << str3 << std::endl;

    return 0;
}*/
