#ifndef _EXCEPTION_HPP_
#define _EXCEPTION_HPP_

#include <exception>
#include <string>

class Exception : public std::exception {
public:
    Exception(const char *caption);
    Exception(const std::string& caption);
    virtual ~Exception() throw () { }

    virtual const char *what() const throw();

private:
    std::string caption;
};

#endif
