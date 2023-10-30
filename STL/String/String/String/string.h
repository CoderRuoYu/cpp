#pragma once
#include <iostream>
#include <string>
#include <assert.h>
using namespace std;
namespace gao
{
    class string

    {

        friend ostream& operator<<(ostream& _cout, const gao::string& s);
        

        friend istream& operator>>(istream& _cin, gao::string& s);

    public:

        typedef char* iterator;

    public:

        string(const char* str = "")
        {
            int len = strlen(str);
            _size = len;
            _capacity = len;
            _str = new char[_capacity + 1];
            memmove(_str, str, _size + 1);
        }

        string(const string& s)
        {
            _size = s._size;
            _capacity = s._capacity;
            _str = new char[_capacity + 1];
            memmove(_str, s._str, _size + 1);
        }
         
        

        ~string()
        {
            _size = 0;
            _capacity = 0;
            delete[] _str;
            _str = nullptr;
        }

        iterator begin()
        {
            return _str;
        }

        iterator end()
        {
            return _str + _size;
        }
        void push_back(char c)
        {
            if (_size == _capacity)
            {
                reserve(_capacity == 0 ? 4 : 2 * _capacity);
            }
            _str[_size++] = c;
            _str[_size] = '\0';
        }

        string& operator+=(char c)
        {
            push_back(c);
            return *this;
        }

        void append(const char* str)
        {
            if (_capacity < _size + strlen(str) )
            {
                reserve(_size + strlen(str));
            }
            memmove(_str + _size, str, strlen(str) + 1);
            _size = _size + strlen(str);
        }

        string& operator+=(const char* str)
        {
            append(str);
            return *this;
        }

        
        string& operator=(string s)
        {
            string temp(s);
            swap(temp);
            return *this;
        }

        void clear()
        {
            _str[0] = '\0';
            _size = 0;
        }

        void swap(string& s)
        {
            std::swap(_str, s._str);
            std::swap(_size, s._size);
            std::swap(_capacity, s._capacity);
        }

        const char* c_str()const
        {
            return _str;
        }

        size_t size()const
        {
            return _size;
        }

        size_t capacity()const
        {
            return _capacity;
        }

        bool empty()
        {
            if (_size == 0)
                return true;
            return false;
        }

        void resize(size_t n, char c = '\0')
        {
            assert(n >= 0);
            if (n <= _size)
            {
                _size = n;
                _str[n] = '\0';
            }
            else
            {
                reserve(n);
                for (int i = _size; i < n; i++)
                {
                    _str[i] = c;
                }
                _size = n;
                _str[_size] = '\0';
            }
        }

        void reserve(size_t n)
        {
            if (n > _capacity)
            {
                char* tem = new char[n + 1];
                memmove(tem, _str, _size + 1);
                delete[] _str;
                _str = tem;
                _capacity = n;
            }
        }



        /////////////////////////////////////////////////////////////

        // access

        char& operator[](size_t index)
        {
            return _str[index];
        }

        const char& operator[](size_t index)const
        {
            return _str[index];
        }



        /////////////////////////////////////////////////////////////

        //relational operators
        bool operator<(const string& s)
        {
            //如果字符串小于输入字符串返回值<0，相等0，大于>0
            //true  _size<s._size
            int ret = memcmp(_str, s._str, _size < s._size ? _size : s._size);
            return (ret < 0 || (ret == 0 && _size < s._size));
        }

        bool operator<=(const string& s)
        {
            return *this < s || *this == s;
        }

        bool operator>(const string& s)
        {
            return !(*this <= s);
        }



        bool operator>=(const string& s)
        {
            return !(*this < s);
        }

        bool operator==(const string& s)
        {
            if (_size == s._size)
            {
                return !((bool)memcmp(_str, s._str, _size));
            }
            return false;
        }

        bool operator!=(const string& s)
        {
            return !(*this == s);
        }




        // 返回c在string中第一次出现的位置

        size_t find(char c, size_t pos = 0) const
        {
            for (size_t i = pos; i < _size; i++)
            {
                if (_str[i] == 'c')
                {
                    return i;
                }
            }
            return npos;
        }

        // 返回子串s在string中第一次出现的位置

        size_t find(const char* s, size_t pos = 0) const
        {
            assert(pos < _size);
            const char* ptr = strstr(_str, s);
            if (ptr)
            {
                return ptr - _str;
            }
            else
            {
                return npos;
            }

        }

        // 在pos位置上插入字符c/字符串str，并返回该字符的位置

        string& insert(size_t pos, char c)
        {
            assert(pos <= _size);
            if (_size + 1 > _capacity)
            {
                reserve(_size + 1);
            }
            for (size_t i = _size; i > pos; i--)
            {
                _str[i] = _str[i - 1];
            }
            _str[pos] = c;
            _str[_size] = '\0';
            return *this;
        }

        string& insert(size_t pos, const char* str)
        {
            assert(pos >= 0 && pos <= _size);
            size_t sz = strlen(str);
            if (_size + sz <= _capacity)
            {
                size_t end = _size + sz ;
                size_t start = _size;
                while (start >= pos)
                {
                    _str[end--] = _str[start--];
                }
                memmove(_str + pos, str, sz);
                _size += sz;
            }
            else
            {
                reserve(_capacity + sz);
                size_t end = _size + sz;
                size_t start = _size;
                while (start >= pos)
                {
                    _str[end--] = _str[start--];
                }
                memmove(_str + pos, str, sz);
                _size += sz;
            }
            return *this;
        }



        

        string& erase(size_t pos, size_t len)
        {
            assert(pos >= 0 && pos < _size);
            if (len ==npos||pos + len >= _size)
            {
                _size = pos;
                _str[_size] = '\0';
            }
            else
            {
                size_t end = pos + len;
                while (end <= _size)
                {
                    _str[pos++] = _str[end++];
                }
                _size -= len;
            }
            return *this;
        }
    public:
        const static size_t npos ;
    private:
        char* _str;
        size_t _capacity;
        size_t _size;
    };
    const size_t string::npos = -1;
    istream& operator>>(istream& _cin, gao::string& s)
    {
        s.clear();
        char ch;
        ch = _cin.get();
        char buff[128];
        int i = 0;
        while (ch != ' ' && ch != '\n')
        {
            buff[i++] = ch;
            ch = _cin.get();
            if (i == 127)
            {
                buff[i] = '\0';
                s += buff;
                i = 0;
            }
        }
        if (i != 0)
        {
            buff[i] = '\0';
            s += buff;
        }
        return _cin;
    }
    ostream& operator<<(ostream& _cout, const gao::string& s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            _cout << s[i];
        }
        return _cout;
    }

};
