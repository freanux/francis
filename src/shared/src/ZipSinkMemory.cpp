#include "ZipSinkMemory.hpp"

#include <cstring>

ZipSinkMemory::ZipSinkMemory() : buffer(0), ptr(0), size(0) { }

ZipSinkMemory::~ZipSinkMemory() {
    close();
}

void ZipSinkMemory::open(size_t size) throw (ZipSinkException) {
    if (buffer) {
        throw_already_opened();
    }

    if (!size) {
        throw_illegal_operation();
    }

    buffer = new unsigned char[size];
    ptr = buffer;
}


void ZipSinkMemory::write(const void *data, size_t size) throw (ZipSinkException) {
    if (!buffer) {
        throw_not_opened();
    }

    const unsigned char *tmp_data = static_cast<const unsigned char *>(data);
    if (ptr < tmp_data || ptr > (tmp_data + this->size)) {
        throw_illegal_operation();
    }

    memcpy(ptr, data, size);
    ptr += size;
}

void ZipSinkMemory::close() throw () {
    if (buffer) {
        delete[] buffer;
        buffer = 0;
    }
}

const void *ZipSinkMemory::get_data() const {
    return buffer;
}

size_t ZipSinkMemory::get_size() const {
    return size;
}
