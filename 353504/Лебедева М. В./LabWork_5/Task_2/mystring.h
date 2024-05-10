#ifndef MYSTRING_H
#define MYSTRING_H

#include "String_global.h"
#include <memory>
#include <iterator>

namespace my
{
    extern "C" void* memcpy(void* s1, const void* s2, size_t n);
    extern "C" void* memmove(void* s1, const void* s2, size_t n);
    extern "C" char* strcpy(char* s1, const char* s2);
    extern "C" char* strncpy(char* s1, const char* s2, size_t n);
    extern "C" char* strcat(char* s1, const char* s2);
    extern "C" char* strncat(char* s1, const char* s2, size_t n);
    extern "C" int memcmp(const void* s1, const void* s2, size_t n);
    extern "C" int strcmp(const char* s1, const char* s2) noexcept;
    // strcoll
    extern "C" int strncmp(const char* s1, const char* s2, size_t n) noexcept;
    //strxfrm
    extern "C" size_t strcspn(const char* s1, const char* s2);
    //strtok
    extern "C" void* memset(void* s, int c, size_t n);
    //my_strerror
    extern "C" size_t strlen(const char* s);
}  // namespace my

    const size_t NO_POS = -1;

class STRING_EXPORT String
{
private:
    std::unique_ptr<char[]> _data;
    size_t _size;
    size_t _capacity;

    using iterator = char*;
    using const_iterator = const char*;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

public:
    String();
    String(const char *str);
    String(size_t amnt, char c);
    String(const String &other);
    String(String &&other) noexcept;
    String& operator=(const String& other);
    String& operator=(String&& other) noexcept;
    ~String() = default;

    void resize(size_t newSize);
    void reserve(size_t newSize);
    bool empty() const noexcept;
    size_t length() const noexcept;
    size_t size() const noexcept;
    size_t capacity() const noexcept;
    void shrink_to_fit();

    char& at(size_t pos);
    const char& at(size_t pos) const;
    char& operator[](size_t pos);
    const char& operator[](size_t pos) const;
    char& front();
    const char& front() const;
    char& back();
    const char& back() const;
    const char* c_str() const noexcept;
    const char* data() const noexcept;

    iterator begin() noexcept;
    const_iterator begin() const noexcept;
    iterator end() noexcept;
    const_iterator end() const noexcept;
    reverse_iterator rbegin() noexcept;
    const_reverse_iterator rbegin() const noexcept;
    reverse_iterator rend() noexcept;
    const_reverse_iterator rend() const noexcept;

    void clear() noexcept;
    void erase(size_t pos, size_t len);
    void push_back(char c);
    void pop_back() noexcept;
    size_t copy(char* dest, size_t len, size_t pos = 0) const;

    void insert(size_t pos, const char* str);
    void insert(size_t pos, const String& str);
    void insert(size_t pos, size_t n, char c);

    void append(const char* str);
    void append(const String& str);
    void append(size_t n, char c);

    void replace(size_t pos, size_t len, const char* str);
    void replace(size_t pos, size_t len, const String& str);

    size_t find(const String& str, size_t pos = 0) const noexcept;
    size_t find(const char* str, size_t pos = 0) const noexcept;
    size_t rfind(const char* str, size_t pos) const noexcept;
    size_t rfind(const char* str) const noexcept;
    size_t rfind(const String& str, size_t pos) const noexcept;
    size_t rfind(const String& str) const noexcept;

    int compare(const String& str) const noexcept;

    friend String operator+(const String& lhs, const String& rhs);
    friend String operator+(const String& lhs, char rhs);
    friend String operator+(char lhs, const String& rhs);

    friend bool operator==(const String& lhs, const String& rhs) noexcept;
    friend bool operator!=(const String& lhs, const String& rhs) noexcept;
    friend bool operator<(const String& lhs, const String& rhs) noexcept;
    friend bool operator>(const String& lhs, const String& rhs) noexcept;
    friend bool operator<=(const String& lhs, const String& rhs) noexcept;
    friend bool operator>=(const String& lhs, const String& rhs) noexcept;
};

std::ostream& operator<<(std::ostream& os, const String& obj);

#endif // MYSTRING_H
