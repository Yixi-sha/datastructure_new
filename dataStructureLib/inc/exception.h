#ifndef EXCEPTION_H
#define EXCEPTION_H

#include "object.h"
namespace yixi {

#define THROW_EXCEPTION(obj, message) throw obj(message, __FILE__, __LINE__)

class Exception : public Object
{
protected:
    char* i_message;
    char* i_location;

    void init(const char* message, const char* file, int line);
public:
    Exception(const char* message);
    Exception(const char* file, int line);
    Exception(const char* message, const char* file, int line);

    Exception(const Exception& obj);
    Exception& operator= (const Exception& obj);

    virtual const char* message() const;
    virtual const char* location() const;

    virtual ~Exception() = 0;
};


class ArithmeticException:public Exception
{
public:
    ArithmeticException():Exception(0){}
    ArithmeticException(const char *message):Exception(message){}
    ArithmeticException(const char *file,int line):Exception(file,line){}
    ArithmeticException(const char* message,const char *file,int line):Exception(message,file,line){}

    ArithmeticException(const ArithmeticException& obj):Exception(obj){}

    ArithmeticException& operator =(const ArithmeticException& obj)
    {
        Exception::operator =(obj);
        return *this;
    }
};

class NullPointerException:public Exception
{
public:
    NullPointerException():Exception(0){}
    NullPointerException(const char *message):Exception(message){}
    NullPointerException(const char *file,int line):Exception(file,line){}
    NullPointerException(const char* message,const char *file,int line):Exception(message,file,line){}

    NullPointerException(const NullPointerException& obj):Exception(obj){}

    NullPointerException& operator =(const NullPointerException& obj)
    {
        Exception::operator =(obj);
        return *this;
    }
};

class IndexOutOfBoundsException:public Exception
{
public:
    IndexOutOfBoundsException():Exception(0){}
    IndexOutOfBoundsException(const char *message):Exception(message){}
    IndexOutOfBoundsException(const char *file,int line):Exception(file,line){}
    IndexOutOfBoundsException(const char* message,const char *file,int line):Exception(message,file,line){}

    IndexOutOfBoundsException(const IndexOutOfBoundsException& obj):Exception(obj){}

    IndexOutOfBoundsException& operator =(const IndexOutOfBoundsException& obj)
    {
        Exception::operator =(obj);
        return *this;
    }
};

class NoEnoughMemoryException:public Exception
{
public:
    NoEnoughMemoryException():Exception(0){}
    NoEnoughMemoryException(const char *message):Exception(message){}
    NoEnoughMemoryException(const char *file,int line):Exception(file,line){}
    NoEnoughMemoryException(const char* message,const char *file,int line):Exception(message,file,line){}

    NoEnoughMemoryException(const NoEnoughMemoryException& obj):Exception(obj){}

    NoEnoughMemoryException& operator =(const NoEnoughMemoryException& obj)
    {
        Exception::operator =(obj);
        return *this;
    }
};

class InvalidParameterException:public Exception
{
public:
    InvalidParameterException():Exception(0){}
    InvalidParameterException(const char *message):Exception(message){}
    InvalidParameterException(const char *file,int line):Exception(file,line){}
    InvalidParameterException(const char* message,const char *file,int line):Exception(message,file,line){}

    InvalidParameterException(const InvalidParameterException& obj):Exception(obj){}

    InvalidParameterException& operator =(const InvalidParameterException& obj)
    {
        Exception::operator =(obj);
        return *this;
    }
};

class InvalidOperationException:public Exception
{
public:
    InvalidOperationException():Exception(0){}
    InvalidOperationException(const char *message):Exception(message){}
    InvalidOperationException(const char *file,int line):Exception(file,line){}
    InvalidOperationException(const char* message,const char *file,int line):Exception(message,file,line){}

    InvalidOperationException(const InvalidOperationException& obj):Exception(obj){}

    InvalidOperationException& operator =(const InvalidOperationException& obj)
    {
        Exception::operator =(obj);
        return *this;
    }
};


}



#endif // EXCEPTION_H
