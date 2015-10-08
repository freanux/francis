#include "ZipSink.hpp"

ZipSink::ZipSink() { }

ZipSink::~ZipSink() { }

void ZipSink::open(size_t size) throw (ZipSinkException) { }

void ZipSink::write(const void *data, size_t size) throw (ZipSinkException) { }

void ZipSink::close() throw () { }


void ZipSink::throw_not_opened() throw (ZipSinkException) {
    throw ZipSinkException("ZipSink not opened.");
}

void ZipSink::throw_already_opened() throw (ZipSinkException) {
    throw ZipSinkException("ZipSink already opened.");
}

void ZipSink::throw_illegal_operation() throw (ZipSinkException) {
    throw ZipSinkException("Illegal ZipSink operation.");
}