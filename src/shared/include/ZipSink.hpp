#ifndef _ZIPSINK_HPP_
#define _ZIPSINK_HPP_

#include "Exception.hpp"

class ZipSinkException : public Exception {
public:
    ZipSinkException(const char *msg) : Exception(msg) { }
    ZipSinkException(const std::string& msg) : Exception(msg) { }
};

class ZipSink {
private:
    ZipSink(const ZipSink&);
    ZipSink& operator=(const ZipSink&);

public:
    ZipSink();
    virtual ~ZipSink();

    virtual void open(size_t size) throw (ZipSinkException);
    virtual void write(const void *data, size_t size) throw (ZipSinkException);
    virtual void close() throw ();

protected:
    void throw_not_opened() throw (ZipSinkException);
    void throw_already_opened() throw (ZipSinkException);
    void throw_illegal_operation() throw (ZipSinkException);
};

#endif