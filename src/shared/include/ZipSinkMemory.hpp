#ifndef _ZIPSINKMEMORY_HPP_
#define _ZIPSINKMEMORY_HPP_

#include "ZipSink.hpp"

class ZipSinkMemory : public ZipSink {
public:
    ZipSinkMemory();
    virtual ~ZipSinkMemory();

    virtual void open(size_t size) throw (ZipSinkException);
    virtual void write(const void *data, size_t size) throw (ZipSinkException);
    virtual void close() throw ();

    const void *get_data() const;
    size_t get_size() const;

private:
    unsigned char *buffer;
    unsigned char *ptr;
    size_t size;
};

#endif