#ifndef _ZIPREADER_HPP_
#define _ZIPREADER_HPP_

#include "Zip.hpp"
#include "ZipSink.hpp"

#include <string>
#include <vector>
#include <cstdio>

class ZipReaderException : public ZipException {
public:
    ZipReaderException(const char *msg) : ZipException(msg) { }
    ZipReaderException(const std::string& msg) : ZipException(msg) { }
};

class ZipReader : public Zip {
private:
    ZipReader(const ZipReader&);
    ZipReader& operator=(const ZipReader&);

public:
    ZipReader(const std::string& filename) throw (ZipReaderException);
    virtual ~ZipReader();

    const Files& get_files() const;
    bool file_exists(std::string filename);
    bool equals_directory(const File& file, const std::string& directory);
    void extract(std::string filename, ZipSink& sink) throw (ZipReaderException);

private:
    void throw_corrupt_file(const std::string& msg) throw (ZipReaderException);
    void throw_inflate_failed(const std::string& msg) throw (ZipReaderException);
    const File& get_file(const std::string& filename) throw (ZipReaderException);
};

#endif
